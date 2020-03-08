#include "LuaWrapperEx.h"
#include "Global.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "Renderer.h"
#include "UtilLuaConversion.h"
#include "../Classes/XLuaModuleRegistry.h"
#include "../Classes/XStopWatch.h"

using namespace std;
using namespace lstg;

#pragma warning( disable : 4244 )

LUA_REGISTER_MODULE_DEF(lstg_ex)
{
	static StopWatch sw0;
	static StopWatch sw;

	struct WrapperImpl
	{
		static int QueryTimeMS(lua_State* L)noexcept
		{
			lua_pushnumber(L, sw0.get() * 1000);
			return 1;
		}
		static int Tic(lua_State* L)noexcept
		{
			lua_pushnumber(L, sw.get() * 1000);
			sw.reset();
			return 1;
		}
	};
	luaL_Reg tFunctions[] = {
		{ "QueryTimeMS", &WrapperImpl::QueryTimeMS },
		{ "Tic", &WrapperImpl::Tic },
		{ nullptr, nullptr }
	};
	luaL_register(L, "ex", tFunctions);
	lua_pop(L, 1);
	return 0;
}
