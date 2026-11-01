#include "lua_cc_controller_auto.hpp"
#include "lua_cc_controller_adapters.hpp"
#include "base/CCGameController.h"

int lua_cocos2d_Controller_getDeviceId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getDeviceId");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceId));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_getDeviceName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getDeviceName");
	LUA_TRY_INVOKE_R(0, static_cast<std::string_view(cocos2d::Controller::*)()const>(&cocos2d::Controller::getDeviceName));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_getKeyStatus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getKeyStatus");
	LUA_TRY_INVOKE_R(1, static_cast<const cocos2d::Controller::KeyStatus&(cocos2d::Controller::*)(int)>(&cocos2d::Controller::getKeyStatus));
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getTag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getTag");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::Controller::*)()const>(&cocos2d::Controller::getTag));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_isConnected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:isConnected");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::Controller::*)()const>(&cocos2d::Controller::isConnected));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_setTag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:setTag");
	LUA_TRY_INVOKE(1, static_cast<void(cocos2d::Controller::*)(int)>(&cocos2d::Controller::setTag));
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getControllerByDeviceId(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:getControllerByDeviceId");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByDeviceId));
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getControllerByTag(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:getControllerByTag");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Controller*(*)(int)>(&cocos2d::Controller::getControllerByTag));
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_startDiscoveryController(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:startDiscoveryController");
	LUA_TRY_INVOKE(0, static_cast<void(*)()>(&cocos2d::Controller::startDiscoveryController));
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_stopDiscoveryController(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:stopDiscoveryController");
	LUA_TRY_INVOKE(0, static_cast<void(*)()>(&cocos2d::Controller::stopDiscoveryController));
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Controller_ccController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cocos2d::Controller, "Controller", "cc.Controller",
		nullptr, nullptr);
	LUA_METHOD("getDeviceId", lua_cocos2d_Controller_getDeviceId);
	LUA_METHOD("getDeviceName", lua_cocos2d_Controller_getDeviceName);
	LUA_METHOD("getKeyStatus", lua_cocos2d_Controller_getKeyStatus);
	LUA_METHOD("getTag", lua_cocos2d_Controller_getTag);
	LUA_METHOD("isConnected", lua_cocos2d_Controller_isConnected);
	LUA_METHOD("setTag", lua_cocos2d_Controller_setTag);
	LUA_METHOD("getControllerByDeviceId", lua_cocos2d_Controller_getControllerByDeviceId);
	LUA_METHOD("getControllerByTag", lua_cocos2d_Controller_getControllerByTag);
	LUA_METHOD("startDiscoveryController", lua_cocos2d_Controller_startDiscoveryController);
	LUA_METHOD("stopDiscoveryController", lua_cocos2d_Controller_stopDiscoveryController);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_EventController_getController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:getController");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::Controller*(cocos2d::EventController::*)()const>(&cocos2d::EventController::getController));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_getControllerEventType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:getControllerEventType");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::EventController::ControllerEventType(cocos2d::EventController::*)()const>(&cocos2d::EventController::getControllerEventType));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_getKeyCode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:getKeyCode");
	LUA_TRY_INVOKE_R(0, static_cast<int(cocos2d::EventController::*)()const>(&cocos2d::EventController::getKeyCode));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_isConnected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:isConnected");
	LUA_TRY_INVOKE_R(0, static_cast<bool(cocos2d::EventController::*)()const>(&cocos2d::EventController::isConnected));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_setConnectStatus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:setConnectStatus");
	LUA_TRY_INVOKE(1, static_cast<void(cocos2d::EventController::*)(bool)>(&cocos2d::EventController::setConnectStatus));
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_EventController_setKeyCode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:setKeyCode");
	LUA_TRY_INVOKE(1, static_cast<void(cocos2d::EventController::*)(int)>(&cocos2d::EventController::setKeyCode));
	LUA_INVOKE_FOOTER("1");
}
int luaReg_Controller_ccEventController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::EventController, "EventController", "cc.EventController",
		cocos2d::Event, "cc.Event",
		nullptr, nullptr);
	LUA_METHOD("getController", lua_cocos2d_EventController_getController);
	LUA_METHOD("getControllerEventType", lua_cocos2d_EventController_getControllerEventType);
	LUA_METHOD("getKeyCode", lua_cocos2d_EventController_getKeyCode);
	LUA_METHOD("isConnected", lua_cocos2d_EventController_isConnected);
	LUA_METHOD("setConnectStatus", lua_cocos2d_EventController_setConnectStatus);
	LUA_METHOD("setKeyCode", lua_cocos2d_EventController_setKeyCode);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_cocos2d_EventListenerController_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.EventListenerController", "cc.EventListenerController:create");
	LUA_TRY_INVOKE_R(0, static_cast<cocos2d::EventListenerController*(*)()>(&cocos2d::EventListenerController::create));
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Controller_ccEventListenerController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cocos2d::EventListenerController, "EventListenerController", "cc.EventListenerController",
		cocos2d::EventListener, "cc.EventListener",
		nullptr, nullptr);
	LUA_METHOD("create", lua_cocos2d_EventListenerController_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}

int register_all_cocos2dx_controller(lua_State* lua_S)
{
	luaReg_Controller_ccController(lua_S);
	luaReg_Controller_ccEventController(lua_S);
	luaReg_Controller_ccEventListenerController(lua_S);
	return 0;
}
