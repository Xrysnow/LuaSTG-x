#pragma once
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

class LuaModuleRegistry
{
	LuaModuleRegistry() = default;
	~LuaModuleRegistry() = default;
	std::unordered_map<std::string, std::pair<lua_CFunction, int32_t>> modules;
	std::unordered_map<std::string, std::unordered_map<std::string, lua_CFunction>> functions;
public:
	LuaModuleRegistry(const LuaModuleRegistry &) = delete;
	LuaModuleRegistry &operator =(const LuaModuleRegistry &) = delete;

	static LuaModuleRegistry* get();

	static LuaModuleRegistry& addModule(
		const std::string& name,
		lua_CFunction regFunc,
		int32_t priority = 0);
	static LuaModuleRegistry& listModules(
		std::vector<std::pair<std::string, lua_CFunction>>& out);
	static LuaModuleRegistry& registerModules(lua_State* L);

	static LuaModuleRegistry& addFunction(
		const std::string& nameSpace,
		const std::string& funcName,
		lua_CFunction regFunc);
	static LuaModuleRegistry& listFunctions(
		std::vector<std::tuple<std::string, std::string, lua_CFunction>>& out);
	static LuaModuleRegistry& registerFunctions(lua_State* L);
};

#define LUA_REGISTER_MODULE(Name, Entry)\
	static CC_UNUSED auto& __make_ ## Name ## _ ## Entry ## __ = \
		LuaModuleRegistry::addModule(#Name, Entry)

#define LUA_REGISTER_MODULE_DEF(Name)\
	int LuaModule_##Name(lua_State* L);\
	LUA_REGISTER_MODULE(Name, LuaModule_##Name);\
	int LuaModule_##Name(lua_State* L)

#define LUA_REGISTER_FUNC(ParentName, Name, Entry)\
	static CC_UNUSED auto& __make_ ## ParentName ## _ ## Name ## _ ## Entry ## __ = \
		LuaModuleRegistry::addFunction(#ParentName, #Name, Entry)

#define LUA_REGISTER_FUNC_DEF(ParentName, Name)\
	int LuaFunc_##ParentName##_##Name(lua_State* L);\
	LUA_REGISTER_FUNC(ParentName, Name, LuaFunc_##ParentName##_##Name);\
	int LuaFunc_##ParentName##_##Name(lua_State* L)
