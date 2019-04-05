#include "LW_Text.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "UnicodeStringEncoding.h"
#include "Utility.h"
#include "UtilLua.h"
#include "Renderer.h"
#include "UtilLuaRes.h"
#include "../fcyLib/fcyMisc/fcyStringHelper.h"

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

static int RenderText(lua_State* L) noexcept
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
static int RenderTTF(lua_State* L) noexcept
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

static int CalcTextSize(lua_State* L)
{
	auto p = lua::toResFont(L, 1);
	if (!p)
		return error_find(L, 1);
	auto text = luaL_checkstring(L, 2);
	// 编码转换 TODO: ???
	static wstring s_TempStringBuf;
	string txt;
	try
	{
		Utf8ToUtf16(text, s_TempStringBuf);
		txt = fcyStringHelper::WideCharToMultiByte_UTF8(s_TempStringBuf);
	}
	catch (const bad_alloc&)
	{
		return luaL_error(L, "can't convert code, out of memory.");
	}
	auto size = p->calcSize(txt);
	lua_pushnumber(L, size.x * 0.5);
	lua_pushnumber(L, size.y * 0.5);
	return 2;
}

vector<luaL_Reg> lstg::LW_Text()
{
	vector<luaL_Reg> ret = {
		{ "RenderText", &RenderText },
		{ "RenderTTF", &RenderTTF },		//extended
		{ "CalcTextSize", &CalcTextSize },	//new
	};
	return ret;
}
