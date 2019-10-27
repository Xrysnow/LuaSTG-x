#pragma once
#include "LuaWrapper.h"

namespace lstg
{
	/// @brief 颜色包装
	class ColorWrapper
	{
	public:
		static cocos2d::Color4B* CreateAndPush(lua_State* L);
	};
}
