#pragma once
#include "Global.h"
#include "../fcyLib/fcyMisc/fcyRandom.h"

namespace lstg
{
	class RandomizerWrapper
	{
	public:
		static void Register(lua_State* L)noexcept;
		static fcyRandomWELL512* CreateAndPush(lua_State* L);
	};
}
