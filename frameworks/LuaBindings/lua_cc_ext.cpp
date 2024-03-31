#include "lua_cc_ext.hpp"
#include "platform/CCImage.h"
#include "../Classes/XBuffer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/Utility.h"
#include "Util/UtilLuaConversion.h"
#include "lua_conversion/lua_conversion.hpp"
using ::lua::luaval_to_native;
using ::lua::native_to_luaval;

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

int lua_cc_ext_Image_initWithImageData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.Image";
	constexpr auto LUA_FNAME = "cc.Image:initWithImageData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::Image*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		lstg::Buffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->initWithImageData(arg0->data(), arg0->size());
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_ext_Image_initWithRawData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.Image";
	constexpr auto LUA_FNAME = "cc.Image:initWithRawData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::Image*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4) {
		lstg::Buffer* arg0;
		int arg1;
		int arg2;
		int arg3;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->initWithRawData(arg0->data(), arg0->size(), arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 5) {
		lstg::Buffer* arg0;
		int arg1;
		int arg2;
		int arg3;
		bool arg4;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->initWithRawData(arg0->data(), arg0->size(), arg1, arg2, arg3, arg4);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4 to 5");
}
int lua_cc_ext_Image_initWithSVGFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.Image";
	constexpr auto LUA_FNAME = "cc.Image:initWithSVGFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::Image*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::initImageWithSVG(cobj, arg0, cocos2d::Size());
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 2) {
		if (lua_isnumber(tolua_S, 3))
		{
			std::string arg0;
			double arg1;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
			auto ret = lstg::initImageWithSVG(cobj, arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
		else
		{
			std::string arg0;
			cocos2d::Size arg1;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			ok &= luaval_to_size(tolua_S, 3, &arg1, LUA_FNAME);
			LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
			auto ret = lstg::initImageWithSVG(cobj, arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	}
	if (argc == 3) {
		std::string arg0;
		double arg1;
		std::string arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::initImageWithSVG(cobj, arg0, arg1, arg2);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 4) {
		std::string arg0;
		double arg1;
		std::string arg2;
		double arg3;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::initImageWithSVG(cobj, arg0, arg1, arg2, arg3);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 4");
}

int lua_cc_ext_Texture2D_newImage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.Texture2D";
	constexpr auto LUA_FNAME = "cc.Texture2D:newImage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::Texture2D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 0) {
			auto ret = lstg::getTextureImage(cobj);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = lstg::getTextureImage(cobj, arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 4) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg1;
			ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg2;
			ok &= luaval_to_uint32(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg3;
			ok &= luaval_to_uint32(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			auto ret = lstg::getTextureImage(cobj, arg0, arg1, arg2, arg3);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 5) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg1;
			ok &= luaval_to_uint32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg2;
			ok &= luaval_to_uint32(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			unsigned int arg3;
			ok &= luaval_to_uint32(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			bool arg4;
			ok &= luaval_to_boolean(tolua_S, 6, &arg4, LUA_FNAME);
			if (!ok) { break; }
			auto ret = lstg::getTextureImage(cobj, arg0, arg1, arg2, arg3, arg4);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
static int lua_cc_ext_Texture2D_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_ext_Texture2D(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "cc.Texture2D");
	tolua_cclass(tolua_S, "Texture2D", "cc.Texture2D", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Texture2D");
		tolua_function(tolua_S, "newImage", lua_cc_ext_Texture2D_newImage);
	tolua_endmodule(tolua_S);
	lua::registerLuaType<cocos2d::Texture2D>("cc.Texture2D", "Texture2D");
	return 1;
}

int lua_cc_ext_Sprite_newImage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "cc.Sprite";
	constexpr auto LUA_FNAME = "cc.Sprite:newImage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (cocos2d::Sprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::getSpriteImage(cobj);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::getSpriteImage(cobj, arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}

int register_all_cc_ext(lua_State* tolua_S)
{
	if (nullptr == tolua_S)
        return 0;
    lua_pushstring(tolua_S, "cc.Image");
    lua_rawget(tolua_S, LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S,"initWithImageData", lua_cc_ext_Image_initWithImageData);
        tolua_function(tolua_S,"initWithRawData", lua_cc_ext_Image_initWithRawData);
        tolua_function(tolua_S,"initWithSVGFile", lua_cc_ext_Image_initWithSVGFile);
    }
    lua_pop(tolua_S, 1);

	lua_pushstring(tolua_S, "cc.Texture2D");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "newImage", lua_cc_ext_Texture2D_newImage);
	}
	lua_pop(tolua_S, 1);

	lua_pushstring(tolua_S, "cc.Sprite");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "newImage", lua_cc_ext_Sprite_newImage);
	}
	lua_pop(tolua_S, 1);
	return 0;
}

