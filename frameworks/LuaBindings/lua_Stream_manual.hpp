#pragma once
#include "io/Stream.h"

struct lua_State;

// Lua owns a Local Ref handle. The Atomic core never receives Lua metadata.
// Wrapping an external stream retains its cursor; close only detaches this handle.
int pushLuaStream(lua_State* L, cocos2d::io::StreamPtr stream);
int luaReg_Stream_manual(lua_State* L);
