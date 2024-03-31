#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_ObjSym_lstg_symComputeNode(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symOperand(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symOperator(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symStatement(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symAssigment(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symBlock(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symNumber(lua_State* lua_S);
extern int luaReg_ObjSym_lstg_symBoolean(lua_State* lua_S);

inline int luaReg_ObjSym(lua_State* lua_S)
{
	luaReg_ObjSym_lstg_symComputeNode(lua_S);
	luaReg_ObjSym_lstg_symOperand(lua_S);
	luaReg_ObjSym_lstg_symOperator(lua_S);
	luaReg_ObjSym_lstg_symStatement(lua_S);
	luaReg_ObjSym_lstg_symAssigment(lua_S);
	luaReg_ObjSym_lstg_symBlock(lua_S);
	luaReg_ObjSym_lstg_symNumber(lua_S);
	luaReg_ObjSym_lstg_symBoolean(lua_S);
	return 0;
}
