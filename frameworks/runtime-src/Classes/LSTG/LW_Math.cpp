#include "LW_Math.h"
#include "UtilLua.h"
#include "../Math/XMath.h"
#include "CollisionDetect.h"
#include "MemPoolManager.h"
#include "Renderer.h"

using namespace std;
using namespace lstg;

static int Sin(lua_State* L) noexcept
{
	lua_pushnumber(L, sin(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
static int Cos(lua_State* L) noexcept
{
	lua_pushnumber(L, cos(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
static int ASin(lua_State* L) noexcept
{
	lua_pushnumber(L, asin(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
static int ACos(lua_State* L) noexcept
{
	lua_pushnumber(L, acos(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
static int Tan(lua_State* L) noexcept
{
	lua_pushnumber(L, tan(luaL_checknumber(L, 1) * LDEGREE2RAD));
	return 1;
}
static int ATan(lua_State* L) noexcept
{
	lua_pushnumber(L, atan(luaL_checknumber(L, 1)) * LRAD2DEGREE);
	return 1;
}
static int ATan2(lua_State* L) noexcept
{
	lua_pushnumber(L, atan2(luaL_checknumber(L, 1), luaL_checknumber(L, 2)) * LRAD2DEGREE);
	return 1;
}
static int SinCos(lua_State* L) noexcept //TODO
{
	const auto angle = luaL_checknumber(L, 1) * LDEGREE2RAD;
	const auto s = std::sin(angle);
	const auto c = std::cos(angle);
	lua_pushnumber(L, s);
	lua_pushnumber(L, c);
	return 2;
}
static int SampleBezierA1_(lua_State* L) noexcept
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

	lua::pushArray(L,out_x);
	lua::pushArray(L,out_y);
	lua::pushArray(L,out_rot);
	return 3;
}

vector<luaL_Reg> lstg::LW_Math()
{
	vector<luaL_Reg> ret = {
		{ "sin", &Sin },
		{ "cos", &Cos },
		{ "asin", &ASin },
		{ "acos", &ACos },
		{ "tan", &Tan },
		{ "atan", &ATan },
		{ "atan2", &ATan2 },

		{ "SampleBezierA1", &SampleBezierA1_ },
	};
	return ret;
}
