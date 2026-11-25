#pragma once
#include "platform/SystemInfo.h"
#include "lua_conversion/lua_conversion_tolua.hpp"

namespace lua {
template<> struct value_type<cc::SystemInfoSubscription> : std::true_type {};
}
