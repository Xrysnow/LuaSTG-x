#pragma once
#include "lua_conversion_tolua.hpp"
#include "cocos2d.h"

namespace lua
{
	inline void ref_type_to_luaval(lua_State* L, cocos2d::Ref* ref, const char* typeID)
    {
        if (ref)
        {
            const char* typeName = typeID ? typeID : typeid(*ref).name();
			using key_type = decltype(g_luaType)::key_type;
			using type = std::conditional_t<std::is_integral_v<key_type>, key_type, const char*>;
            const auto key = reinterpret_cast<type>(typeName);
            const auto iter = g_luaType.find(key);
            std::string luatype = "cc.Ref";
            if (g_luaType.end() != iter)
				luatype = iter->second;
            toluafix_pushusertype_ccobject(
                L, (int)ref->_ID, &ref->_luaID, (void*)ref, luatype.c_str());
        }
        else
        {
            lua_pushnil(L);
        }
    }

	////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	struct to_native<T*, std::enable_if_t<std::is_base_of_v<cocos2d::Ref, T>>> {
		static bool F(lua_State* L, int lo, T** outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if(lua_isnil(L, lo)) {
				*outValue = nullptr;
				return true;
			}
			std::string className = getClassNameByType<T>();
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
	struct to_native<T*, std::enable_if_t<!std::is_base_of_v<cocos2d::Ref, T>>> {
		static bool F(lua_State* L, int lo, T** outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
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

	LUA_TO_NATIVE_VECTOR(cocos2d::Vector, pushBack);

	template<typename T>
	struct to_native<hlookup::string_map<T>> {
		static bool F(lua_State* L, int lo, hlookup::string_map<T>* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_istable(L, lo)) return false;
			std::string key; T value;
			lua_pushnil(L);
			while (lua_next(L, lo) != 0)
			{
				if (!to_native<std::string>::F(L, top + 1, &key, fName))
				{
					lua_pop(L, 1);
					continue;
				}
				if (to_native<T>::F(L, top + 2, &value, fName))
					outValue->operator[](key) = value;
				lua_pop(L, 1);
			}
			return true;
		}
	};

	template<>
	struct to_native<hlookup::string_set> {
		static bool F(lua_State* L, int lo, hlookup::string_set* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			const size_t len = lua_objlen(L, lo);
			std::string value;
			lua_pushnil(L);
			bool ok = true;
			for (size_t i = 0; i < len; i++) {
				lua_pushnumber(L, i + 1);
				lua_gettable(L, lo);
				ok &= to_native<std::string>::F(L, top + 1, &value, fName);
				lua_pop(L, 1);
				if (ok)
					outValue->insert(value);
				else
					break;
			}
			return true;
		}
	};

	template<>
	struct to_native<cocos2d::Vec2> {
		static bool F(lua_State* L, int lo, cocos2d::Vec2* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::Vec2 v;
			bool ok = true;
			ok &= luaval_field_to_native(L, lo, "x", &v.x, fName) || luaval_field_to_native(L, lo, "width", &v.x, fName);
			ok &= luaval_field_to_native(L, lo, "y", &v.y, fName) || luaval_field_to_native(L, lo, "height", &v.y, fName);
			if (ok) *outValue = v;
			return ok;
		}
	};

	LUA_TO_NATIVE_STRUCT3(cocos2d::Vec3, x, y, z);
	LUA_TO_NATIVE_STRUCT4(cocos2d::Vec4, x, y, z, w);
	LUA_TO_NATIVE_STRUCT2(cocos2d::BlendFunc, src, dst);
	LUA_TO_NATIVE_STRUCT3(cocos2d::Color3B, r, g, b);
	//LUA_TO_NATIVE_STRUCT4(cocos2d::Color4B, r, g, b, a);
	LUA_TO_NATIVE_STRUCT4(cocos2d::Color4F, r, g, b, a);
	LUA_TO_NATIVE_STRUCT4(cocos2d::Quaternion, x, y, z, w);
	LUA_TO_NATIVE_STRUCT2(cocos2d::MeshVertexAttrib, type, vertexAttrib);
	LUA_TO_NATIVE_STRUCT3(cocos2d::V3F_C4B_T2F, vertices, colors, texCoords);
	LUA_TO_NATIVE_STRUCT4(cocos2d::V3F_C4B_T2F_Quad, tl, tr, bl, br);
	LUA_TO_NATIVE_STRUCT4(cocos2d::Viewport, x, y, w, h);
	LUA_TO_NATIVE_STRUCT4(cocos2d::backend::AttributeBindInfo, attributeName, location, size, type);

#if CC_USE_PHYSICS
	LUA_TO_NATIVE_STRUCT3(cocos2d::PhysicsMaterial, density, restitution, friction);

	template<>
	struct to_native<cocos2d::PhysicsContactData> {
		static bool F(lua_State* L, int lo, cocos2d::PhysicsContactData* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::PhysicsContactData v;
			bool ok = luaval_field_to_native(L, lo, "normal", &v.normal, fName);
			if (ok)
			{
				lua_pushliteral(L, "points");
				lua_gettable(L, lo);
				ok = luaval_to_native_array(L, -1, v.points, 4, fName);
				lua_pop(L, 1);
			}
			if (ok) *outValue = v;
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::PhysicsRayCastInfo> {
		static bool F(lua_State* L, int lo, cocos2d::PhysicsRayCastInfo* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::PhysicsRayCastInfo v{};
			bool ok = luaval_field_to_native(L, lo, "start", &v.start, fName) &&
				luaval_field_to_native(L, lo, "ended", &v.end, fName) &&
				luaval_field_to_native(L, lo, "contact", &v.contact, fName) &&
				luaval_field_to_native(L, lo, "normal", &v.normal, fName) &&
				luaval_field_to_native(L, lo, "fraction", &v.fraction, fName) &&
				luaval_field_to_native(L, lo, "shape", &v.shape, fName);
			if (ok) *outValue = v;
			return ok;
		}
	};
#endif

	template<>
	struct to_native<cocos2d::Color4B> {
		static bool F(lua_State* L, int lo, cocos2d::Color4B* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (lua_type(L, lo) == LUA_TUSERDATA) {
				auto p = static_cast<cocos2d::Color4B*>(luaL_checkudata(L, lo, "lstgColor"));
				if (p) {
					*outValue = *p;
					return true;
				}
			}
			if (!is_indexable(L, lo))
				return false;
			cocos2d::Color4B v;
			bool ok = luaval_field_to_native(L, lo, "r", &v.r, fName) &&
				luaval_field_to_native(L, lo, "g", &v.g, fName) &&
				luaval_field_to_native(L, lo, "b", &v.b, fName) &&
				luaval_field_to_native(L, lo, "a", &v.a, fName);
			if (ok) *outValue = v;
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::Rect> {
		static bool F(lua_State* L, int lo, cocos2d::Rect* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::Rect v;
			bool ok = luaval_field_to_native(L, lo, "x", &v.origin.x, fName) &&
				luaval_field_to_native(L, lo, "y", &v.origin.y, fName) &&
				luaval_field_to_native(L, lo, "width", &v.size.width, fName) &&
				luaval_field_to_native(L, lo, "height", &v.size.height, fName);
			if (ok) *outValue = v;
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::AffineTransform> {
		static bool F(lua_State* L, int lo, cocos2d::AffineTransform* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_istable(L, lo)) return false;
			cocos2d::AffineTransform v{};
			bool ok = luaval_field_to_native(L, lo, "a", &v.a, fName) &&
				luaval_field_to_native(L, lo, "b", &v.b, fName) &&
				luaval_field_to_native(L, lo, "c", &v.c, fName) &&
				luaval_field_to_native(L, lo, "d", &v.d, fName) &&
				luaval_field_to_native(L, lo, "tx", &v.tx, fName) &&
				luaval_field_to_native(L, lo, "ty", &v.ty, fName);
			if (ok) *outValue = v;
			return ok;
		}
	};
	
	template<>
	struct to_native<cocos2d::FontDefinition> {
		static bool F(lua_State* L, int lo, cocos2d::FontDefinition* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_istable(L, lo)) return false;
			cocos2d::FontDefinition v;
			luaval_field_to_native(L, lo, "fontName", &v._fontName, fName);
			luaval_field_to_native(L, lo, "fontSize", &v._fontSize, fName);
			luaval_field_to_native(L, lo, "fontAlignmentH", &v._alignment, fName);
			luaval_field_to_native(L, lo, "fontAlignmentV", &v._vertAlignment, fName);
			luaval_field_to_native(L, lo, "fontFillColor", &v._fontFillColor, fName);
			luaval_field_to_native(L, lo, "fontDimensions", &v._dimensions, fName);
			luaval_field_to_native(L, lo, "shadowEnabled", &v._shadow._shadowEnabled, fName);
			luaval_field_to_native(L, lo, "strokeEnabled", &v._stroke._strokeEnabled, fName);
			if (v._shadow._shadowEnabled)
			{
				luaval_field_to_native(L, lo, "shadowOffset", &v._shadow._shadowOffset, fName);
				luaval_field_to_native(L, lo, "shadowBlur", &v._shadow._shadowBlur, fName);
				luaval_field_to_native(L, lo, "shadowOpacity", &v._shadow._shadowOpacity, fName);
			}
			if (v._shadow._shadowEnabled)
			{
				luaval_field_to_native(L, lo, "strokeColor", &v._stroke._strokeColor, fName);
				luaval_field_to_native(L, lo, "strokeSize", &v._stroke._strokeSize, fName);
			}
			return true;
		}
	};

	template<>
	struct to_native<cocos2d::TTFConfig> {
		static bool F(lua_State* L, int lo, cocos2d::TTFConfig* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!lua_istable(L, lo)) return false;
			cocos2d::TTFConfig v;
			luaval_field_to_native(L, lo, "fontFilePath", &v.fontFilePath, fName);
			luaval_field_to_native(L, lo, "fontSize", &v.fontSize, fName);
			luaval_field_to_native(L, lo, "glyphs", &v.glyphs, fName);
			luaval_field_to_native(L, lo, "customGlyphs", &v.customGlyphs, fName);
			luaval_field_to_native(L, lo, "distanceFieldEnabled", &v.distanceFieldEnabled, fName);
			luaval_field_to_native(L, lo, "outlineSize", &v.outlineSize, fName);
			*outValue = v;
			return true;
		}
	};

	template<>
	struct to_native<cocos2d::Value> {
		static bool F(lua_State* L, int lo, cocos2d::Value* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			const auto type = lua_type(L, lo);
			bool ok = false;
			if (is_indexable(L, lo))
			{
				lua_pushnumber(L, 1);
				lua_gettable(L, lo);
				if (lua_isnil(L, -1)) /** if table[1] = nil,we don't think it is a pure array */
				{
					lua_pop(L, 1);
					cocos2d::ValueMap dictVal;
					if ((ok = luaval_to_native(L, lo, &dictVal, fName)))
						*outValue = cocos2d::Value(dictVal);
				}
				else
				{
					lua_pop(L, 1);
					cocos2d::ValueVector arrVal;
					if ((ok = luaval_to_native(L, lo, &arrVal, fName)))
						*outValue = cocos2d::Value(arrVal);
				}
			}
			else if (type == LUA_TSTRING)
			{
				std::string stringValue;
				if ((ok = luaval_to_native(L, lo, &stringValue, fName)))
					*outValue = cocos2d::Value(stringValue);
			}
			else if (type == LUA_TBOOLEAN)
			{
				bool boolVal = false;
				if ((ok = luaval_to_native(L, lo, &boolVal, fName)))
					*outValue = cocos2d::Value(boolVal);
			}
			else if (type == LUA_TNUMBER)
			{
				double doubleVal = 0;
				if ((ok = luaval_to_native(L, lo, &doubleVal, fName)))
					*outValue = cocos2d::Value(doubleVal);
			}
			else if (type == LUA_TNIL)
			{
				*outValue = cocos2d::Value::Null;
			}
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::Mat4> {
		static bool F(lua_State* L, int lo, cocos2d::Mat4* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			if (lua_objlen(L, lo) != 16) return false;
			for (int i = 0; i < 16; ++i)
			{
				if (!luaval_field_to_native(L, lo, i + 1, &outValue->m[i], fName))
					outValue->m[i] = 0;
			}
			return true;
		}
	};

	template<>
	struct to_native<cocos2d::Texture2D::TexParams> {
		static bool F(lua_State* L, int lo, cocos2d::Texture2D::TexParams* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::Texture2D::TexParams v;
			bool ok = luaval_field_to_native(L, lo, "minFilter", &v.minFilter, fName) &&
				luaval_field_to_native(L, lo, "magFilter", &v.magFilter, fName);
			ok = ok && (luaval_field_to_native(L, lo, "wrapS", &v.sAddressMode, fName) || luaval_field_to_native(L, lo, "sAddressMode", &v.sAddressMode, fName));
			ok = ok && (luaval_field_to_native(L, lo, "wrapT", &v.tAddressMode, fName) || luaval_field_to_native(L, lo, "tAddressMode", &v.tAddressMode, fName));
			if (ok) *outValue = v;
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::backend::UniformLocation> {
		static bool F(lua_State* L, int lo, cocos2d::backend::UniformLocation* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::backend::UniformLocation v;
			bool ok = luaval_field_to_native(L, lo, "shaderStage", &v.shaderStage, fName);
			if (ok)
			{
				lua_pushliteral(L, "location");
				lua_gettable(L, lo);
				ok = luaval_to_native_array(L, -1, v.location, 2, fName);
				lua_pop(L, 1);
			}
			if (ok) *outValue = v;
			return ok;
		}
	};

	template<>
	struct to_native<cocos2d::backend::BlendDescriptor> {
		static bool F(lua_State* L, int lo, cocos2d::backend::BlendDescriptor* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (!is_indexable(L, lo)) return false;
			cocos2d::backend::BlendDescriptor v;
			luaval_field_to_native(L, lo, "writeMask", &v.writeMask, fName);
			luaval_field_to_native(L, lo, "blendEnabled", &v.blendEnabled, fName);
			luaval_field_to_native(L, lo, "rgbBlendOperation", &v.rgbBlendOperation, fName);
			luaval_field_to_native(L, lo, "alphaBlendOperation", &v.alphaBlendOperation, fName);
			luaval_field_to_native(L, lo, "sourceRGBBlendFactor", &v.sourceRGBBlendFactor, fName);
			luaval_field_to_native(L, lo, "destinationRGBBlendFactor", &v.destinationRGBBlendFactor, fName);
			luaval_field_to_native(L, lo, "sourceAlphaBlendFactor", &v.sourceAlphaBlendFactor, fName);
			luaval_field_to_native(L, lo, "destinationAlphaBlendFactor", &v.destinationAlphaBlendFactor, fName);
			*outValue = v;
			return true;
		}
	};

    ////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	struct to_lua<T*, std::enable_if_t<std::is_base_of_v<cocos2d::Ref, T>>> {
		static void F(lua_State* L, T* inValue) {
			if (!L) return;
			ref_type_to_luaval(L, (cocos2d::Ref*)inValue, typeid(T).name());
		}
	};

	template<typename T>
	struct to_lua<T*, std::enable_if_t<!std::is_base_of_v<cocos2d::Ref, T>>> {
		static void F(lua_State* L, T* inValue) {
			if (!L) return;
			if(!inValue) { lua_pushnil(L); return; }
			const auto className = getClassNameByType<T>();
			if(className.empty()) { lua_pushnil(L); return; }
			lua_getfield(L, LUA_REGISTRYINDEX, className.c_str());
			if (lua_isnil(L, -1)) // leave nil on stack
				return;
			tolua_pushusertype(L, (void*)inValue, className.c_str());
			lua_remove(L, -2);
		}
	};

	LUA_TO_LUA_VECTOR(cocos2d::Vector);

	template<typename T>
	struct to_lua<hlookup::string_map<T>> {
		static void F(lua_State* L, const hlookup::string_map<T>& inValue) {
			if (!L) return;
			lua_createtable(L, 0, (int)inValue.size());
			for (auto&& it : inValue)
			{
				lua_pushlstring(L, it.first.c_str(), it.first.size());
				to_lua<T>::F(L, it.second);
				lua_settable(L, -1);
			}
		}
	};

	template<>
	struct to_lua<hlookup::string_set> {
		static void F(lua_State* L, const hlookup::string_set& inValue) {
			if (!L) return;
			lua_createtable(L, (int)inValue.size(), 0);
			int i = 1;
			for (auto&& it : inValue)
			{
				lua_pushlstring(L, it.c_str(), it.size());
				lua_rawseti(L, -1, i);
				++i;
			}
		}
	};
	
	template<>
	struct to_lua<std::thread::id> {
		static void F(lua_State* L, const std::thread::id& inValue) {
			if (!L) return;
			lua_pushinteger(L, std::hash<std::thread::id>{}(inValue));
		}
	};

	LUA_TO_LUA_STRUCT2(cocos2d::Vec2, x, y);
	LUA_TO_LUA_STRUCT3(cocos2d::Vec3, x, y, z);
	LUA_TO_LUA_STRUCT4(cocos2d::Vec4, x, y, z, w);
	LUA_TO_LUA_STRUCT2(cocos2d::BlendFunc, src, dst);
	LUA_TO_LUA_STRUCT3(cocos2d::Color3B, r, g, b);
	LUA_TO_LUA_STRUCT4(cocos2d::Color4B, r, g, b, a);
	LUA_TO_LUA_STRUCT4(cocos2d::Color4F, r, g, b, a);
	LUA_TO_LUA_STRUCT4(cocos2d::Quaternion, x, y, z, w);
	LUA_TO_LUA_STRUCT2(cocos2d::MeshVertexAttrib, type, vertexAttrib);
	LUA_TO_LUA_STRUCT3(cocos2d::V3F_C4B_T2F, vertices, colors, texCoords);
	LUA_TO_LUA_STRUCT4(cocos2d::V3F_C4B_T2F_Quad, tl, tr, bl, br);
	LUA_TO_LUA_STRUCT4(cocos2d::Viewport, x, y, w, h);
	LUA_TO_LUA_STRUCT6(cocos2d::AffineTransform, a, b, c, d, tx, ty);
	LUA_TO_LUA_STRUCT6(cocos2d::TTFConfig, fontFilePath, fontSize, glyphs, customGlyphs, distanceFieldEnabled, outlineSize);
	LUA_TO_LUA_STRUCT4(cocos2d::Texture2D::TexParams, minFilter, magFilter, sAddressMode, tAddressMode); // cocos2d::backend::SamplerDescriptor
	LUA_TO_LUA_STRUCT4(cocos2d::backend::AttributeBindInfo, attributeName, location, size, type);

#if CC_USE_PHYSICS
	LUA_TO_LUA_STRUCT3(cocos2d::PhysicsMaterial, density, restitution, friction);

	template<>
	struct to_lua<cocos2d::PhysicsContactData> {
		static void F(lua_State* L, const cocos2d::PhysicsContactData& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 3);
			native_to_luaval_field(L, -1, "normal", inValue.normal);
			native_to_luaval_field(L, -1, "POINT_MAX", inValue.POINT_MAX);
			lua_pushstring(L, "points");
			native_array_to_luaval(L, inValue.points, inValue.POINT_MAX);
			lua_settable(L, -3);
		}
	};

	template<>
	struct to_lua<cocos2d::PhysicsRayCastInfo> {
		static void F(lua_State* L, const cocos2d::PhysicsRayCastInfo& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 6);
			native_to_luaval_field(L, -1, "start", inValue.start);
			native_to_luaval_field(L, -1, "ended", inValue.end);
			native_to_luaval_field(L, -1, "contact", inValue.contact);
			native_to_luaval_field(L, -1, "normal", inValue.normal);
			native_to_luaval_field(L, -1, "fraction", inValue.fraction);
			native_to_luaval_field(L, -1, "shape", inValue.shape);
		}
	};
#endif

	template<>
	struct to_lua<cocos2d::Rect> {
		static void F(lua_State* L, const cocos2d::Rect& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 4);
			native_to_luaval_field(L, -1, "x", inValue.origin.x);
			native_to_luaval_field(L, -1, "y", inValue.origin.y);
			native_to_luaval_field(L, -1, "width", inValue.size.width);
			native_to_luaval_field(L, -1, "height", inValue.size.height);
		}
	};

	template<>
	struct to_lua<cocos2d::FontDefinition> {
		static void F(lua_State* L, const cocos2d::FontDefinition& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 13);
			native_to_luaval_field(L, -1, "fontName", inValue._fontName);
			native_to_luaval_field(L, -1, "fontSize", inValue._fontSize);
			native_to_luaval_field(L, -1, "fontAlignmentH", inValue._alignment);
			native_to_luaval_field(L, -1, "fontAlignmentV", inValue._vertAlignment);
			native_to_luaval_field(L, -1, "fontFillColor", inValue._fontFillColor);
			native_to_luaval_field(L, -1, "fontDimensions", inValue._dimensions);
			native_to_luaval_field(L, -1, "shadowEnabled", inValue._shadow._shadowEnabled);
			native_to_luaval_field(L, -1, "shadowOffset", inValue._shadow._shadowOffset);
			native_to_luaval_field(L, -1, "shadowBlur", inValue._shadow._shadowBlur);
			native_to_luaval_field(L, -1, "shadowOpacity", inValue._shadow._shadowOpacity);
			native_to_luaval_field(L, -1, "shadowEnabled", inValue._stroke._strokeEnabled);
			native_to_luaval_field(L, -1, "strokeColor", inValue._stroke._strokeColor);
			native_to_luaval_field(L, -1, "strokeSize", inValue._stroke._strokeSize);
		}
	};

	template<>
	struct to_lua<cocos2d::Mat4> {
		static void F(lua_State* L, const cocos2d::Mat4& inValue) {
			if (!L) return;
			native_array_to_luaval(L, inValue.m, 16);
		}
	};

	template<>
	struct to_lua<cocos2d::Value> {
		static void F(lua_State* L, const cocos2d::Value& inValue) {
			if (!L) return;
			switch (inValue.getTypeFamily())
			{
			case cocos2d::Value::Type::BOOLEAN:
				lua_pushboolean(L, inValue.asBool());
				break;
			case cocos2d::Value::Type::FLOAT:
			case cocos2d::Value::Type::DOUBLE:
				lua_pushnumber(L, inValue.asDouble());
				break;
			case cocos2d::Value::Type::INTEGER:
				lua_pushinteger(L, inValue.asInt64());
				break;
			case cocos2d::Value::Type::STRING:
				native_to_luaval(L, inValue.asStringRef());
				break;
			case cocos2d::Value::Type::VECTOR:
				native_to_luaval(L, inValue.asValueVector());
				break;
			case cocos2d::Value::Type::MAP:
				native_to_luaval(L, inValue.asValueMap());
				break;
			case cocos2d::Value::Type::INT_KEY_MAP:
				native_to_luaval(L, inValue.asIntKeyMap());
				break;
			default:
				break;
			}
		}
	};

	template<>
	struct to_lua<cocos2d::backend::UniformLocation> {
		static void F(lua_State* L, const cocos2d::backend::UniformLocation& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 2);
			native_to_luaval_field(L, -1, "shaderStage", inValue.shaderStage);
			lua_pushstring(L, "location");
			native_array_to_luaval(L, inValue.location, 2);
			lua_settable(L, -3);
		}
	};

	template<>
	struct to_lua<cocos2d::backend::BlendDescriptor> {
		static void F(lua_State* L, const cocos2d::backend::BlendDescriptor& inValue) {
			if (!L) return;
			lua_createtable(L, 0, 4);
			native_to_luaval_field(L, -1, "writeMask", inValue.writeMask);
			native_to_luaval_field(L, -1, "blendEnabled", inValue.writeMask);
			native_to_luaval_field(L, -1, "rgbBlendOperation", inValue.rgbBlendOperation);
			native_to_luaval_field(L, -1, "alphaBlendOperation", inValue.alphaBlendOperation);
			native_to_luaval_field(L, -1, "sourceRGBBlendFactor", inValue.sourceRGBBlendFactor);
			native_to_luaval_field(L, -1, "destinationRGBBlendFactor", inValue.destinationRGBBlendFactor);
			native_to_luaval_field(L, -1, "sourceAlphaBlendFactor", inValue.sourceAlphaBlendFactor);
			native_to_luaval_field(L, -1, "destinationAlphaBlendFactor", inValue.destinationAlphaBlendFactor);
		}
	};
}

#ifndef LUA_INVOKE_HEADER
#define LUA_INVOKE_HEADER(CName_, FName_)\
	constexpr auto LUA_OBJ_TYPE = CName_;\
	constexpr auto LUA_FNAME = FName_;\
	const int argc = lua_gettop(lua_S) - 1;\
	int arg_cur = -1;\
	bool ok = false;
#endif // !LUA_INVOKE_HEADER

#ifndef LUA_SINVOKE_HEADER
#define LUA_SINVOKE_HEADER(CName_, FName_)\
	constexpr auto LUA_FNAME = FName_;\
	const int argc = lua_gettop(lua_S) - 1;\
	int arg_cur = -1;\
	bool ok = false;
#endif // !LUA_SINVOKE_HEADER

#ifndef LUA_GINVOKE_HEADER
#define LUA_GINVOKE_HEADER(CName_, FName_)\
	constexpr auto LUA_FNAME = FName_;\
	const int argc = lua_gettop(lua_S);\
	int arg_cur = -1;\
	bool ok = false;
#endif // !LUA_GINVOKE_HEADER

#ifndef LUA_TRY_INVOKE
#define LUA_TRY_INVOKE(ARGC_, Fn_)\
	if (argc == (ARGC_) && !ok) {\
		lua_pushvalue(lua_S, 1);\
		lua_insert(lua_S, 1);\
		ok = lua::invoke_native(lua_S, arg_cur, (Fn_));\
		if (ok) {\
			lua_settop(lua_S, 1);\
			return 1;\
		} else {\
			lua_remove(lua_S, 1);\
		}\
	}
#endif // !LUA_TRY_INVOKE

#ifndef LUA_TRY_INVOKE_R
#define LUA_TRY_INVOKE_R(ARGC_, Fn_)\
	if (argc == (ARGC_) && !ok) {\
		ok = lua::invoke_native(lua_S, arg_cur, (Fn_));\
		if (ok) return 1;\
	}
#endif // !LUA_TRY_INVOKE_R

#ifndef LUA_TRY_CTOR
#define LUA_TRY_CTOR(ARGC_, Fn_)\
	if (argc == (ARGC_) && !ok) {\
		ok = lua::invoke_native(lua_S, arg_cur, (Fn_));\
		if (ok) {\
			tolua_register_gc(lua_S, lua_gettop(lua_S));\
			return 1;\
		}\
	}
#endif // !LUA_TRY_CTOR

#ifndef LUA_INVOKE_FOOTER
#define LUA_INVOKE_FOOTER(Expected_)\
	if (arg_cur == -1)\
		return luaL_error(lua_S, "wrong number of arguments in '%s': %d, expects %s", LUA_FNAME, argc, Expected_);\
	else if (arg_cur == 0)\
		return luaL_error(lua_S, "invalid class object in '%s'", LUA_FNAME);\
	return luaL_error(lua_S, "invalid argument #%d in '%s'", arg_cur, LUA_FNAME);
#endif // !LUA_INVOKE_FOOTER

#ifndef LUA_SINVOKE_FOOTER
#define LUA_SINVOKE_FOOTER(Expected_)\
	if (arg_cur == -1)\
		return luaL_error(lua_S, "wrong number of arguments in '%s': %d, expects %s", LUA_FNAME, argc, Expected_);\
	return luaL_error(lua_S, "invalid argument #%d in '%s'", arg_cur, LUA_FNAME);
#endif // !LUA_SINVOKE_FOOTER

#ifndef LUA_GINVOKE_FOOTER
#define LUA_GINVOKE_FOOTER(Expected_) LUA_SINVOKE_FOOTER(Expected_)
#endif // !LUA_GINVOKE_FOOTER

#ifndef LUA_ENTRY
#define LUA_ENTRY(S_) tolua_module(lua_S, (S_), 0); tolua_beginmodule(lua_S, (S_));
#endif // !LUA_ENTRY

#ifndef LUA_ENTRY_END
#define LUA_ENTRY_END(N_) lua_pop(lua_S, (N_));
#endif // !LUA_ENTRY_END

#ifndef LUA_CLS_DEF
#define LUA_CLS_DEF(T_, TType_, TName_, Ctor_, Dtor_)\
	const char* typeName = (TName_);\
	const char* castName = (TType_);\
	using current_type = T_;\
	tolua_usertype(lua_S, (TName_));\
	tolua_cclass(lua_S, (TType_), (TName_), "", (Dtor_));\
	tolua_beginmodule(lua_S, (TType_));
#endif // !LUA_CLS_DEF

#ifndef LUA_CLS_DEF_BASE
#define LUA_CLS_DEF_BASE(T_, TType_, TName_, BT_, BName_, Ctor_, Dtor_)\
	const char* typeName = (TName_);\
	const char* castName = (TType_);\
	using current_type = T_;\
	tolua_usertype(lua_S, (TName_));\
	tolua_cclass(lua_S, (TType_), (TName_), (BName_), (Dtor_));\
	tolua_beginmodule(lua_S, (TType_));
#endif // !LUA_CLS_DEF_BASE

#ifndef LUA_METHOD
#define LUA_METHOD(Name_, Fn_)\
	tolua_function(lua_S, (Name_), Fn_);
#endif // !LUA_METHOD

#ifndef LUA_CLS_END
#define LUA_CLS_END()\
	tolua_endmodule(lua_S);\
	lua::registerLuaType<current_type>(typeName, castName);
#endif // !LUA_CLS_END

#ifndef LUA_TO_COBJ
#define LUA_TO_COBJ(T_, IDX_)\
	(T_)tolua_tousertype(lua_S, (IDX_), nullptr);
#endif // !LUA_TO_COBJ

#ifndef LUA_PUSH_NATIVE
#define LUA_PUSH_NATIVE(V_)\
	lua::native_to_luaval(lua_S, V_);
#endif // !LUA_PUSH_NATIVE

#ifndef LUA_NATIVE_SETTER
#define LUA_NATIVE_SETTER(V_, IDX_)\
	if (!lua::luaval_to_native(lua_S, (IDX_), &(V_), LUA_FNAME))\
		return luaL_error(lua_S, "invalid value for '%s'", LUA_FNAME);
#endif // !LUA_NATIVE_SETTER

#ifndef LUA_CUR_FNAME
#define LUA_CUR_FNAME(FName_)\
	constexpr auto LUA_FNAME = FName_;
#endif // !LUA_CUR_FNAME

#ifndef LUA_FIELD
#define LUA_FIELD(Name_, Getter_, Setter_)\
	tolua_variable(lua_S, (Name_), (Getter_), (Setter_));
#endif // !LUA_FIELD

#ifndef LUA_SFIELD
#define LUA_SFIELD(Name_, Getter_, Setter_)\
	tolua_variable(lua_S, (Name_), (Getter_), (Setter_));
#endif // !LUA_SFIELD

#ifndef LUA_CONSTANT
#define LUA_CONSTANT(Name_, V_)\
	tolua_constant(lua_S, (Name_), (lua_Number)(V_));
#endif // !LUA_CONSTANT

#ifndef LUA_ENUM_DEF
#define LUA_ENUM_DEF(Name_)\
	tolua_module(lua_S, (Name_), 0);\
	tolua_beginmodule(lua_S, (Name_));
#endif // !LUA_ENUM_DEF

#ifndef LUA_ENUM_ENTRY
#define LUA_ENUM_ENTRY(Name_, V_)\
	tolua_constant(lua_S, (Name_), (lua_Number)(V_));
#endif // !LUA_ENUM_ENTRY

#ifndef LUA_ENUM_END
#define LUA_ENUM_END()\
	tolua_endmodule(lua_S);
#endif // !LUA_ENUM_END
