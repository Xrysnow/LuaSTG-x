#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_FileDialog_lstgFileDialog(lua_State* lua_S);

inline int luaReg_FileDialog(lua_State* lua_S)
{
	luaReg_FileDialog_lstgFileDialog(lua_S);
	return 0;
}
