#include "lua_BlendMode_auto.hpp"
#include "../LSTG/BlendMode.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

#define BlendMode_to_luaval(L, val) object_to_luaval<lstg::BlendMode>(L, "lstg.BlendMode", val)
//#define COCOS2D_DEBUG 2

int lua_x_BlendMode_BlendMode_setFogGLProgram(lua_State* tolua_S)
{
    int argc = 0;
    lstg::BlendMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::BlendMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BlendMode_BlendMode_setFogGLProgram'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        lstg::FogMode arg0;
        cocos2d::GLProgram* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.BlendMode:setFogGLProgram");

        ok &= luaval_to_object<cocos2d::GLProgram>(tolua_S, 3, "cc.GLProgram",&arg1, "lstg.BlendMode:setFogGLProgram");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_setFogGLProgram'", nullptr);
            return 0;
        }
        cobj->setFogGLProgram(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.BlendMode:setFogGLProgram",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_setFogGLProgram'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BlendMode_BlendMode_getName(lua_State* tolua_S)
{
    int argc = 0;
    lstg::BlendMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::BlendMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BlendMode_BlendMode_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.BlendMode:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BlendMode_BlendMode_getGLProgramState(lua_State* tolua_S)
{
    int argc = 0;
    lstg::BlendMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::BlendMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BlendMode_BlendMode_getGLProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getGLProgramState'", nullptr);
            return 0;
        }
        cocos2d::GLProgramState* ret = cobj->getGLProgramState();
        object_to_luaval<cocos2d::GLProgramState>(tolua_S, "cc.GLProgramState",(cocos2d::GLProgramState*)ret);
        return 1;
    }
    if (argc == 1) 
    {
        lstg::FogMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.BlendMode:getGLProgramState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getGLProgramState'", nullptr);
            return 0;
        }
        cocos2d::GLProgramState* ret = cobj->getGLProgramState(arg0);
        object_to_luaval<cocos2d::GLProgramState>(tolua_S, "cc.GLProgramState",(cocos2d::GLProgramState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.BlendMode:getGLProgramState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getGLProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BlendMode_BlendMode_getID(lua_State* tolua_S)
{
    int argc = 0;
    lstg::BlendMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::BlendMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BlendMode_BlendMode_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.BlendMode:getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BlendMode_BlendMode_getGLProgram(lua_State* tolua_S)
{
    int argc = 0;
    lstg::BlendMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::BlendMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BlendMode_BlendMode_getGLProgram'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getGLProgram'", nullptr);
            return 0;
        }
        cocos2d::GLProgram* ret = cobj->getGLProgram();
        object_to_luaval<cocos2d::GLProgram>(tolua_S, "cc.GLProgram",(cocos2d::GLProgram*)ret);
        return 1;
    }
    if (argc == 1) 
    {
        lstg::FogMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.BlendMode:getGLProgram");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getGLProgram'", nullptr);
            return 0;
        }
        cocos2d::GLProgram* ret = cobj->getGLProgram(arg0);
        object_to_luaval<cocos2d::GLProgram>(tolua_S, "cc.GLProgram",(cocos2d::GLProgram*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.BlendMode:getGLProgram",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getGLProgram'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BlendMode_BlendMode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        unsigned int arg1;
        unsigned int arg2;
        unsigned int arg3;
        cocos2d::GLProgram* arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.BlendMode:create");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "lstg.BlendMode:create");
        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "lstg.BlendMode:create");
        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "lstg.BlendMode:create");
        ok &= luaval_to_object<cocos2d::GLProgram>(tolua_S, 6, "cc.GLProgram",&arg4, "lstg.BlendMode:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_create'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = lstg::BlendMode::create(arg0, arg1, arg2, arg3, arg4);
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.BlendMode:create",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_BlendMode_BlendMode_getByID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.BlendMode:getByID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getByID'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = lstg::BlendMode::getByID(arg0);
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.BlendMode:getByID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getByID'.",&tolua_err);
#endif
    return 0;
}
int lua_x_BlendMode_BlendMode_createByNames(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.BlendMode:createByNames");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.BlendMode:createByNames");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "lstg.BlendMode:createByNames");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "lstg.BlendMode:createByNames");
        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "lstg.BlendMode:createByNames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_createByNames'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = lstg::BlendMode::createByNames(arg0, arg1, arg2, arg3, arg4);
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.BlendMode:createByNames",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_createByNames'.",&tolua_err);
#endif
    return 0;
}
int lua_x_BlendMode_BlendMode_getIDByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.BlendMode:getIDByName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getIDByName'", nullptr);
            return 0;
        }
        unsigned int ret = lstg::BlendMode::getIDByName(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.BlendMode:getIDByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getIDByName'.",&tolua_err);
#endif
    return 0;
}
int lua_x_BlendMode_BlendMode_getByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.BlendMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.BlendMode:getByName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BlendMode_BlendMode_getByName'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = lstg::BlendMode::getByName(arg0);
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.BlendMode:getByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BlendMode_BlendMode_getByName'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_BlendMode_BlendMode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BlendMode)");
    return 0;
}

int lua_register_x_BlendMode_BlendMode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.BlendMode");
    tolua_cclass(tolua_S,"BlendMode","lstg.BlendMode","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"BlendMode");
        tolua_function(tolua_S,"setFogGLProgram",lua_x_BlendMode_BlendMode_setFogGLProgram);
        tolua_function(tolua_S,"getName",lua_x_BlendMode_BlendMode_getName);
        tolua_function(tolua_S,"getGLProgramState",lua_x_BlendMode_BlendMode_getGLProgramState);
        tolua_function(tolua_S,"getID",lua_x_BlendMode_BlendMode_getID);
        tolua_function(tolua_S,"getGLProgram",lua_x_BlendMode_BlendMode_getGLProgram);
        tolua_function(tolua_S,"create", lua_x_BlendMode_BlendMode_create);
        tolua_function(tolua_S,"getByID", lua_x_BlendMode_BlendMode_getByID);
        tolua_function(tolua_S,"createByNames", lua_x_BlendMode_BlendMode_createByNames);
        tolua_function(tolua_S,"getIDByName", lua_x_BlendMode_BlendMode_getIDByName);
        tolua_function(tolua_S,"getByName", lua_x_BlendMode_BlendMode_getByName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::BlendMode).name();
    g_luaType[typeName] = "lstg.BlendMode";
    g_typeCast["BlendMode"] = "lstg.BlendMode";
    return 1;
}
TOLUA_API int register_all_x_BlendMode(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_BlendMode_BlendMode(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

