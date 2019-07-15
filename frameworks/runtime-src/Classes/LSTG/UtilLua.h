#pragma once
#include "Global.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "BlendMode.h"
#include "GameObjectBentLaser.h"
#include "../Math/XCollision.h"

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
		template<typename T> struct _is_vector : std::false_type {};
		template<typename T> struct _is_vector<std::vector<T>> : std::true_type {};
		template<typename T> constexpr bool _is_vector_v = _is_vector<T>::value;

		template<typename T> struct _is_string_map : std::false_type {};
		template<typename T> struct _is_string_map<std::unordered_map<std::string, T>> : std::true_type {};
		template<typename T> constexpr bool _is_string_map_v = _is_string_map<T>::value;

		template<typename T, class Enable = void> struct _is_integer_map : std::false_type {};
		template<typename T, class U> struct _is_integer_map<std::unordered_map<U, T>,
			typename std::enable_if<std::is_integral_v<U> || std::is_enum_v<U> >::type> : std::true_type {};
		template<typename T> constexpr bool _is_integer_map_v = _is_integer_map<T>::value;

		template<typename T, class Enable = void> struct _is_table : std::false_type {};
		template<typename T> struct _is_table<T,
			typename std::enable_if<_is_vector_v<T> || _is_string_map_v<T> || _is_integer_map_v<T> >::type>
		: std::false_type {};
		template<typename T> constexpr bool _is_table_v = _is_table<T>::value;

		//

		template<typename T>
		bool luaval_to_native(lua_State* L, int lo, T* outValue, const char* funcName = "")
		{
			const auto top = lua_gettop(L);
			if (nullptr == L || nullptr == outValue || top < lo)
				return false;
			bool ok = true;
			if (std::is_enum_v<T>) {
				using type = std::underlying_type_t<T>;
				type value;
				ok = luaval_to_native<type>(L, lo, &value, funcName);
				if (ok) *outValue = (T)value;
				return ok;
			}
			tolua_Error tolua_err;
			if (_is_table_v<T> && !tolua_istable(L, lo, 0, &tolua_err))
				return false;
			if(_is_vector_v<T>) {
				using value_type = typename T::value_type;
				const size_t len = lua_objlen(L, lo);
				value_type value;
				for (size_t i = 0; i < len; i++)
				{
					lua_pushnumber(L, i + 1);
					lua_gettable(L, lo);
					ok &= luaval_to_native<value_type>(L, top, &value);
					lua_pop(L, 1);
					if (ok)
						outValue->push_back(value);
					else
						break;
				}
				return true;
			}
			if (_is_string_map_v<T>) {
				using value_type = typename T::value_type::second_type;
				std::string key;
				value_type value;
				lua_pushnil(L);
				while (lua_next(L, lo) != 0)
				{
					if (lua_isstring(L, top - 1))
					{
						if (luaval_to_native(L, top - 1, &key)
							&& luaval_to_native<value_type>(L, top, &value))
							(*outValue)[key] = value;
					}
					lua_pop(L, 1);
				}
				return true;
			}
			if (_is_integer_map_v<T>) {
				using key_type = typename T::key_type;
				using value_type = typename T::value_type::second_type;
				key_type key;
				value_type value;
				lua_pushnil(L);
				while (lua_next(L, lo) != 0)
				{
					if (lua_isstring(L, top - 1))
					{
						if (luaval_to_native<key_type>(L, top - 1, &key)
							&& luaval_to_native<value_type>(L, top, &value))
							(*outValue)[key] = value;
					}
					lua_pop(L, 1);
				}
				return true;
			}
			return false;
		}

		template<typename T, class Enable = std::enable_if_t<!std::is_pointer_v<T>>>
		void native_to_luaval(lua_State* L, const T& inValue)
		{
			if (!L)
				return;
			if(std::is_same_v<T, bool>) {
				lua_pushboolean(L, (int)inValue);
				return;
			}
			if(std::is_arithmetic_v<T>) {
				lua_pushnumber(L, (lua_Number)inValue);
				return;
			}
			if (std::is_enum_v<T>) {
				using type = std::underlying_type_t<T>;
				type value = (type)inValue;
				native_to_luaval(L, &value);
				return;
			}
			if (_is_vector_v<T>) {
				lua_createtable(L, inValue.size(), 0);
				int index = 1;
				for (auto& value : inValue)
				{
					lua_pushnumber(L, (lua_Number)index);
					native_to_luaval(L, value);
					lua_rawset(L, -3);
					++index;
				}
				return;
			}
			if (_is_string_map_v<T>) {
				lua_createtable(L, 0, inValue.size());
				for (auto& it : inValue)
				{
					lua_pushlstring(L, it.first.c_str(), it.first.size());
					native_to_luaval(L, it.second);
					lua_rawset(L, -3);
				}
				return;
			}
			if (_is_integer_map_v<T>) {
				lua_createtable(L, 0, inValue.size());
				for (auto& it : inValue)
				{
					native_to_luaval(L, it.first);
					native_to_luaval(L, it.second);
					lua_rawset(L, -3);
				}
				return;
			}
			lua_pushnil(L);
		}

		template<typename T>
		void native_to_luaval(lua_State* L, T* inValue)
		{
			if (!L)
				return;
			if (!inValue) {
				lua_pushnil(L);
				return;
			}
			lua_pushnil(L);
		}

#define LUAVAL_TO_NATIVE_BASIC(_F, _T) template<>\
		inline bool luaval_to_native<_T>(lua_State* L, int lo, _T* outValue, const char* funcName){\
		return lua::_F(L, lo, outValue, funcName); }
#define LUAVAL_FROM_NATIVE_BASIC(_F, _T) template<>\
		inline void native_to_luaval<_T>(lua_State* L, const _T& inValue){\
		lua::_F(L, inValue); }
#define LUAVAL_FROM_NATIVE_BASIC_P(_F, _T) template<>\
		inline void native_to_luaval<_T>(lua_State* L, _T* inValue){\
		lua::_F(L, inValue); }

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
		DECL_BASIC_TO_NATIVE(luaval_to_std_vector_string, std::vector<std::string>);
		DECL_BASIC_TO_NATIVE(luaval_to_std_vector_int, std::vector<int>);
		DECL_BASIC_TO_NATIVE(luaval_to_ccvalue, cocos2d::Value);
		DECL_BASIC_TO_NATIVE(luaval_to_ccvaluemap, cocos2d::ValueMap);
		DECL_BASIC_TO_NATIVE(luaval_to_ccvaluemapintkey, cocos2d::ValueMapIntKey);
		DECL_BASIC_TO_NATIVE(luaval_to_ccvaluevector, cocos2d::ValueVector);
		DECL_BASIC_TO_NATIVE(luaval_to_mesh_vertex_attrib, cocos2d::MeshVertexAttrib);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_vector_float, std::vector<float>);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_vector_ushort, std::vector<unsigned short>);
		DECL_BASIC_TO_NATIVE(luaval_to_quaternion, cocos2d::Quaternion);
		DECL_BASIC_TO_NATIVE(luaval_to_texparams, cocos2d::Texture2D::TexParams);
		DECL_BASIC_TO_NATIVE(luaval_to_v3f_c4b_t2f, cocos2d::V3F_C4B_T2F);
		DECL_BASIC_TO_NATIVE(luaval_to_tex2f, cocos2d::Tex2F);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_vector_v3f_c4b_t2f, std::vector<cocos2d::V3F_C4B_T2F>);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_vector_vec2, std::vector<cocos2d::Vec2>);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_vector_vec3, std::vector<cocos2d::Vec3>);
#undef DECL_BASIC_TO_NATIVE
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
		DECL_BASIC_FROM_NATIVE(ccvaluemap_to_luaval, cocos2d::ValueMap);
		DECL_BASIC_FROM_NATIVE(ccvaluemapintkey_to_luaval, cocos2d::ValueMapIntKey);
		DECL_BASIC_FROM_NATIVE(ccvaluevector_to_luaval, cocos2d::ValueVector);
		DECL_BASIC_FROM_NATIVE(mesh_vertex_attrib_to_luaval, cocos2d::MeshVertexAttrib);
		//DECL_BASIC_FROM_NATIVE(ccvector_std_string_to_luaval, std::vector<std::string>);
		//DECL_BASIC_FROM_NATIVE(ccvector_int_to_luaval, std::vector<int>);
		//DECL_BASIC_FROM_NATIVE(ccvector_float_to_luaval, std::vector<float>);
		//DECL_BASIC_FROM_NATIVE(ccvector_ushort_to_luaval, std::vector<unsigned short>);
		DECL_BASIC_FROM_NATIVE(quaternion_to_luaval, cocos2d::Quaternion);
		DECL_BASIC_FROM_NATIVE(texParams_to_luaval, cocos2d::Texture2D::TexParams);
		//DECL_BASIC_FROM_NATIVE(std_vector_vec3_to_luaval, std::vector<cocos2d::Vec3>);
#undef DECL_BASIC_FROM_NATIVE

		constexpr int LUA_TPROTO = LUA_TTHREAD + 1;
		constexpr int LUA_TCDATA = LUA_TTHREAD + 2;

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

		// support cdata
		bool _luaval_to_integer(lua_State* L, int lo,
			int64_t* outValue, size_t targetSize, const char* funcName);
		bool _luaval_to_unsigned_integer(lua_State* L, int lo,
			uint64_t* outValue, size_t targetSize, const char* funcName);

#define LUAVAL_TO_SIGNED(_T) template<>\
		inline bool luaval_to_native<_T>(lua_State* L, int lo, _T* outValue, const char* funcName){\
		int64_t i; bool ret = _luaval_to_integer(L, lo, &i, sizeof(_T), funcName);\
		if (ret) *outValue = (_T)(i); return ret;}
#define LUAVAL_TO_UNSIGNED(_T) template<>\
		inline bool luaval_to_native<_T>(lua_State* L, int lo, _T* outValue, const char* funcName){\
		uint64_t i; bool ret = _luaval_to_unsigned_integer(L, lo, &i, sizeof(_T), funcName);\
		if (ret) *outValue = (_T)(i); return ret;}

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

#define LUAVAL_TO_NATIVE_BASIC_CVT(_F, _T, _Tmid) template<>\
		inline bool luaval_to_native<_T>(lua_State* L, int lo, _T* outValue, const char* funcName){\
		_Tmid tmp; auto ret = lua::_F(L, lo ,&tmp, funcName);\
		if(ret) *outValue = tmp; return ret; }

		LUAVAL_TO_NATIVE_BASIC_CVT(luaval_to_number, float, double);

#undef LUAVAL_TO_NATIVE_BASIC
#undef LUAVAL_TO_NATIVE_BASIC_CVT

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
