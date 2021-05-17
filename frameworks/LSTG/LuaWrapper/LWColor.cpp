#include "LWColor.h"
#include "Global.h"
#include "Util/UtilLua.h"
#include "Util/UtilColor.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using cocos2d::Color4B;

constexpr int COLOR_IDX_METHOD = 1;
constexpr int COLOR_IDX_GETTER = 2;
constexpr int COLOR_IDX_SETTER = 3;
constexpr int COLOR_IDX_CTOR = 4;

Color4B* checkcolor(lua_State* L, int lo)
{
	return luaL_checkcolor(L, lo);
}

uint8_t check_byte(lua_State* L, int lo)
{
	return std::max(0.0, std::min(luaL_checknumber(L, lo), 255.0));
}

uint8_t check_float(lua_State* L, int lo)
{
	return std::max(0.0, std::min(luaL_checknumber(L, lo)*255.0, 255.0));
}

static int color_ARGB(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushnumber(L, p->a);
	lua_pushnumber(L, p->r);
	lua_pushnumber(L, p->g);
	lua_pushnumber(L, p->b);
	return 4;
}

static int color_unpack(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushnumber(L, p->r);
	lua_pushnumber(L, p->g);
	lua_pushnumber(L, p->b);
	lua_pushnumber(L, p->a);
	return 4;
}
static int color_unpackFloat(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushnumber(L, p->r / 255.0);
	lua_pushnumber(L, p->g / 255.0);
	lua_pushnumber(L, p->b / 255.0);
	lua_pushnumber(L, p->a / 255.0);
	return 4;
}

static int color_clone(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto c = ColorWrapper::CreateAndPush(L);
	*c = *p;
	return 1;
}

static int color_set(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto narg = lua_gettop(L) - 1;
	p->r = check_byte(L, 2);
	p->g = check_byte(L, 3);
	p->b = check_byte(L, 4);
	if (narg >= 4)
		p->a = check_byte(L, 5);
	lua_settop(L, 1);
	return 1;
}

static int color_setFloat(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto narg = lua_gettop(L) - 1;
	p->r = check_float(L, 2);
	p->g = check_float(L, 3);
	p->b = check_float(L, 4);
	if (narg >= 4)
		p->a = check_float(L, 5);
	lua_settop(L, 1);
	return 1;
}

static int color_meta_eq(lua_State* L)noexcept
{
	const auto pA = checkcolor(L, 1);
	const auto pB = checkcolor(L, 2);
	lua_pushboolean(L, memcmp(pA, pB, sizeof(Color4B)) == 0);
	return 1;
}

static int color_meta_add(lua_State* L)noexcept
{
	const auto pA = checkcolor(L, 1);
	const auto pB = checkcolor(L, 2);
	const auto pResult = ColorWrapper::CreateAndPush(L);
	*pResult = *pA + *pB;
	return 1;
}

static int color_meta_sub(lua_State* L)noexcept
{
	const auto pA = checkcolor(L, 1);
	const auto pB = checkcolor(L, 2);
	const auto pResult = ColorWrapper::CreateAndPush(L);
	*pResult = *pA - *pB;
	return 1;
}

static int color_meta_mul(lua_State* L)noexcept
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

static int color_meta_tostring(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushfstring(L, "lstg.Color(a:%d, r:%d, g:%d, b:%d)", p->a, p->r, p->g, p->b);
	return 1;
}

static int color_getter_argb(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	lua_pushinteger(L, (p->a << 24) + (p->r << 16) + (p->g << 8) + p->b);
	return 1;
}

static int color_setter_argb(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const uint32_t val = (uint32_t)luaL_checknumber(L, 2);
	p->r = val >> 16;
	p->g = val >> 8;
	p->b = val;
	p->a = val >> 24;
	return 0;
}

static int color_meta_index(lua_State* L)noexcept
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

	//luaL_getmetatable(L, TYPENAME_COLOR); // t k mt
	lua_getmetatable(L, 1); // t k mt
	lua_rawgeti(L, -1, COLOR_IDX_METHOD); // t k mt methods
	lua_pushvalue(L, 2); // t k mt methods k
	lua_rawget(L, -2); // t k mt methods f
	if (!lua_isnil(L, -1))
		return 1;
	lua_pop(L, 2); // t k mt
	lua_rawgeti(L, -1, COLOR_IDX_GETTER); // t k mt getters
	lua_pushvalue(L, 2); // t k mt getters k
	lua_rawget(L, -2); // t k mt getters k f
	if (!lua_isnil(L, -1))
	{
		lua_pushvalue(L, 1); // t k mt getters k f t
		lua_call(L, 1, 1);
		return 1;
	}
	return 0;
}

static int color_meta_newindex(lua_State* L)noexcept
{
	const auto p = checkcolor(L, 1);
	const auto k = luaL_checkstring(L, 2);
	const auto k0 = k[0];
	if (k0 != '\0'&&k[1] == '\0')
	{
		const uint8_t v = (uint8_t)luaL_checkinteger(L, 3);
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

	//luaL_getmetatable(L, TYPENAME_COLOR); // t k v mt
	lua_getmetatable(L, 1);
	lua_rawgeti(L, -1, COLOR_IDX_SETTER); // t k v mt setters
	lua_pushvalue(L, 2); // t k v mt setters k
	lua_rawget(L, -2); // t k v mt setters f
	if (!lua_isnil(L, -1))
	{
		lua_pushvalue(L, 1); // t k v mt setters f t
		lua_pushvalue(L, 3); // t k v mt setters f t v
		lua_call(L, 2, 0);
		return 0;
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
		{ "__eq", &color_meta_eq },
		{ "__add", &color_meta_add },
		{ "__sub", &color_meta_sub },
		{ "__mul", &color_meta_mul },
		{ "__tostring", &color_meta_tostring },
		{ "__index", &color_meta_index },
		{ "__newindex", &color_meta_newindex },
		{ nullptr, nullptr }
	};
	luaL_openlib(L, TYPENAME_COLOR, tMethods, 0); // t
	luaL_newmetatable(L, TYPENAME_COLOR); // t mt
	luaL_openlib(L, nullptr, tMetaTable, 0); // t mt

	// methods, getters, setters
	for (auto s : { COLOR_IDX_METHOD,COLOR_IDX_GETTER,COLOR_IDX_SETTER })
	{
		lua_pushinteger(L, s);
		lua_newtable(L);
		lua_rawset(L, -3);
	}

	lua_rawgeti(L, -1, COLOR_IDX_METHOD); // t mt methods
	tolua_function(L, "ARGB", color_ARGB);
	tolua_function(L, "unpack", color_unpack);
	tolua_function(L, "unpackFloat", color_unpackFloat);
	tolua_function(L, "clone", color_clone);
	tolua_function(L, "set", color_set);
	tolua_function(L, "setFloat", color_setFloat);
	lua_pop(L, 1); // t mt

	lua_rawgeti(L, -1, COLOR_IDX_GETTER); // t mt getters
	tolua_function(L, "argb", color_getter_argb);
	lua_pop(L, 1); // t mt

	lua_rawgeti(L, -1, COLOR_IDX_SETTER); // t mt setters
	tolua_function(L, "argb", color_setter_argb);
	lua_pop(L, 1); // t mt

	lua_pop(L, 2);
	return 0;
}

Color4B* ColorWrapper::CreateAndPush(lua_State* L)
{
	const auto p = static_cast<Color4B*>(lua_newuserdata(L, sizeof(Color4B)));
	*p = Color4B();
	luaL_getmetatable(L, TYPENAME_COLOR);
	lua_setmetatable(L, -2);
	return p;
}

LUA_REGISTER_FUNC_DEF(lstg, Color)
{
	const auto top = lua_gettop(L);
	const auto p = ColorWrapper::CreateAndPush(L); // ... o
	if (top == 0)
		return 1;
	const auto isnum = lua_isnumber(L, 1);
	if ((top == 1 || top == 4) && isnum)
	{
		Color4B c;
		if (top == 1)
		{
			// note: luaL_checkinteger return signed int, should use luaL_checknumber
			const uint32_t val = (uint32_t)luaL_checknumber(L, 1);
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
		*p = c;
	}
	else
	{
		lua_getmetatable(L, -1); // ... o mt
		lua_rawgeti(L, -1, COLOR_IDX_CTOR); // ... o mt f
		if (!lua_isnil(L, -1))
		{
			lua_insert(L, 1); // f ... o mt
			lua_pop(L, 1); // f ... o
			lua_pushvalue(L, -1); // f ... o o
			lua_insert(L, 1); // o f ...
			lua_insert(L, 3); // o f o ...
			lua_call(L, top + 1, 0); // o
		}
		else
		{
			lua_pop(L, 2); // ... o
		}
	}
	return 1;
}
