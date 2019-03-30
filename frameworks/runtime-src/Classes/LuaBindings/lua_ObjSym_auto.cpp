#include "lua_ObjSym_auto.hpp"
#include "GameObjectSymbol.h"
#include "GOSymbolNumber.h"
#include "GOSymbolBoolean.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLua.h"

int lua_x_ObjSym_ComputeNode_reset(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::ComputeNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.ComputeNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_ComputeNode_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_ComputeNode_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.ComputeNode:reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_ComputeNode_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_ComputeNode_getType(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::ComputeNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.ComputeNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_ComputeNode_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_ComputeNode_getType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.ComputeNode:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_ComputeNode_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_ComputeNode_getNumOut(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::ComputeNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.ComputeNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_ComputeNode_getNumOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_ComputeNode_getNumOut'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getNumOut();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.ComputeNode:getNumOut",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_ComputeNode_getNumOut'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_ComputeNode_getNumIn(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::ComputeNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.ComputeNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::ComputeNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_ComputeNode_getNumIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_ComputeNode_getNumIn'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getNumIn();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.ComputeNode:getNumIn",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_ComputeNode_getNumIn'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_ObjSym_ComputeNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComputeNode)");
    return 0;
}

int lua_register_x_ObjSym_ComputeNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.ComputeNode");
    tolua_cclass(tolua_S,"ComputeNode","lstg_sym.ComputeNode","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ComputeNode");
        tolua_function(tolua_S,"reset",lua_x_ObjSym_ComputeNode_reset);
        tolua_function(tolua_S,"getType",lua_x_ObjSym_ComputeNode_getType);
        tolua_function(tolua_S,"getNumOut",lua_x_ObjSym_ComputeNode_getNumOut);
        tolua_function(tolua_S,"getNumIn",lua_x_ObjSym_ComputeNode_getNumIn);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::ComputeNode).name();
    g_luaType[typeName] = "lstg_sym.ComputeNode";
    g_typeCast["ComputeNode"] = "lstg_sym.ComputeNode";
    return 1;
}

static int lua_x_ObjSym_Operand_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Operand)");
    return 0;
}

int lua_register_x_ObjSym_Operand(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Operand");
    tolua_cclass(tolua_S,"Operand","lstg_sym.Operand","lstg_sym.ComputeNode",nullptr);

    tolua_beginmodule(tolua_S,"Operand");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Operand).name();
    g_luaType[typeName] = "lstg_sym.Operand";
    g_typeCast["Operand"] = "lstg_sym.Operand";
    return 1;
}

int lua_x_ObjSym_Operator_addInput(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Operator* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Operator",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Operator*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Operator_addInput'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::symbol::ComputeNode* arg0;

        ok &= luaval_to_object<lstg::symbol::ComputeNode>(tolua_S, 2, "lstg_sym.ComputeNode",&arg0, "lstg_sym.Operator:addInput");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Operator_addInput'", nullptr);
            return 0;
        }
        cobj->addInput(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Operator:addInput",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Operator_addInput'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Operator_check(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Operator* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Operator",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Operator*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Operator_check'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Operator_check'", nullptr);
            return 0;
        }
        bool ret = cobj->check();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Operator:check",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Operator_check'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Operator_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Operator",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg_sym.Operator:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Operator_create'", nullptr);
            return 0;
        }
        lstg::symbol::Operator* ret = lstg::symbol::Operator::create(arg0);
        object_to_luaval<lstg::symbol::Operator>(tolua_S, "lstg_sym.Operator",(lstg::symbol::Operator*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Operator:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Operator_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_ObjSym_Operator_registBase(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Operator",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Operator_registBase'", nullptr);
            return 0;
        }
        lstg::symbol::Operator::registBase();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Operator:registBase",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Operator_registBase'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ObjSym_Operator_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Operator)");
    return 0;
}

int lua_register_x_ObjSym_Operator(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Operator");
    tolua_cclass(tolua_S,"Operator","lstg_sym.Operator","lstg_sym.ComputeNode",nullptr);

    tolua_beginmodule(tolua_S,"Operator");
        tolua_function(tolua_S,"addInput",lua_x_ObjSym_Operator_addInput);
        tolua_function(tolua_S,"check",lua_x_ObjSym_Operator_check);
        tolua_function(tolua_S,"create", lua_x_ObjSym_Operator_create);
        tolua_function(tolua_S,"registBase", lua_x_ObjSym_Operator_registBase);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Operator).name();
    g_luaType[typeName] = "lstg_sym.Operator";
    g_typeCast["Operator"] = "lstg_sym.Operator";
    return 1;
}

static int lua_x_ObjSym_Statement_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Statement)");
    return 0;
}

int lua_register_x_ObjSym_Statement(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Statement");
    tolua_cclass(tolua_S,"Statement","lstg_sym.Statement","lstg_sym.ComputeNode",nullptr);

    tolua_beginmodule(tolua_S,"Statement");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Statement).name();
    g_luaType[typeName] = "lstg_sym.Statement";
    g_typeCast["Statement"] = "lstg_sym.Statement";
    return 1;
}

int lua_x_ObjSym_Assigment_createWithObjProperty(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Assigment",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        lstg::symbol::ComputeNode* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg_sym.Assigment:createWithObjProperty");
        ok &= luaval_to_object<lstg::symbol::ComputeNode>(tolua_S, 3, "lstg_sym.ComputeNode",&arg1, "lstg_sym.Assigment:createWithObjProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Assigment_createWithObjProperty'", nullptr);
            return 0;
        }
        lstg::symbol::Assigment* ret = lstg::symbol::Assigment::createWithObjProperty(arg0, arg1);
        object_to_luaval<lstg::symbol::Assigment>(tolua_S, "lstg_sym.Assigment",(lstg::symbol::Assigment*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Assigment:createWithObjProperty",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Assigment_createWithObjProperty'.",&tolua_err);
#endif
    return 0;
}
int lua_x_ObjSym_Assigment_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "lstg_sym.Assigment", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		lstg::symbol::ComputeNode* arg0;
		ok &= luaval_to_object<lstg::symbol::ComputeNode>(tolua_S, 2, "lstg_sym.ComputeNode", &arg0, "lstg_sym.Assigment:create");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_ObjSym_Assigment_create'", nullptr);
			return 0;
		}
		lstg::symbol::Assigment* ret = lstg::symbol::Assigment::create(arg0);
		object_to_luaval<lstg::symbol::Assigment>(tolua_S, "lstg_sym.Assigment", (lstg::symbol::Assigment*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Assigment:create", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_ObjSym_Assigment_create'.", &tolua_err);
#endif
				return 0;
}

static int lua_x_ObjSym_Assigment_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Assigment)");
    return 0;
}

int lua_register_x_ObjSym_Assigment(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Assigment");
    tolua_cclass(tolua_S,"Assigment","lstg_sym.Assigment","lstg_sym.Statement",nullptr);

    tolua_beginmodule(tolua_S,"Assigment");
        tolua_function(tolua_S,"createWithObjProperty", lua_x_ObjSym_Assigment_createWithObjProperty);
		tolua_function(tolua_S, "create", lua_x_ObjSym_Assigment_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Assigment).name();
    g_luaType[typeName] = "lstg_sym.Assigment";
    g_typeCast["Assigment"] = "lstg_sym.Assigment";
    return 1;
}

int lua_x_ObjSym_Block_getNumOutput(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Block* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Block_getNumOutput'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_getNumOutput'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getNumOutput();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Block:getNumOutput",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_getNumOutput'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Block_clear(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Block* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Block_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Block:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Block_addOutputNode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Block* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Block_addOutputNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::symbol::ComputeNode* arg0;

        ok &= luaval_to_object<lstg::symbol::ComputeNode>(tolua_S, 2, "lstg_sym.ComputeNode",&arg0, "lstg_sym.Block:addOutputNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_addOutputNode'", nullptr);
            return 0;
        }
        cobj->addOutputNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Block:addOutputNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_addOutputNode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Block_push(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Block* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Block_push'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::symbol::Statement* arg0;

        ok &= luaval_to_object<lstg::symbol::Statement>(tolua_S, 2, "lstg_sym.Statement",&arg0, "lstg_sym.Block:push");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_push'", nullptr);
            return 0;
        }
        cobj->push(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Block:push",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_push'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Block_executeLua(lua_State* tolua_S)
{
    int argc = 0;
    lstg::symbol::Block* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::symbol::Block*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ObjSym_Block_executeLua'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::GameObject* arg0;

        ok &= lstg::lua::luaval_to_GameObject(tolua_S, 2, &arg0, "lstg_sym.Block:executeLua");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_executeLua'", nullptr);
            return 0;
        }
		//lua_settop(tolua_S, 0);
		//lstg::stackDump(tolua_S);
        cobj->executeLua(arg0);
		//lstg::stackDump(tolua_S);
        //lua_settop(tolua_S, 1);
        return cobj->getNumOutput();
    }
	if (argc == 0)
	{
		cobj->executeLua();
		return cobj->getNumOutput();
	}
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg_sym.Block:executeLua",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_executeLua'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ObjSym_Block_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Block",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Block_create'", nullptr);
            return 0;
        }
        lstg::symbol::Block* ret = lstg::symbol::Block::create();
        object_to_luaval<lstg::symbol::Block>(tolua_S, "lstg_sym.Block",(lstg::symbol::Block*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Block:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Block_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ObjSym_Block_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Block)");
    return 0;
}

int lua_register_x_ObjSym_Block(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Block");
    tolua_cclass(tolua_S,"Block","lstg_sym.Block","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Block");
        tolua_function(tolua_S,"getNumOutput",lua_x_ObjSym_Block_getNumOutput);
        tolua_function(tolua_S,"clear",lua_x_ObjSym_Block_clear);
        tolua_function(tolua_S,"addOutputNode",lua_x_ObjSym_Block_addOutputNode);
        tolua_function(tolua_S,"push",lua_x_ObjSym_Block_push);
        tolua_function(tolua_S,"execute",lua_x_ObjSym_Block_executeLua);
        tolua_function(tolua_S,"create", lua_x_ObjSym_Block_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Block).name();
    g_luaType[typeName] = "lstg_sym.Block";
    g_typeCast["Block"] = "lstg_sym.Block";
    return 1;
}

int lua_x_ObjSym_Number_createWithValue(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Number",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg_sym.Number:createWithValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Number_createWithValue'", nullptr);
            return 0;
        }
        lstg::symbol::Number* ret = lstg::symbol::Number::createWithValue(arg0);
        object_to_luaval<lstg::symbol::Number>(tolua_S, "lstg_sym.Number",(lstg::symbol::Number*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Number:createWithValue",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Number_createWithValue'.",&tolua_err);
#endif
    return 0;
}
int lua_x_ObjSym_Number_createWithObjProperty(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Number",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg_sym.Number:createWithObjProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Number_createWithObjProperty'", nullptr);
            return 0;
        }
        lstg::symbol::Number* ret = lstg::symbol::Number::createWithObjProperty(arg0);
        object_to_luaval<lstg::symbol::Number>(tolua_S, "lstg_sym.Number",(lstg::symbol::Number*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Number:createWithObjProperty",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Number_createWithObjProperty'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ObjSym_Number_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Number)");
    return 0;
}

int lua_register_x_ObjSym_Number(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Number");
    tolua_cclass(tolua_S,"Number","lstg_sym.Number","lstg_sym.Operand",nullptr);

    tolua_beginmodule(tolua_S,"Number");
        tolua_function(tolua_S,"createWithValue", lua_x_ObjSym_Number_createWithValue);
        tolua_function(tolua_S,"createWithObjProperty", lua_x_ObjSym_Number_createWithObjProperty);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Number).name();
    g_luaType[typeName] = "lstg_sym.Number";
    g_typeCast["Number"] = "lstg_sym.Number";
    return 1;
}

int lua_x_ObjSym_Boolean_createWithValue(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Boolean",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg_sym.Boolean:createWithValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Boolean_createWithValue'", nullptr);
            return 0;
        }
        lstg::symbol::Boolean* ret = lstg::symbol::Boolean::createWithValue(arg0);
        object_to_luaval<lstg::symbol::Boolean>(tolua_S, "lstg_sym.Boolean",(lstg::symbol::Boolean*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Boolean:createWithValue",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Boolean_createWithValue'.",&tolua_err);
#endif
    return 0;
}
int lua_x_ObjSym_Boolean_createWithObjProperty(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg_sym.Boolean",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg_sym.Boolean:createWithObjProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ObjSym_Boolean_createWithObjProperty'", nullptr);
            return 0;
        }
        lstg::symbol::Boolean* ret = lstg::symbol::Boolean::createWithObjProperty(arg0);
        object_to_luaval<lstg::symbol::Boolean>(tolua_S, "lstg_sym.Boolean",(lstg::symbol::Boolean*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg_sym.Boolean:createWithObjProperty",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ObjSym_Boolean_createWithObjProperty'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ObjSym_Boolean_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Boolean)");
    return 0;
}

int lua_register_x_ObjSym_Boolean(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg_sym.Boolean");
    tolua_cclass(tolua_S,"Boolean","lstg_sym.Boolean","lstg_sym.Operand",nullptr);

    tolua_beginmodule(tolua_S,"Boolean");
        tolua_function(tolua_S,"createWithValue", lua_x_ObjSym_Boolean_createWithValue);
        tolua_function(tolua_S,"createWithObjProperty", lua_x_ObjSym_Boolean_createWithObjProperty);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::symbol::Boolean).name();
    g_luaType[typeName] = "lstg_sym.Boolean";
    g_typeCast["Boolean"] = "lstg_sym.Boolean";
    return 1;
}
TOLUA_API int register_all_x_ObjSym(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg_sym",0);
	tolua_beginmodule(tolua_S,"lstg_sym");

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

