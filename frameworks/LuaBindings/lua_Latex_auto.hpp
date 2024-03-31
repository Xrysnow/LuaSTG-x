#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Latex_lstgLatex(lua_State* lua_S);

inline int luaReg_Latex(lua_State* lua_S)
{
	luaReg_Latex_lstgLatex(lua_S);
	return 0;
}
