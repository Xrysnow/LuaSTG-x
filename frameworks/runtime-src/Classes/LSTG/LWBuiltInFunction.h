#pragma once
#include "Global.h"

namespace lstg
{
	/// @brief 内建函数包装
	class BuiltInFunctionWrapper
	{
	public:
		/// @brief 向lua注册包装类
		static void Register(lua_State* L);
	};
}
