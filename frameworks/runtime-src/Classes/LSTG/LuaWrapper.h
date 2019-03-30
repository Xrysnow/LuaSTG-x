#pragma once
#include "BlendMode.h"
#include "../../cocos2d-x/external/lua/luajit/include/lua.hpp"

#define luaL_objerror(L) luaL_error(L, "invalid lstg object for '%s'", __FUNCTION__)

namespace lstg
{
	BlendMode* TranslateBlendMode(lua_State* L, int argnum);
	void TranslateAlignMode(lua_State* L, int argnum, cocos2d::TextHAlignment& halign, cocos2d::TextVAlignment& valign);
	void RegistWrapper(lua_State* L);
}

