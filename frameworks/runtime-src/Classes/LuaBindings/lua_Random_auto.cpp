#include "lua_Random_auto.hpp"
#include "../Classes/Randomizer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_x_Random_XRandom_randFloat(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_randFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:randFloat");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:randFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_randFloat'", nullptr);
            return 0;
        }
        double ret = cobj->randFloat(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:randFloat",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_randFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_log_norml(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_log_norml'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:log_norml");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:log_norml");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_log_norml'", nullptr);
            return 0;
        }
        double ret = cobj->log_norml(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:log_norml",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_log_norml'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_vonMises(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_vonMises'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:vonMises");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:vonMises");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_vonMises'", nullptr);
            return 0;
        }
        double ret = cobj->vonMises(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:vonMises",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_vonMises'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_getSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_getSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_getSeed'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getSeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:getSeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_getSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_triangular(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_triangular'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:triangular");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:triangular");

            if (!ok) { break; }
            double ret = cobj->triangular(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            double ret = cobj->triangular();
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:triangular");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:triangular");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.XRandom:triangular");

            if (!ok) { break; }
            double ret = cobj->triangular(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.XRandom:triangular",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_triangular'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_randInt(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_randInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.XRandom:randInt");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.XRandom:randInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_randInt'", nullptr);
            return 0;
        }
        int ret = cobj->randInt(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:randInt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_randInt'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_weibull(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_weibull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:weibull");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:weibull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_weibull'", nullptr);
            return 0;
        }
        double ret = cobj->weibull(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:weibull",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_weibull'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_normal(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_normal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:normal");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:normal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_normal'", nullptr);
            return 0;
        }
        double ret = cobj->normal(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:normal",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_normal'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_below(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_below'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, "lstg.XRandom:below");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_below'", nullptr);
            return 0;
        }
		lua_pushnumber(tolua_S, cobj->below(arg0));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:below",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_below'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_gauss(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_gauss'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:gauss");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:gauss");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_gauss'", nullptr);
            return 0;
        }
        double ret = cobj->gauss(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:gauss",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_gauss'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_uniform(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_uniform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:uniform");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:uniform");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_uniform'", nullptr);
            return 0;
        }
        double ret = cobj->uniform(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:uniform",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_uniform'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_setSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_setSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.XRandom:setSeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_setSeed'", nullptr);
            return 0;
        }
        cobj->setSeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:setSeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_setSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_range(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_range'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.XRandom:range");

            if (!ok) { break; }
            long long arg1;
            ok &= luaval_to_long_long(tolua_S, 3,&arg1, "lstg.XRandom:range");

            if (!ok) { break; }
            long long ret = cobj->range(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.XRandom:range");

            if (!ok) { break; }
            long long arg1;
            ok &= luaval_to_long_long(tolua_S, 3,&arg1, "lstg.XRandom:range");

            if (!ok) { break; }
            long long arg2;
            ok &= luaval_to_long_long(tolua_S, 4,&arg2, "lstg.XRandom:range");

            if (!ok) { break; }
            long long ret = cobj->range(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, "lstg.XRandom:range");
            if (!ok) { break; }
            long long ret = cobj->range(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.XRandom:range",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_range'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_beta(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_beta'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:beta");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:beta");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_beta'", nullptr);
            return 0;
        }
        double ret = cobj->beta(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:beta",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_beta'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_expo(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_expo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:expo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_expo'", nullptr);
            return 0;
        }
        double ret = cobj->expo(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:expo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_expo'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_randSign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_randSign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_randSign'", nullptr);
            return 0;
        }
        int ret = cobj->randSign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:randSign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_randSign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_pareto(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_pareto'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:pareto");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_pareto'", nullptr);
            return 0;
        }
        double ret = cobj->pareto(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:pareto",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_pareto'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_gamma(lua_State* tolua_S)
{
    int argc = 0;
    lstg::XRandom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::XRandom*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_XRandom_gamma'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.XRandom:gamma");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.XRandom:gamma");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_XRandom_gamma'", nullptr);
            return 0;
        }
        double ret = cobj->gamma(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.XRandom:gamma",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_gamma'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_XRandom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.XRandom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.XRandom:create");
            if (!ok) { break; }
            lstg::XRandom* ret = lstg::XRandom::create(arg0);
            object_to_luaval<lstg::XRandom>(tolua_S, "lstg.XRandom",(lstg::XRandom*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            lstg::XRandom* ret = lstg::XRandom::create();
            object_to_luaval<lstg::XRandom>(tolua_S, "lstg.XRandom",(lstg::XRandom*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "lstg.XRandom:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_XRandom_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Random_XRandom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (XRandom)");
    return 0;
}

int lua_register_x_Random_XRandom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.XRandom");
    tolua_cclass(tolua_S,"XRandom","lstg.XRandom","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"XRandom");
        tolua_function(tolua_S,"randFloat",lua_x_Random_XRandom_randFloat);
        tolua_function(tolua_S,"log_norml",lua_x_Random_XRandom_log_norml);
        tolua_function(tolua_S,"vonMises",lua_x_Random_XRandom_vonMises);
        tolua_function(tolua_S,"getSeed",lua_x_Random_XRandom_getSeed);
        tolua_function(tolua_S,"triangular",lua_x_Random_XRandom_triangular);
        tolua_function(tolua_S,"randInt",lua_x_Random_XRandom_randInt);
        tolua_function(tolua_S,"weibull",lua_x_Random_XRandom_weibull);
        tolua_function(tolua_S,"normal",lua_x_Random_XRandom_normal);
        tolua_function(tolua_S,"below",lua_x_Random_XRandom_below);
        tolua_function(tolua_S,"gauss",lua_x_Random_XRandom_gauss);
        tolua_function(tolua_S,"uniform",lua_x_Random_XRandom_uniform);
        tolua_function(tolua_S,"setSeed",lua_x_Random_XRandom_setSeed);
        tolua_function(tolua_S,"range",lua_x_Random_XRandom_range);
        tolua_function(tolua_S,"beta",lua_x_Random_XRandom_beta);
        tolua_function(tolua_S,"expo",lua_x_Random_XRandom_expo);
        tolua_function(tolua_S,"randSign",lua_x_Random_XRandom_randSign);
        tolua_function(tolua_S,"pareto",lua_x_Random_XRandom_pareto);
        tolua_function(tolua_S,"gamma",lua_x_Random_XRandom_gamma);
        tolua_function(tolua_S,"create", lua_x_Random_XRandom_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::XRandom).name();
    g_luaType[typeName] = "lstg.XRandom";
    g_typeCast["XRandom"] = "lstg.XRandom";
    return 1;
}
TOLUA_API int register_all_x_Random(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Random_XRandom(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

