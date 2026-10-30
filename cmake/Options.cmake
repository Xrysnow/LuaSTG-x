# Application options and Lua binding diagnostics.

option(LSTGX_NO_LIVE2D    "No live2d module"     OFF)
option(LSTGX_NO_VIDEO     "No video module"      OFF)
option(LSTGX_NO_YUESCRIPT "No Yuescript module"   ON)
option(LSTGX_NO_FAIRY_GUI "No FairyGUI module"   OFF)
option(LSTGX_USE_ANGLE    "Use angle on windows" OFF)

# Keep the internal compatibility flag until all renderer branches are migrated.
set(CC_USE_GFX ON)

# Preserve an explicitly selected policy when upgrading the local cache.
if(DEFINED LSTGX_LUA_BINDING_CHECKS)
    if(NOT DEFINED CC_LUA_BINDING_CHECKS)
        set(CC_LUA_BINDING_CHECKS "${LSTGX_LUA_BINDING_CHECKS}" CACHE STRING "Lua binding diagnostics: AUTO, ON or OFF")
    endif()
    unset(LSTGX_LUA_BINDING_CHECKS CACHE)
    unset(LSTGX_LUA_BINDING_CHECKS)
endif()

# AUTO follows cocos' CC_DEBUG > 0 in the binding header. Only explicit
# overrides are supplied to every target instantiating the templates.
set(CC_LUA_BINDING_CHECKS "AUTO" CACHE STRING "Lua binding diagnostics: AUTO, ON or OFF")
set_property(CACHE CC_LUA_BINDING_CHECKS PROPERTY STRINGS AUTO ON OFF)
string(TOUPPER "${CC_LUA_BINDING_CHECKS}" _cc_lua_binding_checks)
if(_cc_lua_binding_checks STREQUAL "ON")
    add_compile_definitions(CC_LUA_BINDING_CHECKS=1)
elseif(_cc_lua_binding_checks STREQUAL "OFF")
    add_compile_definitions(CC_LUA_BINDING_CHECKS=0)
elseif(NOT _cc_lua_binding_checks STREQUAL "AUTO")
    message(FATAL_ERROR "CC_LUA_BINDING_CHECKS must be AUTO, ON or OFF")
endif()
unset(_cc_lua_binding_checks)

message("LSTGX_NO_LIVE2D: ${LSTGX_NO_LIVE2D}")
message("LSTGX_NO_VIDEO: ${LSTGX_NO_VIDEO}")
message("LSTGX_NO_YUESCRIPT: ${LSTGX_NO_YUESCRIPT}")
message("LSTGX_NO_FAIRY_GUI: ${LSTGX_NO_FAIRY_GUI}")
message("LSTGX_USE_ANGLE: ${LSTGX_USE_ANGLE}")
