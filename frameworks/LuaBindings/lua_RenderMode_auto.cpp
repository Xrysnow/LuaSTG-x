#include "lua_RenderMode_auto.hpp"
#include "../LSTG/RenderMode.h"
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

int lua_x_RenderMode_RenderMode_clone(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:clone";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			std::string arg0;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::backend::Program* arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = lstg::RenderMode::create(arg0, arg1);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 5) {
			std::string arg0;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::backend::BlendOperation arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::backend::BlendFactor arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::backend::BlendFactor arg3;
			ok &= luaval_to_native(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::backend::Program* arg4;
			ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
			if (!ok) { break; }
			auto ret = lstg::RenderMode::create(arg0, arg1, arg2, arg3, arg4);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5");
}
int lua_x_RenderMode_RenderMode_getBlendDescriptor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getBlendDescriptor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBlendDescriptor();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_getBlendFunc(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getBlendFunc";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBlendFunc();
		blendfunc_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_getByID(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getByID";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::RenderMode::getByID(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_RenderMode_RenderMode_getByName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getByName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::RenderMode::getByName(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_RenderMode_RenderMode_getDefaultProgramState(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getDefaultProgramState";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDefaultProgramState();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_getID(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getID";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getID();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_getIDByName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getIDByName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::RenderMode::getIDByName(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_RenderMode_RenderMode_getName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_getProgram(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getProgram";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_getUniformBuffer(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getUniformBuffer";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getUniformBuffer();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_getUniformNames(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:getUniformNames";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_listRenderModes(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:listRenderModes";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::RenderMode::listRenderModes();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_newProgramState(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:newProgramState";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->newProgramState();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_RenderMode_RenderMode_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_setFloat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setFloat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_setMat4(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setMat4";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_setProgram(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setProgram";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::backend::Program* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setProgram(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_RenderMode_RenderMode_setTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
	else if (argc == 3)
	{
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
int lua_x_RenderMode_RenderMode_setUniformBuffer(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setUniformBuffer";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setUniformBuffer(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_RenderMode_RenderMode_setVec2(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setVec2";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_setVec3(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setVec3";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_RenderMode_RenderMode_setVec4(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.RenderMode";
	constexpr auto LUA_FNAME = "lstg.RenderMode:setVec4";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S, 1, nullptr);
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
static int lua_x_RenderMode_RenderMode_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_RenderMode_RenderMode(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.RenderMode");
	tolua_cclass(tolua_S, "RenderMode", "lstg.RenderMode", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "RenderMode");
		tolua_function(tolua_S, "clone", lua_x_RenderMode_RenderMode_clone);
		tolua_function(tolua_S, "getBlendDescriptor", lua_x_RenderMode_RenderMode_getBlendDescriptor);
		tolua_function(tolua_S, "getBlendFunc", lua_x_RenderMode_RenderMode_getBlendFunc);
		tolua_function(tolua_S, "getDefaultProgramState", lua_x_RenderMode_RenderMode_getDefaultProgramState);
		tolua_function(tolua_S, "getID", lua_x_RenderMode_RenderMode_getID);
		tolua_function(tolua_S, "getName", lua_x_RenderMode_RenderMode_getName);
		tolua_function(tolua_S, "getProgram", lua_x_RenderMode_RenderMode_getProgram);
		tolua_function(tolua_S, "getUniformBuffer", lua_x_RenderMode_RenderMode_getUniformBuffer);
		tolua_function(tolua_S, "getUniformNames", lua_x_RenderMode_RenderMode_getUniformNames);
		tolua_function(tolua_S, "newProgramState", lua_x_RenderMode_RenderMode_newProgramState);
		tolua_function(tolua_S, "setColor", lua_x_RenderMode_RenderMode_setColor);
		tolua_function(tolua_S, "setFloat", lua_x_RenderMode_RenderMode_setFloat);
		tolua_function(tolua_S, "setMat4", lua_x_RenderMode_RenderMode_setMat4);
		tolua_function(tolua_S, "setProgram", lua_x_RenderMode_RenderMode_setProgram);
		tolua_function(tolua_S, "setTexture", lua_x_RenderMode_RenderMode_setTexture);
		tolua_function(tolua_S, "setUniformBuffer", lua_x_RenderMode_RenderMode_setUniformBuffer);
		tolua_function(tolua_S, "setVec2", lua_x_RenderMode_RenderMode_setVec2);
		tolua_function(tolua_S, "setVec3", lua_x_RenderMode_RenderMode_setVec3);
		tolua_function(tolua_S, "setVec4", lua_x_RenderMode_RenderMode_setVec4);
		tolua_function(tolua_S, "create", lua_x_RenderMode_RenderMode_create);
		tolua_function(tolua_S, "getByID", lua_x_RenderMode_RenderMode_getByID);
		tolua_function(tolua_S, "getByName", lua_x_RenderMode_RenderMode_getByName);
		tolua_function(tolua_S, "getIDByName", lua_x_RenderMode_RenderMode_getIDByName);
		tolua_function(tolua_S, "listRenderModes", lua_x_RenderMode_RenderMode_listRenderModes);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::RenderMode).name();
	g_luaType[typeName] = "lstg.RenderMode";
	g_typeCast["RenderMode"] = "lstg.RenderMode";
	return 1;
}

int register_all_x_RenderMode(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_RenderMode_RenderMode(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

