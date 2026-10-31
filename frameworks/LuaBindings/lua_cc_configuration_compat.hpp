#pragma once
#include "lua_conversion/lua_conversion.hpp"
#include "lua_cc_configuration_manual.hpp"

// Configuration's legacy bindings check arguments even in Release. Keep these
// overrides local to its translation units; other modules retain their policies.
#ifdef LUA_DEBUG
#define CONFIGURATION_CHECK_TYPE(L, TYPE, NAME) \
	if (!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) \
		return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", \
			(NAME), tolua_typename((L), 1), (TYPE));
#define CONFIGURATION_CHECK_OBJECT(L, OBJECT, NAME) \
	if (!(OBJECT)) return luaL_error((L), "invalid 'cobj' in '%s'", (NAME));
#else
#define CONFIGURATION_CHECK_TYPE(L, TYPE, NAME) (void)(TYPE);
#define CONFIGURATION_CHECK_OBJECT(L, OBJECT, NAME) (void)(OBJECT);
#endif

#undef LUA_INVOKE_HEADER
#define LUA_INVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	CONFIGURATION_CHECK_TYPE(lua_S, LUA_OBJ_TYPE, LUA_FNAME); \
	const auto* configuration_self = tolua_tousertype(lua_S, 1, nullptr); \
	CONFIGURATION_CHECK_OBJECT(lua_S, configuration_self, LUA_FNAME); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = true; \
	int arg_cur = -1; \
	bool ok = false;

// Reading the receiver above also preserves tolua's replacement of a table's
// .c_instance slot: legacy void methods return the underlying userdata.
#undef LUA_SINVOKE_HEADER
#define LUA_SINVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	CONFIGURATION_CHECK_TYPE(lua_S, LUA_OBJ_TYPE, LUA_FNAME); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = false; \
	int arg_cur = -1; \
	bool ok = false;

#undef LUA_TRY_INVOKE
#define LUA_TRY_INVOKE(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		int native_results = 0; \
		ok = lua::_invoke_native<true, true, false, binding_member_self>( \
			lua_S, arg_cur, (Fn_), &native_results); \
		if (ok) { lua_settop(lua_S, 1); return 1; } \
	}

#undef LUA_TRY_INVOKE_R
#define LUA_TRY_INVOKE_R(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		int native_results = 0; \
		ok = lua::_invoke_native<true, true, false, binding_member_self>( \
			lua_S, arg_cur, (Fn_), &native_results); \
		if (ok) return native_results; \
	}

#undef LUA_INVOKE_FOOTER
#define LUA_INVOKE_FOOTER(Expected_) \
	if (arg_cur != -1) return luaL_error(lua_S, "invalid arguments in '%s'", LUA_FNAME); \
	return luaL_error(lua_S, "wrong number of arguments in '%s': %d, expects %s", \
		LUA_FNAME, argc, Expected_);

#undef LUA_SINVOKE_FOOTER
#define LUA_SINVOKE_FOOTER(Expected_) LUA_INVOKE_FOOTER(Expected_)
