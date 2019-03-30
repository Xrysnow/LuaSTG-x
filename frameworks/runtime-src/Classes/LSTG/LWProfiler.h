#pragma once
#include "Global.h"

namespace lstg
{
	class ProfilerWrapper
	{
	public:
		/// @brief 向lua注册包装类
		static void Register(lua_State* L)noexcept;
	};
}
