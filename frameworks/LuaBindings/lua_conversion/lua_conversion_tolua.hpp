#pragma once
#include "tolua++.h"
#include "tolua_fix.h"
#include <array>
#include <bitset>
#include <cstdint>
#include <deque>
#include <forward_list>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
        if (lua_istable(L, lo)) {
            lua_pushstring(L, ".c_instance");
            lua_gettable(L, lo);
            if (lua_isuserdata(L, -1)) {
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
        if (lo < 0)
            lo = lua_gettop(L) + lo + 1;
        if (lo <= 0)
            return 0;
        if (!lua_isuserdata(L, lo)) {
            if (!push_table_instance(L, lo)) {
                return 0;
            }
        }
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
            }
        }
        return 0;
    }

    inline void* _tousertype(lua_State* L, int lo)
    {
        if (!lua_isuserdata(L, lo)) {
            if (!push_table_instance(L, lo))
                return nullptr;
        }
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

	inline bool luaval_to_cptr(lua_State* L, int lo, void** outValue)
	{
		const auto top = lua_gettop(L);
		if (lo < 0)
			lo = top + 1 + lo;
		if (lo < 1 || lo > top)
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
			*outValue = (T)tolua_tonumber(L, lo, 0);
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
		const int handler = toluafix_ref_function(L, lo, 0);
		if (handler == 0)
			return 0;
		std::string key;
		if (fName) key = fName;
		if (!key.empty()) {
			key += "::" + std::to_string(lo);
			lua_pushstring(L, TOLUA_REFID_FUNCTION_MAPPING);
			lua_rawget(L, LUA_REGISTRYINDEX); // ... t
			lua_pushlstring(L, key.c_str(), key.size()); // ... t k
			lua_rawget(L, -2); // ... t v
			if (lua_isnumber(L, -1))
				toluafix_remove_function_by_refid(L, (int)lua_tointeger(L, -1));
			lua_pop(L, 1); // ... t
			lua_pushlstring(L, key.c_str(), key.size()); // ... t k
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

    ////////////////////////////////////////////////////////////////////////////////

	template<typename T, class Enable = void> struct to_native {};

#define LUA_CHECK_TO_NATIVE\
	const auto top = lua_gettop(L);\
	do {\
		if (nullptr == L || nullptr == outValue || top < lo)\
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
		if (lo < 0) lo += lua_gettop(L) + 1;
		lua_pushstring(L, field);
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_field_to_native(lua_State* L, int lo, const std::string& field, T* outValue, const char* fName = "") {
		if (lo < 0) lo += lua_gettop(L) + 1;
		lua_pushlstring(L, field.c_str(), field.size());
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_field_to_native(lua_State* L, int lo, int field, T* outValue, const char* fName = "") {
		if (lo < 0) lo += lua_gettop(L) + 1;
		lua_pushinteger(L, field);
		lua_gettable(L, lo);
		const bool ret = to_native<T>::F(L, -1, outValue, fName);
		lua_pop(L, 1);
		return ret;
	}

	template<typename T>
	bool luaval_to_native_array(lua_State* L, int lo, T* outValue, size_t size, const char* fName = "") {
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
		if (lo < 0) lo += lua_gettop(L) + 1;
		lua_pushstring(L, field);
		to_lua<type>::F(L, inValue);
		lua_settable(L, lo);
	}

	template<typename T>
	void native_to_luaval_field(lua_State* L, int lo, const std::string& field, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		if (lo < 0) lo += lua_gettop(L) + 1;
		lua_pushlstring(L, field.c_str(), field.size());
		to_lua<type>::F(L, inValue);
		lua_settable(L, lo);
	}

	template<typename T>
	void native_to_luaval_field(lua_State* L, int lo, int field, T&& inValue) {
		using type = std::remove_cv_t<std::remove_reference_t<T>>;
		if (lo < 0) lo += lua_gettop(L) + 1;
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

	template<typename R, typename... Targs>
	struct to_native<std::function<R(Targs...)>> {
		static bool F(lua_State* L, int lo, std::function<R(Targs...)>* outValue, const char* fName = "") {
			const auto top = lua_gettop(L);
			if (nullptr == L || nullptr == outValue || top < lo)
				return false;
			if (lua_isnil(L, lo)) {
				*outValue = nullptr;
				return true;
			}
			const int handler = luafunction_to_handler(L, lo, fName);
			if (handler == 0)
				return false;
			*outValue = [=](Targs... args)
			{
				R ret = {};
				handler_to_luafunction(L, handler);
				if (!lua_isfunction(L, -1)) {
					lua_pop(L, 1);
					return ret;
				}
				_to_lua_function_helper<sizeof...(Targs), Targs...>::F(L, std::forward<Targs>(args)...);
				lua_call(L, sizeof...(Targs), 1);
				if (!luaval_to_native(L, -1, &ret, fName))
					luaL_error(L, "invalid return value in handler (%s)", fName);
				return ret;
			};
			return true;
		}
	};

	template<typename... Targs>
	struct to_native<std::function<void(Targs...)>> {
		static bool F(lua_State* L, int lo, std::function<void(Targs...)>* outValue, const char* fName = "") {
			const auto top = lua_gettop(L);
			if (nullptr == L || nullptr == outValue || top < lo)
				return false;
			if (lua_isnil(L, lo)) {
				*outValue = nullptr;
				return true;
			}
			const int handler = luafunction_to_handler(L, lo, fName);
			if (handler == 0)
				return false;
			*outValue = [=](Targs... args)
			{
				handler_to_luafunction(L, handler);
				if (!lua_isfunction(L, -1)) {
					lua_pop(L, 1);
					return;
				}
				_to_lua_function_helper<sizeof...(Targs), Targs...>::F(L, std::forward<Targs>(args)...);
				lua_call(L, sizeof...(Targs), 0);
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
			static_assert(Index > 0);
			return _invoke_helper<Index - 1, Callable, Targs...>::template F<Fargs..., Targ>(L, argTop, argCur, callable, std::forward<Fargs>(args)..., std::forward<Targ>(arg));
		}
	};

	template<typename Callable>
	struct _invoke_helper<0, Callable> {
		template<typename... Fargs>
		static bool F(lua_State* L, int argTop, int& argCur, Callable callable, Fargs&&... args) {
			lua_pop(L, static_cast<int>(sizeof...(Fargs)));
			if constexpr (std::is_same_v<std::invoke_result_t<Callable, Fargs...>, void>)
				std::invoke(callable, std::forward<Fargs>(args)...);
			else
				native_to_luaval(L, std::invoke(callable, std::forward<Fargs>(args)...));
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
		static void F(lua_State* L, const type& inValue) {
			if (!L) return;
			struct wrapper
			{
				static int invoke(lua_State* state) {
					auto p = (type*)lua_touserdata(state, 1);
					if (!p || !*p)
						return 0;
					int cur = 0;
					if (!invoke_native(state, cur, *p))
						return luaL_error(state, "invalid parameter %d", cur);
					return std::is_same_v<R, void> ? 0 : 1;
				}
			};
			auto p = (type*)lua_newuserdata(L, sizeof(type));
			*p = inValue;
			lua_createtable(L, 0, 1);
			lua_pushliteral(L, "__call");
			lua_pushcfunction(L, wrapper::invoke);
			lua_rawset(L, -3);
			lua_setmetatable(L, -2);
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
