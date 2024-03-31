#include "lua_LogSystem_auto.hpp"
#include "LogSystem.h"

int lua_lstg_LogSystem_changePath(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:changePath");
	LUA_TRY_INVOKE_R(1, &lstg::LogSystem::changePath);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_LogSystem_getPath(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:getPath");
	LUA_TRY_INVOKE_R(0, &lstg::LogSystem::getPath);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_LogSystem_setConsoleLevel(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:setConsoleLevel");
	LUA_TRY_INVOKE(1, &lstg::LogSystem::setConsoleLevel);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_LogSystem_write(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:write");
	LUA_TRY_INVOKE_R(1, &lstg::LogSystem::write);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_LogSystem_writeLine(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:writeLine");
	LUA_TRY_INVOKE_R(1, &lstg::LogSystem::writeLine);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_LogSystem_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.LogSystem", "lstg.LogSystem:getInstance");
	LUA_TRY_INVOKE_R(0, &lstg::LogSystem::getInstance);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_LogSystem_lstgLogSystem(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::LogSystem, "LogSystem", "lstg.LogSystem",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("changePath", lua_lstg_LogSystem_changePath);
	LUA_METHOD("getPath", lua_lstg_LogSystem_getPath);
	LUA_METHOD("setConsoleLevel", lua_lstg_LogSystem_setConsoleLevel);
	LUA_METHOD("write", lua_lstg_LogSystem_write);
	LUA_METHOD("writeLine", lua_lstg_LogSystem_writeLine);
	LUA_METHOD("getInstance", lua_lstg_LogSystem_getInstance);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
