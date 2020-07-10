#include "base/ccConfig.h"
#ifndef __x_LogSystem_h__
#define __x_LogSystem_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_x_LogSystem(lua_State* tolua_S);

#endif // __x_LogSystem_h__
