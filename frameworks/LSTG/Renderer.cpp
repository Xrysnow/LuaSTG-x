#include "Renderer.h"
#include "Global.h"
#include "XProfiler.h"
#include "AppFrame.h"
#include "Util/Utility.h"
#include "LogSystem.h"
#include "renderer/backend/Backend.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <EGL/egl.h>
#endif

//#ifdef CC_PLATFORM_PC
//#define BATCH_COMMAND
//#define MT_UpdateVerts
//#endif // CC_PLATFORM_PC

using namespace std;
using namespace lstg;
using namespace cocos2d;

static unsigned short _quadIndices9[9 * 6] = { 0 };
static unsigned short _quadIndices512[LGOBJ_MAXLASERNODE * 6] = { 0 };
struct _initializer
{
	_initializer()
	{
		for (uint16_t i = 0; i < 9; ++i)
		{
			const uint16_t off = i * 4;
			_quadIndices9[i * 6 + 0] = 0 + off;
			_quadIndices9[i * 6 + 1] = 1 + off;
			_quadIndices9[i * 6 + 2] = 2 + off;
			_quadIndices9[i * 6 + 3] = 3 + off;
			_quadIndices9[i * 6 + 4] = 2 + off;
			_quadIndices9[i * 6 + 5] = 1 + off;
		}
		for (uint16_t i = 0; i < LGOBJ_MAXLASERNODE; ++i)
		{
			const uint16_t off = i * 4;
			_quadIndices512[i * 6 + 0] = 0 + off;
			_quadIndices512[i * 6 + 1] = 1 + off;
			_quadIndices512[i * 6 + 2] = 2 + off;
			_quadIndices512[i * 6 + 3] = 3 + off;
			_quadIndices512[i * 6 + 4] = 2 + off;
			_quadIndices512[i * 6 + 5] = 1 + off;
		}
	}
};
static _initializer __Renderer;

unsigned short* XRenderer::quadIndices9 = _quadIndices9;
unsigned short* XRenderer::quadIndices512 = _quadIndices512;

XRenderer* XRenderer::getInstance()
{
	static XRenderer instance;
	return &instance;
}

XRenderer::XRenderer()
{
}

XRenderer::~XRenderer()
{
}

bool XRenderer::init()
{
	auto director = Director::getInstance();
	const auto glv = director->getOpenGLView();
	if (!glv)
		return false;
	auto p = getInstance();
	p->pRenderer = director->getRenderer();
	p->bRenderStarted = false;
	// note: set this
	Image::setPNGPremultipliedAlphaEnabled(false);

	// cocos objects
	p->drawNode = DrawNode::create();
	p->drawNode->retain();
	p->movingCamera = Camera::create();
	p->movingCamera->retain();
	p->tempRenderTexture = nullptr;//note: init in PostEffectCapture
	p->clearRect = Sprite::createWithTexture(nullptr, Rect(0, 0, 2, 2));
	p->clearRect->retain();
	p->clearRectQuad = p->clearRect->getQuad();
	p->clearRectQuad.bl.vertices.set(0, 0, 1024.f);
	p->clearRectQuad.br.vertices.set(1, 0, 1024.f);
	p->clearRectQuad.tl.vertices.set(0, 1, 1024.f);
	p->clearRectQuad.tr.vertices.set(1, 1, 1024.f);
	Mat4::createOrthographicOffCenter(0, 1, 0, 1, -1024.f, 1024.f, &p->clearRectProj);

	auto rm = new RenderMode();
	rm->init(":RendererClearRect:", backend::BlendOperation::ADD,
		backend::BlendFactor::ONE, backend::BlendFactor::ZERO,
		p->clearRect->getProgramState()->getProgram());
	rm->desc.sourceRGBBlendFactor = backend::BlendFactor::ONE;
	rm->desc.destinationRGBBlendFactor = backend::BlendFactor::ZERO;
	rm->desc.sourceAlphaBlendFactor = backend::BlendFactor::ONE;
	rm->desc.destinationAlphaBlendFactor = backend::BlendFactor::ZERO;
	p->clearRectRenderMode = rm;

	const auto program = backend::ProgramCache::getInstance()->getBuiltinProgram(
		backend::ProgramType::POSITION_TEXTURE_COLOR);
	RenderMode::getDefault()->init("DEFAULT",
		backend::BlendOperation::ADD,
		backend::BlendFactor::SRC_ALPHA,
		backend::BlendFactor::ONE_MINUS_SRC_ALPHA,
		program);
	p->currentRenderMode = RenderMode::getDefault();
	p->currentProjection = director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
	director->setProjection(Director::Projection::_2D);
	director->setDisplayStats(false);

	p->commandBuffer = p->pRenderer->getCommandBuffer();

	return true;
}

bool XRenderer::end()
{
	//CC_SAFE_DELETE(getInstance()->currentRoot);//note: do not delete
	//CC_SAFE_DELETE(getInstance()->movingNode);
	CC_SAFE_DELETE(getInstance()->drawNode);
	CC_SAFE_DELETE(getInstance()->movingCamera);
	CC_SAFE_DELETE(getInstance()->clearRectRenderMode);
	CC_SAFE_RELEASE_NULL(getInstance()->tempRenderTexture);
	CC_SAFE_RELEASE_NULL(getInstance()->clearRect);
	CC_SAFE_RELEASE_NULL(getInstance()->commandBuffer);
	RenderMode::modeMap.clear();
	RenderMode::modeVector.clear();
	RenderMode::destructDefault();
	return true;
}

void XRenderer::updateRenderMode(RenderMode* m)
{
	assert(m);
	if (currentRenderMode == m)
		return;
	setProgramStateDirty();
	currentRenderMode = m;
}

void XRenderer::setAALevel(int lv)noexcept
{
	switch (lv)
	{
	case 0:
		optAALevel = lv;
		break;
	case 2:
		optAALevel = lv;
		break;
	case 4:
		optAALevel = lv;
		break;
	case 8:
		optAALevel = lv;
		break;
	case 16:
		optAALevel = lv;
		break;
	default:
		LWARNING("SetAALevel: invalid value");
		break;
	}
}

void XRenderer::setVsync(bool v)noexcept
{
	if (v == optVsync)return;
	optVsync = v;
	bool set = false;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	glfwSwapInterval(v ? 1 : 0);
	// glfwSwapInterval usually not work on windows
	typedef BOOL(WINAPI *PFNWGLSWAPINTERVALEXTPROC)(int interval);
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	if (wglSwapIntervalEXT)
	{
		wglSwapIntervalEXT(v ? 1 : 0);
		set = true;
	}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
	glfwSwapInterval(v ? 1 : 0);
	set = true;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	EGLDisplay eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	eglSwapInterval(eglDisplay, v ? 1 : 0);
	set = true;
#endif
	if (set)
	{
		XINFO("set vsync %s", (v ? "on" : "off"));
	}
	else
	{
		XINFO("not supported");
	}
}

void XRenderer::setOffscreen(bool b) noexcept
{
	bOffscreen = b;
	if (b)
		bUseFrameBuffer = true;
}

void XRenderer::pushCallbackCommand(const std::function<void()>& f)noexcept
{
	auto cmd = LMP.getCallbackCommand();
	cmd->init(0.f);
	cmd->set3D(false);
	cmd->setTransparent(false);
	cmd->setSkipBatching(false);
	cmd->func = f;
	addCommand(cmd);
}

void XRenderer::pushCallbackCommand(RenderQueue::QUEUE_GROUP group, float globalZOrder,
	const std::function<void()>& f) noexcept
{
	auto cmd = LMP.getCallbackCommand();
	cmd->init(globalZOrder);
	cmd->set3D(false);
	cmd->setTransparent(false);
	cmd->setSkipBatching(false);
	cmd->func = f;
	switch (group) {
		case RenderQueue::GLOBALZ_NEG:
			break;
		case RenderQueue::OPAQUE_3D:
			cmd->set3D(true);
			cmd->setTransparent(false);
			break;
		case RenderQueue::TRANSPARENT_3D:
			cmd->set3D(true);
			cmd->setTransparent(true);
			break;
		case RenderQueue::GLOBALZ_ZERO:
			break;
		case RenderQueue::GLOBALZ_POS:
			break;
		default: ;
	}
	addCommand(cmd);
}

bool XRenderer::beginScene()noexcept
{
	if (bRenderStarted)
		return false;
	XProfiler::getInstance()->tic(AppFrame::PF_BeginScene);
	bRenderStarted = true;
	// clear pools
	LMP.trim();
	LMP.reset();
	//LMP.clear();// clear is painful
	labelPool.restore();
	renderTargetUsed.clear();

	// Store glViewport, ProjectionMatrix; Load currentProjection
	const auto f = [=]() {
		storeViewport = pRenderer->getViewport();
		storeProjection = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, currentProjection);
	};
	// todo: maybe GLOBAL_NEG?
	pushCallbackCommand(f);

	setProgramStateDirty();
	frameBufferStart();
	drawNode->clear();
	_verts.clear();
	_indices.clear();
	_cmds.clear();

	XProfiler::getInstance()->toc(AppFrame::PF_BeginScene);
	return true;
}

bool XRenderer::endScene()noexcept
{
	if (!bRenderStarted)
		return false;
	XProfiler::getInstance()->tic(AppFrame::PF_EndScene);
	// check renderTargetStack
	if (!renderTargetStack.empty())
	{
		XWARNING("not all RenderTarget popped");
		while (!renderTargetStack.empty())
			popRenderTarget();
	}

	flushTriangles();

	drawNode->setBlendFunc(BlendFunc::ALPHA_NON_PREMULTIPLIED);
	drawNode->draw(pRenderer, Mat4::IDENTITY, 0);

	frameBufferEnd();
	// restore Viewport, ProjectionMatrix
	const auto f = [=]() {
		pRenderer->setViewPort(storeViewport.x, storeViewport.y, storeViewport.w, storeViewport.h);
		//commandBuffer->setViewport(storeViewport.x, storeViewport.y, storeViewport.w, storeViewport.h);
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, storeProjection);
	};
	pushCallbackCommand(f);

#ifdef MT_UpdateVerts
	updateBatchedVerts();
#endif
	bRenderStarted = false;
	for (auto& t : batchTaskInfo)
	{
		auto& cmd = t.cmd;
		cmd->getTri()->verts = _verts.data() + t.vOffset;
		cmd->getTri()->indices = _indices.data() + t.iOffset;
	}
	batchTaskInfo.clear();
	triToDraw.clear();

	XProfiler::getInstance()->toc(AppFrame::PF_EndScene);
	return true;
}

void XRenderer::renderClear(const Color4F& c)noexcept
{
	if (!renderTargetStack.empty())
	{
		// note: do not use RenderTexture::clear here
		// RenderTexture::clear calls begin + end,
		// but here is between begin and end.
		pRenderer->clear(ClearFlag::COLOR, c, 1.f, 0, 0.f);
	}
	else
	{
#if !defined(CC_USE_METAL) && !defined(CC_USE_GFX)
		// note: will clear all if not set scissor
		const auto vp = currentVP;
		pushCallbackCommand([=]()
		{
			commandBuffer->setScissorRect(true, (float)vp.x, (float)vp.y, (float)vp.w, (float)vp.h);
		});
		pRenderer->clear(ClearFlag::ALL, c, 1.f, 0, 0.f);
		pushCallbackCommand([=]()
		{
			commandBuffer->setScissorRect(false, 0, 0, 0, 0);
		});
#else
		const auto projBak = currentProjection;
		setProjection(clearRectProj);

		const auto c4b = Color4B(c);
		clearRectQuad.bl.colors = c4b;
		clearRectQuad.br.colors = c4b;
		clearRectQuad.tl.colors = c4b;
		clearRectQuad.tr.colors = c4b;

		updateRenderMode(clearRectRenderMode);
		renderTexture(clearRect->getTexture(), &clearRectQuad);

		setProjection(projBak);
#endif
	}
}

bool XRenderer::setViewport(double left, double right, double bottom, double top)noexcept
{
	//TODO: use float
	const int x = std::min(left, right);
	const int y = std::min(bottom, top);
	const unsigned int w = std::max(left, right) - x;
	const unsigned int h = std::max(bottom, top) - y;
	pushCallbackCommand([=]() {
		pRenderer->setViewPort(x, y, w, h);
		//commandBuffer->setViewport(x, y, w, h);
	});
	currentVP.x = x;
	currentVP.y = y;
	currentVP.w = w;
	currentVP.h = h;
	return true;
}

void XRenderer::setOrtho(float left, float right, float bottom, float top)noexcept
{
	CC_ASSERT(left != right);
	CC_ASSERT(bottom != top);
	Mat4::createOrthographicOffCenter(left, right, bottom, top, -1024.f, 1024.f, &currentProjection);
	auto mt = currentProjection;
	pushCallbackCommand([mt]()
	{
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, mt);
	});
	setProgramStateDirty();
}

void XRenderer::setPerspective(float eyeX, float eyeY, float eyeZ,
	float atX, float atY, float atZ,
	float upX, float upY, float upZ,
	float fovy, float aspect,
	float zn, float zf)noexcept
{
	//TODO: remove movingCamera

	// -aspect to convert RH to LH
	movingCamera->initPerspective(fovy*LRAD2DEGREE, -aspect, zn, zf);
	movingCamera->setPosition3D(Vec3(eyeX, eyeY, eyeZ));
	movingCamera->lookAt(Vec3(atX, atY, atZ), Vec3(upX, upY, upZ));

	setProjection(movingCamera->getViewProjectionMatrix());
}

void XRenderer::setProjection(const Mat4& proj)
{
	currentProjection = proj;
	pushCallbackCommand([=]()
	{
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, proj);
	});
	setProgramStateDirty();
}

/******************************************************************************/

bool XRenderer::render(Sprite* p, V3F_C4B_T2F_Quad* quad,
	float x, float y, float rot, float hscale, float vscale, float z)noexcept
{
	auto cmd = LMP.getXTrianglesCommand();
	const auto tr = cmd->getTri();
	if (quad)
	{
		auto q = LMP.getQuad();
		*q = *quad;
		tr->verts = (V3F_C4B_T2F*)q;
	}
	else
	{
		auto q = LMP.getQuad();
		*q = p->getQuad();
		tr->verts = (V3F_C4B_T2F*)q;
	}
	tr->indices = quadIndices9;
	tr->vertCount = 4;
	tr->indexCount = 6;
	setXTCommand(cmd, p->getTexture());
	// note: rotation in cocos2dx is adverse to lstg
	getNodeTransform(p->getAnchorPointInPoints(), x, y, -rot, hscale, vscale, z, cmd->getMV());
	addXTCommand(cmd);
	return true;
}

bool XRenderer::render(ResSprite* p, float x, float y, float rot, float hscale, float vscale, float z)noexcept
{
	updateRenderMode(p->getRenderMode());
	return render(p->getSprite(), &p->getVertex(), x, y, rot, hscale, vscale, z);
}

bool XRenderer::renderRect(ResSprite* p,
	float x1, float y1, float x2, float y2)noexcept
{
	assert(p);

	updateRenderMode(p->getRenderMode());

	auto v = p->getVertex();
	//TODO: Check Z
	v.tl.vertices.set(x1, y1, 0.5f);
	v.tr.vertices.set(x2, y1, 0.5f);
	v.bl.vertices.set(x1, y2, 0.5f);
	v.br.vertices.set(x2, y2, 0.5f);
	return renderTexture(p->getSprite()->getTexture(), &v);
}

bool XRenderer::render4V(ResSprite* p,
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	float x4, float y4, float z4)noexcept
{
	assert(p);

	updateRenderMode(p->getRenderMode());

	auto pSprite = p->getSprite();
	auto v = p->getVertex();
	v.tl.vertices.set(x1, y1, z1);
	v.tr.vertices.set(x2, y2, z2);
	v.bl.vertices.set(x3, y3, z3);
	v.br.vertices.set(x4, y4, z4);
	//TODO: reduce copy
	return renderTexture(pSprite->getTexture(), &v);
}

bool XRenderer::render(ResAnimation* p, int ani_timer,
	float x, float y, float rot, float hscale, float vscale)noexcept
{
	updateRenderMode(p->getRenderMode());
	auto i = int32_t(std::floor(ani_timer / p->getInterval())) % int32_t(p->getCount());
	if (i < 0)i += p->getCount();
	render(p->getSprite(i), &p->getVertex(i), x, y, rot, hscale, vscale);
	return true;
}

bool XRenderer::render(ResParticle::ParticlePool* p, float hscale, float vscale)noexcept
{
	updateRenderMode(p->getRenderMode());
	// already set in Render
	//p->setCenter(p->getCenter());
	p->render(hscale, vscale);
	return true;
}

bool XRenderer::renderTexture(Texture2D* t, V3F_C4B_T2F_Quad* quad)noexcept
{
	auto cmd = LMP.getXTrianglesCommand();
	auto q = LMP.getQuad();
	*q = *quad;
	const auto tri = cmd->getTri();
	tri->verts = (V3F_C4B_T2F*)q;
	tri->indices = quadIndices9;
	tri->vertCount = 4;
	tri->indexCount = 6;
	*cmd->getMV() = Mat4::IDENTITY;
	setXTCommand(cmd, t);
	addXTCommand(cmd);
	return true;
}

bool XRenderer::renderTexture(Texture2D* t, const TrianglesCommand::Triangles& triangles) noexcept
{
	auto cmd = LMP.getXTrianglesCommand();
	setXTCommand(cmd, t);
	*cmd->getTri() = triangles;
	*cmd->getMV() = Mat4::IDENTITY;
	addXTCommand(cmd);
	return true;
}

bool XRenderer::renderTexture(ResTexture* p, V3F_C4B_T2F_Quad* quad)noexcept
{
	return renderTexture(p->getTexture(), quad);
}

bool XRenderer::renderText(ResFont* p, const std::string& str, float x, float y, float scale,
	TextHAlignment halign, TextVAlignment valign)noexcept
{
	assert(p);
	p->setHAlign(halign);
	p->setVAlign(valign);
	return renderText(p, str, x, y, -1, -1, scale, scale);
}

bool XRenderer::renderTextAutoAlign(ResFont* p, const std::string& str, const Rect& rect, float scale,
	TextHAlignment halign, TextVAlignment valign, const Color4B& c)noexcept
{
	assert(p);
	p->setHAlign(halign);
	p->setVAlign(valign);
	p->setColor(c);
	float x = 0.f, y = 0.f;
	switch (halign)
	{
	case TextHAlignment::LEFT: x = rect.getMinX(); break;
	case TextHAlignment::CENTER: x = rect.getMidX(); break;
	case TextHAlignment::RIGHT: x = rect.getMaxX(); break;
	}
	switch (valign)
	{
	case TextVAlignment::TOP: y = rect.getMaxY(); break;
	case TextVAlignment::CENTER: y = rect.getMidY(); break;
	case TextVAlignment::BOTTOM: y = rect.getMinY(); break;
	}
	p->getLabel()->setOverflow(Label::Overflow::NONE);
	return renderText(p, str, x, y, rect.size.width, rect.size.height, scale, scale);
}

bool XRenderer::renderText(ResFont* p, const std::string& str,
	float x, float y, float width, float height, float scaleX, float scaleY)noexcept
{
	assert(p);
	flushTriangles();
	updateRenderMode(p->getRenderMode());

	// use temprary label
	auto label = labelPool.getWithResFont(p, str);
	const auto ha = p->getHAlign();
	const auto va = p->getVAlign();
	label->setString(str);
	label->setAnchorPoint(AlignmentToAnchorPoint(ha, va));
	label->setAlignment(p->getHAlign(), p->getVAlign());
	//label->setOverflow(bWordBreak ? Label::Overflow::RESIZE_HEIGHT : Label::Overflow::NONE);
	if (width > 0 && height > 0 && label->getOverflow() != Label::Overflow::NONE)
		label->setDimensions(width, height);
	label->setScale(scaleX, scaleY);//TODO: setFontSize
	label->setPosition(x, y);
	const auto func = currentRenderMode->getBlendFunc();
	label->setBlendFunc(func);
	if (p->getLabelType() == ResFont::LabelType::TTF)
	{
		// for TTF
		for (int i = 0; i < label->getStringLength(); ++i)
		{
			auto sp = label->getLetter(i);
			if (sp)
				sp->setBlendFunc(func);
		}
	}
	else
	{
		//label->setBlendColor(p->GetBlendColor());//TODO: check
		label->setOpacity(p->getColor().a);
		label->setColor(Color3B(p->getColor()));
	}
	//label->setProgramState(currentRenderMode->getProgramState());// shader is used for effects

	//label->visit(pRenderer, Mat4::IDENTITY, 0);
	const auto& proj = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
	label->visit(pRenderer, proj.getInversed()*currentProjection, 0);

	return true;
}

/******************************************************************************/

bool XRenderer::checkRenderTargetInUse(::RenderTexture* rt)noexcept
{
	if (!rt || renderTargetStack.empty())
		return false;
	return rt == renderTargetStack.back()->getTarget();
}

bool XRenderer::pushRenderTarget(ResRenderTarget* p) noexcept
{
	const auto rt = p->getTarget();
	if (!bRenderStarted)
	{
		XERROR("illegal invoke");
		return false;
	}
	if (!rt)
	{
		XERROR("RenderTexture is null");
		return false;
	}
	for (auto& rrt : renderTargetStack)
	{
		if (rrt == p)
		{
			XERROR("RenderTarget is already in stack");
			return false;
		}
	}
	if (renderTargetUsed.find(p) != renderTargetUsed.end())
	{
		XERROR("RenderTarget is already used");
		return false;
	}
	renderTargetUsed.insert(p);

	flushTriangles();

	rt->setVirtualViewport(Vec2::ZERO,
		Rect(currentVP.x, currentVP.y, currentVP.w, currentVP.h),
		Rect(0, 0, currentVP.w, currentVP.h));
	const auto c = p->getClearColor();
	rt->beginWithClear(c.r / 255.f, c.g / 255.f, c.b / 255.f, c.a / 255.f);
	// RenderTexture::onBegin will set matrix to the state
	// when RenderTexture::begin is called, since we deferred
	// loading matrix, we need to set it again.
	auto mt = currentProjection;
	pushCallbackCommand([mt]()
	{
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, mt);
	});
	renderTargetStack.push_back(p);
	return true;
}

bool XRenderer::popRenderTarget()noexcept
{
	if (!bRenderStarted)
	{
		XERROR("illegal invoke");
		return false;
	}

	if (renderTargetStack.empty())
	{
		XERROR("RenderTarget stack is empty");
		return false;
	}

	flushTriangles();

	auto rt = renderTargetStack.back()->getTarget();
	renderTargetStack.pop_back();
	rt->end();

	return true;
}

bool XRenderer::postEffect(ResRenderTarget* p, ResFX* shader, RenderMode* blend)noexcept
{
	if (!bRenderStarted)
	{
		XERROR("illegal invoke");
		return false;
	}
	auto rt = p->getTarget();
	auto sp = rt->getSprite();
	if (!sp || !shader || !blend)
	{
		XERROR("internal error");
		return false;
	}

	const auto screenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	shader->setScreenSize(Vec2(screenSize.width, screenSize.height));
	shader->setViewport(currentVP);

	// here RenderTexture will always fill screen
	auto size = sp->getTexture()->getContentSizeInPixels();
	pushCallbackCommand([=]()
	{
		pRenderer->setViewPort(0, 0, size.width, size.height);
		// see ResRenderTarget::checkTarget
		Director::getInstance()->loadMatrix(
			MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, rt->getNodeToParentTransform());
	});

	// clip to currentVP
	sp->setTextureRect(Rect(
		currentVP.x, currentVP.y,
		currentVP.w, currentVP.h));
	sp->setAnchorPoint(Vec2::ZERO);
	sp->setPosition(Vec2(currentVP.x, currentVP.y));

	auto cmd = LMP.getXTrianglesCommand();
	const auto state = shader->getRenderMode()->tempraryProgramState();
	cmd->init(0.f, sp->getTexture(), blend, state);
	*cmd->getTri() = sp->getPolygonInfo().triangles;
	*cmd->getMV() = sp->getNodeToParentTransform();
	state->setTexture(state->getUniformLocation(backend::TEXTURE),
		0, sp->getTexture()->getBackendTexture());
	state->setUniform(state->getUniformLocation(backend::MVP_MATRIX),
		&rt->getNodeToParentTransform(), sizeof(Mat4));
	addCommand(cmd);

	const auto mt = currentProjection;
	pushCallbackCommand([=]()
	{
		// RenderTexture::onEnd will restore viewport to default, set again
		pRenderer->setViewPort(currentVP.x, currentVP.y, currentVP.w, currentVP.h);
		// restore
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, mt);
	});
	return true;
}

void XRenderer::setProgramStateDirty()
{
	currentProgramState = nullptr;
	currentTexture = nullptr;
}

/******************************************************************************/

void XRenderer::setXTCommand(XTrianglesCommand* cmd, Texture2D* t)
{
	assert(cmd && t);
	if (!currentProgramState || currentTexture != t)
	{
		currentTexture = t;
		currentProgramState = currentRenderMode->tempraryProgramState();
		currentProgramState->setTexture(currentProgramState->getUniformLocation(backend::TEXTURE),
			0, t->getBackendTexture());
		currentProgramState->setUniform(currentProgramState->getUniformLocation(backend::MVP_MATRIX),
			currentProjection.m, sizeof(currentProjection.m));
	}
	cmd->init(0.f, t, currentRenderMode, currentProgramState);
}

void XRenderer::addCommand(RenderCommand* cmd)
{
#ifdef BATCH_COMMAND
	flushTriangles();
#endif
	pRenderer->addCommand(cmd);
}

void XRenderer::addXTCommand(XTrianglesCommand* cmd)
{
#ifdef BATCH_COMMAND
	if (triToDraw.empty() || triToDraw.back()->getMaterialID() == cmd->getMaterialID())
	{
		// merge
		triToDraw.push_back(cmd);
	}
	else
	{
		// flush
		flushTriangles();
		triToDraw.push_back(cmd);
	}
#else
	pRenderer->addCommand(cmd);
#endif
}

void XRenderer::flushTriangles()
{
	if (triToDraw.empty())
		return;
	const auto size = triToDraw.size();
	if (size < 8)
	{
		for (auto& cmd : triToDraw)
			pRenderer->addCommand(cmd);
		triToDraw.clear();
		return;
	}
	const auto vertStart = _verts.size();
	const auto indStart = _indices.size();
	const auto cmdStart = _cmds.size();
	const auto back = triToDraw.back();
	constexpr int limit = 512;

	_verts.reserve(vertStart + size * 4);
	_indices.reserve(indStart + size * 6);
	_cmds.reserve(cmdStart + size);

	size_t v_filled = 0;
	size_t i_filled = 0;
	size_t processed = 0;
	auto cmd = LMP.getXTrianglesCommand();
	*cmd->getMV() = Mat4::IDENTITY;
	auto v_filled_once = 0;
	auto i_filled_once = 0;
	size_t processed_once = 0;
	for (; processed < size; processed++)
	{
		auto xtc = triToDraw[processed];
		const auto vcount = xtc->getVertexCount();
		const auto icount = xtc->getIndexCount();
		if (v_filled_once + vcount > limit || i_filled_once + icount > limit)
		{
			if (vcount > limit)
			{
				pRenderer->addCommand(xtc);
				continue;
			}
			back->copyProperties(cmd);
			auto tr = cmd->getTri();
			tr->vertCount = v_filled_once;
			tr->indexCount = i_filled_once;
			batchTaskInfo.push_back({
				cmd,
				vertStart + v_filled - v_filled_once,
				indStart + i_filled - i_filled_once,
				cmdStart + processed - processed_once,
				processed_once
			});
			pRenderer->addCommand(cmd);

			cmd = LMP.getXTrianglesCommand();
			*cmd->getMV() = Mat4::IDENTITY;
			v_filled_once = 0;
			i_filled_once = 0;
			processed_once = 0;
		}
		// copy
		for (auto j = 0; j < vcount; ++j)
		{
			_verts.push_back(xtc->getVertices()[j]);
#ifndef MT_UpdateVerts
			xtc->getMV()->transformPoint(&(_verts.back().vertices));
#endif
		}
		for (auto j = 0; j < icount; ++j)
			_indices.push_back(xtc->getIndices()[j] + v_filled_once);
		_cmds.push_back(xtc);

		v_filled += vcount;
		v_filled_once += vcount;
		i_filled += icount;
		i_filled_once += icount;
		++processed_once;
	}
	if (v_filled_once > 0)
	{
		back->copyProperties(cmd);
		auto tr = cmd->getTri();
		tr->vertCount = v_filled_once;
		tr->indexCount = i_filled_once;
		batchTaskInfo.push_back({
			cmd,
			vertStart + v_filled - v_filled_once,
			indStart + i_filled - i_filled_once,
			cmdStart + processed - processed_once,
			processed_once
		});
		pRenderer->addCommand(cmd);
	}
	triToDraw.clear();
}

void XRenderer::updateBatchedVerts()
{
#ifdef MT_UpdateVerts
	const auto size = batchTaskInfo.size();
	const auto nThr = LTHP.size() + 1;
	const auto dat = batchTaskInfo.data();
	const auto vert = _verts.data();
	const auto cmds = _cmds.data();
	deployThreadTaskAndWait(size, nThr, [=](int start, int end, int)
	{
		for (auto j = start; j < end; j++) {
			const auto& inf = dat[j];
			auto voff = inf.vOffset;
			for (auto k = inf.cmdOffset; k < inf.cmdOffset + inf.cmdCount; ++k)
			{
				auto c = cmds[k];
				for (int m = 0; m < c->getVertexCount(); ++m)
				{
					c->getMV()->transformPoint(&(vert[voff].vertices));
					++voff;
				}
			}
		}
	});
#endif
}

/******************************************************************************/

void XRenderer::frameBufferStart()
{
	if (!bUseFrameBuffer)
		return;
	const auto glv = Director::getInstance()->getOpenGLView();
	const auto& dsize = glv->getDesignResolutionSize();
	const auto dh = int(dsize.height);
	const auto dw = int(dsize.width);

	if (frameBuffer)
	{
		const auto fw = int(_lastFBSize.width);
		const auto fh = int(_lastFBSize.height);
		if (fw != dw || fh != dh)
		{
			CC_SAFE_DELETE(frameBuffer);
		}
	}
	if (!frameBuffer)
	{
		frameBuffer = RenderTexture::create(
			dw, dh, backend::PixelFormat::RGBA8888, backend::PixelFormat::D24S8);
		if (!frameBuffer)
		{
			XERROR("create frame buffer failed");
		}
		else
		{
			frameBuffer->retain();
			frameBuffer->setKeepMatrix(true);
			LINFO("create frame buffer, size: (%d, %d)", dw, dh);
		}
		_lastFBSize = dsize;
	}
	if (frameBuffer)
	{
		// note: in order to include render command not in QUEUE_GROUP::GLOBALZ_ZERO,
		// we have to manually change zorder of begin and end
		frameBuffer->setGlobalZOrder(std::numeric_limits<float>::lowest());
		frameBuffer->beginWithClear(0, 0, 0, 0);
		auto mt = currentProjection;
		pushCallbackCommand([mt]()
		{
			Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, mt);
		});
	}
}

void XRenderer::frameBufferEnd()
{
	if (!bUseFrameBuffer || !frameBuffer)
		return;
	flushTriangles();
	frameBuffer->setGlobalZOrder(std::numeric_limits<float>::max());
	frameBuffer->end();
	auto size = Director::getInstance()->getOpenGLView()->getFrameSize();
	if (size.width != _lastFrameSize.width || size.height != _lastFrameSize.height)
	{
		_lastFrameSize = size;
		Mat4::createOrthographicOffCenter(0, size.width, 0, size.height, -1024.f, 1024.f, &_FBProjection);
	}
	pushCallbackCommand([=]()
	{
		pRenderer->setViewPort(0, 0, size.width, size.height);
		Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, _FBProjection);
	});

	if (!bOffscreen)
	{
		const auto tsize = frameBuffer->getSprite()->getTexture()->getContentSizeInPixels();
		const auto scale = min(size.width / tsize.width, size.height / tsize.height);
		renderFrameBuffer(scale);
	}
}

void XRenderer::renderFrameBuffer(float scale, bool copy)
{
	if (!frameBuffer)
		return;
	auto p = frameBuffer->getSprite();
	p->setScale(scale);
	p->setAnchorPoint(Vec2::ZERO);
	p->setPosition(Vec2::ZERO);
	// frameBuffer may be rendered more than once
	auto cmd = LMP.getXTrianglesCommand();
	const auto tex = p->getTexture();
	if (!copy)
	{
		cmd->init(0.f, tex,
			RenderMode::getDefault(), RenderMode::getDefault()->tempraryProgramState());
		*cmd->getTri() = p->getPolygonInfo().triangles;
		*cmd->getMV() = p->getNodeToParentTransform();
	}
	else
	{
		// need flip here
		auto tr = Mat4::IDENTITY;
		tr.m[5] = -1.f;
		tr.m[13] = _lastFBSize.height;
		cmd->init(0.f, tex,
			RenderMode::getDefault(), RenderMode::getDefault()->tempraryProgramState());
		*cmd->getTri() = p->getPolygonInfo().triangles;
		*cmd->getMV() = tr;
	}
	const auto state = cmd->getPipelineDescriptor().programState;
	state->setTexture(state->getUniformLocation(backend::TEXTURE),
		0, tex->getBackendTexture());
	state->setUniform(state->getUniformLocation(backend::MVP_MATRIX),
		_FBProjection.m, sizeof(_FBProjection.m));
	addCommand(cmd);
}

RenderTexture* XRenderer::copyFrameBuffer(bool transparent)
{
	if (!frameBuffer)
		return nullptr;
	auto tmpRT = RenderTexture::create(
		(int)_lastFBSize.width, (int)_lastFBSize.height,
		backend::PixelFormat::RGBA8888, backend::PixelFormat::D24S8);
	tmpRT->retain();
	tmpRT->beginWithClear(0, 0, 0, transparent ? 0 : 1);
	renderFrameBuffer(1.f, true);
	tmpRT->end();
	pushCallbackCommand([=]()
	{
		tmpRT->release();
	});
	return tmpRT;
}
