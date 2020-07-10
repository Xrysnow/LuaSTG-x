#pragma once
#include "Global.h"
#include "../Classes/RandomWELL512.h"

namespace lstg
{
	class RandomizerWrapper
	{
	public:
		static RandomWELL512* CreateAndPush(lua_State* L);
	};
}
