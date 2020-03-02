#

set(EXTERNAL_LIBS "")

# Live2D

add_subdirectory(${RUNTIME_SRC_ROOT}/Classes/Live2D)
set(EXTERNAL_LIBS cc_live2d)

# reader

add_subdirectory(${RUNTIME_SRC_ROOT}/Classes/reader)
list(APPEND EXTERNAL_LIBS creator_reader)

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
	list(APPEND EXTERNAL_LIBS ext_NativeFileDialog)
endif()

# ogg

if(WINDOWS)
	include_directories(${RUNTIME_SRC_ROOT}/external/OggDecoder/include)
elseif(ANDROID)
	add_subdirectory(${RUNTIME_SRC_ROOT}/external/OggDecoder)
	list(APPEND EXTERNAL_LIBS ext_ogg ext_ogg_vorbis ext_ogg_vorbisfile ext_ogg_vorbisenc)
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

# BurstLinker
add_subdirectory(${RUNTIME_SRC_ROOT}/external/BurstLinker)
list(APPEND EXTERNAL_LIBS ext_BurstLinker)

# cLaTeXMath
add_subdirectory(${RUNTIME_SRC_ROOT}/external/cLaTeXMath)
list(APPEND EXTERNAL_LIBS ext_cLaTeXMath)

#
if(WINDOWS)
	list(APPEND EXTERNAL_LIBS imm32.lib)
endif()

target_link_libraries(${APP_NAME} ${EXTERNAL_LIBS})
