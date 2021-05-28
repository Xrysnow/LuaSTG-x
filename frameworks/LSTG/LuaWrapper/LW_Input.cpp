#include "LW_Input.h"
#include "AppFrame.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "InputManager.h"
#include "Util/UtilLua.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

LUA_REGISTER_FUNC_DEF(lstg, GetKeyState)
{
	lua_pushboolean(L, LIM.getKeyState(luaL_checkinteger(L, 1)));
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, GetLastKey)
{
	lua_pushinteger(L, LIM.getLastKey());
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, GetLastChar)
{
	return LIM.getLastChar(L);
}

/*******************************************************************************
 * controller
 *******************************************************************************/

LUA_REGISTER_FUNC_DEF(lstg, GetAllControllers)
{
	int idx = 1;
	lua_newtable(L);
	for (auto c : Controller::getAllController())
	{
		lua_pushnumber(L, idx);
		object_to_luaval(L, "cc.Controller", (Controller*)c);
		lua_rawset(L, -3);
		++idx;
	}
	return 1;
}
ControllerHelper::KeyCallBack getKeyCallBack(LUA_FUNCTION handler)
{
	return [=](Controller* controller, int keyCode, float value, bool isPressed, bool isAnalog)
	{
		const auto state = LuaEngine::getInstance()->getLuaStack()->getLuaState();
		//object_to_luaval(state, "cc.Controller", controller);
		// push id instead of object for better performance
		lua_pushinteger(state, controller->getDeviceId());
		lua_pushinteger(state, keyCode);
		lua_pushnumber(state, value);
		lua_pushboolean(state, isPressed);
		lua_pushboolean(state, isAnalog);
		LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 5);
	};
}
ControllerHelper::ConnectCallBack getConnectCallBack(LUA_FUNCTION handler)
{
	return [=](Controller* controller)
	{
		const auto state = LuaEngine::getInstance()->getLuaStack()->getLuaState();
		object_to_luaval(state, "cc.Controller", controller);
		LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 1);
	};
}
LUA_REGISTER_FUNC_DEF(lstg, SetOnControllerKeyDown)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnKeyDown(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetOnControllerKeyUp)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnKeyUp(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetOnControllerAxisEvent)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnAxisEvent(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetOnControllerConnect)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnConnect(
		(handler == 0) ? nullptr : getConnectCallBack(handler));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, SetOnControllerDisconnect)
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnDisconnect(
		(handler == 0) ? nullptr : getConnectCallBack(handler));
	return 0;
}

/*******************************************************************************
* mouse
*******************************************************************************/
LUA_REGISTER_FUNC_DEF(lstg, GetMousePosition)
{
	const auto pos = LIM.getMousePosition();
	lua_pushnumber(L, pos.x);
	lua_pushnumber(L, pos.y);
	return 2;
}
LUA_REGISTER_FUNC_DEF(lstg, GetMouseState)
{
	lua_pushboolean(L, LIM.getMouseState(luaL_checkinteger(L, 1) - 1));
	return 1;
}

//LUA_REGISTER_FUNC_DEF(lstg, UpdateInput)
//{
//	//LAPP.UpdateInput();
//	return 0;
//}
