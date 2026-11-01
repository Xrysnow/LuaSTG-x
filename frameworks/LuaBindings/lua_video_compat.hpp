#pragma once
#include "lua_conversion/lua_conversion.hpp"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include <cstring>

int register_all_cc_video_manual(lua_State* L);

// Preserve this module's legacy checked conversions independently of Release's
// global binding setting. Numeric strings and nil booleans remain accepted;
// callbacks still require a function (nil was never a cancellation API).
namespace video_binding
{
template<typename T> struct callback_type : std::false_type {};
template<typename R, typename... Args>
struct callback_type<std::function<R(Args...)>> : std::true_type {};

template<typename Arg>
bool prepare_value(lua_State* L, int index, const char* name)
{
	using T = std::remove_cv_t<std::remove_reference_t<Arg>>;
	if constexpr (std::is_enum_v<T> || std::is_same_v<T, int>) {
		int value;
		if (!luaval_to_int32(L, index, &value, name)) return false;
		lua_pushnumber(L, value); lua_replace(L, index);
	} else if constexpr (std::is_same_v<T, unsigned int>) {
		unsigned int value;
		if (!luaval_to_uint32(L, index, &value, name)) return false;
		lua_pushnumber(L, value); lua_replace(L, index);
	} else if constexpr (std::is_floating_point_v<T>) {
		double value;
		if (!luaval_to_number(L, index, &value, name)) return false;
		lua_pushnumber(L, value); lua_replace(L, index);
	} else if constexpr (callback_type<T>::value) {
		return lua_isfunction(L, index);
	}
	return true;
}

template<typename... Args, size_t... Index>
bool prepare_arguments(lua_State* L, const char* name, std::index_sequence<Index...>)
{
	const int first = lua_gettop(L) - int(sizeof...(Args)) + 1;
	return (prepare_value<Args>(L, first + int(Index), name) && ...);
}

template<typename T> struct prepare_signature;
template<typename R, typename... Args>
struct prepare_signature<R(*)(Args...)> {
	static bool run(lua_State* L, const char* name) {
		return prepare_arguments<Args...>(L, name, std::index_sequence_for<Args...>{});
	}
};
template<typename C, typename R, typename... Args>
struct prepare_signature<R(C::*)(Args...)> : prepare_signature<R(*)(Args...)> {};
template<typename C, typename R, typename... Args>
struct prepare_signature<R(C::*)(Args...) const> : prepare_signature<R(*)(Args...)> {};

template<typename F>
bool prepare(lua_State* L, const char* name, const F&)
{
	using T = std::decay_t<F>;
	if constexpr (std::is_class_v<T>)
		return prepare_signature<typename lua::function_traits<T>::pointer>::run(L, name);
	else
		return prepare_signature<T>::run(L, name);
}

inline void finish_result(lua_State* L, const char* name)
{
	// Size aliases Vec2 natively, but these legacy APIs return width/height.
	if (std::strcmp(name, "video.Decoder:getVideoSize") == 0 ||
		std::strcmp(name, "video.Decoder:getVideoTargetSize") == 0) {
		lua_getfield(L, -1, "x"); lua_setfield(L, -2, "width");
		lua_getfield(L, -1, "y"); lua_setfield(L, -2, "height");
		lua_pushnil(L); lua_setfield(L, -2, "x");
		lua_pushnil(L); lua_setfield(L, -2, "y");
	}
}
}

#ifdef LUA_DEBUG
#define VIDEO_CHECK_TYPE(L, TYPE, NAME) \
	if (!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) \
		return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", \
			(NAME), tolua_typename((L), 1), (TYPE));
#define VIDEO_CHECK_OBJECT(L, OBJECT, NAME) \
	if (!(OBJECT)) return luaL_error((L), "invalid 'cobj' in '%s'", (NAME));
#else
#define VIDEO_CHECK_TYPE(L, TYPE, NAME) (void)(TYPE);
#define VIDEO_CHECK_OBJECT(L, OBJECT, NAME) (void)(OBJECT);
#endif

#undef LUA_INVOKE_HEADER
#define LUA_INVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	VIDEO_CHECK_TYPE(lua_S, LUA_OBJ_TYPE, LUA_FNAME); \
	const auto* video_self = tolua_tousertype(lua_S, 1, nullptr); \
	VIDEO_CHECK_OBJECT(lua_S, video_self, LUA_FNAME); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = true; \
	int arg_cur = -1; \
	bool ok = false;

#undef LUA_SINVOKE_HEADER
#define LUA_SINVOKE_HEADER(CName_, FName_) \
	constexpr auto LUA_OBJ_TYPE = CName_; \
	constexpr auto LUA_FNAME = FName_; \
	VIDEO_CHECK_TYPE(lua_S, LUA_OBJ_TYPE, LUA_FNAME); \
	const int argc = lua_gettop(lua_S) - 1; \
	constexpr bool binding_member_self = false; \
	int arg_cur = -1; \
	bool ok = false;

#undef LUA_TRY_INVOKE
#define LUA_TRY_INVOKE(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		auto video_fn = (Fn_); \
		arg_cur = 0; \
		if (video_binding::prepare(lua_S, LUA_FNAME, video_fn)) { \
			int native_results = 0; \
			ok = lua::_invoke_native<true, true, false, binding_member_self>( \
				lua_S, arg_cur, video_fn, &native_results); \
			if (ok) { lua_settop(lua_S, 1); return 1; } \
		} \
	}

#undef LUA_TRY_INVOKE_R
#define LUA_TRY_INVOKE_R(ARGC_, Fn_) \
	if (argc == (ARGC_)) { \
		auto video_fn = (Fn_); \
		arg_cur = 0; \
		if (video_binding::prepare(lua_S, LUA_FNAME, video_fn)) { \
			int native_results = 0; \
			ok = lua::_invoke_native<true, true, false, binding_member_self>( \
				lua_S, arg_cur, video_fn, &native_results); \
			if (ok) { video_binding::finish_result(lua_S, LUA_FNAME); return native_results; } \
		} \
	}

#undef LUA_INVOKE_FOOTER
#define LUA_INVOKE_FOOTER(Expected_) \
	if (arg_cur != -1) return luaL_error(lua_S, "invalid arguments in '%s'", LUA_FNAME); \
	return luaL_error(lua_S, "wrong number of arguments in '%s': %d, expects %s", \
		LUA_FNAME, argc, std::strcmp(Expected_, "0,1") == 0 ? "0 to 1" : Expected_);
#undef LUA_SINVOKE_FOOTER
#define LUA_SINVOKE_FOOTER(Expected_) LUA_INVOKE_FOOTER(Expected_)
