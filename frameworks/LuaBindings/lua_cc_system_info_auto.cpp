#include "lua_cc_system_info_auto.hpp"
#include "lua_conversion/lua_conversion.hpp"
#include "lua_cc_system_info_conversion.hpp"

static_assert(lua::value_type<cc::SystemInfoSubscription>::value, "ValueTypes requires a shared runtime trait for cc::SystemInfoSubscription");
int lua_cc_SystemInfoSubscription_isRunning(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.SystemInfoSubscription", "cc.SystemInfoSubscription:isRunning");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfoSubscription::isRunning);
	LUA_INVOKE_FOOTER("0");
}
int lua_cc_SystemInfoSubscription_poll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.SystemInfoSubscription", "cc.SystemInfoSubscription:poll");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfoSubscription::poll);
	LUA_INVOKE_FOOTER("0");
}
int lua_cc_SystemInfoSubscription_setPaused(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.SystemInfoSubscription", "cc.SystemInfoSubscription:setPaused");
	LUA_TRY_INVOKE(1, &cc::SystemInfoSubscription::setPaused);
	LUA_INVOKE_FOOTER("1");
}
int lua_cc_SystemInfoSubscription_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.SystemInfoSubscription", "cc.SystemInfoSubscription:stop");
	LUA_TRY_INVOKE(0, &cc::SystemInfoSubscription::stop);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_cc_system_info_ccSystemInfoSubscription(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cc::SystemInfoSubscription, "SystemInfoSubscription", "cc.SystemInfoSubscription",
		nullptr, lua::value_collect<cc::SystemInfoSubscription>);
	LUA_METHOD("isRunning", lua_cc_SystemInfoSubscription_isRunning);
	LUA_METHOD("poll", lua_cc_SystemInfoSubscription_poll);
	LUA_METHOD("setPaused", lua_cc_SystemInfoSubscription_setPaused);
	LUA_METHOD("stop", lua_cc_SystemInfoSubscription_stop);
	LUA_CLS_END();
	lua::register_value_metatable<cc::SystemInfoSubscription>(lua_S, "cc.SystemInfoSubscription");
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cc_SystemInfo_getBatteryStatus(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getBatteryStatus");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getBatteryStatus);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getComputer(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getComputer");
	LUA_TRY_INVOKE_R(1, &cc::SystemInfo::getComputer);
	LUA_TRY_INVOKE_R(0, [](){{return cc::SystemInfo::getComputer();}});
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_cc_SystemInfo_getCpu(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getCpu");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getCpu);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getDiskSpace(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getDiskSpace");
	LUA_TRY_INVOKE_R(1, &cc::SystemInfo::getDiskSpace);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cc_SystemInfo_getMemoryUsage(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getMemoryUsage");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getMemoryUsage);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getNetworkInterfaces(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getNetworkInterfaces");
	LUA_TRY_INVOKE_R(1, &cc::SystemInfo::getNetworkInterfaces);
	LUA_TRY_INVOKE_R(0, [](){{return cc::SystemInfo::getNetworkInterfaces();}});
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_cc_SystemInfo_getNetworkState(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getNetworkState");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getNetworkState);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getOs(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getOs");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getOs);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getPowerProfile(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getPowerProfile");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getPowerProfile);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getResourceLimits(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getResourceLimits");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getResourceLimits);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_getUptime(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:getUptime");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::getUptime);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cc_SystemInfo_monitor(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:monitor");
	LUA_TRY_INVOKE_R(4, &cc::SystemInfo::monitor);
	LUA_SINVOKE_FOOTER("4");
}
int lua_cc_SystemInfo_watchNetwork(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.SystemInfo", "cc.SystemInfo:watchNetwork");
	LUA_TRY_INVOKE_R(0, &cc::SystemInfo::watchNetwork);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_cc_system_info_ccSystemInfo(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cc::SystemInfo, "SystemInfo", "cc.SystemInfo",
		nullptr, nullptr);
	LUA_METHOD("getBatteryStatus", lua_cc_SystemInfo_getBatteryStatus);
	LUA_METHOD("getComputer", lua_cc_SystemInfo_getComputer);
	LUA_METHOD("getCpu", lua_cc_SystemInfo_getCpu);
	LUA_METHOD("getDiskSpace", lua_cc_SystemInfo_getDiskSpace);
	LUA_METHOD("getMemoryUsage", lua_cc_SystemInfo_getMemoryUsage);
	LUA_METHOD("getNetworkInterfaces", lua_cc_SystemInfo_getNetworkInterfaces);
	LUA_METHOD("getNetworkState", lua_cc_SystemInfo_getNetworkState);
	LUA_METHOD("getOs", lua_cc_SystemInfo_getOs);
	LUA_METHOD("getPowerProfile", lua_cc_SystemInfo_getPowerProfile);
	LUA_METHOD("getResourceLimits", lua_cc_SystemInfo_getResourceLimits);
	LUA_METHOD("getUptime", lua_cc_SystemInfo_getUptime);
	LUA_METHOD("monitor", lua_cc_SystemInfo_monitor);
	LUA_METHOD("watchNetwork", lua_cc_SystemInfo_watchNetwork);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int register_all_cc_system_info(lua_State* lua_S)
{
	luaReg_cc_system_info_ccSystemInfoSubscription(lua_S);
	luaReg_cc_system_info_ccSystemInfo(lua_S);
	return 0;
}
