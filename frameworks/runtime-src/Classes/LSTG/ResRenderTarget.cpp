#include "ResRenderTarget.h"
#include "LogSystem.h"
#include "Renderer.h"
#include "Utility.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

bool ResRenderTarget::isNeedBlendFix() const
{
	return blendFix;
}

void ResRenderTarget::setNeedBlendFix(bool b)
{
	blendFix = b;
}

Color4B ResRenderTarget::getClearColor() const
{
	return clearColor;
}

void ResRenderTarget::setClearColor(const Color4B& color)
{
	clearColor = color;
}

RenderTexture* ResRenderTarget::getTarget()
{
	checkTarget();
	return target;
}

Texture2D* ResRenderTarget::getTexture()
{
	checkTarget();
	return target->getSprite()->getTexture();
}

Texture2D* ResRenderTarget::copyTexture()
{
	auto tex = new Texture2D();
	tex->initWithImage(target->newImage(false), Texture2D::PixelFormat::RGBA8888);
	tex->autorelease();
	return tex;
}

bool ResRenderTarget::checkTarget()
{
	const auto size = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	const auto w = int(size.width);
	const auto h = int(size.height);
	if (w*h == 0)
		return false;
	if (target && autoResize)
	{
		const auto tex = target->getSprite()->getTexture();
		const auto tw = tex->getPixelsWide();
		const auto th = tex->getPixelsHigh();
		if (tw != w || th != h)
		{
			CC_SAFE_DELETE(target);
		}
	}
	// lazy init
	if (!target)
	{
		LINFO("create posteffect buffer, size: (%d, %d)", w, h);
		target = RenderTexture::create(w, h,
			Texture2D::PixelFormat::RGBA8888, GL_DEPTH24_STENCIL8);
		if (!target)
			return false;
		target->retain();
		// skip auto set projection
		target->setKeepMatrix(true);
		// store projection in transform, it's ok because we do not call visit or draw on it
		Mat4 proj;
		Mat4::createOrthographicOffCenter(0, size.width, 0, size.height, -1024.f, 1024.f, &proj);
		target->setNodeToParentTransform(proj);
	}
	return true;
}

bool ResRenderTarget::push()
{
	if (pushed)
		return false;
	if (!checkTarget())
		return false;
	pushed = LRR.pushRenderTarget(this);
	return pushed;
}

bool ResRenderTarget::pop()
{
	if (!pushed)
		return false;
	// TODO: check if the poped is this
	pushed = !LRR.popRenderTarget();
	return !pushed;
}

bool ResRenderTarget::render(ResFX* shader, BlendMode* blend)
{
	// do not render if in use
	if (pushed)
		return false;
	if (!shader)
		return false;
	if (!blend)
		blend = BlendMode::Default;
	return LRR.postEffect(this, shader, blend);
}

string ResRenderTarget::getInfo() const
{
	string info = Resource::getInfo() + cocos2d::StringUtils::format(
		" | autoResize = %s | blendFix = %s | clearColor = %s",
		autoResize ? "true" : "false",
		blendFix ? "true" : "false",
		tostring(clearColor).c_str()
	);
	if (target)
		return info + " | TextureInfo = " + target->getDescription();
	else
		return info;
}

ResRenderTarget::ResRenderTarget(const std::string& name, RenderTexture* tex, bool autoResize_)
	:Resource(ResourceType::RenderTarget, name), target(tex), autoResize(autoResize_)
{
	if (target)
		target->retain();
	clearColor = Color4B(0, 0, 0, 0);
}

ResRenderTarget::~ResRenderTarget()
{
	if (target)
		target->release();
}

ResRenderTarget* ResRenderTarget::create(const std::string& name)
{
	return new (nothrow) ResRenderTarget(name, nullptr, true);
}
