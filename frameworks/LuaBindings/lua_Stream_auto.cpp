#include "lua_Stream_auto.hpp"
#include "XStream.h"

int luaReg_Stream_lstgStreamSeekOrigin(lua_State* lua_S)
{
	LUA_ENUM_DEF("SeekOrigin");
	LUA_ENUM_ENTRY("BEG", lstg::Stream::SeekOrigin::BEG);
	LUA_ENUM_ENTRY("CUR", lstg::Stream::SeekOrigin::CUR);
	LUA_ENUM_ENTRY("END", lstg::Stream::SeekOrigin::END);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_Stream_fill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:fill");
	LUA_TRY_INVOKE_R(3, &lstg::Stream::fill);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_Stream_isResizable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:isResizable");
	LUA_TRY_INVOKE_R(0, &lstg::Stream::isResizable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_isWritable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:isWritable");
	LUA_TRY_INVOKE_R(0, &lstg::Stream::isWritable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_lock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:lock");
	LUA_TRY_INVOKE(0, &lstg::Stream::lock);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_resize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:resize");
	LUA_TRY_INVOKE_R(1, &lstg::Stream::resize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Stream_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:seek");
	LUA_TRY_INVOKE_R(2, &lstg::Stream::seek);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Stream_size(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:size");
	LUA_TRY_INVOKE_R(0, &lstg::Stream::size);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_tell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:tell");
	LUA_TRY_INVOKE_R(0, &lstg::Stream::tell);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_tryLock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:tryLock");
	LUA_TRY_INVOKE_R(0, &lstg::Stream::tryLock);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Stream_unlock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Stream", "lstg.Stream:unlock");
	LUA_TRY_INVOKE(0, &lstg::Stream::unlock);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_Stream_lstgStream(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Stream, "Stream", "lstg.Stream",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("fill", lua_lstg_Stream_fill);
	LUA_METHOD("isResizable", lua_lstg_Stream_isResizable);
	LUA_METHOD("isWritable", lua_lstg_Stream_isWritable);
	LUA_METHOD("lock", lua_lstg_Stream_lock);
	LUA_METHOD("resize", lua_lstg_Stream_resize);
	LUA_METHOD("seek", lua_lstg_Stream_seek);
	LUA_METHOD("size", lua_lstg_Stream_size);
	LUA_METHOD("tell", lua_lstg_Stream_tell);
	LUA_METHOD("tryLock", lua_lstg_Stream_tryLock);
	LUA_METHOD("unlock", lua_lstg_Stream_unlock);
	luaReg_Stream_lstgStreamSeekOrigin(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_StreamFile_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.StreamFile", "lstg.StreamFile:create");
	LUA_TRY_INVOKE_R(2, &lstg::StreamFile::create);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_Stream_lstgStreamFile(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::StreamFile, "StreamFile", "lstg.StreamFile",
		lstg::Stream, "lstg.Stream",
		nullptr, nullptr);
	LUA_METHOD("create", lua_lstg_StreamFile_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_StreamMemory_getBuffer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.StreamMemory", "lstg.StreamMemory:getBuffer");
	LUA_TRY_INVOKE_R(0, &lstg::StreamMemory::getBuffer);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_StreamMemory_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.StreamMemory", "lstg.StreamMemory:create");
	LUA_TRY_INVOKE_R(2, static_cast<lstg::StreamMemory*(*)(lstg::Buffer*, bool)>(&lstg::StreamMemory::create));
	LUA_TRY_INVOKE_R(1, [](lstg::Buffer* arg0){{return lstg::StreamMemory::create(arg0);}});
	LUA_TRY_INVOKE_R(0, [](){{return lstg::StreamMemory::create();}});
	LUA_SINVOKE_FOOTER("0,1,2");
}
int luaReg_Stream_lstgStreamMemory(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::StreamMemory, "StreamMemory", "lstg.StreamMemory",
		lstg::Stream, "lstg.Stream",
		nullptr, nullptr);
	LUA_METHOD("getBuffer", lua_lstg_StreamMemory_getBuffer);
	LUA_METHOD("create", lua_lstg_StreamMemory_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
