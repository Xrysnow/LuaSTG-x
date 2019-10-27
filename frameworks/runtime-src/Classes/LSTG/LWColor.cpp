#include "LWColor.h"
#include "Global.h"
#include "UtilLua.h"
#include "UtilColor.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using cocos2d::Color4B;

Color4B* checkcolor(lua_State* L, int lo)
{
	return luaL_checkcolor(L, lo);
}

static int ARGB(lua_State* L)noexcept
{
	const Color4B* p = checkcolor(L, 1);
	lua_pushnumber(L, p->a);
	lua_pushnumber(L, p->r);
	lua_pushnumber(L, p->g);
	lua_pushnumber(L, p->b);
	return 4;
}

static int Meta_Eq(lua_State* L)noexcept
{
	const Color4B* pA = checkcolor(L, 1);
	const Color4B* pB = checkcolor(L, 2);
	lua_pushboolean(L, memcmp(pA, pB, sizeof(Color4B)) == 0);
	return 1;
}

static int Meta_Add(lua_State* L)noexcept
{
	const Color4B* pA = checkcolor(L, 1);
	const Color4B* pB = checkcolor(L, 2);
	const auto pResult = ColorWrapper::CreateAndPush(L);
	*pResult = *pA + *pB;
	return 1;
}

static int Meta_Sub(lua_State* L)noexcept
{
	const Color4B* pA = checkcolor(L, 1);
	const Color4B* pB = checkcolor(L, 2);
	const auto pResult = ColorWrapper::CreateAndPush(L);
	*pResult = *pA - *pB;
	return 1;
}

static int Meta_Mul(lua_State* L)noexcept
{
	lua_Number tFactor;
	Color4B *p = nullptr, *pResult = nullptr;
	if (lua_isnumber(L, 1))  // number * lstgColor
	{
		tFactor = luaL_checknumber(L, 1);
		p = checkcolor(L, 2);
	}
	else if (lua_isnumber(L, 2))  // lstgColor * number
	{
		tFactor = luaL_checknumber(L, 2);
		p = checkcolor(L, 1);
	}
	else  // lstgColor * lstgColor
	{
		const auto pA = checkcolor(L, 1);
		const auto pB = checkcolor(L, 2);
		pResult = ColorWrapper::CreateAndPush(L);
		*pResult = *pA * *pB;
		return 1;
	}
	pResult = ColorWrapper::CreateAndPush(L);
	*pResult = *p * tFactor;
	return 1;
}

static int Meta_ToString(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushfstring(L, "lstg.Color(a:%d, r:%d, g:%d, b:%d)", p->a, p->r, p->g, p->b);
	return 1;
}

static int GetAttr(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto k = luaL_checkstring(L, 2);
	if (k[0] == '\0')return 0;
	if (k[1] == '\0')
	{
		switch (k[0])
		{
		case 'r':
			lua_pushinteger(L, p->r);
			return 1;
		case 'g':
			lua_pushinteger(L, p->g);
			return 1;
		case 'b':
			lua_pushinteger(L, p->b);
			return 1;
		case 'a':
			lua_pushinteger(L, p->a);
			return 1;
		default:;
		}
	}
	if (strcmp(k, "argb") == 0)
	{
		lua_pushinteger(L, (p->a << 24) + (p->r << 16) + (p->g << 8) + p->b);
		return 1;
	}
	if (strcmp(k, "ARGB") == 0)
	{
		lua_pushcfunction(L, &ARGB);
		return 1;
	}
	return 0;
}

static int SetAttr(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto k = luaL_checkstring(L, 2);
	const auto k0 = k[0];
	if (k0 != '\0'&&k[1] == '\0')
	{
		const uint8_t v = luaL_checkinteger(L, 3);
		switch (k0)
		{
		case 'r':
			p->r = v;
			return 0;
		case 'g':
			p->g = v;
			return 0;
		case 'b':
			p->b = v;
			return 0;
		case 'a':
			p->a = v;
			return 0;
		default:;
		}
	}
	if (strcmp(k, "argb") == 0)
	{
		const uint32_t val = luaL_checknumber(L, 3);
		p->r = val >> 16;
		p->g = val >> 8;
		p->b = val;
		p->a = val >> 24;
	}
	return 0;
}

LUA_REGISTER_MODULE_DEF(lstg_Color)
{
	luaL_Reg tMethods[] =
	{
		//{ "ARGB", &ARGB },
		{ nullptr, nullptr }
	};
	luaL_Reg tMetaTable[] =
	{
		{ "__eq", &Meta_Eq },
		{ "__add", &Meta_Add },
		{ "__sub", &Meta_Sub },
		{ "__mul", &Meta_Mul },
		{ "__tostring", &Meta_ToString },
		{ "__index", &GetAttr },
		{ "__newindex", &SetAttr },
		{ nullptr, nullptr }
	};
	luaL_openlib(L, TYPENAME_COLOR, tMethods, 0);  // t
	luaL_newmetatable(L, TYPENAME_COLOR);  // t mt
	luaL_openlib(L, nullptr, tMetaTable, 0);  // t mt
	//lua_pushliteral(L, "__index");  // t mt s
	//lua_pushvalue(L, -3);  // t mt s t
	//lua_rawset(L, -3);  // t mt (mt["__index"] = t)
	lua_pushliteral(L, "__metatable");  // t mt s
	lua_pushvalue(L, -3);  // t mt s t
	lua_rawset(L, -3);  // t mt (mt["__metatable"] = t)  protect metatable
	lua_pop(L, 2);
	return 0;
}

Color4B* ColorWrapper::CreateAndPush(lua_State* L)
{
	const auto p = static_cast<Color4B*>(lua_newuserdata(L, sizeof(Color4B)));
	new(p) Color4B();  // construct inplace
	luaL_getmetatable(L, TYPENAME_COLOR);
	lua_setmetatable(L, -2);
	return p;
}

LUA_REGISTER_FUNC_DEF(lstg, Color)
{
	const auto top = lua_gettop(L);
	if (top == 0)
	{
		ColorWrapper::CreateAndPush(L);
		return 1;
	}
	Color4B c;
	if (top == 1)
	{
		// note: luaL_checkinteger return signed int
		const uint32_t val = luaL_checknumber(L, 1);
		c.r = val >> 16;
		c.g = val >> 8;
		c.b = val;
		c.a = val >> 24;
	}
	else
	{
		// a r g b -> r g b a
		c.set(
			int32_t(luaL_checkinteger(L, 2)),
			int32_t(luaL_checkinteger(L, 3)),
			int32_t(luaL_checkinteger(L, 4)),
			int32_t(luaL_checkinteger(L, 1))
		);
	}
	*ColorWrapper::CreateAndPush(L) = c;
	return 1;
}
