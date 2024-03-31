#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_StopWatch_lstgStopWatch(lua_State* lua_S);

inline int luaReg_StopWatch(lua_State* lua_S)
{
	luaReg_StopWatch_lstgStopWatch(lua_S);
	return 0;
}
