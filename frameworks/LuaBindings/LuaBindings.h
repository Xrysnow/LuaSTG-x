#pragma once
#include "lua_conversion/lua_conversion.hpp"

namespace lstg
{
	class RenderMode;
}

namespace lua
{
	bool luaval_to_RenderMode(lua_State* L, int lo, lstg::RenderMode** outValue, const char* fName = "");
	bool luaval_to_Color4B(lua_State* L, int lo, cocos2d::Color4B* outValue, const char* fName = "");

	template<>
	struct to_native<lstg::RenderMode*> {
		static bool F(lua_State* L, int lo, lstg::RenderMode** outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (lua_isnil(L, lo)) {
				*outValue = nullptr;
				return true;
			}
			return luaval_to_RenderMode(L, lo, outValue, fName);
		}
	};
}
