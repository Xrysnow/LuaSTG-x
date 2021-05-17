#include "lua_BentLaser_auto.hpp"
#include "Object/GameObjectBentLaser.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b

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

int lua_x_BentLaser_GameObjectBentLaser_boundCheck(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:boundCheck";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->boundCheck();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_clear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:clear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clear();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_collisionCheck(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:collisionCheck";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->collisionCheck(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			lstg::GameObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
			if (!ok) { break; }
			auto ret = cobj->collisionCheck(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:collisionCheckExtendWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->collisionCheckExtendWidth(arg0, arg1, arg2);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			lstg::GameObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->collisionCheckExtendWidth(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_BentLaser_GameObjectBentLaser_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::GameObjectBentLaser::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getColorMixMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getColorMixMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColorMixMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getColorMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getColorMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColorMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getDefaultColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getDefaultColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDefaultColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getDefaultWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDefaultWidth();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getLength(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getLength";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLength();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getLengthLimit(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getLengthLimit";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLengthLimit();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodeColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodeColor(arg0);
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodeCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodeCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeLength(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodeLength";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodeLength(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeLimit(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodeLimit";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodeLimit();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodePosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodePosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodePosition(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_getNodeWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getNodeWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNodeWidth(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_getRenderScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:getRenderScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRenderScale();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_popHead(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:popHead";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->popHead(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->popHead();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_popTail(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:popTail";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->popTail(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->popTail();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_pushHead(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:pushHead";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushHead(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushHead(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 4) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Color4B arg3;
			ok &=luaval_to_color4b(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushHead(arg0, arg1, arg2, arg3);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
int lua_x_BentLaser_GameObjectBentLaser_pushTail(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:pushTail";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushTail(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushTail(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 4) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Color4B arg3;
			ok &=luaval_to_color4b(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			cobj->pushTail(arg0, arg1, arg2, arg3);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
int lua_x_BentLaser_GameObjectBentLaser_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 7) {
			lstg::ResTexture* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			lstg::RenderMode* arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Color4B arg2;
			ok &=luaval_to_color4b(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			double arg3;
			ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			double arg4;
			ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
			if (!ok) { break; }
			double arg5;
			ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
			if (!ok) { break; }
			double arg6;
			ok &= luaval_to_number(tolua_S, 8, &arg6, LUA_FNAME);
			if (!ok) { break; }
			cobj->render(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			lstg::ResSprite* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->render(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_reset(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:reset";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->reset();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_BentLaser_GameObjectBentLaser_setAllColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setAllColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAllColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setAllWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setAllWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAllWidth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setColorMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setColorMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::GameObjectBentLaser::ColorMode arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColorMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		lstg::GameObjectBentLaser::ColorMode arg0;
		lstg::GameObjectBentLaser::ColorMixMode arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColorMode(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_x_BentLaser_GameObjectBentLaser_setDefaultColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setDefaultColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDefaultColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setDefaultWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDefaultWidth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setLengthLimit(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setLengthLimit";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLengthLimit(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setNodeColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		cocos2d::Color4B arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &=luaval_to_color4b(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNodeColor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeLimit(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setNodeLimit";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNodeLimit(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_setNodePosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setNodePosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		int arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNodePosition(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_BentLaser_GameObjectBentLaser_setNodeWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setNodeWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		double arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNodeWidth(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_BentLaser_GameObjectBentLaser_setRenderScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:setRenderScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRenderScale(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.GameObjectBentLaser";
	constexpr auto LUA_FNAME = "lstg.GameObjectBentLaser:strictCollisionCheck";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::GameObjectBentLaser*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->strictCollisionCheck(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			lstg::GameObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
			if (!ok) { break; }
			auto ret = cobj->strictCollisionCheck(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_BentLaser_GameObjectBentLaser_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_BentLaser_GameObjectBentLaser(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.GameObjectBentLaser");
	tolua_cclass(tolua_S, "GameObjectBentLaser", "lstg.GameObjectBentLaser", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "GameObjectBentLaser");
		tolua_function(tolua_S, "boundCheck", lua_x_BentLaser_GameObjectBentLaser_boundCheck);
		tolua_function(tolua_S, "clear", lua_x_BentLaser_GameObjectBentLaser_clear);
		tolua_function(tolua_S, "collisionCheck", lua_x_BentLaser_GameObjectBentLaser_collisionCheck);
		tolua_function(tolua_S, "collisionCheckExtendWidth", lua_x_BentLaser_GameObjectBentLaser_collisionCheckExtendWidth);
		tolua_function(tolua_S, "getColorMixMode", lua_x_BentLaser_GameObjectBentLaser_getColorMixMode);
		tolua_function(tolua_S, "getColorMode", lua_x_BentLaser_GameObjectBentLaser_getColorMode);
		tolua_function(tolua_S, "getDefaultColor", lua_x_BentLaser_GameObjectBentLaser_getDefaultColor);
		tolua_function(tolua_S, "getDefaultWidth", lua_x_BentLaser_GameObjectBentLaser_getDefaultWidth);
		tolua_function(tolua_S, "getLength", lua_x_BentLaser_GameObjectBentLaser_getLength);
		tolua_function(tolua_S, "getLengthLimit", lua_x_BentLaser_GameObjectBentLaser_getLengthLimit);
		tolua_function(tolua_S, "getNodeColor", lua_x_BentLaser_GameObjectBentLaser_getNodeColor);
		tolua_function(tolua_S, "getNodeCount", lua_x_BentLaser_GameObjectBentLaser_getNodeCount);
		tolua_function(tolua_S, "getNodeLength", lua_x_BentLaser_GameObjectBentLaser_getNodeLength);
		tolua_function(tolua_S, "getNodeLimit", lua_x_BentLaser_GameObjectBentLaser_getNodeLimit);
		tolua_function(tolua_S, "getNodePosition", lua_x_BentLaser_GameObjectBentLaser_getNodePosition);
		tolua_function(tolua_S, "getNodeWidth", lua_x_BentLaser_GameObjectBentLaser_getNodeWidth);
		tolua_function(tolua_S, "getRenderScale", lua_x_BentLaser_GameObjectBentLaser_getRenderScale);
		tolua_function(tolua_S, "popHead", lua_x_BentLaser_GameObjectBentLaser_popHead);
		tolua_function(tolua_S, "popTail", lua_x_BentLaser_GameObjectBentLaser_popTail);
		tolua_function(tolua_S, "pushHead", lua_x_BentLaser_GameObjectBentLaser_pushHead);
		tolua_function(tolua_S, "pushTail", lua_x_BentLaser_GameObjectBentLaser_pushTail);
		tolua_function(tolua_S, "render", lua_x_BentLaser_GameObjectBentLaser_render);
		tolua_function(tolua_S, "reset", lua_x_BentLaser_GameObjectBentLaser_reset);
		tolua_function(tolua_S, "setAllColor", lua_x_BentLaser_GameObjectBentLaser_setAllColor);
		tolua_function(tolua_S, "setAllWidth", lua_x_BentLaser_GameObjectBentLaser_setAllWidth);
		tolua_function(tolua_S, "setColorMode", lua_x_BentLaser_GameObjectBentLaser_setColorMode);
		tolua_function(tolua_S, "setDefaultColor", lua_x_BentLaser_GameObjectBentLaser_setDefaultColor);
		tolua_function(tolua_S, "setDefaultWidth", lua_x_BentLaser_GameObjectBentLaser_setDefaultWidth);
		tolua_function(tolua_S, "setLengthLimit", lua_x_BentLaser_GameObjectBentLaser_setLengthLimit);
		tolua_function(tolua_S, "setNodeColor", lua_x_BentLaser_GameObjectBentLaser_setNodeColor);
		tolua_function(tolua_S, "setNodeLimit", lua_x_BentLaser_GameObjectBentLaser_setNodeLimit);
		tolua_function(tolua_S, "setNodePosition", lua_x_BentLaser_GameObjectBentLaser_setNodePosition);
		tolua_function(tolua_S, "setNodeWidth", lua_x_BentLaser_GameObjectBentLaser_setNodeWidth);
		tolua_function(tolua_S, "setRenderScale", lua_x_BentLaser_GameObjectBentLaser_setRenderScale);
		tolua_function(tolua_S, "strictCollisionCheck", lua_x_BentLaser_GameObjectBentLaser_strictCollisionCheck);
		tolua_function(tolua_S, "create", lua_x_BentLaser_GameObjectBentLaser_create);
		{
			tolua_module(tolua_S, "ColorMode", 0);
			tolua_beginmodule(tolua_S, "ColorMode");
			{
				tolua_constant(tolua_S, "Normal", (lua_Number)lstg::GameObjectBentLaser::ColorMode::Normal);
				tolua_constant(tolua_S, "Node", (lua_Number)lstg::GameObjectBentLaser::ColorMode::Node);
				tolua_constant(tolua_S, "NodeSmooth", (lua_Number)lstg::GameObjectBentLaser::ColorMode::NodeSmooth);
				tolua_constant(tolua_S, "ColorModeNum", (lua_Number)lstg::GameObjectBentLaser::ColorMode::ColorModeNum);
			}
			tolua_endmodule(tolua_S);
		}
		{
			tolua_module(tolua_S, "ColorMixMode", 0);
			tolua_beginmodule(tolua_S, "ColorMixMode");
			{
				tolua_constant(tolua_S, "None", (lua_Number)lstg::GameObjectBentLaser::ColorMixMode::None);
				tolua_constant(tolua_S, "Multi", (lua_Number)lstg::GameObjectBentLaser::ColorMixMode::Multi);
				tolua_constant(tolua_S, "Add", (lua_Number)lstg::GameObjectBentLaser::ColorMixMode::Add);
				tolua_constant(tolua_S, "ColorMixModeNum", (lua_Number)lstg::GameObjectBentLaser::ColorMixMode::ColorMixModeNum);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::GameObjectBentLaser).name();
	g_luaType[typeName] = "lstg.GameObjectBentLaser";
	g_typeCast["GameObjectBentLaser"] = "lstg.GameObjectBentLaser";
	return 1;
}

int register_all_x_BentLaser(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_BentLaser_GameObjectBentLaser(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

