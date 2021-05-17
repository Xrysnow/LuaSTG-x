#include "lua_ObjSym_auto.hpp"
#include "Symbol/GameObjectSymbol.h"
#include "Symbol/GOSymbolNumber.h"
#include "Symbol/GOSymbolBoolean.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;

#ifndef LUA_CHECK_COBJ_TYPE
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) if(!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
	#else
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) (void)(TYPE);
	#endif
#endif
#ifndef LUA_CHECK_COBJ
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ(L, COBJ, NAME) if(!(COBJ)) { return luaL_error((L), "invalid 'cobj' in '%s'", NAME); }
	#else
		#define LUA_CHECK_COBJ(L, COBJ, NAME)
	#endif
#endif
#ifndef LUA_CHECK_PARAMETER
	#define LUA_CHECK_PARAMETER(L, OK, NAME) if(!(OK)) { return luaL_error((L), "invalid arguments in '%s'", NAME); }
#endif
#ifndef LUA_PARAMETER_ERROR
	#define LUA_PARAMETER_ERROR(L, NAME, ARGC, EXPECT) return luaL_error((L), "wrong number of arguments in '%s': %d, expects %s", NAME, (ARGC), EXPECT);
#endif

int lua_x_ObjSym_ComputeNode_getNumIn(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.ComputeNode";
	constexpr auto LUA_FNAME = "lstg_sym.ComputeNode:getNumIn";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNumIn();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_ComputeNode_getNumOut(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.ComputeNode";
	constexpr auto LUA_FNAME = "lstg_sym.ComputeNode:getNumOut";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNumOut();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_ComputeNode_getType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.ComputeNode";
	constexpr auto LUA_FNAME = "lstg_sym.ComputeNode:getType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_ComputeNode_reset(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.ComputeNode";
	constexpr auto LUA_FNAME = "lstg_sym.ComputeNode:reset";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_ObjSym_ComputeNode_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_ComputeNode(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.ComputeNode");
	tolua_cclass(tolua_S, "ComputeNode", "lstg_sym.ComputeNode", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "ComputeNode");
		tolua_function(tolua_S, "getNumIn", lua_x_ObjSym_ComputeNode_getNumIn);
		tolua_function(tolua_S, "getNumOut", lua_x_ObjSym_ComputeNode_getNumOut);
		tolua_function(tolua_S, "getType", lua_x_ObjSym_ComputeNode_getType);
		tolua_function(tolua_S, "reset", lua_x_ObjSym_ComputeNode_reset);
		{
			tolua_module(tolua_S, "Type", 0);
			tolua_beginmodule(tolua_S, "Type");
			{
				tolua_constant(tolua_S, "Number", (lua_Number)lstg::symbol::ComputeNode::Type::Number);
				tolua_constant(tolua_S, "Boolean", (lua_Number)lstg::symbol::ComputeNode::Type::Boolean);
				tolua_constant(tolua_S, "String", (lua_Number)lstg::symbol::ComputeNode::Type::String);
				tolua_constant(tolua_S, "OprandTypeNum", (lua_Number)lstg::symbol::ComputeNode::Type::OprandTypeNum);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::ComputeNode).name();
	g_luaType[typeName] = "lstg_sym.ComputeNode";
	g_typeCast["ComputeNode"] = "lstg_sym.ComputeNode";
	return 1;
}

static int lua_x_ObjSym_Operand_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Operand(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Operand");
	tolua_cclass(tolua_S, "Operand", "lstg_sym.Operand", "lstg_sym.ComputeNode", nullptr);

	tolua_beginmodule(tolua_S, "Operand");
		{
			tolua_module(tolua_S, "Source", 0);
			tolua_beginmodule(tolua_S, "Source");
			{
				tolua_constant(tolua_S, "Value", (lua_Number)lstg::symbol::Operand::Source::Value);
				tolua_constant(tolua_S, "GameObject", (lua_Number)lstg::symbol::Operand::Source::GameObject);
				tolua_constant(tolua_S, "GameObjectLua", (lua_Number)lstg::symbol::Operand::Source::GameObjectLua);
				tolua_constant(tolua_S, "OprandSourceNum", (lua_Number)lstg::symbol::Operand::Source::OprandSourceNum);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Operand).name();
	g_luaType[typeName] = "lstg_sym.Operand";
	g_typeCast["Operand"] = "lstg_sym.Operand";
	return 1;
}

int lua_x_ObjSym_Operator_addInput(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Operator";
	constexpr auto LUA_FNAME = "lstg_sym.Operator:addInput";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Operator*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::symbol::ComputeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addInput(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Operator_check(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Operator";
	constexpr auto LUA_FNAME = "lstg_sym.Operator:check";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Operator*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->check();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_Operator_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Operator";
	constexpr auto LUA_FNAME = "lstg_sym.Operator:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Operator::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Operator_registBase(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Operator";
	constexpr auto LUA_FNAME = "lstg_sym.Operator:registBase";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		lstg::symbol::Operator::registBase();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_ObjSym_Operator_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Operator(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Operator");
	tolua_cclass(tolua_S, "Operator", "lstg_sym.Operator", "lstg_sym.ComputeNode", nullptr);

	tolua_beginmodule(tolua_S, "Operator");
		tolua_function(tolua_S, "addInput", lua_x_ObjSym_Operator_addInput);
		tolua_function(tolua_S, "check", lua_x_ObjSym_Operator_check);
		tolua_function(tolua_S, "create", lua_x_ObjSym_Operator_create);
		tolua_function(tolua_S, "registBase", lua_x_ObjSym_Operator_registBase);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Operator).name();
	g_luaType[typeName] = "lstg_sym.Operator";
	g_typeCast["Operator"] = "lstg_sym.Operator";
	return 1;
}

static int lua_x_ObjSym_Statement_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Statement(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Statement");
	tolua_cclass(tolua_S, "Statement", "lstg_sym.Statement", "lstg_sym.ComputeNode", nullptr);

	tolua_beginmodule(tolua_S, "Statement");
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Statement).name();
	g_luaType[typeName] = "lstg_sym.Statement";
	g_typeCast["Statement"] = "lstg_sym.Statement";
	return 1;
}

int lua_x_ObjSym_Assigment_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Assigment";
	constexpr auto LUA_FNAME = "lstg_sym.Assigment:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::symbol::ComputeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Assigment::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Assigment_createWithObjProperty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Assigment";
	constexpr auto LUA_FNAME = "lstg_sym.Assigment:createWithObjProperty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		lstg::symbol::ComputeNode* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Assigment::createWithObjProperty(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_x_ObjSym_Assigment_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Assigment(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Assigment");
	tolua_cclass(tolua_S, "Assigment", "lstg_sym.Assigment", "lstg_sym.Statement", nullptr);

	tolua_beginmodule(tolua_S, "Assigment");
		tolua_function(tolua_S, "create", lua_x_ObjSym_Assigment_create);
		tolua_function(tolua_S, "createWithObjProperty", lua_x_ObjSym_Assigment_createWithObjProperty);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Assigment).name();
	g_luaType[typeName] = "lstg_sym.Assigment";
	g_typeCast["Assigment"] = "lstg_sym.Assigment";
	return 1;
}

int lua_x_ObjSym_Block_addOutputNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:addOutputNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::symbol::ComputeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addOutputNode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Block_clear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:clear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clear();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_Block_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Block::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_Block_executeLua(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:executeLua";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 0) {
			cobj->executeLua();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			lstg::GameObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
			if (!ok) { break; }
			cobj->executeLua(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Block_getNumOutput(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:getNumOutput";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNumOutput();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ObjSym_Block_push(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Block";
	constexpr auto LUA_FNAME = "lstg_sym.Block:push";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::symbol::Statement* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->push(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_ObjSym_Block_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Block(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Block");
	tolua_cclass(tolua_S, "Block", "lstg_sym.Block", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Block");
		tolua_function(tolua_S, "addOutputNode", lua_x_ObjSym_Block_addOutputNode);
		tolua_function(tolua_S, "clear", lua_x_ObjSym_Block_clear);
		tolua_function(tolua_S, "execute", lua_x_ObjSym_Block_executeLua);
		tolua_function(tolua_S, "getNumOutput", lua_x_ObjSym_Block_getNumOutput);
		tolua_function(tolua_S, "push", lua_x_ObjSym_Block_push);
		tolua_function(tolua_S, "create", lua_x_ObjSym_Block_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Block).name();
	g_luaType[typeName] = "lstg_sym.Block";
	g_typeCast["Block"] = "lstg_sym.Block";
	return 1;
}

int lua_x_ObjSym_Boolean_createWithObjProperty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Boolean";
	constexpr auto LUA_FNAME = "lstg_sym.Boolean:createWithObjProperty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Boolean::createWithObjProperty(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Boolean_createWithValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Boolean";
	constexpr auto LUA_FNAME = "lstg_sym.Boolean:createWithValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Boolean::createWithValue(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_ObjSym_Boolean_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Boolean(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Boolean");
	tolua_cclass(tolua_S, "Boolean", "lstg_sym.Boolean", "lstg_sym.Operand", nullptr);

	tolua_beginmodule(tolua_S, "Boolean");
		tolua_function(tolua_S, "createWithObjProperty", lua_x_ObjSym_Boolean_createWithObjProperty);
		tolua_function(tolua_S, "createWithValue", lua_x_ObjSym_Boolean_createWithValue);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Boolean).name();
	g_luaType[typeName] = "lstg_sym.Boolean";
	g_typeCast["Boolean"] = "lstg_sym.Boolean";
	return 1;
}

int lua_x_ObjSym_Number_createWithObjProperty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Number";
	constexpr auto LUA_FNAME = "lstg_sym.Number:createWithObjProperty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Number::createWithObjProperty(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ObjSym_Number_createWithValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg_sym.Number";
	constexpr auto LUA_FNAME = "lstg_sym.Number:createWithValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::symbol::Number::createWithValue(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_ObjSym_Number_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ObjSym_Number(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg_sym.Number");
	tolua_cclass(tolua_S, "Number", "lstg_sym.Number", "lstg_sym.Operand", nullptr);

	tolua_beginmodule(tolua_S, "Number");
		tolua_function(tolua_S, "createWithObjProperty", lua_x_ObjSym_Number_createWithObjProperty);
		tolua_function(tolua_S, "createWithValue", lua_x_ObjSym_Number_createWithValue);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::symbol::Number).name();
	g_luaType[typeName] = "lstg_sym.Number";
	g_typeCast["Number"] = "lstg_sym.Number";
	return 1;
}

int register_all_x_ObjSym(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg_sym", 0);
	tolua_beginmodule(tolua_S, "lstg_sym");

	lua_register_x_ObjSym_ComputeNode(tolua_S);
	lua_register_x_ObjSym_Statement(tolua_S);
	lua_register_x_ObjSym_Assigment(tolua_S);
	lua_register_x_ObjSym_Operand(tolua_S);
	lua_register_x_ObjSym_Number(tolua_S);
	lua_register_x_ObjSym_Operator(tolua_S);
	lua_register_x_ObjSym_Boolean(tolua_S);
	lua_register_x_ObjSym_Block(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

