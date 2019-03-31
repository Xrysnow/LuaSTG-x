#include "lua_cc_ui_fix.h"

#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "ui/UIWidget.h"

int lua_cocos2dx_ui_Widget_hitTest00(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::ui::Widget* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "ccui.Widget", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::ui::Widget*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_ui_Widget_hitTest'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3 || argc == 2)
	{
		cocos2d::Vec2 arg0;
		const cocos2d::Camera* arg1;
		cocos2d::Vec3 arg2;

		ok &= luaval_to_vec2(tolua_S, 2, &arg0, "ccui.Widget:hitTest");

		ok &= luaval_to_object<const cocos2d::Camera>(tolua_S, 3, "cc.Camera", &arg1, "ccui.Widget:hitTest");

		if (argc == 3)
		{
			ok &= lua_istable(tolua_S, 4);
		}
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_ui_Widget_hitTest'", nullptr);
			return 0;
		}
		bool ret = cobj->hitTest(arg0, arg1, &arg2);
		if (argc == 3)
		{
			lua_pushnumber(tolua_S, arg2.x);
			lua_setfield(tolua_S, 4, "x");
			lua_pushnumber(tolua_S, arg2.y);
			lua_setfield(tolua_S, 4, "y");
			lua_pushnumber(tolua_S, arg2.z);
			lua_setfield(tolua_S, 4, "z");
		}
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d or %d \n", "ccui.Widget:hitTest", argc, 2, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
		tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_ui_Widget_hitTest'.", &tolua_err);
#endif
	return 0;
}

int register_all_cocos2dx_ui_fix(lua_State* L)
{
	if (nullptr == L)
		return 0;

	lua_pushstring(L, "ccui.Widget");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "hitTest", lua_cocos2dx_ui_Widget_hitTest00);
	}
	lua_pop(L, 1);

	return 0;
}

