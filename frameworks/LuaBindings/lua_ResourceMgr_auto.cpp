#include "lua_ResourceMgr_auto.hpp"
#include "../LSTG/ResourceMgr.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLua.h"
#define printf(...)
using lstg::lua::luaval_to_async_callback;
using lstg::lua::ref_vector_to_luaval;

int lua_x_ResourceMgr_ResourcePack_getCRC32(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getCRC32'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:getCRC32");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getCRC32'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCRC32(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getCRC32",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getCRC32'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync'", nullptr);
            return 0;
        }
        cobj->cacheAllFilesAsync();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        std::function<void ()> arg0;
        ok &= luaval_to_async_callback(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync'", nullptr);
            return 0;
        }
        cobj->cacheAllFilesAsync(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:cacheAllFilesAsync",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_removeFileCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_removeFileCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:removeFileCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_removeFileCache'", nullptr);
            return 0;
        }
        bool ret = cobj->removeFileCache(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:removeFileCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_removeFileCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_clearFileCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_clearFileCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_clearFileCache'", nullptr);
            return 0;
        }
        cobj->clearFileCache();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:clearFileCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_clearFileCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getPriority(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getPriority'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getPriority'", nullptr);
            return 0;
        }
        double ret = cobj->getPriority();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getPriority",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getPriority'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getStringFromFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getStringFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:getStringFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getStringFromFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->getStringFromFile(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getStringFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getStringFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_listFiles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_listFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_listFiles'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->listFiles();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:listFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_listFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_cacheFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_cacheFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:cacheFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheFile'", nullptr);
            return 0;
        }
        bool ret = cobj->cacheFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:cacheFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_cacheFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getPath(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getPath'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPath();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getPath'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getCompressedSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getCompressedSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:getCompressedSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getCompressedSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCompressedSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getCompressedSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getCompressedSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getUncompressedSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getUncompressedSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:getUncompressedSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getUncompressedSize'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getUncompressedSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getUncompressedSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getUncompressedSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_loadAndCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_loadAndCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:loadAndCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_loadAndCache'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->loadAndCache(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:loadAndCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_loadAndCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_isFileCached(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_isFileCached'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:isFileCached");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_isFileCached'", nullptr);
            return 0;
        }
        bool ret = cobj->isFileCached(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:isFileCached",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_isFileCached'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_cacheFileAsync(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_cacheFileAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:cacheFileAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheFileAsync'", nullptr);
            return 0;
        }
        cobj->cacheFileAsync(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::function<void ()> arg1;
        ok &= luaval_to_std_string(tolua_S, 2, &arg0, "lstg.ResourcePack:cacheFileAsync");
        ok &= luaval_to_async_callback(tolua_S, 3, &arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheFileAsync'", nullptr);
            return 0;
        }
        cobj->cacheFileAsync(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:cacheFileAsync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_cacheFileAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_setPriority(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_setPriority'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResourcePack:setPriority");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_setPriority'", nullptr);
            return 0;
        }
        cobj->setPriority(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:setPriority",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_setPriority'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_getFileCount(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_getFileCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_getFileCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getFileCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:getFileCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_getFileCount'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:isFileOrDirectoryExist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist'", nullptr);
            return 0;
        }
        bool ret = cobj->isFileOrDirectoryExist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:isFileOrDirectoryExist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_cacheAllFiles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFiles'", nullptr);
            return 0;
        }
        cobj->cacheAllFiles();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:cacheAllFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_cacheAllFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_listCachedFiles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourcePack* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourcePack_listCachedFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_listCachedFiles'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->listCachedFiles();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourcePack:listCachedFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_listCachedFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourcePack_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResourcePack",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourcePack:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResourcePack:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourcePack_create'", nullptr);
            return 0;
        }
        lstg::ResourcePack* ret = lstg::ResourcePack::create(arg0, arg1);
        object_to_luaval<lstg::ResourcePack>(tolua_S, "lstg.ResourcePack",(lstg::ResourcePack*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResourcePack:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourcePack_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ResourceMgr_ResourcePack_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResourcePack)");
    return 0;
}

int lua_register_x_ResourceMgr_ResourcePack(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResourcePack");
    tolua_cclass(tolua_S,"ResourcePack","lstg.ResourcePack","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ResourcePack");
        tolua_function(tolua_S,"getCRC32",lua_x_ResourceMgr_ResourcePack_getCRC32);
        tolua_function(tolua_S,"cacheAllFilesAsync",lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync);
        tolua_function(tolua_S,"removeFileCache",lua_x_ResourceMgr_ResourcePack_removeFileCache);
        tolua_function(tolua_S,"clearFileCache",lua_x_ResourceMgr_ResourcePack_clearFileCache);
        tolua_function(tolua_S,"getPriority",lua_x_ResourceMgr_ResourcePack_getPriority);
        tolua_function(tolua_S,"getStringFromFile",lua_x_ResourceMgr_ResourcePack_getStringFromFile);
        tolua_function(tolua_S,"listFiles",lua_x_ResourceMgr_ResourcePack_listFiles);
        tolua_function(tolua_S,"cacheFile",lua_x_ResourceMgr_ResourcePack_cacheFile);
        tolua_function(tolua_S,"getPath",lua_x_ResourceMgr_ResourcePack_getPath);
        tolua_function(tolua_S,"getCompressedSize",lua_x_ResourceMgr_ResourcePack_getCompressedSize);
        tolua_function(tolua_S,"getUncompressedSize",lua_x_ResourceMgr_ResourcePack_getUncompressedSize);
        tolua_function(tolua_S,"loadAndCache",lua_x_ResourceMgr_ResourcePack_loadAndCache);
        tolua_function(tolua_S,"isFileCached",lua_x_ResourceMgr_ResourcePack_isFileCached);
        tolua_function(tolua_S,"cacheFileAsync",lua_x_ResourceMgr_ResourcePack_cacheFileAsync);
        tolua_function(tolua_S,"setPriority",lua_x_ResourceMgr_ResourcePack_setPriority);
        tolua_function(tolua_S,"getFileCount",lua_x_ResourceMgr_ResourcePack_getFileCount);
        tolua_function(tolua_S,"isFileOrDirectoryExist",lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist);
        tolua_function(tolua_S,"cacheAllFiles",lua_x_ResourceMgr_ResourcePack_cacheAllFiles);
        tolua_function(tolua_S,"listCachedFiles",lua_x_ResourceMgr_ResourcePack_listCachedFiles);
        tolua_function(tolua_S,"create", lua_x_ResourceMgr_ResourcePack_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResourcePack).name();
    g_luaType[typeName] = "lstg.ResourcePack";
    g_typeCast["ResourcePack"] = "lstg.ResourcePack";
    return 1;
}

int lua_x_ResourceMgr_ResourceMgr_addResourcePack(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_addResourcePack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        lstg::ResourcePack* arg0;
        bool arg1;

        ok &= luaval_to_object<lstg::ResourcePack>(tolua_S, 2, "lstg.ResourcePack",&arg0, "lstg.ResourceMgr:addResourcePack");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.ResourceMgr:addResourcePack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_addResourcePack'", nullptr);
            return 0;
        }
        cobj->addResourcePack(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:addResourcePack",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_addResourcePack'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_isLocalFileCached(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_isLocalFileCached'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:isLocalFileCached");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_isLocalFileCached'", nullptr);
            return 0;
        }
        bool ret = cobj->isLocalFileCached(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:isLocalFileCached",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_isLocalFileCached'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_loadResourcePack(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_loadResourcePack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:loadResourcePack");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResourceMgr:loadResourcePack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_loadResourcePack'", nullptr);
            return 0;
        }
        lstg::ResourcePack* ret = cobj->loadResourcePack(arg0, arg1);
        object_to_luaval<lstg::ResourcePack>(tolua_S, "lstg.ResourcePack",(lstg::ResourcePack*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:loadResourcePack",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_loadResourcePack'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_setGlobalImageScaleFactor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_setGlobalImageScaleFactor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResourceMgr:setGlobalImageScaleFactor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_setGlobalImageScaleFactor'", nullptr);
            return 0;
        }
        cobj->setGlobalImageScaleFactor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:setGlobalImageScaleFactor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_setGlobalImageScaleFactor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getGlobalImageScaleFactor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getGlobalImageScaleFactor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getGlobalImageScaleFactor'", nullptr);
            return 0;
        }
        double ret = cobj->getGlobalImageScaleFactor();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getGlobalImageScaleFactor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getGlobalImageScaleFactor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:loadLocalFileAndCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->loadLocalFileAndCache(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:loadLocalFileAndCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getStringFromFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:getStringFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->getStringFromFile(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getStringFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getResourcePacks(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePacks'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePacks'", nullptr);
            return 0;
        }
		ref_vector_to_luaval(tolua_S, cobj->getResourcePacks());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getResourcePacks",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePacks'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_cacheLocalFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:cacheLocalFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFile'", nullptr);
            return 0;
        }
        bool ret = cobj->cacheLocalFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:cacheLocalFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->listCachedLocalFiles();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:listCachedLocalFiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:removeLocalFileCache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache'", nullptr);
            return 0;
        }
        bool ret = cobj->removeLocalFileCache(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:removeLocalFileCache",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_unloadResourcePack(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_unloadResourcePack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:unloadResourcePack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_unloadResourcePack'", nullptr);
            return 0;
        }
        bool ret = cobj->unloadResourcePack(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:unloadResourcePack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_unloadResourcePack'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache'", nullptr);
            return 0;
        }
        cobj->clearLocalFileCache();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:clearLocalFileCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getResourcePack(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:getResourcePack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePack'", nullptr);
            return 0;
        }
        lstg::ResourcePack* ret = cobj->getResourcePack(arg0);
        object_to_luaval<lstg::ResourcePack>(tolua_S, "lstg.ResourcePack",(lstg::ResourcePack*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getResourcePack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getResourcePack'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_extractFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_extractFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:extractFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResourceMgr:extractFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_extractFile'", nullptr);
            return 0;
        }
        bool ret = cobj->extractFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:extractFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_extractFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:isFileOrDirectoryExist");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist'", nullptr);
            return 0;
        }
        bool ret = cobj->isFileOrDirectoryExist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:isFileOrDirectoryExist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getBufferFromFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getBufferFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:getBufferFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getBufferFromFile'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->getBufferFromFile(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getBufferFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getBufferFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:cacheLocalFileAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync'", nullptr);
            return 0;
        }
        cobj->cacheLocalFileAsync(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::function<void ()> arg1;
        ok &= luaval_to_std_string(tolua_S, 2, &arg0, "lstg.ResourceMgr:cacheLocalFileAsync");
        ok &= luaval_to_async_callback(tolua_S, 3, &arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync'", nullptr);
            return 0;
        }
        cobj->cacheLocalFileAsync(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:cacheLocalFileAsync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks'", nullptr);
            return 0;
        }
        cobj->unloadAllResourcePacks();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:unloadAllResourcePacks",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_clear(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:isResourcePackLoaded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded'", nullptr);
            return 0;
        }
        bool ret = cobj->isResourcePackLoaded(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:isResourcePackLoaded",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResourceMgr:getStringFromLocalFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->getStringFromLocalFile(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceMgr:getStringFromLocalFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ResourceMgr_ResourceMgr_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResourceMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ResourceMgr_ResourceMgr_getInstance'", nullptr);
            return 0;
        }
        lstg::ResourceMgr* ret = lstg::ResourceMgr::getInstance();
        object_to_luaval<lstg::ResourceMgr>(tolua_S, "lstg.ResourceMgr",(lstg::ResourceMgr*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResourceMgr:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ResourceMgr_ResourceMgr_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_ResourceMgr_ResourceMgr_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResourceMgr)");
    return 0;
}

int lua_register_x_ResourceMgr_ResourceMgr(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResourceMgr");
    tolua_cclass(tolua_S,"ResourceMgr","lstg.ResourceMgr","",nullptr);

    tolua_beginmodule(tolua_S,"ResourceMgr");
        tolua_function(tolua_S,"addResourcePack",lua_x_ResourceMgr_ResourceMgr_addResourcePack);
        tolua_function(tolua_S,"isLocalFileCached",lua_x_ResourceMgr_ResourceMgr_isLocalFileCached);
        tolua_function(tolua_S,"loadResourcePack",lua_x_ResourceMgr_ResourceMgr_loadResourcePack);
        tolua_function(tolua_S,"setGlobalImageScaleFactor",lua_x_ResourceMgr_ResourceMgr_setGlobalImageScaleFactor);
        tolua_function(tolua_S,"getGlobalImageScaleFactor",lua_x_ResourceMgr_ResourceMgr_getGlobalImageScaleFactor);
        tolua_function(tolua_S,"loadLocalFileAndCache",lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache);
        tolua_function(tolua_S,"getStringFromFile",lua_x_ResourceMgr_ResourceMgr_getStringFromFile);
        tolua_function(tolua_S,"getResourcePacks",lua_x_ResourceMgr_ResourceMgr_getResourcePacks);
        tolua_function(tolua_S,"cacheLocalFile",lua_x_ResourceMgr_ResourceMgr_cacheLocalFile);
        tolua_function(tolua_S,"listCachedLocalFiles",lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles);
        tolua_function(tolua_S,"removeLocalFileCache",lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache);
        tolua_function(tolua_S,"unloadResourcePack",lua_x_ResourceMgr_ResourceMgr_unloadResourcePack);
        tolua_function(tolua_S,"clearLocalFileCache",lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache);
        tolua_function(tolua_S,"getResourcePack",lua_x_ResourceMgr_ResourceMgr_getResourcePack);
        tolua_function(tolua_S,"extractFile",lua_x_ResourceMgr_ResourceMgr_extractFile);
        tolua_function(tolua_S,"isFileOrDirectoryExist",lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist);
        tolua_function(tolua_S,"getBufferFromFile",lua_x_ResourceMgr_ResourceMgr_getBufferFromFile);
        tolua_function(tolua_S,"cacheLocalFileAsync",lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync);
        tolua_function(tolua_S,"unloadAllResourcePacks",lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks);
        tolua_function(tolua_S,"clear",lua_x_ResourceMgr_ResourceMgr_clear);
        tolua_function(tolua_S,"isResourcePackLoaded",lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded);
        tolua_function(tolua_S,"getStringFromLocalFile",lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile);
        tolua_function(tolua_S,"getInstance", lua_x_ResourceMgr_ResourceMgr_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResourceMgr).name();
    g_luaType[typeName] = "lstg.ResourceMgr";
    g_typeCast["ResourceMgr"] = "lstg.ResourceMgr";
    return 1;
}
TOLUA_API int register_all_x_ResourceMgr(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_ResourceMgr_ResourcePack(tolua_S);
	lua_register_x_ResourceMgr_ResourceMgr(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

