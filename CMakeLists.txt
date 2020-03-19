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
cmake_minimum_required(VERSION 3.6)

set(APP_NAME LuaSTG-x)

project(${APP_NAME})

if(XCODE)
    if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 8.0)
    endif()
endif()

set(RUNTIME_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/runtime-src)
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/cocos2d-x)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
set(BUILD_LUA_LIBS ON)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

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
include(src.cmake)

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
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/scripting/lua-bindings/proj.android ${ENGINE_BINARY_PATH}/cocos/lua-android)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive lua_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} luacocos2d)
target_include_directories(${APP_NAME} PRIVATE ${GAME_INCLUDE})

# mark app resources, resource will be copy auto after mark
setup_cocos_app_config(${APP_NAME})

include(modules.cmake)

if(MSVC)
    target_compile_options(${APP_NAME} PUBLIC /Z7)
    set_property(TARGET ${APP_NAME} APPEND_STRING PROPERTY LINK_FLAGS " /SAFESEH:NO")
endif()

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
        set_xcode_property(${APP_NAME} INFOPLIST_FILE "${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Info.plist")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "")
        set_xcode_property(${APP_NAME} CODE_SIGN_IDENTITY "iPhone Developer")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
elseif(ANDROID)
    set(depend_libs)
    set(all_depend_libs)
    search_depend_libs_recursive(cocos2dlua depend_libs)
    foreach(depend_lib ${depend_libs})
        if(TARGET ${depend_lib})
            get_target_property(target_type ${depend_lib} TYPE)
            if(${target_type} STREQUAL "SHARED_LIBRARY")
                get_target_property(tmp_loc ${depend_lib} IMPORTED_LOCATION)
                if(tmp_loc)
                    list(APPEND all_depend_libs ${tmp_loc})
                endif()
            endif()
        endif()
    endforeach()
    if(all_depend_libs)
        list(REMOVE_DUPLICATES all_depend_libs)
    endif()
    foreach(dll_file ${all_depend_libs})
        file(COPY ${dll_file} DESTINATION ${RUNTIME_SRC_ROOT}/proj.android/app/libs/${ANDROID_ABI})
    endforeach()
endif()
# copy resource on linux or WINDOWS
if(LINUX OR WINDOWS)
    cocos_get_resource_path(APP_RES_DIR ${APP_NAME})
    cocos_copy_target_res(${APP_NAME} LINK_TO ${APP_RES_DIR}/res FOLDERS ${res_res_folders})
    cocos_copy_lua_scripts(${APP_NAME} ${res_src_folders} ${APP_RES_DIR}/src )
endif()
