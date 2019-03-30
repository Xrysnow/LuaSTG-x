/// @file Global.h
/// @brief 全局定义文件
#pragma once

// C
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cmath>

// STL
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <regex>
#include <array>
#include <limits>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "cocos2d.h"

#if ((CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)\
	|| (CC_TARGET_PLATFORM == CC_PLATFORM_IOS))
#define PLATFORM_MOBILE
#elif ((CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)\
	|| (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)\
	|| (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX))
#define PLATFORM_PC
#else
#error
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
// Keep order
#include "WinSock2.h"
#include "Windows.h"
// CRTDBG
#include <crtdbg.h>
#endif

// fancy2d
#include "../fcyLib/fcyParser/fcyPathParser.h"
#include "../fcyLib/fcyMisc/fcyStopWatch.h"
#include "../fcyLib/fcyMisc/fcyStringHelper.h"
#include "../fcyLib/fcyMisc/fcyRandom.h"
#include "../fcyLib/fcyMemPool.h"
#include "../fcyLib/fcyType.h"
#include "../fcyLib/fcyMath.h"
#include "../fcyLib/f2dStruct.h"

// luajit
#include "../../cocos2d-x/external/lua/luajit/include/lua.hpp"

// macros

#if defined(_MSC_VER)
#define LNOINLINE __declspec(noinline)
#elif (defined(__GNUC__) && ((__GNUC__ >= 4))\
	||(defined(__clang__) && (__clang_major__ >= 3)))
#define LNOINLINE __attribute__((noinline))
#else
#error
#endif

#define LNOEXCEPT noexcept
#define LNOUSE(x) static_cast<void>(x)
#ifdef _DEBUG
//#define LDEBUG
#endif

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#define SAFE_DELETE(p) if(p){CC_SAFE_DELETE(p);}

// version

constexpr auto LVERSION = L"LuaSTG-x";
constexpr auto LVERSION_LUA = LUAJIT_VERSION;

// file names

constexpr auto LLOGFILE = "lstg_log.txt";
constexpr auto LLAUNCH_SCRIPT = L"launch";
constexpr auto LCORE_SCRIPT = L"core.lua";

// global callback names

constexpr auto LFUNC_GAMEINIT = "GameInit";
constexpr auto LFUNC_FRAME = "FrameFunc";
constexpr auto LFUNC_RENDER = "RenderFunc";
constexpr auto LFUNC_LOSEFOCUS = "FocusLoseFunc";
constexpr auto LFUNC_GAINFOCUS = "FocusGainFunc";

// object pool

constexpr auto LGOBJ_MAXCNT = 32768;  // 最大对象数
constexpr auto LGOBJ_MAXLASERNODE = 512;  // 曲线激光最大节点数
constexpr auto LGOBJ_DEFAULTGROUP = 0;  // 默认组
constexpr auto LGOBJ_GROUPCNT = 16;  // 碰撞组数

constexpr auto LPARTICLE_MAXCNT = 500;  // max count for each particle pool

constexpr auto TYPENAME_COLOR = "lstgColor";
constexpr auto TYPENAME_RANDGEN = "lstgRand";
constexpr auto TYPENAME_BENTLASER = "lstgBentLaserData";

// callback index in lua class

constexpr auto LGOBJ_CC_INIT = 1;
constexpr auto LGOBJ_CC_DEL = 2;
constexpr auto LGOBJ_CC_FRAME = 3;
constexpr auto LGOBJ_CC_RENDER = 4;
constexpr auto LGOBJ_CC_COLLI = 5;
constexpr auto LGOBJ_CC_KILL = 6;

// math const

constexpr auto LRAD2DEGREE = 57.29577951f; // rad to degree
constexpr auto LDEGREE2RAD = 0.0174532925f; // degree to rad
constexpr auto LPI_HALF = 1.5707963267f;  // PI*0.5

// assert for pointer
#define assert_ptr(p) if(p==nullptr){\
	LogSystem::getInstance()->Log(LogType::Error, "unexpected nullptr in %s (%s, line %d)",\
	__FUNCTION__, __FILE__, __LINE__);\
	CCASSERT(p, "unexpected nullptr");\
}

namespace lstg
{
	class AppFrame;
}
