#include "ResBase.h"
#include <scripting/lua-bindings/manual/tolua_fix.h>
#include "Utility.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

// TODO: move to lua
string Resource::getInfo() const
{
	return "Type: " + tostring(resType) + " | Name: " + resName;
}

void Resource::pushLua(lua_State* L)
{
	toluafix_pushusertype_ccobject(L, (int)_ID, &_luaID, (void*)this, toluatype(resType));
}

Resource* Resource::fromLua(lua_State* L, int idx, ResourceType type)
{
	tolua_Error tolua_err;
	if (!tolua_isusertype(L, idx, toluatype(type), 0, &tolua_err))
		return nullptr;
	return static_cast<Resource*>(tolua_tousertype(L, idx, nullptr));
}

Resource::Resource(ResourceType t, const std::string& name, const string& path)
: resType(t), resName(name), resPath(path)
{
	autorelease();
}

Resource::~Resource()
{
}

std::string ResourceColliable::getInfo() const
{
	return Resource::getInfo() +
		StringUtils::format(" | Half size: (%.3f, %.3f) | Collider type: %s",
			halfSizeX, halfSizeY, xmath::collision::to_string(colliderType));
}

ResourceColliable::ResourceColliable(
	ResourceType t, const std::string& name, XColliderType colliType, const std::string& path)
: Resource(t, name, path), colliderType(colliType)
{
}

ResourceColliable::ResourceColliable(
	ResourceType t, const std::string& name, XColliderType colliType, double a, double b,
	const std::string& path)
	: Resource(t, name, path), colliderType(colliType), halfSizeX(a), halfSizeY(b)
{
}

ResourceColliable::~ResourceColliable()
{
}

void ResourceQuad::setColor(const Color4B& color)
{
	vertex.tl.colors = color;
	vertex.bl.colors = color;
	vertex.tr.colors = color;
	vertex.br.colors = color;
}

void ResourceQuad::setColor(const Color4B& color, int i)
{
	switch (i)
	{
	case 0:
		vertex.tl.colors = color;
		break;
	case 1:
		vertex.tr.colors = color;
		break;
	case 2:
		vertex.bl.colors = color;
		break;
	case 3:
		vertex.br.colors = color;
		break;
	default:
		break;
	}
}

void ResourceQuad::setAlpha(uint8_t alpha)
{
	vertex.tl.colors.a = alpha;
	vertex.bl.colors.a = alpha;
	vertex.tr.colors.a = alpha;
	vertex.br.colors.a = alpha;
}

Color4B ResourceQuad::getColor(int i) const
{
	switch (i)
	{
	case 0: return vertex.tl.colors;
	case 1: return vertex.tr.colors;
	case 2: return vertex.bl.colors;
	case 3: return vertex.br.colors;
	default: return vertex.tl.colors;
	}
}

string ResourceQuad::getInfo() const
{
	return ResourceColliable::getInfo() +
		" | BlendMode: " + getBlendMode()->getName() +
		" | Color0: " + tostring(vertex.tl.colors);
}

ResourceQuad::ResourceQuad(
	ResourceType t, const std::string& name,
	XColliderType colliType, double a, double b, const std::string& path)
: ResourceColliable(t, name, colliType, a, b, path)
{
	ResourceQuad::setColor(Color4B::WHITE);
}
