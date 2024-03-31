#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Buffer_lstgBuffer(lua_State* lua_S);

inline int luaReg_Buffer(lua_State* lua_S)
{
	luaReg_Buffer_lstgBuffer(lua_S);
	return 0;
}
