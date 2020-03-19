#include "LW_Frame.h"
#include "AppFrame.h"
#include "Renderer.h"
#include "LogSystem.h"
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
	size_t size;
	const auto s = luaL_checklstring(L, 1, &size);
	LAPP.loadScript({ s,size });
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, Snapshot)
{
	size_t size;
	const auto s = luaL_checklstring(L, 1, &size);
	LAPP.snapShot({ s,size });
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
	if (!LAPP.frameInit())
	{
		return luaL_error(L, "FrameInit failed");
	}
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, FrameReset)
{
	if (!LAPP.frameReset())
	{
		return luaL_error(L, "FrameReset failed");
	}
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, FrameEnd)
{
	LAPP.frameShutdown();
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, GetPlatform)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	lua_pushstring(L, "windows");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
	lua_pushstring(L, "mac");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
	lua_pushstring(L, "linux");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	lua_pushstring(L, "android");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
	lua_pushstring(L, "ios");
#else
	lua_pushstring(L, "others");
#endif
	return 1;
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

#ifdef MessageBox
#undef MessageBox
#endif
LUA_REGISTER_FUNC_DEF(lstg, MessageBox)
{
	cocos2d::ccMessageBox(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
	return 0;
}
