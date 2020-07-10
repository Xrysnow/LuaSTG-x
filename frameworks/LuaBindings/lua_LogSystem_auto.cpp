#include "lua_LogSystem_auto.hpp"
#include "../LSTG/LogSystem.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_x_LogSystem_LogSystem_write(lua_State* tolua_S)
{
    int argc = 0;
    lstg::LogSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::LogSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_LogSystem_LogSystem_write'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.LogSystem:write");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_write'", nullptr);
            return 0;
        }
        bool ret = cobj->write(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.LogSystem:write",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_write'.",&tolua_err);
#endif

    return 0;
}
int lua_x_LogSystem_LogSystem_setConsoleLevel(lua_State* tolua_S)
{
    int argc = 0;
    lstg::LogSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::LogSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_LogSystem_LogSystem_setConsoleLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.LogSystem:setConsoleLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_setConsoleLevel'", nullptr);
            return 0;
        }
        cobj->setConsoleLevel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.LogSystem:setConsoleLevel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_setConsoleLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_x_LogSystem_LogSystem_writeLine(lua_State* tolua_S)
{
    int argc = 0;
    lstg::LogSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::LogSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_LogSystem_LogSystem_writeLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.LogSystem:writeLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_writeLine'", nullptr);
            return 0;
        }
        bool ret = cobj->writeLine(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.LogSystem:writeLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_writeLine'.",&tolua_err);
#endif

    return 0;
}
int lua_x_LogSystem_LogSystem_getPath(lua_State* tolua_S)
{
    int argc = 0;
    lstg::LogSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::LogSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_LogSystem_LogSystem_getPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_getPath'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPath();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.LogSystem:getPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_getPath'.",&tolua_err);
#endif

    return 0;
}
int lua_x_LogSystem_LogSystem_changePath(lua_State* tolua_S)
{
    int argc = 0;
    lstg::LogSystem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::LogSystem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_LogSystem_LogSystem_changePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.LogSystem:changePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_changePath'", nullptr);
            return 0;
        }
        bool ret = cobj->changePath(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.LogSystem:changePath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_changePath'.",&tolua_err);
#endif

    return 0;
}
int lua_x_LogSystem_LogSystem_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.LogSystem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_LogSystem_LogSystem_getInstance'", nullptr);
            return 0;
        }
        lstg::LogSystem* ret = lstg::LogSystem::getInstance();
        object_to_luaval<lstg::LogSystem>(tolua_S, "lstg.LogSystem",(lstg::LogSystem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.LogSystem:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_LogSystem_LogSystem_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_LogSystem_LogSystem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LogSystem)");
    return 0;
}

int lua_register_x_LogSystem_LogSystem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.LogSystem");
    tolua_cclass(tolua_S,"LogSystem","lstg.LogSystem","",nullptr);

    tolua_beginmodule(tolua_S,"LogSystem");
        tolua_function(tolua_S,"write",lua_x_LogSystem_LogSystem_write);
        tolua_function(tolua_S,"setConsoleLevel",lua_x_LogSystem_LogSystem_setConsoleLevel);
        tolua_function(tolua_S,"writeLine",lua_x_LogSystem_LogSystem_writeLine);
        tolua_function(tolua_S,"getPath",lua_x_LogSystem_LogSystem_getPath);
        tolua_function(tolua_S,"changePath",lua_x_LogSystem_LogSystem_changePath);
        tolua_function(tolua_S,"getInstance", lua_x_LogSystem_LogSystem_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::LogSystem).name();
    g_luaType[typeName] = "lstg.LogSystem";
    g_typeCast["LogSystem"] = "lstg.LogSystem";
    return 1;
}
TOLUA_API int register_all_x_LogSystem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_LogSystem_LogSystem(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

