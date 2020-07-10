#include "lua_ZipArchive_auto.hpp"
#include "../Classes/XZipArchive.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLuaConversion.h"

int lua_x_ZipArchive_ZipArchive_getEntryByIndex(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getEntryByIndex'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryByIndex'", nullptr);
            return 0;
        }
        std::string ret = cobj->getEntryByIndex(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    if (argc == 2) 
    {
        long long arg0;
        lstg::ZipArchive::State arg1;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryByIndex");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:getEntryByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryByIndex'", nullptr);
            return 0;
        }
        std::string ret = cobj->getEntryByIndex(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getEntryByIndex", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getEntryByIndex'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_addEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_addEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:addEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_addEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->addEntry(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:addEntry", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_addEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_close(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_close'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_close'", nullptr);
            return 0;
        }
        bool ret = cobj->close();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:close", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_close'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_open(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_open'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_open'", nullptr);
            return 0;
        }
        bool ret = cobj->open();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 1) 
    {
        lstg::ZipArchive::OpenMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ZipArchive:open");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_open'", nullptr);
            return 0;
        }
        bool ret = cobj->open(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        lstg::ZipArchive::OpenMode arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ZipArchive:open");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:open");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_open'", nullptr);
            return 0;
        }
        bool ret = cobj->open(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:open", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_open'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:setEntryCompressionEnabled");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:setEntryCompressionEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->setEntryCompressionEnabled(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        bool arg1;
        lstg::ZipArchive::State arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:setEntryCompressionEnabled");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:setEntryCompressionEnabled");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "lstg.ZipArchive:setEntryCompressionEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->setEntryCompressionEnabled(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:setEntryCompressionEnabled", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getEntryCount(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getEntryCount'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryCount'", nullptr);
            return 0;
        }
        long long ret = cobj->getEntryCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 1) 
    {
        lstg::ZipArchive::State arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ZipArchive:getEntryCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryCount'", nullptr);
            return 0;
        }
        long long ret = cobj->getEntryCount(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getEntryCount", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getEntryCount'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_isEncrypted(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_isEncrypted'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_isEncrypted'", nullptr);
            return 0;
        }
        bool ret = cobj->isEncrypted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:isEncrypted", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_isEncrypted'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_renameEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_renameEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:renameEntry");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:renameEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_renameEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->renameEntry(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:renameEntry", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_renameEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:isEntryCompressionEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isEntryCompressionEnabled(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        lstg::ZipArchive::State arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:isEntryCompressionEnabled");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:isEntryCompressionEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled'", nullptr);
            return 0;
        }
        bool ret = cobj->isEntryCompressionEnabled(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:isEntryCompressionEnabled", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_addString(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_addString'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:addString");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:addString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_addString'", nullptr);
            return 0;
        }
        bool ret = cobj->addString(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:addString", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_addString'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getMode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getMode", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getMode'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_isOpen(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_isOpen'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_isOpen'", nullptr);
            return 0;
        }
        bool ret = cobj->isOpen();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:isOpen", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_isOpen'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getEntryComment(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getEntryComment'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryComment'", nullptr);
            return 0;
        }
        std::string ret = cobj->getEntryComment(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        lstg::ZipArchive::State arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryComment");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:getEntryComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryComment'", nullptr);
            return 0;
        }
        std::string ret = cobj->getEntryComment(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getEntryComment", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getEntryComment'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_readEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_readEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:readEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_readEntry'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->readEntry(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        lstg::ZipArchive::State arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:readEntry");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:readEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_readEntry'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->readEntry(arg0, arg1);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:readEntry", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_readEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_setEntryComment(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_setEntryComment'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:setEntryComment");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:setEntryComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_setEntryComment'", nullptr);
            return 0;
        }
        bool ret = cobj->setEntryComment(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        lstg::ZipArchive::State arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:setEntryComment");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:setEntryComment");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "lstg.ZipArchive:setEntryComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_setEntryComment'", nullptr);
            return 0;
        }
        bool ret = cobj->setEntryComment(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:setEntryComment", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_setEntryComment'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getComment(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getComment'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getComment'", nullptr);
            return 0;
        }
        std::string ret = cobj->getComment();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    if (argc == 1) 
    {
        lstg::ZipArchive::State arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ZipArchive:getComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getComment'", nullptr);
            return 0;
        }
        std::string ret = cobj->getComment(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getComment", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getComment'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_unlink(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_unlink'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_unlink'", nullptr);
            return 0;
        }
        bool ret = cobj->unlink();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:unlink", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_unlink'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_deleteEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_deleteEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:deleteEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_deleteEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->deleteEntry(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:deleteEntry", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_deleteEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_isMutable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_isMutable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_isMutable'", nullptr);
            return 0;
        }
        bool ret = cobj->isMutable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:isMutable", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_isMutable'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getEntries(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getEntries'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntries'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->getEntries();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 1) 
    {
        lstg::ZipArchive::State arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ZipArchive:getEntries");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntries'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->getEntries(arg0);
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getEntries", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getEntries'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_addFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_addFile'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:addFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:addFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_addFile'", nullptr);
            return 0;
        }
        bool ret = cobj->addFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:addFile", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_addFile'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_extractEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_extractEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:extractEntry");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:extractEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_extractEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->extractEntry(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        lstg::ZipArchive::State arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:extractEntry");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:extractEntry");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "lstg.ZipArchive:extractEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_extractEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->extractEntry(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:extractEntry", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_extractEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_hasEntry(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_hasEntry'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:hasEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_hasEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEntry(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:hasEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_hasEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEntry(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        bool arg1;
        bool arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "lstg.ZipArchive:hasEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_hasEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEntry(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        bool arg1;
        bool arg2;
        lstg::ZipArchive::State arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "lstg.ZipArchive:hasEntry");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "lstg.ZipArchive:hasEntry");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_hasEntry'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEntry(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:hasEntry", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_hasEntry'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_setComment(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_setComment'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:setComment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_setComment'", nullptr);
            return 0;
        }
        bool ret = cobj->setComment(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:setComment", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_setComment'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_addData(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_addData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        lstg::Buffer* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:addData");

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 3, "lstg.Buffer",&arg1, "lstg.ZipArchive:addData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_addData'", nullptr);
            return 0;
        }
        bool ret = cobj->addData(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:addData", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_addData'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_getEntryInfo(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_getEntryInfo'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryInfo'", nullptr);
            return 0;
        }
        lstg::ZipArchive::ZipEntryInfo ret = cobj->getEntryInfo(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        lstg::ZipArchive::State arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:getEntryInfo");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:getEntryInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_getEntryInfo'", nullptr);
            return 0;
        }
        lstg::ZipArchive::ZipEntryInfo ret = cobj->getEntryInfo(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:getEntryInfo", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_getEntryInfo'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_removeComment(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_removeComment'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_removeComment'", nullptr);
            return 0;
        }
        bool ret = cobj->removeComment();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:removeComment", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_removeComment'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_discard(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ZipArchive* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ZipArchive*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_ZipArchive_ZipArchive_discard'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_discard'", nullptr);
            return 0;
        }
        cobj->discard();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ZipArchive:discard", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_discard'.",&tolua_err);
    return 0;
#endif
}
int lua_x_ZipArchive_ZipArchive_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_create'", nullptr);
            return 0;
        }
        lstg::ZipArchive* ret = lstg::ZipArchive::create(arg0);
        object_to_luaval<lstg::ZipArchive>(tolua_S, "lstg.ZipArchive",(lstg::ZipArchive*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ZipArchive:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ZipArchive:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_create'", nullptr);
            return 0;
        }
        lstg::ZipArchive* ret = lstg::ZipArchive::create(arg0, arg1);
        object_to_luaval<lstg::ZipArchive>(tolua_S, "lstg.ZipArchive",(lstg::ZipArchive*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ZipArchive:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_ZipArchive_ZipArchive_createFromBuffer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ZipArchive",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        lstg::Buffer* arg0;
        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.ZipArchive:createFromBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_createFromBuffer'", nullptr);
            return 0;
        }
        lstg::ZipArchive* ret = lstg::ZipArchive::createFromBuffer(arg0);
        object_to_luaval<lstg::ZipArchive>(tolua_S, "lstg.ZipArchive",(lstg::ZipArchive*)ret);
        return 1;
    }
    if (argc == 2)
    {
        lstg::Buffer* arg0;
        lstg::ZipArchive::OpenMode arg1;
        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.ZipArchive:createFromBuffer");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:createFromBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_createFromBuffer'", nullptr);
            return 0;
        }
        lstg::ZipArchive* ret = lstg::ZipArchive::createFromBuffer(arg0, arg1);
        object_to_luaval<lstg::ZipArchive>(tolua_S, "lstg.ZipArchive",(lstg::ZipArchive*)ret);
        return 1;
    }
    if (argc == 3)
    {
        lstg::Buffer* arg0;
        lstg::ZipArchive::OpenMode arg1;
        bool arg2;
        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.ZipArchive:createFromBuffer");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ZipArchive:createFromBuffer");
        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "lstg.ZipArchive:createFromBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ZipArchive_ZipArchive_createFromBuffer'", nullptr);
            return 0;
        }
        lstg::ZipArchive* ret = lstg::ZipArchive::createFromBuffer(arg0, arg1, arg2);
        object_to_luaval<lstg::ZipArchive>(tolua_S, "lstg.ZipArchive",(lstg::ZipArchive*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ZipArchive:createFromBuffer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ZipArchive_ZipArchive_createFromBuffer'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ZipArchive_ZipArchive_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ZipArchive)");
    return 0;
}

int lua_register_x_ZipArchive_ZipArchive(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ZipArchive");
    tolua_cclass(tolua_S,"ZipArchive","lstg.ZipArchive","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ZipArchive");
        tolua_function(tolua_S,"getEntryByIndex",lua_x_ZipArchive_ZipArchive_getEntryByIndex);
        tolua_function(tolua_S,"addEntry",lua_x_ZipArchive_ZipArchive_addEntry);
        tolua_function(tolua_S,"close",lua_x_ZipArchive_ZipArchive_close);
        tolua_function(tolua_S,"open",lua_x_ZipArchive_ZipArchive_open);
        tolua_function(tolua_S,"setEntryCompressionEnabled",lua_x_ZipArchive_ZipArchive_setEntryCompressionEnabled);
        tolua_function(tolua_S,"getEntryCount",lua_x_ZipArchive_ZipArchive_getEntryCount);
        tolua_function(tolua_S,"isEncrypted",lua_x_ZipArchive_ZipArchive_isEncrypted);
        tolua_function(tolua_S,"renameEntry",lua_x_ZipArchive_ZipArchive_renameEntry);
        tolua_function(tolua_S,"isEntryCompressionEnabled",lua_x_ZipArchive_ZipArchive_isEntryCompressionEnabled);
        tolua_function(tolua_S,"addString",lua_x_ZipArchive_ZipArchive_addString);
        tolua_function(tolua_S,"getMode",lua_x_ZipArchive_ZipArchive_getMode);
        tolua_function(tolua_S,"isOpen",lua_x_ZipArchive_ZipArchive_isOpen);
        tolua_function(tolua_S,"getEntryComment",lua_x_ZipArchive_ZipArchive_getEntryComment);
        tolua_function(tolua_S,"readEntry",lua_x_ZipArchive_ZipArchive_readEntry);
        tolua_function(tolua_S,"setEntryComment",lua_x_ZipArchive_ZipArchive_setEntryComment);
        tolua_function(tolua_S,"getComment",lua_x_ZipArchive_ZipArchive_getComment);
        tolua_function(tolua_S,"unlink",lua_x_ZipArchive_ZipArchive_unlink);
        tolua_function(tolua_S,"deleteEntry",lua_x_ZipArchive_ZipArchive_deleteEntry);
        tolua_function(tolua_S,"isMutable",lua_x_ZipArchive_ZipArchive_isMutable);
        tolua_function(tolua_S,"getEntries",lua_x_ZipArchive_ZipArchive_getEntries);
        tolua_function(tolua_S,"addFile",lua_x_ZipArchive_ZipArchive_addFile);
        tolua_function(tolua_S,"extractEntry",lua_x_ZipArchive_ZipArchive_extractEntry);
        tolua_function(tolua_S,"hasEntry",lua_x_ZipArchive_ZipArchive_hasEntry);
        tolua_function(tolua_S,"setComment",lua_x_ZipArchive_ZipArchive_setComment);
        tolua_function(tolua_S,"addData",lua_x_ZipArchive_ZipArchive_addData);
        tolua_function(tolua_S,"getEntryInfo",lua_x_ZipArchive_ZipArchive_getEntryInfo);
        tolua_function(tolua_S,"removeComment",lua_x_ZipArchive_ZipArchive_removeComment);
        tolua_function(tolua_S,"discard",lua_x_ZipArchive_ZipArchive_discard);
        tolua_function(tolua_S,"create", lua_x_ZipArchive_ZipArchive_create);
        tolua_function(tolua_S,"createFromBuffer", lua_x_ZipArchive_ZipArchive_createFromBuffer);
        {
            tolua_module(tolua_S, "OpenMode", 0);
            tolua_beginmodule(tolua_S,"OpenMode");
            {
                tolua_constant(tolua_S, "NOT_OPEN", lstg::ZipArchive::OpenMode::NOT_OPEN);
                tolua_constant(tolua_S, "READ_ONLY", lstg::ZipArchive::OpenMode::READ_ONLY);
                tolua_constant(tolua_S, "WRITE", lstg::ZipArchive::OpenMode::WRITE);
                tolua_constant(tolua_S, "NEW", lstg::ZipArchive::OpenMode::NEW);
            }
            tolua_endmodule(tolua_S);
        }
        {
            tolua_module(tolua_S, "State", 0);
            tolua_beginmodule(tolua_S,"State");
            {
                tolua_constant(tolua_S, "ORIGINAL", lstg::ZipArchive::State::ORIGINAL);
                tolua_constant(tolua_S, "CURRENT", lstg::ZipArchive::State::CURRENT);
            }
            tolua_endmodule(tolua_S);
        }
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ZipArchive).name();
    g_luaType[typeName] = "lstg.ZipArchive";
    g_typeCast["ZipArchive"] = "lstg.ZipArchive";
    return 1;
}
TOLUA_API int register_all_x_ZipArchive(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_ZipArchive_ZipArchive(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

