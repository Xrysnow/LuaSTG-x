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

include(cmake/MSVCDebugInfo.cmake)
project(${APP_NAME})

include(cmake/Options.cmake)

set(RUNTIME_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/runtime-src)
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/cocos-x)

include(cmake/CocosSetup.cmake)
include(cmake/Sources.cmake)

if(ANDROID)
    # AndroidManifest.xml expects this shared library name.
    set(APP_NAME cocos2dlua)
endif()

set(APP_SRC ${GAME_HEADER} ${GAME_SOURCE})

# Create the application target and Android platform glue.
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

# Set application output, IDE grouping, and resource synchronization targets.
setup_cocos_app_config(${APP_NAME})

target_compile_definitions(${APP_NAME} PUBLIC CC_USE_GFX)

if(CC_EXTENSION_LIBS)
    target_link_libraries(${APP_NAME} ${CC_EXTENSION_LIBS})
endif()

include(cmake/Modules.cmake)
include(cmake/AppPlatform.cmake)
