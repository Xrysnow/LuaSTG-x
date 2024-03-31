#include "lua_Random_auto.hpp"
#include "XRand.h"

int luaReg_Random_lstgRandomGeneratorType(lua_State* lua_S)
{
	LUA_ENUM_DEF("GeneratorType");
	LUA_ENUM_ENTRY("well512", lstg::Random::GeneratorType::well512);
	LUA_ENUM_ENTRY("minstd_rand0", lstg::Random::GeneratorType::minstd_rand0);
	LUA_ENUM_ENTRY("minstd_rand", lstg::Random::GeneratorType::minstd_rand);
	LUA_ENUM_ENTRY("mt19937", lstg::Random::GeneratorType::mt19937);
	LUA_ENUM_ENTRY("mt19937_64", lstg::Random::GeneratorType::mt19937_64);
	LUA_ENUM_ENTRY("ranlux24_base", lstg::Random::GeneratorType::ranlux24_base);
	LUA_ENUM_ENTRY("ranlux48_base", lstg::Random::GeneratorType::ranlux48_base);
	LUA_ENUM_ENTRY("ranlux24", lstg::Random::GeneratorType::ranlux24);
	LUA_ENUM_ENTRY("ranlux48", lstg::Random::GeneratorType::ranlux48);
	LUA_ENUM_ENTRY("knuth_b", lstg::Random::GeneratorType::knuth_b);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_Random_new(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Random", "lstg.Random:new");
	LUA_TRY_CTOR(2, [](uint32_t arg0,lstg::Random::GeneratorType arg1){{return new lstg::Random(std::move(arg0),std::move(arg1));}});
	LUA_TRY_CTOR(1, [](uint32_t arg0){{return new lstg::Random(std::move(arg0));}});
	LUA_TRY_CTOR(0, [](){{return new lstg::Random();}});
	LUA_SINVOKE_FOOTER("0,1,2");
}
int lua_lstg_Random_delete(lua_State* lua_S)
{
	auto cobj = LUA_TO_COBJ(lstg::Random*, 1);
	delete cobj;
	return 0;
}
int lua_lstg_Random_bernoulli(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:bernoulli");
	LUA_TRY_INVOKE_R(1, &lstg::Random::bernoulli);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_binomial(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:binomial");
	LUA_TRY_INVOKE_R(2, &lstg::Random::binomial);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_cauchy(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:cauchy");
	LUA_TRY_INVOKE_R(2, &lstg::Random::cauchy);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_chi_squared(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:chi_squared");
	LUA_TRY_INVOKE_R(1, &lstg::Random::chi_squared);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_discrete(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:discrete");
	LUA_TRY_INVOKE_R(1, &lstg::Random::discrete);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_extreme_value(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:extreme_value");
	LUA_TRY_INVOKE_R(2, &lstg::Random::extreme_value);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_fisher_f(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:fisher_f");
	LUA_TRY_INVOKE_R(2, &lstg::Random::fisher_f);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_geometric(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:geometric");
	LUA_TRY_INVOKE_R(1, &lstg::Random::geometric);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_getSeed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:getSeed");
	LUA_TRY_INVOKE_R(0, &lstg::Random::getSeed);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Random_negative_binomial(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:negative_binomial");
	LUA_TRY_INVOKE_R(2, &lstg::Random::negative_binomial);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_piecewise_constant(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:piecewise_constant");
	LUA_TRY_INVOKE_R(2, &lstg::Random::piecewise_constant);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_piecewise_linear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:piecewise_linear");
	LUA_TRY_INVOKE_R(2, &lstg::Random::piecewise_linear);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_poisson(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:poisson");
	LUA_TRY_INVOKE_R(1, &lstg::Random::poisson);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_randFloat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:randFloat");
	LUA_TRY_INVOKE_R(2, &lstg::Random::randFloat);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_randInt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:randInt");
	LUA_TRY_INVOKE_R(2, &lstg::Random::randInt);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_randSign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:randSign");
	LUA_TRY_INVOKE_R(0, &lstg::Random::randSign);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Random_setSeed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:setSeed");
	LUA_TRY_INVOKE(1, &lstg::Random::setSeed);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_student_t(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:student_t");
	LUA_TRY_INVOKE_R(1, &lstg::Random::student_t);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Random_uniform_int(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Random", "lstg.Random:uniform_int");
	LUA_TRY_INVOKE_R(2, &lstg::Random::uniform_int);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Random_getDeviceSeed(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Random", "lstg.Random:getDeviceSeed");
	LUA_TRY_INVOKE_R(0, &lstg::Random::getDeviceSeed);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_Random_lstgRandom(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Random, "Random", "lstg.Random",
		xmath::random::Random, "lstg_sym.xmath.random.Random",
		lua_lstg_Random_new, lua_lstg_Random_delete);
	LUA_METHOD("new", lua_lstg_Random_new);
	LUA_METHOD("bernoulli", lua_lstg_Random_bernoulli);
	LUA_METHOD("binomial", lua_lstg_Random_binomial);
	LUA_METHOD("cauchy", lua_lstg_Random_cauchy);
	LUA_METHOD("chi_squared", lua_lstg_Random_chi_squared);
	LUA_METHOD("discrete", lua_lstg_Random_discrete);
	LUA_METHOD("extreme_value", lua_lstg_Random_extreme_value);
	LUA_METHOD("fisher_f", lua_lstg_Random_fisher_f);
	LUA_METHOD("geometric", lua_lstg_Random_geometric);
	LUA_METHOD("getSeed", lua_lstg_Random_getSeed);
	LUA_METHOD("negative_binomial", lua_lstg_Random_negative_binomial);
	LUA_METHOD("piecewise_constant", lua_lstg_Random_piecewise_constant);
	LUA_METHOD("piecewise_linear", lua_lstg_Random_piecewise_linear);
	LUA_METHOD("poisson", lua_lstg_Random_poisson);
	LUA_METHOD("randFloat", lua_lstg_Random_randFloat);
	LUA_METHOD("randInt", lua_lstg_Random_randInt);
	LUA_METHOD("randSign", lua_lstg_Random_randSign);
	LUA_METHOD("setSeed", lua_lstg_Random_setSeed);
	LUA_METHOD("student_t", lua_lstg_Random_student_t);
	LUA_METHOD("uniform_int", lua_lstg_Random_uniform_int);
	LUA_METHOD("getDeviceSeed", lua_lstg_Random_getDeviceSeed);
	luaReg_Random_lstgRandomGeneratorType(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
