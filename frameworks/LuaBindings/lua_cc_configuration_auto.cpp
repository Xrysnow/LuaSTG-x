#include "lua_cc_configuration_auto.hpp"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_cocos2dx_configuration_Configuration_checkForGLExtension(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_checkForGLExtension'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Configuration:checkForGLExtension");
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_checkForGLExtension'", nullptr);
            return 0;
        }
        bool ret = cobj->checkForGLExtension(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:checkForGLExtension", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_checkForGLExtension'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_gatherGPUInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_gatherGPUInfo'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_gatherGPUInfo'", nullptr);
            return 0;
        }
        cobj->gatherGPUInfo();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:gatherGPUInfo", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_gatherGPUInfo'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getAnimate3DQuality(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getAnimate3DQuality'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getAnimate3DQuality'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getAnimate3DQuality();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getAnimate3DQuality", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getAnimate3DQuality'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getInfo'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getInfo'", nullptr);
            return 0;
        }
        std::string ret = cobj->getInfo();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getInfo", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getInfo'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getInstance'", nullptr);
            return 0;
        }
        cocos2d::Configuration* ret = cocos2d::Configuration::getInstance();
        object_to_luaval(tolua_S, "cc.Configuration", ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.Configuration:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_configuration_Configuration_getMaxAttributes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxAttributes'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxAttributes'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxAttributes();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxAttributes", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxAttributes'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxModelviewStackDepth(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxModelviewStackDepth'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxModelviewStackDepth'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxModelviewStackDepth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxModelviewStackDepth", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxModelviewStackDepth'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxSupportDirLightInShader(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportDirLightInShader'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportDirLightInShader'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxSupportDirLightInShader();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxSupportDirLightInShader", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportDirLightInShader'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxSupportPointLightInShader(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportPointLightInShader'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportPointLightInShader'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxSupportPointLightInShader();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxSupportPointLightInShader", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportPointLightInShader'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxSupportSpotLightInShader(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportSpotLightInShader'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportSpotLightInShader'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxSupportSpotLightInShader();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxSupportSpotLightInShader", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxSupportSpotLightInShader'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxTextureSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureSize'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureSize'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxTextureSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxTextureSize", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureSize'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getMaxTextureUnits(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureUnits'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureUnits'", nullptr);
            return 0;
        }
        int ret = cobj->getMaxTextureUnits();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getMaxTextureUnits", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getMaxTextureUnits'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_getValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_getValue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Configuration:getValue");
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getValue'", nullptr);
            return 0;
        }
        const cocos2d::Value& ret = cobj->getValue(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Configuration:getValue");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "cc.Configuration:getValue");
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_getValue'", nullptr);
            return 0;
        }
        const cocos2d::Value& ret = cobj->getValue(arg0, arg1);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:getValue", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_getValue'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:init", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_init'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_loadConfigFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_loadConfigFile'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Configuration:loadConfigFile");
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_loadConfigFile'", nullptr);
            return 0;
        }
        cobj->loadConfigFile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:loadConfigFile", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_loadConfigFile'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_setValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_setValue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.Configuration:setValue");

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, "cc.Configuration:setValue");
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:setValue", argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_setValue'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsATITC(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsATITC'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsATITC'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsATITC();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsATITC", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsATITC'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsBGRA8888(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsBGRA8888'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsBGRA8888'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsBGRA8888();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsBGRA8888", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsBGRA8888'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsDiscardFramebuffer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsDiscardFramebuffer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsDiscardFramebuffer'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsDiscardFramebuffer();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsDiscardFramebuffer", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsDiscardFramebuffer'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsETC(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsETC'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsETC'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsETC();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsETC", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsETC'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsMapBuffer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsMapBuffer'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsMapBuffer'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsMapBuffer();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsMapBuffer", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsMapBuffer'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsNPOT(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsNPOT'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsNPOT'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsNPOT();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsNPOT", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsNPOT'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsOESDepth24(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsOESDepth24'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsOESDepth24'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsOESDepth24();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsOESDepth24", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsOESDepth24'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsOESPackedDepthStencil(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsOESPackedDepthStencil'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsOESPackedDepthStencil'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsOESPackedDepthStencil();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsOESPackedDepthStencil", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsOESPackedDepthStencil'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsPVRTC(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsPVRTC'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsPVRTC'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsPVRTC();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsPVRTC", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsPVRTC'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsS3TC(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsS3TC'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsS3TC'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsS3TC();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsS3TC", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsS3TC'.",&tolua_err);
    return 0;
#endif
}
int lua_cocos2dx_configuration_Configuration_supportsShareableVAO(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Configuration* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Configuration",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::Configuration*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_configuration_Configuration_supportsShareableVAO'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_configuration_Configuration_supportsShareableVAO'", nullptr);
            return 0;
        }
        bool ret = cobj->supportsShareableVAO();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Configuration:supportsShareableVAO", argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_configuration_Configuration_supportsShareableVAO'.",&tolua_err);
    return 0;
#endif
}
static int lua_cocos2dx_configuration_Configuration_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Configuration)");
    return 0;
}

int lua_register_cocos2dx_configuration_Configuration(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.Configuration");
    tolua_cclass(tolua_S,"Configuration","cc.Configuration","",nullptr);

    tolua_beginmodule(tolua_S,"Configuration");
        tolua_function(tolua_S,"supportsPVRTC",lua_cocos2dx_configuration_Configuration_supportsPVRTC);
        tolua_function(tolua_S,"supportsOESDepth24",lua_cocos2dx_configuration_Configuration_supportsOESDepth24);
        tolua_function(tolua_S,"getMaxModelviewStackDepth",lua_cocos2dx_configuration_Configuration_getMaxModelviewStackDepth);
        tolua_function(tolua_S,"supportsShareableVAO",lua_cocos2dx_configuration_Configuration_supportsShareableVAO);
        tolua_function(tolua_S,"supportsBGRA8888",lua_cocos2dx_configuration_Configuration_supportsBGRA8888);
        tolua_function(tolua_S,"checkForGLExtension",lua_cocos2dx_configuration_Configuration_checkForGLExtension);
        tolua_function(tolua_S,"getMaxAttributes",lua_cocos2dx_configuration_Configuration_getMaxAttributes);
        tolua_function(tolua_S,"supportsATITC",lua_cocos2dx_configuration_Configuration_supportsATITC);
        tolua_function(tolua_S,"supportsNPOT",lua_cocos2dx_configuration_Configuration_supportsNPOT);
        tolua_function(tolua_S,"init",lua_cocos2dx_configuration_Configuration_init);
        tolua_function(tolua_S,"getAnimate3DQuality",lua_cocos2dx_configuration_Configuration_getAnimate3DQuality);
        tolua_function(tolua_S,"getMaxSupportPointLightInShader",lua_cocos2dx_configuration_Configuration_getMaxSupportPointLightInShader);
        tolua_function(tolua_S,"getMaxTextureSize",lua_cocos2dx_configuration_Configuration_getMaxTextureSize);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_configuration_Configuration_setValue);
        tolua_function(tolua_S,"getMaxSupportSpotLightInShader",lua_cocos2dx_configuration_Configuration_getMaxSupportSpotLightInShader);
        tolua_function(tolua_S,"supportsETC",lua_cocos2dx_configuration_Configuration_supportsETC);
        tolua_function(tolua_S,"getMaxSupportDirLightInShader",lua_cocos2dx_configuration_Configuration_getMaxSupportDirLightInShader);
        tolua_function(tolua_S,"loadConfigFile",lua_cocos2dx_configuration_Configuration_loadConfigFile);
        tolua_function(tolua_S,"supportsDiscardFramebuffer",lua_cocos2dx_configuration_Configuration_supportsDiscardFramebuffer);
        tolua_function(tolua_S,"supportsOESPackedDepthStencil",lua_cocos2dx_configuration_Configuration_supportsOESPackedDepthStencil);
        tolua_function(tolua_S,"supportsS3TC",lua_cocos2dx_configuration_Configuration_supportsS3TC);
        tolua_function(tolua_S,"getInfo",lua_cocos2dx_configuration_Configuration_getInfo);
        tolua_function(tolua_S,"getMaxTextureUnits",lua_cocos2dx_configuration_Configuration_getMaxTextureUnits);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_configuration_Configuration_getValue);
        tolua_function(tolua_S,"gatherGPUInfo",lua_cocos2dx_configuration_Configuration_gatherGPUInfo);
        tolua_function(tolua_S,"supportsMapBuffer",lua_cocos2dx_configuration_Configuration_supportsMapBuffer);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_configuration_Configuration_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::Configuration).name();
    g_luaType[typeName] = "cc.Configuration";
    g_typeCast["Configuration"] = "cc.Configuration";
    return 1;
}
TOLUA_API int register_all_cocos2dx_configuration(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "cc", 0);
	tolua_beginmodule(tolua_S, "cc");

	lua_register_cocos2dx_configuration_Configuration(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

