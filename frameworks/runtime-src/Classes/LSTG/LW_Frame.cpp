#include "LW_Frame.h"
#include "AppFrame.h"
#include "Renderer.h"

using namespace std;
using namespace lstg;

static int SetFPS(lua_State* L) noexcept
{
	int v = luaL_checkinteger(L, 1);
	if (v <= 0)
		v = 60;
	LAPP.setFPS(static_cast<uint32_t>(v));
	return 0;
}

static int GetFPS(lua_State* L) noexcept
{
	lua_pushnumber(L, LAPP.getFPS());
	return 1;
}

static int SetVsync(lua_State* L) noexcept
{
	LRR.setVsync(lua_toboolean(L, 1) != 0);
	return 0;
}

static int SystemLog(lua_State* L) noexcept
{
	LLOGGER.writeLine(string("[LOG] ") + luaL_checkstring(L, 1));
	return 0;
}

static int Print(lua_State* L) noexcept
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

static int DoFile(lua_State* L) noexcept
{
	LAPP.loadScript(luaL_checkstring(L, 1));
	return 0;
}

static int ShowSplashWindow(lua_State* L) noexcept
{
	if (lua_gettop(L) == 0)
		LAPP.ShowSplashWindow();
	else
		LAPP.ShowSplashWindow(luaL_checkstring(L, 1));
	return 0;
}

static int FrameInit(lua_State* L) noexcept
{
	if (!LAPP.Init())
	{
		return luaL_error(L, "FrameInit failed");
	}
	return 0;
}

static int FrameReset(lua_State* L) noexcept
{
	if (!LAPP.Reset())
	{
		return luaL_error(L, "FrameReset failed");
	}
	return 0;
}

vector<luaL_Reg> lstg::LW_Frame()
{
	vector<luaL_Reg> ret = {
		{ "SetFPS", &SetFPS },
		{ "GetFPS", &GetFPS },
		{ "SetVsync", &SetVsync },
		{ "SystemLog", &SystemLog },
		{ "Print", &Print },
		{ "DoFile", &DoFile },
		{ "ShowSplashWindow", &ShowSplashWindow },

		{ "FrameInit", &FrameInit },
		{ "FrameReset", &FrameReset },
	};
	return ret;
}
