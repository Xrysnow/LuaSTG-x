#include "lua_Latex_auto.hpp"
#include "../Classes/XLatex.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"

int lua_x_Latex_Latex_getDepth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getDepth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getDepth'", nullptr);
            return 0;
        }
        double ret = cobj->getDepth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getDepth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getDepth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_getBaseline(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getBaseline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getBaseline'", nullptr);
            return 0;
        }
        double ret = cobj->getBaseline();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getBaseline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getBaseline'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_getHeight(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getHeight'", nullptr);
            return 0;
        }
        double ret = cobj->getHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_getWidth(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getWidth'", nullptr);
            return 0;
        }
        double ret = cobj->getWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_getTextSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getTextSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getTextSize'", nullptr);
            return 0;
        }
        double ret = cobj->getTextSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getTextSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getTextSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_getInsets(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Latex* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Latex*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Latex_Latex_getInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_getInsets'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getInsets();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Latex:getInsets",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_getInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Latex_Latex_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        double arg2;
        double arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.Latex:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.Latex:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.Latex:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.Latex:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_create'", nullptr);
            return 0;
        }
        lstg::Latex* ret = lstg::Latex::create(arg0, arg1, arg2, arg3);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 5)
    {
        std::string arg0;
        int arg1;
        double arg2;
        double arg3;
        cocos2d::Color4B arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.Latex:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.Latex:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.Latex:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.Latex:create");
        ok &=luaval_to_color4b(tolua_S, 6, &arg4, "lstg.Latex:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_create'", nullptr);
            return 0;
        }
        lstg::Latex* ret = lstg::Latex::create(arg0, arg1, arg2, arg3, arg4);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.Latex:create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Latex_Latex_setDebug(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.Latex",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.Latex:setDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Latex_Latex_setDebug'", nullptr);
            return 0;
        }
        lstg::Latex::setDebug(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.Latex:setDebug",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Latex_Latex_setDebug'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Latex_Latex_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Latex)");
    return 0;
}

int lua_register_x_Latex_Latex(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.Latex");
    tolua_cclass(tolua_S,"Latex","lstg.Latex","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"Latex");
        tolua_function(tolua_S,"getDepth",lua_x_Latex_Latex_getDepth);
        tolua_function(tolua_S,"getBaseline",lua_x_Latex_Latex_getBaseline);
        tolua_function(tolua_S,"getHeight",lua_x_Latex_Latex_getHeight);
        tolua_function(tolua_S,"getWidth",lua_x_Latex_Latex_getWidth);
        tolua_function(tolua_S,"getTextSize",lua_x_Latex_Latex_getTextSize);
        tolua_function(tolua_S,"getInsets",lua_x_Latex_Latex_getInsets);
        tolua_function(tolua_S,"create", lua_x_Latex_Latex_create);
        tolua_function(tolua_S,"setDebug", lua_x_Latex_Latex_setDebug);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::Latex).name();
    g_luaType[typeName] = "lstg.Latex";
    g_typeCast["Latex"] = "lstg.Latex";
    return 1;
}
TOLUA_API int register_all_x_Latex(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Latex_Latex(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

