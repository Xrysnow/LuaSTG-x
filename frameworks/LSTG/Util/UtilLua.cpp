﻿#include "UtilLua.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Utility.h"
#include "AppFrame.h"
#include "LogSystem.h"
#include "UtilLuaConversion.h"
#include "LuaWrapper/LuaWrapper.h"
#include "LuaWrapper/LWColor.h"
#include "Resource/ResFX.h"
#include "../../Classes/XBuffer.h"
#include "lua_conversion/lua_conversion.hpp"

using namespace std;
using namespace lstg;
using namespace cocos2d;

using ::lua::luaval_field_to_native;
using ::lua::native_to_luaval_field;
using ::lua::luaval_to_native;
using ::lua::LUA_TCDATA;

template<typename T>
bool luaval_to_integer_T(lua_State* L,
	int lo,
	std::enable_if_t<std::is_same_v<T, int64_t> || std::is_same_v<T, uint64_t>, T>* outValue,
	size_t targetSize,
	const char* funcName)
{
	if (nullptr == L || nullptr == outValue)
		return false;
	const auto type = lua_type(L, lo);
	if (type == ::lua::LUA_TCDATA)
	{
		if(std::is_same_v<T, int64_t>)
			lua_pushstring(L, "ffi.cast_int64");
		else
			lua_pushstring(L, "ffi.cast_uint64");
		lua_rawget(L, LUA_REGISTRYINDEX);
		const auto tfunc = lua_type(L, -1);
		if (tfunc == LUA_TFUNCTION)
		{
			void* ret = nullptr;
			lua_pushvalue(L, lo);
			lua_pushlightuserdata(L, &ret);
			if (lua_pcall(L, 1, 1, 0) == 0)
			{
				::lua::luaval_to_cptr(L, -1, &ret);
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
	tolua_Error tolua_err;
	bool is_number = type == LUA_TNUMBER;
	if (!is_number)
	{
		tolua_err.index = lo; tolua_err.array = 0; tolua_err.type = "number";
#if CC_DEBUG
		luaval_to_native_err(L, "#ferror:", &tolua_err, funcName);
#endif
		return false;
	}
	if (std::is_same<T, int64_t>::value && targetSize == 4)
	{
		// see luaval_to_int32
		const uint32_t estimateValue = (uint32_t)lua_tonumber(L, lo);
		if (estimateValue == (uint32_t)std::numeric_limits<int32_t>::min())
			*outValue = (int32_t)estimateValue;
		else
			*outValue = (int64_t)(int32_t)lua_tonumber(L, lo);
	}
	else
		*outValue = (T)tolua_tonumber(L, lo, 0);
	return true;
}

bool lstg::lua::_luaval_to_integer(lua_State* L, int lo, int64_t* outValue, size_t targetSize, const char* funcName)
{
	return luaval_to_integer_T<int64_t>(L, lo, outValue, targetSize, funcName);
}

bool lstg::lua::_luaval_to_unsigned_integer(lua_State* L, int lo, uint64_t* outValue, size_t targetSize, const char* funcName)
{
	return luaval_to_integer_T<uint64_t>(L, lo, outValue, targetSize, funcName);
}

LuaStack* lstg::lua::stack()
{
	return LuaEngine::getInstance()->getLuaStack();
}

int lstg::lua::StackTraceback(lua_State *L)
{
	lua_getfield(L, LUA_GLOBALSINDEX, "debug");  // errmsg t
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);
		return 1;
	}
	lua_getfield(L, -1, "traceback");  // errmsg t f
	if (!lua_isfunction(L, -1) && !lua_iscfunction(L, -1))
	{
		lua_pop(L, 2);
		return 1;
	}
	lua_pushvalue(L, 1);  // errmsg t f errmsg
	lua_pushinteger(L, 2);  // errmsg t f errmsg 2
	if (0 != lua_pcall(L, 2, 1, 0))  // errmsg t 
	{
		LWARNING("error in traceback (%s)", lua_tostring(L, -1));
		lua_pop(L, 2);
	}
	return 1;
}

int push_table_instance(lua_State* L, int lo)
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
int lstg::lua::isusertype(lua_State* L, int lo, const char* type)
{
	// note: lo must be positive
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

void* lstg::lua::_tousertype(lua_State* L, int lo)
{
	if (!lua_isuserdata(L, lo)) {
		if (!push_table_instance(L, lo))
			return nullptr;
	}
	const auto u = lua_touserdata(L, lo);
	return u ? *(void**)u : nullptr;
}

bool lstg::lua::_luaval_to_color4b(lua_State* L, int lo, Color4B* outValue, const char* funcName)
{
	if (lua_type(L, lo) == LUA_TUSERDATA)
	{
		const auto c = luaL_checkcolor(L, lo);
		if (!c)
			return false;
		// need copy because c is lua value and can be released
		*outValue = *c;
		return true;
	}
	else
	{
		return ::luaval_to_color4b(L, lo, outValue, funcName);
	}
}

void lstg::lua::_color4b_to_luaval(lua_State* L, const Color4B& cc)
{
	const auto p = ColorWrapper::CreateAndPush(L);
	*p = cc;
}

bool lstg::lua::luaval_to_V3F_C4B_T2F_Quad(lua_State* L, int lo, V3F_C4B_T2F_Quad* outValue, const char* /*funcName*/)
{
	if (!lua_istable(L, lo))return false;
	V3F_C4B_T2F_Quad ret;
	const auto p = (V3F_C4B_T2F*)&ret;
	for (auto i = 0; i < 4; ++i)
	{
		lua_rawgeti(L, lo, i + 1);
		if (!lua_istable(L, -1))return false;
		lua_rawgeti(L, -1, 4);
		Color4B color;
		if (!_luaval_to_color4b(L, -1, &color))
			return false;
		lua_pop(L, 1);
		lua_rawgeti(L, -1, 1);
		lua_rawgeti(L, -2, 2);
		lua_rawgeti(L, -3, 3);
		p[i].vertices.x = lua_tonumber(L, -3);
		p[i].vertices.y = lua_tonumber(L, -2);
		p[i].vertices.z = lua_tonumber(L, -1);
		lua_pop(L, 3);
		lua_rawgeti(L, -1, 1);
		lua_rawgeti(L, -2, 2);
		p[i].texCoords.u = lua_tonumber(L, -2);
		p[i].texCoords.v = lua_tonumber(L, -1);
		lua_pop(L, 2);
	}
	*outValue = ret;
	return true;
}

void lstg::lua::V3F_C4B_T2F_Quad_to_luaval(lua_State* L, const V3F_C4B_T2F_Quad& inValue)
{
	lua_createtable(L, 0, 4);
	const auto p = reinterpret_cast<const V3F_C4B_T2F*>(&inValue);
	for (auto i = 0; i < 4; ++i)
	{
		const auto v = p[i];
		lua_createtable(L, 6, 0);
		lua_pushnumber(L, v.vertices.x);
		lua_rawseti(L, -2, 1);
		lua_pushnumber(L, v.vertices.y);
		lua_rawseti(L, -2, 2);
		lua_pushnumber(L, v.vertices.z);
		lua_rawseti(L, -2, 3);
		_color4b_to_luaval(L, v.colors);
		lua_rawseti(L, -2, 4);
		lua_pushnumber(L, v.texCoords.u);
		lua_rawseti(L, -2, 5);
		lua_pushnumber(L, v.texCoords.v);
		lua_rawseti(L, -2, 6);
		lua_rawseti(L, -2, i + 1);
	}
}

bool lstg::lua::luaval_to_UniformLocation(lua_State* L, int lo, backend::UniformLocation* outValue,
	const char* funcName)
{
	if (!lua_istable(L, lo))
		return false;
	std::vector<int> loc;
	backend::ShaderStage stage;
	if (!luaval_field_to_native(L, lo, "location", &loc, funcName) ||
		!luaval_field_to_native(L, lo, "shaderStage", &stage, funcName))
		return false;
	for (auto i = 0u; i < std::min((size_t)2, loc.size()); ++i)
		outValue->location[i] = loc.at(i);
	outValue->shaderStage = stage;
	return true;
}

void lstg::lua::UniformLocation_to_luaval(lua_State* L, const backend::UniformLocation& inValue)
{
	lua_createtable(L, 0, 2);
	const std::array<int, 2> arr = { inValue.location[0],inValue.location[1] };
	native_to_luaval_field(L, -1, "location", arr);
	native_to_luaval_field(L, -1, "shaderStage", inValue.shaderStage);
}

bool lstg::lua::luaval_to_SamplerDescriptor(lua_State* L, int lo, backend::SamplerDescriptor* outValue,
	const char* funcName)
{
	if (!lua_istable(L, lo))
		return false;
	const auto old = *outValue;
	if (!luaval_field_to_native(L, lo, "magFilter", &outValue->magFilter, funcName) ||
		!luaval_field_to_native(L, lo, "minFilter", &outValue->minFilter, funcName) ||
		!luaval_field_to_native(L, lo, "sAddressMode", &outValue->sAddressMode, funcName) ||
		!luaval_field_to_native(L, lo, "tAddressMode", &outValue->tAddressMode, funcName))
	{
		*outValue = old;
		return false;
	}
	return true;
}

void lstg::lua::SamplerDescriptor_to_luaval(lua_State* L, const backend::SamplerDescriptor& inValue)
{
	lua_createtable(L, 0, 4);
	native_to_luaval_field(L, -1, "magFilter", inValue.magFilter);
	native_to_luaval_field(L, -1, "minFilter", inValue.minFilter);
	native_to_luaval_field(L, -1, "sAddressMode", inValue.sAddressMode);
	native_to_luaval_field(L, -1, "tAddressMode", inValue.tAddressMode);
}

bool lstg::lua::luaval_to_AttributeBindInfo(lua_State* L, int lo, backend::AttributeBindInfo* outValue,
	const char* funcName)
{
	if (!lua_istable(L, lo))
		return false;
	const auto old = *outValue;
	if (!luaval_field_to_native(L, lo, "attributeName", &outValue->attributeName, funcName) ||
		!luaval_field_to_native(L, lo, "location", &outValue->location, funcName) ||
		!luaval_field_to_native(L, lo, "size", &outValue->size, funcName) ||
		!luaval_field_to_native(L, lo, "type", &outValue->type, funcName))
	{
		*outValue = old;
		return false;
	}
	return true;
}

void lstg::lua::AttributeBindInfo_to_luaval(lua_State* L, const backend::AttributeBindInfo& inValue)
{
	lua_createtable(L, 0, 4);
	native_to_luaval_field(L, -1, "attributeName", inValue.attributeName);
	native_to_luaval_field(L, -1, "location", inValue.location);
	native_to_luaval_field(L, -1, "size", inValue.size);
	native_to_luaval_field(L, -1, "type", inValue.type);
}

bool lstg::lua::luaval_to_Viewport(lua_State* L, int lo, Viewport* outValue, const char* funcName)
{
	if (!lua_istable(L, lo))
		return false;
	const auto old = *outValue;
	if (!luaval_field_to_native(L, lo, "x", &outValue->x, funcName) ||
		!luaval_field_to_native(L, lo, "y", &outValue->y, funcName) ||
		!luaval_field_to_native(L, lo, "w", &outValue->w, funcName) ||
		!luaval_field_to_native(L, lo, "h", &outValue->h, funcName))
	{
		*outValue = old;
		return false;
	}
	return true;
}

void lstg::lua::Viewport_to_luaval(lua_State* L, const Viewport& inValue)
{
	lua_createtable(L, 0, 4);
	native_to_luaval_field(L, -1, "x", inValue.x);
	native_to_luaval_field(L, -1, "y", inValue.y);
	native_to_luaval_field(L, -1, "w", inValue.w);
	native_to_luaval_field(L, -1, "h", inValue.h);
}

bool lstg::lua::luaval_to_BlendDescriptor(lua_State* L, int lo, backend::BlendDescriptor* outValue,
	const char* funcName)
{
	if (!lua_istable(L, lo))
		return false;
	const auto old = *outValue;
	if (!luaval_field_to_native(L, lo, "src", &outValue->sourceRGBBlendFactor, funcName) ||
		!luaval_field_to_native(L, lo, "srcAlpha", &outValue->sourceAlphaBlendFactor, funcName) ||
		!luaval_field_to_native(L, lo, "dst", &outValue->destinationRGBBlendFactor, funcName) ||
		!luaval_field_to_native(L, lo, "dstAlpha", &outValue->destinationAlphaBlendFactor, funcName))
	{
		*outValue = old;
		return false;
	}
	return true;
}

void lstg::lua::BlendDescriptor_to_luaval(lua_State* L, const backend::BlendDescriptor& inValue)
{
	lua_createtable(L, 0, 4);
	native_to_luaval_field(L, -1, "src", inValue.sourceRGBBlendFactor);
	native_to_luaval_field(L, -1, "srcAlpha", inValue.sourceAlphaBlendFactor);
	native_to_luaval_field(L, -1, "dst", inValue.destinationRGBBlendFactor);
	native_to_luaval_field(L, -1, "dstAlpha", inValue.destinationAlphaBlendFactor);
}

bool lstg::lua::luaval_to_RenderMode(lua_State* L, int lo, RenderMode** outValue, const char* /*funcName*/)
{
	if (!outValue)
		return false;
	const auto type = lua_type(L, lo);
	RenderMode* b = nullptr;
	if (type == LUA_TNUMBER)
		b = RenderMode::getByID(luaL_checkinteger(L, lo));
	else if (type == LUA_TSTRING)
	{
		size_t size;
		const auto s = luaL_checklstring(L, lo, &size);
		b = RenderMode::getByName({ s,size });
	}
	else
	{
		b = tousertype<RenderMode>(
			L, lo, ::lua::getClassNameByType<RenderMode>().c_str());
		if(!b)
		{
			const auto res = tousertype<ResFX>(
				L, lo, ::lua::getClassNameByType<ResFX>().c_str());
			if (res)
				b = res->getRenderMode();
		}
	}
	if (!b)
		return false;
	*outValue = b;
	return true;
}

bool lstg::lua::luaval_to_ColliderType(lua_State* L, int lo, XColliderType* outValue, const char* /*funcName*/)
{
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
	{
		size_t size;
		const auto s = luaL_checklstring(L, lo, &size);
		const auto v = xmath::collision::from_string({ s,size });
		if (v == XColliderType::ColliderTypeNum)
			return false;
		*outValue = v;
		return true;
	}
	else if (type == LUA_TBOOLEAN)
	{
		if (lua_toboolean(L, lo))
			*outValue = XColliderType::OBB;
		else
			*outValue = XColliderType::Circle;
		return true;
	}
	else if (type == LUA_TNUMBER)
	{
		const auto i = luaL_checkinteger(L, lo);
		if (i < 0 || i >= (int)XColliderType::ColliderTypeNum)
			return false;
		*outValue = (XColliderType)i;
		return true;
	}
	return false;
}

void lstg::lua::ColliderType_to_luaval(lua_State* L, XColliderType colliderType)
{
	if (colliderType != XColliderType::Circle)
		lua_pushinteger(L, (lua_Integer)colliderType);
	else
		lua_pushboolean(L, false);
}

bool lstg::lua::luaval_to_GameObject(lua_State* L, int lo, GameObject** outValue, const char* /*funcName*/)
{
	const auto type = lua_type(L, lo);
	if (type == LUA_TTABLE)
	{
		lua_rawgeti(L, lo, 2);
		if (!lua_isnumber(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
		const auto id = size_t(lua_tonumber(L, -1));
		lua_pop(L, 1);
		const auto ret = LPOOL.GetPooledObject(id);
		if (ret&&ret->status != STATUS_FREE)
		{
			*outValue = ret;
			return true;
		}
	}
	if (type == LUA_TCDATA)
		return luaval_to_cptr(L, lo, (void**)outValue);
	return false;
}

void lstg::lua::GameObject_to_luaval(lua_State* L, GameObject* obj)
{
	LPOOL.pushObject(L, obj);
	//lua::cptr_to_luaval(L, obj);
}

void lstg::lua::BaseLight_to_luaval(lua_State* L, BaseLight* light)
{
	if (light)
	{
		string type = "cc.BaseLight";
		switch (light->getLightType())
		{
		case LightType::DIRECTIONAL: type = "cc.DirectionLight"; break;
		case LightType::POINT: type = "cc.PointLight"; break;
		case LightType::SPOT: type = "cc.SpotLight"; break;
		case LightType::AMBIENT: type = "cc.AmbientLight"; break;
		default: ;
		}
		object_to_luaval<BaseLight>(L, type.c_str(), light);
	}
	else
		lua_pushnil(L);
}

bool lstg::lua::luaval_to_cptr(lua_State* L, int lo, void** outValue)
{
	const auto top = lua_gettop(L);
	if (lo < 0)
		lo = top + 1 + lo;
	if (lo<1 || lo>top)
	{
		*outValue = nullptr;
		return false;
	}
	lua_pushstring(L, "ffi.convert_ptr");
	lua_rawget(L, LUA_REGISTRYINDEX);
	const auto tfunc = lua_type(L, -1);
	if (tfunc == LUA_TFUNCTION)
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

void lstg::lua::cptr_to_luaval(lua_State* L, void* ptr)
{
	if (!ptr)
		lua_pushnil(L);
	else
		lua_pushlightuserdata(L, ptr);
}

void lstg::lua::cptr_to_luaval(lua_State* L, void* ptr, const std::string& ptrType)
{
	if (!ptr)
		lua_pushnil(L);
	else
	{
		lua_pushstring(L, "ffi.cast_ptr");
		lua_rawget(L, LUA_REGISTRYINDEX);
		lua_pushlightuserdata(L, ptr);
		lua_pushlstring(L, ptrType.c_str(), ptrType.size());
		if (lua_pcall(L, 2, 1, 0) != 0)
		{
			lua_pop(L, 1);
			lua_pushnil(L);
		}
	}
}

void lstg::lua::V3F_C4B_T2F_ptr_to_luaval(lua_State* L, V3F_C4B_T2F* ptr)
{
	if (!ptr)
		lua_pushnil(L);
	else
	{
		lua_pushstring(L, "ffi.cast_ptr_vert");
		lua_rawget(L, LUA_REGISTRYINDEX);
		lua_pushlightuserdata(L, ptr);
		if (lua_pcall(L, 1, 1, 0) != 0)
		{
			LERROR("failed to call ffi.cast_ptr_vert");
		}
	}
}

bool lstg::lua::luaval_to_async_callback(lua_State* L, int lo, std::function<void()>* outValue)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, lo, 0);
	if (handler == 0)
		return false;
	if (outValue)
	{
		*outValue = [=]()
		{
			LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 0);
			// async_callback will ba called only once
			LuaEngine::getInstance()->removeScriptHandler(handler);
		};
	}
	return true;
}

void lstg::lua::ref_type_to_luaval(lua_State* L, Ref* ref, const char* typeID)
{
	if (ref)
	{
		const auto typeName = typeID ? typeID : typeid(*ref).name();
		const auto iter = g_luaType.find(reinterpret_cast<uintptr_t>(typeName));
		auto type = "cc.Ref";
		if (g_luaType.end() != iter)
			type = iter->second;
		toluafix_pushusertype_ccobject(
			L, (int)ref->_ID, &ref->_luaID, (void*)ref, type);
	}
	else
	{
		lua_pushnil(L);
	}
}

const void* lstg::lua::luaval_to_const_data(lua_State* L, int lo, int lo_size, size_t* outSize)
{
	const void* data = nullptr;
	size_t size = 0;
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
	{
		data = lua_tolstring(L, lo, &size);
	}
	else if (type == LUA_TCDATA)
	{
		void* p = nullptr;
		luaval_to_cptr(L, lo, &p);
		if (p)
		{
			data = p;
			const auto size_ = luaL_checkinteger(L, lo_size);
			if (size_ > 0)
				size = size_;
		}
	}
	else
	{
		Buffer* buf = nullptr;
		if (luaval_to_native(L, lo, &buf) && buf)
		{
			data = buf->data();
			size = buf->size();
		}
	}
	*outSize = size;
	return data;
}

std::vector<float> lstg::lua::getArray(lua_State* L, int lo, const char* field)
{
	const auto len = lua_objlen(L, lo);
	std::vector<float> ret;
	ret.reserve(len);
	for (size_t i = 1; i <= len; i++)
	{
		lua_rawgeti(L, lo, i);
		lua_getfield(L, -1, field);
		ret.push_back(luaL_checknumber(L, -1));
		lua_pop(L, 1);
	}
	return ret;
}

std::vector<Vec2> lstg::lua::getVec2Array(lua_State* L, int lo)
{
	const auto len = lua_objlen(L, lo);
	std::vector<Vec2> ret;
	ret.reserve(len);
	for (size_t i = 1; i <= len; i++)
	{
		lua_rawgeti(L, lo, i);
		lua_rawgeti(L, -1, 1);
		const auto x = luaL_checknumber(L, -1);
		lua_rawgeti(L, -1, 2);
		const auto y = luaL_checknumber(L, -1);
		ret.emplace_back(x, y);
		lua_pop(L, 1);
	}
	return ret;
}

std::vector<Vec2> lstg::lua::getVec2Array(lua_State* L, int lo, const char* k1, const char* k2)
{
	const auto len = lua_objlen(L, lo);
	std::vector<Vec2> ret;
	ret.reserve(len);
	for (size_t i = 1; i <= len; i++)
	{
		lua_rawgeti(L, lo, i);
		lua_getfield(L, -1, k1);
		const auto x = luaL_checknumber(L, -1);
		lua_getfield(L, -1, k2);
		const auto y= luaL_checknumber(L, -1);
		ret.emplace_back(x, y);
		lua_pop(L, 1);
	}
	return ret;
}

int lstg::lua::pushCArray(lua_State* L, lua_Number* arr, uint32_t size)
{
	if (!arr || size == 0)return 0;
	lua_pushstring(L, "ffi.alloc_arr");
	lua_rawget(L, LUA_REGISTRYINDEX);
	const auto tfunc = lua_type(L, -1);
	if (tfunc == LUA_TFUNCTION)
	{
		lua_pushinteger(L, size);
		if (lua_pcall(L, 1, 1, 0) == 0)
		{
			void* p;
			if (luaval_to_cptr(L, -1, &p))
			{
				std::memcpy(p, arr, size * sizeof(lua_Number));
				return 1;
			}
			else
			{
				lua_pop(L, 1);
				LERROR("error when call luaval_to_cptr");
			}
		}
		else
		{
			LERROR("error when call ffi.alloc_arr");
		}
	}
	else
		lua_pop(L, 1);
	return 0;
}

// LJ_GC64 is off by default on win64
#if CC_64BITS && CC_TARGET_PLATFORM != CC_PLATFORM_WIN32
#define HASH_OFFSET (-3)
#else
#define HASH_OFFSET (-2)
#endif

const char* lstg::lua::checkstring(lua_State* L, int lo, size_t* strlen, uint32_t* hash)
{
	const auto ret = luaL_checklstring(L, lo, strlen);
	// hack into lua
	if (hash)
		*hash = reinterpret_cast<const uint32_t*>(ret)[HASH_OFFSET];
	return ret;
}

const char* lstg::lua::tostring(lua_State* L, int lo, size_t* strlen, uint32_t* hash)
{
	const auto ret = lua_tolstring(L, lo, strlen);
	if (hash)
		*hash = reinterpret_cast<const uint32_t*>(ret)[HASH_OFFSET];
	return ret;
}

std::string lstg::lua::getClassNameByTypeID(const char* typeID)
{
	const auto it = g_luaType.find(reinterpret_cast<uintptr_t>(typeID));
	if (it != g_luaType.end())
		return it->second;
	return "";
}
