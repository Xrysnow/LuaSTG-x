#include "ResBase.h"
#include <scripting/lua-bindings/manual/tolua_fix.h>
#include "LogSystem.h"
#include "Util/Utility.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

std::unordered_set<Resource*> Resource::instances;

void Resource::destroyInstances()
{
	//for (auto& p : instances)
	//	delete p;
	LINFO("%s: %d Resource instances not destructed", __FUNCTION__, instances.size());
	instances.clear();
}

// TODO: move to lua
std::unordered_map<std::string, std::string> Resource::getInfo() const
{
	std::unordered_map<std::string, std::string> ret = {
		{"type", tostring(resType)},
		{"name", resName } };
	if (!resPath.empty())
		ret["path"] = resPath;
	return ret;
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
	instances.insert(this);
	autorelease();
}

Resource::~Resource()
{
	instances.erase(this);
}

std::unordered_map<std::string, std::string> ResourceColliable::getInfo() const
{
	auto ret = Resource::getInfo();
	ret["ra"] = to_string(halfSizeX);
	ret["rb"] = to_string(halfSizeX);
	ret["collider"] = xmath::collision::to_string(colliderType);
	return ret;
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

std::unordered_map<std::string, std::string> ResourceQuad::getInfo() const
{
	auto ret = ResourceColliable::getInfo();
	ret["render_mode"] = getRenderMode()->getName();
	ret["color"] = tostring(vertex.tl.colors);
	return ret;
}

ResourceQuad::ResourceQuad(
	ResourceType t, const std::string& name,
	XColliderType colliType, double a, double b, const std::string& path)
: ResourceColliable(t, name, colliType, a, b, path)
{
	ResourceQuad::setColor(Color4B::WHITE);
}
