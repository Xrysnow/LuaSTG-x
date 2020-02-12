#pragma once
#include "RenderMode.h"
#include "../../cocos2d-x/external/lua/luajit/include/lua.hpp"

#define luaL_objerror(L) luaL_error(L, "invalid lstg object for '%s'", __FUNCTION__)

namespace lstg
{
	RenderMode* TranslateRenderMode(lua_State* L, int argnum);
	void TranslateAlignMode(lua_State* L, int argnum, cocos2d::TextHAlignment& halign, cocos2d::TextVAlignment& valign);
}
