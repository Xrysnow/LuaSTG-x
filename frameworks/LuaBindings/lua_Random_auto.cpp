#include "lua_Random_auto.hpp"
#include "../Classes/XRand.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLua.h"

int lua_x_Random_Random_randFloat(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_randFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:randFloat");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:randFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_randFloat'", nullptr);
            return 0;
        }
        double ret = cobj->randFloat(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:randFloat",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_randFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_log_norml(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_log_norml'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:log_norml");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:log_norml");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_log_norml'", nullptr);
            return 0;
        }
        double ret = cobj->log_norml(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:log_norml",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_log_norml'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_vonMises(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_vonMises'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:vonMises");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:vonMises");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_vonMises'", nullptr);
            return 0;
        }
        double ret = cobj->vonMises(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:vonMises",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_vonMises'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_getSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_getSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_getSeed'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getSeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:getSeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_getSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_triangular(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_triangular'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:triangular");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:triangular");

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
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:triangular");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:triangular");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.Random:triangular");

            if (!ok) { break; }
            double ret = cobj->triangular(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.Random:triangular",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_triangular'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_randInt(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_randInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.Random:randInt");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.Random:randInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_randInt'", nullptr);
            return 0;
        }
        int ret = cobj->randInt(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:randInt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_randInt'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_weibull(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_weibull'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:weibull");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:weibull");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_weibull'", nullptr);
            return 0;
        }
        double ret = cobj->weibull(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:weibull",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_weibull'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_normal(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_normal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:normal");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:normal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_normal'", nullptr);
            return 0;
        }
        double ret = cobj->normal(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:normal",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_normal'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_below(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_below'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned long long arg0;

        ok &= lstg::lua::luaval_to_unsigned_long_long(tolua_S, 2,&arg0, "lstg.Random:below");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_below'", nullptr);
            return 0;
        }
        unsigned long long ret = cobj->below(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:below",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_below'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_gauss(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_gauss'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:gauss");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:gauss");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_gauss'", nullptr);
            return 0;
        }
        double ret = cobj->gauss(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:gauss",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_gauss'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_uniform(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_uniform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:uniform");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:uniform");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_uniform'", nullptr);
            return 0;
        }
        double ret = cobj->uniform(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:uniform",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_uniform'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_setSeed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_setSeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Random:setSeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_setSeed'", nullptr);
            return 0;
        }
        cobj->setSeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:setSeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_setSeed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_range(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_range'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            long long arg0;
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.Random:range");

            if (!ok) { break; }
            long long arg1;
            ok &= luaval_to_long_long(tolua_S, 3,&arg1, "lstg.Random:range");

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
            ok &= luaval_to_long_long(tolua_S, 2,&arg0, "lstg.Random:range");

            if (!ok) { break; }
            long long arg1;
            ok &= luaval_to_long_long(tolua_S, 3,&arg1, "lstg.Random:range");

            if (!ok) { break; }
            long long arg2;
            ok &= luaval_to_long_long(tolua_S, 4,&arg2, "lstg.Random:range");

            if (!ok) { break; }
            long long ret = cobj->range(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned long long arg0;
            ok &= lstg::lua::luaval_to_unsigned_long_long(tolua_S, 2,&arg0, "lstg.Random:range");

            if (!ok) { break; }
            long long ret = cobj->range(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.Random:range",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_range'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_beta(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_beta'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:beta");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:beta");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_beta'", nullptr);
            return 0;
        }
        double ret = cobj->beta(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:beta",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_beta'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_expo(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_expo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:expo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_expo'", nullptr);
            return 0;
        }
        double ret = cobj->expo(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:expo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_expo'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_randSign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_randSign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_randSign'", nullptr);
            return 0;
        }
        int ret = cobj->randSign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:randSign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_randSign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_pareto(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_pareto'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:pareto");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_pareto'", nullptr);
            return 0;
        }
        double ret = cobj->pareto(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:pareto",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_pareto'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_gamma(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Random* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Random*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Random_Random_gamma'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.Random:gamma");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.Random:gamma");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Random_Random_gamma'", nullptr);
            return 0;
        }
        double ret = cobj->gamma(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Random:gamma",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_gamma'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Random_Random_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.Random",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.Random:create");
            if (!ok) { break; }
            lstg::Random* ret = lstg::Random::create(arg0);
            object_to_luaval<lstg::Random>(tolua_S, "lstg.Random",(lstg::Random*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            lstg::Random* ret = lstg::Random::create();
            object_to_luaval<lstg::Random>(tolua_S, "lstg.Random",(lstg::Random*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "lstg.Random:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Random_Random_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Random_Random_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Random)");
    return 0;
}

int lua_register_x_Random_Random(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.Random");
    tolua_cclass(tolua_S,"Random","lstg.Random","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Random");
        tolua_function(tolua_S,"randFloat",lua_x_Random_Random_randFloat);
        tolua_function(tolua_S,"log_norml",lua_x_Random_Random_log_norml);
        tolua_function(tolua_S,"vonMises",lua_x_Random_Random_vonMises);
        tolua_function(tolua_S,"getSeed",lua_x_Random_Random_getSeed);
        tolua_function(tolua_S,"triangular",lua_x_Random_Random_triangular);
        tolua_function(tolua_S,"randInt",lua_x_Random_Random_randInt);
        tolua_function(tolua_S,"weibull",lua_x_Random_Random_weibull);
        tolua_function(tolua_S,"normal",lua_x_Random_Random_normal);
        tolua_function(tolua_S,"below",lua_x_Random_Random_below);
        tolua_function(tolua_S,"gauss",lua_x_Random_Random_gauss);
        tolua_function(tolua_S,"uniform",lua_x_Random_Random_uniform);
        tolua_function(tolua_S,"setSeed",lua_x_Random_Random_setSeed);
        tolua_function(tolua_S,"range",lua_x_Random_Random_range);
        tolua_function(tolua_S,"beta",lua_x_Random_Random_beta);
        tolua_function(tolua_S,"expo",lua_x_Random_Random_expo);
        tolua_function(tolua_S,"randSign",lua_x_Random_Random_randSign);
        tolua_function(tolua_S,"pareto",lua_x_Random_Random_pareto);
        tolua_function(tolua_S,"gamma",lua_x_Random_Random_gamma);
        tolua_function(tolua_S,"create", lua_x_Random_Random_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::Random).name();
    g_luaType[typeName] = "lstg.Random";
    g_typeCast["Random"] = "lstg.Random";
    return 1;
}
TOLUA_API int register_all_x_Random(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Random_Random(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

