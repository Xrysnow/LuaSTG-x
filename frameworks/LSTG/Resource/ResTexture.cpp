#include "ResTexture.h"
#include "cocos2d.h"
#include "Renderer.h"
#include "AppFrame.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

bool ResTexture::isTextureFlipped()
{
	return XRenderer::isRenderTargetFlipped() &&
		texture->getBackendTexture()->getTextureUsage() == TextureUsage::RENDER_TARGET;
}

void ResTexture::setTriangles(Triangles* tri)
{
	CC_SAFE_RELEASE(xtri);
	xtri = tri;
	CC_SAFE_RETAIN(xtri);
}

bool ResTexture::render(const V3F_C4B_T2F_Quad& quad)
{
	return LRR.renderTexture(this, &quad);
}

bool ResTexture::render(RenderMode* blend, const V3F_C4B_T2F_Quad& quad)
{
	if (!blend)
		return false;
	LRR.updateRenderMode(blend);
	return LRR.renderTexture(this, &quad);
}

std::unordered_map<std::string, std::string> ResTexture::getInfo() const
{
	auto ret = Resource::getInfo();
	ret["format"] = texture->getStringForFormat();
	return ret;
}

ResTexture::ResTexture(const std::string& name, Texture2D* tex)
: Resource(ResourceType::Texture, name), texture(tex)
{
	texture->retain();
	const auto size = texture->getContentSize();
	setTriangles(Triangles::createQuad(Vec2(size)));
}

ResTexture::~ResTexture()
{
	texture->release();
	setTriangles(nullptr);
}

ResTexture* ResTexture::create(const std::string& name, const std::string& path)
{
	try
	{
		const auto data = LRES.getBufferFromFile(path);
		if (!data)
			return nullptr;
		// must use new
		auto image = new Image();
		auto tex = new Texture2D();
		tex->autorelease();
		if (image->initWithImageData(data->data(), data->size()))
		{
			if (tex->initWithImage(image))
			{
				const auto ret = new (nothrow) ResTexture(name, tex);
				if (ret)
					ret->resPath = path;
				// delete
				delete image;
				return ret;
			}
		}
		// delete
		delete image;
	}
	catch (...)
	{
	}
	return nullptr;
}

ResTexture* ResTexture::createWithTexture(const std::string& name, Texture2D* texture)
{
	if (!texture)
		return nullptr;
	return new (nothrow) ResTexture(name, texture);
}
