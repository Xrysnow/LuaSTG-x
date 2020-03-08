#include "LW_Text.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "UnicodeStringEncoding.h"
#include "UtilLua.h"
#include "Renderer.h"
#include "UtilLuaRes.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

inline int error_find(lua_State* L, int lo)
{
	return luaL_error(L, "can't find font '%s'", lua_tostring(L, lo));
}
inline int error_render(lua_State* L, int lo)
{
	return luaL_error(L, "can't render font '%s'", lua_tostring(L, lo));
}

LUA_REGISTER_FUNC_DEF(lstg, RenderText)
{
	auto halign = TextHAlignment::LEFT;
	auto valign = TextVAlignment::TOP;
	if (lua_gettop(L) == 6)
		TranslateAlignMode(L, 6, halign, valign);
	auto p = lua::toResFont(L, 1);
	if (!p)
		return error_find(L, 1);
	if (!LRR.renderText(
		p,
		luaL_checkstring(L, 2),
		(float)luaL_checknumber(L, 3),
		(float)luaL_checknumber(L, 4),
		(float)(L_IMG_FACTOR * luaL_optnumber(L, 5, 1.0)),
		halign,
		valign
	))
	{
		return error_render(L, 1);
	}
	return 0;
}
//TODO:
LUA_REGISTER_FUNC_DEF(lstg, RenderTTF)
{
	auto left = float(luaL_checknumber(L, 3));
	auto right = float(luaL_checknumber(L, 4));
	auto bottom = float(luaL_checknumber(L, 5));
	auto top = float(luaL_checknumber(L, 6));

	if (lua_gettop(L) > 6)
	{
		auto halign = TextHAlignment::LEFT;
		auto valign = TextVAlignment::TOP;
		TranslateAlignMode(L, 7, halign, valign);
		auto rect = Rect(left, bottom, right - left, top - bottom);
		auto p = lua::toResFont(L, 1);
		if (!p)
		{
			return error_find(L, 1);
		}
		if (!LRR.renderTextAutoAlign(
			p,
			luaL_checkstring(L, 2),
			rect,
			//warning: In lstg, this size is 0.5x
			L_IMG_FACTOR * float(luaL_optnumber(L, 9, 1.0))*0.5,
			halign,
			valign,
			lua::luaval_to_c4b(L, 8)
		))
		{
			return error_render(L, 1);
		}
	}
	else//@xry
	{
		auto p = lua::toResFont(L, 1);
		if (!p)
			return error_find(L, 1);

		if (!LRR.renderText(
			p,
			luaL_checkstring(L, 2),
			left,
			top,
			max(0.f, right - left),
			max(0.f, top - bottom),
			L_IMG_FACTOR*0.5
		))
		{
			return error_render(L, 1);
		}
	}
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, CalcTextSize)
{
	auto p = lua::toResFont(L, 1);
	if (!p)
		return error_find(L, 1);
	const auto size = p->calcSize(luaL_checkstring(L, 2));
	lua_pushnumber(L, size.x * 0.5);
	lua_pushnumber(L, size.y * 0.5);
	return 2;
}
