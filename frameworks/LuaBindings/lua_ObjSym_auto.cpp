#include "lua_ObjSym_auto.hpp"
#include "Symbol/GameObjectSymbol.h"
#include "Symbol/GOSymbolNumber.h"
#include "Symbol/GOSymbolBoolean.h"

int lua_lstg_symbol_ComputeNode_getNumIn(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.ComputeNode", "lstg_sym.ComputeNode:getNumIn");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::ComputeNode::getNumIn);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_ComputeNode_getNumOut(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.ComputeNode", "lstg_sym.ComputeNode:getNumOut");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::ComputeNode::getNumOut);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_ComputeNode_getType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.ComputeNode", "lstg_sym.ComputeNode:getType");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::ComputeNode::getType);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_ComputeNode_reset(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.ComputeNode", "lstg_sym.ComputeNode:reset");
	LUA_TRY_INVOKE(0, &lstg::symbol::ComputeNode::reset);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_ObjSym_lstg_symComputeNode(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::ComputeNode, "ComputeNode", "lstg_sym.ComputeNode",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getNumIn", lua_lstg_symbol_ComputeNode_getNumIn);
	LUA_METHOD("getNumOut", lua_lstg_symbol_ComputeNode_getNumOut);
	LUA_METHOD("getType", lua_lstg_symbol_ComputeNode_getType);
	LUA_METHOD("reset", lua_lstg_symbol_ComputeNode_reset);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Operand__setBoolean(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Operand", "lstg_sym.Operand:_setBoolean");
	LUA_TRY_INVOKE(1, &lstg::symbol::Operand::_setBoolean);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_symbol_Operand__setNumber(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Operand", "lstg_sym.Operand:_setNumber");
	LUA_TRY_INVOKE(1, &lstg::symbol::Operand::_setNumber);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_ObjSym_lstg_symOperand(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Operand, "Operand", "lstg_sym.Operand",
		lstg::symbol::ComputeNode, "lstg_sym.ComputeNode",
		nullptr, nullptr);
	LUA_METHOD("_setBoolean", lua_lstg_symbol_Operand__setBoolean);
	LUA_METHOD("_setNumber", lua_lstg_symbol_Operand__setNumber);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Operator_addInput(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Operator", "lstg_sym.Operator:addInput");
	LUA_TRY_INVOKE(1, &lstg::symbol::Operator::addInput);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_symbol_Operator_check(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Operator", "lstg_sym.Operator:check");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::Operator::check);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_Operator_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Operator", "lstg_sym.Operator:create");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Operator::create);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_symbol_Operator_registBase(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Operator", "lstg_sym.Operator:registBase");
	LUA_TRY_INVOKE(0, &lstg::symbol::Operator::registBase);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_ObjSym_lstg_symOperator(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Operator, "Operator", "lstg_sym.Operator",
		lstg::symbol::ComputeNode, "lstg_sym.ComputeNode",
		nullptr, nullptr);
	LUA_METHOD("addInput", lua_lstg_symbol_Operator_addInput);
	LUA_METHOD("check", lua_lstg_symbol_Operator_check);
	LUA_METHOD("create", lua_lstg_symbol_Operator_create);
	LUA_METHOD("registBase", lua_lstg_symbol_Operator_registBase);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int luaReg_ObjSym_lstg_symStatement(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Statement, "Statement", "lstg_sym.Statement",
		lstg::symbol::ComputeNode, "lstg_sym.ComputeNode",
		nullptr, nullptr);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Assigment_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Assigment", "lstg_sym.Assigment:create");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Assigment::create);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_symbol_Assigment_createWithObjProperty(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Assigment", "lstg_sym.Assigment:createWithObjProperty");
	LUA_TRY_INVOKE_R(2, &lstg::symbol::Assigment::createWithObjProperty);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_ObjSym_lstg_symAssigment(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Assigment, "Assigment", "lstg_sym.Assigment",
		lstg::symbol::Statement, "lstg_sym.Statement",
		nullptr, nullptr);
	LUA_METHOD("create", lua_lstg_symbol_Assigment_create);
	LUA_METHOD("createWithObjProperty", lua_lstg_symbol_Assigment_createWithObjProperty);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Block_addOutputNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:addOutputNode");
	LUA_TRY_INVOKE(1, &lstg::symbol::Block::addOutputNode);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_symbol_Block_clear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:clear");
	LUA_TRY_INVOKE(0, &lstg::symbol::Block::clear);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_Block_executeLua(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:executeLua");
	LUA_TRY_INVOKE(1, static_cast<void(lstg::symbol::Block::*)(lstg::GameObject*)>(&lstg::symbol::Block::executeLua));
	LUA_TRY_INVOKE(0, static_cast<void(lstg::symbol::Block::*)()>(&lstg::symbol::Block::executeLua));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_symbol_Block_getNumOutput(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:getNumOutput");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::Block::getNumOutput);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_symbol_Block_push(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:push");
	LUA_TRY_INVOKE(1, &lstg::symbol::Block::push);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_symbol_Block_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Block", "lstg_sym.Block:create");
	LUA_TRY_INVOKE_R(0, &lstg::symbol::Block::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_ObjSym_lstg_symBlock(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Block, "Block", "lstg_sym.Block",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("addOutputNode", lua_lstg_symbol_Block_addOutputNode);
	LUA_METHOD("clear", lua_lstg_symbol_Block_clear);
	LUA_METHOD("executeLua", lua_lstg_symbol_Block_executeLua);
	LUA_METHOD("getNumOutput", lua_lstg_symbol_Block_getNumOutput);
	LUA_METHOD("push", lua_lstg_symbol_Block_push);
	LUA_METHOD("create", lua_lstg_symbol_Block_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Number_createWithObjProperty(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Number", "lstg_sym.Number:createWithObjProperty");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Number::createWithObjProperty);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_symbol_Number_createWithValue(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Number", "lstg_sym.Number:createWithValue");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Number::createWithValue);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_ObjSym_lstg_symNumber(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Number, "Number", "lstg_sym.Number",
		lstg::symbol::Operand, "lstg_sym.Operand",
		nullptr, nullptr);
	LUA_METHOD("createWithObjProperty", lua_lstg_symbol_Number_createWithObjProperty);
	LUA_METHOD("createWithValue", lua_lstg_symbol_Number_createWithValue);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_symbol_Boolean_createWithObjProperty(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Boolean", "lstg_sym.Boolean:createWithObjProperty");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Boolean::createWithObjProperty);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_symbol_Boolean_createWithValue(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg_sym.Boolean", "lstg_sym.Boolean:createWithValue");
	LUA_TRY_INVOKE_R(1, &lstg::symbol::Boolean::createWithValue);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_ObjSym_lstg_symBoolean(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_CLS_DEF_BASE(lstg::symbol::Boolean, "Boolean", "lstg_sym.Boolean",
		lstg::symbol::Operand, "lstg_sym.Operand",
		nullptr, nullptr);
	LUA_METHOD("createWithObjProperty", lua_lstg_symbol_Boolean_createWithObjProperty);
	LUA_METHOD("createWithValue", lua_lstg_symbol_Boolean_createWithValue);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
