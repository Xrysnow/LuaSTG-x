# Application options and Lua binding diagnostics.

option(LSTGX_NO_LIVE2D    "No live2d module"     OFF)
option(CC_ENABLE_VIDEO_TEXTURE "Build FFmpeg video textures" ON)
option(LSTGX_NO_YUESCRIPT "No Yuescript module"   ON)
option(LSTGX_NO_FAIRY_GUI "No FairyGUI module"   OFF)

# Discard retired ANGLE switches from existing build directories.
unset(LSTGX_USE_ANGLE CACHE)
unset(LSTGX_USE_ANGLE)
unset(CC_USE_ANGLE CACHE)
unset(CC_USE_ANGLE)

if(DEFINED LSTGX_NO_VIDEO)
    message(WARNING "LSTGX_NO_VIDEO is no longer used. Set CC_ENABLE_VIDEO_TEXTURE=ON or OFF.")
    unset(LSTGX_NO_VIDEO CACHE)
    unset(LSTGX_NO_VIDEO)
endif()

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

message("LSTGX_NO_LIVE2D: ${LSTGX_NO_LIVE2D}")
message("CC_ENABLE_VIDEO_TEXTURE: ${CC_ENABLE_VIDEO_TEXTURE}")
message("LSTGX_NO_YUESCRIPT: ${LSTGX_NO_YUESCRIPT}")
message("LSTGX_NO_FAIRY_GUI: ${LSTGX_NO_FAIRY_GUI}")
