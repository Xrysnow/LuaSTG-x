#include "XLuaModuleRegistry.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

LuaModuleRegistry* LuaModuleRegistry::get()
{
	static LuaModuleRegistry inst;
	return &inst;
}

LuaModuleRegistry& LuaModuleRegistry::addModule(const std::string& name, lua_CFunction regFunc, int32_t priority)
{
	auto inst = get();
	inst->modules[name] = { regFunc,priority };
	return *inst;
}

LuaModuleRegistry& LuaModuleRegistry::listModules(std::vector<std::pair<std::string, lua_CFunction>>& out)
{
	auto inst = get();
	std::multimap<int32_t, std::pair<std::string, lua_CFunction>> entries;
	for (auto& it : inst->modules)
		entries.insert({ it.second.second, {it.first, it.second.first} });
	for (auto& it : entries)
		out.push_back(it.second);
	return *inst;
}

LuaModuleRegistry& LuaModuleRegistry::registerModules(lua_State* L)
{
	std::vector<std::pair<std::string, lua_CFunction>> modules;
	listModules(modules);
	lua_pushvalue(L, LUA_GLOBALSINDEX);
	auto top = lua_gettop(L);
	for (auto& it : modules)
	{
		it.second(L);
		const auto new_top = lua_gettop(L);
		if (top != new_top)
		{
			cocos2d::log("Lua stack changed %d when register %s",
				new_top - top, it.first.c_str());
			top = new_top;
		}
	}
	lua_pop(L, 1);
	return *get();
}

LuaModuleRegistry& LuaModuleRegistry::addFunction(
	const std::string& nameSpace, const std::string& funcName, lua_CFunction regFunc)
{
	auto inst = get();
	auto& functions = inst->functions;
	if (functions.find(nameSpace) == functions.end())
		functions[nameSpace] = {};
	functions[nameSpace][funcName] = regFunc;
	return *inst;
}

LuaModuleRegistry& LuaModuleRegistry::listFunctions(
	std::vector<std::tuple<std::string, std::string, lua_CFunction>>& out)
{
	auto inst = get();
	for (auto& parent : inst->functions)
		for (auto& it : parent.second)
			out.emplace_back(parent.first, it.first, it.second);
	return *inst;
}

LuaModuleRegistry& LuaModuleRegistry::registerFunctions(lua_State* L)
{
	auto inst = get();
	lua_pushvalue(L, LUA_GLOBALSINDEX);
	for (auto& parent : inst->functions)
	{
		const auto pName = parent.first.c_str();
		tolua_open(L);
		tolua_module(L, pName, 0);
		tolua_beginmodule(L, pName);
		for (auto& it : parent.second)
			tolua_function(L, it.first.c_str(), it.second);
		tolua_endmodule(L);
	}
	lua_pop(L, 1);
	return *inst;
}
