#include "ResSprite.h"
#include "Renderer.h"
#include "AppFrame.h"
#include "LogSystem.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;


void ResSprite::setNormalMap(Texture2D* texture)
{
	normalMap = texture;
}

bool ResSprite::render(float x, float y, float rot, float hscale, float vscale, float z)
{
	return LRR.render(this, x, y, rot, hscale, vscale, z);
}

bool ResSprite::renderRect(float x1, float y1, float x2, float y2)
{
	return LRR.renderRect(this, x1, y1, x2, y2);
}

bool ResSprite::render4v(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3,
	float x4, float y4, float z4)
{
	return LRR.render4V(this, x1, y1, z1, x2, y2, z2, x4, y4, z4, x3, y3, z3);
}

ResSprite* ResSprite::clone(const std::string& newName)
{
	if (newName == resName)
		return this;
	const auto sp = Sprite::createWithSpriteFrame(sprite->getSpriteFrame());
	if (!sp)
	{
		XERROR("failed when creating Sprite.");
		return nullptr;
	}
	auto res = new (nothrow) ResSprite(newName, sp, colliderType, halfSizeX, halfSizeY, resPath);
	if(!res)
	{
		XERROR("failed when creating ResSprite.");
		return nullptr;
	}
	return res;
}

std::unordered_map<std::string, std::string> ResSprite::getInfo() const
{
	auto ret = ResourceQuad::getInfo();
	ret["description"] = sprite->getDescription();
	ret["ra"] = to_string(halfSizeX);
	ret["rb"] = to_string(halfSizeY);
	ret["collider"] = xmath::collision::to_string(colliderType);
	return ret;
}

size_t ResSprite::getMemorySize()
{
	size_t total = sizeof(ResSprite) + resName.size() + resPath.size();
	if (sprite->getReferenceCount() == 1)
		total += sizeof(Sprite);
	if (normalMap && normalMap->getReferenceCount() == 1)
		total += sizeof(Texture2D);
	return total;
}

ResSprite::ResSprite(const std::string& name, Sprite* sprite,
                     XColliderType colliType, double a, double b, const std::string& path)
: ResourceQuad(ResourceType::Sprite, name, colliType, a, b, path), sprite(sprite)
{
	sprite->setColor(Color3B::WHITE);
	sprite->setOpacity(255);
	const auto v = sprite->getQuad();
	ResourceQuad::setVertex(v);
}

ResSprite::~ResSprite()
{
}

ResSprite* ResSprite::create(const std::string& name, ResTexture* texture,
	double x, double y, double w, double h,
	double a, double b, XColliderType colliType)
{
	if (!texture)
		return nullptr;
	const auto sp = Sprite::createWithTexture(
		texture->getTexture(), Rect(x, y, w, h));
	if (!sp)
		return nullptr;
	auto ret = new (nothrow) ResSprite(name, sp, colliType, a, b);
	if (ret)
		ret->resPath = texture->getPath();
	return ret;
}

ResSprite* ResSprite::createWithSprite(const std::string& name, Sprite* sprite, double a, double b,
	XColliderType colliType)
{
	if (!sprite)
		return nullptr;
	return new (nothrow) ResSprite(name, sprite, colliType, a, b);
}
