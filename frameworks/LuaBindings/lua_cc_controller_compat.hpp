#pragma once
#include "lua_conversion/lua_conversion.hpp"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include <cstdio>
#include <cstring>

namespace controller_binding
{
// The legacy tolua helpers accept numeric strings and use their historical
// integer cast. Normalize only this module's native arguments before invoking
// the shared checked converter; do not broaden the shared conversion policy.
template<typename Argument>
bool prepare_value(lua_State* L, int index, const char* name)
{
	using T = std::remove_cv_t<std::remove_reference_t<Argument>>;
	if constexpr (std::is_same_v<T, int>) {
		int value;
		if (!luaval_to_int32(L, index, &value, name)) return false;
		lua_pushnumber(L, value); lua_replace(L, index);
	} else if constexpr (std::is_same_v<T, bool>) {
		bool value;
		if (!luaval_to_boolean(L, index, &value, name)) return false;
		lua_pushboolean(L, value); lua_replace(L, index);
	}
	return true;
}

template<typename... Arguments, size_t... Index>
bool prepare_arguments(lua_State* L, const char* name, std::index_sequence<Index...>)
{
	const int first = lua_gettop(L) - static_cast<int>(sizeof...(Arguments)) + 1;
	return (prepare_value<Arguments>(L, first + static_cast<int>(Index), name) && ...);
}

template<typename T> struct prepare_signature;
template<typename R, typename... Arguments>
struct prepare_signature<R(*)(Arguments...)> {
	static bool run(lua_State* L, const char* name) {
		return prepare_arguments<Arguments...>(L, name, std::index_sequence_for<Arguments...>{});
	}
};
template<typename C, typename R, typename... Arguments>
struct prepare_signature<R(C::*)(Arguments...)> : prepare_signature<R(*)(Arguments...)> {};
template<typename C, typename R, typename... Arguments>
struct prepare_signature<R(C::*)(Arguments...) const> : prepare_signature<R(*)(Arguments...)> {};
}

// Keep the old module's argument checks in both build configurations and its
// public diagnostics. These overrides apply only to the generated Controller TU.
inline void controller_legacy_native_name(char* buffer, size_t size, const char* name)
{
	const auto* separator = std::strchr(name, ':');
	std::snprintf(buffer, size, "lua_cocos2dx_controller_%.*s_%s",
		static_cast<int>(separator - name - 3), name + 3, separator + 1);
}

#if CC_DEBUG >= 1
#define CONTROLLER_CHECK_RECEIVER(L, TYPE, NAME, TABLE) \
	tolua_Error controller_receiver_error; \
	if (!((TABLE) ? tolua_isusertable((L), 1, (TYPE), 0, &controller_receiver_error) \
		: tolua_isusertype((L), 1, (TYPE), 0, &controller_receiver_error))) { \
		char controller_native_name[192]; \
		controller_legacy_native_name(controller_native_name, sizeof(controller_native_name), (NAME)); \
		char controller_receiver_message[256]; \
		std::snprintf(controller_receiver_message, sizeof(controller_receiver_message), "#ferror in function '%s'.", controller_native_name); \
		tolua_error((L), controller_receiver_message, &controller_receiver_error); return 0; \
	}
#define CONTROLLER_CHECK_OBJECT(L, OBJECT, NAME) \
	if (!(OBJECT)) { \
		char controller_native_name[192]; \
		controller_legacy_native_name(controller_native_name, sizeof(controller_native_name), (NAME)); \
		return luaL_error((L), "invalid 'cobj' in function '%s'", controller_native_name); \
	}
#else
#define CONTROLLER_CHECK_RECEIVER(L, TYPE, NAME, TABLE) (void)(TYPE);
#define CONTROLLER_CHECK_OBJECT(L, OBJECT, NAME) (void)(OBJECT);
#endif

#undef LUA_INVOKE_HEADER
#define LUA_INVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	CONTROLLER_CHECK_RECEIVER(lua_S, LUA_OBJ_TYPE, LUA_FNAME, false); \
	const auto* controller_self = tolua_tousertype(lua_S, 1, nullptr); \
	CONTROLLER_CHECK_OBJECT(lua_S, controller_self, LUA_FNAME); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = true; \
	int arg_cur = -1; \
	bool ok = false;

#undef LUA_SINVOKE_HEADER
#define LUA_SINVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	CONTROLLER_CHECK_RECEIVER(lua_S, LUA_OBJ_TYPE, LUA_FNAME, true); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = false; \
	int arg_cur = -1; \
	bool ok = false;

#undef LUA_TRY_INVOKE
#define LUA_TRY_INVOKE(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		auto controller_fn = (Fn_); \
		arg_cur = 0; \
		if (controller_binding::prepare_signature<decltype(controller_fn)>::run(lua_S, LUA_FNAME)) { \
			int native_results = 0; \
			ok = lua::_invoke_native<true, true, false, binding_member_self>(lua_S, arg_cur, controller_fn, &native_results); \
			if (ok) { lua_settop(lua_S, 1); return 1; } \
		} \
	}
#undef LUA_TRY_INVOKE_R
#define LUA_TRY_INVOKE_R(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		auto controller_fn = (Fn_); \
		arg_cur = 0; \
		if (controller_binding::prepare_signature<decltype(controller_fn)>::run(lua_S, LUA_FNAME)) { \
			int native_results = 0; \
			ok = lua::_invoke_native<true, true, false, binding_member_self>(lua_S, arg_cur, controller_fn, &native_results); \
			if (ok) return native_results; \
		} \
	}

#define CONTROLLER_ARGUMENT_FAILURE() \
	if (arg_cur != -1) { \
		char controller_native_name[192]; \
		controller_legacy_native_name(controller_native_name, sizeof(controller_native_name), LUA_FNAME); \
		return luaL_error(lua_S, "invalid arguments in function '%s'", controller_native_name); \
	}
#undef LUA_INVOKE_FOOTER
#define LUA_INVOKE_FOOTER(Expected_) \
	CONTROLLER_ARGUMENT_FAILURE(); \
	return luaL_error(lua_S, "%s has wrong number of arguments: %d, was expecting %s \n", LUA_FNAME, argc, Expected_);
#undef LUA_SINVOKE_FOOTER
#define LUA_SINVOKE_FOOTER(Expected_) \
	CONTROLLER_ARGUMENT_FAILURE(); \
	return luaL_error(lua_S, "%s has wrong number of arguments: %d, was expecting %s\n ", LUA_FNAME, argc, Expected_);
