#include "Renderer.h"
#include "Global.h"
#include "XProfiler.h"
#include "AppFrame.h"
#include "Utility.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <EGL/egl.h>
#endif

#define MT_UpdateVerts

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

XRenderer::XRenderer(): pRenderer(nullptr), storeViewport{}
{
}

XRenderer::~XRenderer()
{
}

bool XRenderer::init()
{
	auto director = Director::getInstance();
	auto glv = director->getOpenGLView();
	if (!glv)
	{
		return false;
	}
	auto p = getInstance();
	p->pRenderer = director->getRenderer();
	// note: there is a default fbo for render, see Director::setClearColor
	//p->pRenderer->setClearColor(Color4F(0, 0, 0, 0));
	director->setClearColor(Color4F(0, 0, 0, 0));
	p->bRenderStarted = false;
	// note: set this
	Image::setPNGPremultipliedAlphaEnabled(false);

	// cocos objects
	p->drawNode = DrawNode::create();
	p->drawNode->retain();
	p->movingCamera = Camera::create();
	p->movingCamera->retain();
	p->tempRenderTexture = nullptr;//note: init in PostEffectCapture

	const auto glp = GLProgramCache::getInstance()->getGLProgram(
		GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
	//auto glp = GLProgramCache::getInstance()->getGLProgram(
	//GLProgram::SHADER_NAME_ETC1AS_POSITION_TEXTURE_COLOR_NO_MVP);
	BlendMode::Default->setFogGLProgram(FogMode::None, glp);
	p->currentBlendMode = BlendMode::Default;
	p->currentProjection = director->getProjectionMatrix(0);
	director->setProjection(Director::Projection::_2D);
	director->setDisplayStats(false);

	return true;
}

bool XRenderer::end()
{
	//SAFE_DELETE(getInstance()->currentRoot);//note: do not delete
	//SAFE_DELETE(getInstance()->movingNode);
	SAFE_DELETE(getInstance()->drawNode);
	SAFE_DELETE(getInstance()->movingCamera);
	CC_SAFE_RELEASE_NULL(getInstance()->tempRenderTexture);
	return true;
}

void XRenderer::updateBlendMode(BlendMode* m)
{
	//assert_ptr(m);
	if (currentBlendMode == m)
		return;
	currentBlendMode = m;
	auto glps = currentBlendMode->getGLProgramState(currentFogMode);
	//CCASSERT(glps, "can't get GLProgramState!");
	// only the last param set will take effect at each frame
	if (currentFogMode != None && glps)
	{
		// update fog uniforms, note: they can be killed by the shader compiler
		auto &c = currentFogParam.color;
		glps->setUniformVec4("u_fogColor", Vec4(c.r, c.g, c.b, /*c.a*/1.f));
		switch (currentFogMode)
		{
		case Liner:
			glps->setUniformFloat("u_fogStart", currentFogParam.start);
			glps->setUniformFloat("u_fogEnd", currentFogParam.end);
			break;
		case Exp1:
		case Exp2:
			glps->setUniformFloat("u_fogDensity", currentFogParam.density);
			break;
		default: break;
		}
	}
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

void XRenderer::pushCustomCommend(function<void()> f)noexcept
{
	auto cmd = LMP.getCustomCommand();
	cmd->init(0.f);
	cmd->set3D(false);
	cmd->setTransparent(false);
	cmd->setSkipBatching(false);
	cmd->func = f;
	addCommand(cmd);
}

void XRenderer::pushCustomCommend(RenderQueue::QUEUE_GROUP group, float globalZOrder, std::function<void()> f) noexcept
{
	auto cmd = LMP.getCustomCommand();
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

	// Store glViewport, ProjectionMatrix; Load currentProjection
	const auto f = [=]() {
		glGetIntegerv(GL_VIEWPORT, storeViewport);
		storeProjection = Director::getInstance()->getProjectionMatrix(0);
		Director::getInstance()->loadProjectionMatrix(currentProjection, 0);
	};
	// todo: maybe GLOBAL_NEG?
	pushCustomCommend(f);

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
	bRenderStarted = false;
	// restore glBlendEquation, glViewport, ProjectionMatrix
	const auto f = [=]() {
		glBlendEquation(GL_FUNC_ADD);
		glViewport(storeViewport[0], storeViewport[1], storeViewport[2], storeViewport[3]);
		Director::getInstance()->loadProjectionMatrix(storeProjection, 0);
	};
	pushCustomCommend(f);

#ifdef MT_UpdateVerts
	updateBatchedVerts();
#endif
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
		// wrong code:
		//   auto r = renderTargetStack.back();
		//   r->clear(c.r, c.g, c.b, c.a);
		// RenderTexture::clear calls begin + end,
		// but here is between begin and end.
		pushCustomCommend([c]()
		{
			GLfloat oldColor[4] = { 0.0f };
			glGetFloatv(GL_COLOR_CLEAR_VALUE, oldColor);//save
			//glClearColor(c.r, c.g, c.b, 1.f);
			glClearColor(c.r, c.g, c.b, c.a);
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(oldColor[0], oldColor[1], oldColor[2], oldColor[3]);//restore
		});
	}
	else
	{
		pushCustomCommend([=]()
		{
			// note: glClear will clear all if not use glScissor
			glScissor(
				GLint(currentVP._left),
				GLint(currentVP._bottom),
				GLsizei(currentVP._width),
				GLsizei(currentVP._height));
			glEnable(GL_SCISSOR_TEST);
			glDepthMask(GL_TRUE);
			//glClearColor(c.r, c.g, c.b, 1.f);
			glClearColor(c.r, c.g, c.b, c.a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glDisable(GL_SCISSOR_TEST);
			glDepthMask(GL_FALSE);
		});
	}
}

bool XRenderer::setViewport(double left, double right, double bottom, double top)noexcept
{
	const auto f = [=]() {
		glViewport(GLint(left), GLint(bottom), GLsizei(right - left), GLsizei(top - bottom));
	};
	pushCustomCommend(f);
	currentVP = cocos2d::experimental::Viewport(left, bottom, right - left, top - bottom);
	return true;
}

void XRenderer::setOrtho(float left, float right, float bottom, float top)noexcept
{
	CC_ASSERT(left != right);
	CC_ASSERT(bottom != top);
	Mat4::createOrthographicOffCenter(left, right, bottom, top, -1024.f, 1024.f, &currentProjection);
	auto mt = currentProjection;
	const auto f = [mt]()
	{
		Director::getInstance()->loadProjectionMatrix(mt, 0);
	};
	pushCustomCommend(f);
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
	currentProjection = movingCamera->getViewProjectionMatrix();

	auto mt = currentProjection;
	const auto f = [mt]()
	{
		Director::getInstance()->loadProjectionMatrix(mt, 0);
	};
	pushCustomCommend(f);
}

void XRenderer::setFog(float start, float end, const Color4F& color)noexcept
{
	if (start != end)
	{
		currentFogParam.color = color;
		if (start == -1.0f)
		{
			currentFogParam.density = end;
			currentFogMode = Exp1;
		}
		else if (start == -2.0f)
		{
			currentFogParam.density = end;
			currentFogMode = Exp2;
		}
		else
		{
			currentFogParam.start = start;
			currentFogParam.end = end;
			currentFogMode = Liner;
		}
		// update immediately TODO: avoid repeat of setting
		auto glps = currentBlendMode->getGLProgramState(currentFogMode);
		if (glps)
		{
			auto &c = currentFogParam.color;
			glps->setUniformVec4("u_fogColor", Vec4(c.r, c.g, c.b, /*c.a*/1.f));
			switch (currentFogMode)
			{
			case Liner:
				glps->setUniformFloat("u_fogStart", currentFogParam.start);
				glps->setUniformFloat("u_fogEnd", currentFogParam.end);
				break;
			case Exp1:
			case Exp2:
				glps->setUniformFloat("u_fogDensity", currentFogParam.density);
				break;
			default: break;
			}
		}
	}
	else
	{
		currentFogMode = None;
	}
	/*
	 * Dosen't work TODO: refer lua-test
	 *
		function<void()> f;
		if (start != end)
		{
			fogColor[0] = color.r; fogColor[1]= color.g; fogColor[2] = color.b; fogColor[3] = color.a;
			if (start == -1.0f)
			{
				f = [=]() {
					pRenderer->setDepthTest(true);
					glEnable(GL_FOG);//激活雾效果
					glFogi(GL_FOG_MODE, GL_EXP);//雾方程
					glFogfv(GL_FOG_COLOR, fogColor);//雾颜色
					glFogf(GL_FOG_DENSITY, end);//雾密度
					glHint(GL_FOG_HINT, GL_DONT_CARE);//在渲染质量与速度上没有偏向
				};
			}
			else if (start == -2.0f)
			{
				f = [=]() {
					pRenderer->setDepthTest(true);
					glEnable(GL_FOG);
					glFogi(GL_FOG_MODE, GL_EXP2);
					glFogfv(GL_FOG_COLOR, fogColor);
					glFogf(GL_FOG_DENSITY, end);
					glHint(GL_FOG_HINT, GL_DONT_CARE);
				};
			}
			else
			{
				f = [=]() {
					pRenderer->setDepthTest(true);
					glEnable(GL_FOG);
					glFogi(GL_FOG_MODE, GL_LINEAR)
					glFogfv(GL_FOG_COLOR, fogColor);
					glHint(GL_FOG_HINT, GL_DONT_CARE);
					glFogf(GL_FOG_START, start);//雾开始值(距离观察点开始距离)
					glFogf(GL_FOG_END, end);//雾结束值
				};
			}
		}
		else
		{
			f = [=]() {
				pRenderer->setDepthTest(false);
				glDisable(GL_FOG);//关闭雾效果
			};
		}
		auto cmd = make_shared<CustomCommand>();
		cmd->init(0.f);
		cmd->func = f;
		pRenderer->addCommand(cmd.get());
		tempRenderCommands.push_back(cmd);
	*/
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
	// avoid copy Mat4 and Triangles
	cmd->init(
		0.f, p->getTexture(),
		currentBlendMode->getGLProgramState(currentFogMode),
		currentBlendMode->blendFunc,
		currentBlendMode->blendEquation
	);
	// note: rotation in cocos2dx is adverse to lstg
	getNodeTransform(p->getAnchorPointInPoints(), x, y, -rot, hscale, vscale, z, cmd->getMV());
	addXTCommand(cmd);
	return true;
}

bool XRenderer::render(ResSprite* p, float x, float y, float rot, float hscale, float vscale, float z)noexcept
{
	updateBlendMode(p->getBlendMode());
	return render(p->getSprite(), &p->getVertex(), x, y, rot, hscale, vscale, z);
}

bool XRenderer::renderRect(ResSprite* p,
	float x1, float y1, float x2, float y2)noexcept
{
	assert_ptr(p);

	updateBlendMode(p->getBlendMode());

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
	assert_ptr(p);

	updateBlendMode(p->getBlendMode());

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
	updateBlendMode(p->getBlendMode());
	auto i = int32_t(std::floor(ani_timer / p->getInterval())) % int32_t(p->getCount());
	if (i < 0)i += p->getCount();
	render(p->getSprite(i), &p->getVertex(i), x, y, rot, hscale, vscale);
	return true;
}

bool XRenderer::render(ResParticle::ParticlePool* p, float hscale, float vscale)noexcept
{
	updateBlendMode(p->getBlendMode());
	// already set in Render
	//p->SetCenter(p->GetCenter());
	p->Render(hscale, vscale);
	return true;
}

bool XRenderer::renderTexture(Texture2D* t, V3F_C4B_T2F_Quad* quad)noexcept
{
	auto cmd = LMP.getXTrianglesCommand();
	auto q = LMP.getQuad();
	*q = *quad;
	//TrianglesCommand::Triangles tri;
	const auto tri = cmd->getTri();
	tri->verts = (V3F_C4B_T2F*)q;
	tri->indices = quadIndices9;
	tri->vertCount = 4;
	tri->indexCount = 6;
	*cmd->getMV() = Mat4::IDENTITY;
	cmd->init(
		0.f, t,
		currentBlendMode->getGLProgramState(currentFogMode),
		currentBlendMode->blendFunc,
		currentBlendMode->blendEquation
		//tri,// triangles will be copied
		//Mat4::IDENTITY
	);//TODO: May be better
	addXTCommand(cmd);
	return true;
}

bool XRenderer::renderTexture(Texture2D* t, const TrianglesCommand::Triangles& triangles) noexcept
{
	auto cmd = LMP.getXTrianglesCommand();
	cmd->init(
		0.f, t,
		currentBlendMode->getGLProgramState(currentFogMode),
		currentBlendMode->blendFunc,
		currentBlendMode->blendEquation,
		triangles,
		Mat4::IDENTITY
	);
	addXTCommand(cmd);
	return true;
}

bool XRenderer::renderTexture(ResTexture* p, V3F_C4B_T2F_Quad* quad)noexcept
{
	return renderTexture(p->getTexture(), quad);
}

bool XRenderer::renderText(ResFont* p, const char* str, float x, float y, float scale,
	TextHAlignment halign, TextVAlignment valign)noexcept
{
	assert_ptr(p);
	p->setHAlign(halign);
	p->setVAlign(valign);
	return renderText(p, str, x, y, -1, -1, scale);
}

bool XRenderer::renderTextAutoAlign(ResFont* p, const char* str, Rect& rect, float scale,
	TextHAlignment halign, TextVAlignment valign, Color4B c)noexcept
{
	assert_ptr(p);
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
	return renderText(p, str, x, y, rect.size.width, rect.size.height, scale);
}

bool XRenderer::renderText(ResFont* p, const char* str,
	float x, float y, float width, float height, float scale)noexcept
{
	assert_ptr(p);
	flushTriangles();
	updateBlendMode(p->getBlendMode());

	// use temprary label
	auto label = labelPool.getWithResFont(p);
	const auto ha = p->getHAlign();
	const auto va = p->getVAlign();
	label->setString(str);
	label->setAnchorPoint(AlignmentToAnchorPoint(ha, va));
	label->setAlignment(p->getHAlign(), p->getVAlign());
	//label->setOverflow(bWordBreak ? Label::Overflow::RESIZE_HEIGHT : Label::Overflow::NONE);
	if (width > 0 && height > 0 && label->getOverflow() != Label::Overflow::NONE)
		label->setDimensions(width, height);
	label->setScale(scale);//TODO: setFontSize
	label->setPosition(x, y);
	label->setBlendFunc(currentBlendMode->blendFunc);
	if (p->getLabelType() == ResFont::LabelType::TTF)
	{
		// for TTF
		label->enableOutline(p->getOutlineColor(), p->getOutlineSize());
		label->setTextColor(p->getColor());
		//lb->setGLProgram(currentGLProgram);//TTF label uses shader for effects
	}
	else
	{
		//label->setBlendColor(p->GetBlendColor());//no need
		label->setOpacity(p->getColor().a);
		label->setColor(Color3B(p->getColor()));
		label->setGLProgram(currentBlendMode->getGLProgram());//don't set fog
	}
	label->visit(pRenderer, Mat4::IDENTITY, 0);
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

	flushTriangles();

	rt->setVirtualViewport(Vec2::ZERO,
		Rect(currentVP._left, currentVP._bottom, currentVP._width, currentVP._height),
		Rect(0, 0, currentVP._width, currentVP._height));
	const auto c = p->getClearColor();
	rt->beginWithClear(c.r / 255.f, c.g / 255.f, c.b / 255.f, c.a / 255.f);
	// RenderTexture::onBegin will set matrix to the state
	// when RenderTexture::begin is called, since we deferred
	// loading matrix, we need to set it again.
	auto mt = currentProjection;
	pushCustomCommend([mt]()
	{
		Director::getInstance()->loadProjectionMatrix(mt, 0);
	});
	renderTargetStack.push_back(p);
	// fix alpha blend
	XTrianglesCommand::isBlendFuncSeparate = p->isNeedBlendFix();
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

	if (renderTargetStack.empty())
		XTrianglesCommand::isBlendFuncSeparate = false;
	else
		XTrianglesCommand::isBlendFuncSeparate = renderTargetStack.back()->isNeedBlendFix();
	return true;
}

bool XRenderer::postEffect(ResRenderTarget* p, ResFX* shader, BlendMode* blend)noexcept
{
	if (!bRenderStarted)
	{
		XERROR("illegal invoke");
		return false;
	}
	auto rt = p->getTarget();
	auto sp = rt->getSprite();
	if (!sp || !shader->getProgram())
	{
		XERROR("internal error");
		return false;
	}

	const auto screenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	shader->setScreenSize(Vec2(screenSize.width, screenSize.height));
	shader->setViewport(Rect(currentVP._left, currentVP._bottom, currentVP._width, currentVP._height));

	// here RenderTexture will always fill screen
	auto size = rt->getSprite()->getTexture()->getContentSizeInPixels();
	pushCustomCommend([=]() {
		glViewport(GLint(0), GLint(0), GLsizei(size.width), GLsizei(size.height));
	});
	pushCustomCommend([rt]()
	{
		// see ResRenderTarget::checkTarget
		Director::getInstance()->loadProjectionMatrix(rt->getNodeToParentTransform(), 0);
	});

	// clip to currentVP
	sp->setTextureRect(Rect(
		currentVP._left, currentVP._bottom,
		currentVP._width, currentVP._height));
	sp->setAnchorPoint(Vec2::ZERO);
	sp->setPosition(Vec2(currentVP._left, currentVP._bottom));

	auto cmd = LMP.getXTrianglesCommand();
	cmd->init(
		0.f, sp->getTexture(),
		shader->getProgramState(),
		blend->blendFunc,
		blend->blendEquation,
		sp->getPolygonInfo().triangles,
		sp->getNodeToParentTransform()
		//Mat4::IDENTITY
	);
	addCommand(cmd);

	// RenderTexture::onEnd will restore glViewport to default, set again
	pushCustomCommend([=]() {
		glViewport(
			GLint(currentVP._left), GLint(currentVP._bottom),
			GLsizei(currentVP._width), GLsizei(currentVP._height));
	});
	// restore
	auto mt = currentProjection;
	pushCustomCommend([mt]()
	{
		Director::getInstance()->loadProjectionMatrix(mt, 0);
	});
	return true;
}

/******************************************************************************/

void XRenderer::addCommand(RenderCommand* cmd)
{
	flushTriangles();
	pRenderer->addCommand(cmd);
}

void XRenderer::addXTCommand(XTrianglesCommand* cmd)
{
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
	static atomic<int> flagn;
	flagn = 0;

	const auto dat = batchTaskInfo.data();
	const auto vert = _verts.data();
	const auto cmds = _cmds.data();
	deployThreadTask(size, nThr, [=](int start, int end)
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
		++flagn;
	});
	while (flagn < nThr) {}
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
			dw, dh, Texture2D::PixelFormat::RGBA8888, GL_DEPTH24_STENCIL8);
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
		pushCustomCommend([mt]()
		{
			Director::getInstance()->loadProjectionMatrix(mt, 0);
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
	pushCustomCommend([=]() {
		glViewport(GLint(0), GLint(0), GLsizei(size.width), GLsizei(size.height));
	});
	if (size.width != _lastFrameSize.width || size.height != _lastFrameSize.height)
	{
		_lastFrameSize = size;
		Mat4::createOrthographicOffCenter(0, size.width, 0, size.height, -1024.f, 1024.f, &_FBProjection);
	}
	pushCustomCommend([this]()
	{
		Director::getInstance()->loadProjectionMatrix(_FBProjection, 0);
	});

	const auto tsize = frameBuffer->getSprite()->getTexture()->getContentSizeInPixels();
	const auto scale = min(size.width / tsize.width, size.height / tsize.height);
	renderFrameBuffer(scale);
}

void XRenderer::renderFrameBuffer(float scale, bool copy)
{
	if (frameBuffer)
	{
		auto p = frameBuffer->getSprite();
		p->setScale(scale);
		p->setAnchorPoint(Vec2::ZERO);
		p->setPosition(Vec2::ZERO);
		auto cmd = LMP.getXTrianglesCommand();
		const auto tex = p->getTexture();
		if (!copy)
		{
			cmd->init(
				0.f, tex,
				p->getGLProgramState(),
				p->getBlendFunc(),
				GL_FUNC_ADD,
				p->getPolygonInfo().triangles,
				p->getNodeToParentTransform()
			);
		}
		else
		{
			// need flip here
			auto tr = Mat4::IDENTITY;
			tr.m[5] = -1.f;
			tr.m[13] = _lastFBSize.height;
			cmd->init(
				0.f, tex,
				p->getGLProgramState(),
				p->getBlendFunc(),
				GL_FUNC_ADD,
				p->getPolygonInfo().triangles,
				tr
			);
		}
		addCommand(cmd);
	}
}

RenderTexture* XRenderer::copyFrameBuffer(bool transparent)
{
	if (!frameBuffer)
		return nullptr;
	auto tmpRT = RenderTexture::create(
		_lastFBSize.width, _lastFBSize.height,
		Texture2D::PixelFormat::RGBA8888, GL_DEPTH24_STENCIL8);
	tmpRT->retain();
	tmpRT->beginWithClear(0, 0, 0, transparent ? 0 : 1);
	renderFrameBuffer(1.f, true);
	tmpRT->end();
	pushCustomCommend([=]()
	{
		tmpRT->release();
	});
	return tmpRT;
}

/******************************************************************************/
