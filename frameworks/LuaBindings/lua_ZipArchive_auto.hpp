#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_ZipArchive_lstgZipArchive(lua_State* lua_S);

inline int luaReg_ZipArchive(lua_State* lua_S)
{
	luaReg_ZipArchive_lstgZipArchive(lua_S);
	return 0;
}
