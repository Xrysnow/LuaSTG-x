#pragma once
#include "Global.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "BlendMode.h"
#include "GameObjectBentLaser.h"
#include "../Math/XCollision.h"
#include <forward_list>

#define luaL_checkfloat(L, n) ((float)luaL_checknumber(L, n))
#define luaL_newcolor(L) (static_cast<cocos2d::Color4B*>(lua_newuserdata(L, sizeof(cocos2d::Color4B))))
#define luaL_checkcolor(L, n) (static_cast<cocos2d::Color4B*>(luaL_checkudata(L, n, TYPENAME_COLOR)))

namespace lstg {
	struct GameObject;
}

namespace lstg
{
	namespace lua
	{
		constexpr int LUA_TPROTO = LUA_TTHREAD + 1;
		constexpr int LUA_TCDATA = LUA_TTHREAD + 2;

		// support cdata
		bool _luaval_to_integer(lua_State* L, int lo,
			int64_t* outValue, size_t targetSize, const char* funcName);
		bool _luaval_to_unsigned_integer(lua_State* L, int lo,
			uint64_t* outValue, size_t targetSize, const char* funcName);

		//

		template<typename T, class Enable = void> struct to_native {};

#define CHECK_TO_NATIVE const auto top = lua_gettop(L); if (nullptr == L || nullptr == outValue || top < lo) return false;

#define LUAVAL_TO_NATIVE_BASIC(_F, _T) template<>\
		struct to_native<_T> {\
			static bool F(lua_State* L, int lo, _T* outValue, const char* fName = "") {\
				return lua::_F(L, lo, outValue, fName); } };

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
						outValue->##_Setter(value);\
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
					if(!to_native<K>::F(L, top - 1, &key, fName)) {\
						lua_pop(L, 1); /* removes 'value'; keep 'key' for next iteration*/\
						continue;\
					}\
					if (to_native<V>::F(L, top, &value, fName))\
						(*outValue)_Setter;\
					lua_pop(L, 1);\
				}\
				return true; } };\

		template<typename T>
		struct to_native<T, std::enable_if_t<std::is_enum_v<T>>> {
			static bool F(lua_State* L, int lo, T* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				using type = std::underlying_type_t<T>;
				type value;
				auto ok = to_native<type>(L, lo, &value, fName);
				if (ok) *outValue = (T)value;
				return ok;
			}
		};

#define LUAVAL_TO_SIGNED(_T) template<>\
		struct to_native<_T> {\
			static bool F(lua_State* L, int lo, _T* outValue, const char* funcName){\
				int64_t i; bool ret = _luaval_to_integer(L, lo, &i, sizeof(_T), funcName);\
				if (ret) *outValue = (_T)(i); return ret; } }
#define LUAVAL_TO_UNSIGNED(_T) template<>\
		struct to_native<_T> {\
			static bool F(lua_State* L, int lo, _T* outValue, const char* funcName){\
				uint64_t i; bool ret = _luaval_to_unsigned_integer(L, lo, &i, sizeof(_T), funcName);\
				if (ret) *outValue = (_T)(i); return ret; } }

		LUAVAL_TO_SIGNED(int8_t);
		LUAVAL_TO_SIGNED(int16_t);
		LUAVAL_TO_SIGNED(int32_t);
		LUAVAL_TO_SIGNED(int64_t);
		LUAVAL_TO_UNSIGNED(uint8_t);
		LUAVAL_TO_UNSIGNED(uint16_t);
		LUAVAL_TO_UNSIGNED(uint32_t);
		LUAVAL_TO_UNSIGNED(uint64_t);
#undef LUAVAL_TO_SIGNED
#undef LUAVAL_TO_UNSIGNED

#define DECL_BASIC_TO_NATIVE(_F, _T) bool _F(lua_State* L, int lo, _T* outValue, const char* funcName = "");\
	LUAVAL_TO_NATIVE_BASIC(_F, _T);
		DECL_BASIC_TO_NATIVE(luaval_to_boolean, bool);
		DECL_BASIC_TO_NATIVE(luaval_to_number, double);
		DECL_BASIC_TO_NATIVE(luaval_to_std_string, std::string);
		DECL_BASIC_TO_NATIVE(luaval_to_rect, cocos2d::Rect);
		DECL_BASIC_TO_NATIVE(luaval_to_color3b, cocos2d::Color3B);
		DECL_BASIC_TO_NATIVE(luaval_to_color4b, cocos2d::Color4B);
		DECL_BASIC_TO_NATIVE(luaval_to_color4f, cocos2d::Color4F);
		DECL_BASIC_TO_NATIVE(luaval_to_physics_material, cocos2d::PhysicsMaterial);
		DECL_BASIC_TO_NATIVE(luaval_to_affinetransform, cocos2d::AffineTransform);
		DECL_BASIC_TO_NATIVE(luaval_to_fontdefinition, cocos2d::FontDefinition);
		DECL_BASIC_TO_NATIVE(luaval_to_mat4, cocos2d::Mat4);
		DECL_BASIC_TO_NATIVE(luaval_to_vec2, cocos2d::Vec2);
		DECL_BASIC_TO_NATIVE(luaval_to_vec3, cocos2d::Vec3);
		DECL_BASIC_TO_NATIVE(luaval_to_vec4, cocos2d::Vec4);
		DECL_BASIC_TO_NATIVE(luaval_to_blendfunc, cocos2d::BlendFunc);
		DECL_BASIC_TO_NATIVE(luaval_to_ttfconfig, cocos2d::TTFConfig);
		DECL_BASIC_TO_NATIVE(luaval_to_uniform, cocos2d::Uniform);
		DECL_BASIC_TO_NATIVE(luaval_to_vertexattrib, cocos2d::VertexAttrib);
		DECL_BASIC_TO_NATIVE(luaval_to_ccvalue, cocos2d::Value);
		DECL_BASIC_TO_NATIVE(luaval_to_mesh_vertex_attrib, cocos2d::MeshVertexAttrib);
		DECL_BASIC_TO_NATIVE(luaval_to_quaternion, cocos2d::Quaternion);
		DECL_BASIC_TO_NATIVE(luaval_to_texparams, cocos2d::Texture2D::TexParams);
		DECL_BASIC_TO_NATIVE(luaval_to_v3f_c4b_t2f, cocos2d::V3F_C4B_T2F);
		DECL_BASIC_TO_NATIVE(luaval_to_tex2f, cocos2d::Tex2F);
#undef DECL_BASIC_TO_NATIVE

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

		TO_NATIVE_MAP(std::map, [key] = value);
		TO_NATIVE_MAP(std::unordered_map, [key] = value);
		TO_NATIVE_MAP(std::multimap, .emplace(key, value));
		TO_NATIVE_MAP(std::unordered_multimap, .emplace(key, value));

		template<typename T, class Enable = void>
		bool luaval_to_native(lua_State* L, int lo, T* outValue, const char* fName = "") {
			return to_native<T>::F(L, lo, outValue, fName);
		}

		////////////////////////////////////////////////////////////////////////////////

		template<typename T, class Enable = void> struct to_lua {};

#define LUAVAL_FROM_NATIVE_BASIC(_F, _T) template<>\
		struct to_lua<_T> {\
			static bool F(lua_State* L, const _T& inValue) {\
				lua::_F(L, inValue); } };

#define LUAVAL_FROM_NATIVE_BASIC_P(_F, _T) template<>\
		struct to_lua<_T*> {\
			static bool F(lua_State* L, _T* inValue) {\
				lua::_F(L, inValue); } };

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

#define DECL_BASIC_FROM_NATIVE(_F, _T) void _F(lua_State* L, const _T& inValue);\
	LUAVAL_FROM_NATIVE_BASIC(_F, _T);
		DECL_BASIC_FROM_NATIVE(vec2_to_luaval, cocos2d::Vec2);
		DECL_BASIC_FROM_NATIVE(vec3_to_luaval, cocos2d::Vec3);
		DECL_BASIC_FROM_NATIVE(vec4_to_luaval, cocos2d::Vec4);
		DECL_BASIC_FROM_NATIVE(size_to_luaval, cocos2d::Size);
		DECL_BASIC_FROM_NATIVE(rect_to_luaval, cocos2d::Rect);
		DECL_BASIC_FROM_NATIVE(color3b_to_luaval, cocos2d::Color3B);
		DECL_BASIC_FROM_NATIVE(color4b_to_luaval, cocos2d::Color4B);
		DECL_BASIC_FROM_NATIVE(color4f_to_luaval, cocos2d::Color4F);
		DECL_BASIC_FROM_NATIVE(affinetransform_to_luaval, cocos2d::AffineTransform);
		DECL_BASIC_FROM_NATIVE(fontdefinition_to_luaval, cocos2d::FontDefinition);
		DECL_BASIC_FROM_NATIVE(mat4_to_luaval, cocos2d::Mat4);
		DECL_BASIC_FROM_NATIVE(blendfunc_to_luaval, cocos2d::BlendFunc);
		DECL_BASIC_FROM_NATIVE(ttfconfig_to_luaval, cocos2d::TTFConfig);
		DECL_BASIC_FROM_NATIVE(uniform_to_luaval, cocos2d::Uniform);
		DECL_BASIC_FROM_NATIVE(vertexattrib_to_luaval, cocos2d::VertexAttrib);
		DECL_BASIC_FROM_NATIVE(ccvalue_to_luaval, cocos2d::Value);
		DECL_BASIC_FROM_NATIVE(mesh_vertex_attrib_to_luaval, cocos2d::MeshVertexAttrib);
		DECL_BASIC_FROM_NATIVE(quaternion_to_luaval, cocos2d::Quaternion);
		DECL_BASIC_FROM_NATIVE(texParams_to_luaval, cocos2d::Texture2D::TexParams);
#undef DECL_BASIC_FROM_NATIVE

		TO_LUA_VECTOR(cocos2d::Vector);
		TO_LUA_VECTOR(std::vector);
		TO_LUA_VECTOR(std::deque);
		TO_LUA_VECTOR(std::forward_list);
		TO_LUA_VECTOR(std::list);
		TO_LUA_VECTOR(std::set);
		TO_LUA_VECTOR(std::multiset);
		TO_LUA_VECTOR(std::unordered_set);
		TO_LUA_VECTOR(std::unordered_multiset);

		TO_LUA_MAP(std::map);
		TO_LUA_MAP(std::unordered_map);
		TO_LUA_MAP(std::multimap);
		TO_LUA_MAP(std::unordered_multimap);

		template<typename T>
		void native_to_luaval(lua_State* L, T inValue) {
			to_lua<T>::F(L, inValue);
		}

		////////////////////////////////////////////////////////////////////////////////

		cocos2d::LuaStack* stack();
		int StackTraceback(lua_State *L);
		int isusertype(lua_State* L, int lo, const char* type);
		void* _tousertype(lua_State* L, int lo);
		template<typename T>
		T* tousertype(lua_State* L, int lo, const char* type)
		{
			if (!isusertype(L, lo, type))
				return nullptr;
			const auto u = lua_touserdata(L, lo);
			return static_cast<T*>(u ? *(void**)u : nullptr);
		}

		bool _luaval_to_color4b(lua_State* L, int lo, cocos2d::Color4B* outValue, const char* funcName = "");
		void _color4b_to_luaval(lua_State* L, const cocos2d::Color4B& cc);
		inline cocos2d::Color4B luaval_to_c4b(lua_State* L, int lo)
		{
			return *luaL_checkcolor(L, lo);
		}

		bool _luaarray_to_numbers(lua_State* L, int lo, const std::function<void(double)>& callBack);

		bool luaval_to_unsigned_long_long(lua_State* L, int lo, unsigned long long* outValue, const char* funcName);

		template<typename T>
		bool luaval_to_std_vector_number(lua_State* L, int lo, std::vector<T>* outValue, const char* funcName)
		{
			static_assert(std::is_arithmetic<T>::value, "");
			if (!outValue)
				return false;
			return _luaarray_to_numbers(L, lo, [=](double v) { outValue->push_back((T)v); });
		}

		bool luaval_to_V3F_C4B_T2F_Quad(lua_State* L, int lo,
			cocos2d::V3F_C4B_T2F_Quad* outValue, const char* funcName = "");
		LUAVAL_TO_NATIVE_BASIC(luaval_to_V3F_C4B_T2F_Quad, cocos2d::V3F_C4B_T2F_Quad);
		void V3F_C4B_T2F_Quad_to_luaval(lua_State* L, cocos2d::V3F_C4B_T2F_Quad quad);
		LUAVAL_FROM_NATIVE_BASIC(V3F_C4B_T2F_Quad_to_luaval, cocos2d::V3F_C4B_T2F_Quad);

		bool luaval_to_BlendMode(lua_State* L, int lo, BlendMode** outValue, const char* funcName = "");
		LUAVAL_TO_NATIVE_BASIC(luaval_to_BlendMode, BlendMode*);
		void BlendMode_to_luaval(lua_State* L, BlendMode* blendMode);
		LUAVAL_FROM_NATIVE_BASIC_P(BlendMode_to_luaval, BlendMode);

		bool luaval_to_ColliderType(lua_State* L, int lo, XColliderType* outValue, const char* funcName = "");
		LUAVAL_TO_NATIVE_BASIC(luaval_to_ColliderType, XColliderType);
		void ColliderType_to_luaval(lua_State* L, XColliderType colliderType);
		LUAVAL_FROM_NATIVE_BASIC(ColliderType_to_luaval, XColliderType);

		bool luaval_to_GameObject(lua_State* L, int lo, GameObject** outValue, const char* funcName = "");
		void GameObject_to_luaval(lua_State* L, GameObject* obj);

		void BaseLight_to_luaval(lua_State* L, cocos2d::BaseLight* light);

		bool luaval_to_cptr(lua_State* L, int lo, void** outValue);
		void cptr_to_luaval(lua_State* L, void* ptr);
		void cptr_to_luaval(lua_State* L, void* ptr, const std::string& ptrType);
		void V3F_C4B_T2F_ptr_to_luaval(lua_State* L, cocos2d::V3F_C4B_T2F* ptr);

		bool luaval_to_async_callback(lua_State* L, int lo, std::function<void()>* outValue);
		/** Push Ref object with its real type (needs RTTI). */
		void ref_type_to_luaval(lua_State* L, cocos2d::Ref* ref);

		template <class T>
		void ref_vector_to_luaval(lua_State* L, const std::vector<T*>& inValue)
		{
			static_assert(std::is_base_of<cocos2d::Ref, T>::value, "");
			if (!L) return;
			lua_newtable(L);
			int idx = 1;
			for (const auto& obj : inValue)
			{
				lua_pushnumber(L, idx);
				ref_type_to_luaval(L, obj);
				lua_rawset(L, -3);
				++idx;
			}
		}

		template<typename T>
		int pushArray(lua_State* L, T* arr, uint32_t size)
		{
			static_assert(std::is_arithmetic<T>::value, "");
			lua_createtable(L, size, 0);
			for (auto i = 1U; i <= size; ++i)
			{
				lua_pushnumber(L, lua_Number(arr[i - 1]));
				lua_rawseti(L, -2, i);
			}
			return 1;
		}

		int pushArray(lua_State* L, const std::vector<float>& arr);

		// get array from table like {1, 3, 5}
		std::vector<float> getArray(lua_State* L, int lo);

		// get array from table like {{x=1}, {x=3}, {x=5}}
		std::vector<float> getArray(lua_State* L, int lo, const char* field);

		// get vec2 array from table like {{1,2}, {3,4}, {5,6}}
		std::vector<cocos2d::Vec2> getVec2Array(lua_State* L, int lo);

		// get vec2 array from table like {{x=1, y=2}, {x=3, y=4}}
		std::vector<cocos2d::Vec2> getVec2Array(lua_State* L, int lo, const char* k1, const char* k2);

		// push array by ffi method, about 3x faster
		int pushCArray(lua_State* L, lua_Number* arr, uint32_t size);

		const char* checkstring(lua_State* L, int lo, size_t* strlen, uint32_t* hash);
		const char* tostring(lua_State* L, int lo, size_t* strlen, uint32_t* hash);

		template<typename T>
		typename std::enable_if<
			std::is_arithmetic_v<T> || std::is_same_v<T, std::string>,
			T>::type ccvalue_to_type(const cocos2d::Value& v)
		{
			if (std::is_same_v<T, bool>)
				return v.asBool();
			if (std::is_same_v<T, float>)
				return v.asFloat();
			if (std::is_same_v<T, double>)
				return v.asDouble();
			if (std::is_same_v<T, uint8_t>)
				return v.asByte();
			if (std::is_signed_v<T>)
				return v.asInt();
			if (std::is_unsigned_v<T>)
				return v.asUnsignedInt();
			return T();
		}

		template<typename T>
		cocos2d::ValueVector std_vector_to_ccvaluevector(const std::vector<T>& v)
		{
			cocos2d::ValueVector ret;
			for (auto& it : v)
				ret.push_back(cocos2d::Value(*it));
			return ret;
		}

		template<typename T>
		std::vector<T> ccvaluevector_to_std_vector(const cocos2d::ValueVector& v)
		{
			std::vector<T> ret;
			for (auto& it : v)
				ret.push_back(ccvalue_to_type<T>(it));
			return ret;
		}

		template<typename T>
		cocos2d::ValueMap std_map_to_ccvaluemap(const std::unordered_map<std::string, T>& v)
		{
			cocos2d::ValueMap ret;
			for (auto& it : v)
				ret[it.first] = it.second;
			return ret;
		}

		template<typename T>
		std::unordered_map<std::string, T> ccvaluemap_to_std_map(const cocos2d::ValueMap& v)
		{
			std::unordered_map<std::string, T> ret;
			for (auto& it : v)
				ret[it.first] = ccvalue_to_type<T>(it.second);
			return ret;
		}

		template<typename K, typename T>
		cocos2d::ValueMapIntKey std_map_to_ccvaluemapintkey(const std::unordered_map<K, T>& v)
		{
			cocos2d::ValueMapIntKey ret;
			for (auto& it : v)
				ret[(int)it.first] = it.second;
			return ret;
		}

		template<typename K, typename T>
		std::unordered_map<K, T> ccvaluemapintkey_to_std_map(const cocos2d::ValueMapIntKey& v)
		{
			std::unordered_map<K, T> ret;
			for (auto& it : v)
				ret[(K)it.first] = ccvalue_to_type<T>(it.second);
			return ret;
		}

	}
}
