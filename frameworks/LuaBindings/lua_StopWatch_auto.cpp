#include "lua_StopWatch_auto.hpp"
#include "../Classes/XStopWatch.h"
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

int lua_x_StopWatch_StopWatch_get(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StopWatch";
	constexpr auto LUA_FNAME = "lstg.StopWatch:get";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->get();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_StopWatch_StopWatch_pause(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StopWatch";
	constexpr auto LUA_FNAME = "lstg.StopWatch:pause";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->pause();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_StopWatch_StopWatch_reset(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StopWatch";
	constexpr auto LUA_FNAME = "lstg.StopWatch:reset";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_StopWatch_StopWatch_resume(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StopWatch";
	constexpr auto LUA_FNAME = "lstg.StopWatch:resume";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->resume();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_StopWatch_StopWatch_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StopWatch";
	constexpr auto LUA_FNAME = "lstg.StopWatch constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new lstg::StopWatch();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_x_StopWatch_StopWatch_finalize(lua_State* tolua_S)
{
#ifdef LUA_DEBUG
	printf("luabindings: finalizing LUA object (StopWatch)");
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "StopWatch", 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S, 2, &tolua_err)
	) {
		tolua_error(tolua_S, "#ferror in function 'delete'", &tolua_err);
		return 0;
	}
	else
#endif
	{
		auto* self = (lstg::StopWatch*)tolua_tousertype(tolua_S, 1, 0);
#ifdef LUA_DEBUG
		if (!self) tolua_error(tolua_S, "invalid 'self' in function 'delete'", nullptr);
#endif
		delete self;
	}
	return 0;
}

int lua_register_x_StopWatch_StopWatch(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.StopWatch");
	tolua_cclass(tolua_S, "StopWatch", "lstg.StopWatch", "", lua_x_StopWatch_StopWatch_finalize);

	tolua_beginmodule(tolua_S, "StopWatch");
		tolua_function(tolua_S, "new", lua_x_StopWatch_StopWatch_constructor);
		tolua_function(tolua_S, "get", lua_x_StopWatch_StopWatch_get);
		tolua_function(tolua_S, "pause", lua_x_StopWatch_StopWatch_pause);
		tolua_function(tolua_S, "reset", lua_x_StopWatch_StopWatch_reset);
		tolua_function(tolua_S, "resume", lua_x_StopWatch_StopWatch_resume);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::StopWatch).name();
	g_luaType[typeName] = "lstg.StopWatch";
	g_typeCast["StopWatch"] = "lstg.StopWatch";
	return 1;
}

int register_all_x_StopWatch(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_StopWatch_StopWatch(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

