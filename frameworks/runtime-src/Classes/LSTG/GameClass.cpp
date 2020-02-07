#include "GameClass.h"
#include "UtilLua.h"

#define KEY_FRAME_FUNC(_P) (void*)((size_t)(_P) + 1)
#define KEY_RENDER_FUNC(_P) (void*)((size_t)(_P) + 2)

using namespace lstg;

std::array<GameClass, GameClass::MAX_CLASS_COUNT> GameClass::classes;
cocos2d::Map<uint32_t, symbol::Block*> GameClass::classFrameBlocks;

GameClass::GameClass()
{
}

GameClass::~GameClass()
{
}

GameClass* GameClass::registerClass(lua_State* L)
{
	const auto argc = lua_gettop(L);
	if (argc == 0)
		return nullptr;

	symbol::Block* bk = nullptr;
	if (argc > 1)
	{
		//bk = tolua_tousertype<symbol::Block>(L, 2, "lstg_sym.Block");
		bk = (symbol::Block*)tolua_tousertype(L, 2, nullptr);
		lua_settop(L, 1);
	}

	lua_rawgeti(L, 1, 7);  // t(class) cid
	const auto cid = lua_tointeger(L, -1);
	lua_pop(L, 1);  // t(class)
	// note: if lua value cannot convert to number, lua_tointeger will return 0
	if (cid <= 0 || cid > MAX_CLASS_COUNT)
		return nullptr;
	const auto ret = &classes[cid - 1];
	ret->id = cid;
	ret->isDefaultFrame = false;
	ret->isDefaultRender = false;
	ret->extProperty = false;
	ret->is3D = false;
	ret->frameBlock = nullptr;

	if (bk)
	{
		classFrameBlocks.insert(cid, bk);
		ret->frameBlock = bk;
	}

	lua_pushlightuserdata(L, ret);
	lua_pushvalue(L, 1);  // t(class) key t(class)
	lua_settable(L, LUA_REGISTRYINDEX);

	lua_pushlightuserdata(L, KEY_FRAME_FUNC(ret));
	lua_rawgeti(L, 1, LGOBJ_CC_FRAME);  // t(class) key f(frame)
	if (lua_isnil(L, -1))
	{
		ret->isDefaultFrame = true;
		lua_pop(L, 2);
	}
	else
	{
		lua_settable(L, LUA_REGISTRYINDEX);  
	}
	// t(class)
	lua_pushlightuserdata(L, KEY_RENDER_FUNC(ret));
	lua_rawgeti(L, 1, LGOBJ_CC_RENDER);  // t(class) key f(render)
	if (lua_isnil(L, -1))
	{
		ret->isDefaultRender = true;
		lua_pop(L, 2);
	}
	else
	{
		lua_settable(L, LUA_REGISTRYINDEX);
	}
	// t(class)
	lua_pushstring(L, ".x");
	lua_rawget(L, 1);  // t(class) t[".x"]
	if (lua_toboolean(L, -1) != 0)
		ret->extProperty = true;
	lua_pop(L, 1);  // t(class)
	lua_pushstring(L, ".3d");
	lua_rawget(L, 1);  // t(class) t[".3d"]
	if (lua_toboolean(L, -1) != 0)
		ret->is3D = true;
	lua_pop(L, 1);  // t(class)

	return ret;
}

GameClass* GameClass::getByID(uint32_t cid)
{
	if (cid == 0 || cid > MAX_CLASS_COUNT)
		return nullptr;
	const auto ret = &classes[cid - 1];
	return (ret->id == cid) ? ret : nullptr;
}

void GameClass::clear(lua_State* L)
{
	for (auto& cls : classes)
	{
		for (auto& ptr : {
			(void*)&cls,
			KEY_FRAME_FUNC(&cls),
			KEY_RENDER_FUNC(&cls)
		})
		{
			lua_pushlightuserdata(L, ptr);
			lua_pushnil(L);
			lua_settable(L, LUA_REGISTRYINDEX);
		}
	}
	classFrameBlocks.clear();
}

void GameClass::pushLua(lua_State* L)
{
	lua_pushlightuserdata(L, this);
	lua_gettable(L, LUA_REGISTRYINDEX);
}

void GameClass::pushLuaFrameFunc(lua_State* L)
{
	lua_pushlightuserdata(L, KEY_FRAME_FUNC(this));
	lua_gettable(L, LUA_REGISTRYINDEX);
}

void GameClass::pushLuaRenderFunc(lua_State* L)
{
	lua_pushlightuserdata(L, KEY_RENDER_FUNC(this));
	lua_gettable(L, LUA_REGISTRYINDEX);
}
