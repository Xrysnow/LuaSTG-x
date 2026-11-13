# Configure application packaging and runtime deployment after linking modules.

if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
            MACOSX_BUNDLE_INFO_PLIST "${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Info.plist"
        )
        # The legacy Intel LuaJIT layout produces an invalid low-address arm64
        # executable. Keep the platform's normal image/pagezero layout on arm64.
        if(CMAKE_OSX_ARCHITECTURES STREQUAL "x86_64"
           OR (NOT CMAKE_OSX_ARCHITECTURES AND CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64"))
            set_target_properties(${APP_NAME} PROPERTIES
                LINK_FLAGS "-pagezero_size 10000 -image_base 100000000"
            )
        endif()
    elseif(IOS)
        if(NOT MACOSX_BUNDLE_GUI_IDENTIFIER)
            set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.xrysnow.lstgx")
        endif()
        set_target_properties(${APP_NAME} PROPERTIES
            MACOSX_BUNDLE_INFO_PLIST "${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Info.plist"
            MACOSX_BUNDLE_GUI_IDENTIFIER "${MACOSX_BUNDLE_GUI_IDENTIFIER}"
            XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "${MACOSX_BUNDLE_GUI_IDENTIFIER}"
        )
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        # Keep the user's CMAKE_XCODE_ATTRIBUTE_* signing settings. Xcode's
        # defaults also allow unsigned compile/link checks without a team.
        target_link_options(${APP_NAME} PRIVATE -Wl,-rpath,@executable_path/Frameworks)
        get_target_property(LSTGX_OPENAL_FRAMEWORK OpenAL FRAMEWORK)
        if(LSTGX_OPENAL_FRAMEWORK)
            if(XCODE)
                set_property(TARGET ${APP_NAME} APPEND PROPERTY XCODE_EMBED_FRAMEWORKS OpenAL)
                set_target_properties(${APP_NAME} PROPERTIES
                    XCODE_EMBED_FRAMEWORKS_CODE_SIGN_ON_COPY ON
                    XCODE_EMBED_FRAMEWORKS_REMOVE_HEADERS_ON_COPY ON
                )
            else()
                add_custom_command(TARGET ${APP_NAME} POST_BUILD
                    COMMAND /usr/bin/ditto "$<TARGET_BUNDLE_DIR:OpenAL>"
                        "$<TARGET_BUNDLE_CONTENT_DIR:${APP_NAME}>/Frameworks/soft_oal.framework"
                    VERBATIM
                )
            endif()
        endif()
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
    include("${CMAKE_CURRENT_LIST_DIR}/LinuxRuntime.cmake")
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
