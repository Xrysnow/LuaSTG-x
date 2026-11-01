#pragma once
#include "lua_conversion/lua_conversion.hpp"
#include "base/CCGameController.h"

namespace lua
{
// KeyStatus is a Lua snapshot, never a borrowed view into a device's state map.
template<>
struct to_lua<cocos2d::Controller::KeyStatus> {
	static void F(lua_State* L, const cocos2d::Controller::KeyStatus& value) {
		// Lua allocation can run finalizers that change or destroy the device.
		const auto snapshot = value;
		lua_createtable(L, 0, 3);
		lua_pushboolean(L, snapshot.isPressed);
		lua_setfield(L, -2, "isPressed");
		lua_pushnumber(L, snapshot.value);
		lua_setfield(L, -2, "value");
		// Keep the established table contract: numeric 0/1, not a Lua boolean.
		lua_pushnumber(L, snapshot.isAnalog ? 1 : 0);
		lua_setfield(L, -2, "isAnalog");
	}
};
}
