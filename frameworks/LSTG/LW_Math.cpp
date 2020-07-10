#include "LW_Math.h"
#include "UtilLua.h"
#include "../Math/XMath.h"
#include "CollisionDetect.h"
#include "UtilLuaConversion.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;

LUA_REGISTER_FUNC_DEF(lstg, sin)
{
	lua_pushnumber(L, sin(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, cos)
{
	lua_pushnumber(L, cos(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, asin)
{
	lua_pushnumber(L, asin(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, acos)
{
	lua_pushnumber(L, acos(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, tan)
{
	lua_pushnumber(L, tan(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, atan)
{
	lua_pushnumber(L, atan(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, atan2)
{
	lua_pushnumber(L, atan2(luaL_checknumber(L, 1), luaL_checknumber(L, 2)) * LRAD2DEGREE);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, sincos)
{
	const auto angle = luaL_checknumber(L, 1) * LDEGREE2RAD;
	const auto s = std::sin(angle);
	const auto c = std::cos(angle);
	lua_pushnumber(L, s);
	lua_pushnumber(L, c);
	return 2;
}

LUA_REGISTER_FUNC_DEF(lstg, SampleBezierA1)
{
	auto in_pos = lua::getVec2Array(L, 1, "x", "y");
	auto i = luaL_checkinteger(L, 2);
	if (i > in_pos.size())
		i = in_pos.size();
	const auto l = float(luaL_checknumber(L, 3));
	const auto r = float(luaL_optnumber(L, 4, 0.4));
	lua_settop(L, 0);

	vector<cocos2d::Vec2> out_pos;
	vector<float> out_rot;
	lstg::SampleBezierA1(i, l, r, in_pos, out_pos, out_rot);
	vector<float> out_x; out_x.reserve(out_pos.size());
	vector<float> out_y; out_y.reserve(out_pos.size());
	for (auto& p : out_pos)
	{
		out_x.push_back(p.x);
		out_y.push_back(p.y);
	}

	lua::native_to_luaval(L, out_x);
	lua::native_to_luaval(L, out_y);
	lua::native_to_luaval(L, out_rot);
	return 3;
}

#define LUA_MATH_DEF1(F) LUA_REGISTER_FUNC_DEF(math, F) {\
	lua_pushnumber(L, std::F(\
		luaL_checknumber(L, 1)));\
	return 1;\
}
#define LUA_MATH_DEF2(F) LUA_REGISTER_FUNC_DEF(math, F) {\
	lua_pushnumber(L, std::F(\
		luaL_checknumber(L, 1), luaL_checknumber(L, 2)));\
	return 1;\
}

LUA_REGISTER_FUNC_DEF(math, div)
{
	const auto v = std::lldiv(
		luaL_checknumber(L, 1), luaL_checknumber(L, 2));
	lua_pushnumber(L, v.quot);
	lua_pushnumber(L, v.rem);
	return 2;
}

// basic

LUA_MATH_DEF2(remainder)
LUA_REGISTER_FUNC_DEF(math, fma)
{
	lua_pushnumber(L, std::fma(
		luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
	return 1;
}
LUA_MATH_DEF2(fdim)

// exp

LUA_MATH_DEF1(exp2)
LUA_MATH_DEF1(expm1)
LUA_MATH_DEF1(log2)
LUA_MATH_DEF1(log1p)

// pow

LUA_MATH_DEF1(cbrt)
LUA_MATH_DEF2(hypot)

// hyperbolic

LUA_MATH_DEF1(asinh)
LUA_MATH_DEF1(acosh)
LUA_MATH_DEF1(atanh)

// erf, gamma

LUA_MATH_DEF1(erf)
LUA_MATH_DEF1(erfc)
LUA_MATH_DEF1(tgamma)
LUA_MATH_DEF1(lgamma)

// rounding

LUA_MATH_DEF1(trunc)
LUA_MATH_DEF1(round)

// float operation

LUA_MATH_DEF2(scalbln)
LUA_MATH_DEF1(ilogb)
LUA_MATH_DEF1(logb)
LUA_MATH_DEF2(nextafter)
LUA_MATH_DEF2(nexttoward)
LUA_MATH_DEF2(copysign)

// classify

LUA_REGISTER_FUNC_DEF(math, fpclassify)
{
	switch (std::fpclassify(
		luaL_checknumber(L, 1)))
	{
	case FP_INFINITE: lua_pushliteral(L, "inf");
	case FP_NAN: lua_pushliteral(L, "nan");
	case FP_NORMAL: lua_pushliteral(L, "normal");
	case FP_SUBNORMAL: lua_pushliteral(L, "subnormal");
	case FP_ZERO: lua_pushliteral(L, "zero");
	default: lua_pushliteral(L, "unknown");
	}
	return 1;
}
LUA_MATH_DEF1(isfinite)
LUA_MATH_DEF1(isinf)
LUA_MATH_DEF1(isnan)
LUA_MATH_DEF1(isnormal)
LUA_REGISTER_FUNC_DEF(math, signbit)
{
	lua_pushboolean(L, std::signbit(
		luaL_checknumber(L, 1)));
	return 1;
}

