#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Triangles_lstgTriangles(lua_State* lua_S);

inline int luaReg_Triangles(lua_State* lua_S)
{
	luaReg_Triangles_lstgTriangles(lua_S);
	return 0;
}
