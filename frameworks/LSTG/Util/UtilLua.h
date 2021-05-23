#pragma once
#include "Global.h"
#include "scripting/lua-bindings/manual/CCLuaStack.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "RenderMode.h"
#include "Object/GameObjectBentLaser.h"
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
		constexpr int LUA_TPROTO = LUA_TTHREAD + 1;
		constexpr int LUA_TCDATA = LUA_TTHREAD + 2;

		// support cdata
		bool _luaval_to_integer(lua_State* L, int lo,
			int64_t* outValue, size_t targetSize, const char* funcName);
		bool _luaval_to_unsigned_integer(lua_State* L, int lo,
			uint64_t* outValue, size_t targetSize, const char* funcName);

		//

#define DECL_BASIC_TO_NATIVE(_F, _T) bool _##_F(lua_State* L, int lo, _T* outValue, const char* funcName = "");
		DECL_BASIC_TO_NATIVE(luaval_to_boolean, bool);
		DECL_BASIC_TO_NATIVE(luaval_to_number, double);
		//DECL_BASIC_TO_NATIVE(luaval_to_std_string, std::string);
		DECL_BASIC_TO_NATIVE(luaval_to_size, cocos2d::Size);
		DECL_BASIC_TO_NATIVE(luaval_to_rect, cocos2d::Rect);
		DECL_BASIC_TO_NATIVE(luaval_to_color3b, cocos2d::Color3B);
		//DECL_BASIC_TO_NATIVE(luaval_to_color4b, cocos2d::Color4B);
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
		DECL_BASIC_TO_NATIVE(luaval_to_ccvalue, cocos2d::Value);
		DECL_BASIC_TO_NATIVE(luaval_to_mesh_vertex_attrib, cocos2d::MeshVertexAttrib);
		DECL_BASIC_TO_NATIVE(luaval_to_quaternion, cocos2d::Quaternion);
		DECL_BASIC_TO_NATIVE(luaval_to_texparams, cocos2d::Texture2D::TexParams);
		DECL_BASIC_TO_NATIVE(luaval_to_v3f_c4b_t2f, cocos2d::V3F_C4B_T2F);
		DECL_BASIC_TO_NATIVE(luaval_to_tex2f, cocos2d::Tex2F);
		DECL_BASIC_TO_NATIVE(luaval_to_uniformLocation, cocos2d::backend::UniformLocation);
#undef DECL_BASIC_TO_NATIVE

#define DECL_BASIC_FROM_NATIVE(_F, _T) void _##_F(lua_State* L, const _T& inValue);
		DECL_BASIC_FROM_NATIVE(vec2_to_luaval, cocos2d::Vec2);
		DECL_BASIC_FROM_NATIVE(vec3_to_luaval, cocos2d::Vec3);
		DECL_BASIC_FROM_NATIVE(vec4_to_luaval, cocos2d::Vec4);
		DECL_BASIC_FROM_NATIVE(size_to_luaval, cocos2d::Size);
		DECL_BASIC_FROM_NATIVE(rect_to_luaval, cocos2d::Rect);
		DECL_BASIC_FROM_NATIVE(color3b_to_luaval, cocos2d::Color3B);
		//DECL_BASIC_FROM_NATIVE(color4b_to_luaval, cocos2d::Color4B);
		DECL_BASIC_FROM_NATIVE(color4f_to_luaval, cocos2d::Color4F);
		DECL_BASIC_FROM_NATIVE(affinetransform_to_luaval, cocos2d::AffineTransform);
		DECL_BASIC_FROM_NATIVE(physics_material_to_luaval, cocos2d::PhysicsMaterial);
		DECL_BASIC_FROM_NATIVE(fontdefinition_to_luaval, cocos2d::FontDefinition);
		DECL_BASIC_FROM_NATIVE(mat4_to_luaval, cocos2d::Mat4);
		DECL_BASIC_FROM_NATIVE(blendfunc_to_luaval, cocos2d::BlendFunc);
		DECL_BASIC_FROM_NATIVE(ttfconfig_to_luaval, cocos2d::TTFConfig);
		DECL_BASIC_FROM_NATIVE(ccvalue_to_luaval, cocos2d::Value);
		DECL_BASIC_FROM_NATIVE(mesh_vertex_attrib_to_luaval, cocos2d::MeshVertexAttrib);
		DECL_BASIC_FROM_NATIVE(quaternion_to_luaval, cocos2d::Quaternion);
		DECL_BASIC_FROM_NATIVE(texParams_to_luaval, cocos2d::Texture2D::TexParams);
#undef DECL_BASIC_FROM_NATIVE

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

#define DECL_NATIVE_CONV(F, T)\
	bool luaval_to_##F(lua_State* L, int lo, T* outValue, const char* funcName = "");\
	void F##_to_luaval(lua_State* L, const T& inValue);

		DECL_NATIVE_CONV(V3F_C4B_T2F_Quad, cocos2d::V3F_C4B_T2F_Quad);
		DECL_NATIVE_CONV(UniformLocation, cocos2d::backend::UniformLocation);
		DECL_NATIVE_CONV(SamplerDescriptor, cocos2d::backend::SamplerDescriptor);
		DECL_NATIVE_CONV(AttributeBindInfo, cocos2d::backend::AttributeBindInfo);
		DECL_NATIVE_CONV(Viewport, cocos2d::Viewport);
		DECL_NATIVE_CONV(BlendDescriptor, cocos2d::backend::BlendDescriptor);
#undef DECL_NATIVE_CONV

		bool luaval_to_RenderMode(lua_State* L, int lo, RenderMode** outValue, const char* funcName = "");
		void RenderMode_to_luaval(lua_State* L, RenderMode* renderMode);

		bool luaval_to_ColliderType(lua_State* L, int lo, XColliderType* outValue, const char* funcName = "");
		void ColliderType_to_luaval(lua_State* L, XColliderType colliderType);

		bool luaval_to_GameObject(lua_State* L, int lo, GameObject** outValue, const char* funcName = "");
		void GameObject_to_luaval(lua_State* L, GameObject* obj);

		void BaseLight_to_luaval(lua_State* L, cocos2d::BaseLight* light);

		bool luaval_to_cptr(lua_State* L, int lo, void** outValue);
		void cptr_to_luaval(lua_State* L, void* ptr);
		void cptr_to_luaval(lua_State* L, void* ptr, const std::string& ptrType);
		void V3F_C4B_T2F_ptr_to_luaval(lua_State* L, cocos2d::V3F_C4B_T2F* ptr);

		bool luaval_to_async_callback(lua_State* L, int lo, std::function<void()>* outValue);
		/** Push Ref object with its real type (needs RTTI). */
		void ref_type_to_luaval(lua_State* L, cocos2d::Ref* ref, const char* typeID = nullptr);

		const void* luaval_to_const_data(lua_State* L, int lo, int lo_size, size_t* outSize);

		template <class T>
		void ref_vector_to_luaval(lua_State* L, const std::vector<T*>& inValue) {
			static_assert(std::is_base_of<cocos2d::Ref, T>::value, "");
			if (!L) return;
			lua_newtable(L);
			int idx = 1;
			for (const auto& obj : inValue) {
				lua_pushnumber(L, idx);
				ref_type_to_luaval(L, (cocos2d::Ref*)obj);
				lua_rawset(L, -3);
				++idx;
			}
		}

		template<typename T>
		int pushArray(lua_State* L, T* arr, size_t size) {
			static_assert(std::is_arithmetic<T>::value, "");
			lua_createtable(L, size, 0);
			for (auto i = 1U; i <= size; ++i) {
				lua_pushnumber(L, lua_Number(arr[i - 1]));
				lua_rawseti(L, -2, i);
			}
			return 1;
		}

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

		std::string getClassNameByTypeID(const std::string& typeID);
	}
}
