#include "LWProfiler.h"
#include "AppFrame.h"
#include "../Classes/XProfiler.h"

using namespace std;
using namespace lstg;

#define GETNAME_CHECK string name = luaL_checkstring(L, 1); if (!CheckName(name))return 0;

bool CheckName(const string& name)
{
	static unordered_set<string> internalName = {
		LAPP.PF_Schedule,
		LAPP.PF_Visit,
		LAPP.PF_Render,
		LAPP.PF_BeginScene,
		LAPP.PF_EndScene
	};
	return internalName.find(name) == internalName.end();
}

void ProfilerWrapper::Register(lua_State* L) noexcept
{
	struct WrapperImpl
	{
		static int nameSchedule(lua_State* L)noexcept
		{
			lua_pushstring(L, LAPP.PF_Schedule.c_str());
			return 1;
		}

		static int nameVisit(lua_State* L) noexcept
		{
			lua_pushstring(L, LAPP.PF_Visit.c_str());
			return 1;
		}

		static int nameRender(lua_State* L) noexcept
		{
			lua_pushstring(L, LAPP.PF_Render.c_str());
			return 1;
		}

		static int nameBeginScene(lua_State* L) noexcept
		{
			lua_pushstring(L, LAPP.PF_BeginScene.c_str());
			return 1;
		}

		static int nameEndScene(lua_State* L) noexcept
		{
			lua_pushstring(L, LAPP.PF_EndScene.c_str());
			return 1;
		}

		static int tic(lua_State* L) noexcept
		{
			GETNAME_CHECK;
			XProfiler::getInstance()->tic(name);
			return 0;
		}

		static int toc(lua_State* L) noexcept
		{
			GETNAME_CHECK;
			lua_pushnumber(L, XProfiler::getInstance()->toc(name));
			return 1;
		}

		static int getAverage(lua_State* L) noexcept
		{
			lua_pushnumber(L, XProfiler::getInstance()->getAverage(luaL_checkstring(L, 1)));
			return 1;
		}

		static int getMin(lua_State* L) noexcept
		{
			lua_pushnumber(L, XProfiler::getInstance()->getMin(luaL_checkstring(L, 1)));
			return 1;
		}

		static int getMax(lua_State* L) noexcept
		{
			lua_pushnumber(L, XProfiler::getInstance()->getMax(luaL_checkstring(L, 1)));
			return 1;
		}

		static int getLast(lua_State* L) noexcept
		{
			lua_pushnumber(L, XProfiler::getInstance()->getLast(luaL_checkstring(L, 1)));
			return 1;
		}

		static int clear(lua_State* L) noexcept
		{
			XProfiler::getInstance()->clear(luaL_checkstring(L, 1));
			return 0;
		}

		static int clearAll(lua_State* L) noexcept
		{
			XProfiler::getInstance()->clearAll();
			return 0;
		}

	};
	luaL_Reg tFunctions[] =
	{
		{ "nameSchedule", &WrapperImpl::nameSchedule },
		{ "nameVisit", &WrapperImpl::nameVisit },
		{ "nameRender", &WrapperImpl::nameRender },
		{ "nameBeginScene", &WrapperImpl::nameBeginScene },
		{ "nameEndScene", &WrapperImpl::nameEndScene },
		{ "tic", &WrapperImpl::tic },
		{ "toc", &WrapperImpl::toc },
		{ "getAverage", &WrapperImpl::getAverage },
		{ "getMin", &WrapperImpl::getMin },
		{ "getMax", &WrapperImpl::getMax },
		{ "getLast", &WrapperImpl::getLast },
		{ "clear", &WrapperImpl::clear },
		{ "clearAll", &WrapperImpl::clearAll },
		{ nullptr, nullptr }
	};
	luaL_register(L, "profiler", tFunctions);
	lua_pop(L, 1);
}
