#pragma once
#include "tolua++.h"
#include "tolua_fix.h"
#include <array>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <forward_list>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef CC_USE_GFX
extern std::unordered_map<uintptr_t, const char*> g_luaType;
extern std::unordered_map<std::string, const char*> g_typeCast;
#else
extern std::unordered_map<std::string, std::string> g_luaType;
extern std::unordered_map<std::string, std::string> g_typeCast;
#endif

namespace lua
{
	constexpr int LUA_TPROTO = LUA_TTHREAD + 1;
    constexpr int LUA_TCDATA = LUA_TTHREAD + 2;
	constexpr auto _ffi_cast_uint64 = R"__(
local ffi = require('ffi')
local store = ffi.new('uint64_t[1]')
local ptr = ffi.cast('uint64_t*', store)
return function(value)
	store[0] = value
    return ptr
end
)__";
	constexpr auto _ffi_cast_int64 = R"__(
local ffi = require('ffi')
local store = ffi.new('int64_t[1]')
local ptr = ffi.cast('int64_t*', store)
return function(value)
	store[0] = value
    return ptr
end
)__";
	constexpr auto _ffi_convert_ptr = R"__(
local ffi = require('ffi')
local C = ffi.C
local _ptr_size = ffi.sizeof('void*')
local _pptr_t = ffi.typeof('void*[1]')
pcall(ffi.cdef, [[void* memcpy(void *p1, void *p2, size_t n);]])
return function(cdata_ptr, userdata)
    C.memcpy(userdata, _pptr_t(cdata_ptr), _ptr_size)
end
)__";

    template<typename T>
    std::string getClassNameByType()
    {
		using key_type = decltype(g_luaType)::key_type;
		using type = std::conditional_t<std::is_integral_v<key_type>, key_type, const char*>;
		const auto key = reinterpret_cast<type>(typeid(T).name());
        const auto it = g_luaType.find(key);
        if (it != g_luaType.end())
            return it->second;
        return "";
    }

    template<typename T>
    void registerLuaType(const char* luaType, const char* castType)
    {
		using key_type = decltype(g_luaType)::key_type;
		using type = std::conditional_t<std::is_integral_v<key_type>, key_type, const char*>;
		const auto key = reinterpret_cast<type>(typeid(T).name());
        g_luaType[key] = luaType;
        g_typeCast[castType] = luaType;
    }

    inline int push_table_instance(lua_State* L, int lo)
    {
        if (lo < 0 && lo > LUA_REGISTRYINDEX) {
            lo = lua_gettop(L) + lo + 1;
            if (lo <= 0)
                return 0;
        }
        if (lua_istable(L, lo)) {
            lua_pushstring(L, ".c_instance");
            lua_gettable(L, lo);
            if (lua_type(L, -1) == LUA_TUSERDATA) {
                lua_replace(L, lo);
                return 1;
            }
            lua_pop(L, 1);
            return 0;
        }
        return 0;
    }

    inline int isusertype(lua_State* L, int lo, const char* type)
    {
        if (!L || !type || !*type)
            return 0;
        if (lo < 0 && lo > LUA_REGISTRYINDEX) {
            lo = lua_gettop(L) + lo + 1;
            if (lo <= 0)
                return 0;
        }
        if (lo == 0 || lo > lua_gettop(L))
            return 0;
        if (lua_type(L, lo) != LUA_TUSERDATA) {
            if (!push_table_instance(L, lo)) {
                return 0;
            }
        }
        if (lua_objlen(L, lo) != sizeof(void*))
            return 0;
        if (lua_getmetatable(L, lo))        /* if metatable? */
        {
            lua_rawget(L, LUA_REGISTRYINDEX);  /* get registry[mt] */
            const char *tn = lua_tostring(L, -1);
            const int r = tn && (strcmp(tn, type) == 0);
            lua_pop(L, 1);
            if (r)
                return 1;
            else
            {
                /* check if it is a specialized class */
                lua_pushstring(L, "tolua_super");
                lua_rawget(L, LUA_REGISTRYINDEX); /* get super */
                if (!lua_istable(L, -1)) {
                    lua_pop(L, 1);
                    return 0;
                }
                lua_getmetatable(L, lo);
                lua_rawget(L, -2);                /* get super[mt] */
                if (lua_istable(L, -1))
                {
                    lua_pushstring(L, type);
                    lua_rawget(L, -2);                /* get super[mt][type] */
                    const int b = lua_toboolean(L, -1);
                    lua_pop(L, 3);
                    if (b)
                        return 1;
                }
                else
                    lua_pop(L, 2);
            }
        }
        return 0;
    }

    inline void* _tousertype(lua_State* L, int lo)
    {
        if (!L)
            return nullptr;
        if (lo < 0 && lo > LUA_REGISTRYINDEX) {
            lo = lua_gettop(L) + lo + 1;
            if (lo <= 0)
                return nullptr;
        }
        if (lo == 0 || lo > lua_gettop(L))
            return nullptr;
        if (lua_type(L, lo) != LUA_TUSERDATA) {
            if (!push_table_instance(L, lo))
                return nullptr;
        }
        if (lua_objlen(L, lo) != sizeof(void*))
            return nullptr;
        const auto u = lua_touserdata(L, lo);
        return u ? *(void**)u : nullptr;
    }

    inline bool _try_get_internal_helper(lua_State* L, const char* key, const char* def)
    {
		lua_pushstring(L, key); // 1
		lua_rawget(L, LUA_REGISTRYINDEX); // 1
		auto tfunc = lua_type(L, -1);
		if (tfunc == LUA_TNIL)
		{
			lua_pop(L, 1); // 0
			luaL_dostring(L, def); // 1
			lua_setfield(L, LUA_REGISTRYINDEX, key); // 0
			lua_pushstring(L, key); // 1
			lua_rawget(L, LUA_REGISTRYINDEX); // 1
			tfunc = lua_type(L, -1);
		}
		return tfunc == LUA_TFUNCTION;
    }

	inline bool is_indexable(lua_State* L, int lo)
	{
		const auto t = lua_type(L, lo);
		return t == LUA_TTABLE || t == LUA_TUSERDATA || t == LUA_TCDATA;
	}

	////////////////////////////////////////////////////////////////////////////////

	// fix stack indices and keep pseudo-indices, 0 means invalid
	inline int _absolute_index(lua_State* L, int lo) {
		if (!L) return 0;
		if (lo <= LUA_REGISTRYINDEX) return lo;
		const int top = lua_gettop(L);
		if (lo < 0) lo += top + 1;
		return lo > 0 && lo <= top ? lo : 0;
	}

	inline bool luaval_to_cptr(lua_State* L, int lo, void** outValue)
	{
		if (!L || !outValue) return false;
		lo = _absolute_index(L, lo);
		if (!lo)
		{
			*outValue = nullptr;
			return false;
		}
		const auto ok = _try_get_internal_helper(L, "ffi.convert_ptr", _ffi_convert_ptr);
		if (ok)
		{
			void* ret = nullptr;
			lua_pushvalue(L, lo);
			lua_pushlightuserdata(L, &ret);
			if (lua_pcall(L, 2, 0, 0) == 0)
			{
				*outValue = ret;
				return true;
			}
			*outValue = nullptr;
			return false;
		}
		else
		{
			lua_pop(L, 1);
			*outValue = nullptr;
			return false;
		}
	}

	template<typename T, typename Enable = std::enable_if_t<std::is_same_v<T, int64_t> || std::is_same_v<T, uint64_t>, T>>
	bool _luaval_to_integer(lua_State* L, int lo,
		T* outValue,
		size_t targetSize, const char* funcName)
	{
		if (nullptr == L || nullptr == outValue)
			return false;
		lo = _absolute_index(L, lo);
		if (!lo) return false;
		constexpr bool isint64 = std::is_same_v<T, int64_t>;
		const auto type = lua_type(L, lo);
		if (type == LUA_TCDATA)
		{
			const char* key = isint64 ? "ffi.cast_int64" : "ffi.cast_uint64";
			const char* def = isint64 ? _ffi_cast_int64 : _ffi_cast_uint64;
			const auto ok = _try_get_internal_helper(L, key, def);
			if (ok)
			{
				void* ret = nullptr;
				lua_pushvalue(L, lo);
				lua_pushlightuserdata(L, &ret);
				if (lua_pcall(L, 1, 1, 0) == 0)
				{
					luaval_to_cptr(L, -1, &ret);
					if (ret)
					{
						*outValue = *(T*)ret;
						return true;
					}
				}
			}
			else
			{
				lua_pop(L, 1);
			}
		}
		bool is_number = type == LUA_TNUMBER;
		if (!is_number)
		{
			return false;
		}
		// do not use tolua_tonumber, since it rejects pseudo-indices
		if (std::is_same_v<T, int64_t> && targetSize == 4)
		{
			// see luaval_to_int32
			const auto estimateValue = (uint32_t)lua_tonumber(L, lo);
			if (estimateValue == (uint32_t)std::numeric_limits<int32_t>::min())
				*outValue = (int32_t)estimateValue;
			else
				*outValue = (int64_t)(int32_t)lua_tonumber(L, lo);
		}
		else
			*outValue = (T)lua_tonumber(L, lo);
		return true;
	}

	inline bool luaval_to_int(lua_State* L, int lo, int64_t* outValue, size_t targetSize, const char* funcName)
    {
		return _luaval_to_integer<int64_t>(L, lo, outValue, targetSize, funcName);
    }

	inline bool luaval_to_uint(lua_State* L, int lo, uint64_t* outValue, size_t targetSize, const char* funcName)
    {
		return _luaval_to_integer<uint64_t>(L, lo, outValue, targetSize, funcName);
    }

	////////////////////////////////////////////////////////////////////////////////

	inline int luafunction_to_handler(lua_State* L, int lo, const char* fName)
	{
		const int index = _absolute_index(L, lo);
		if (!index) return 0;
		const int handler = toluafix_ref_function(L, index, 0);
		if (handler == 0)
			return 0;
		std::string key;
		if (fName) key = fName;
		if (!key.empty()) {
			key += "::" + std::to_string(lo);
			lua_pushstring(L, TOLUA_REFID_FUNCTION_MAPPING);
			lua_rawget(L, LUA_REGISTRYINDEX); // ... t
			lua_pushlstring(L, key.c_str(), key.size()); // ... t k
			// Names are lookup aliases, not ownership or replacement keys.
			lua_pushinteger(L, handler); // ... t k v
			lua_settable(L, -3); // ... t
			lua_pop(L, 1);
		}
		return handler;
	}

	inline int query_luafunction_handler(lua_State* L, int lo, const char* fName)
    {
		std::string key;
		if (fName) key = fName;
		if (!key.empty()) {
			int value = 0;
			key += "::" + std::to_string(lo);
			lua_pushstring(L, TOLUA_REFID_FUNCTION_MAPPING);
			lua_rawget(L, LUA_REGISTRYINDEX); // ... t
			lua_pushlstring(L, key.c_str(), key.size()); // ... t k
			lua_rawget(L, -2); // ... t v
			if (lua_isnumber(L, -1))
				value = (int)lua_tointeger(L, -1);
			lua_pop(L, 2);
			return value;
		}
		return 0;
    }

	inline void handler_to_luafunction(lua_State* L, int handler)
    {
		if (handler != 0)
			toluafix_get_function_by_refid(L, handler);
		else
			lua_pushnil(L);
    }

	// Lua-owned storage for the state lifetime sentinel.
	template<typename T>
	struct _callback_userdata {
		using value_type = std::shared_ptr<T>;
		value_type* value;
		alignas(value_type) unsigned char storage[sizeof(value_type)];
		static void* key() { static char k; return &k; }
		// Keep the userdata rooted during reset: destroying its value may enter Lua.
		static void reset(_callback_userdata* p) {
			if (p->value) {
				auto* value = p->value;
				// Invalidate first so reentrant __gc cannot destroy the value twice.
				p->value = nullptr;
				value->~value_type();
			}
		}
		static int collect(lua_State* L) {
			if (lua_type(L, 1) != LUA_TUSERDATA || lua_objlen(L, 1) != sizeof(_callback_userdata)
				|| !lua_getmetatable(L, 1)) return 0;
			lua_pushlightuserdata(L, key());
			lua_rawget(L, LUA_REGISTRYINDEX);
			const bool matches = lua_rawequal(L, -1, -2) != 0;
			lua_pop(L, 2);
			if (matches) reset(static_cast<_callback_userdata*>(lua_touserdata(L, 1)));
			return 0;
		}
		static _callback_userdata* push(lua_State* L, const value_type& value) {
			lua_pushlightuserdata(L, key());
			lua_rawget(L, LUA_REGISTRYINDEX);
			if (lua_isnil(L, -1)) {
				lua_pop(L, 1);
				lua_createtable(L, 0, 1);
				lua_pushcfunction(L, collect);
				lua_setfield(L, -2, "__gc");
				lua_pushlightuserdata(L, key());
				lua_pushvalue(L, -2);
				lua_rawset(L, LUA_REGISTRYINDEX);
			}
			auto* p = new (lua_newuserdata(L, sizeof(_callback_userdata))) _callback_userdata{};
			lua_insert(L, -2);
			lua_setmetatable(L, -2);
			p->value = new (p->storage) value_type(value);
			return p;
		}
	};

	struct _callback_reference;
	// The mutex protects cross-thread release bookkeeping, not the Lua VM.
	struct _callback_state {
		const std::thread::id thread = std::this_thread::get_id();
		std::mutex mutex;
		bool alive = true;
		_callback_reference* pending = nullptr;
		bool callable() {
			std::lock_guard<std::mutex> lock(mutex);
			return alive && thread == std::this_thread::get_id();
		}
		void drain(lua_State* L);
		void close();
	};

	// One registration, shared by C++ copies and temporary call anchors.
	struct _callback_reference {
		std::shared_ptr<_callback_state> state;
		lua_State* L;
		// Own the diagnostic name; the caller's fName may be temporary.
		std::string name;
		std::string key;
		int handler = 0;
		int thread_ref = LUA_NOREF;
		_callback_reference* next = nullptr;
		void unref(lua_State* current) {
			if (handler) {
				toluafix_remove_function_by_refid(current, handler);
				if (!key.empty()) {
					lua_pushstring(current, TOLUA_REFID_FUNCTION_MAPPING);
					lua_rawget(current, LUA_REGISTRYINDEX);
					lua_pushlstring(current, key.data(), key.size());
					lua_rawget(current, -2);
					// An older callback must not remove a newer callback's alias.
					const bool matches = lua_isnumber(current, -1)
						&& lua_tointeger(current, -1) == handler;
					lua_pop(current, 1);
					if (matches) {
						lua_pushlstring(current, key.data(), key.size());
						lua_pushnil(current);
						lua_rawset(current, -3);
					}
					lua_pop(current, 1);
				}
			}
			// Last: current may itself be the coroutine kept alive by this ref.
			luaL_unref(current, LUA_REGISTRYINDEX, thread_ref);
		}
		static void release(_callback_reference* p) {
			bool active;
			{
				std::lock_guard<std::mutex> lock(p->state->mutex);
				active = p->state->alive;
				if (active && p->state->thread != std::this_thread::get_id()) {
					// Never access Lua from a worker. No allocation in this deleter.
					// Drain on the next owner-thread registration/call, or discard on close.
					p->next = p->state->pending;
					p->state->pending = p;
					return;
				}
			}
			if (active) p->unref(p->L);
			delete p;
		}
	};

	inline void _callback_state::drain(lua_State* L) {
		_callback_reference* list;
		{
			std::lock_guard<std::mutex> lock(mutex);
			list = pending;
			pending = nullptr;
		}
		// Unref outside the lock: Lua GC can reenter callback destruction.
		while (list) {
			auto* p = list;
			list = p->next;
			p->unref(L);
			delete p;
		}
	}
	inline void _callback_state::close() {
		_callback_reference* list;
		{
			std::lock_guard<std::mutex> lock(mutex);
			alive = false;
			list = pending;
			pending = nullptr;
		}
		while (list) {
			auto* p = list;
			list = p->next;
			delete p; // lua_close owns the registry; do not use Lua here.
		}
	}
	// Only the registry owns this sentinel; its finalizer marks surviving refs closed.
	struct _callback_lifetime {
		std::shared_ptr<_callback_state> state = std::make_shared<_callback_state>();
		~_callback_lifetime() { state->close(); }
	};
	// Coroutines share the registry and therefore the same lifetime sentinel.
	inline std::shared_ptr<_callback_state> _get_callback_state(lua_State* L) {
		static char key;
		using holder = _callback_userdata<_callback_lifetime>;
		lua_pushlightuserdata(L, &key);
		lua_rawget(L, LUA_REGISTRYINDEX);
		if (lua_isnil(L, -1)) {
			lua_pop(L, 1);
			holder::push(L, std::make_shared<_callback_lifetime>());
			lua_pushlightuserdata(L, &key);
			lua_pushvalue(L, -2);
			lua_rawset(L, LUA_REGISTRYINDEX);
		}
		auto* p = static_cast<holder*>(lua_touserdata(L, -1));
		auto state = p->value ? (*p->value)->state : nullptr;
		lua_pop(L, 1);
		if (state && state->callable()) state->drain(L);
		return state;
	}
	inline std::shared_ptr<_callback_reference> _own_luafunction(lua_State* L, int lo, const char* name) {
		const int index = _absolute_index(L, lo);
		if (!index || !lua_isfunction(L, index)) return nullptr;
		auto state = _get_callback_state(L);
		if (!state || !state->callable()) return nullptr;
		auto ref = std::shared_ptr<_callback_reference>(new _callback_reference{
			state, L, name ? name : "", "" }, _callback_reference::release);
		if (!ref->name.empty()) ref->key = ref->name + "::" + std::to_string(lo);
		// Pin the originating coroutine while native code holds the callback.
		lua_pushthread(L);
		ref->thread_ref = luaL_ref(L, LUA_REGISTRYINDEX);
		ref->handler = luafunction_to_handler(L, lo, name);
		return ref->handler ? ref : nullptr;
	}

    ////////////////////////////////////////////////////////////////////////////////

	template<typename T, class Enable = void> struct to_native {};

#define LUA_CHECK_TO_NATIVE\
	const auto top = L ? lua_gettop(L) : 0;\
	do {\
		if (nullptr == L || nullptr == outValue || !(lo = ::lua::_absolute_index(L, lo)))\
			return false;\
	} while (false)

#define LUA_TO_NATIVE_VECTOR(_Ty, _Setter) template<typename T>\
	struct to_native<_Ty<T>> {\
		static bool F(lua_State* L, int lo, _Ty<T>* outValue, const char* fName = "") {\
			LUA_CHECK_TO_NATIVE;\
			const auto type = lua_type(L, lo);\
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))\
				return false;\
			const size_t len = lua_objlen(L, lo);\
			T value;\
			bool ok = true;\
			for (size_t i = 0; i < len; i++) {\
				lua_pushnumber(L, i + 1);\
				lua_gettable(L, lo);\
				ok &= to_native<T>::F(L, top + 1, &value, fName);\
				lua_pop(L, 1);\
				if (ok)\
					outValue->_Setter(value);\
				else\
					break;\
			}\
			return true; } };

#define LUA_TO_NATIVE_MAP(_Ty, _Setter) template<typename K, typename V>\
	struct to_native<_Ty<K, V>> {\
		static bool F(lua_State* L, int lo, _Ty<K, V>* outValue, const char* fName = "") {\
			LUA_CHECK_TO_NATIVE;\
			const auto type = lua_type(L, lo);\
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))\
				return false;\
			K key; V value;\
			lua_pushnil(L);\
			while (lua_next(L, lo) != 0) {\
				if(!to_native<K>::F(L, top + 1, &key, fName)) {\
					lua_pop(L, 1); /* removes 'value'; keep 'key' for next iteration*/\
					continue;\
				}\
				if (to_native<V>::F(L, top + 2, &value, fName))\
					(*outValue)_Setter;\
				lua_pop(L, 1);\
			}\
			return true; } };\

#define TO_NATIVE_SIGNED(_T) template<>\
	struct to_native<_T> {\
		static bool F(lua_State* L, int lo, _T* outValue, const char* funcName = ""){\
			int64_t i; bool ret = luaval_to_int(L, lo, &i, sizeof(_T), funcName);\
			if (ret) *outValue = (_T)(i); return ret; } }
#define TO_NATIVE_UNSIGNED(_T) template<>\
	struct to_native<_T> {\
		static bool F(lua_State* L, int lo, _T* outValue, const char* funcName = ""){\
			uint64_t i; bool ret = luaval_to_uint(L, lo, &i, sizeof(_T), funcName);\
			if (ret) *outValue = (_T)(i); return ret; } }

	TO_NATIVE_SIGNED(int8_t);
	TO_NATIVE_SIGNED(int16_t);
	TO_NATIVE_SIGNED(int32_t);
	TO_NATIVE_SIGNED(int64_t);
	TO_NATIVE_UNSIGNED(uint8_t);
	TO_NATIVE_UNSIGNED(uint16_t);
	TO_NATIVE_UNSIGNED(uint32_t);
	TO_NATIVE_UNSIGNED(uint64_t);

#undef TO_NATIVE_SIGNED
#undef TO_NATIVE_UNSIGNED

	template<typename T>
	struct to_native<T, std::enable_if_t<std::is_enum_v<T>>> {
		static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			using type = std::underlying_type_t<T>;
			type value;
			auto ok = to_native<type>::F(L, lo, &value, fName);
			if (ok) *outValue = (T)value;
			return ok;
		}
	};

	template<>
	struct to_native<bool> {
		static bool F(lua_State* L, int lo, bool* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto ok = lua_isnil(L, lo) || lua_isboolean(L, lo);
			if (ok) *outValue = (bool)lua_toboolean(L, lo);
			return ok;
		}
	};

	template<>
	struct to_native<float> {
		static bool F(lua_State* L, int lo, float* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto ok = lua_isnumber(L, lo);
			if (ok) *outValue = (float)lua_tonumber(L, lo);
			return ok;
		}
	};

	template<>
	struct to_native<double> {
		static bool F(lua_State* L, int lo, double* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto ok = lua_isnumber(L, lo);
			if (ok) *outValue = lua_tonumber(L, lo);
			return ok;
		}
	};

	template<>
	struct to_native<const char*> {
		static bool F(lua_State* L, int lo, const char** outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_isstring(L, lo))
				return false;
			*outValue = lua_tolstring(L, lo, nullptr);
			return true;
		}
	};

	template<>
	struct to_native<std::string> {
		static bool F(lua_State* L, int lo, std::string* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_isstring(L, lo))
				return false;
			size_t size;
			const auto str = lua_tolstring(L, lo, &size);
			outValue->assign(str, size);
			return true;
		}
	};

#ifdef __cpp_lib_string_view
	template<>
	struct to_native<std::string_view> {
		static bool F(lua_State* L, int lo, std::string_view* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_isstring(L, lo))
				return false;
			size_t size;
			const auto str = lua_tolstring(L, lo, &size);
			*outValue = { str,size };
			return true;
		}
	};
#endif

	template<typename T, size_t Size>
	struct to_native<std::array<T, Size>> {
		static bool F(lua_State* L, int lo, std::array<T, Size>* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto type = lua_type(L, lo);
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
				return false;
			const size_t len = std::min(lua_objlen(L, lo), Size);
			T value;
			bool ok = true;
			for (size_t i = 0; i < len; i++) {
				lua_pushnumber(L, i + 1);
				lua_gettable(L, lo);
				ok &= to_native<T>::F(L, top + 1, &value, fName);
				lua_pop(L, 1);
				if (ok)
					outValue->operator[](i) = value;
				else
					break;
			}
			return true;
		}
	};

	template<typename T1, typename T2>
	struct to_native<std::pair<T1, T2>> {
		static bool F(lua_State* L, int lo, std::pair<T1, T2>* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto type = lua_type(L, lo);
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
				return false;
			T1 value1; T2 value2;
			bool ok = true;
			lua_pushnumber(L, 1);
			lua_gettable(L, lo);
			ok &= to_native<T1>::F(L, top + 1, &value1, fName);
			lua_pop(L, 1);
			if (ok)
				outValue->first = value1;
			else
				return false;
			lua_pushnumber(L, 2);
			lua_gettable(L, lo);
			ok &= to_native<T2>::F(L, top + 1, &value2, fName);
			lua_pop(L, 1);
			if (ok)
				outValue->second = value2;
			return ok;
		}
	};

	template<size_t Index, typename ...Targs>
	struct _to_native_tuple_helper {
		static bool F(lua_State* L, int idx, std::tuple<Targs...>* outValue, const char* fName) {
			using type = std::tuple_element_t<Index - 1, std::tuple<Targs...>>;
			lua_pushnumber(L, Index);
			lua_gettable(L, idx);
			const auto ok = to_native<type>::F(L, lua_gettop(L), &std::get<Index - 1>(*outValue), fName);
			lua_pop(L, 1);
			if (!ok) return false;
			return _to_native_tuple_helper<Index - 1, Targs...>::F(L, idx, outValue, fName);
		}
	};

	template<typename ...Targs>
	struct _to_native_tuple_helper<0, Targs...> {
		static bool F(lua_State* L, int idx, std::tuple<Targs...>* outValue, const char* fName) {
			return true;
		}
	};

	template<typename... Types>
	struct to_native<std::tuple<Types...>> {
		using tuple_type = std::tuple<Types...>;
		static bool F(lua_State* L, int lo, tuple_type* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto type = lua_type(L, lo);
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
				return false;
			constexpr size_t size = std::tuple_size_v<tuple_type>;
			return _to_native_tuple_helper<size, Types...>::F(L, lo, outValue, fName);
		}
	};

	template<size_t Size>
	struct to_native<std::bitset<Size>> {
		static bool F(lua_State* L, int lo, std::bitset<Size>* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto type = lua_type(L, lo);
			if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
				return false;
			const size_t len = std::min(lua_objlen(L, lo), Size);
			bool value;
			bool ok = true;
			for (size_t i = 0; i < len; i++) {
				lua_pushnumber(L, i + 1);
				lua_gettable(L, lo);
				ok &= to_native<bool>::F(L, top + 1, &value, fName);
				lua_pop(L, 1);
				if (ok)
					outValue->set(i, value);
				else
					break;
			}
			return true;
		}
	};

	LUA_TO_NATIVE_VECTOR(std::vector, push_back);
	LUA_TO_NATIVE_VECTOR(std::deque, push_back);
	LUA_TO_NATIVE_VECTOR(std::forward_list, push_front);
	LUA_TO_NATIVE_VECTOR(std::list, push_back);
	LUA_TO_NATIVE_VECTOR(std::set, insert);
	LUA_TO_NATIVE_VECTOR(std::multiset, insert);
	LUA_TO_NATIVE_VECTOR(std::unordered_set, insert);
	LUA_TO_NATIVE_VECTOR(std::unordered_multiset, insert);
	LUA_TO_NATIVE_VECTOR(std::stack, push);
	LUA_TO_NATIVE_VECTOR(std::queue, push);
	LUA_TO_NATIVE_VECTOR(std::priority_queue, push);

	LUA_TO_NATIVE_MAP(std::map, [key] = value);
	LUA_TO_NATIVE_MAP(std::unordered_map, [key] = value);
	LUA_TO_NATIVE_MAP(std::multimap, .emplace(key, value));
	LUA_TO_NATIVE_MAP(std::unordered_multimap, .emplace(key, value));

	template<typename T>
	bool luaval_to_native(lua_State* L, int lo, T* outValue, const char* fName = "") {
		return to_native<T>::F(L, lo, outValue, fName);
	}

	template<typename T>
	bool luaval_field_to_native(lua_State* L, int lo, const char* field, T* outValue, const char* fName = "") {
		if (!field) return false;
		LUA_CHECK_TO_NATIVE;
		lua_pushstring(L, field);
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_field_to_native(lua_State* L, int lo, const std::string& field, T* outValue, const char* fName = "") {
		LUA_CHECK_TO_NATIVE;
		lua_pushlstring(L, field.c_str(), field.size());
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_field_to_native(lua_State* L, int lo, int field, T* outValue, const char* fName = "") {
		LUA_CHECK_TO_NATIVE;
		lua_pushinteger(L, field);
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_to_native_array(lua_State* L, int lo, T* outValue, size_t size, const char* fName = "") {
		LUA_CHECK_TO_NATIVE;
		std::vector<T> value;
		if(!to_native<std::vector<T>>::F(L, lo, &value, fName))
			return false;
		if (value.size() != size) return false;
		for (size_t i = 0; i < size; ++i)
			outValue[i] = value[i];
		return true;
	}

	template<typename T>
	bool luaval_to_native_array_inplace(lua_State* L, int lo, T* outValue, size_t size, const char* fName = "") {
		LUA_CHECK_TO_NATIVE;
		if (!is_indexable(L, lo)) return false;
		const size_t len = lua_objlen(L, lo);
		if (len != size) return false;
		bool ok = true;
		for (int i = 0; i < size; ++i)
		{
			lua_pushnumber(L, i + 1);
			lua_gettable(L, lo);
			ok &= to_native<T>::F(L, top + 1, outValue + i, fName);
			lua_pop(L, 1);
			if(!ok)
				break;
		}
		return ok;
	}

	////////////////////////////////////////////////////////////////////////////////

	template<typename T, class Enable = void> struct to_lua {};

#define LUA_TO_LUA_VECTOR(_Ty) template<typename T>\
	struct to_lua<_Ty<T>> {\
		static void F(lua_State* L, const _Ty<T>& inValue) {\
			if (!L) return;\
			lua_createtable(L, (int)inValue.size(), 0);\
			int index = 1;\
			for (auto& value : inValue) {\
				lua_pushnumber(L, (lua_Number)index);\
				to_lua<T>::F(L, value);\
				lua_rawset(L, -3);\
				++index;\
			} } };

#define LUA_TO_LUA_MAP(_Ty) template<typename K, typename V>\
	struct to_lua<_Ty<K, V>> {\
		static void F(lua_State* L, const _Ty<K, V>& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 0);\
			for (auto& it : inValue) {\
				to_lua<K>::F(L, it.first);\
				to_lua<V>::F(L, it.second);\
				lua_rawset(L, -3);\
			} } };

	template<>
	struct to_lua<bool> {
		static void F(lua_State* L, bool inValue) {
			if (!L) return;
			lua_pushboolean(L, inValue);
		}
	};

	template<typename T>
	struct to_lua<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
		static void F(lua_State* L, T inValue) {
			if (!L) return;
			lua_pushnumber(L, (lua_Number)inValue);
		}
	};

	template<typename T>
	struct to_lua<T, std::enable_if_t<std::is_enum_v<T>>> {
		static void F(lua_State* L, T inValue) {
			if (!L) return;
			using type = std::underlying_type_t<T>;
			lua_pushnumber(L, (lua_Number)(type)inValue);
		}
	};

	template<>
	struct to_lua<const char*> {
		static void F(lua_State* L, const char* inValue) {
			if (!L) return;
			lua_pushstring(L, inValue);
		}
	};

	template<>
	struct to_lua<std::string> {
		static void F(lua_State* L, const std::string& inValue) {
			if (!L) return;
			lua_pushlstring(L, inValue.c_str(), inValue.size());
		}
	};

#ifdef __cpp_lib_string_view
	template<>
	struct to_lua<std::string_view> {
		static void F(lua_State* L, const std::string_view& inValue) {
			if (!L) return;
			lua_pushlstring(L, inValue.data(), inValue.size());
		}
	};
#endif

	template<typename T, size_t Size>
	struct to_lua<std::array<T, Size>> {
		static void F(lua_State* L, const std::array<T, Size>& inValue) {
			if (!L) return;
			lua_createtable(L, (int)inValue.size(), 0);
			int index = 1;
			for (auto& value : inValue) {
				lua_pushnumber(L, (lua_Number)index);
				to_lua<T>::F(L, value);
				lua_rawset(L, -3);
				++index;
			}
		}
	};

	template<typename T1, typename T2>
	struct to_lua<std::pair<T1, T2>> {
		static void F(lua_State* L, const std::pair<T1, T2>& inValue) {
			if (!L) return;
			lua_createtable(L, 2, 0);
			lua_pushnumber(L, 1);
			to_lua<T1>::F(L, inValue.first);
			lua_settable(L, -3);
			lua_pushnumber(L, 2);
			to_lua<T2>::F(L, inValue.second);
			lua_settable(L, -3);
		}
	};

	template<size_t Index, typename... Targs>
	struct _to_lua_tuple_helper {
		static void F(lua_State* L, int idx, const std::tuple<Targs...>& inValue) {
			using type = std::tuple_element_t<Index - 1, std::tuple<Targs...>>;
			lua_pushnumber(L, Index);
			to_lua<type>::F(L, std::get<Index - 1>(inValue));
			lua_settable(L, idx);
			_to_lua_tuple_helper<Index - 1, Targs...>::F(L, idx, inValue);
		}
	};

	template<typename... Targs>
	struct _to_lua_tuple_helper<0, Targs...> {
		static void F(lua_State* L, int idx, const std::tuple<Targs...>& inValue) {
		}
	};

	template<typename... Types>
	struct to_lua<std::tuple<Types...>> {
		using tuple_type = std::tuple<Types...>;
		static void F(lua_State* L, const tuple_type& inValue) {
			if (!L) return;
			constexpr size_t size = std::tuple_size_v<tuple_type>;
			lua_createtable(L, (int)size, 0);
			_to_lua_tuple_helper<size, Types...>::F(L, lua_gettop(L), inValue);
		}
	};

	template<size_t Size>
	struct to_lua<std::bitset<Size>> {
		static void F(lua_State* L, const std::bitset<Size>& inValue) {
			if (!L) return;
			lua_createtable(L, (int)inValue.size(), 0);
			for (size_t i = 0; i < Size; ++i) {
				lua_pushnumber(L, (lua_Number)i);
				to_lua<bool>::F(L, inValue.test(i));
				lua_rawset(L, -3);
			}
		}
	};

	LUA_TO_LUA_VECTOR(std::vector);
	LUA_TO_LUA_VECTOR(std::deque);
	LUA_TO_LUA_VECTOR(std::forward_list);
	LUA_TO_LUA_VECTOR(std::list);
	LUA_TO_LUA_VECTOR(std::set);
	LUA_TO_LUA_VECTOR(std::multiset);
	LUA_TO_LUA_VECTOR(std::unordered_set);
	LUA_TO_LUA_VECTOR(std::unordered_multiset);

	LUA_TO_LUA_MAP(std::map);
	LUA_TO_LUA_MAP(std::unordered_map);
	LUA_TO_LUA_MAP(std::multimap);
	LUA_TO_LUA_MAP(std::unordered_multimap);

	template<typename T>
	void native_to_luaval(lua_State* L, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		to_lua<type>::F(L, inValue);
	}

	template<typename T>
	void native_to_luaval_field(lua_State* L, int lo, const char* field, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		if (!field) return;
		if (!L || !(lo = _absolute_index(L, lo))) return;
		lua_pushstring(L, field);
		to_lua<type>::F(L, inValue);
		lua_settable(L, lo);
	}

	template<typename T>
	void native_to_luaval_field(lua_State* L, int lo, const std::string& field, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		if (!L || !(lo = _absolute_index(L, lo))) return;
		lua_pushlstring(L, field.c_str(), field.size());
		to_lua<type>::F(L, inValue);
		lua_settable(L, lo);
	}

	template<typename T>
	void native_to_luaval_field(lua_State* L, int lo, int field, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		if (!L || !(lo = _absolute_index(L, lo))) return;
		lua_pushinteger(L, field);
		to_lua<type>::F(L, inValue);
		lua_settable(L, lo);
	}

	template<typename T>
	void native_array_to_luaval(lua_State* L, const T* inValue, size_t size) {
		lua_createtable(L, (int)size, 0);
		for (size_t i = 0; i < size; ++i) {
			lua_pushinteger(L, i + 1);
			to_lua<T>::F(L, inValue[i]);
			lua_settable(L, -3);
		}
	}

	template<size_t Index, typename Targ = void, typename... Targs>
	struct _to_lua_function_helper {
		static void F(lua_State* L, Targ&& arg, Targs&&... args) {
			native_to_luaval(L, arg);
			_to_lua_function_helper<Index - 1, Targs...>::F(L, std::forward<Targs>(args)...);
		}
	};

	template<>
	struct _to_lua_function_helper<0> {
		static void F(lua_State* L) {
		}
	};

	// Do not invoke tostring/metamethods outside a protected Lua frame.
	inline const char* _callback_error_text(lua_State* L, int index) {
		return lua_type(L, index) == LUA_TSTRING ? lua_tostring(L, index)
			: lua_typename(L, lua_type(L, index));
	}
	inline void _callback_log_error(lua_State* L, const char* name) {
		std::fprintf(stderr, "[LUA ERROR] callback (%s): %s\n", name, _callback_error_text(L, -1));
	}
	inline int _callback_report_error(lua_State* L) {
		lua_pushfstring(L, "[LUA ERROR] callback (%s): %s",
			lua_tostring(L, lua_upvalueindex(1)), _callback_error_text(L, 1));
		// Match LuaStack's reporting hook, but protect the reporter too. Its return
		// value is irrelevant (the application's hook does not return a string).
		lua_pushliteral(L, "__G__TRACKBACK__");
		lua_rawget(L, LUA_GLOBALSINDEX);
		if (lua_isfunction(L, -1)) {
			lua_pushvalue(L, 2);
			if (lua_pcall(L, 1, 0, 0) != 0) {
				std::fprintf(stderr, "%s\n[LUA ERROR] callback reporter: %s\n",
					lua_tostring(L, 2), _callback_error_text(L, -1));
			}
		} else {
			std::fprintf(stderr, "%s\n", lua_tostring(L, 2));
		}
		lua_pushvalue(L, 2);
		return 1;
	}

	template<typename F>
	struct _callback_call {
		_callback_reference* callback;
		F* invoke;
		bool completed = false;
		static int run(lua_State* L) {
			auto* context = static_cast<_callback_call*>(lua_touserdata(L, lua_upvalueindex(1)));
			if (!context) return luaL_error(L, "expired Lua callback invocation");
			// A debug-retained trampoline must not retain a pointer to this C++ frame.
			lua_pushnil(L);
			lua_replace(L, lua_upvalueindex(1));
			(*context->invoke)(L);
			context->completed = true;
			return 0;
		}
		static int enter(lua_State* L) {
			auto* context = lua_type(L, 1) == LUA_TLIGHTUSERDATA
				? static_cast<_callback_call*>(lua_touserdata(L, 1)) : nullptr;
			if (!context) return luaL_error(L, "expired Lua callback setup");
			lua_settop(L, 0);
			context->callback->state->drain(L);
			lua_pushlstring(L, context->callback->name.data(), context->callback->name.size());
			lua_pushcclosure(L, _callback_report_error, 1);
			lua_pushlightuserdata(L, context);
			lua_pushcclosure(L, run, 1);
			const int status = lua_pcall(L, 0, 0, 1);
			if (status != 0) {
				context->completed = false;
				if (status != LUA_ERRRUN)
					_callback_log_error(L, context->callback->name.c_str());
			}
			return 0;
		}
	};

	template<typename F>
	bool _call_luafunction(const std::shared_ptr<_callback_reference>& ref, F&& invoke) {
		// All C++ owners live outside both protected frames, including when the
		// callback clears its own slot or the reporting hook triggers GC/reentry.
		auto keep = ref;
		if (!keep->state->callable()) return false;
		auto* L = keep->L;
		const int top = lua_gettop(L);
		_callback_call<F> context{ keep.get(), &invoke };
		// cpcall also protects frame setup, argument conversion and result conversion.
		if (lua_cpcall(L, _callback_call<F>::enter, &context) != 0) {
			context.completed = false;
			_callback_log_error(L, keep->name.c_str());
		}
		lua_settop(L, top);
		return context.completed;
	}

	template<typename R, typename... Targs>
	struct to_native<std::function<R(Targs...)>> {
		static bool F(lua_State* L, int lo, std::function<R(Targs...)>* outValue, const char* fName = "") {
			const int index = _absolute_index(L, lo);
			if (!outValue || !index)
				return false;
			if (lua_isnil(L, index)) {
				*outValue = nullptr;
				return true;
			}
			auto ref = _own_luafunction(L, lo, fName);
			if (!ref)
				return false;
			*outValue = [ref = std::move(ref)](Targs... args)
			{
				R ret = {};
				auto* callback = ref.get();
				const bool ok = _call_luafunction(ref, [&](lua_State* L) {
					handler_to_luafunction(L, callback->handler);
					if (!lua_isfunction(L, -1)) return;
					luaL_checkstack(L, sizeof...(Targs), "Lua callback argument stack overflow");
					_to_lua_function_helper<sizeof...(Targs), Targs...>::F(L, std::forward<Targs>(args)...);
					lua_call(L, sizeof...(Targs), 1);
					if (!luaval_to_native(L, -1, &ret, callback->name.c_str()))
						luaL_error(L, "invalid return value in handler (%s)", callback->name.c_str());
				});
				if (!ok) return R{};
				return ret;
			};
			return true;
		}
	};

	template<typename... Targs>
	struct to_native<std::function<void(Targs...)>> {
		static bool F(lua_State* L, int lo, std::function<void(Targs...)>* outValue, const char* fName = "") {
			const int index = _absolute_index(L, lo);
			if (!outValue || !index)
				return false;
			if (lua_isnil(L, index)) {
				*outValue = nullptr;
				return true;
			}
			auto ref = _own_luafunction(L, lo, fName);
			if (!ref)
				return false;
			*outValue = [ref = std::move(ref)](Targs... args)
			{
				auto* callback = ref.get();
				_call_luafunction(ref, [&](lua_State* L) {
					handler_to_luafunction(L, callback->handler);
					if (!lua_isfunction(L, -1)) return;
					luaL_checkstack(L, sizeof...(Targs), "Lua callback argument stack overflow");
					_to_lua_function_helper<sizeof...(Targs), Targs...>::F(L, std::forward<Targs>(args)...);
					lua_call(L, sizeof...(Targs), 0);
				});
			};
			return true;
		}
	};

	////////////////////////////////////////////////////////////////////////////////

	template<size_t Index, typename Callable, typename Targ = void, typename... Targs>
	struct _invoke_helper {
		template<typename... Fargs>
		static bool F(lua_State* L, int argTop, int& argCur, Callable callable, Fargs&&... args) {
			++argCur;
			using T = std::remove_cv_t<std::remove_reference_t<Targ>>;
			T arg{};
			if (!luaval_to_native(L, argTop + 1 - Index, &arg))
				return false;
			if constexpr (std::is_member_function_pointer_v<Callable> && sizeof...(Fargs) == 0) {
				if (!arg)
					return false;
			}
			static_assert(Index > 0);
			return _invoke_helper<Index - 1, Callable, Targs...>::template F<Fargs..., Targ>(L, argTop, argCur, callable, std::forward<Fargs>(args)..., std::forward<Targ>(arg));
		}
	};

	inline void _invoke_in_frame(lua_State* L, int nargs, lua_CFunction entry, void* context) {
		// retain args in the outer frame until invoke completes to avoid GC issues
		const int top = lua_gettop(L);
		const int prefix = top - nargs;
		luaL_checkstack(L, prefix + 2, "native invocation stack overflow");
		lua_pushlightuserdata(L, context); // ...prefix, ...args, context(call)
		lua_pushcclosure(L, entry, 1); // ...prefix, ...args, closure
		// reproduce the stack:
		// ...prefix, ...args, closure, ...prefix
		for (int i = 1; i <= prefix; ++i)
			lua_pushvalue(L, i);
		// inner may clear its stack
		lua_call(L, prefix, LUA_MULTRET); // ...prefix, ...args, ...prefix?, ...result
		// ...prefix?, ...result
		for (int i = 0; i < top; ++i)
			lua_remove(L, 1);
	}

	template<typename F>
	int _invoke_frame_entry(lua_State* L) {
		auto* call = static_cast<F*>(lua_touserdata(L, lua_upvalueindex(1)));
		if (!call)
			return luaL_error(L, "expired native invocation");
		// debug code can retain the closure and may cause UB, so make it expire
		lua_pushnil(L);
		lua_replace(L, lua_upvalueindex(1));
		return (*call)(L);
	}

	template<typename Callable>
	struct _invoke_helper<0, Callable> {
		template<typename... Fargs>
		static bool F(lua_State* L, int argTop, int& argCur, Callable callable, Fargs&&... args) {
			auto invoke = [&](lua_State* state) {
				if constexpr (std::is_same_v<std::invoke_result_t<Callable, Fargs...>, void>)
					std::invoke(callable, std::forward<Fargs>(args)...);
				else
					native_to_luaval(state, std::invoke(callable, std::forward<Fargs>(args)...));
				return lua_gettop(state);
			};
			_invoke_in_frame(L, static_cast<int>(sizeof...(Fargs)), _invoke_frame_entry<decltype(invoke)>, &invoke);
			return true;
		}
	};

	template<typename T>
	struct invoke {};

	template<typename R, typename... Targs>
	struct invoke<std::function<R(Targs...)>> {
		using callable_t = std::function<R(Targs...)>;
		static bool F(lua_State* L, callable_t callable, int& argCur)
		{
			constexpr size_t narg = sizeof...(Targs);
			const auto top = lua_gettop(L);
			if (top < narg)
				return false;
			argCur = 0;
			return _invoke_helper<narg, callable_t, Targs...>::F(L, top, argCur, callable);
		}
	};

	template<typename R, typename... Targs>
	struct invoke<R(*)(Targs...)> {
		using callable_t = std::function<R(Targs...)>;
		static bool F(lua_State* L, callable_t callable, int& argCur)
		{
			constexpr size_t narg = sizeof...(Targs);
			const auto top = lua_gettop(L);
			if (top < narg)
				return false;
			argCur = 0;
			return _invoke_helper<narg, callable_t, Targs...>::F(L, top, argCur, callable);
		}
	};

	template<typename C, typename R, typename... Targs>
	struct invoke<R(C::*)(Targs...)> {
		using callable_t = R(C::*)(Targs...);
		static bool F(lua_State* L, callable_t callable, int& argCur)
		{
			constexpr size_t narg = sizeof...(Targs);
			const auto top = lua_gettop(L);
			if (top < narg + 1)
				return false;
			argCur = -1;
			return _invoke_helper<narg + 1, callable_t, C*, Targs...>::F(L, top, argCur, callable);
		}
	};

	template<typename C, typename R, typename... Targs>
	struct invoke<R(C::*)(Targs...) const> {
		using callable_t = R(C::*)(Targs...) const;
		static bool F(lua_State* L, callable_t callable, int& argCur)
		{
			constexpr size_t narg = sizeof...(Targs);
			const auto top = lua_gettop(L);
			if (top < narg + 1)
				return false;
			argCur = -1;
			return _invoke_helper<narg + 1, callable_t, const C*, Targs...>::F(L, top, argCur, callable);
		}
	};

	template <typename Function>
	struct function_traits : public function_traits<decltype(&Function::operator())> {};

	template <typename ClassType, typename ReturnType, typename... Args>
	struct function_traits<ReturnType(ClassType::*)(Args...) const> {
		typedef ReturnType(*pointer)(Args...);
		typedef std::function<ReturnType(Args...)> function;
	};

	template<typename T>
	bool invoke_native(lua_State* L, int& argCur, T callable)
	{
		if constexpr (std::is_class_v<T>)
			return invoke<typename function_traits<T>::function>::F(L, callable, argCur);
		else
			return invoke<T>::F(L, callable, argCur);
	}

	template<typename R, typename... Targs>
	struct to_lua<std::function<R(Targs...)>> {
		using type = std::function<R(Targs...)>;
	private:
		struct userdata {
			type* value;
			alignas(type) unsigned char storage[sizeof(type)];
		};
		static void* metatable_key() {
			static char key;
			return &key;
		}
		static userdata* get(lua_State* L) {
			if (lua_type(L, 1) != LUA_TUSERDATA || lua_objlen(L, 1) != sizeof(userdata)
				|| !lua_getmetatable(L, 1))
				return nullptr;
			lua_pushlightuserdata(L, metatable_key());
			lua_rawget(L, LUA_REGISTRYINDEX);
			const bool matches = lua_rawequal(L, -1, -2) != 0;
			lua_pop(L, 2);
			return matches ? static_cast<userdata*>(lua_touserdata(L, 1)) : nullptr;
		}
		static int collect(lua_State* L) {
			auto* p = get(L);
			if (p && p->value) {
				auto* value = p->value;
				p->value = nullptr; // invalidate before destruction, fix reentrant __gc
				value->~type();
			}
			return 0;
		}
		static int call(lua_State* L) {
			auto* p = get(L);
			if (!p)
				return luaL_error(L, "invalid std::function object");
			if (!p->value)
				return luaL_error(L, "expired std::function object");
			if (!*p->value)
				return 0;
			int cur = 0;
			if (!invoke_native(L, cur, *p->value))
				return luaL_error(L, "invalid parameter %d", cur);
			return std::is_same_v<R, void> ? 0 : 1;
		}
	public:
		static void F(lua_State* L, const type& inValue) {
			if (!L) return;
			lua_pushlightuserdata(L, metatable_key());
			lua_rawget(L, LUA_REGISTRYINDEX);
			if (lua_isnil(L, -1)) {
				lua_pop(L, 1);
				lua_createtable(L, 0, 2);
				lua_pushcfunction(L, call);
				lua_setfield(L, -2, "__call");
				lua_pushcfunction(L, collect);
				lua_setfield(L, -2, "__gc");
				lua_pushlightuserdata(L, metatable_key());
				lua_pushvalue(L, -2);
				lua_rawset(L, LUA_REGISTRYINDEX);
			}
			auto* p = new (lua_newuserdata(L, sizeof(userdata))) userdata{};
			lua_insert(L, -2);
			lua_setmetatable(L, -2);
			// construct after all lua allocations so an exception here leaves an inert userdata
			p->value = new (p->storage) type(inValue);
		}
	};
}

////////////////////////////////////////////////////////////////////////////////

#define LUA_TO_NATIVE_STRUCT2(T, Field1, Field2) \
	template<>\
	struct to_native<T> {\
		static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {\
			LUA_CHECK_TO_NATIVE;\
			if (!is_indexable(L, lo)) return false;\
			T v;\
			bool ok = luaval_field_to_native(L, lo, #Field1, &v.Field1, fName) &&\
				luaval_field_to_native(L, lo, #Field2, &v.Field2, fName);\
			if (ok) *outValue = v;\
			return ok;\
		}\
	};

#define LUA_TO_NATIVE_STRUCT3(T, Field1, Field2, Field3) \
	template<>\
	struct to_native<T> {\
		static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {\
			LUA_CHECK_TO_NATIVE;\
			if (!is_indexable(L, lo)) return false;\
			T v;\
			bool ok = luaval_field_to_native(L, lo, #Field1, &v.Field1, fName) &&\
				luaval_field_to_native(L, lo, #Field2, &v.Field2, fName) &&\
				luaval_field_to_native(L, lo, #Field3, &v.Field3, fName);\
			if (ok) *outValue = v;\
			return ok;\
		}\
	};

#define LUA_TO_NATIVE_STRUCT4(T, Field1, Field2, Field3, Field4) \
	template<>\
	struct to_native<T> {\
		static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {\
			LUA_CHECK_TO_NATIVE;\
			if (!is_indexable(L, lo)) return false;\
			T v;\
			bool ok = luaval_field_to_native(L, lo, #Field1, &v.Field1, fName) &&\
				luaval_field_to_native(L, lo, #Field2, &v.Field2, fName) &&\
				luaval_field_to_native(L, lo, #Field3, &v.Field3, fName) &&\
				luaval_field_to_native(L, lo, #Field4, &v.Field4, fName);\
			if (ok) *outValue = v;\
			return ok;\
		}\
	};

#define LUA_TO_LUA_STRUCT2(T, Field1, Field2) \
	template<>\
	struct to_lua<T> {\
		static void F(lua_State* L, const T& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 2);\
			native_to_luaval_field(L, -1, #Field1, inValue.Field1);\
			native_to_luaval_field(L, -1, #Field2, inValue.Field2);\
		}\
	};

#define LUA_TO_LUA_STRUCT3(T, Field1, Field2, Field3) \
	template<>\
	struct to_lua<T> {\
		static void F(lua_State* L, const T& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 3);\
			native_to_luaval_field(L, -1, #Field1, inValue.Field1);\
			native_to_luaval_field(L, -1, #Field2, inValue.Field2);\
			native_to_luaval_field(L, -1, #Field3, inValue.Field3);\
		}\
	};

#define LUA_TO_LUA_STRUCT4(T, Field1, Field2, Field3, Field4) \
	template<>\
	struct to_lua<T> {\
		static void F(lua_State* L, const T& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 4);\
			native_to_luaval_field(L, -1, #Field1, inValue.Field1);\
			native_to_luaval_field(L, -1, #Field2, inValue.Field2);\
			native_to_luaval_field(L, -1, #Field3, inValue.Field3);\
			native_to_luaval_field(L, -1, #Field4, inValue.Field4);\
		}\
	};

#define LUA_TO_LUA_STRUCT5(T, Field1, Field2, Field3, Field4, Field5) \
	template<>\
	struct to_lua<T> {\
		static void F(lua_State* L, const T& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 5);\
			native_to_luaval_field(L, -1, #Field1, inValue.Field1);\
			native_to_luaval_field(L, -1, #Field2, inValue.Field2);\
			native_to_luaval_field(L, -1, #Field3, inValue.Field3);\
			native_to_luaval_field(L, -1, #Field4, inValue.Field4);\
			native_to_luaval_field(L, -1, #Field5, inValue.Field5);\
		}\
	};

#define LUA_TO_LUA_STRUCT6(T, Field1, Field2, Field3, Field4, Field5, Field6) \
	template<>\
	struct to_lua<T> {\
		static void F(lua_State* L, const T& inValue) {\
			if (!L) return;\
			lua_createtable(L, 0, 6);\
			native_to_luaval_field(L, -1, #Field1, inValue.Field1);\
			native_to_luaval_field(L, -1, #Field2, inValue.Field2);\
			native_to_luaval_field(L, -1, #Field3, inValue.Field3);\
			native_to_luaval_field(L, -1, #Field4, inValue.Field4);\
			native_to_luaval_field(L, -1, #Field5, inValue.Field5);\
			native_to_luaval_field(L, -1, #Field6, inValue.Field6);\
		}\
	};
