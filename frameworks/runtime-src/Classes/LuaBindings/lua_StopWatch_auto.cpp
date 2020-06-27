#include "lua_StopWatch_auto.hpp"
#include "../Classes/XStopWatch.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_x_StopWatch_StopWatch_reset(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StopWatch* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.StopWatch",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_StopWatch_StopWatch_reset'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_StopWatch_StopWatch_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StopWatch:reset", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_StopWatch_StopWatch_reset'.",&tolua_err);
    return 0;
#endif
}
int lua_x_StopWatch_StopWatch_pause(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StopWatch* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.StopWatch",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_StopWatch_StopWatch_pause'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_StopWatch_StopWatch_pause'", nullptr);
            return 0;
        }
        cobj->pause();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StopWatch:pause", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_StopWatch_StopWatch_pause'.",&tolua_err);
    return 0;
#endif
}
int lua_x_StopWatch_StopWatch_get(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StopWatch* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.StopWatch",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_StopWatch_StopWatch_get'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_StopWatch_StopWatch_get'", nullptr);
            return 0;
        }
        double ret = cobj->get();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StopWatch:get", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_StopWatch_StopWatch_get'.",&tolua_err);
    return 0;
#endif
}
int lua_x_StopWatch_StopWatch_resume(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StopWatch* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.StopWatch",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_StopWatch_StopWatch_resume'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_StopWatch_StopWatch_resume'", nullptr);
            return 0;
        }
        cobj->resume();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StopWatch:resume", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_StopWatch_StopWatch_resume'.",&tolua_err);
    return 0;
#endif
}
int lua_x_StopWatch_StopWatch_constructor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StopWatch* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_StopWatch_StopWatch_constructor'", nullptr);
            return 0;
        }
        cobj = new lstg::StopWatch();
        tolua_pushusertype(tolua_S,(void*)cobj,"lstg.StopWatch");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StopWatch:StopWatch", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_x_StopWatch_StopWatch_constructor'.",&tolua_err);
    return 0;
#endif
}

static int lua_x_StopWatch_StopWatch_finalize(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
    printf("luabindings: finalizing LUA object (StopWatch)");
    tolua_Error tolua_err;
    if (
    !tolua_isusertype(tolua_S,1,"lstg.StopWatch",0,&tolua_err) ||
    !tolua_isnoobj(tolua_S,2,&tolua_err)
    )
        goto tolua_lerror;
    else
#endif
    {
        lstg::StopWatch* self = (lstg::StopWatch*)  tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", nullptr);
#endif
        delete self;
    }
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
    return 0;
#endif
}

int lua_register_x_StopWatch_StopWatch(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.StopWatch");
    tolua_cclass(tolua_S,"StopWatch","lstg.StopWatch","",lua_x_StopWatch_StopWatch_finalize);

    tolua_beginmodule(tolua_S,"StopWatch");
        tolua_function(tolua_S,"new",lua_x_StopWatch_StopWatch_constructor);
        tolua_function(tolua_S,"reset",lua_x_StopWatch_StopWatch_reset);
        tolua_function(tolua_S,"pause",lua_x_StopWatch_StopWatch_pause);
        tolua_function(tolua_S,"get",lua_x_StopWatch_StopWatch_get);
        tolua_function(tolua_S,"resume",lua_x_StopWatch_StopWatch_resume);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::StopWatch).name();
    g_luaType[typeName] = "lstg.StopWatch";
    g_typeCast["StopWatch"] = "lstg.StopWatch";
    return 1;
}
TOLUA_API int register_all_x_StopWatch(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_StopWatch_StopWatch(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

