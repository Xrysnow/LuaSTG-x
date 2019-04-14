#include "LW_Input.h"
#include "AppFrame.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "UtilLua.h"
#include "InputManager.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

static int GetKeyState(lua_State* L) noexcept
{
	lua_pushboolean(L, LIM.getKeyState(luaL_checkinteger(L, 1)));
	return 1;
}
static int GetLastKey(lua_State* L) noexcept
{
	lua_pushinteger(L, LIM.getLastKey());
	return 1;
}
static int GetLastChar(lua_State* L) noexcept
{
	return LIM.getLastChar(L);
}
/*******************************************************************************
 * controller
 *******************************************************************************/

static int GetAllControllers(lua_State* L) noexcept
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
		object_to_luaval(state, "cc.Controller", controller);
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
static int SetOnControllerKeyDown(lua_State* L) noexcept
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnKeyDown(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
static int SetOnControllerKeyUp(lua_State* L) noexcept
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnKeyUp(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
static int SetOnControllerAxisEvent(lua_State* L) noexcept
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnAxisEvent(
		(handler == 0) ? nullptr : getKeyCallBack(handler));
	return 0;
}
static int SetOnControllerConnect(lua_State* L) noexcept
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnConnect(
		(handler == 0) ? nullptr : getConnectCallBack(handler));
	return 0;
}

static int SetOnControllerDisconnect(lua_State* L) noexcept
{
	const LUA_FUNCTION handler = toluafix_ref_function(L, 1, 0);
	ControllerHelper::getInstance()->setOnDisconnect(
		(handler == 0) ? nullptr : getConnectCallBack(handler));
	return 0;
}

/*******************************************************************************
* mouse
*******************************************************************************/
static int GetMousePosition(lua_State* L) noexcept
{
	const auto pos = LIM.getMousePosition();
	lua_pushnumber(L, pos.x);
	lua_pushnumber(L, pos.y);
	return 2;
}
static int GetMouseState(lua_State* L) noexcept
{
	lua_pushboolean(L, LIM.getMouseState(luaL_checkinteger(L, 1) - 1));
	return 1;
}

//static int UpdateInput(lua_State* L) noexcept
//{
//	//LAPP.UpdateInput();
//	return 0;
//}

vector<luaL_Reg> lstg::LW_Input()
{
	vector<luaL_Reg> ret = {
		{ "GetKeyState", &GetKeyState },
		{ "GetLastKey", &GetLastKey },
		{ "GetLastChar", &GetLastChar },

		{ "GetAllControllers", &GetAllControllers },
		{ "SetOnControllerKeyDown", &SetOnControllerKeyDown },
		{ "SetOnControllerKeyUp", &SetOnControllerKeyUp },
		{ "SetOnControllerAxisEvent", &SetOnControllerAxisEvent },
		{ "SetOnControllerConnect", &SetOnControllerConnect },
		{ "SetOnControllerDisconnect", &SetOnControllerDisconnect },

		{ "GetMousePosition", &GetMousePosition },
		{ "GetMouseState", &GetMouseState },
		//{ "UpdateInput", &UpdateInput },  //new
	};
	return ret;
}
