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

int lua_cocos2dx_EventDispatcher_addCustomEventListener00(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.EventDispatcher";
	constexpr auto LUA_FNAME = "cc.EventDispatcher:addCustomEventListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::EventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;
		std::function<void(cocos2d::EventCustom *)> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 3, 0);
		ok &= handler != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		arg1 = [=](cocos2d::EventCustom *)
		{
			LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 0);
		};
		auto ret = cobj->addCustomEventListener(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
#ifdef CC_VERSION
extern int lua_ax_base_GLViewImpl_createWithRect(lua_State* tolua_S);
extern int lua_ax_base_GLViewImpl_create(lua_State* tolua_S);
#define lua_cocos2dx_GLViewImpl_createWithRect lua_ax_base_GLViewImpl_createWithRect
#define lua_cocos2dx_GLViewImpl_create lua_ax_base_GLViewImpl_create
#else
extern int lua_cocos2dx_GLViewImpl_createWithRect(lua_State* tolua_S);
extern int lua_cocos2dx_GLViewImpl_create(lua_State* tolua_S);
#endif // CC_VERSION
int lua_cocos2dx_GLViewImpl_createWithRect00(lua_State* tolua_S)
{
#ifdef CC_PLATFORM_PC
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.GLViewImpl";
	constexpr auto LUA_FNAME = "cc.GLViewImpl:createWithRect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4)
	{
		std::string arg0;
		cocos2d::Rect arg1;
		double arg2;
		bool arg3;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_rect(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cocos2d::GLViewImpl::createWithRect(arg0, arg1, arg2, arg3);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
#endif
	return lua_cocos2dx_GLViewImpl_createWithRect(tolua_S);
}
int lua_cocos2dx_GLViewImpl_create00(lua_State* tolua_S)
{
#ifdef CC_PLATFORM_PC
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.GLViewImpl";
	constexpr auto LUA_FNAME = "cc.GLViewImpl:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cocos2d::GLViewImpl::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
#endif
	return lua_cocos2dx_GLViewImpl_create(tolua_S);
}

#ifdef CC_VERSION
int lua_cc_FileUtils_getSuitableFOpen(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.FileUtils", "cc.FileUtils:getSuitableFOpen");
	LUA_TRY_INVOKE_R(1, &cocos2d::FileUtils::getSuitableFOpen);
	LUA_INVOKE_FOOTER("1");
}
#endif

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

	lua_pushstring(L, "cc.EventDispatcher");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "addCustomEventListener", lua_cocos2dx_EventDispatcher_addCustomEventListener00);
	}
	lua_pop(L, 1);

	lua_pushstring(L, "cc.GLViewImpl");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "createWithRect", lua_cocos2dx_GLViewImpl_createWithRect00);
		tolua_function(L, "create", lua_cocos2dx_GLViewImpl_create00);
	}
	lua_pop(L, 1);

#ifdef CC_VERSION
	lua_pushstring(L, "cc.FileUtils");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "getSuitableFOpen", lua_cc_FileUtils_getSuitableFOpen);
	}
	lua_pop(L, 1);
#endif

	return 0;
}

