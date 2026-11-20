#pragma once

struct lua_State;

namespace lstg
{
	int registerLuaTextInput(lua_State* L);
	void resetLuaTextInput(lua_State* L);
}
