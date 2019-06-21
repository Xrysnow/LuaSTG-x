#include "XRefAdapter.h"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"

using namespace lstg;
using namespace cocos2d;

static auto ADAPTER_FIELD = ".adapter";

static RefAdapter* getRefAdapter(lua_State* L, int idx)
{
	lua_getmetatable(L, idx);
	lua_getfield(L, -1, ADAPTER_FIELD);
	if (lua_isnil(L, -1))
		return nullptr;
	const auto ret = (RefAdapter*)lua_touserdata(L, -1);
	lua_pop(L, 2);
	return ret;
}
static int _retain(lua_State* L)
{
	auto adapter = getRefAdapter(L, 1);
	if (adapter)
		adapter->retain();
	return 0;
}
static int _release(lua_State* L)
{
	auto adapter = getRefAdapter(L, 1);
	if (adapter)
		adapter->release();
	return 0;
}
static int _getReferenceCount(lua_State* L)
{
	auto adapter = getRefAdapter(L, 1);
	if (adapter)
	{
		lua_settop(L, 0);
		lua_pushnumber(L, adapter->getReferenceCount());
		return 1;
	}
	return 0;
}

const char* RefAdapter::getLuaTypeName(const std::string& hashName)
{
	const auto iter = g_luaType.find(hashName);
	if (g_luaType.end() != iter)
		return iter->second.c_str();
	return nullptr;
}

RefAdapter* RefAdapter::_create(void* obj, const std::string& className, const std::function<void(void*)>& dtor)
{
	auto ret = new (std::nothrow) RefAdapter();
	if (ret)
	{
		ret->_ptr = obj;
		ret->_className = className;
		ret->_dtor = dtor;
		ret->_typeName = className;
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}

void RefAdapter::pushLua(lua_State* L)
{
	if (!_ptr)
	{
		lua_pushnil(L);
		return;
	}
	if (_isRef)
	{
		// use c style cast, T may not polymorphic
		auto dynObject = (cocos2d::Ref*)(_ptr);
		const int ID = (int)(dynObject->_ID);
		int* luaID = &(dynObject->_luaID);
		toluafix_pushusertype_ccobject(L, ID, luaID, (void*)_ptr, _className.c_str());
		return;
	}

	lua_pushlightuserdata(L, this);
	lua_gettable(L, LUA_REGISTRYINDEX);
	// obj(R[this])
	if (!lua_isnil(L, -1))
		return;
	lua_pop(L, 1);

	tolua_pushusertype(L, _ptr, _typeName.c_str());

	// obj
	lua_getmetatable(L, -1);
	// obj mt
	lua_pushlightuserdata(L, this);
	// obj mt this
	lua_setfield(L, -2, ADAPTER_FIELD);
	// obj mt
	lua_pop(L, 1);
	// obj
	tolua_function(L, "retain", _retain);
	tolua_function(L, "release", _release);
	tolua_function(L, "getReferenceCount", _getReferenceCount);
	// obj
	lua_pushlightuserdata(L, this);
	// obj this
	lua_pushvalue(L, -2);
	// obj this obj
	lua_settable(L, LUA_REGISTRYINDEX);
	//obj
}

RefAdapter::~RefAdapter()
{
	if (_ptr&&!_isRef)
	{
		const auto L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
		lua_pushlightuserdata(L, this);
		// this
		lua_gettable(L, LUA_REGISTRYINDEX);
		// obj
		lua_pushnil(L);
		// obj nil
		lua_setfield(L, -1, ADAPTER_FIELD);
		// obj
		auto u = (void**)lua_touserdata(L, -1);
		if (u)
			*u = nullptr;
		lua_pop(L, 1);
	}
	if (_dtor)
		_dtor(_ptr);
}
