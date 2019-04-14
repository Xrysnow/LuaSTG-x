#include "LuaWrapper.h"
#include "AppFrame.h"
#include "LWColor.h"
#include "LWRandomizer.h"
#include "LWBuiltInFunction.h"
#include "LuaWrapperEx.h"
#include "LWProfiler.h"
#include "UtilLua.h"


using namespace std;
using namespace lstg;
using namespace cocos2d;

BlendMode* lstg::TranslateBlendMode(lua_State* L, int argnum)
{
	BlendMode* ret;
	if (!lua::luaval_to_BlendMode(L, argnum, &ret))
	{
		luaL_error(L, "invalid blend mode");
		return nullptr;
	}
	return ret;
}

void lstg::TranslateAlignMode(lua_State* L, int argnum, TextHAlignment& halign, TextVAlignment& valign)
{
	const int e = luaL_checkinteger(L, argnum);
	switch (e & 0x03)  // HGETEXT_HORZMASK
	{
	case 0:  // HGETEXT_LEFT
		halign = TextHAlignment::LEFT;
		break;
	case 1:  // HGETEXT_CENTER
		halign = TextHAlignment::CENTER;
		break;
	case 2:  // HGETEXT_RIGHT
		halign = TextHAlignment::RIGHT;
		break;
	default:
		luaL_error(L, "invalid align mode.");
		return;
	}
	switch (e & 0x0C)  // HGETEXT_VERTMASK
	{
	case 0:  // HGETEXT_TOP
		valign = TextVAlignment::TOP;
		break;
	case 4:  // HGETEXT_MIDDLE
		valign = TextVAlignment::CENTER;
		break;
	case 8:  // HGETEXT_BOTTOM
		valign = TextVAlignment::BOTTOM;
		break;
	default:
		luaL_error(L, "invalid align mode.");
		return;
	}
}

void lstg::RegistWrapper(lua_State* L)
{
	ColorWrapper::Register(L);
	RandomizerWrapper::Register(L);
	BuiltInFunctionWrapper::Register(L);

	EXWrapper::Register(L);

	ProfilerWrapper::Register(L);

	vector<string> cdef = {
		"require('ffi').cdef[[void* memcpy(void *p1, void *p2, size_t n);]]",
		"require('ffi').cdef[[void* malloc(size_t n);]]",
		"require('ffi').cdef[[void free(void* p);]]"
	};
	cdef.emplace_back(R"__(
local ffi = require('ffi')
ffi.cdef[[ typedef struct { float x; float y; float z; } cc_Vec3; ]]
ffi.cdef[[ typedef struct {
	uint8_t r; uint8_t g; uint8_t b; uint8_t a;
} cc_Color4B; ]]
ffi.cdef[[ typedef struct { float u; float v; } cc_Tex2F; ]]
ffi.cdef[[ typedef struct {
	cc_Vec3 vertices;
	cc_Color4B colors;
	cc_Tex2F texCoords;
} cc_V3F_C4B_T2F; ]]
ffi.cdef[[ typedef struct {
	cc_V3F_C4B_T2F tl;
	cc_V3F_C4B_T2F bl;
	cc_V3F_C4B_T2F tr;
	cc_V3F_C4B_T2F br;
} cc_V3F_C4B_T2F_Quad; ]]
)__");
	for (auto& def : cdef)
	{
		luaL_dostring(L, def.c_str());
	}

	unordered_map<string, string> ffi_func;
	// used when get C pointer from lua
	ffi_func["ffi.convert_ptr"] = R"__(
local ffi = require('ffi')
local C = ffi.C
local _ptr_size = ffi.sizeof('void*')
local _pptr_t = ffi.typeof('void*[1]')
return function(cdata_ptr, userdata)
    C.memcpy(userdata, _pptr_t(cdata_ptr), _ptr_size)
end
)__";
	// used when push C pointer to lua
	ffi_func["ffi.cast_ptr"] = R"__(
local ffi = require('ffi')
local cast = ffi.cast
local typeof = ffi.typeof
return function(userdata, type_str)
    return cast(typeof(type_str), userdata)
end
)__";
	ffi_func["ffi.cast_ptr_vert"] = R"__(
local ffi = require('ffi')
local cast = ffi.cast
local ty = ffi.typeof('cc_V3F_C4B_T2F*')
return function(userdata)
    return cast(ty, userdata)
end
)__";

	ffi_func["ffi.ptr_to_arr"] = R"__(
local ffi = require('ffi')
local cast = ffi.cast
local _arr_t = ffi.typeof('double*')
return function(userdata_or_cdata)
    return cast(_arr_t, userdata_or_cdata)
end
)__";
	ffi_func["ffi.alloc_raw"] = R"__(
local ffi = require('ffi')
local C = ffi.C
local gc = ffi.gc
return function(size)
    local ptr = C.malloc(size)
    gc(ptr, C.free)
    return ptr
end
)__";
	ffi_func["ffi.alloc_arr"] = R"__(
local ffi = require('ffi')
local C = ffi.C
local gc = ffi.gc
local cast = ffi.cast
local _size = ffi.sizeof('double')
local _arr_t = ffi.typeof('double*')
return function(size)
    local ptr = C.malloc(size*_size)
    gc(ptr, C.free)
    return cast(_arr_t, ptr)
end
)__";
	for(auto& it : ffi_func)
	{
		if (luaL_dostring(L, it.second.c_str()) == 0)
			lua_setfield(L, LUA_REGISTRYINDEX, it.first.c_str());
		else
		{
			XERROR("error when loading function '%s'", it.first.c_str());
		}
	}
	lua_settop(L, 0);
}
