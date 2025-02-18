#include "lua_WindowHelper_auto.hpp"
#include "WindowHelper.h"

int luaReg_WindowHelper_lstgWindowHelperOperation(lua_State* lua_S)
{
	LUA_ENUM_DEF("Operation");
	LUA_ENUM_ENTRY("SHOW", lstg::WindowHelper::Operation::SHOW);
	LUA_ENUM_ENTRY("HIDE", lstg::WindowHelper::Operation::HIDE);
	LUA_ENUM_ENTRY("FOCUS", lstg::WindowHelper::Operation::FOCUS);
	LUA_ENUM_ENTRY("ICONIFY", lstg::WindowHelper::Operation::ICONIFY);
	LUA_ENUM_ENTRY("RESTORE", lstg::WindowHelper::Operation::RESTORE);
	LUA_ENUM_ENTRY("MAXIMIZE", lstg::WindowHelper::Operation::MAXIMIZE);
	LUA_ENUM_END();
	return 0;
}
int luaReg_WindowHelper_lstgWindowHelperCursorType(lua_State* lua_S)
{
	LUA_ENUM_DEF("CursorType");
	LUA_ENUM_ENTRY("ARROW", lstg::WindowHelper::CursorType::ARROW);
	LUA_ENUM_ENTRY("IBEAM", lstg::WindowHelper::CursorType::IBEAM);
	LUA_ENUM_ENTRY("CROSSHAIR", lstg::WindowHelper::CursorType::CROSSHAIR);
	LUA_ENUM_ENTRY("HAND", lstg::WindowHelper::CursorType::HAND);
	LUA_ENUM_ENTRY("HRESIZE", lstg::WindowHelper::CursorType::HRESIZE);
	LUA_ENUM_ENTRY("VRESIZE", lstg::WindowHelper::CursorType::VRESIZE);
	LUA_ENUM_ENTRY("CUSTOM", lstg::WindowHelper::CursorType::CUSTOM);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_WindowHelper_getClipboardString(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getClipboardString");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getClipboardString);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_getDpiScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getDpiScale");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getDpiScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_enumDeviceResolution(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:enumDeviceResolution");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::enumDeviceResolution);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_setImeEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setImeEnabled");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::setImeEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_isImeEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:isImeEnabled");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::isImeEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getPosition");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_getSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getSize");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_getTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getTitle");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getTitle);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_hint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:hint");
	LUA_TRY_INVOKE(2, &lstg::WindowHelper::hint);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_WindowHelper_isCursorVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:isCursorVisible");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::isCursorVisible);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_isFullscreen(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:isFullscreen");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::isFullscreen);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_isVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:isVisible");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::isVisible);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_isVsync(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:isVsync");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::isVsync);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_moveToCenter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:moveToCenter");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::moveToCenter);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_operate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:operate");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::operate);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_resetHint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:resetHint");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::resetHint);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_setClipboardString(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setClipboardString");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setClipboardString);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setCursorVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setCursorVisible");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setCursorVisible);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setCustomCursor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setCustomCursor");
	LUA_TRY_INVOKE(2, &lstg::WindowHelper::setCustomCursor);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_WindowHelper_setDefaultCursor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setDefaultCursor");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::setDefaultCursor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_setFullscreen(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setFullscreen");
	LUA_TRY_INVOKE(0, &lstg::WindowHelper::setFullscreen);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_WindowHelper_setPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setPosition");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setSize");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setStandardCursor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setStandardCursor");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setStandardCursor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setTitle");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setTitle);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setVisible");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setVisible);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_setVsync(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:setVsync");
	LUA_TRY_INVOKE(1, &lstg::WindowHelper::setVsync);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_WindowHelper_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.WindowHelper", "lstg.WindowHelper:getInstance");
	LUA_TRY_INVOKE_R(0, &lstg::WindowHelper::getInstance);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_WindowHelper_lstgWindowHelper(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::WindowHelper, "WindowHelper", "lstg.WindowHelper",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getClipboardString", lua_lstg_WindowHelper_getClipboardString);
	LUA_METHOD("getDpiScale", lua_lstg_WindowHelper_getDpiScale);
	LUA_METHOD("enumDeviceResolution", lua_lstg_WindowHelper_enumDeviceResolution);
	LUA_METHOD("setImeEnabled", lua_lstg_WindowHelper_setImeEnabled);
	LUA_METHOD("isImeEnabled", lua_lstg_WindowHelper_isImeEnabled);
	LUA_METHOD("getPosition", lua_lstg_WindowHelper_getPosition);
	LUA_METHOD("getSize", lua_lstg_WindowHelper_getSize);
	LUA_METHOD("getTitle", lua_lstg_WindowHelper_getTitle);
	LUA_METHOD("hint", lua_lstg_WindowHelper_hint);
	LUA_METHOD("isCursorVisible", lua_lstg_WindowHelper_isCursorVisible);
	LUA_METHOD("isFullscreen", lua_lstg_WindowHelper_isFullscreen);
	LUA_METHOD("isVisible", lua_lstg_WindowHelper_isVisible);
	LUA_METHOD("isVsync", lua_lstg_WindowHelper_isVsync);
	LUA_METHOD("moveToCenter", lua_lstg_WindowHelper_moveToCenter);
	LUA_METHOD("operate", lua_lstg_WindowHelper_operate);
	LUA_METHOD("resetHint", lua_lstg_WindowHelper_resetHint);
	LUA_METHOD("setClipboardString", lua_lstg_WindowHelper_setClipboardString);
	LUA_METHOD("setCursorVisible", lua_lstg_WindowHelper_setCursorVisible);
	LUA_METHOD("setCustomCursor", lua_lstg_WindowHelper_setCustomCursor);
	LUA_METHOD("setDefaultCursor", lua_lstg_WindowHelper_setDefaultCursor);
	LUA_METHOD("setFullscreen", lua_lstg_WindowHelper_setFullscreen);
	LUA_METHOD("setPosition", lua_lstg_WindowHelper_setPosition);
	LUA_METHOD("setSize", lua_lstg_WindowHelper_setSize);
	LUA_METHOD("setStandardCursor", lua_lstg_WindowHelper_setStandardCursor);
	LUA_METHOD("setTitle", lua_lstg_WindowHelper_setTitle);
	LUA_METHOD("setVisible", lua_lstg_WindowHelper_setVisible);
	LUA_METHOD("setVsync", lua_lstg_WindowHelper_setVsync);
	LUA_METHOD("getInstance", lua_lstg_WindowHelper_getInstance);
	luaReg_WindowHelper_lstgWindowHelperCursorType(lua_S);
	luaReg_WindowHelper_lstgWindowHelperOperation(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_MonitorHelper_getContentScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getContentScale");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getContentScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getCurrentVideoMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getCurrentVideoMode");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getCurrentVideoMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getGammaRamp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getGammaRamp");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getGammaRamp);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getName");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getPhysicalSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getPhysicalSize");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getPhysicalSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getPosition");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getVideoModes(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getVideoModes");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getVideoModes);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getWorkarea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getWorkarea");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getWorkarea);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_isValid(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:isValid");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::isValid);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_setGamma(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:setGamma");
	LUA_TRY_INVOKE(1, &lstg::MonitorHelper::setGamma);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_MonitorHelper_setGammaRamp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:setGammaRamp");
	LUA_TRY_INVOKE(1, &lstg::MonitorHelper::setGammaRamp);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_MonitorHelper_getCurrentMonitor(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getCurrentMonitor");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getCurrentMonitor);
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getMonitors(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getMonitors");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getMonitors);
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_MonitorHelper_getPrimaryMonitor(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.MonitorHelper", "lstg.MonitorHelper:getPrimaryMonitor");
	LUA_TRY_INVOKE_R(0, &lstg::MonitorHelper::getPrimaryMonitor);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_WindowHelper_lstgMonitorHelper(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::MonitorHelper, "MonitorHelper", "lstg.MonitorHelper",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("getContentScale", lua_lstg_MonitorHelper_getContentScale);
	LUA_METHOD("getCurrentVideoMode", lua_lstg_MonitorHelper_getCurrentVideoMode);
	LUA_METHOD("getGammaRamp", lua_lstg_MonitorHelper_getGammaRamp);
	LUA_METHOD("getName", lua_lstg_MonitorHelper_getName);
	LUA_METHOD("getPhysicalSize", lua_lstg_MonitorHelper_getPhysicalSize);
	LUA_METHOD("getPosition", lua_lstg_MonitorHelper_getPosition);
	LUA_METHOD("getVideoModes", lua_lstg_MonitorHelper_getVideoModes);
	LUA_METHOD("getWorkarea", lua_lstg_MonitorHelper_getWorkarea);
	LUA_METHOD("isValid", lua_lstg_MonitorHelper_isValid);
	LUA_METHOD("setGamma", lua_lstg_MonitorHelper_setGamma);
	LUA_METHOD("setGammaRamp", lua_lstg_MonitorHelper_setGammaRamp);
	LUA_METHOD("getCurrentMonitor", lua_lstg_MonitorHelper_getCurrentMonitor);
	LUA_METHOD("getMonitors", lua_lstg_MonitorHelper_getMonitors);
	LUA_METHOD("getPrimaryMonitor", lua_lstg_MonitorHelper_getPrimaryMonitor);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
