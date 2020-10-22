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

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
// Keep order
#include "WinSock2.h"
#include "Windows.h"
// CRTDBG
#include <crtdbg.h>
#endif

// luajit
#include "../../cocos2d-x/external/lua/luajit/include/lua.hpp"

// macros

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

// file names

constexpr auto LLOGFILE = "lstg_log.txt";
constexpr auto LLAUNCH_SCRIPT = "main.lua";

// global callback names

//constexpr auto LFUNC_GAMEINIT = "GameInit";
//constexpr auto LFUNC_FRAME = "FrameFunc";
//constexpr auto LFUNC_RENDER = "RenderFunc";
constexpr auto LFUNC_LOSEFOCUS = "FocusLoseFunc";
constexpr auto LFUNC_GAINFOCUS = "FocusGainFunc";
constexpr auto LFUNC_FINDRES = "FindResForObject";

// object pool

// max object count
constexpr auto LGOBJ_MAXCNT = 32768;
// max node count for bent laser
constexpr auto LGOBJ_MAXLASERNODE = 512;
// group count
constexpr auto LGOBJ_GROUPCNT = 16;
// max count for each particle pool
constexpr auto LPARTICLE_MAXCNT = 500;
// type name for lua color class
constexpr auto TYPENAME_COLOR = "lstgColor";
// type name for lua rng class
constexpr auto TYPENAME_RANDGEN = "lstgRand";

// callback index in lua class

constexpr auto LGOBJ_CC_INIT = 1;
constexpr auto LGOBJ_CC_DEL = 2;
constexpr auto LGOBJ_CC_FRAME = 3;
constexpr auto LGOBJ_CC_RENDER = 4;
constexpr auto LGOBJ_CC_COLLI = 5;
constexpr auto LGOBJ_CC_KILL = 6;

// math const

// rad to degree
constexpr auto LRAD2DEGREE = 57.29577951f;
constexpr auto LRAD2DEGREE_D = 57.295779513082320876;
// degree to rad
constexpr auto LDEGREE2RAD = 0.0174532925f;
constexpr auto LDEGREE2RAD_D = 0.017453292519943295769;

// assert

#define xassert(p) if(!(p)) {\
	LogSystem::getInstance()->Log(LogType::Error, "unexpected error in %s (%s, line %d)",\
	__FUNCTION__, __FILE__, __LINE__);\
	CCASSERT(p, "unexpected error"); }
#define xassert_ptr(p) if((p) == nullptr) {\
	LogSystem::getInstance()->Log(LogType::Error, "unexpected nullptr in %s (%s, line %d)",\
	__FUNCTION__, __FILE__, __LINE__);\
	CCASSERT(p, "unexpected nullptr"); }

namespace lstg
{
	class AppFrame;
}
