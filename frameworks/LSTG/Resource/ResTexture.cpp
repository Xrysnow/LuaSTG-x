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
	triangles = tri;
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

size_t ResTexture::getMemorySize()
{
	size_t total = sizeof(ResRenderTarget) + resName.size() + resPath.size();
	if (texture->getReferenceCount() == 1)
		total += sizeof(Texture2D);
	if (triangles && triangles->getReferenceCount() == 1)
		total += sizeof(Triangles) + triangles->getVertexCount() * sizeof(V3F_C4B_T2F) + triangles->getIndexCount() * sizeof(unsigned short);
	return total;
}

ResTexture::ResTexture(const std::string& name, Texture2D* tex)
: Resource(ResourceType::Texture, name), texture(tex)
{
	const auto size = texture->getContentSize();
	setTriangles(Triangles::createQuad(Vec2(size)).get());
}

ResTexture::~ResTexture()
{
	setTriangles(nullptr);
}

cc::IntrusivePtr<ResTexture> ResTexture::create(const std::string& name, const std::string& path)
{
	try
	{
		const auto data = LRES.getFileData(path);
		if (!data)
			return nullptr;
		cc::IntrusivePtr<Image> image{new Image()};
		cc::IntrusivePtr<Texture2D> tex{new Texture2D()};
		if (image->initWithImageData(data->data(), data->size()))
		{
			if (tex->initWithImage(image.get()))
			{
				cc::IntrusivePtr<ResTexture> ret{new (nothrow) ResTexture(name, tex.get())};
				if (ret)
					ret->resPath = path;
				return Resource::finishConstruction(std::move(ret));
			}
		}
	}
	catch (...)
	{
	}
	return nullptr;
}

cc::IntrusivePtr<ResTexture> ResTexture::createWithTexture(const std::string& name, Texture2D* texture)
{
	if (!texture)
		return nullptr;
	cc::IntrusivePtr<ResTexture> owner{new (nothrow) ResTexture(name, texture)};
	return Resource::finishConstruction(std::move(owner));
}
