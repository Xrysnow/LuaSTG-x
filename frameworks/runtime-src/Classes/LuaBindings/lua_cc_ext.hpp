#pragma once
#include "base/ccConfig.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_cc_ext(lua_State* tolua_S);

