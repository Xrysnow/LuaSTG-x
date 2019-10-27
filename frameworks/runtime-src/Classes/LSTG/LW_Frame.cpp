#include "LW_Frame.h"
#include "AppFrame.h"
#include "Renderer.h"
#include "tolua_fix.h"
#include "CCLuaEngine.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;

LUA_REGISTER_FUNC_DEF(lstg, SetFPS)
{
	int v = luaL_checkinteger(L, 1);
	if (v <= 0)
		v = 60;
	LAPP.setFPS(static_cast<uint32_t>(v));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, GetFPS)
{
	lua_pushnumber(L, LAPP.getFPS());
	return 1;
}

LUA_REGISTER_FUNC_DEF(lstg, SetVsync)
{
	LRR.setVsync(lua_toboolean(L, 1) != 0);
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, SystemLog)
{
	LLOGGER.writeLine(string("[LOG] ") + luaL_checkstring(L, 1));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, Print)
{
	int n = lua_gettop(L);
	lua_getglobal(L, "tostring"); // ... f
	lua_pushstring(L, ""); // ... f s
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
		{
			lua_pushstring(L, "\t"); // ... f s s
			lua_concat(L, 2); // ... f s
		}
		lua_pushvalue(L, -2); // ... f s f
		lua_pushvalue(L, i); // ... f s f arg[i]
		lua_call(L, 1, 1); // ... f s ret
		//const char* x = luaL_checkstring(L, -1);
		lua_concat(L, 2); // ... f s
	}
	string info = luaL_checkstring(L, -1);
	lua_pop(L, 2);
	cocos2d::log("%s", info.c_str());
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, DoFile)
{
	LAPP.loadScript(luaL_checkstring(L, 1));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, ShowSplashWindow)
{
	if (lua_gettop(L) == 0)
		LAPP.ShowSplashWindow();
	else
		LAPP.ShowSplashWindow(luaL_checkstring(L, 1));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, SetThreadPoolSize)
{
	const auto val = luaL_checkinteger(L, 1);
	if (val < 0)
		return luaL_error(L, "invalid argument");
	LTHP.resize(val);
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, GetThreadPoolSize)
{
	lua_pushinteger(L, LTHP.size());
	return 1;
}

LUA_REGISTER_FUNC_DEF(lstg, FrameInit)
{
	if (!LAPP.Init())
	{
		return luaL_error(L, "FrameInit failed");
	}
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, FrameReset)
{
	if (!LAPP.Reset())
	{
		return luaL_error(L, "FrameReset failed");
	}
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, SetOnWriteLog)
{
	const auto handler = toluafix_ref_function(L, 1, 0);
	if (handler == 0)
		return luaL_error(L, "invalid argument");
	LLOGGER.setOnWrite([=](const std::string& str)
	{
		auto stack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		stack->pushString(str.c_str(), str.size());
		stack->executeFunctionByHandler(handler, 1);
		stack->clean();
	});
	return 0;
}
