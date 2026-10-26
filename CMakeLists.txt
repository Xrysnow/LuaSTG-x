#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/
cmake_minimum_required(VERSION 3.28)

set(APP_NAME LuaSTG-x)

project(${APP_NAME})

option(LSTGX_NO_LIVE2D    "No live2d module"     OFF)
option(LSTGX_NO_VIDEO     "No video module"      OFF)
option(LSTGX_NO_YUESCRIPT "No Yuescript module"   ON)
option(LSTGX_USE_ANGLE    "Use angle on windows" OFF)
option(LSTGX_USE_GFX      "Use GFX beckend"       ON)

message("LSTGX_NO_LIVE2D: ${LSTGX_NO_LIVE2D}")
message("LSTGX_NO_VIDEO: ${LSTGX_NO_VIDEO}")
message("LSTGX_NO_YUESCRIPT: ${LSTGX_NO_YUESCRIPT}")
message("LSTGX_USE_ANGLE: ${LSTGX_USE_ANGLE}")
message("LSTGX_USE_GFX: ${LSTGX_USE_GFX}")

set(CC_USE_ANGLE "${LSTGX_USE_ANGLE}")
set(CC_USE_GFX "${LSTGX_USE_GFX}")
set(USE_JOB_SYSTEM_TASKFLOW ON)
set(USE_JOB_SYSTEM_TBB OFF)

set(RUNTIME_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/runtime-src)
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/cocos2d-x)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
# Apply Xcode defaults after IOS/MACOSX detection and before creating targets.
# Preserve deployment versions supplied through CMake or Xcode attributes.
if(XCODE AND "${CMAKE_OSX_DEPLOYMENT_TARGET}" STREQUAL "")
    if(IOS AND NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 13.0)
    elseif(MACOSX AND NOT DEFINED CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET)
        set(CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET 10.15)
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
list(REMOVE_ITEM CC_EXTENSION_LIBS "")
list(REMOVE_DUPLICATES CC_EXTENSION_LIBS)
set(CC_EXTENSION_LIBS "${CC_EXTENSION_LIBS}" CACHE INTERNAL "extensions for auto link to target application" FORCE)

# script and source files info, not need to compile
set(res_res_folders
    "${CMAKE_CURRENT_SOURCE_DIR}/res"
)
set(res_src_folders
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
if(APPLE OR VS)
    cocos_mark_multi_resources(res_res RES_TO "Resources/res" FOLDERS ${res_res_folders})
    cocos_mark_multi_resources(res_src RES_TO "Resources/src" FOLDERS ${res_src_folders})
    set(cc_common_res ${res_res} ${res_src} ${res_script})
endif()

# sources
include(CMakeSources.cmake)

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME cocos2dlua)
endif()

set(APP_SRC ${GAME_HEADER} ${GAME_SOURCE})

# mark app complie info and libs info
if(NOT ANDROID)
    add_executable(${APP_NAME} ${APP_SRC})
else()
    add_library(${APP_NAME} SHARED ${APP_SRC})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(cpp_android_spec cocos2d)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/extensions/scripting/lua-bindings/proj.android ${ENGINE_BINARY_PATH}/cocos/lua-android)
    target_link_libraries(lua_android_spec luacocos2d)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive lua_android_spec -Wl,--no-whole-archive)

    config_android_shared_libs("org.lstgx.lib" "${CMAKE_CURRENT_SOURCE_DIR}/frameworks/runtime-src/proj.android/app/src")
endif()

target_link_libraries(${APP_NAME} luacocos2d)
target_include_directories(${APP_NAME} PRIVATE ${GAME_INCLUDE})

# mark app resources, resource will be copy auto after mark
setup_cocos_app_config(${APP_NAME})

if(CC_USE_GFX)
	target_compile_definitions(${APP_NAME} PUBLIC CC_USE_GFX)
endif()

if(CC_EXTENSION_LIBS)
    target_link_libraries(${APP_NAME} ${CC_EXTENSION_LIBS})
endif()

include(CMakeModules.cmake)

if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
            MACOSX_BUNDLE_INFO_PLIST "${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Info.plist"
        )
        set_target_properties(${APP_NAME} PROPERTIES
            LINK_FLAGS "-pagezero_size 10000 -image_base 100000000"
        )
    elseif(IOS)
        set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Info.plist")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "")
        set_xcode_property(${APP_NAME} CODE_SIGN_IDENTITY "iPhone Developer")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
    if(MSVC)
        target_compile_options(${APP_NAME} PUBLIC /Z7)
        target_compile_options(${APP_NAME} PUBLIC /wd4244) # disable warning 4244
        set_property(TARGET ${APP_NAME} APPEND_STRING PROPERTY LINK_FLAGS " /SAFESEH:NO")
    endif()
    if(WIN64)
        set(PVR_ROOT ${COCOS2DX_ROOT_PATH}/external/PVRVFrame/prebuilt/win64)
    else()
        set(PVR_ROOT ${COCOS2DX_ROOT_PATH}/external/PVRVFrame/prebuilt/win32)
    endif()
    function(copy_custom_file target file)
        get_filename_component(file_name ${file} NAME)
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${file} "$<TARGET_FILE_DIR:${APP_NAME}>/${file_name}"
        )
    endfunction()
    copy_custom_file(${APP_NAME} ${PVR_ROOT}/libEGL.dll)
    copy_custom_file(${APP_NAME} ${PVR_ROOT}/libGLES_CM.dll)
    copy_custom_file(${APP_NAME} ${PVR_ROOT}/libGLESv2.dll)
elseif(LINUX)
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/LinuxRuntime.cmake")
    lstgx_deploy_linux_runtime(${APP_NAME}
        RESOURCE_DIRS "${res_res_folders}" "${res_src_folders}")
endif()
# copy resource on linux next to the executable, matching FileUtilsLinux's root
if(LINUX)
    # Use the output directory set by setup_cocos_app_config. TARGET_FILE_DIR
    # would create a dependency cycle with SYNC_RESOURCE under CMP0112 OLD.
    get_target_property(APP_RES_DIR ${APP_NAME} RUNTIME_OUTPUT_DIRECTORY)
    if(CMAKE_CONFIGURATION_TYPES)
        string(APPEND APP_RES_DIR "/$<CONFIG>")
    endif()
    add_custom_command(TARGET SYNC_RESOURCE-${APP_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${res_res_folders}" "${APP_RES_DIR}/res"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${res_src_folders}" "${APP_RES_DIR}/src"
        VERBATIM
    )
endif()
