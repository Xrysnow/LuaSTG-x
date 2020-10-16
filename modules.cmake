#

set(EXTERNAL_LIBS "")
set(LSTGX_MOD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks)
set(LSTGX_EXT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/external)

# apple

# ffmpeg, video

set(CC_VIDEO_DEPEND_LIBS)
add_subdirectory(${LSTGX_EXT_ROOT}/ffmpeg)
list(APPEND CC_VIDEO_DEPEND_LIBS ext_ffmpeg)
if(APPLE)
	# dylib for mac, framework for ios
	target_link_libraries(${APP_NAME} ${FFMPEG_LIBRARY})
	# if(MACOSX)
		# copy to Frameworks, need to check sign option in Xcode project
		target_sources(${APP_NAME} PUBLIC ${FFMPEG_LIBRARY})
		set_source_files_properties(${FFMPEG_LIBRARY} PROPERTIES MACOSX_PACKAGE_LOCATION Frameworks HEADER_FILE_ONLY 1)
		# set rpath
		set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS "-Wl,-rpath,@loader_path/../Frameworks")
	# elseif(IOS)
		# set_target_properties(${APP_NAME} PROPERTIES XCODE_ATTRIBUTE_FRAMEWORK_SEARCH_PATHS ${FFMPEG_FRAMEWORK_PATH})
	# endif()
endif()

add_subdirectory(${LSTGX_MOD_ROOT}/Video)
list(APPEND EXTERNAL_LIBS cc_video)

# ogg, OpenalSoft, audio

set(CC_AUDIO_DEPEND_LIBS)

if(WINDOWS)
	include_directories(${LSTGX_EXT_ROOT}/OggDecoder/include)
elseif(ANDROID)
	add_subdirectory(${LSTGX_EXT_ROOT}/OggDecoder)
	list(APPEND CC_AUDIO_DEPEND_LIBS ext_ogg ext_ogg_vorbis ext_ogg_vorbisfile ext_ogg_vorbisenc)
else()
	add_subdirectory(${LSTGX_EXT_ROOT}/OggDecoder)
	list(APPEND CC_AUDIO_DEPEND_LIBS ext_ogg)
endif()

if(WINDOWS)
	include_directories(${LSTGX_EXT_ROOT}/OpenalSoft/include)
elseif(ANDROID OR LINUX)
	add_subdirectory(${LSTGX_EXT_ROOT}/OpenalSoft)
	list(APPEND CC_AUDIO_DEPEND_LIBS ext_al)
endif()

if(MACOSX OR IOS)
	list(APPEND CC_AUDIO_DEPEND_LIBS ${COREMEDIA_LIBRARY})
endif()

add_subdirectory(${LSTGX_MOD_ROOT}/Audio)
list(APPEND EXTERNAL_LIBS cc_audio)

# imgui

add_subdirectory(${LSTGX_MOD_ROOT}/imgui)
list(APPEND EXTERNAL_LIBS cc_imgui)

# Live2D

add_subdirectory(${LSTGX_MOD_ROOT}/Live2D)
list(APPEND EXTERNAL_LIBS cc_live2d)

# math

add_subdirectory(${LSTGX_MOD_ROOT}/Math)
list(APPEND EXTERNAL_LIBS x_math)

# reader

add_subdirectory(${LSTGX_MOD_ROOT}/reader)
list(APPEND EXTERNAL_LIBS creator_reader)

# BurstLinker

add_subdirectory(${LSTGX_EXT_ROOT}/BurstLinker)
list(APPEND EXTERNAL_LIBS ext_BurstLinker)

# cLaTeXMath

add_subdirectory(${LSTGX_EXT_ROOT}/cLaTeXMath)
list(APPEND EXTERNAL_LIBS ext_cLaTeXMath)

# lua

add_subdirectory(${LSTGX_EXT_ROOT}/LuaExtensions/cjson)
list(APPEND EXTERNAL_LIBS ext_cjson)
add_subdirectory(${LSTGX_EXT_ROOT}/LuaExtensions/lfs)
list(APPEND EXTERNAL_LIBS ext_lfs)
add_subdirectory(${LSTGX_EXT_ROOT}/LuaExtensions/lpeg)
list(APPEND EXTERNAL_LIBS ext_lpeg)
add_subdirectory(${LSTGX_EXT_ROOT}/LuaExtensions/lua53)
list(APPEND EXTERNAL_LIBS ext_lua53)

# libzippp

add_subdirectory(${LSTGX_EXT_ROOT}/libzippp)
list(APPEND EXTERNAL_LIBS ext_libzippp)

# nfd

if(WINDOWS OR LINUX OR MACOSX)
	add_subdirectory(${LSTGX_EXT_ROOT}/NativeFileDialog)
	list(APPEND EXTERNAL_LIBS ext_NativeFileDialog)
endif()

# windows

if(WINDOWS)
	list(APPEND EXTERNAL_LIBS imm32.lib)
endif()

target_link_libraries(${APP_NAME} ${EXTERNAL_LIBS})
