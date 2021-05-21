#include "lua_Random_auto.hpp"
#include "../Classes/XRand.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using lstg::lua::luaval_to_native;
using lstg::lua::native_to_luaval;
using lstg::lua::luaval_to_unsigned_long_long;

#ifndef LUA_CHECK_COBJ_TYPE
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) if(!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
	#else
		#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) (void)(TYPE);
	#endif
#endif
#ifndef LUA_CHECK_COBJ
	#ifdef LUA_DEBUG
		#define LUA_CHECK_COBJ(L, COBJ, NAME) if(!(COBJ)) { return luaL_error((L), "invalid 'cobj' in '%s'", NAME); }
	#else
		#define LUA_CHECK_COBJ(L, COBJ, NAME)
	#endif
#endif
#ifndef LUA_CHECK_PARAMETER
	#define LUA_CHECK_PARAMETER(L, OK, NAME) if(!(OK)) { return luaL_error((L), "invalid arguments in '%s'", NAME); }
#endif
#ifndef LUA_PARAMETER_ERROR
	#define LUA_PARAMETER_ERROR(L, NAME, ARGC, EXPECT) return luaL_error((L), "wrong number of arguments in '%s': %d, expects %s", NAME, (ARGC), EXPECT);
#endif

int lua_x_Random_Random_below(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:below";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned long long arg0;
		ok &= luaval_to_unsigned_long_long(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->below(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_bernoulli(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:bernoulli";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->bernoulli(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_beta(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:beta";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->beta(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_binomial(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:binomial";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		double arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->binomial(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_cauchy(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:cauchy";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->cauchy(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_chi_squared(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:chi_squared";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->chi_squared(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_discrete(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:discrete";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::vector<double> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->discrete(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_expo(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:expo";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->expo(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_extreme_value(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:extreme_value";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->extreme_value(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_fisher_f(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:fisher_f";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->fisher_f(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_gamma(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:gamma";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->gamma(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_gauss(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:gauss";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->gauss(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_geometric(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:geometric";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->geometric(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_getDeviceSeed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:getDeviceSeed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = lstg::Random::getDeviceSeed();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Random_Random_getSeed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:getSeed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSeed();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Random_Random_log_normal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:log_normal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->log_normal(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_negative_binomial(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:negative_binomial";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		double arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->negative_binomial(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_normal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:normal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->normal(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_pareto(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:pareto";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->pareto(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_piecewise_constant(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:piecewise_constant";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::vector<double> arg0;
		std::vector<double> arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->piecewise_constant(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_piecewise_linear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:piecewise_linear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::vector<double> arg0;
		std::vector<double> arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->piecewise_linear(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_poisson(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:poisson";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->poisson(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_randFloat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:randFloat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->randFloat(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_randInt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:randInt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->randInt(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_randSign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:randSign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->randSign();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_x_Random_Random_range(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:range";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			long long arg0;
			ok &= luaval_to_long_long(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			long long arg1;
			ok &= luaval_to_long_long(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->range(arg0, arg1);
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			long long arg0;
			ok &= luaval_to_long_long(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			long long arg1;
			ok &= luaval_to_long_long(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			long long arg2;
			ok &= luaval_to_long_long(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->range(arg0, arg1, arg2);
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			unsigned long long arg0;
			ok &= luaval_to_unsigned_long_long(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->range(arg0);
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_setSeed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:setSeed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSeed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_student_t(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:student_t";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->student_t(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_x_Random_Random_triangular(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:triangular";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->triangular(arg0, arg1);
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			auto ret = cobj->triangular();
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->triangular(arg0, arg1, arg2);
			tolua_pushnumber(tolua_S, (lua_Number)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_x_Random_Random_uniform(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:uniform";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->uniform(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_vonMises(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:vonMises";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->vonMises(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_weibull(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random:weibull";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (lstg::Random*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->weibull(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_x_Random_Random_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "lstg.Random";
	constexpr auto LUA_FNAME = "lstg.Random constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new lstg::Random();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new lstg::Random(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	if (argc == 2) {
		unsigned int arg0;
		lstg::Random::GeneratorType arg1;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new lstg::Random(arg0, arg1);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}

static int lua_x_Random_Random_finalize(lua_State* tolua_S)
{
#ifdef LUA_DEBUG
	printf("luabindings: finalizing LUA object (Random)");
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Random", 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S, 2, &tolua_err)
	) {
		tolua_error(tolua_S, "#ferror in function 'delete'", &tolua_err);
		return 0;
	}
	else
#endif
	{
		auto* self = (lstg::Random*)tolua_tousertype(tolua_S, 1, 0);
#ifdef LUA_DEBUG
		if (!self) tolua_error(tolua_S, "invalid 'self' in function 'delete'", nullptr);
#endif
		delete self;
	}
	return 0;
}

int lua_register_x_Random_Random(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "lstg.Random");
	tolua_cclass(tolua_S, "Random", "lstg.Random", "", lua_x_Random_Random_finalize);

	tolua_beginmodule(tolua_S, "Random");
		tolua_function(tolua_S, "new", lua_x_Random_Random_constructor);
		tolua_function(tolua_S, "below", lua_x_Random_Random_below);
		tolua_function(tolua_S, "bernoulli", lua_x_Random_Random_bernoulli);
		tolua_function(tolua_S, "beta", lua_x_Random_Random_beta);
		tolua_function(tolua_S, "binomial", lua_x_Random_Random_binomial);
		tolua_function(tolua_S, "cauchy", lua_x_Random_Random_cauchy);
		tolua_function(tolua_S, "chi_squared", lua_x_Random_Random_chi_squared);
		tolua_function(tolua_S, "discrete", lua_x_Random_Random_discrete);
		tolua_function(tolua_S, "expo", lua_x_Random_Random_expo);
		tolua_function(tolua_S, "extreme_value", lua_x_Random_Random_extreme_value);
		tolua_function(tolua_S, "fisher_f", lua_x_Random_Random_fisher_f);
		tolua_function(tolua_S, "gamma", lua_x_Random_Random_gamma);
		tolua_function(tolua_S, "gauss", lua_x_Random_Random_gauss);
		tolua_function(tolua_S, "geometric", lua_x_Random_Random_geometric);
		tolua_function(tolua_S, "getSeed", lua_x_Random_Random_getSeed);
		tolua_function(tolua_S, "log_normal", lua_x_Random_Random_log_normal);
		tolua_function(tolua_S, "negative_binomial", lua_x_Random_Random_negative_binomial);
		tolua_function(tolua_S, "normal", lua_x_Random_Random_normal);
		tolua_function(tolua_S, "pareto", lua_x_Random_Random_pareto);
		tolua_function(tolua_S, "piecewise_constant", lua_x_Random_Random_piecewise_constant);
		tolua_function(tolua_S, "piecewise_linear", lua_x_Random_Random_piecewise_linear);
		tolua_function(tolua_S, "poisson", lua_x_Random_Random_poisson);
		tolua_function(tolua_S, "randFloat", lua_x_Random_Random_randFloat);
		tolua_function(tolua_S, "randInt", lua_x_Random_Random_randInt);
		tolua_function(tolua_S, "randSign", lua_x_Random_Random_randSign);
		tolua_function(tolua_S, "range", lua_x_Random_Random_range);
		tolua_function(tolua_S, "setSeed", lua_x_Random_Random_setSeed);
		tolua_function(tolua_S, "student_t", lua_x_Random_Random_student_t);
		tolua_function(tolua_S, "triangular", lua_x_Random_Random_triangular);
		tolua_function(tolua_S, "uniform", lua_x_Random_Random_uniform);
		tolua_function(tolua_S, "vonMises", lua_x_Random_Random_vonMises);
		tolua_function(tolua_S, "weibull", lua_x_Random_Random_weibull);
		tolua_function(tolua_S, "getDeviceSeed", lua_x_Random_Random_getDeviceSeed);
		{
			tolua_module(tolua_S, "GeneratorType", 0);
			tolua_beginmodule(tolua_S, "GeneratorType");
			{
				tolua_constant(tolua_S, "well512", (lua_Number)lstg::Random::GeneratorType::well512);
				tolua_constant(tolua_S, "minstd_rand0", (lua_Number)lstg::Random::GeneratorType::minstd_rand0);
				tolua_constant(tolua_S, "minstd_rand", (lua_Number)lstg::Random::GeneratorType::minstd_rand);
				tolua_constant(tolua_S, "mt19937", (lua_Number)lstg::Random::GeneratorType::mt19937);
				tolua_constant(tolua_S, "mt19937_64", (lua_Number)lstg::Random::GeneratorType::mt19937_64);
				tolua_constant(tolua_S, "ranlux24_base", (lua_Number)lstg::Random::GeneratorType::ranlux24_base);
				tolua_constant(tolua_S, "ranlux48_base", (lua_Number)lstg::Random::GeneratorType::ranlux48_base);
				tolua_constant(tolua_S, "ranlux24", (lua_Number)lstg::Random::GeneratorType::ranlux24);
				tolua_constant(tolua_S, "ranlux48", (lua_Number)lstg::Random::GeneratorType::ranlux48);
				tolua_constant(tolua_S, "knuth_b", (lua_Number)lstg::Random::GeneratorType::knuth_b);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(lstg::Random).name();
	g_luaType[typeName] = "lstg.Random";
	g_typeCast["Random"] = "lstg.Random";
	return 1;
}

int register_all_x_Random(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "lstg", 0);
	tolua_beginmodule(tolua_S, "lstg");

	lua_register_x_Random_Random(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

