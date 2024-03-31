#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_BentLaser_lstgGameObjectBentLaser(lua_State* lua_S);

inline int luaReg_BentLaser(lua_State* lua_S)
{
	luaReg_BentLaser_lstgGameObjectBentLaser(lua_S);
	return 0;
}
