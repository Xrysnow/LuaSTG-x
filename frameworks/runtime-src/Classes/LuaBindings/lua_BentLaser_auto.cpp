#include "lua_BentLaser_auto.hpp"
#include "../LSTG/GameObjectBentLaser.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLua.h"

//using namespace lstg::lua;
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b

int lua_x_BentLaser_GameObjectBentLaser_render(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_render'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 7) {
            lstg::ResTexture* arg0;
            ok &= luaval_to_object<lstg::ResTexture>(tolua_S, 2, "lstg.ResTexture",&arg0, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            lstg::BlendMode* arg1;
            ok &= lstg::lua::luaval_to_BlendMode(tolua_S, 3, &arg1, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            cocos2d::Color4B arg2;
            ok &=luaval_to_color4b(tolua_S, 4, &arg2, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            double arg5;
            ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            double arg6;
            ok &= luaval_to_number(tolua_S, 8,&arg6, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            cobj->render(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            lstg::ResSprite* arg0;
            ok &= luaval_to_object<lstg::ResSprite>(tolua_S, 2, "lstg.ResSprite",&arg0, "lstg.GameObjectBentLaser:render");

            if (!ok) { break; }
            cobj->render(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:render",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_render'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setLengthLimit(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setLengthLimit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setLengthLimit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setLengthLimit'", nullptr);
            return 0;
        }
        cobj->setLengthLimit(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setLengthLimit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setLengthLimit'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setColorMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setColorMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::GameObjectBentLaser::ColorMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.GameObjectBentLaser:setColorMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setColorMode'", nullptr);
            return 0;
        }
        cobj->setColorMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        lstg::GameObjectBentLaser::ColorMode arg0;
        lstg::GameObjectBentLaser::ColorMixMode arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.GameObjectBentLaser:setColorMode");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.GameObjectBentLaser:setColorMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setColorMode'", nullptr);
            return 0;
        }
        cobj->setColorMode(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setColorMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setColorMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:collisionCheckExtendWidth");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:collisionCheckExtendWidth");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:collisionCheckExtendWidth");

            if (!ok) { break; }
            bool ret = cobj->collisionCheckExtendWidth(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            lstg::GameObject* arg0;
            ok &= lstg::lua::luaval_to_GameObject(tolua_S, 2, &arg0, "lstg.GameObjectBentLaser:collisionCheckExtendWidth");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:collisionCheckExtendWidth");

            if (!ok) { break; }
            bool ret = cobj->collisionCheckExtendWidth(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:collisionCheckExtendWidth",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:getNodeWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getNodeWidth(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodeWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeLimit(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLimit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLimit'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getNodeLimit();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodeLimit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLimit'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodePosition(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodePosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:getNodePosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodePosition'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getNodePosition(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodePosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodePosition'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_pushHead(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_pushHead'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            cobj->pushHead(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            cobj->pushHead(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            cocos2d::Color4B arg3;
            ok &=luaval_to_color4b(tolua_S, 5, &arg3, "lstg.GameObjectBentLaser:pushHead");

            if (!ok) { break; }
            cobj->pushHead(arg0, arg1, arg2, arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:pushHead",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_pushHead'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getColorMixMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMixMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMixMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getColorMixMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getColorMixMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMixMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_popHead(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_popHead'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:popHead");

            if (!ok) { break; }
            cobj->popHead(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->popHead();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:popHead",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_popHead'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:strictCollisionCheck");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:strictCollisionCheck");

            if (!ok) { break; }
            bool ret = cobj->strictCollisionCheck(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            lstg::GameObject* arg0;
            ok &= lstg::lua::luaval_to_GameObject(tolua_S, 2, &arg0, "lstg.GameObjectBentLaser:strictCollisionCheck");

            if (!ok) { break; }
            bool ret = cobj->strictCollisionCheck(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:strictCollisionCheck",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeLength(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:getNodeLength");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLength'", nullptr);
            return 0;
        }
        double ret = cobj->getNodeLength(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodeLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeLength'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setRenderScale(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setRenderScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setRenderScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setRenderScale'", nullptr);
            return 0;
        }
        cobj->setRenderScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setRenderScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setRenderScale'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getLength(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getLength'", nullptr);
            return 0;
        }
        double ret = cobj->getLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getLength'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_collisionCheck(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_collisionCheck'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:collisionCheck");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:collisionCheck");

            if (!ok) { break; }
            bool ret = cobj->collisionCheck(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            lstg::GameObject* arg0;
            ok &= lstg::lua::luaval_to_GameObject(tolua_S, 2, &arg0, "lstg.GameObjectBentLaser:collisionCheck");

            if (!ok) { break; }
            bool ret = cobj->collisionCheck(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:collisionCheck",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_collisionCheck'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_pushTail(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_pushTail'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            cobj->pushTail(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            cobj->pushTail(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            cocos2d::Color4B arg3;
            ok &=luaval_to_color4b(tolua_S, 5, &arg3, "lstg.GameObjectBentLaser:pushTail");

            if (!ok) { break; }
            cobj->pushTail(arg0, arg1, arg2, arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:pushTail",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_pushTail'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        double arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setNodeWidth");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:setNodeWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeWidth'", nullptr);
            return 0;
        }
        cobj->setNodeWidth(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setNodeWidth",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getLengthLimit(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getLengthLimit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getLengthLimit'", nullptr);
            return 0;
        }
        double ret = cobj->getLengthLimit();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getLengthLimit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getLengthLimit'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeCount(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getNodeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getDefaultWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getDefaultWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setDefaultColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.GameObjectBentLaser:setDefaultColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultColor'", nullptr);
            return 0;
        }
        cobj->setDefaultColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setDefaultColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setDefaultWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth'", nullptr);
            return 0;
        }
        cobj->setDefaultWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setDefaultWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeLimit(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeLimit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setNodeLimit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeLimit'", nullptr);
            return 0;
        }
        cobj->setNodeLimit(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setNodeLimit",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeLimit'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setNodePosition(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setNodePosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        unsigned int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setNodePosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.GameObjectBentLaser:setNodePosition");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.GameObjectBentLaser:setNodePosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setNodePosition'", nullptr);
            return 0;
        }
        cobj->setNodePosition(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setNodePosition",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setNodePosition'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_reset(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_popTail(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_popTail'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:popTail");

            if (!ok) { break; }
            cobj->popTail(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->popTail();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.GameObjectBentLaser:popTail",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_popTail'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_clear(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setAllWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setAllWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setAllWidth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setAllWidth'", nullptr);
            return 0;
        }
        cobj->setAllWidth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setAllWidth",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setAllWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        unsigned int arg0;
        cocos2d::Color4B arg1;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:setNodeColor");

        ok &=luaval_to_color4b(tolua_S, 3, &arg1, "lstg.GameObjectBentLaser:setNodeColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeColor'", nullptr);
            return 0;
        }
        cobj->setNodeColor(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setNodeColor",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setNodeColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getColorMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getColorMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getColorMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getColorMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getDefaultColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getDefaultColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getDefaultColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getDefaultColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.GameObjectBentLaser:getNodeColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getNodeColor(arg0);
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getNodeColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getNodeColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_boundCheck(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_boundCheck'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_boundCheck'", nullptr);
            return 0;
        }
        bool ret = cobj->boundCheck();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:boundCheck",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_boundCheck'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_getRenderScale(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_getRenderScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_getRenderScale'", nullptr);
            return 0;
        }
        double ret = cobj->getRenderScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:getRenderScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_getRenderScale'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_setAllColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::GameObjectBentLaser* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_BentLaser_GameObjectBentLaser_setAllColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.GameObjectBentLaser:setAllColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_setAllColor'", nullptr);
            return 0;
        }
        cobj->setAllColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.GameObjectBentLaser:setAllColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_setAllColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_BentLaser_GameObjectBentLaser_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.GameObjectBentLaser",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_BentLaser_GameObjectBentLaser_create'", nullptr);
            return 0;
        }
        lstg::GameObjectBentLaser* ret = lstg::GameObjectBentLaser::create();
        object_to_luaval<lstg::GameObjectBentLaser>(tolua_S, "lstg.GameObjectBentLaser",(lstg::GameObjectBentLaser*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.GameObjectBentLaser:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_BentLaser_GameObjectBentLaser_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_BentLaser_GameObjectBentLaser_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameObjectBentLaser)");
    return 0;
}

int lua_register_x_BentLaser_GameObjectBentLaser(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.GameObjectBentLaser");
    tolua_cclass(tolua_S,"GameObjectBentLaser","lstg.GameObjectBentLaser","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GameObjectBentLaser");
        tolua_function(tolua_S,"render",lua_x_BentLaser_GameObjectBentLaser_render);
        tolua_function(tolua_S,"setLengthLimit",lua_x_BentLaser_GameObjectBentLaser_setLengthLimit);
        tolua_function(tolua_S,"setColorMode",lua_x_BentLaser_GameObjectBentLaser_setColorMode);
        tolua_function(tolua_S,"collisionCheckExtendWidth",lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth);
        tolua_function(tolua_S,"getNodeWidth",lua_x_BentLaser_GameObjectBentLaser_getNodeWidth);
        tolua_function(tolua_S,"getNodeLimit",lua_x_BentLaser_GameObjectBentLaser_getNodeLimit);
        tolua_function(tolua_S,"getNodePosition",lua_x_BentLaser_GameObjectBentLaser_getNodePosition);
        tolua_function(tolua_S,"pushHead",lua_x_BentLaser_GameObjectBentLaser_pushHead);
        tolua_function(tolua_S,"getColorMixMode",lua_x_BentLaser_GameObjectBentLaser_getColorMixMode);
        tolua_function(tolua_S,"popHead",lua_x_BentLaser_GameObjectBentLaser_popHead);
        tolua_function(tolua_S,"strictCollisionCheck",lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck);
        tolua_function(tolua_S,"getNodeLength",lua_x_BentLaser_GameObjectBentLaser_getNodeLength);
        tolua_function(tolua_S,"setRenderScale",lua_x_BentLaser_GameObjectBentLaser_setRenderScale);
        tolua_function(tolua_S,"getLength",lua_x_BentLaser_GameObjectBentLaser_getLength);
        tolua_function(tolua_S,"collisionCheck",lua_x_BentLaser_GameObjectBentLaser_collisionCheck);
        tolua_function(tolua_S,"pushTail",lua_x_BentLaser_GameObjectBentLaser_pushTail);
        tolua_function(tolua_S,"setNodeWidth",lua_x_BentLaser_GameObjectBentLaser_setNodeWidth);
        tolua_function(tolua_S,"getLengthLimit",lua_x_BentLaser_GameObjectBentLaser_getLengthLimit);
        tolua_function(tolua_S,"getNodeCount",lua_x_BentLaser_GameObjectBentLaser_getNodeCount);
        tolua_function(tolua_S,"getDefaultWidth",lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth);
        tolua_function(tolua_S,"setDefaultColor",lua_x_BentLaser_GameObjectBentLaser_setDefaultColor);
        tolua_function(tolua_S,"setDefaultWidth",lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth);
        tolua_function(tolua_S,"setNodeLimit",lua_x_BentLaser_GameObjectBentLaser_setNodeLimit);
        tolua_function(tolua_S,"setNodePosition",lua_x_BentLaser_GameObjectBentLaser_setNodePosition);
        tolua_function(tolua_S,"reset",lua_x_BentLaser_GameObjectBentLaser_reset);
        tolua_function(tolua_S,"popTail",lua_x_BentLaser_GameObjectBentLaser_popTail);
        tolua_function(tolua_S,"clear",lua_x_BentLaser_GameObjectBentLaser_clear);
        tolua_function(tolua_S,"setAllWidth",lua_x_BentLaser_GameObjectBentLaser_setAllWidth);
        tolua_function(tolua_S,"setNodeColor",lua_x_BentLaser_GameObjectBentLaser_setNodeColor);
        tolua_function(tolua_S,"getColorMode",lua_x_BentLaser_GameObjectBentLaser_getColorMode);
        tolua_function(tolua_S,"getDefaultColor",lua_x_BentLaser_GameObjectBentLaser_getDefaultColor);
        tolua_function(tolua_S,"getNodeColor",lua_x_BentLaser_GameObjectBentLaser_getNodeColor);
        tolua_function(tolua_S,"boundCheck",lua_x_BentLaser_GameObjectBentLaser_boundCheck);
        tolua_function(tolua_S,"getRenderScale",lua_x_BentLaser_GameObjectBentLaser_getRenderScale);
        tolua_function(tolua_S,"setAllColor",lua_x_BentLaser_GameObjectBentLaser_setAllColor);
        tolua_function(tolua_S,"create", lua_x_BentLaser_GameObjectBentLaser_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::GameObjectBentLaser).name();
    g_luaType[typeName] = "lstg.GameObjectBentLaser";
    g_typeCast["GameObjectBentLaser"] = "lstg.GameObjectBentLaser";
    return 1;
}
TOLUA_API int register_all_x_BentLaser(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_BentLaser_GameObjectBentLaser(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

