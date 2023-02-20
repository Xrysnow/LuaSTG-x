#include "ResRenderTarget.h"
#include "LogSystem.h"
#include "Renderer.h"
#include "Util/Utility.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

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
	if (checkTarget())
		return target;
	return nullptr;
}

Texture2D* ResRenderTarget::getTexture()
{
	if (checkTarget())
		return target->getSprite()->getTexture();
	return nullptr;
}

Texture2D* ResRenderTarget::copyTexture(bool flip)
{
	auto tex = new Texture2D();
	tex->autorelease();
	Image* img = nullptr;
	target->newImage([&](Image* i) { img = i; }, flip);
	if (img)
	{
		tex->initWithImage(img, backend::PixelFormat::RGBA8888);
		return tex;
	}
	return nullptr;
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
		target = RenderTexture::create(
			w,
			h,
			backend::PixelFormat::RGBA8888,
			backend::PixelFormat::D24S8, 
			false);
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
	//TODO: check if the poped is this
	pushed = !LRR.popRenderTarget();
	return !pushed;
}

bool ResRenderTarget::render(ResFX* shader, RenderMode* blend)
{
	// do not render if in use
	if (pushed)
	{
		XWARNING("not poped");
		return false;
	}
	if (!shader)
	{
		XWARNING("no shader");
		return false;
	}
	if (!blend)
		blend = RenderMode::getDefault();
	return LRR.postEffect(this, shader, blend);
}

std::unordered_map<std::string, std::string> ResRenderTarget::getInfo() const
{
	auto ret = Resource::getInfo();
	ret["auto_resize"] = autoResize ? "true" : "false";
	ret["clear_color"] = tostring(clearColor);
	if (target)
		ret["description"] = target->getDescription();
	return ret;
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
