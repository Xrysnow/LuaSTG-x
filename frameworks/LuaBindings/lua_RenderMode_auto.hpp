#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_RenderMode_lstgRenderMode(lua_State* lua_S);

inline int luaReg_RenderMode(lua_State* lua_S)
{
	luaReg_RenderMode_lstgRenderMode(lua_S);
	return 0;
}
