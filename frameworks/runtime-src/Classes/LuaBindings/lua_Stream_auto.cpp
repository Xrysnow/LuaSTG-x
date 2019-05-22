#include "lua_Stream_auto.hpp"
#include "XStream.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLua.h"
#define printf(...)

int lua_x_Stream_Stream_isResizable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_isResizable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_isResizable'", nullptr);
            return 0;
        }
        bool ret = cobj->isResizable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:isResizable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_isResizable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_isWritable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_isWritable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_isWritable'", nullptr);
            return 0;
        }
        bool ret = cobj->isWritable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:isWritable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_isWritable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_unlock(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_unlock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_unlock'", nullptr);
            return 0;
        }
        cobj->unlock();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:unlock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_unlock'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_tryLock(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_tryLock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_tryLock'", nullptr);
            return 0;
        }
        bool ret = cobj->tryLock();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:tryLock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_tryLock'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_lock(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_lock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_lock'", nullptr);
            return 0;
        }
        cobj->lock();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:lock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_lock'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_fill(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_fill'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        lstg::Stream* arg0;
        unsigned long long arg1;
        lstg::Buffer* arg2;

        ok &= luaval_to_object<lstg::Stream>(tolua_S, 2, "lstg.Stream",&arg0, "lstg.Stream:fill");

        ok &= lstg::lua::luaval_to_unsigned_long_long(tolua_S, 3,&arg1, "lstg.Stream:fill");

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 4, "lstg.Buffer",&arg2, "lstg.Stream:fill");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_fill'", nullptr);
            return 0;
        }
        bool ret = cobj->fill(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:fill",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_fill'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_seek(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_seek'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        lstg::Stream::SeekOrigin arg0;
        long long arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.Stream:seek");

        ok &= luaval_to_long_long(tolua_S, 3,&arg1, "lstg.Stream:seek");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_seek'", nullptr);
            return 0;
        }
        bool ret = cobj->seek(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:seek",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_seek'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_tell(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_tell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_tell'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->tell();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:tell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_tell'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_resize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_resize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned long long arg0;

        ok &= lstg::lua::luaval_to_unsigned_long_long(tolua_S, 2,&arg0, "lstg.Stream:resize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_resize'", nullptr);
            return 0;
        }
        bool ret = cobj->resize(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:resize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_resize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_Stream_size(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Stream* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Stream",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Stream*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_Stream_size'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_Stream_size'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->size();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Stream:size",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_Stream_size'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_Stream_Stream_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Stream)");
    return 0;
}

int lua_register_x_Stream_Stream(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.Stream");
    tolua_cclass(tolua_S,"Stream","lstg.Stream","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Stream");
        tolua_function(tolua_S,"isResizable",lua_x_Stream_Stream_isResizable);
        tolua_function(tolua_S,"isWritable",lua_x_Stream_Stream_isWritable);
        tolua_function(tolua_S,"unlock",lua_x_Stream_Stream_unlock);
        tolua_function(tolua_S,"tryLock",lua_x_Stream_Stream_tryLock);
        tolua_function(tolua_S,"lock",lua_x_Stream_Stream_lock);
        tolua_function(tolua_S,"fill",lua_x_Stream_Stream_fill);
        tolua_function(tolua_S,"seek",lua_x_Stream_Stream_seek);
        tolua_function(tolua_S,"tell",lua_x_Stream_Stream_tell);
        tolua_function(tolua_S,"resize",lua_x_Stream_Stream_resize);
        tolua_function(tolua_S,"size",lua_x_Stream_Stream_size);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::Stream).name();
    g_luaType[typeName] = "lstg.Stream";
    g_typeCast["Stream"] = "lstg.Stream";
    return 1;
}

int lua_x_Stream_StreamFile_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.StreamFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.StreamFile:create");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.StreamFile:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamFile_create'", nullptr);
            return 0;
        }
        lstg::StreamFile* ret = lstg::StreamFile::create(arg0, arg1);
        object_to_luaval<lstg::StreamFile>(tolua_S, "lstg.StreamFile",(lstg::StreamFile*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.StreamFile:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_StreamFile_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Stream_StreamFile_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StreamFile)");
    return 0;
}

int lua_register_x_Stream_StreamFile(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.StreamFile");
    tolua_cclass(tolua_S,"StreamFile","lstg.StreamFile","lstg.Stream",nullptr);

    tolua_beginmodule(tolua_S,"StreamFile");
        tolua_function(tolua_S,"create", lua_x_Stream_StreamFile_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::StreamFile).name();
    g_luaType[typeName] = "lstg.StreamFile";
    g_typeCast["StreamFile"] = "lstg.StreamFile";
    return 1;
}

int lua_x_Stream_StreamMemory_getBuffer(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StreamMemory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.StreamMemory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::StreamMemory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_StreamMemory_getBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamMemory_getBuffer'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->getBuffer();
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StreamMemory:getBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_StreamMemory_getBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_StreamMemory_data(lua_State* tolua_S)
{
    int argc = 0;
    lstg::StreamMemory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.StreamMemory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::StreamMemory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Stream_StreamMemory_data'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamMemory_data'", nullptr);
            return 0;
        }
        unsigned char* ret = cobj->data();
        lstg::lua::cptr_to_luaval(tolua_S, ret, "unsigned char*");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.StreamMemory:data",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_StreamMemory_data'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Stream_StreamMemory_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.StreamMemory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamMemory_create'", nullptr);
            return 0;
        }
        lstg::StreamMemory* ret = lstg::StreamMemory::create();
        object_to_luaval<lstg::StreamMemory>(tolua_S, "lstg.StreamMemory",(lstg::StreamMemory*)ret);
        return 1;
    }
    if (argc == 1)
    {
        lstg::Buffer* arg0;
        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.StreamMemory:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamMemory_create'", nullptr);
            return 0;
        }
        lstg::StreamMemory* ret = lstg::StreamMemory::create(arg0);
        object_to_luaval<lstg::StreamMemory>(tolua_S, "lstg.StreamMemory",(lstg::StreamMemory*)ret);
        return 1;
    }
    if (argc == 2)
    {
        lstg::Buffer* arg0;
        bool arg1;
        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.StreamMemory:create");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "lstg.StreamMemory:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Stream_StreamMemory_create'", nullptr);
            return 0;
        }
        lstg::StreamMemory* ret = lstg::StreamMemory::create(arg0, arg1);
        object_to_luaval<lstg::StreamMemory>(tolua_S, "lstg.StreamMemory",(lstg::StreamMemory*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.StreamMemory:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Stream_StreamMemory_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Stream_StreamMemory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (StreamMemory)");
    return 0;
}

int lua_register_x_Stream_StreamMemory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.StreamMemory");
    tolua_cclass(tolua_S,"StreamMemory","lstg.StreamMemory","lstg.Stream",nullptr);

    tolua_beginmodule(tolua_S,"StreamMemory");
        tolua_function(tolua_S,"getBuffer",lua_x_Stream_StreamMemory_getBuffer);
        tolua_function(tolua_S,"data",lua_x_Stream_StreamMemory_data);
        tolua_function(tolua_S,"create", lua_x_Stream_StreamMemory_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::StreamMemory).name();
    g_luaType[typeName] = "lstg.StreamMemory";
    g_typeCast["StreamMemory"] = "lstg.StreamMemory";
    return 1;
}
TOLUA_API int register_all_x_Stream(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Stream_Stream(tolua_S);
	lua_register_x_Stream_StreamFile(tolua_S);
	lua_register_x_Stream_StreamMemory(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

