#pragma once
#include "base/ccConfig.h"
#ifndef __x_Resource_h__
#define __x_Resource_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_x_Resource(lua_State* tolua_S);

#endif // __x_Resource_h__
