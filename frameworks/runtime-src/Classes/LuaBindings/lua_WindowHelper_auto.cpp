#include "lua_WindowHelper_auto.hpp"
#include "../Classes/WindowHelper.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_x_WindowHelper_WindowHelper_operate(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_operate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::WindowHelper::Operation arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.WindowHelper:operate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_operate'", nullptr);
            return 0;
        }
        cobj->operate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:operate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_operate'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_getClipboardString(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_getClipboardString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_getClipboardString'", nullptr);
            return 0;
        }
        const char* ret = cobj->getClipboardString().c_str();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:getClipboardString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_getClipboardString'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_setClipboardString(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_setClipboardString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.WindowHelper:setClipboardString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_setClipboardString'", nullptr);
            return 0;
        }
        cobj->setClipboardString(arg0_tmp);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:setClipboardString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_setClipboardString'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_hint(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_hint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.WindowHelper:hint");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.WindowHelper:hint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_hint'", nullptr);
            return 0;
        }
        cobj->hint(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:hint",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_hint'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_isVsync(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_isVsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_isVsync'", nullptr);
            return 0;
        }
        bool ret = cobj->isVsync();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:isVsync",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_isVsync'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_setGamma(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_setGamma'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.WindowHelper:setGamma");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_setGamma'", nullptr);
            return 0;
        }
        cobj->setGamma(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:setGamma",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_setGamma'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_resetHint(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_resetHint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_resetHint'", nullptr);
            return 0;
        }
        cobj->resetHint();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:resetHint",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_resetHint'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_getGamma(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_getGamma'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_getGamma'", nullptr);
            return 0;
        }
        double ret = cobj->getGamma();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:getGamma",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_getGamma'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_setVsync(lua_State* tolua_S)
{
    int argc = 0;
    lstg::WindowHelper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelper_setVsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.WindowHelper:setVsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_setVsync'", nullptr);
            return 0;
        }
        cobj->setVsync(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelper:setVsync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_setVsync'.",&tolua_err);
#endif

    return 0;
}
int lua_x_WindowHelper_WindowHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.WindowHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_WindowHelper_WindowHelper_getInstance'", nullptr);
            return 0;
        }
        lstg::WindowHelper* ret = lstg::WindowHelper::getInstance();
        object_to_luaval<lstg::WindowHelper>(tolua_S, "lstg.WindowHelper",(lstg::WindowHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.WindowHelper:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_WindowHelper_WindowHelper_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_WindowHelper_WindowHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WindowHelper)");
    return 0;
}

int lua_register_x_WindowHelper_WindowHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.WindowHelper");
    tolua_cclass(tolua_S,"WindowHelper","lstg.WindowHelper","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"WindowHelper");
        tolua_function(tolua_S,"operate",lua_x_WindowHelper_WindowHelper_operate);
        tolua_function(tolua_S,"getClipboardString",lua_x_WindowHelper_WindowHelper_getClipboardString);
        tolua_function(tolua_S,"setClipboardString",lua_x_WindowHelper_WindowHelper_setClipboardString);
        tolua_function(tolua_S,"hint",lua_x_WindowHelper_WindowHelper_hint);
        tolua_function(tolua_S,"isVsync",lua_x_WindowHelper_WindowHelper_isVsync);
        tolua_function(tolua_S,"setGamma",lua_x_WindowHelper_WindowHelper_setGamma);
        tolua_function(tolua_S,"resetHint",lua_x_WindowHelper_WindowHelper_resetHint);
        tolua_function(tolua_S,"getGamma",lua_x_WindowHelper_WindowHelper_getGamma);
        tolua_function(tolua_S,"setVsync",lua_x_WindowHelper_WindowHelper_setVsync);
        tolua_function(tolua_S,"getInstance", lua_x_WindowHelper_WindowHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::WindowHelper).name();
    g_luaType[typeName] = "lstg.WindowHelper";
    g_typeCast["WindowHelper"] = "lstg.WindowHelper";
    return 1;
}

#ifdef CC_PLATFORM_PC
int lua_x_WindowHelper_WindowHelperDesktop_moveToCenter(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_moveToCenter'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_moveToCenter'", nullptr);
			return 0;
		}
		cobj->moveToCenter();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:moveToCenter", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_moveToCenter'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		lstg::WindowHelper::CursorType arg0;

		ok &= luaval_to_int32(tolua_S, 2, (int *)&arg0, "lstg.WindowHelperDesktop:setStandardCursor");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor'", nullptr);
			return 0;
		}
		cobj->setStandardCursor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setStandardCursor", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setFullscreen(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setFullscreen'", nullptr);
		return 0;
}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setFullscreen'", nullptr);
			return 0;
		}
		cobj->setFullscreen();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setFullscreen", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setFullscreen'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		bool arg0;

		ok &= luaval_to_boolean(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setCursorVisible");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible'", nullptr);
			return 0;
		}
		cobj->setCursorVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setCursorVisible", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setTitle(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setTitle'", nullptr);
		return 0;
}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setTitle");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setTitle'", nullptr);
			return 0;
		}
		cobj->setTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setTitle", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setTitle'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible'", nullptr);
			return 0;
		}
		bool ret = cobj->isCursorVisible();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:isCursorVisible", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;
		cocos2d::Vec2 arg1;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setCustomCursor");

		ok &= luaval_to_vec2(tolua_S, 3, &arg1, "lstg.WindowHelperDesktop:setCustomCursor");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor'", nullptr);
			return 0;
	}
		cobj->setCustomCursor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setCustomCursor", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_isFullscreen(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_isFullscreen'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_isFullscreen'", nullptr);
			return 0;
		}
		bool ret = cobj->isFullscreen();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
		}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:isFullscreen", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_isFullscreen'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_getSize(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_getSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_getSize'", nullptr);
			return 0;
		}
		cocos2d::Size ret = cobj->getSize();
		size_to_luaval(tolua_S, ret);
		return 1;
		}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:getSize", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_getSize'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setSize(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Size arg0;

		ok &= luaval_to_size(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setSize");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setSize'", nullptr);
			return 0;
	}
		cobj->setSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setSize", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setSize'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_getTitle(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_getTitle'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_getTitle'", nullptr);
			return 0;
		}
		std::string ret = cobj->getTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
		}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:getTitle", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_getTitle'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_isVisible(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_isVisible'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_isVisible'", nullptr);
			return 0;
		}
		bool ret = cobj->isVisible();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:isVisible", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_isVisible'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_setPosition(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setPosition'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Vec2 arg0;

		ok &= luaval_to_vec2(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setPosition");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setPosition'", nullptr);
			return 0;
		}
		cobj->setPosition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
		}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setPosition", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setPosition'.", &tolua_err);
#endif

				return 0;
}
int lua_x_WindowHelper_WindowHelperDesktop_setVisible(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setVisible'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		bool arg0;

		ok &= luaval_to_boolean(tolua_S, 2, &arg0, "lstg.WindowHelperDesktop:setVisible");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setVisible'", nullptr);
			return 0;
	}
		cobj->setVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setVisible", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setVisible'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor'", nullptr);
			return 0;
		}
		cobj->setDefaultCursor();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:setDefaultCursor", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_getPosition(lua_State* tolua_S)
{
	int argc = 0;
	lstg::WindowHelperDesktop* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_x_WindowHelper_WindowHelperDesktop_getPosition'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_getPosition'", nullptr);
			return 0;
		}
		cocos2d::Vec2 ret = cobj->getPosition();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.WindowHelperDesktop:getPosition", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_getPosition'.", &tolua_err);
#endif

				return 0;
	}
int lua_x_WindowHelper_WindowHelperDesktop_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "lstg.WindowHelperDesktop", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_x_WindowHelper_WindowHelperDesktop_getInstance'", nullptr);
			return 0;
		}
		lstg::WindowHelperDesktop* ret = lstg::WindowHelperDesktop::getInstance();
		object_to_luaval<lstg::WindowHelperDesktop>(tolua_S, "lstg.WindowHelperDesktop", (lstg::WindowHelperDesktop*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.WindowHelperDesktop:getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_x_WindowHelper_WindowHelperDesktop_getInstance'.", &tolua_err);
#endif
				return 0;
}
static int lua_x_WindowHelper_WindowHelperDesktop_finalize(lua_State* tolua_S)
{
	printf("luabindings: finalizing LUA object (WindowHelperDesktop)");
	return 0;
}
#else
int lua_x_WindowHelper_WindowHelperDesktop_getInstance(lua_State* tolua_S)
{
	lua_pushnil(tolua_S);
	return 1;
}
#endif

int lua_register_x_WindowHelper_WindowHelperDesktop(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.WindowHelperDesktop");
    tolua_cclass(tolua_S,"WindowHelperDesktop","lstg.WindowHelperDesktop","lstg.WindowHelper",nullptr);

    tolua_beginmodule(tolua_S,"WindowHelperDesktop");
#ifdef CC_PLATFORM_PC
		tolua_function(tolua_S, "moveToCenter", lua_x_WindowHelper_WindowHelperDesktop_moveToCenter);
		tolua_function(tolua_S, "setStandardCursor", lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor);
		tolua_function(tolua_S, "setFullscreen", lua_x_WindowHelper_WindowHelperDesktop_setFullscreen);
		tolua_function(tolua_S, "setCursorVisible", lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible);
		tolua_function(tolua_S, "setTitle", lua_x_WindowHelper_WindowHelperDesktop_setTitle);
		tolua_function(tolua_S, "isCursorVisible", lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible);
		tolua_function(tolua_S, "setCustomCursor", lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor);
		tolua_function(tolua_S, "isFullscreen", lua_x_WindowHelper_WindowHelperDesktop_isFullscreen);
		tolua_function(tolua_S, "getSize", lua_x_WindowHelper_WindowHelperDesktop_getSize);
		tolua_function(tolua_S, "setSize", lua_x_WindowHelper_WindowHelperDesktop_setSize);
		tolua_function(tolua_S, "getTitle", lua_x_WindowHelper_WindowHelperDesktop_getTitle);
		tolua_function(tolua_S, "isVisible", lua_x_WindowHelper_WindowHelperDesktop_isVisible);
		tolua_function(tolua_S, "setPosition", lua_x_WindowHelper_WindowHelperDesktop_setPosition);
		tolua_function(tolua_S, "setVisible", lua_x_WindowHelper_WindowHelperDesktop_setVisible);
		tolua_function(tolua_S, "setDefaultCursor", lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor);
		tolua_function(tolua_S, "getPosition", lua_x_WindowHelper_WindowHelperDesktop_getPosition);
#endif
		tolua_function(tolua_S,"getInstance", lua_x_WindowHelper_WindowHelperDesktop_getInstance);
    tolua_endmodule(tolua_S);
#ifdef CC_PLATFORM_PC
	std::string typeName = typeid(lstg::WindowHelperDesktop).name();
#else
	std::string typeName = "lstg.WindowHelperDesktop";
#endif
	g_luaType[typeName] = "lstg.WindowHelperDesktop";
    g_typeCast["WindowHelperDesktop"] = "lstg.WindowHelperDesktop";
    return 1;
}
TOLUA_API int register_all_x_WindowHelper(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_WindowHelper_WindowHelper(tolua_S);
	lua_register_x_WindowHelper_WindowHelperDesktop(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

