# Configure cocos and its extensions before collecting application sources.

set(CC_USE_ANGLE "${LSTGX_USE_ANGLE}")
set(USE_JOB_SYSTEM_TASKFLOW ON)
set(USE_JOB_SYSTEM_TBB OFF)

# Override only this configure's effective value; keep the user's engine option
# in the cache so removing the disable override restores their preference.
if(LSTGX_NO_FAIRY_GUI)
    set(CC_ENABLE_EXT_FAIRYGUI OFF)
endif()

set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
if(MACOSX)
    if(LSTGX_USE_ANGLE)
        message(FATAL_ERROR "macOS requires LSTGX_USE_ANGLE=OFF (GFX Metal).")
    endif()
endif()
# Apply Xcode defaults after IOS/MACOSX detection and before creating targets.
# Preserve deployment versions supplied through CMake or Xcode attributes.
if(XCODE AND "${CMAKE_OSX_DEPLOYMENT_TARGET}" STREQUAL "")
    if(IOS AND NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 17.0)
    elseif(MACOSX AND NOT DEFINED CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET)
        set(CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET 12.0)
    endif()
endif()
if(APPLE)
    enable_language(OBJC OBJCXX)
    # Keep Objective-C and Objective-C++ aligned with the C/C++ settings.
    set(CMAKE_OBJC_STANDARD ${CMAKE_C_STANDARD})
    set(CMAKE_OBJC_STANDARD_REQUIRED ${CMAKE_C_STANDARD_REQUIRED})
    set(CMAKE_OBJCXX_STANDARD ${CMAKE_CXX_STANDARD})
    set(CMAKE_OBJCXX_STANDARD_REQUIRED ${CMAKE_CXX_STANDARD_REQUIRED})
    set(CMAKE_OBJCXX_EXTENSIONS ${CMAKE_CXX_EXTENSIONS})
endif()
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
if(APPLE AND TARGET ext_gfx)
    # The Metal backend needs cocos math headers when compiling ext_gfx.
    target_include_directories(ext_gfx PRIVATE "${COCOS2DX_ROOT_PATH}/cocos")
    if(MACOSX)
        target_link_libraries(ext_gfx PUBLIC "-framework MetalPerformanceShaders")
    elseif(IOS)
        # The Metal driver also uses MPS filters and CoreVideo's CVMetalTextureCache
        # (external texture import) on iOS.
        target_link_libraries(ext_gfx PUBLIC
            "-framework MetalPerformanceShaders" "-framework CoreVideo")
    endif()
endif()
if(MACOSX AND TARGET libcurl)
    # The bundled static curl uses SCDynamicStoreCopyProxies.
    set_property(TARGET libcurl APPEND PROPERTY INTERFACE_LINK_LIBRARIES
        "-framework SystemConfiguration")
endif()
list(REMOVE_ITEM CC_EXTENSION_LIBS "")
list(REMOVE_DUPLICATES CC_EXTENSION_LIBS)
set(CC_EXTENSION_LIBS "${CC_EXTENSION_LIBS}" CACHE INTERNAL "extensions for auto link to target application" FORCE)

if(MSVC AND TARGET fairygui)
    # Avoid exhausting PDB streams with repeated covariant-return debug sources.
    # /Z7 keeps full debug symbols in the objects instead of a compiler PDB.
    target_compile_options(fairygui PRIVATE "$<$<CONFIG:Debug>:/Z7>")
endif()
