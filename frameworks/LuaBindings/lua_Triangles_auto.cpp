#include "lua_Triangles_auto.hpp"
#include "../Classes/XTriangles.h"
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

int lua_x_Triangles_Triangles_clone(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:clone";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->clone();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Triangles_Triangles_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		unsigned int arg0;
		unsigned int arg1;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Triangles_Triangles_createCircle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:createCircle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		unsigned int arg0;
		unsigned int arg1;
		double arg2;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createCircle(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 4) {
		unsigned int arg0;
		unsigned int arg1;
		double arg2;
		cocos2d::Rect arg3;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_rect(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createCircle(arg0, arg1, arg2, arg3);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3 to 4");
}
int lua_x_Triangles_Triangles_createGrid(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:createGrid";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		unsigned int arg0;
		unsigned int arg1;
		cocos2d::Vec2 arg2;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_vec2(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createGrid(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 4) {
		unsigned int arg0;
		unsigned int arg1;
		cocos2d::Vec2 arg2;
		cocos2d::Rect arg3;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_vec2(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_rect(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createGrid(arg0, arg1, arg2, arg3);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3 to 4");
}
int lua_x_Triangles_Triangles_createQuad(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:createQuad";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createQuad(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 2) {
		cocos2d::Vec2 arg0;
		cocos2d::Rect arg1;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_rect(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createQuad(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_x_Triangles_Triangles_createSector(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:createSector";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 5) {
		unsigned int arg0;
		unsigned int arg1;
		double arg2;
		double arg3;
		double arg4;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createSector(arg0, arg1, arg2, arg3, arg4);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 6) {
		unsigned int arg0;
		unsigned int arg1;
		double arg2;
		double arg3;
		double arg4;
		cocos2d::Rect arg5;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_rect(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Triangles::createSector(arg0, arg1, arg2, arg3, arg4, arg5);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5 to 6");
}
int lua_x_Triangles_Triangles_getIndexCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:getIndexCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getIndexCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Triangles_Triangles_getVertexCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:getVertexCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVertexCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Triangles_Triangles_setAllVertexColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setAllVertexColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color4B arg0;
		ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAllVertexColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Triangles_Triangles_setIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		unsigned int arg0;
		unsigned short arg1;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ushort(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setIndex(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Triangles_Triangles_setVertex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setVertex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 7) {
		unsigned int arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		double arg5;
		cocos2d::Color4B arg6;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		ok &=luaval_to_color4b(tolua_S, 8, &arg6, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertex(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "7");
}
int lua_x_Triangles_Triangles_setVertexColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setVertexColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		unsigned int arg0;
		cocos2d::Color4B arg1;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &=luaval_to_color4b(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertexColor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Triangles_Triangles_setVertexCoords(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setVertexCoords";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		unsigned int arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertexCoords(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Triangles_Triangles_setVertexPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Triangles";
	constexpr auto LUA_FNAME = "lstg.Triangles:setVertexPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Triangles*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4) {
		unsigned int arg0;
		double arg1;
		double arg2;
		double arg3;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVertexPosition(arg0, arg1, arg2, arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
static int lua_x_Triangles_Triangles_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Triangles_Triangles(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.Triangles");
	tolua_cclass(tolua_S, "Triangles", "lstg.Triangles", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Triangles");
		tolua_function(tolua_S, "clone", lua_x_Triangles_Triangles_clone);
		tolua_function(tolua_S, "getIndexCount", lua_x_Triangles_Triangles_getIndexCount);
		tolua_function(tolua_S, "getVertexCount", lua_x_Triangles_Triangles_getVertexCount);
		tolua_function(tolua_S, "setAllVertexColor", lua_x_Triangles_Triangles_setAllVertexColor);
		tolua_function(tolua_S, "setIndex", lua_x_Triangles_Triangles_setIndex);
		tolua_function(tolua_S, "setVertex", lua_x_Triangles_Triangles_setVertex);
		tolua_function(tolua_S, "setVertexColor", lua_x_Triangles_Triangles_setVertexColor);
		tolua_function(tolua_S, "setVertexCoords", lua_x_Triangles_Triangles_setVertexCoords);
		tolua_function(tolua_S, "setVertexPosition", lua_x_Triangles_Triangles_setVertexPosition);
		tolua_function(tolua_S, "create", lua_x_Triangles_Triangles_create);
		tolua_function(tolua_S, "createCircle", lua_x_Triangles_Triangles_createCircle);
		tolua_function(tolua_S, "createGrid", lua_x_Triangles_Triangles_createGrid);
		tolua_function(tolua_S, "createQuad", lua_x_Triangles_Triangles_createQuad);
		tolua_function(tolua_S, "createSector", lua_x_Triangles_Triangles_createSector);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::Triangles).name();
	g_luaType[typeName] = "lstg.Triangles";
	g_typeCast["Triangles"] = "lstg.Triangles";
	return 1;
}

int register_all_x_Triangles(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_Triangles_Triangles(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

