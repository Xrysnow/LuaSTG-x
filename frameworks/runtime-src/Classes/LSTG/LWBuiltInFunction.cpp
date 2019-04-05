#include "LWBuiltInFunction.h"
#include "AppFrame.h"
#include "LWColor.h"
#include "LWRandomizer.h"
#include "GameObjectBentLaser.h"

#include "LW_Audio.h"
#include "LW_Frame.h"
#include "LW_Graph.h"
#include "LW_Input.h"
#include "LW_Math.h"
#include "LW_Object.h"
#include "LW_Render.h"
#include "LW_Text.h"

using namespace std;
using namespace lstg;
using cocos2d::Color4B;

void BuiltInFunctionWrapper::Register(lua_State* L)
{
	vector<luaL_Reg> functions;
	auto lw_base = {
		LW_Audio(),
		LW_Frame(),
		LW_Graph(),
		LW_Input(),
		LW_Math(),
		LW_Object(),
		LW_Render(),
		LW_Text(),
	};
	for(auto& lw : lw_base)
		functions.insert(functions.end(), lw.begin(), lw.end());

	struct Misc
	{
		static int Snapshot(lua_State* L) noexcept
		{
			LAPP.SnapShot(luaL_checkstring(L, 1));
			return 0;
		}
		static int Execute(lua_State* L) noexcept
		{
			return 0;
		}
	};

	struct Debug
	{
		static int ObjTable(lua_State* L) noexcept
		{
			return LPOOL.GetObjectTable(L);
		}
	};

	struct Constructor
	{
		static int NewColor(lua_State* L) noexcept
		{
			Color4B c;
			if (lua_gettop(L) == 1)
			{
				// note: luaL_checkinteger return signed int
				const uint32_t val = luaL_checknumber(L, 1);
				c.a = val >> 24;
				c.r = val >> 16;
				c.g = val >> 8;
				c.b = val;
			}
			else
			{
				// a r g b
				c.set(
					int32_t(luaL_checkinteger(L, 2)),
					int32_t(luaL_checkinteger(L, 3)),
					int32_t(luaL_checkinteger(L, 4)),
					int32_t(luaL_checkinteger(L, 1))
				);
			}
			*ColorWrapper::CreateAndPush(L) = c;
			return 1;
		}
		static int NewRand(lua_State* L) noexcept
		{
			RandomizerWrapper::CreateAndPush(L);
			return 1;
		}
		//static int BentLaserData(lua_State* L) noexcept
		//{
		//	GameObjectBentLaser::CreateAndPush(L);
		//	return 1;
		//}
	};

	struct Deprecated
	{
		static int UpdateObjList(lua_State* L) noexcept
		{
			return 0;
		}
		static int RegTTF(lua_State* L) noexcept
		{
			return 0;
		}
		static int UpdateSound(lua_State* L) noexcept
		{
			return 0;
		}
	};

	vector<luaL_Reg> misc = {
		{ "Snapshot", &Misc::Snapshot },
		{ "Execute", &Misc::Execute },
		{ "ObjTable", &Debug::ObjTable },
		{ "Color", &Constructor::NewColor },
		{ "Rand", &Constructor::NewRand },
		//{ "BentLaserData", &Constructor::BentLaserData },
		{ "UpdateObjList", &Deprecated::UpdateObjList },
		{ "RegTTF", &Deprecated::RegTTF },
		{ "UpdateSound", &Deprecated::UpdateSound },
	};

	functions.insert(functions.end(), misc.begin(), misc.end());
	functions.push_back({ nullptr, nullptr });

	luaL_register(L, "lstg", functions.data());
	lua_pop(L, 1);
}

