#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_WindowHelper_lstgWindowHelper(lua_State* lua_S);
extern int luaReg_WindowHelper_lstgMonitorHelper(lua_State* lua_S);

inline int luaReg_WindowHelper(lua_State* lua_S)
{
	luaReg_WindowHelper_lstgWindowHelper(lua_S);
	luaReg_WindowHelper_lstgMonitorHelper(lua_S);
	return 0;
}
