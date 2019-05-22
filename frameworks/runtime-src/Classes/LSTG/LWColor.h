#pragma once
#include "LuaWrapper.h"

namespace lstg
{
	/// @brief 颜色包装
	class ColorWrapper
	{
	public:
		/// @brief 向lua注册包装类
		static void Register(lua_State* L)noexcept;
		/// @brief 创建一个颜色类并推入堆栈
		static cocos2d::Color4B* CreateAndPush(lua_State* L);
	};
}
