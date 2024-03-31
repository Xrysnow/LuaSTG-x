#include "lua_StopWatch_auto.hpp"
#include "XStopWatch.h"

int lua_lstg_StopWatch_new(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.StopWatch", "lstg.StopWatch:new");
	LUA_TRY_CTOR(0, [](){{return new lstg::StopWatch();}});
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_StopWatch_delete(lua_State* lua_S)
{
	auto cobj = LUA_TO_COBJ(lstg::StopWatch*, 1);
	delete cobj;
	return 0;
}
int lua_lstg_StopWatch_get(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.StopWatch", "lstg.StopWatch:get");
	LUA_TRY_INVOKE_R(0, &lstg::StopWatch::get);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_StopWatch_pause(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.StopWatch", "lstg.StopWatch:pause");
	LUA_TRY_INVOKE(0, &lstg::StopWatch::pause);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_StopWatch_reset(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.StopWatch", "lstg.StopWatch:reset");
	LUA_TRY_INVOKE(0, &lstg::StopWatch::reset);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_StopWatch_resume(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.StopWatch", "lstg.StopWatch:resume");
	LUA_TRY_INVOKE(0, &lstg::StopWatch::resume);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_StopWatch_lstgStopWatch(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF(lstg::StopWatch, "StopWatch", "lstg.StopWatch",
		lua_lstg_StopWatch_new, lua_lstg_StopWatch_delete);
	LUA_METHOD("new", lua_lstg_StopWatch_new);
	LUA_METHOD("get", lua_lstg_StopWatch_get);
	LUA_METHOD("pause", lua_lstg_StopWatch_pause);
	LUA_METHOD("reset", lua_lstg_StopWatch_reset);
	LUA_METHOD("resume", lua_lstg_StopWatch_resume);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
