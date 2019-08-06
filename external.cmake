#

if(WINDOWS)
	set(FRAMEWORK_GLEW_PATH ${COCOS2DX_ROOT_PATH}/external/win32-specific/gles/include/OGLES)
	set(FRAMEWORK_DEFINITIOINS "-DCSM_TARGET_WIN_GL")
elseif(ANDROID)
	set(FRAMEWORK_DEFINITIOINS "-DCSM_TARGET_ANDROID_ES2")
elseif(MACOSX)
	set(FRAMEWORK_DEFINITIOINS "-DCSM_TARGET_MAC_GL")
elseif(IOS)
	set(FRAMEWORK_DEFINITIOINS "-DCSM_TARGET_IPHONE_ES2")
elseif(LINUX)
	#
endif()

set(EXTERNAL_LIBS "")

# Live2D

add_subdirectory(${RUNTIME_SRC_ROOT}/external/Cubism)
add_subdirectory(${RUNTIME_SRC_ROOT}/Classes/Live2D/Framework)
set(EXTERNAL_LIBS CubismFramework)
list(APPEND EXTERNAL_LIBS ${CSM_CORE_LIBS})

# reader

#add_subdirectory(${RUNTIME_SRC_ROOT}/Classes/reader)
#list(APPEND EXTERNAL_LIBS creator_reader)

# ffmpeg

add_subdirectory(${RUNTIME_SRC_ROOT}/external/ffmpeg)
list(APPEND EXTERNAL_LIBS ext_ffmpeg)
if(MACOSX OR IOS)
	include_directories(/System/Library/Frameworks)
	find_library(COREMEDIA_LIBRARY CoreMedia)
	find_library(SECURITY_LIBRARY Security)
	find_library(VIDEOTOOLBOX_LIBRARY VideoToolbox)
	list(APPEND EXTERNAL_LIBS ${COREMEDIA_LIBRARY})
	list(APPEND EXTERNAL_LIBS ${SECURITY_LIBRARY})
	list(APPEND EXTERNAL_LIBS ${VIDEOTOOLBOX_LIBRARY})

	list(APPEND EXTERNAL_LIBS bz2)
endif()

# nfd

if(WINDOWS OR LINUX OR MACOSX)
	add_subdirectory(${RUNTIME_SRC_ROOT}/external/NativeFileDialog)
	list(APPEND EXTERNAL_LIBS ext_nfd)
endif()

# ogg

if(WINDOWS)
	include_directories(${RUNTIME_SRC_ROOT}/external/OggDecoder/include)
else()
	add_subdirectory(${RUNTIME_SRC_ROOT}/external/OggDecoder)
	list(APPEND EXTERNAL_LIBS ext_ogg)
endif()

# OpenalSoft

if(WINDOWS)
	include_directories(${RUNTIME_SRC_ROOT}/external/OpenalSoft/include)
elseif(ANDROID OR LINUX)
	add_subdirectory(${RUNTIME_SRC_ROOT}/external/OpenalSoft)
	list(APPEND EXTERNAL_LIBS ext_al)
endif()

# imgui

add_subdirectory(${RUNTIME_SRC_ROOT}/Classes/imgui)
list(APPEND EXTERNAL_LIBS cc_imgui)

# lua

add_subdirectory(${RUNTIME_SRC_ROOT}/external/LuaExtensions/lfs)
list(APPEND EXTERNAL_LIBS ext_lfs)
add_subdirectory(${RUNTIME_SRC_ROOT}/external/LuaExtensions/lpeg)
list(APPEND EXTERNAL_LIBS ext_lpeg)
add_subdirectory(${RUNTIME_SRC_ROOT}/external/LuaExtensions/lua53)
list(APPEND EXTERNAL_LIBS ext_lua53)

#
if(WINDOWS)
	list(APPEND EXTERNAL_LIBS imm32.lib)
endif()

target_link_libraries(${APP_NAME} ${EXTERNAL_LIBS})
