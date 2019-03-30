#pragma once
#include "Global.h"
namespace lstg
{
	class LL2DWrapper
	{
	public:
#ifdef USEL2D
		/// @brief 向lua注册包装类
		static void Register(lua_State* L)noexcept;
#else
		static void Register(lua_State* L)noexcept {}
#endif
	};

	/// @brief 视频功能包装 @xry
	class VideoWrapper
	{
	public:
#ifdef USE_VIDEO
		/// @brief 向lua注册包装类
		static void Register(lua_State* L)noexcept;
#else
		static void Register(lua_State* L)noexcept {}
#endif
	};

	/// @brief EX函数包装 @xry
	class EXWrapper
	{
	public:
		/// @brief 向lua注册包装类
		static void Register(lua_State* L)noexcept;
	};

}
