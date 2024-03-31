#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Random_lstgRandom(lua_State* lua_S);

inline int luaReg_Random(lua_State* lua_S)
{
	luaReg_Random_lstgRandom(lua_S);
	return 0;
}
