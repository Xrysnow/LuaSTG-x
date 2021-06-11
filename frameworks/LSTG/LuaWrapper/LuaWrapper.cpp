#include "LuaWrapper.h"
#include "AppFrame.h"
#include "Util/UtilLua.h"
#include "LogSystem.h"
#include "lstrlib.h"
#include "lutf8lib.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

RenderMode* lstg::TranslateRenderMode(lua_State* L, int argnum)
{
	RenderMode* ret;
	if (!lua::luaval_to_RenderMode(L, argnum, &ret))
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

static int str_pack(lua_State* L)
{
	const char* fmt = luaL_checkstring(L, 1);
	luaL_Buffer_53 b;
	lua53_str_pack(L, fmt, 2, &b);
	lua53_pushresult(&b);
	return 1;
}
static int str_unpack(lua_State* L)
{
	const char *fmt = luaL_checkstring(L, 1);
	size_t datasize = 0;
	const char* data = luaL_checklstring(L, 2, &datasize);
	return lua53_str_unpack(L, fmt, data, datasize, 2, 3);
}

LUA_REGISTER_MODULE_DEF(lstg_misc)
{
	const auto top = lua_gettop(L);

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
	// number value from cdata
	ffi_func["ffi.cast_uint64"] = R"__(
local ffi = require('ffi')
local store = ffi.new('uint64_t[1]')
local ptr = ffi.cast('uint64_t*', store)
return function(value)
	store[0] = value
    return ptr
end
)__";
	ffi_func["ffi.cast_int64"] = R"__(
local ffi = require('ffi')
local store = ffi.new('int64_t[1]')
local ptr = ffi.cast('int64_t*', store)
return function(value)
	store[0] = value
    return ptr
end
)__";

	for(auto& it : ffi_func)
	{
		if (!luaL_dostring(L, it.second.c_str()))
			lua_setfield(L, LUA_REGISTRYINDEX, it.first.c_str());
		else
		{
			XERROR("error when loading function '%s'", it.first.c_str());
		}
	}
	lua_settop(L, top);

	lua_getglobal(L, "string");
	if (lua_istable(L, -1))
	{
		tolua_function(L, "pack", str_pack);
		tolua_function(L, "unpack", str_unpack);
		tolua_function(L, "packsize", lua53_str_packsize);		
	}
	lua_settop(L, top);

	luaopen_luautf8(L);
	lua_setglobal(L, "utf8");
	lua_settop(L, top);
	return 0;
}

#if defined(CC_PLATFORM_PC)
#include "glfw3.h"
LUA_REGISTER_MODULE_DEF(lstg_glfw)
{
	tolua_open(L);
	tolua_module(L, "lstg", 0);
	tolua_beginmodule(L, "lstg");
	tolua_module(L, "glfw", 0);
	tolua_beginmodule(L, "glfw");

#define SET(F) lua_pushlightuserdata(L, (void*)(F)); lua_setfield(L, -2, #F);
	SET(glfwInit);
	SET(glfwTerminate);
	SET(glfwInitHint);
	SET(glfwGetVersion);
	SET(glfwGetVersionString);
	SET(glfwGetError);
	SET(glfwSetErrorCallback);
	SET(glfwGetMonitors);
	SET(glfwGetPrimaryMonitor);
	SET(glfwGetMonitorPos);
	SET(glfwGetMonitorWorkarea);
	SET(glfwGetMonitorPhysicalSize);
	SET(glfwGetMonitorContentScale);
	SET(glfwGetMonitorName);
	SET(glfwSetMonitorUserPointer);
	SET(glfwGetMonitorUserPointer);
	SET(glfwSetMonitorCallback);
	SET(glfwGetVideoModes);
	SET(glfwGetVideoMode);
	SET(glfwSetGamma);
	SET(glfwGetGammaRamp);
	SET(glfwSetGammaRamp);
	SET(glfwDefaultWindowHints);
	SET(glfwWindowHint);
	SET(glfwWindowHintString);
	SET(glfwCreateWindow);
	SET(glfwDestroyWindow);
	SET(glfwWindowShouldClose);
	SET(glfwSetWindowShouldClose);
	SET(glfwSetWindowTitle);
	SET(glfwSetWindowIcon);
	SET(glfwGetWindowPos);
	SET(glfwSetWindowPos);
	SET(glfwGetWindowSize);
	SET(glfwSetWindowSizeLimits);
	SET(glfwSetWindowAspectRatio);
	SET(glfwSetWindowSize);
	SET(glfwGetFramebufferSize);
	SET(glfwGetWindowFrameSize);
	SET(glfwGetWindowContentScale);
	SET(glfwGetWindowOpacity);
	SET(glfwSetWindowOpacity);
	SET(glfwIconifyWindow);
	SET(glfwRestoreWindow);
	SET(glfwMaximizeWindow);
	SET(glfwShowWindow);
	SET(glfwHideWindow);
	SET(glfwFocusWindow);
	SET(glfwRequestWindowAttention);
	SET(glfwGetWindowMonitor);
	SET(glfwSetWindowMonitor);
	SET(glfwGetWindowAttrib);
	SET(glfwSetWindowAttrib);
	SET(glfwSetWindowUserPointer);
	SET(glfwGetWindowUserPointer);
	SET(glfwSetWindowPosCallback);
	SET(glfwSetWindowSizeCallback);
	SET(glfwSetWindowCloseCallback);
	SET(glfwSetWindowRefreshCallback);
	SET(glfwSetWindowFocusCallback);
	SET(glfwSetWindowIconifyCallback);
	SET(glfwSetWindowMaximizeCallback);
	SET(glfwSetFramebufferSizeCallback);
	SET(glfwSetWindowContentScaleCallback);
	SET(glfwPollEvents);
	SET(glfwWaitEvents);
	SET(glfwWaitEventsTimeout);
	SET(glfwPostEmptyEvent);
	SET(glfwGetInputMode);
	SET(glfwSetInputMode);
	SET(glfwRawMouseMotionSupported);
	SET(glfwGetKeyName);
	SET(glfwGetKeyScancode);
	SET(glfwGetKey);
	SET(glfwGetMouseButton);
	SET(glfwGetCursorPos);
	SET(glfwSetCursorPos);
	SET(glfwCreateCursor);
	SET(glfwCreateStandardCursor);
	SET(glfwDestroyCursor);
	SET(glfwSetCursor);
	SET(glfwSetKeyCallback);
	SET(glfwSetCharCallback);
	SET(glfwSetCharModsCallback);
	SET(glfwSetMouseButtonCallback);
	SET(glfwSetCursorPosCallback);
	SET(glfwSetCursorEnterCallback);
	SET(glfwSetScrollCallback);
	SET(glfwSetDropCallback);
	SET(glfwJoystickPresent);
	SET(glfwGetJoystickAxes);
	SET(glfwGetJoystickButtons);
	SET(glfwGetJoystickHats);
	SET(glfwGetJoystickName);
	SET(glfwGetJoystickGUID);
	SET(glfwSetJoystickUserPointer);
	SET(glfwGetJoystickUserPointer);
	SET(glfwJoystickIsGamepad);
	SET(glfwSetJoystickCallback);
	SET(glfwUpdateGamepadMappings);
	SET(glfwGetGamepadName);
	SET(glfwGetGamepadState);
	SET(glfwSetClipboardString);
	SET(glfwGetClipboardString);
	SET(glfwGetTime);
	SET(glfwSetTime);
	SET(glfwGetTimerValue);
	SET(glfwGetTimerFrequency);
	SET(glfwMakeContextCurrent);
	SET(glfwGetCurrentContext);
	SET(glfwSwapBuffers);
	SET(glfwSwapInterval);
	SET(glfwExtensionSupported);
	SET(glfwGetProcAddress);
	SET(glfwVulkanSupported);
	SET(glfwGetRequiredInstanceExtensions);
#undef SET

	tolua_endmodule(L);
	tolua_endmodule(L);
	return 0;
}
#endif
