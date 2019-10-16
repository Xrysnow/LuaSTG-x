#pragma once
#include "UtilLua.h"
#include <cstdint>
#include <array>
#include <vector>
#include <forward_list>
#include <tuple>
#include <bitset>
#include <type_traits>

namespace lstg
{
	namespace lua
	{
		template<typename T, class Enable = void> struct to_native {};

#define CHECK_TO_NATIVE const auto top = lua_gettop(L); if (nullptr == L || nullptr == outValue || top < lo) return false;

#define TO_NATIVE_BASIC(_F, _T) template<>\
		struct to_native<_T> {\
			static bool F(lua_State* L, int lo, _T* outValue, const char* fName = "") {\
				return lua::_F(L, lo, outValue, fName); } };

#define TO_NATIVE_BASIC_PTR(_T) template<>\
		struct to_native<_T*> {\
			static bool F(lua_State* L, int lo, _T** outValue, const char* fName = "") {\
				return lua::luaval_to_cptr(L, lo, (void**)outValue); } };

#define TO_NATIVE_VECTOR(_Ty, _Setter) template<typename T>\
		struct to_native<_Ty<T>> {\
			static bool F(lua_State* L, int lo, _Ty<T>* outValue, const char* fName = "") {\
				CHECK_TO_NATIVE;\
				const auto type = lua_type(L, lo);\
				if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))\
					return false;\
				const size_t len = lua_objlen(L, lo);\
				T value;\
				bool ok = true;\
				for (size_t i = 0; i < len; i++) {\
					lua_pushnumber(L, i + 1);\
					lua_gettable(L, lo);\
					ok &= to_native<T>::F(L, top, &value, fName);\
					lua_pop(L, 1);\
					if (ok)\
						outValue->_Setter(value);\
					else\
						break;\
				}\
				return true; } };

#define TO_NATIVE_MAP(_Ty, _Setter) template<typename K, typename V>\
		struct to_native<_Ty<K, V>> {\
			static bool F(lua_State* L, int lo, _Ty<K, V>* outValue, const char* fName = "") {\
				CHECK_TO_NATIVE;\
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
				int64_t i; bool ret = _luaval_to_integer(L, lo, &i, sizeof(_T), funcName);\
				if (ret) *outValue = (_T)(i); return ret; } }
#define TO_NATIVE_UNSIGNED(_T) template<>\
		struct to_native<_T> {\
			static bool F(lua_State* L, int lo, _T* outValue, const char* funcName = ""){\
				uint64_t i; bool ret = _luaval_to_unsigned_integer(L, lo, &i, sizeof(_T), funcName);\
				if (ret) *outValue = (_T)(i); return ret; } }

		template<typename T>
		struct to_native<T, typename std::enable_if<std::is_enum<T>::value>::type> {
			static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				using type = std::underlying_type_t<T>;
				type value;
				auto ok = to_native<type>::F(L, lo, &value, fName);
				if (ok) *outValue = (T)value;
				return ok;
			}
		};

		TO_NATIVE_SIGNED(int8_t);
		TO_NATIVE_SIGNED(int16_t);
		TO_NATIVE_SIGNED(int32_t);
		TO_NATIVE_SIGNED(int64_t);
		TO_NATIVE_UNSIGNED(uint8_t);
		TO_NATIVE_UNSIGNED(uint16_t);
		TO_NATIVE_UNSIGNED(uint32_t);
		TO_NATIVE_UNSIGNED(uint64_t);

		TO_NATIVE_BASIC(luaval_to_boolean, bool);
		TO_NATIVE_BASIC(luaval_to_number, double);

		TO_NATIVE_BASIC_PTR(bool);
		TO_NATIVE_BASIC_PTR(char);
		TO_NATIVE_BASIC_PTR(int8_t);
		TO_NATIVE_BASIC_PTR(int16_t);
		TO_NATIVE_BASIC_PTR(int32_t);
		TO_NATIVE_BASIC_PTR(int64_t);
		TO_NATIVE_BASIC_PTR(uint8_t);
		TO_NATIVE_BASIC_PTR(uint16_t);
		TO_NATIVE_BASIC_PTR(uint32_t);
		TO_NATIVE_BASIC_PTR(uint64_t);
		TO_NATIVE_BASIC_PTR(float);
		TO_NATIVE_BASIC_PTR(double);
		//
		TO_NATIVE_BASIC(luaval_to_vec2, cocos2d::Vec2);
		TO_NATIVE_BASIC(luaval_to_vec3, cocos2d::Vec3);
		TO_NATIVE_BASIC(luaval_to_vec4, cocos2d::Vec4);
		TO_NATIVE_BASIC(luaval_to_size, cocos2d::Size);
		TO_NATIVE_BASIC(luaval_to_rect, cocos2d::Rect);
		TO_NATIVE_BASIC(luaval_to_color3b, cocos2d::Color3B);
		TO_NATIVE_BASIC(luaval_to_color4b, cocos2d::Color4B);
		TO_NATIVE_BASIC(luaval_to_color4f, cocos2d::Color4F);
		TO_NATIVE_BASIC(luaval_to_mat4, cocos2d::Mat4);
		TO_NATIVE_BASIC(luaval_to_affinetransform, cocos2d::AffineTransform);
		TO_NATIVE_BASIC(luaval_to_fontdefinition, cocos2d::FontDefinition);
		TO_NATIVE_BASIC(luaval_to_blendfunc, cocos2d::BlendFunc);
		TO_NATIVE_BASIC(luaval_to_ttfconfig, cocos2d::TTFConfig);
		TO_NATIVE_BASIC(luaval_to_uniform, cocos2d::Uniform);
		TO_NATIVE_BASIC(luaval_to_vertexattrib, cocos2d::VertexAttrib);
		TO_NATIVE_BASIC(luaval_to_ccvalue, cocos2d::Value);
		TO_NATIVE_BASIC(luaval_to_mesh_vertex_attrib, cocos2d::MeshVertexAttrib);
		TO_NATIVE_BASIC(luaval_to_quaternion, cocos2d::Quaternion);
		TO_NATIVE_BASIC(luaval_to_texparams, cocos2d::Texture2D::TexParams);
		//TO_NATIVE_BASIC(luaval_to_v3f_c4b_t2f, cocos2d::V3F_C4B_T2F);
		//TO_NATIVE_BASIC(luaval_to_tex2f, cocos2d::Tex2F);
		//
		TO_NATIVE_BASIC(luaval_to_V3F_C4B_T2F_Quad, cocos2d::V3F_C4B_T2F_Quad);
		TO_NATIVE_BASIC(luaval_to_BlendMode, BlendMode*);
		TO_NATIVE_BASIC(luaval_to_ColliderType, XColliderType);

		template<>
		struct to_native<float> {
			static bool F(lua_State* L, int lo, float* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				double v;
				const auto ok = to_native<double>::F(L, lo, &v, fName);
				if (ok) *outValue = (float)v;
				return ok;
			}
		};

		template<>
		struct to_native<const char*> {
			static bool F(lua_State* L, int lo, const char** outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				if (!lua_isstring(L, lo))
					return false;
				*outValue = lua_tolstring(L, lo, nullptr);
				return true;
			}
		};

		template<>
		struct to_native<std::string> {
			static bool F(lua_State* L, int lo, std::string* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				if (!lua_isstring(L, lo))
					return false;
				size_t size;
				const auto str = lua_tolstring(L, lo, &size);
				outValue->assign(str, size);
				return true;
			}
		};

		template<typename T>
		struct to_native<T*, typename std::enable_if<std::is_base_of<cocos2d::Ref, T>::value>::type> {
			static bool F(lua_State* L, int lo, T** outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				if(lua_isnil(L, lo)) {
					*outValue = nullptr;
					return true;
				}
				auto className = getClassNameByTypeID(typeid(T).name());
				if (className.empty()) className = "cc.Ref";
				if (!isusertype(L, lo, className.c_str()))
					return false;
				const auto u = lua_touserdata(L, lo);
				if (!u)
					return false; //note: return false when userdata is null
				*outValue = static_cast<T*>(*(void**)u);
				return true;
			}
		};

		template<typename T>
		struct to_native<T*, typename std::enable_if<!std::is_base_of<cocos2d::Ref, T>::value>::type> {
			static bool F(lua_State* L, int lo, T** outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				if(lua_isnil(L, lo)) {
					*outValue = nullptr;
					return true;
				}
				auto p = (T*)_tousertype(L, lo); //note: return false when userdata is null
				if (!p)
					return false;
				*outValue = p;
				return true;
			}
		};

		template<typename T, size_t Size>
		struct to_native<std::array<T, Size>> {
			static bool F(lua_State* L, int lo, std::array<T, Size>* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				const auto type = lua_type(L, lo);
				if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
					return false;
				const size_t len = std::min(lua_objlen(L, lo), Size);
				T value;
				bool ok = true;
				for (size_t i = 0; i < len; i++) {
					lua_pushnumber(L, i + 1);
					lua_gettable(L, lo);
					ok &= to_native<T>::F(L, top, &value, fName);
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
				CHECK_TO_NATIVE;
				const auto type = lua_type(L, lo);
				if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
					return false;
				T1 value1; T2 value2;
				bool ok = true;
				lua_pushnumber(L, 1);
				lua_gettable(L, lo);
				ok &= to_native<T1>::F(L, top, &value1, fName);
				lua_pop(L, 1);
				if (ok)
					outValue->first = value1;
				else
					return false;
				lua_pushnumber(L, 2);
				lua_gettable(L, lo);
				ok &= to_native<T2>::F(L, top, &value2, fName);
				lua_pop(L, 1);
				if (ok)
					outValue->second = value2;
				return ok;
			}
		};

		template<size_t Index, typename ...Targs>
		struct _to_native_tuple_helper {
			static bool F(lua_State* L, int idx, std::tuple<Targs...>* outValue, const char* fName) {
				using type = typename std::tuple_element<Index - 1, std::tuple<Targs...>>::type;
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
				CHECK_TO_NATIVE;
				const auto type = lua_type(L, lo);
				if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
					return false;
				constexpr size_t size = std::tuple_size<tuple_type>::value;
				return _to_native_tuple_helper<size, Types...>::F(L, lo, outValue, fName);
			}
		};

		template<size_t Size>
		struct to_native<std::bitset<Size>> {
			static bool F(lua_State* L, int lo, std::bitset<Size>* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				const auto type = lua_type(L, lo);
				if (!(type == LUA_TTABLE || type == LUA_TUSERDATA || type == LUA_TCDATA))
					return false;
				const size_t len = std::min(lua_objlen(L, lo), Size);
				bool value;
				bool ok = true;
				for (size_t i = 0; i < len; i++) {
					lua_pushnumber(L, i + 1);
					lua_gettable(L, lo);
					ok &= to_native<bool>::F(L, top, &value, fName);
					lua_pop(L, 1);
					if (ok)
						outValue->set(i, value);
					else
						break;
				}
				return true;
			}
		};

		TO_NATIVE_VECTOR(cocos2d::Vector, pushBack);
		TO_NATIVE_VECTOR(std::vector, push_back);
		TO_NATIVE_VECTOR(std::deque, push_back);
		TO_NATIVE_VECTOR(std::forward_list, push_front);
		TO_NATIVE_VECTOR(std::list, push_back);
		TO_NATIVE_VECTOR(std::set, insert);
		TO_NATIVE_VECTOR(std::multiset, insert);
		TO_NATIVE_VECTOR(std::unordered_set, insert);
		TO_NATIVE_VECTOR(std::unordered_multiset, insert);
		TO_NATIVE_VECTOR(std::stack, push);
		TO_NATIVE_VECTOR(std::queue, push);
		TO_NATIVE_VECTOR(std::priority_queue, push);

		TO_NATIVE_MAP(cocos2d::Map, .insert(key, value));
		TO_NATIVE_MAP(std::map, [key] = value);
		TO_NATIVE_MAP(std::unordered_map, [key] = value);
		TO_NATIVE_MAP(std::multimap, .emplace(key, value));
		TO_NATIVE_MAP(std::unordered_multimap, .emplace(key, value));

		template<typename T>
		bool luaval_to_native(lua_State* L, int lo, T* outValue, const char* fName = "") {
			return to_native<T>::F(L, lo, outValue, fName);
		}

#undef CHECK_TO_NATIVE
#undef TO_NATIVE_BASIC
#undef TO_NATIVE_BASIC_PTR
#undef TO_NATIVE_VECTOR
#undef TO_NATIVE_MAP
#undef TO_NATIVE_SIGNED
#undef TO_NATIVE_UNSIGNED

		////////////////////////////////////////////////////////////////////////////////

		template<typename T, class Enable = void> struct to_lua {};

#define TO_LUA_BASIC(_F, _T) template<>\
		struct to_lua<_T> {\
			static void F(lua_State* L, const _T& inValue) {\
				lua::_F(L, inValue); } };

#define TO_LUA_BASIC_P(_F, _T) template<>\
		struct to_lua<_T*> {\
			static void F(lua_State* L, _T* inValue) {\
				lua::_F(L, inValue); } };

#define TO_LUA_BASIC_PTR(_T) template<>\
		struct to_lua<_T*> {\
			static void F(lua_State* L, _T* inValue) {\
				lua::cptr_to_luaval(L, (void*)inValue, #_T "*"); } };

#define TO_LUA_VECTOR(_Ty) template<typename T>\
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

#define TO_LUA_MAP(_Ty) template<typename K, typename V>\
		struct to_lua<_Ty<K, V>> {\
			static void F(lua_State* L, const _Ty<K, V>& inValue) {\
				if (!L) return;\
				lua_createtable(L, 0, 0);\
				for (auto& it : inValue) {\
					to_lua<K>::F(L, it.first);\
					to_lua<V>::F(L, it.second);\
					lua_rawset(L, -3);\
				} } };

		TO_LUA_BASIC_PTR(bool);
		TO_LUA_BASIC_PTR(char);
		TO_LUA_BASIC_PTR(int8_t);
		TO_LUA_BASIC_PTR(int16_t);
		TO_LUA_BASIC_PTR(int32_t);
		TO_LUA_BASIC_PTR(int64_t);
		TO_LUA_BASIC_PTR(uint8_t);
		TO_LUA_BASIC_PTR(uint16_t);
		TO_LUA_BASIC_PTR(uint32_t);
		TO_LUA_BASIC_PTR(uint64_t);
		TO_LUA_BASIC_PTR(float);
		TO_LUA_BASIC_PTR(double);

		TO_LUA_BASIC(vec2_to_luaval, cocos2d::Vec2);
		TO_LUA_BASIC(vec3_to_luaval, cocos2d::Vec3);
		TO_LUA_BASIC(vec4_to_luaval, cocos2d::Vec4);
		TO_LUA_BASIC(size_to_luaval, cocos2d::Size);
		TO_LUA_BASIC(rect_to_luaval, cocos2d::Rect);
		TO_LUA_BASIC(color3b_to_luaval, cocos2d::Color3B);
		TO_LUA_BASIC(color4b_to_luaval, cocos2d::Color4B);
		TO_LUA_BASIC(color4f_to_luaval, cocos2d::Color4F);
		TO_LUA_BASIC(mat4_to_luaval, cocos2d::Mat4);
		TO_LUA_BASIC(affinetransform_to_luaval, cocos2d::AffineTransform);
		TO_LUA_BASIC(fontdefinition_to_luaval, cocos2d::FontDefinition);
		TO_LUA_BASIC(blendfunc_to_luaval, cocos2d::BlendFunc);
		TO_LUA_BASIC(ttfconfig_to_luaval, cocos2d::TTFConfig);
		TO_LUA_BASIC(uniform_to_luaval, cocos2d::Uniform);
		TO_LUA_BASIC(vertexattrib_to_luaval, cocos2d::VertexAttrib);
		TO_LUA_BASIC(ccvalue_to_luaval, cocos2d::Value);
		TO_LUA_BASIC(mesh_vertex_attrib_to_luaval, cocos2d::MeshVertexAttrib);
		TO_LUA_BASIC(quaternion_to_luaval, cocos2d::Quaternion);
		TO_LUA_BASIC(texParams_to_luaval, cocos2d::Texture2D::TexParams);
		//
		TO_LUA_BASIC(V3F_C4B_T2F_Quad_to_luaval, cocos2d::V3F_C4B_T2F_Quad);
		TO_LUA_BASIC_P(BlendMode_to_luaval, BlendMode);
		TO_LUA_BASIC(ColliderType_to_luaval, XColliderType);

		template<>
		struct to_lua<bool> {
			static void F(lua_State* L, bool inValue) {
				if (!L) return;
				lua_pushboolean(L, inValue);
			}
		};

		template<typename T>
		struct to_lua<T, typename std::enable_if<std::is_arithmetic<T>::value>::type> {
			static void F(lua_State* L, T inValue) {
				if (!L) return;
				lua_pushnumber(L, (lua_Number)inValue);
			}
		};

		template<typename T>
		struct to_lua<T, typename std::enable_if<std::is_enum<T>::value>::type> {
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

		template<typename T>
		struct to_lua<T*, typename std::enable_if<std::is_base_of<cocos2d::Ref, T>::value>::type> {
			static void F(lua_State* L, T* inValue) {
				if (!L) return;
				ref_type_to_luaval(L, (cocos2d::Ref*)inValue, typeid(T).name());
			}
		};

		template<typename T>
		struct to_lua<T*, typename std::enable_if<!std::is_base_of<cocos2d::Ref, T>::value>::type> {
			static void F(lua_State* L, T* inValue) {
				if (!L) return;
				if(!inValue) { lua_pushnil(L); return; }
				const auto className = getClassNameByTypeID(typeid(T).name());
				if(className.empty()) { lua_pushnil(L); return; }
				lua_getfield(L, LUA_REGISTRYINDEX, className.c_str());
				if (lua_isnil(L, -1)) // leave nil on stack
					return;
;				tolua_pushusertype(L, (void*)inValue, className.c_str());
			}
		};

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
				using type = typename std::tuple_element<Index - 1, std::tuple<Targs...>>::type;
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
				constexpr size_t size = std::tuple_size<tuple_type>::value;
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

		TO_LUA_VECTOR(cocos2d::Vector);
		TO_LUA_VECTOR(std::vector);
		TO_LUA_VECTOR(std::deque);
		TO_LUA_VECTOR(std::forward_list);
		TO_LUA_VECTOR(std::list);
		TO_LUA_VECTOR(std::set);
		TO_LUA_VECTOR(std::multiset);
		TO_LUA_VECTOR(std::unordered_set);
		TO_LUA_VECTOR(std::unordered_multiset);

		TO_LUA_MAP(cocos2d::Map);
		TO_LUA_MAP(std::map);
		TO_LUA_MAP(std::unordered_map);
		TO_LUA_MAP(std::multimap);
		TO_LUA_MAP(std::unordered_multimap);

		template<typename T>
		void native_to_luaval(lua_State* L, T inValue) {
			to_lua<T>::F(L, inValue);
		}

#undef TO_LUA_BASIC
#undef TO_LUA_BASIC_P
#undef TO_LUA_BASIC_PTR
#undef TO_LUA_VECTOR
#undef TO_LUA_MAP
	}
}
