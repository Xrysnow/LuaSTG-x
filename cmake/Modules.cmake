# Application module dependencies and module-specific deployment.

set(EXTERNAL_LIBS "")
set(LSTGX_MOD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks)
set(LSTGX_EXT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/external)

# Embed the FFmpeg framework linked by cocos2d.
if(APPLE AND CC_ENABLE_VIDEO_TEXTURE)
	if(XCODE)
		# Xcode selects the slice and embeds/signs its dynamic framework.
		set_property(TARGET ${APP_NAME} APPEND PROPERTY XCODE_EMBED_FRAMEWORKS "${FFMPEG_LIBRARY}")
		set_target_properties(${APP_NAME} PROPERTIES
			XCODE_EMBED_FRAMEWORKS_CODE_SIGN_ON_COPY ON
			XCODE_EMBED_FRAMEWORKS_REMOVE_HEADERS_ON_COPY ON
		)
	else()
		# LOCATION on an imported XCFramework resolves to the selected framework.
		get_target_property(FFMPEG_SELECTED_FRAMEWORK ext_ffmpeg LOCATION)
		# Preserve the versioned macOS framework's symlinks when copying.
		add_custom_command(TARGET ${APP_NAME} POST_BUILD
			COMMAND /usr/bin/ditto
				"${FFMPEG_SELECTED_FRAMEWORK}"
				"$<TARGET_BUNDLE_CONTENT_DIR:${APP_NAME}>/Frameworks/FFmpeg.framework"
			VERBATIM
		)
	endif()
	# set rpath
	if(MACOSX)
		target_link_options(${APP_NAME} PRIVATE -Wl,-rpath,@loader_path/../Frameworks)
	endif()
endif()

# imgui

add_subdirectory(${LSTGX_MOD_ROOT}/imgui)
target_link_libraries(cc_imgui PUBLIC cocos2d)
list(APPEND EXTERNAL_LIBS cc_imgui)

# Live2D

if(NOT LSTGX_NO_LIVE2D)
	if(WINDOWS)
		# Match the application's DLL CRT (/MDd in Debug).
		set(CORE_CRL_MD ON)
	endif()
	add_subdirectory(${LSTGX_MOD_ROOT}/Live2D)
	target_link_libraries(cc_live2d PUBLIC cocos2d)
	list(APPEND EXTERNAL_LIBS cc_live2d)
else()
	target_compile_definitions(${APP_NAME} PUBLIC LSTGX_NO_LIVE2D)
endif()

# math

add_subdirectory(${LSTGX_MOD_ROOT}/Math)
list(APPEND EXTERNAL_LIBS x_math)

# BurstLinker

add_subdirectory(${LSTGX_EXT_ROOT}/BurstLinker)
list(APPEND EXTERNAL_LIBS ext_BurstLinker)

# MicroTeX

add_subdirectory(${LSTGX_EXT_ROOT}/MicroTeX)
list(APPEND EXTERNAL_LIBS ext_MicroTeX)

# Keep standalone third-party modules on their existing language defaults.
block(SCOPE_FOR VARIABLES PROPAGATE EXTERNAL_LIBS)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_OBJCXX_STANDARD 17)

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

	# Yuescript

	if(NOT LSTGX_NO_YUESCRIPT)
		add_subdirectory(${LSTGX_EXT_ROOT}/Yuescript)
		list(APPEND EXTERNAL_LIBS ext_Yuescript)
	else()
		target_compile_definitions(${APP_NAME} PUBLIC LSTGX_NO_YUESCRIPT)
	endif()
endblock()

list(APPEND EXTERNAL_LIBS ${COCOS_EXTENSION_LIBS})

# windows

if(WINDOWS)
	list(APPEND EXTERNAL_LIBS imm32.lib)
endif()

target_link_libraries(${APP_NAME} ${EXTERNAL_LIBS})
