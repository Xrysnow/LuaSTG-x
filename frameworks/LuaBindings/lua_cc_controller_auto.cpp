#include "lua_cc_controller_auto.hpp"
#include "lua_cc_controller_adapters.hpp"
#include "base/GameController.h"

int lua_cocos2d_Controller_getDeviceId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getDeviceId");
	LUA_TRY_INVOKE_R(0, &cc::Controller::getDeviceId);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_getDeviceName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getDeviceName");
	LUA_TRY_INVOKE_R(0, &cc::Controller::getDeviceName);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_getKeyStatus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getKeyStatus");
	LUA_TRY_INVOKE_R(1, &cc::Controller::getKeyStatus);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getTag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:getTag");
	LUA_TRY_INVOKE_R(0, &cc::Controller::getTag);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_isConnected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:isConnected");
	LUA_TRY_INVOKE_R(0, &cc::Controller::isConnected);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_setTag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.Controller", "cc.Controller:setTag");
	LUA_TRY_INVOKE(1, &cc::Controller::setTag);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getControllerByDeviceId(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:getControllerByDeviceId");
	LUA_TRY_INVOKE_R(1, &cc::Controller::getControllerByDeviceId);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_getControllerByTag(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:getControllerByTag");
	LUA_TRY_INVOKE_R(1, &cc::Controller::getControllerByTag);
	LUA_SINVOKE_FOOTER("1");
}
int lua_cocos2d_Controller_startDiscoveryController(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:startDiscoveryController");
	LUA_TRY_INVOKE(0, &cc::Controller::startDiscoveryController);
	LUA_SINVOKE_FOOTER("0");
}
int lua_cocos2d_Controller_stopDiscoveryController(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.Controller", "cc.Controller:stopDiscoveryController");
	LUA_TRY_INVOKE(0, &cc::Controller::stopDiscoveryController);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Controller_ccController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF(cc::Controller, "Controller", "cc.Controller",
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
	LUA_TRY_INVOKE_R(0, &cc::EventController::getController);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_getControllerEventType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:getControllerEventType");
	LUA_TRY_INVOKE_R(0, &cc::EventController::getControllerEventType);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_getKeyCode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:getKeyCode");
	LUA_TRY_INVOKE_R(0, &cc::EventController::getKeyCode);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_isConnected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:isConnected");
	LUA_TRY_INVOKE_R(0, &cc::EventController::isConnected);
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventController_setConnectStatus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:setConnectStatus");
	LUA_TRY_INVOKE(1, &cc::EventController::setConnectStatus);
	LUA_INVOKE_FOOTER("1");
}
int lua_cocos2d_EventController_setKeyCode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventController", "cc.EventController:setKeyCode");
	LUA_TRY_INVOKE(1, &cc::EventController::setKeyCode);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_Controller_ccEventController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::EventController, "EventController", "cc.EventController",
		cc::Event, "cc.Event",
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
int lua_cocos2d_EventListenerController_clone_1(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("cc.EventListenerController", "cc.EventListenerController:clone");
	LUA_TRY_INVOKE_R(0, static_cast<cc::IntrusivePtr<cc::EventListener>(cc::EventListenerController::*)()>(&cc::EventListenerController::clone));
	LUA_INVOKE_FOOTER("0");
}
int lua_cocos2d_EventListenerController_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("cc.EventListenerController", "cc.EventListenerController:create");
	LUA_TRY_INVOKE_R(0, &cc::EventListenerController::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Controller_ccEventListenerController(lua_State* lua_S)
{
	LUA_ENTRY("cc");
	LUA_CLS_DEF_BASE(cc::EventListenerController, "EventListenerController", "cc.EventListenerController",
		cc::EventListener, "cc.EventListener",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_cocos2d_EventListenerController_clone_1);
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
