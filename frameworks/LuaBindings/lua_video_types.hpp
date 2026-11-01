#pragma once
#include "lua_conversion/lua_conversion.hpp"
extern "C"
{
#include "libavutil/rational.h"
}

namespace lua
{
LUA_TO_LUA_STRUCT2(AVRational, num, den);
}
