#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Stream_lstgStream(lua_State* lua_S);
extern int luaReg_Stream_lstgStreamFile(lua_State* lua_S);
extern int luaReg_Stream_lstgStreamMemory(lua_State* lua_S);

inline int luaReg_Stream(lua_State* lua_S)
{
	luaReg_Stream_lstgStream(lua_S);
	luaReg_Stream_lstgStreamFile(lua_S);
	luaReg_Stream_lstgStreamMemory(lua_S);
	return 0;
}
