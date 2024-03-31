#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_ResourceMgr_lstgResourcePack(lua_State* lua_S);
extern int luaReg_ResourceMgr_lstgResourceMgr(lua_State* lua_S);

inline int luaReg_ResourceMgr(lua_State* lua_S)
{
	luaReg_ResourceMgr_lstgResourcePack(lua_S);
	luaReg_ResourceMgr_lstgResourceMgr(lua_S);
	return 0;
}
