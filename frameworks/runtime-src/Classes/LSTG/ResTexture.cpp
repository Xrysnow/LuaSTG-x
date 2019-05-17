#include "ResTexture.h"
#include "cocos2d.h"
//#include "LogSystem.h"
#include "Renderer.h"
#include "AppFrame.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

void ResTexture::setTriangles(Triangles* tri)
{
	CC_SAFE_RELEASE(xtri);
	xtri = tri;
	CC_SAFE_RETAIN(xtri);
}

bool ResTexture::render(const V3F_C4B_T2F_Quad& quad)
{
	const auto q = LMP.getQuad();
	*q = quad;
	return LRR.renderTexture(this, q);
}

bool ResTexture::render(BlendMode* blend, const V3F_C4B_T2F_Quad& quad)
{
	const auto q = LMP.getQuad();
	*q = quad;
	LRR.updateBlendMode(blend);
	return LRR.renderTexture(this, q);
}

string ResTexture::getInfo() const
{
	return Resource::getInfo() + " | TexInfo = " + texture->getDescription();
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
