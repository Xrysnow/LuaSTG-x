#pragma once
#include "LuaWrapper.h"

namespace lstg
{
	// 对象控制函数（这些方法将被转发到对象池）
	std::vector<luaL_Reg> LW_Object();
}
