#include "lua_ResourceMgr_auto.hpp"
#include "../LSTG/ResourceMgr.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;

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

int lua_x_ResourceMgr_ResourcePack_cacheAllFiles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:cacheAllFiles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheAllFiles();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:cacheAllFilesAsync";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheAllFilesAsync();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		std::function<void ()> arg0;
		int handler2 = toluafix_ref_function(tolua_S, 2, 0);
		ok &= handler2 != 0;
		if(ok)
		{
			arg0 = [=]()
			{
				toluafix_get_function_by_refid(tolua_S, handler2);
				if (!lua_isfunction(tolua_S, -1))
				{
					lua_pop(tolua_S, 1);
					return ;
				}
				lua_call(tolua_S, 0, 0);
			};
		};
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheAllFilesAsync(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_x_ResourceMgr_ResourcePack_cacheFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:cacheFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->cacheFile(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_cacheFileAsync(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:cacheFileAsync";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheFileAsync(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		std::function<void ()> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		int handler3 = toluafix_ref_function(tolua_S, 3, 0);
		ok &= handler3 != 0;
		if(ok)
		{
			arg1 = [=]()
			{
				toluafix_get_function_by_refid(tolua_S, handler3);
				if (!lua_isfunction(tolua_S, -1))
				{
					lua_pop(tolua_S, 1);
					return ;
				}
				lua_call(tolua_S, 0, 0);
			};
		};
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheFileAsync(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_x_ResourceMgr_ResourcePack_clearFileCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:clearFileCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearFileCache();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResourcePack::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_ResourceMgr_ResourcePack_getCRC32(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getCRC32";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCRC32(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_getCompressedSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getCompressedSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCompressedSize(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_getFileCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getFileCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFileCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_getPath(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getPath";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
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
int lua_x_ResourceMgr_ResourcePack_getPriority(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getPriority";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPriority();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_getStringFromFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getStringFromFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getStringFromFile(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_getUncompressedSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:getUncompressedSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getUncompressedSize(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_isFileCached(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:isFileCached";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFileCached(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:isFileOrDirectoryExist";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFileOrDirectoryExist(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_listCachedFiles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:listCachedFiles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->listCachedFiles();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_listFiles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:listFiles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->listFiles();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourcePack_loadAndCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:loadAndCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->loadAndCache(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_removeFileCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:removeFileCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->removeFileCache(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourcePack_setPriority(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourcePack";
	constexpr auto LUA_FNAME = "lstg.ResourcePack:setPriority";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourcePack*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPriority(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_ResourceMgr_ResourcePack_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ResourceMgr_ResourcePack(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResourcePack");
	tolua_cclass(tolua_S, "ResourcePack", "lstg.ResourcePack", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "ResourcePack");
		tolua_function(tolua_S, "cacheAllFiles", lua_x_ResourceMgr_ResourcePack_cacheAllFiles);
		tolua_function(tolua_S, "cacheAllFilesAsync", lua_x_ResourceMgr_ResourcePack_cacheAllFilesAsync);
		tolua_function(tolua_S, "cacheFile", lua_x_ResourceMgr_ResourcePack_cacheFile);
		tolua_function(tolua_S, "cacheFileAsync", lua_x_ResourceMgr_ResourcePack_cacheFileAsync);
		tolua_function(tolua_S, "clearFileCache", lua_x_ResourceMgr_ResourcePack_clearFileCache);
		tolua_function(tolua_S, "getCRC32", lua_x_ResourceMgr_ResourcePack_getCRC32);
		tolua_function(tolua_S, "getCompressedSize", lua_x_ResourceMgr_ResourcePack_getCompressedSize);
		tolua_function(tolua_S, "getFileCount", lua_x_ResourceMgr_ResourcePack_getFileCount);
		tolua_function(tolua_S, "getPath", lua_x_ResourceMgr_ResourcePack_getPath);
		tolua_function(tolua_S, "getPriority", lua_x_ResourceMgr_ResourcePack_getPriority);
		tolua_function(tolua_S, "getStringFromFile", lua_x_ResourceMgr_ResourcePack_getStringFromFile);
		tolua_function(tolua_S, "getUncompressedSize", lua_x_ResourceMgr_ResourcePack_getUncompressedSize);
		tolua_function(tolua_S, "isFileCached", lua_x_ResourceMgr_ResourcePack_isFileCached);
		tolua_function(tolua_S, "isFileOrDirectoryExist", lua_x_ResourceMgr_ResourcePack_isFileOrDirectoryExist);
		tolua_function(tolua_S, "listCachedFiles", lua_x_ResourceMgr_ResourcePack_listCachedFiles);
		tolua_function(tolua_S, "listFiles", lua_x_ResourceMgr_ResourcePack_listFiles);
		tolua_function(tolua_S, "loadAndCache", lua_x_ResourceMgr_ResourcePack_loadAndCache);
		tolua_function(tolua_S, "removeFileCache", lua_x_ResourceMgr_ResourcePack_removeFileCache);
		tolua_function(tolua_S, "setPriority", lua_x_ResourceMgr_ResourcePack_setPriority);
		tolua_function(tolua_S, "create", lua_x_ResourceMgr_ResourcePack_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResourcePack).name();
	g_luaType[typeName] = "lstg.ResourcePack";
	g_typeCast["ResourcePack"] = "lstg.ResourcePack";
	return 1;
}

int lua_x_ResourceMgr_ResourceMgr_addResourcePack(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:addResourcePack";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		lstg::ResourcePack* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addResourcePack(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_ResourceMgr_ResourceMgr_cacheLocalFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:cacheLocalFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->cacheLocalFile(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:cacheLocalFileAsync";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheLocalFileAsync(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		std::function<void ()> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		int handler3 = toluafix_ref_function(tolua_S, 3, 0);
		ok &= handler3 != 0;
		if(ok)
		{
			arg1 = [=]()
			{
				toluafix_get_function_by_refid(tolua_S, handler3);
				if (!lua_isfunction(tolua_S, -1))
				{
					lua_pop(tolua_S, 1);
					return ;
				}
				lua_call(tolua_S, 0, 0);
			};
		};
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cacheLocalFileAsync(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_x_ResourceMgr_ResourceMgr_clear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:clear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clear();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:clearLocalFileCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearLocalFileCache();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_extractFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:extractFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->extractFile(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_ResourceMgr_ResourceMgr_getBufferFromFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getBufferFromFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBufferFromFile(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_getInstance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getInstance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::ResourceMgr::getInstance();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_getResourcePack(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getResourcePack";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getResourcePack(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_getResourcePacks(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getResourcePacks";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getResourcePacks();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_getStringFromFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getStringFromFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getStringFromFile(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:getStringFromLocalFile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getStringFromLocalFile(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:isFileOrDirectoryExist";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFileOrDirectoryExist(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_isLocalFileCached(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:isLocalFileCached";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isLocalFileCached(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:isResourcePackLoaded";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isResourcePackLoaded(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:listCachedLocalFiles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->listCachedLocalFiles();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:loadLocalFileAndCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->loadLocalFileAndCache(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_loadResourcePack(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:loadResourcePack";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->loadResourcePack(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:removeLocalFileCache";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->removeLocalFileCache(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:unloadAllResourcePacks";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->unloadAllResourcePacks();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_ResourceMgr_ResourceMgr_unloadResourcePack(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.ResourceMgr";
	constexpr auto LUA_FNAME = "lstg.ResourceMgr:unloadResourcePack";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::ResourceMgr*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->unloadResourcePack(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_x_ResourceMgr_ResourceMgr_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_ResourceMgr_ResourceMgr(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.ResourceMgr");
	tolua_cclass(tolua_S, "ResourceMgr", "lstg.ResourceMgr", "", nullptr);

	tolua_beginmodule(tolua_S, "ResourceMgr");
		tolua_function(tolua_S, "addResourcePack", lua_x_ResourceMgr_ResourceMgr_addResourcePack);
		tolua_function(tolua_S, "cacheLocalFile", lua_x_ResourceMgr_ResourceMgr_cacheLocalFile);
		tolua_function(tolua_S, "cacheLocalFileAsync", lua_x_ResourceMgr_ResourceMgr_cacheLocalFileAsync);
		tolua_function(tolua_S, "clear", lua_x_ResourceMgr_ResourceMgr_clear);
		tolua_function(tolua_S, "clearLocalFileCache", lua_x_ResourceMgr_ResourceMgr_clearLocalFileCache);
		tolua_function(tolua_S, "extractFile", lua_x_ResourceMgr_ResourceMgr_extractFile);
		tolua_function(tolua_S, "getBufferFromFile", lua_x_ResourceMgr_ResourceMgr_getBufferFromFile);
		tolua_function(tolua_S, "getResourcePack", lua_x_ResourceMgr_ResourceMgr_getResourcePack);
		tolua_function(tolua_S, "getResourcePacks", lua_x_ResourceMgr_ResourceMgr_getResourcePacks);
		tolua_function(tolua_S, "getStringFromFile", lua_x_ResourceMgr_ResourceMgr_getStringFromFile);
		tolua_function(tolua_S, "getStringFromLocalFile", lua_x_ResourceMgr_ResourceMgr_getStringFromLocalFile);
		tolua_function(tolua_S, "isFileOrDirectoryExist", lua_x_ResourceMgr_ResourceMgr_isFileOrDirectoryExist);
		tolua_function(tolua_S, "isLocalFileCached", lua_x_ResourceMgr_ResourceMgr_isLocalFileCached);
		tolua_function(tolua_S, "isResourcePackLoaded", lua_x_ResourceMgr_ResourceMgr_isResourcePackLoaded);
		tolua_function(tolua_S, "listCachedLocalFiles", lua_x_ResourceMgr_ResourceMgr_listCachedLocalFiles);
		tolua_function(tolua_S, "loadLocalFileAndCache", lua_x_ResourceMgr_ResourceMgr_loadLocalFileAndCache);
		tolua_function(tolua_S, "loadResourcePack", lua_x_ResourceMgr_ResourceMgr_loadResourcePack);
		tolua_function(tolua_S, "removeLocalFileCache", lua_x_ResourceMgr_ResourceMgr_removeLocalFileCache);
		tolua_function(tolua_S, "unloadAllResourcePacks", lua_x_ResourceMgr_ResourceMgr_unloadAllResourcePacks);
		tolua_function(tolua_S, "unloadResourcePack", lua_x_ResourceMgr_ResourceMgr_unloadResourcePack);
		tolua_function(tolua_S, "getInstance", lua_x_ResourceMgr_ResourceMgr_getInstance);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::ResourceMgr).name();
	g_luaType[typeName] = "lstg.ResourceMgr";
	g_typeCast["ResourceMgr"] = "lstg.ResourceMgr";
	return 1;
}

int register_all_x_ResourceMgr(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_ResourceMgr_ResourcePack(tolua_S);
	lua_register_x_ResourceMgr_ResourceMgr(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

