# Configure cocos and its extensions before collecting application sources.

set(USE_JOB_SYSTEM_TASKFLOW ON)
set(USE_JOB_SYSTEM_TBB OFF)

# Override only this configure's effective value; keep the user's engine option
# in the cache so removing the disable override restores their preference.
if(LSTGX_NO_FAIRY_GUI)
    set(CC_ENABLE_EXT_FAIRYGUI OFF)
endif()

set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
set(BUILD_LUA_LIBS ON)
# Rebuild the auto-link list for this configure; disabled extensions must not persist.
unset(CC_EXTENSION_LIBS)
set(CC_EXTENSION_LIBS "" CACHE INTERNAL "extensions for auto link to target application" FORCE)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
if(APPLE AND XCODE AND TARGET OpenAL)
    # Pin the framework product to CMake's computed link path (lib/$(CONFIG)).
    # OpenAL's own "$(inherited)" CONFIGURATION_BUILD_DIR defers to Xcode's
    # default, which appends the effective-platform suffix (Debug-iphoneos) on
    # iOS while CMake's link path stays lib/$(CONFIG)/soft_oal.framework.
    set_property(TARGET OpenAL PROPERTY
        XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_BINARY_DIR}/lib/$(CONFIGURATION)")
endif()
list(REMOVE_ITEM CC_EXTENSION_LIBS "")
list(REMOVE_DUPLICATES CC_EXTENSION_LIBS)
set(CC_EXTENSION_LIBS "${CC_EXTENSION_LIBS}" CACHE INTERNAL "extensions for auto link to target application" FORCE)

if(MSVC AND TARGET fairygui)
    # Avoid exhausting PDB streams with repeated covariant-return debug sources.
    # /Z7 keeps full debug symbols in the objects instead of a compiler PDB.
    target_compile_options(fairygui PRIVATE "$<$<CONFIG:Debug>:/Z7>")
endif()
