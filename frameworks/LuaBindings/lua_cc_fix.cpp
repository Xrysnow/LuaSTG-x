#include "lua_cc_fix.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
//#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "Util/UtilLuaConversion.h"
#include "lua_conversion/lua_conversion.hpp"
using ::lua::luaval_to_native;
using ::lua::native_to_luaval;

#ifndef LUA_CHECK_COBJ_TYPE
#ifdef LUA_DEBUG
#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) if(!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
#else
#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) (void)(TYPE);
#endif
#endif
#ifndef LUA_CHECK_COBJ
#ifdef LUA_DEBUG
#define LUA_CHECK_COBJ(L, COBJ, NAME) if(!(COBJ)) { return luaL_error((L), "invalid 'cobj' in '%s'", NAME); }
#else
#define LUA_CHECK_COBJ(L, COBJ, NAME)
#endif
#endif
#ifndef LUA_CHECK_PARAMETER
#define LUA_CHECK_PARAMETER(L, OK, NAME) if(!(OK)) { return luaL_error((L), "invalid arguments in '%s'", NAME); }
#endif
#ifndef LUA_PARAMETER_ERROR
#define LUA_PARAMETER_ERROR(L, NAME, ARGC, EXPECT) return luaL_error((L), "wrong number of arguments in '%s': %d, expects %s", NAME, (ARGC), EXPECT);
#endif

int lua_cocos2dx_ui_Widget_hitTest00(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "ccui.Widget";
	constexpr auto LUA_FNAME = "ccui.Widget:hitTest";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::ui::Widget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3 || argc == 2)
	{
		cocos2d::Vec2 arg0;
		const cocos2d::Camera* arg1;
		cocos2d::Vec3 arg2;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_object<const cocos2d::Camera>(tolua_S, 3, "cc.Camera", &arg1, LUA_FNAME);
		if (argc == 3)
		{
			ok &= lua_istable(tolua_S, 4);
		}
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
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
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2,3");
}

int register_all_cocos2dx_fix(lua_State* L)
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

