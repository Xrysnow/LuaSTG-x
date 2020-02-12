#include "lua_ParticlePool_auto.hpp"
#include "../LSTG/ResParticle.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLua.h"
#include "UtilLuaConversion.h"
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b
//using namespace lstg::lua;

int lua_x_ParticlePool_ParticlePool_getSpread(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpread'", nullptr);
            return 0;
        }
        double ret = cobj->getSpread();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpread'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSpeedMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpeedMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpeedMin'", nullptr);
            return 0;
        }
        double ret = cobj->getSpeedMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpeedMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpeedMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSeed'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getSeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSizeStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSizeStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSizeStart'", nullptr);
            return 0;
        }
        double ret = cobj->getSizeStart();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSizeStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSizeStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getResource(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getResource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getResource'", nullptr);
            return 0;
        }
        lstg::ResParticle* ret = cobj->getResource();
        object_to_luaval<lstg::ResParticle>(tolua_S, "lstg.ResParticle",(lstg::ResParticle*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getResource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getResource'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getLifeMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getLifeMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getLifeMin'", nullptr);
            return 0;
        }
        double ret = cobj->getLifeMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getLifeMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getLifeMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSpeedMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpeedMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpeedMax'", nullptr);
            return 0;
        }
        double ret = cobj->getSpeedMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpeedMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpeedMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setColorVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setColorVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setColorVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setColorVar'", nullptr);
            return 0;
        }
        cobj->setColorVar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setColorVar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setColorVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getEmissionFreq(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getEmissionFreq'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getEmissionFreq'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getEmissionFreq();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getEmissionFreq",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getEmissionFreq'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setGravityMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setGravityMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setGravityMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setGravityMin'", nullptr);
            return 0;
        }
        cobj->setGravityMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setGravityMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setGravityMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpinEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpinEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpinEnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpinEnd'", nullptr);
            return 0;
        }
        cobj->setSpinEnd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpinEnd",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpinEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setColorEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setColorEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResParticle::ParticlePool:setColorEnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setColorEnd'", nullptr);
            return 0;
        }
        cobj->setColorEnd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setColorEnd",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setColorEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getGravityMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getGravityMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getGravityMax'", nullptr);
            return 0;
        }
        double ret = cobj->getGravityMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getGravityMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getGravityMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setTangentialAccelMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setTangentialAccelMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMin'", nullptr);
            return 0;
        }
        cobj->setTangentialAccelMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setTangentialAccelMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpread(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpread");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpread'", nullptr);
            return 0;
        }
        cobj->setSpread(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpread",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpread'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getRelative(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getRelative'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getRelative'", nullptr);
            return 0;
        }
        bool ret = cobj->getRelative();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getRelative",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getRelative'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSeed'", nullptr);
            return 0;
        }
        cobj->setSeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getLifeMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getLifeMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getLifeMax'", nullptr);
            return 0;
        }
        double ret = cobj->getLifeMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getLifeMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getLifeMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setTangentialAccelMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setTangentialAccelMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMax'", nullptr);
            return 0;
        }
        cobj->setTangentialAccelMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setTangentialAccelMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setTangentialAccelMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setLifeMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setLifeMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setLifeMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setLifeMax'", nullptr);
            return 0;
        }
        cobj->setLifeMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setLifeMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setLifeMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setDirection");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setDirection'", nullptr);
            return 0;
        }
        cobj->setDirection(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setAlphaVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setAlphaVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setAlphaVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setAlphaVar'", nullptr);
            return 0;
        }
        cobj->setAlphaVar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setAlphaVar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setAlphaVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setColorStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setColorStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResParticle::ParticlePool:setColorStart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setColorStart'", nullptr);
            return 0;
        }
        cobj->setColorStart(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setColorStart",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setColorStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setRelative(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setRelative'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setRelative");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setRelative'", nullptr);
            return 0;
        }
        cobj->setRelative(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setRelative",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setRelative'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpeedMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpeedMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpeedMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpeedMin'", nullptr);
            return 0;
        }
        cobj->setSpeedMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpeedMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpeedMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setActive(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setActive");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setActive'", nullptr);
            return 0;
        }
        cobj->setActive(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setActive",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setActive'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getRadialAccelMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMin'", nullptr);
            return 0;
        }
        double ret = cobj->getRadialAccelMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getRadialAccelMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setRadialAccelMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setRadialAccelMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMin'", nullptr);
            return 0;
        }
        cobj->setRadialAccelMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setRadialAccelMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setCenter(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "lstg.ResParticle::ParticlePool:setCenter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setCenter'", nullptr);
            return 0;
        }
        cobj->setCenter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setCenter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getAlphaVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getAlphaVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getAlphaVar'", nullptr);
            return 0;
        }
        double ret = cobj->getAlphaVar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getAlphaVar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getAlphaVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setEmissionFreq(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setEmissionFreq'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setEmissionFreq");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setEmissionFreq'", nullptr);
            return 0;
        }
        cobj->setEmissionFreq(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setEmissionFreq",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setEmissionFreq'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getRadialAccelMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMax'", nullptr);
            return 0;
        }
        double ret = cobj->getRadialAccelMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getRadialAccelMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getRadialAccelMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpeedMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpeedMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpeedMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpeedMax'", nullptr);
            return 0;
        }
        cobj->setSpeedMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpeedMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpeedMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getCenter(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getCenter'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getCenter();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getCenter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSizeVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSizeVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSizeVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSizeVar'", nullptr);
            return 0;
        }
        cobj->setSizeVar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSizeVar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSizeVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpinStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpinStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpinStart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpinStart'", nullptr);
            return 0;
        }
        cobj->setSpinStart(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpinStart",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpinStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSpinEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpinEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpinEnd'", nullptr);
            return 0;
        }
        double ret = cobj->getSpinEnd();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpinEnd",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpinEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getTangentialAccelMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMin'", nullptr);
            return 0;
        }
        double ret = cobj->getTangentialAccelMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getTangentialAccelMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setRotation(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setRotation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setRotation'", nullptr);
            return 0;
        }
        cobj->setRotation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setRotation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setLifeMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setLifeMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setLifeMin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setLifeMin'", nullptr);
            return 0;
        }
        cobj->setLifeMin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setLifeMin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setLifeMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setRadialAccelMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setRadialAccelMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMax'", nullptr);
            return 0;
        }
        cobj->setRadialAccelMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setRadialAccelMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setRadialAccelMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getColorEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getColorEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getColorEnd'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getColorEnd();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getColorEnd",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getColorEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getRotation(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getRotation'", nullptr);
            return 0;
        }
        double ret = cobj->getRotation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSizeStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSizeStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSizeStart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSizeStart'", nullptr);
            return 0;
        }
        cobj->setSizeStart(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSizeStart",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSizeStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_isActive(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_isActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_isActive'", nullptr);
            return 0;
        }
        bool ret = cobj->isActive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:isActive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_isActive'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getTangentialAccelMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMax'", nullptr);
            return 0;
        }
        double ret = cobj->getTangentialAccelMax();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getTangentialAccelMax",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getTangentialAccelMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getColorVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getColorVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getColorVar'", nullptr);
            return 0;
        }
        double ret = cobj->getColorVar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getColorVar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getColorVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSizeEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSizeEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSizeEnd'", nullptr);
            return 0;
        }
        double ret = cobj->getSizeEnd();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSizeEnd",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSizeEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getColorStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getColorStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getColorStart'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getColorStart();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getColorStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getColorStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getGravityMin(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getGravityMin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getGravityMin'", nullptr);
            return 0;
        }
        double ret = cobj->getGravityMin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getGravityMin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getGravityMin'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getRenderMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getRenderMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getRenderMode'", nullptr);
            return 0;
        }
        lstg::RenderMode* ret = cobj->getRenderMode();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getRenderMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getRenderMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSpinVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSpinVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSpinVar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSpinVar'", nullptr);
            return 0;
        }
        cobj->setSpinVar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSpinVar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSpinVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSpinStart(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpinStart'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpinStart'", nullptr);
            return 0;
        }
        double ret = cobj->getSpinStart();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpinStart",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpinStart'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getLifetime(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getLifetime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getLifetime'", nullptr);
            return 0;
        }
        double ret = cobj->getLifetime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getLifetime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getLifetime'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSizeVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSizeVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSizeVar'", nullptr);
            return 0;
        }
        double ret = cobj->getSizeVar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSizeVar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSizeVar'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getDirection'", nullptr);
            return 0;
        }
        double ret = cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setSizeEnd(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setSizeEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setSizeEnd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setSizeEnd'", nullptr);
            return 0;
        }
        cobj->setSizeEnd(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setSizeEnd",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setSizeEnd'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getAliveCount(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getAliveCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getAliveCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getAliveCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getAliveCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getAliveCount'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setLifetime(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setLifetime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setLifetime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setLifetime'", nullptr);
            return 0;
        }
        cobj->setLifetime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setLifetime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setLifetime'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setRenderMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setRenderMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::RenderMode* arg0;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.ResParticle::ParticlePool:setRenderMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setRenderMode'", nullptr);
            return 0;
        }
        cobj->setRenderMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setRenderMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setRenderMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_setGravityMax(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_setGravityMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResParticle::ParticlePool:setGravityMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_setGravityMax'", nullptr);
            return 0;
        }
        cobj->setGravityMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:setGravityMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_setGravityMax'.",&tolua_err);
#endif

    return 0;
}
int lua_x_ParticlePool_ParticlePool_getSpinVar(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle::ParticlePool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle::ParticlePool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle::ParticlePool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_ParticlePool_ParticlePool_getSpinVar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_ParticlePool_ParticlePool_getSpinVar'", nullptr);
            return 0;
        }
        double ret = cobj->getSpinVar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle::ParticlePool:getSpinVar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_ParticlePool_ParticlePool_getSpinVar'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_ParticlePool_ParticlePool_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ParticlePool)");
    return 0;
}

int lua_register_x_ParticlePool_ParticlePool(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResParticle::ParticlePool");
    tolua_cclass(tolua_S,"ParticlePool","lstg.ResParticle::ParticlePool","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ParticlePool");
        tolua_function(tolua_S,"getSpread",lua_x_ParticlePool_ParticlePool_getSpread);
        tolua_function(tolua_S,"getSpeedMin",lua_x_ParticlePool_ParticlePool_getSpeedMin);
        tolua_function(tolua_S,"getSeed",lua_x_ParticlePool_ParticlePool_getSeed);
        tolua_function(tolua_S,"getSizeStart",lua_x_ParticlePool_ParticlePool_getSizeStart);
        tolua_function(tolua_S,"getResource",lua_x_ParticlePool_ParticlePool_getResource);
        tolua_function(tolua_S,"getLifeMin",lua_x_ParticlePool_ParticlePool_getLifeMin);
        tolua_function(tolua_S,"getSpeedMax",lua_x_ParticlePool_ParticlePool_getSpeedMax);
        tolua_function(tolua_S,"setColorVar",lua_x_ParticlePool_ParticlePool_setColorVar);
        tolua_function(tolua_S,"getEmissionFreq",lua_x_ParticlePool_ParticlePool_getEmissionFreq);
        tolua_function(tolua_S,"setGravityMin",lua_x_ParticlePool_ParticlePool_setGravityMin);
        tolua_function(tolua_S,"setSpinEnd",lua_x_ParticlePool_ParticlePool_setSpinEnd);
        tolua_function(tolua_S,"setColorEnd",lua_x_ParticlePool_ParticlePool_setColorEnd);
        tolua_function(tolua_S,"getGravityMax",lua_x_ParticlePool_ParticlePool_getGravityMax);
        tolua_function(tolua_S,"setTangentialAccelMin",lua_x_ParticlePool_ParticlePool_setTangentialAccelMin);
        tolua_function(tolua_S,"setSpread",lua_x_ParticlePool_ParticlePool_setSpread);
        tolua_function(tolua_S,"getRelative",lua_x_ParticlePool_ParticlePool_getRelative);
        tolua_function(tolua_S,"setSeed",lua_x_ParticlePool_ParticlePool_setSeed);
        tolua_function(tolua_S,"getLifeMax",lua_x_ParticlePool_ParticlePool_getLifeMax);
        tolua_function(tolua_S,"setTangentialAccelMax",lua_x_ParticlePool_ParticlePool_setTangentialAccelMax);
        tolua_function(tolua_S,"setLifeMax",lua_x_ParticlePool_ParticlePool_setLifeMax);
        tolua_function(tolua_S,"setDirection",lua_x_ParticlePool_ParticlePool_setDirection);
        tolua_function(tolua_S,"setAlphaVar",lua_x_ParticlePool_ParticlePool_setAlphaVar);
        tolua_function(tolua_S,"setColorStart",lua_x_ParticlePool_ParticlePool_setColorStart);
        tolua_function(tolua_S,"setRelative",lua_x_ParticlePool_ParticlePool_setRelative);
        tolua_function(tolua_S,"setSpeedMin",lua_x_ParticlePool_ParticlePool_setSpeedMin);
        tolua_function(tolua_S,"setActive",lua_x_ParticlePool_ParticlePool_setActive);
        tolua_function(tolua_S,"getRadialAccelMin",lua_x_ParticlePool_ParticlePool_getRadialAccelMin);
        tolua_function(tolua_S,"setRadialAccelMin",lua_x_ParticlePool_ParticlePool_setRadialAccelMin);
        tolua_function(tolua_S,"setCenter",lua_x_ParticlePool_ParticlePool_setCenter);
        tolua_function(tolua_S,"getAlphaVar",lua_x_ParticlePool_ParticlePool_getAlphaVar);
        tolua_function(tolua_S,"setEmissionFreq",lua_x_ParticlePool_ParticlePool_setEmissionFreq);
        tolua_function(tolua_S,"getRadialAccelMax",lua_x_ParticlePool_ParticlePool_getRadialAccelMax);
        tolua_function(tolua_S,"setSpeedMax",lua_x_ParticlePool_ParticlePool_setSpeedMax);
        tolua_function(tolua_S,"getCenter",lua_x_ParticlePool_ParticlePool_getCenter);
        tolua_function(tolua_S,"setSizeVar",lua_x_ParticlePool_ParticlePool_setSizeVar);
        tolua_function(tolua_S,"setSpinStart",lua_x_ParticlePool_ParticlePool_setSpinStart);
        tolua_function(tolua_S,"getSpinEnd",lua_x_ParticlePool_ParticlePool_getSpinEnd);
        tolua_function(tolua_S,"getTangentialAccelMin",lua_x_ParticlePool_ParticlePool_getTangentialAccelMin);
        tolua_function(tolua_S,"setRotation",lua_x_ParticlePool_ParticlePool_setRotation);
        tolua_function(tolua_S,"setLifeMin",lua_x_ParticlePool_ParticlePool_setLifeMin);
        tolua_function(tolua_S,"setRadialAccelMax",lua_x_ParticlePool_ParticlePool_setRadialAccelMax);
        tolua_function(tolua_S,"getColorEnd",lua_x_ParticlePool_ParticlePool_getColorEnd);
        tolua_function(tolua_S,"getRotation",lua_x_ParticlePool_ParticlePool_getRotation);
        tolua_function(tolua_S,"setSizeStart",lua_x_ParticlePool_ParticlePool_setSizeStart);
        tolua_function(tolua_S,"isActive",lua_x_ParticlePool_ParticlePool_isActive);
        tolua_function(tolua_S,"getTangentialAccelMax",lua_x_ParticlePool_ParticlePool_getTangentialAccelMax);
        tolua_function(tolua_S,"getColorVar",lua_x_ParticlePool_ParticlePool_getColorVar);
        tolua_function(tolua_S,"getSizeEnd",lua_x_ParticlePool_ParticlePool_getSizeEnd);
        tolua_function(tolua_S,"getColorStart",lua_x_ParticlePool_ParticlePool_getColorStart);
        tolua_function(tolua_S,"getGravityMin",lua_x_ParticlePool_ParticlePool_getGravityMin);
        tolua_function(tolua_S,"getRenderMode",lua_x_ParticlePool_ParticlePool_getRenderMode);
        tolua_function(tolua_S,"setSpinVar",lua_x_ParticlePool_ParticlePool_setSpinVar);
        tolua_function(tolua_S,"getSpinStart",lua_x_ParticlePool_ParticlePool_getSpinStart);
        tolua_function(tolua_S,"getLifetime",lua_x_ParticlePool_ParticlePool_getLifetime);
        tolua_function(tolua_S,"getSizeVar",lua_x_ParticlePool_ParticlePool_getSizeVar);
        tolua_function(tolua_S,"getDirection",lua_x_ParticlePool_ParticlePool_getDirection);
        tolua_function(tolua_S,"setSizeEnd",lua_x_ParticlePool_ParticlePool_setSizeEnd);
        tolua_function(tolua_S,"getAliveCount",lua_x_ParticlePool_ParticlePool_getAliveCount);
        tolua_function(tolua_S,"setLifetime",lua_x_ParticlePool_ParticlePool_setLifetime);
        tolua_function(tolua_S,"setRenderMode",lua_x_ParticlePool_ParticlePool_setRenderMode);
        tolua_function(tolua_S,"setGravityMax",lua_x_ParticlePool_ParticlePool_setGravityMax);
        tolua_function(tolua_S,"getSpinVar",lua_x_ParticlePool_ParticlePool_getSpinVar);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResParticle::ParticlePool).name();
    g_luaType[typeName] = "lstg.ResParticle::ParticlePool";
    g_typeCast["ParticlePool"] = "lstg.ResParticle::ParticlePool";
    return 1;
}
TOLUA_API int register_all_x_ParticlePool(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_ParticlePool_ParticlePool(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

