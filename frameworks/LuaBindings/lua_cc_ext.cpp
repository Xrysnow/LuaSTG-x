#include "lua_cc_ext.hpp"
#include "platform/CCImage.h"
#include "../Classes/XBuffer.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "../LSTG/UtilLuaConversion.h"
#include "../LSTG/Utility.h"

int lua_cc_ext_Image_initWithImageData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Image* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Image",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Image*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cc_ext_Image_initWithImageData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::Buffer* arg0;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "cc.Image:initWithImageData");
		if(!arg0) ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cc_ext_Image_initWithImageData'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithImageData(arg0->data(), arg0->size());
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Image:initWithImageData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cc_ext_Image_initWithImageData'.",&tolua_err);
    return 0;
#endif
}
int lua_cc_ext_Image_initWithRawData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Image* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"cc.Image",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Image*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cc_ext_Image_initWithRawData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        lstg::Buffer* arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "cc.Image:initWithRawData");
		if(!arg0) ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Image:initWithRawData");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.Image:initWithRawData");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "cc.Image:initWithRawData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cc_ext_Image_initWithRawData'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithRawData(arg0->data(), arg0->size(), arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 5) 
    {
        lstg::Buffer* arg0;
        int arg1;
        int arg2;
        int arg3;
        bool arg4;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "cc.Image:initWithRawData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.Image:initWithRawData");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.Image:initWithRawData");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "cc.Image:initWithRawData");

        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "cc.Image:initWithRawData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cc_ext_Image_initWithRawData'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithRawData(arg0->data(), arg0->size(), arg1, arg2, arg3, arg4);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Image:initWithRawData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cc_ext_Image_initWithRawData'.",&tolua_err);
    return 0;
#endif
}
int lua_cc_ext_Image_initWithSVGFile(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::Image* cobj = nullptr;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "cc.Image", 0, &tolua_err)) goto tolua_lerror;
#endif
	cobj = (cocos2d::Image*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cc_ext_Image_initWithSVGFile'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "cc.Image:initWithSVGFile");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cc_ext_Image_initWithSVGFile'", nullptr);
			return 0;
		}
		bool ret = lstg::initImageWithSVG(cobj, arg0, cocos2d::Size());
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 2)
	{
		std::string arg0;
		cocos2d::Size arg1;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "cc.Image:initWithSVGFile");

		ok &= luaval_to_size(tolua_S, 3, &arg1, "cc.Image:initWithSVGFile");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cc_ext_Image_initWithSVGFile'", nullptr);
			return 0;
		}
		bool ret = lstg::initImageWithSVG(cobj, arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Image:initWithSVGFile", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_cc_ext_Image_initWithSVGFile'.", &tolua_err);
				return 0;
#endif
}

int lua_cc_ext_Texture2D_newImage(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::Texture2D* cobj = nullptr;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "cc.Texture2D", 0, &tolua_err)) goto tolua_lerror;
#endif
	cobj = (cocos2d::Texture2D*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cc_ext_Texture2D_newImage'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 0) {
			cocos2d::Image* ret = lstg::getTextureImage(cobj);
			object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0, "cc.Texture2D:newImage");
			if (!ok) { break; }
			cocos2d::Image* ret = lstg::getTextureImage(cobj, arg0);
			object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 4) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg1;
			ok &= luaval_to_uint32(tolua_S, 3, &arg1, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg2;
			ok &= luaval_to_uint32(tolua_S, 4, &arg2, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg3;
			ok &= luaval_to_uint32(tolua_S, 5, &arg3, "cc.Texture2D:newImage");
			if (!ok) { break; }
			cocos2d::Image* ret = lstg::getTextureImage(cobj, arg0, arg1, arg2, arg3);
			object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 5) {
			unsigned int arg0;
			ok &= luaval_to_uint32(tolua_S, 2, &arg0, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg1;
			ok &= luaval_to_uint32(tolua_S, 3, &arg1, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg2;
			ok &= luaval_to_uint32(tolua_S, 4, &arg2, "cc.Texture2D:newImage");
			if (!ok) { break; }
			unsigned int arg3;
			ok &= luaval_to_uint32(tolua_S, 5, &arg3, "cc.Texture2D:newImage");
			if (!ok) { break; }
			bool arg4;
			ok &= luaval_to_boolean(tolua_S, 6, &arg4, "cc.Texture2D:newImage");
			if (!ok) { break; }
			cocos2d::Image* ret = lstg::getTextureImage(cobj, arg0, arg1, arg2, arg3, arg4);
			object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
			return 1;
		}
	} while (false);
	ok = true;
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Texture2D:newImage", argc, 4);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_cc_ext_Texture2D_newImage'.", &tolua_err);
				return 0;
#endif
}

int lua_cc_ext_Sprite_newImage(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::Sprite* cobj = nullptr;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "cc.Sprite", 0, &tolua_err)) goto tolua_lerror;
#endif
	cobj = (cocos2d::Sprite*)tolua_tousertype(tolua_S, 1, nullptr);
#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cc_ext_Sprite_newImage'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cc_ext_Sprite_newImage'", nullptr);
			return 0;
		}
		cocos2d::Image* ret = lstg::getSpriteImage(cobj);
		object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
		return 1;
	}
	if (argc == 1)
	{
		bool arg0;

		ok &= luaval_to_boolean(tolua_S, 2, &arg0, "cc.Sprite:newImage");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_cc_ext_Sprite_newImage'", nullptr);
			return 0;
		}
		cocos2d::Image* ret = lstg::getSpriteImage(cobj, arg0);
		object_to_luaval<cocos2d::Image>(tolua_S, "cc.Image", (cocos2d::Image*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Sprite:newImage", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_cc_ext_Sprite_newImage'.", &tolua_err);
				return 0;
#endif
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

