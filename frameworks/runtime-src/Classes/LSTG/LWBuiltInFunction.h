#pragma once
#include "Global.h"

namespace lstg
{
	class BuiltInFunctionWrapper
	{
	public:
		static void Register(lua_State* L);
	};
}
