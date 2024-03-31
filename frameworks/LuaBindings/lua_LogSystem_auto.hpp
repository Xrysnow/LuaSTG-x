#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_LogSystem_lstgLogSystem(lua_State* lua_S);

inline int luaReg_LogSystem(lua_State* lua_S)
{
	luaReg_LogSystem_lstgLogSystem(lua_S);
	return 0;
}
