#include "lua_Buffer_auto.hpp"
#include "XStream.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLua.h"
#define printf(...)

int lua_x_Buffer_Buffer_set(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_set'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        uint16_t arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:set");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "lstg.Buffer:set");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_set'", nullptr);
            return 0;
        }
        cobj->set(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:set",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_set'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_setShrinkable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_setShrinkable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.Buffer:setShrinkable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_setShrinkable'", nullptr);
            return 0;
        }
        cobj->setShrinkable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:setShrinkable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_setShrinkable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_move(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_move'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::Buffer* arg0;

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.Buffer:move");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_move'", nullptr);
            return 0;
        }
        cobj->move(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:move",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_move'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_back(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_back'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_back'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->back();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:back",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_back'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_erase(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_erase'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        unsigned int arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:erase");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "lstg.Buffer:erase");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_erase'", nullptr);
            return 0;
        }
        cobj->erase(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:erase",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_erase'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_at(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_at'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:at");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_at'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->at(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:at",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_at'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_isShrinkable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_isShrinkable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_isShrinkable'", nullptr);
            return 0;
        }
        bool ret = cobj->isShrinkable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:isShrinkable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_isShrinkable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_size(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_size'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_size'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->size();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:size",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_size'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_setResizable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_setResizable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.Buffer:setResizable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_setResizable'", nullptr);
            return 0;
        }
        cobj->setResizable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:setResizable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_setResizable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_capacity(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_capacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_capacity'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->capacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:capacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_capacity'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_isResizable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_isResizable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_isResizable'", nullptr);
            return 0;
        }
        bool ret = cobj->isResizable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:isResizable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_isResizable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_isWritable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_isWritable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_isWritable'", nullptr);
            return 0;
        }
        bool ret = cobj->isWritable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:isWritable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_isWritable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_swap(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_swap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::Buffer* arg0;

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.Buffer:swap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_swap'", nullptr);
            return 0;
        }
        cobj->swap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:swap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_swap'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_pop_back(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_pop_back'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_pop_back'", nullptr);
            return 0;
        }
        cobj->pop_back();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:pop_back",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_pop_back'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_assign_values(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_assign_values'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<unsigned char> arg0;

        ok &= lstg::lua::luaval_to_std_vector_number<uint8_t>(tolua_S, 2, &arg0, "lstg.Buffer:assign_values");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_assign_values'", nullptr);
            return 0;
        }
        cobj->assign_values(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:assign_values",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_assign_values'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_empty(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_empty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_empty'", nullptr);
            return 0;
        }
        bool ret = cobj->empty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:empty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_empty'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_shrink_to_fit(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_shrink_to_fit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_shrink_to_fit'", nullptr);
            return 0;
        }
        cobj->shrink_to_fit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:shrink_to_fit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_shrink_to_fit'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_insert_value(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_insert_value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        unsigned int arg1;
        uint16_t arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:insert_value");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "lstg.Buffer:insert_value");

        ok &= luaval_to_uint16(tolua_S, 4,&arg2, "lstg.Buffer:insert_value");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_insert_value'", nullptr);
            return 0;
        }
        cobj->insert_value(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:insert_value",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_insert_value'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_clone(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_clone'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = cobj->clone();
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:clone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_assign_value(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_assign_value'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        uint16_t arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:assign_value");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "lstg.Buffer:assign_value");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_assign_value'", nullptr);
            return 0;
        }
        cobj->assign_value(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:assign_value",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_assign_value'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_isAppendable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_isAppendable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_isAppendable'", nullptr);
            return 0;
        }
        bool ret = cobj->isAppendable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:isAppendable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_isAppendable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_front(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_front'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_front'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->front();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:front",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_front'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_copy(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_copy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::Buffer* arg0;

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.Buffer:copy");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_copy'", nullptr);
            return 0;
        }
        cobj->copy(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:copy",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_copy'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_data(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_data'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_data'", nullptr);
            return 0;
        }
        unsigned char* ret = cobj->data();
        lstg::lua::cptr_to_luaval(tolua_S, ret, "unsigned char*");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:data",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_data'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_resize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_resize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:resize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_resize'", nullptr);
            return 0;
        }
        cobj->resize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        unsigned int arg0;
        uint16_t arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:resize");

        ok &= luaval_to_uint16(tolua_S, 3,&arg1, "lstg.Buffer:resize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_resize'", nullptr);
            return 0;
        }
        cobj->resize(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:resize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_resize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_insert(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        unsigned int arg0;
        lstg::Buffer* arg1;
        unsigned int arg2;
        unsigned int arg3;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:insert");

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 3, "lstg.Buffer",&arg1, "lstg.Buffer:insert");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "lstg.Buffer:insert");

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "lstg.Buffer:insert");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_insert'", nullptr);
            return 0;
        }
        cobj->insert(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:insert",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_push_back(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_push_back'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "lstg.Buffer:push_back");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_push_back'", nullptr);
            return 0;
        }
        cobj->push_back(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:push_back",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_push_back'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_clear(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_setAppendable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_setAppendable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.Buffer:setAppendable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_setAppendable'", nullptr);
            return 0;
        }
        cobj->setAppendable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:setAppendable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_setAppendable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_to_string(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_to_string'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_to_string'", nullptr);
            return 0;
        }
        std::string ret = cobj->to_string();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:to_string",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_to_string'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_insert_values(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_insert_values'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        std::vector<unsigned char> arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:insert_values");

        ok &= lstg::lua::luaval_to_std_vector_number<uint8_t>(tolua_S, 3, &arg1, "lstg.Buffer:insert_values");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_insert_values'", nullptr);
            return 0;
        }
        cobj->insert_values(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:insert_values",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_insert_values'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_setWritable(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_setWritable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.Buffer:setWritable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_setWritable'", nullptr);
            return 0;
        }
        cobj->setWritable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:setWritable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_setWritable'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_set_values(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_set_values'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        std::vector<unsigned char> arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:set_values");

        ok &= lstg::lua::luaval_to_std_vector_number<uint8_t>(tolua_S, 3, &arg1, "lstg.Buffer:set_values");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_set_values'", nullptr);
            return 0;
        }
        cobj->set_values(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:set_values",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_set_values'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_assign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_assign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        lstg::Buffer* arg0;
        unsigned int arg1;
        unsigned int arg2;

        ok &= luaval_to_object<lstg::Buffer>(tolua_S, 2, "lstg.Buffer",&arg0, "lstg.Buffer:assign");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "lstg.Buffer:assign");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "lstg.Buffer:assign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_assign'", nullptr);
            return 0;
        }
        cobj->assign(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:assign",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_assign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_reserve(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Buffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Buffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Buffer_Buffer_reserve'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:reserve");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_reserve'", nullptr);
            return 0;
        }
        cobj->reserve(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Buffer:reserve",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_reserve'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Buffer_Buffer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_create'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = lstg::Buffer::create();
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Buffer:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_create'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = lstg::Buffer::create(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.Buffer:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Buffer_Buffer_createFromString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.Buffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.Buffer:createFromString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Buffer_Buffer_createFromString'", nullptr);
            return 0;
        }
        lstg::Buffer* ret = lstg::Buffer::createFromString(arg0);
        object_to_luaval<lstg::Buffer>(tolua_S, "lstg.Buffer",(lstg::Buffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.Buffer:createFromString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Buffer_Buffer_createFromString'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Buffer_Buffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Buffer)");
    return 0;
}

int lua_register_x_Buffer_Buffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.Buffer");
    tolua_cclass(tolua_S,"Buffer","lstg.Buffer","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Buffer");
        tolua_function(tolua_S,"set",lua_x_Buffer_Buffer_set);
        tolua_function(tolua_S,"setShrinkable",lua_x_Buffer_Buffer_setShrinkable);
        tolua_function(tolua_S,"move",lua_x_Buffer_Buffer_move);
        tolua_function(tolua_S,"back",lua_x_Buffer_Buffer_back);
        tolua_function(tolua_S,"erase",lua_x_Buffer_Buffer_erase);
        tolua_function(tolua_S,"at",lua_x_Buffer_Buffer_at);
        tolua_function(tolua_S,"isShrinkable",lua_x_Buffer_Buffer_isShrinkable);
        tolua_function(tolua_S,"size",lua_x_Buffer_Buffer_size);
        tolua_function(tolua_S,"setResizable",lua_x_Buffer_Buffer_setResizable);
        tolua_function(tolua_S,"capacity",lua_x_Buffer_Buffer_capacity);
        tolua_function(tolua_S,"isResizable",lua_x_Buffer_Buffer_isResizable);
        tolua_function(tolua_S,"isWritable",lua_x_Buffer_Buffer_isWritable);
        tolua_function(tolua_S,"swap",lua_x_Buffer_Buffer_swap);
        tolua_function(tolua_S,"pop_back",lua_x_Buffer_Buffer_pop_back);
        tolua_function(tolua_S,"assign_values",lua_x_Buffer_Buffer_assign_values);
        tolua_function(tolua_S,"empty",lua_x_Buffer_Buffer_empty);
        tolua_function(tolua_S,"shrink_to_fit",lua_x_Buffer_Buffer_shrink_to_fit);
        tolua_function(tolua_S,"insert_value",lua_x_Buffer_Buffer_insert_value);
        tolua_function(tolua_S,"clone",lua_x_Buffer_Buffer_clone);
        tolua_function(tolua_S,"assign_value",lua_x_Buffer_Buffer_assign_value);
        tolua_function(tolua_S,"isAppendable",lua_x_Buffer_Buffer_isAppendable);
        tolua_function(tolua_S,"front",lua_x_Buffer_Buffer_front);
        tolua_function(tolua_S,"copy",lua_x_Buffer_Buffer_copy);
        tolua_function(tolua_S,"data",lua_x_Buffer_Buffer_data);
        tolua_function(tolua_S,"resize",lua_x_Buffer_Buffer_resize);
        tolua_function(tolua_S,"insert",lua_x_Buffer_Buffer_insert);
        tolua_function(tolua_S,"push_back",lua_x_Buffer_Buffer_push_back);
        tolua_function(tolua_S,"clear",lua_x_Buffer_Buffer_clear);
        tolua_function(tolua_S,"setAppendable",lua_x_Buffer_Buffer_setAppendable);
        tolua_function(tolua_S,"to_string",lua_x_Buffer_Buffer_to_string);
        tolua_function(tolua_S,"insert_values",lua_x_Buffer_Buffer_insert_values);
        tolua_function(tolua_S,"setWritable",lua_x_Buffer_Buffer_setWritable);
        tolua_function(tolua_S,"set_values",lua_x_Buffer_Buffer_set_values);
        tolua_function(tolua_S,"assign",lua_x_Buffer_Buffer_assign);
        tolua_function(tolua_S,"reserve",lua_x_Buffer_Buffer_reserve);
        tolua_function(tolua_S,"create", lua_x_Buffer_Buffer_create);
        tolua_function(tolua_S,"createFromString", lua_x_Buffer_Buffer_createFromString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::Buffer).name();
    g_luaType[typeName] = "lstg.Buffer";
    g_typeCast["Buffer"] = "lstg.Buffer";
    return 1;
}
TOLUA_API int register_all_x_Buffer(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Buffer_Buffer(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

