#include "lua_WindowHelper_auto.hpp"
#include "../Classes/WindowHelper.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;

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

int lua_x_WindowHelper_WindowHelper_getClipboardString(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:getClipboardString";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getClipboardString();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelper_getGamma(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:getGamma";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getGamma();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelper_getInstance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:getInstance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::WindowHelper::getInstance();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelper_hint(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:hint";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hint(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_WindowHelper_WindowHelper_isVsync(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:isVsync";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isVsync();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelper_operate(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:operate";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::WindowHelper::Operation arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->operate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelper_resetHint(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:resetHint";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->resetHint();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelper_setClipboardString(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:setClipboardString";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setClipboardString(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelper_setGamma(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:setGamma";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setGamma(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelper_setVsync(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelper";
	constexpr auto LUA_FNAME = "lstg.WindowHelper:setVsync";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelper*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVsync(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_WindowHelper_WindowHelper_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_WindowHelper_WindowHelper(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.WindowHelper");
	tolua_cclass(tolua_S, "WindowHelper", "lstg.WindowHelper", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "WindowHelper");
		tolua_function(tolua_S, "getClipboardString", lua_x_WindowHelper_WindowHelper_getClipboardString);
		tolua_function(tolua_S, "getGamma", lua_x_WindowHelper_WindowHelper_getGamma);
		tolua_function(tolua_S, "hint", lua_x_WindowHelper_WindowHelper_hint);
		tolua_function(tolua_S, "isVsync", lua_x_WindowHelper_WindowHelper_isVsync);
		tolua_function(tolua_S, "operate", lua_x_WindowHelper_WindowHelper_operate);
		tolua_function(tolua_S, "resetHint", lua_x_WindowHelper_WindowHelper_resetHint);
		tolua_function(tolua_S, "setClipboardString", lua_x_WindowHelper_WindowHelper_setClipboardString);
		tolua_function(tolua_S, "setGamma", lua_x_WindowHelper_WindowHelper_setGamma);
		tolua_function(tolua_S, "setVsync", lua_x_WindowHelper_WindowHelper_setVsync);
		tolua_function(tolua_S, "getInstance", lua_x_WindowHelper_WindowHelper_getInstance);
		{
			tolua_module(tolua_S, "Operation", 0);
			tolua_beginmodule(tolua_S, "Operation");
			{
				tolua_constant(tolua_S, "SHOW", (lua_Number)lstg::WindowHelper::Operation::SHOW);
				tolua_constant(tolua_S, "HIDE", (lua_Number)lstg::WindowHelper::Operation::HIDE);
				tolua_constant(tolua_S, "FOCUS", (lua_Number)lstg::WindowHelper::Operation::FOCUS);
				tolua_constant(tolua_S, "ICONIFY", (lua_Number)lstg::WindowHelper::Operation::ICONIFY);
				tolua_constant(tolua_S, "RESTORE", (lua_Number)lstg::WindowHelper::Operation::RESTORE);
				tolua_constant(tolua_S, "MAXIMIZE", (lua_Number)lstg::WindowHelper::Operation::MAXIMIZE);
			}
			tolua_endmodule(tolua_S);
		}
		{
			tolua_module(tolua_S, "CursorType", 0);
			tolua_beginmodule(tolua_S, "CursorType");
			{
				tolua_constant(tolua_S, "ARROW", (lua_Number)lstg::WindowHelper::CursorType::ARROW);
				tolua_constant(tolua_S, "IBEAM", (lua_Number)lstg::WindowHelper::CursorType::IBEAM);
				tolua_constant(tolua_S, "CROSSHAIR", (lua_Number)lstg::WindowHelper::CursorType::CROSSHAIR);
				tolua_constant(tolua_S, "HAND", (lua_Number)lstg::WindowHelper::CursorType::HAND);
				tolua_constant(tolua_S, "HRESIZE", (lua_Number)lstg::WindowHelper::CursorType::HRESIZE);
				tolua_constant(tolua_S, "VRESIZE", (lua_Number)lstg::WindowHelper::CursorType::VRESIZE);
				tolua_constant(tolua_S, "CUSTOM", (lua_Number)lstg::WindowHelper::CursorType::CUSTOM);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::WindowHelper).name();
	g_luaType[typeName] = "lstg.WindowHelper";
	g_typeCast["WindowHelper"] = "lstg.WindowHelper";
	return 1;
}

#ifdef CC_PLATFORM_PC
int lua_x_WindowHelper_WindowHelperDesktop_getInstance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:getInstance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::WindowHelperDesktop::getInstance();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_getPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:getPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPosition();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_getSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:getSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_getTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:getTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:isCursorVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isCursorVisible();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_isFullscreen(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:isFullscreen";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFullscreen();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_isVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:isVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isVisible();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_moveToCenter(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:moveToCenter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->moveToCenter();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setCursorVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setCursorVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setCustomCursor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Vec2 arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_vec2(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setCustomCursor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setDefaultCursor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDefaultCursor();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_setFullscreen(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setFullscreen";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFullscreen();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_WindowHelper_WindowHelperDesktop_setPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelperDesktop_setSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= luaval_to_size(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setStandardCursor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::WindowHelper::CursorType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setStandardCursor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelperDesktop_setTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_WindowHelper_WindowHelperDesktop_setVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.WindowHelperDesktop";
	constexpr auto LUA_FNAME = "lstg.WindowHelperDesktop:setVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::WindowHelperDesktop*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_WindowHelper_WindowHelperDesktop_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_WindowHelper_WindowHelperDesktop(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.WindowHelperDesktop");
	tolua_cclass(tolua_S, "WindowHelperDesktop", "lstg.WindowHelperDesktop", "lstg.WindowHelper", nullptr);

	tolua_beginmodule(tolua_S, "WindowHelperDesktop");
		tolua_function(tolua_S, "getPosition", lua_x_WindowHelper_WindowHelperDesktop_getPosition);
		tolua_function(tolua_S, "getSize", lua_x_WindowHelper_WindowHelperDesktop_getSize);
		tolua_function(tolua_S, "getTitle", lua_x_WindowHelper_WindowHelperDesktop_getTitle);
		tolua_function(tolua_S, "isCursorVisible", lua_x_WindowHelper_WindowHelperDesktop_isCursorVisible);
		tolua_function(tolua_S, "isFullscreen", lua_x_WindowHelper_WindowHelperDesktop_isFullscreen);
		tolua_function(tolua_S, "isVisible", lua_x_WindowHelper_WindowHelperDesktop_isVisible);
		tolua_function(tolua_S, "moveToCenter", lua_x_WindowHelper_WindowHelperDesktop_moveToCenter);
		tolua_function(tolua_S, "setCursorVisible", lua_x_WindowHelper_WindowHelperDesktop_setCursorVisible);
		tolua_function(tolua_S, "setCustomCursor", lua_x_WindowHelper_WindowHelperDesktop_setCustomCursor);
		tolua_function(tolua_S, "setDefaultCursor", lua_x_WindowHelper_WindowHelperDesktop_setDefaultCursor);
		tolua_function(tolua_S, "setFullscreen", lua_x_WindowHelper_WindowHelperDesktop_setFullscreen);
		tolua_function(tolua_S, "setPosition", lua_x_WindowHelper_WindowHelperDesktop_setPosition);
		tolua_function(tolua_S, "setSize", lua_x_WindowHelper_WindowHelperDesktop_setSize);
		tolua_function(tolua_S, "setStandardCursor", lua_x_WindowHelper_WindowHelperDesktop_setStandardCursor);
		tolua_function(tolua_S, "setTitle", lua_x_WindowHelper_WindowHelperDesktop_setTitle);
		tolua_function(tolua_S, "setVisible", lua_x_WindowHelper_WindowHelperDesktop_setVisible);
		tolua_function(tolua_S, "getInstance", lua_x_WindowHelper_WindowHelperDesktop_getInstance);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::WindowHelperDesktop).name();
	g_luaType[typeName] = "lstg.WindowHelperDesktop";
	g_typeCast["WindowHelperDesktop"] = "lstg.WindowHelperDesktop";
	return 1;
}
#endif

int register_all_x_WindowHelper(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_WindowHelper_WindowHelper(tolua_S);
#ifdef CC_PLATFORM_PC
	lua_register_x_WindowHelper_WindowHelperDesktop(tolua_S);
#endif

	tolua_endmodule(tolua_S);
	return 1;
}

