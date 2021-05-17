#include "lua_Stream_auto.hpp"
#include "XStream.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;
using lstg::lua::luaval_to_unsigned_long_long;

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

int lua_x_Stream_Stream_fill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:fill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		lstg::Stream* arg0;
		unsigned long long arg1;
		lstg::Buffer* arg2;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_unsigned_long_long(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->fill(arg0, arg1, arg2);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Stream_Stream_isResizable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:isResizable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isResizable();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_isWritable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:isWritable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isWritable();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_lock(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:lock";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->lock();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_resize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:resize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned long long arg0;
		ok &= luaval_to_unsigned_long_long(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->resize(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Stream_Stream_seek(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:seek";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		lstg::Stream::SeekOrigin arg0;
		long long arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_long_long(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->seek(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Stream_Stream_size(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:size";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->size();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_tell(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:tell";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->tell();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_tryLock(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:tryLock";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->tryLock();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Stream_Stream_unlock(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Stream";
	constexpr auto LUA_FNAME = "lstg.Stream:unlock";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Stream*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->unlock();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Stream_Stream_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Stream_Stream(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.Stream");
	tolua_cclass(tolua_S, "Stream", "lstg.Stream", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Stream");
		tolua_function(tolua_S, "fill", lua_x_Stream_Stream_fill);
		tolua_function(tolua_S, "isResizable", lua_x_Stream_Stream_isResizable);
		tolua_function(tolua_S, "isWritable", lua_x_Stream_Stream_isWritable);
		tolua_function(tolua_S, "lock", lua_x_Stream_Stream_lock);
		tolua_function(tolua_S, "resize", lua_x_Stream_Stream_resize);
		tolua_function(tolua_S, "seek", lua_x_Stream_Stream_seek);
		tolua_function(tolua_S, "size", lua_x_Stream_Stream_size);
		tolua_function(tolua_S, "tell", lua_x_Stream_Stream_tell);
		tolua_function(tolua_S, "tryLock", lua_x_Stream_Stream_tryLock);
		tolua_function(tolua_S, "unlock", lua_x_Stream_Stream_unlock);
		{
			tolua_module(tolua_S, "SeekOrigin", 0);
			tolua_beginmodule(tolua_S, "SeekOrigin");
			{
				tolua_constant(tolua_S, "BEG", (lua_Number)lstg::Stream::SeekOrigin::BEG);
				tolua_constant(tolua_S, "CUR", (lua_Number)lstg::Stream::SeekOrigin::CUR);
				tolua_constant(tolua_S, "END", (lua_Number)lstg::Stream::SeekOrigin::END);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::Stream).name();
	g_luaType[typeName] = "lstg.Stream";
	g_typeCast["Stream"] = "lstg.Stream";
	return 1;
}

int lua_x_Stream_StreamFile_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StreamFile";
	constexpr auto LUA_FNAME = "lstg.StreamFile:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::StreamFile::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_x_Stream_StreamFile_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Stream_StreamFile(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.StreamFile");
	tolua_cclass(tolua_S, "StreamFile", "lstg.StreamFile", "lstg.Stream", nullptr);

	tolua_beginmodule(tolua_S, "StreamFile");
		tolua_function(tolua_S, "create", lua_x_Stream_StreamFile_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::StreamFile).name();
	g_luaType[typeName] = "lstg.StreamFile";
	g_typeCast["StreamFile"] = "lstg.StreamFile";
	return 1;
}

int lua_x_Stream_StreamMemory_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StreamMemory";
	constexpr auto LUA_FNAME = "lstg.StreamMemory:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::StreamMemory::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 1) {
		lstg::Buffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::StreamMemory::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 2) {
		lstg::Buffer* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::StreamMemory::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_x_Stream_StreamMemory_getBuffer(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.StreamMemory";
	constexpr auto LUA_FNAME = "lstg.StreamMemory:getBuffer";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::StreamMemory*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBuffer();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_x_Stream_StreamMemory_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_x_Stream_StreamMemory(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.StreamMemory");
	tolua_cclass(tolua_S, "StreamMemory", "lstg.StreamMemory", "lstg.Stream", nullptr);

	tolua_beginmodule(tolua_S, "StreamMemory");
		tolua_function(tolua_S, "getBuffer", lua_x_Stream_StreamMemory_getBuffer);
		tolua_function(tolua_S, "create", lua_x_Stream_StreamMemory_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::StreamMemory).name();
	g_luaType[typeName] = "lstg.StreamMemory";
	g_typeCast["StreamMemory"] = "lstg.StreamMemory";
	return 1;
}

int register_all_x_Stream(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_Stream_Stream(tolua_S);
	lua_register_x_Stream_StreamFile(tolua_S);
	lua_register_x_Stream_StreamMemory(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

