#include "lua_Resource_auto.hpp"
#include "Resource/GameResources.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"

using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b

#ifndef LUA_CHECK_COBJ_TYPE
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) if(!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
	#else
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) (void)(TYPE);
	#endif
#endif
#ifndef LUA_CHECK_COBJ
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ(L, COBJ, NAME) if(!(COBJ)) { return luaL_error((L), "invalid 'cobj' in '%s'", NAME); }
	#else
		#define LUA_CHECK_COBJ(L, COBJ, NAME)
	#endif
#endif
#ifndef LUA_CHECK_PARAMETER
	#define LUA_CHECK_PARAMETER(L, OK, NAME) if(!(OK)) { return luaL_error((L), "invalid arguments in '%s'", NAME); }
#endif
#ifndef LUA_PARAMETER_ERROR
	#define LUA_PARAMETER_ERROR(L, NAME, ARGC, EXPECT) return luaL_error((L), "wrong number of arguments in '%s': %d, expects %s", NAME, (ARGC), EXPECT);
#endif


int lua_x_Resource_Resource_getInfo(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Resource";
	constexpr auto LUA_FNAME = "lstg.Resource:getInfo";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Resource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInfo();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_Resource_getName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Resource";
	constexpr auto LUA_FNAME = "lstg.Resource:getName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Resource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getName();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_Resource_getPath(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Resource";
	constexpr auto LUA_FNAME = "lstg.Resource:getPath";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Resource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPath();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_Resource_getType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Resource";
	constexpr auto LUA_FNAME = "lstg.Resource:getType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Resource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Resource_Resource_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_Resource(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.Resource");
	tolua_cclass(tolua_S, "Resource", "lstg.Resource", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Resource");
		tolua_function(tolua_S, "getInfo", lua_x_Resource_Resource_getInfo);
		tolua_function(tolua_S, "getName", lua_x_Resource_Resource_getName);
		tolua_function(tolua_S, "getPath", lua_x_Resource_Resource_getPath);
		tolua_function(tolua_S, "getType", lua_x_Resource_Resource_getType);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::Resource).name();
	g_luaType[typeName] = "lstg.Resource";
	g_typeCast["Resource"] = "lstg.Resource";
	return 1;
}

int lua_x_Resource_ResourceColliable_getColliderType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceColliable";
	constexpr auto LUA_FNAME = "lstg.ResourceColliable:getColliderType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColliderType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResourceColliable_getHalfSizeX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceColliable";
	constexpr auto LUA_FNAME = "lstg.ResourceColliable:getHalfSizeX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHalfSizeX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResourceColliable_getHalfSizeY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceColliable";
	constexpr auto LUA_FNAME = "lstg.ResourceColliable:getHalfSizeY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHalfSizeY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Resource_ResourceColliable_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResourceColliable(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResourceColliable");
	tolua_cclass(tolua_S, "ResourceColliable", "lstg.ResourceColliable", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResourceColliable");
		tolua_function(tolua_S, "getColliderType", lua_x_Resource_ResourceColliable_getColliderType);
		tolua_function(tolua_S, "getHalfSizeX", lua_x_Resource_ResourceColliable_getHalfSizeX);
		tolua_function(tolua_S, "getHalfSizeY", lua_x_Resource_ResourceColliable_getHalfSizeY);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResourceColliable).name();
	g_luaType[typeName] = "lstg.ResourceColliable";
	g_typeCast["ResourceColliable"] = "lstg.ResourceColliable";
	return 1;
}

int lua_x_Resource_ResourceQuad_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor(arg0);
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_x_Resource_ResourceQuad_getRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:getRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRenderMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResourceQuad_getVertex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:getVertex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVertex();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResourceQuad_setAlpha(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:setAlpha";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		uint16_t arg0;
		ok &= luaval_to_uint16(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlpha(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResourceQuad_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			cocos2d::Color4B arg0;
			ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			int arg1;
			ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->setColor(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Color4B arg0;
			ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->setColor(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResourceQuad_setRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:setRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::RenderMode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRenderMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResourceQuad_setVertex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceQuad";
	constexpr auto LUA_FNAME = "lstg.ResourceQuad:setVertex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::V3F_C4B_T2F_Quad arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResourceQuad_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResourceQuad(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResourceQuad");
	tolua_cclass(tolua_S, "ResourceQuad", "lstg.ResourceQuad", "lstg.ResourceColliable", nullptr);

	tolua_beginmodule(tolua_S, "ResourceQuad");
		tolua_function(tolua_S, "getColor", lua_x_Resource_ResourceQuad_getColor);
		tolua_function(tolua_S, "getRenderMode", lua_x_Resource_ResourceQuad_getRenderMode);
		tolua_function(tolua_S, "getVertex", lua_x_Resource_ResourceQuad_getVertex);
		tolua_function(tolua_S, "setAlpha", lua_x_Resource_ResourceQuad_setAlpha);
		tolua_function(tolua_S, "setColor", lua_x_Resource_ResourceQuad_setColor);
		tolua_function(tolua_S, "setRenderMode", lua_x_Resource_ResourceQuad_setRenderMode);
		tolua_function(tolua_S, "setVertex", lua_x_Resource_ResourceQuad_setVertex);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResourceQuad).name();
	g_luaType[typeName] = "lstg.ResourceQuad";
	g_typeCast["ResourceQuad"] = "lstg.ResourceQuad";
	return 1;
}

int lua_x_Resource_ResTexture_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResTexture::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResTexture_createWithTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:createWithTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Texture2D* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResTexture::createWithTexture(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResTexture_getTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:getTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTexture();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResTexture_getTriangles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:getTriangles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTriangles();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResTexture_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			lstg::RenderMode* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::V3F_C4B_T2F_Quad arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, "LUA_FNAME");
			if (!ok) { break; }
			auto ret = cobj->render(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::V3F_C4B_T2F_Quad arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
			if (!ok) { break; }
			auto ret = cobj->render(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResTexture_setTriangles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResTexture";
	constexpr auto LUA_FNAME = "lstg.ResTexture:setTriangles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::Triangles* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTriangles(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResTexture_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResTexture(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResTexture");
	tolua_cclass(tolua_S, "ResTexture", "lstg.ResTexture", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResTexture");
		tolua_function(tolua_S, "getTexture", lua_x_Resource_ResTexture_getTexture);
		tolua_function(tolua_S, "getTriangles", lua_x_Resource_ResTexture_getTriangles);
		tolua_function(tolua_S, "render", lua_x_Resource_ResTexture_render);
		tolua_function(tolua_S, "setTriangles", lua_x_Resource_ResTexture_setTriangles);
		tolua_function(tolua_S, "create", lua_x_Resource_ResTexture_create);
		tolua_function(tolua_S, "createWithTexture", lua_x_Resource_ResTexture_createWithTexture);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResTexture).name();
	g_luaType[typeName] = "lstg.ResTexture";
	g_typeCast["ResTexture"] = "lstg.ResTexture";
	return 1;
}

int lua_x_Resource_ResAnimation_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 12) {
		std::string arg0;
		lstg::ResTexture* arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		int arg6;
		int arg7;
		int arg8;
		double arg9;
		double arg10;
		xmath::collision::ColliderType arg11;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 8, &arg6, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 9, &arg7, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 10, &arg8, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 11, &arg9, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 12, &arg10, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 13, &arg11, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResAnimation::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "12");
}
int lua_x_Resource_ResAnimation_getCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:getCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAnimation_getInterval(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:getInterval";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInterval();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAnimation_getSprite(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:getSprite";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSprite(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResAnimation_getVertex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:getVertex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVertex(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResAnimation_newCocosAnimation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:newCocosAnimation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->newCocosAnimation();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAnimation_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		int arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 4) {
		int arg0;
		double arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 5) {
		int arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 6) {
		int arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3 to 6");
}
int lua_x_Resource_ResAnimation_setInterval(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:setInterval";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setInterval(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResAnimation_setVertex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAnimation";
	constexpr auto LUA_FNAME = "lstg.ResAnimation:setVertex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::V3F_C4B_T2F_Quad arg0;
		unsigned int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertex(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_x_Resource_ResAnimation_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResAnimation(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResAnimation");
	tolua_cclass(tolua_S, "ResAnimation", "lstg.ResAnimation", "lstg.ResourceQuad", nullptr);

	tolua_beginmodule(tolua_S, "ResAnimation");
		tolua_function(tolua_S, "getCount", lua_x_Resource_ResAnimation_getCount);
		tolua_function(tolua_S, "getInterval", lua_x_Resource_ResAnimation_getInterval);
		tolua_function(tolua_S, "getSprite", lua_x_Resource_ResAnimation_getSprite);
		tolua_function(tolua_S, "getVertex", lua_x_Resource_ResAnimation_getVertex);
		tolua_function(tolua_S, "newCocosAnimation", lua_x_Resource_ResAnimation_newCocosAnimation);
		tolua_function(tolua_S, "render", lua_x_Resource_ResAnimation_render);
		tolua_function(tolua_S, "setInterval", lua_x_Resource_ResAnimation_setInterval);
		tolua_function(tolua_S, "setVertex", lua_x_Resource_ResAnimation_setVertex);
		tolua_function(tolua_S, "create", lua_x_Resource_ResAnimation_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResAnimation).name();
	g_luaType[typeName] = "lstg.ResAnimation";
	g_typeCast["ResAnimation"] = "lstg.ResAnimation";
	return 1;
}

int lua_x_Resource_ResSprite_clone(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:clone";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->clone(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResSprite_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 9) {
		std::string arg0;
		lstg::ResTexture* arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		double arg6;
		double arg7;
		xmath::collision::ColliderType arg8;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 8, &arg6, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 9, &arg7, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 10, &arg8, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResSprite::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "9");
}
int lua_x_Resource_ResSprite_createWithSprite(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:createWithSprite";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 5) {
		std::string arg0;
		cocos2d::Sprite* arg1;
		double arg2;
		double arg3;
		xmath::collision::ColliderType arg4;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResSprite::createWithSprite(arg0, arg1, arg2, arg3, arg4);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5");
}
int lua_x_Resource_ResSprite_getNormalMap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:getNormalMap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNormalMap();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResSprite_getSprite(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:getSprite";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSprite();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResSprite_getTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:getTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTexture();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResSprite_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 3) {
		double arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 4) {
		double arg0;
		double arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 5) {
		double arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 6) {
		double arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2 to 6");
}
int lua_x_Resource_ResSprite_render4v(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:render4v";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 12) {
		double arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		double arg6;
		double arg7;
		double arg8;
		double arg9;
		double arg10;
		double arg11;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 8, &arg6, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 9, &arg7, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 10, &arg8, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 11, &arg9, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 12, &arg10, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 13, &arg11, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render4v(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "12");
}
int lua_x_Resource_ResSprite_renderRect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:renderRect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4) {
		double arg0;
		double arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->renderRect(arg0, arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
int lua_x_Resource_ResSprite_setNormalMap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSprite";
	constexpr auto LUA_FNAME = "lstg.ResSprite:setNormalMap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Texture2D* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNormalMap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResSprite_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResSprite(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResSprite");
	tolua_cclass(tolua_S, "ResSprite", "lstg.ResSprite", "lstg.ResourceQuad", nullptr);

	tolua_beginmodule(tolua_S, "ResSprite");
		tolua_function(tolua_S, "clone", lua_x_Resource_ResSprite_clone);
		tolua_function(tolua_S, "getNormalMap", lua_x_Resource_ResSprite_getNormalMap);
		tolua_function(tolua_S, "getSprite", lua_x_Resource_ResSprite_getSprite);
		tolua_function(tolua_S, "getTexture", lua_x_Resource_ResSprite_getTexture);
		tolua_function(tolua_S, "render", lua_x_Resource_ResSprite_render);
		tolua_function(tolua_S, "render4v", lua_x_Resource_ResSprite_render4v);
		tolua_function(tolua_S, "renderRect", lua_x_Resource_ResSprite_renderRect);
		tolua_function(tolua_S, "setNormalMap", lua_x_Resource_ResSprite_setNormalMap);
		tolua_function(tolua_S, "create", lua_x_Resource_ResSprite_create);
		tolua_function(tolua_S, "createWithSprite", lua_x_Resource_ResSprite_createWithSprite);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResSprite).name();
	g_luaType[typeName] = "lstg.ResSprite";
	g_typeCast["ResSprite"] = "lstg.ResSprite";
	return 1;
}

int lua_x_Resource_ResParticle_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResParticle";
	constexpr auto LUA_FNAME = "lstg.ResParticle:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 6) {
		std::string arg0;
		std::string arg1;
		lstg::ResSprite* arg2;
		double arg3;
		double arg4;
		xmath::collision::ColliderType arg5;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResParticle::create(arg0, arg1, arg2, arg3, arg4, arg5);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "6");
}
int lua_x_Resource_ResParticle_getBindSprite(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResParticle";
	constexpr auto LUA_FNAME = "lstg.ResParticle:getBindSprite";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResParticle*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBindSprite();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResParticle_getRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResParticle";
	constexpr auto LUA_FNAME = "lstg.ResParticle:getRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResParticle*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRenderMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResParticle_newCocosParticle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResParticle";
	constexpr auto LUA_FNAME = "lstg.ResParticle:newCocosParticle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResParticle*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->newCocosParticle();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Resource_ResParticle_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResParticle(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResParticle");
	tolua_cclass(tolua_S, "ResParticle", "lstg.ResParticle", "lstg.ResourceColliable", nullptr);

	tolua_beginmodule(tolua_S, "ResParticle");
		tolua_function(tolua_S, "getBindSprite", lua_x_Resource_ResParticle_getBindSprite);
		tolua_function(tolua_S, "getRenderMode", lua_x_Resource_ResParticle_getRenderMode);
		tolua_function(tolua_S, "newCocosParticle", lua_x_Resource_ResParticle_newCocosParticle);
		tolua_function(tolua_S, "create", lua_x_Resource_ResParticle_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResParticle).name();
	g_luaType[typeName] = "lstg.ResParticle";
	g_typeCast["ResParticle"] = "lstg.ResParticle";
	return 1;
}

int lua_x_Resource_ResFont_HGE2BMF(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:HGE2BMF";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFont::HGE2BMF(arg0, arg1);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFont_calcSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:calcSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->calcSize(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_createBMF(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:createBMF";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFont::createBMF(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFont_createHGE(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:createHGE";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFont::createHGE(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFont_createLabel(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:createLabel";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->createLabel();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_createTTF(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:createTTF";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		std::string arg1;
		double arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFont::createTTF(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Resource_ResFont_disableAllEffects(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableAllEffects";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableAllEffects();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableBold(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableBold";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableBold();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableGlow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableGlow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableGlow();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableItalics(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableItalics";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableItalics();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableOutline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableOutline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableOutline();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableShadow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableShadow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableShadow();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableStrikethrough(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableStrikethrough";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableStrikethrough();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_disableUnderline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:disableUnderline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableUnderline();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_enableBold(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableBold";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableBold();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_enableGlow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableGlow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableGlow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_enableItalics(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableItalics";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableItalics();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_enableOutline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableOutline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableOutline(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		cocos2d::Color4B arg0;
		int arg1;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableOutline(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_x_Resource_ResFont_enableShadow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableShadow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableShadow();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableShadow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		cocos2d::Color4B arg0;
		cocos2d::Size arg1;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_size(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableShadow(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		cocos2d::Color4B arg0;
		cocos2d::Size arg1;
		int arg2;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_size(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableShadow(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 3");
}
int lua_x_Resource_ResFont_enableStrikethrough(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableStrikethrough";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableStrikethrough();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_enableUnderline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:enableUnderline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableUnderline();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getFontAscender(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getFontAscender";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFontAscender();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getGlowColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getGlowColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getGlowColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getHAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getHAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getLabel(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getLabel";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLabel();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getLabelType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getLabelType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLabelType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getOutlineColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getOutlineColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOutlineColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getOutlineSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getOutlineSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOutlineSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRenderMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getShadowBlurRadius(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getShadowBlurRadius";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getShadowBlurRadius();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getShadowColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getShadowColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getShadowColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getShadowOffset(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getShadowOffset";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getShadowOffset();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getTTFConfig(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getTTFConfig";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTTFConfig();
		ttfconfig_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_getVAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:getVAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isBold(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isBold";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isBold();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isGlowed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isGlowed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isGlowed();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isItalics(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isItalics";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isItalics();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isOutlined(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isOutlined";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isOutlined();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isShadowed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isShadowed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isShadowed();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isStrikethrough(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isStrikethrough";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isStrikethrough();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_isUnderlined(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:isUnderlined";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isUnderlined();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFont_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 4) {
		std::string arg0;
		double arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 5) {
		std::string arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 6) {
		std::string arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 7) {
		std::string arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		double arg6;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 8, &arg6, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3 to 7");
}
int lua_x_Resource_ResFont_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setHAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setHAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextHAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setHAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setOutlineColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setOutlineColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOutlineColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setOutlineSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setOutlineSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOutlineSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::RenderMode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRenderMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setTTFConfig(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setTTFConfig";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::_ttfConfig arg0;
		ok &= luaval_to_ttfconfig(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTTFConfig(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFont_setVAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFont";
	constexpr auto LUA_FNAME = "lstg.ResFont:setVAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFont*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextVAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResFont_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResFont(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResFont");
	tolua_cclass(tolua_S, "ResFont", "lstg.ResFont", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResFont");
		tolua_function(tolua_S, "calcSize", lua_x_Resource_ResFont_calcSize);
		tolua_function(tolua_S, "createLabel", lua_x_Resource_ResFont_createLabel);
		tolua_function(tolua_S, "disableAllEffects", lua_x_Resource_ResFont_disableAllEffects);
		tolua_function(tolua_S, "disableBold", lua_x_Resource_ResFont_disableBold);
		tolua_function(tolua_S, "disableGlow", lua_x_Resource_ResFont_disableGlow);
		tolua_function(tolua_S, "disableItalics", lua_x_Resource_ResFont_disableItalics);
		tolua_function(tolua_S, "disableOutline", lua_x_Resource_ResFont_disableOutline);
		tolua_function(tolua_S, "disableShadow", lua_x_Resource_ResFont_disableShadow);
		tolua_function(tolua_S, "disableStrikethrough", lua_x_Resource_ResFont_disableStrikethrough);
		tolua_function(tolua_S, "disableUnderline", lua_x_Resource_ResFont_disableUnderline);
		tolua_function(tolua_S, "enableBold", lua_x_Resource_ResFont_enableBold);
		tolua_function(tolua_S, "enableGlow", lua_x_Resource_ResFont_enableGlow);
		tolua_function(tolua_S, "enableItalics", lua_x_Resource_ResFont_enableItalics);
		tolua_function(tolua_S, "enableOutline", lua_x_Resource_ResFont_enableOutline);
		tolua_function(tolua_S, "enableShadow", lua_x_Resource_ResFont_enableShadow);
		tolua_function(tolua_S, "enableStrikethrough", lua_x_Resource_ResFont_enableStrikethrough);
		tolua_function(tolua_S, "enableUnderline", lua_x_Resource_ResFont_enableUnderline);
		tolua_function(tolua_S, "getColor", lua_x_Resource_ResFont_getColor);
		tolua_function(tolua_S, "getFontAscender", lua_x_Resource_ResFont_getFontAscender);
		tolua_function(tolua_S, "getGlowColor", lua_x_Resource_ResFont_getGlowColor);
		tolua_function(tolua_S, "getHAlign", lua_x_Resource_ResFont_getHAlign);
		tolua_function(tolua_S, "getLabel", lua_x_Resource_ResFont_getLabel);
		tolua_function(tolua_S, "getLabelType", lua_x_Resource_ResFont_getLabelType);
		tolua_function(tolua_S, "getOutlineColor", lua_x_Resource_ResFont_getOutlineColor);
		tolua_function(tolua_S, "getOutlineSize", lua_x_Resource_ResFont_getOutlineSize);
		tolua_function(tolua_S, "getRenderMode", lua_x_Resource_ResFont_getRenderMode);
		tolua_function(tolua_S, "getShadowBlurRadius", lua_x_Resource_ResFont_getShadowBlurRadius);
		tolua_function(tolua_S, "getShadowColor", lua_x_Resource_ResFont_getShadowColor);
		tolua_function(tolua_S, "getShadowOffset", lua_x_Resource_ResFont_getShadowOffset);
		tolua_function(tolua_S, "getTTFConfig", lua_x_Resource_ResFont_getTTFConfig);
		tolua_function(tolua_S, "getVAlign", lua_x_Resource_ResFont_getVAlign);
		tolua_function(tolua_S, "isBold", lua_x_Resource_ResFont_isBold);
		tolua_function(tolua_S, "isGlowed", lua_x_Resource_ResFont_isGlowed);
		tolua_function(tolua_S, "isItalics", lua_x_Resource_ResFont_isItalics);
		tolua_function(tolua_S, "isOutlined", lua_x_Resource_ResFont_isOutlined);
		tolua_function(tolua_S, "isShadowed", lua_x_Resource_ResFont_isShadowed);
		tolua_function(tolua_S, "isStrikethrough", lua_x_Resource_ResFont_isStrikethrough);
		tolua_function(tolua_S, "isUnderlined", lua_x_Resource_ResFont_isUnderlined);
		tolua_function(tolua_S, "render", lua_x_Resource_ResFont_render);
		tolua_function(tolua_S, "setColor", lua_x_Resource_ResFont_setColor);
		tolua_function(tolua_S, "setHAlign", lua_x_Resource_ResFont_setHAlign);
		tolua_function(tolua_S, "setOutlineColor", lua_x_Resource_ResFont_setOutlineColor);
		tolua_function(tolua_S, "setOutlineSize", lua_x_Resource_ResFont_setOutlineSize);
		tolua_function(tolua_S, "setRenderMode", lua_x_Resource_ResFont_setRenderMode);
		tolua_function(tolua_S, "setTTFConfig", lua_x_Resource_ResFont_setTTFConfig);
		tolua_function(tolua_S, "setVAlign", lua_x_Resource_ResFont_setVAlign);
		tolua_function(tolua_S, "HGE2BMF", lua_x_Resource_ResFont_HGE2BMF);
		tolua_function(tolua_S, "createBMF", lua_x_Resource_ResFont_createBMF);
		tolua_function(tolua_S, "createHGE", lua_x_Resource_ResFont_createHGE);
		tolua_function(tolua_S, "createTTF", lua_x_Resource_ResFont_createTTF);
		{
			tolua_module(tolua_S, "LabelType", 0);
			tolua_beginmodule(tolua_S, "LabelType");
			{
				tolua_constant(tolua_S, "TTF", (lua_Number)lstg::ResFont::LabelType::TTF);
				tolua_constant(tolua_S, "BMFONT", (lua_Number)lstg::ResFont::LabelType::BMFONT);
				tolua_constant(tolua_S, "CHARMAP", (lua_Number)lstg::ResFont::LabelType::CHARMAP);
				tolua_constant(tolua_S, "SYSTEM", (lua_Number)lstg::ResFont::LabelType::SYSTEM);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResFont).name();
	g_luaType[typeName] = "lstg.ResFont";
	g_typeCast["ResFont"] = "lstg.ResFont";
	return 1;
}

int lua_x_Resource_ResAudio_getFFT(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:getFFT";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFFT();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_getFFTSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:getFFTSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFFTSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_getSource(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:getSource";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSource();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_getStream(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:getStream";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getStream();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_isPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:isPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPlaying();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_isStopped(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:isStopped";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isStopped();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_pause(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:pause";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->pause();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_play(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:play";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->play(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->play(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->play();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_resume(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:resume";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->resume();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResAudio_stop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResAudio";
	constexpr auto LUA_FNAME = "lstg.ResAudio:stop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->stop();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Resource_ResAudio_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResAudio(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResAudio");
	tolua_cclass(tolua_S, "ResAudio", "lstg.ResAudio", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResAudio");
		tolua_function(tolua_S, "getFFT", lua_x_Resource_ResAudio_getFFT);
		tolua_function(tolua_S, "getFFTSize", lua_x_Resource_ResAudio_getFFTSize);
		tolua_function(tolua_S, "getSource", lua_x_Resource_ResAudio_getSource);
		tolua_function(tolua_S, "getStream", lua_x_Resource_ResAudio_getStream);
		tolua_function(tolua_S, "isPlaying", lua_x_Resource_ResAudio_isPlaying);
		tolua_function(tolua_S, "isStopped", lua_x_Resource_ResAudio_isStopped);
		tolua_function(tolua_S, "pause", lua_x_Resource_ResAudio_pause);
		tolua_function(tolua_S, "play", lua_x_Resource_ResAudio_play);
		tolua_function(tolua_S, "resume", lua_x_Resource_ResAudio_resume);
		tolua_function(tolua_S, "stop", lua_x_Resource_ResAudio_stop);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResAudio).name();
	g_luaType[typeName] = "lstg.ResAudio";
	g_typeCast["ResAudio"] = "lstg.ResAudio";
	return 1;
}

int lua_x_Resource_ResSound_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResSound";
	constexpr auto LUA_FNAME = "lstg.ResSound:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResSound::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_x_Resource_ResSound_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResSound(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResSound");
	tolua_cclass(tolua_S, "ResSound", "lstg.ResSound", "lstg.ResAudio", nullptr);

	tolua_beginmodule(tolua_S, "ResSound");
		tolua_function(tolua_S, "create", lua_x_Resource_ResSound_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResSound).name();
	g_luaType[typeName] = "lstg.ResSound";
	g_typeCast["ResSound"] = "lstg.ResSound";
	return 1;
}

int lua_x_Resource_ResMusic_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResMusic";
	constexpr auto LUA_FNAME = "lstg.ResMusic:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4) {
		std::string arg0;
		std::string arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResMusic::create(arg0, arg1, arg2, arg3);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
static int lua_x_Resource_ResMusic_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResMusic(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResMusic");
	tolua_cclass(tolua_S, "ResMusic", "lstg.ResMusic", "lstg.ResAudio", nullptr);

	tolua_beginmodule(tolua_S, "ResMusic");
		tolua_function(tolua_S, "create", lua_x_Resource_ResMusic_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResMusic).name();
	g_luaType[typeName] = "lstg.ResMusic";
	g_typeCast["ResMusic"] = "lstg.ResMusic";
	return 1;
}

int lua_x_Resource_ResFX_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		std::string arg1;
		std::string arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFX::create(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Resource_ResFX_createWithProgram(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:createWithProgram";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::backend::Program* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFX::createWithProgram(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_createWithString(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:createWithString";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		std::string arg1;
		std::string arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResFX::createWithString(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Resource_ResFX_getProgram(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:getProgram";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getProgram();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFX_getProgramState(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:getProgramState";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getProgramState();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFX_getRenderMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:getRenderMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRenderMode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFX_getUniformNames(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:getUniformNames";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getUniformNames();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResFX_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Color4B arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &=luaval_to_color4b(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setFloat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setFloat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		double arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFloat(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setMat4(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setMat4";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Mat4 arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_mat4(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMat4(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setScreenSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setScreenSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScreenSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResFX_setTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Texture2D* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTexture(arg0, 0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	else if (argc == 3) {
		std::string arg0;
		cocos2d::Texture2D* arg1;
		uint32_t arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTexture(arg0, arg2, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setVec2(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setVec2";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Vec2 arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_vec2(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVec2(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setVec3(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setVec3";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Vec3 arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_vec3(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVec3(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setVec4(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setVec4";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Vec4 arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_vec4(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVec4(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResFX_setViewport(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResFX";
	constexpr auto LUA_FNAME = "lstg.ResFX:setViewport";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResFX*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Viewport arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setViewport(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResFX_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResFX(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResFX");
	tolua_cclass(tolua_S, "ResFX", "lstg.ResFX", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResFX");
		tolua_function(tolua_S, "getProgram", lua_x_Resource_ResFX_getProgram);
		tolua_function(tolua_S, "getProgramState", lua_x_Resource_ResFX_getProgramState);
		tolua_function(tolua_S, "getRenderMode", lua_x_Resource_ResFX_getRenderMode);
		tolua_function(tolua_S, "getUniformNames", lua_x_Resource_ResFX_getUniformNames);
		tolua_function(tolua_S, "setColor", lua_x_Resource_ResFX_setColor);
		tolua_function(tolua_S, "setFloat", lua_x_Resource_ResFX_setFloat);
		tolua_function(tolua_S, "setMat4", lua_x_Resource_ResFX_setMat4);
		tolua_function(tolua_S, "setScreenSize", lua_x_Resource_ResFX_setScreenSize);
		tolua_function(tolua_S, "setTexture", lua_x_Resource_ResFX_setTexture);
		tolua_function(tolua_S, "setVec2", lua_x_Resource_ResFX_setVec2);
		tolua_function(tolua_S, "setVec3", lua_x_Resource_ResFX_setVec3);
		tolua_function(tolua_S, "setVec4", lua_x_Resource_ResFX_setVec4);
		tolua_function(tolua_S, "setViewport", lua_x_Resource_ResFX_setViewport);
		tolua_function(tolua_S, "create", lua_x_Resource_ResFX_create);
		tolua_function(tolua_S, "createWithProgram", lua_x_Resource_ResFX_createWithProgram);
		tolua_function(tolua_S, "createWithString", lua_x_Resource_ResFX_createWithString);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResFX).name();
	g_luaType[typeName] = "lstg.ResFX";
	g_typeCast["ResFX"] = "lstg.ResFX";
	return 1;
}

int lua_x_Resource_ResRenderTarget_copyTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:copyTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->copyTexture();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResRenderTarget::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResRenderTarget_getClearColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:getClearColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getClearColor();
		color4b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_getTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:getTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTarget();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_getTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:getTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTexture();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_isNeedBlendFix(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:isNeedBlendFix";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isNeedBlendFix();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_pop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:pop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->pop();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_push(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:push";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->push();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Resource_ResRenderTarget_render(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:render";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		lstg::ResFX* arg0;
		lstg::RenderMode* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->render(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Resource_ResRenderTarget_setClearColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:setClearColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setClearColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Resource_ResRenderTarget_setNeedBlendFix(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResRenderTarget";
	constexpr auto LUA_FNAME = "lstg.ResRenderTarget:setNeedBlendFix";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNeedBlendFix(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_Resource_ResRenderTarget_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Resource_ResRenderTarget(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResRenderTarget");
	tolua_cclass(tolua_S, "ResRenderTarget", "lstg.ResRenderTarget", "lstg.Resource", nullptr);

	tolua_beginmodule(tolua_S, "ResRenderTarget");
		tolua_function(tolua_S, "copyTexture", lua_x_Resource_ResRenderTarget_copyTexture);
		tolua_function(tolua_S, "getClearColor", lua_x_Resource_ResRenderTarget_getClearColor);
		tolua_function(tolua_S, "getTarget", lua_x_Resource_ResRenderTarget_getTarget);
		tolua_function(tolua_S, "getTexture", lua_x_Resource_ResRenderTarget_getTexture);
		tolua_function(tolua_S, "isNeedBlendFix", lua_x_Resource_ResRenderTarget_isNeedBlendFix);
		tolua_function(tolua_S, "pop", lua_x_Resource_ResRenderTarget_pop);
		tolua_function(tolua_S, "push", lua_x_Resource_ResRenderTarget_push);
		tolua_function(tolua_S, "render", lua_x_Resource_ResRenderTarget_render);
		tolua_function(tolua_S, "setClearColor", lua_x_Resource_ResRenderTarget_setClearColor);
		tolua_function(tolua_S, "setNeedBlendFix", lua_x_Resource_ResRenderTarget_setNeedBlendFix);
		tolua_function(tolua_S, "create", lua_x_Resource_ResRenderTarget_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResRenderTarget).name();
	g_luaType[typeName] = "lstg.ResRenderTarget";
	g_typeCast["ResRenderTarget"] = "lstg.ResRenderTarget";
	return 1;
}

TOLUA_API int register_all_x_Resource(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_Resource_Resource(tolua_S);
	lua_register_x_Resource_ResTexture(tolua_S);
	lua_register_x_Resource_ResFont(tolua_S);
	lua_register_x_Resource_ResourceColliable(tolua_S);
	lua_register_x_Resource_ResourceQuad(tolua_S);
	lua_register_x_Resource_ResAnimation(tolua_S);
	lua_register_x_Resource_ResSprite(tolua_S);
	lua_register_x_Resource_ResParticle(tolua_S);
	lua_register_x_Resource_ResRenderTarget(tolua_S);
	lua_register_x_Resource_ResAudio(tolua_S);
	lua_register_x_Resource_ResMusic(tolua_S);
	lua_register_x_Resource_ResSound(tolua_S);
	lua_register_x_Resource_ResFX(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

