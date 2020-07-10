#include "lua_FileDialog_auto.hpp"
#include "../Classes/XFileDialog.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_x_FileDialog_FileDialog_openMultiple(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.FileDialog",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.FileDialog:openMultiple");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.FileDialog:openMultiple");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_FileDialog_FileDialog_openMultiple'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = lstg::FileDialog::openMultiple(arg0, arg1);
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.FileDialog:openMultiple",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_FileDialog_FileDialog_openMultiple'.",&tolua_err);
#endif
    return 0;
}
int lua_x_FileDialog_FileDialog_pickFolder(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.FileDialog",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.FileDialog:pickFolder");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_FileDialog_FileDialog_pickFolder'", nullptr);
            return 0;
        }
        std::string ret = lstg::FileDialog::pickFolder(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.FileDialog:pickFolder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_FileDialog_FileDialog_pickFolder'.",&tolua_err);
#endif
    return 0;
}
int lua_x_FileDialog_FileDialog_getLastError(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.FileDialog",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_FileDialog_FileDialog_getLastError'", nullptr);
            return 0;
        }
        std::string ret = lstg::FileDialog::getLastError();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.FileDialog:getLastError",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_FileDialog_FileDialog_getLastError'.",&tolua_err);
#endif
    return 0;
}
int lua_x_FileDialog_FileDialog_save(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.FileDialog",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.FileDialog:save");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.FileDialog:save");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_FileDialog_FileDialog_save'", nullptr);
            return 0;
        }
        std::string ret = lstg::FileDialog::save(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.FileDialog:save",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_FileDialog_FileDialog_save'.",&tolua_err);
#endif
    return 0;
}
int lua_x_FileDialog_FileDialog_open(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.FileDialog",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.FileDialog:open");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.FileDialog:open");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_FileDialog_FileDialog_open'", nullptr);
            return 0;
        }
        std::string ret = lstg::FileDialog::open(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.FileDialog:open",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_FileDialog_FileDialog_open'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_FileDialog_FileDialog_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FileDialog)");
    return 0;
}

int lua_register_x_FileDialog_FileDialog(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.FileDialog");
    tolua_cclass(tolua_S,"FileDialog","lstg.FileDialog","",nullptr);

    tolua_beginmodule(tolua_S,"FileDialog");
        tolua_function(tolua_S,"openMultiple", lua_x_FileDialog_FileDialog_openMultiple);
        tolua_function(tolua_S,"pickFolder", lua_x_FileDialog_FileDialog_pickFolder);
        tolua_function(tolua_S,"getLastError", lua_x_FileDialog_FileDialog_getLastError);
        tolua_function(tolua_S,"save", lua_x_FileDialog_FileDialog_save);
        tolua_function(tolua_S,"open", lua_x_FileDialog_FileDialog_open);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::FileDialog).name();
    g_luaType[typeName] = "lstg.FileDialog";
    g_typeCast["FileDialog"] = "lstg.FileDialog";
    return 1;
}
TOLUA_API int register_all_x_FileDialog(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_FileDialog_FileDialog(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

