set(LIB_NAME x_math)

set(INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${COCOS2DX_ROOT_PATH}/cocos
    ${COCOS2DX_ROOT_PATH}/cocos/base
    ${COCOS2DX_ROOT_PATH}/cocos/platform
    ${COCOS2DX_ROOT_PATH}/extensions
    ${COCOS2DX_ROOT_PATH}/external
    ${COCOS2DX_ROOT_PATH}/external/glfw3/include/win32
    ${COCOS2DX_ROOT_PATH}/external/glfw/include/GLFW
    ${COCOS2DX_ROOT_PATH}/external/win32-specific/gles/include/OGLES
)
if(BUILD_LUA_LIBS)
    list(APPEND INCLUDES
        ${COCOS2DX_ROOT_PATH}/external/lua/tolua)
endif()
foreach(dir ${INCLUDES})
    if(EXISTS ${dir})
        include_directories(${dir})
    endif()
endforeach()

set(HEADER
    meow_fft.h
    XCollision.h
    XComplex.h
    XConstant.h
    XDistance.h
    XEquation.h
    XFFT.h
    XMathInternal.h
    XIntersect.h
    XMath.h
    XRandom.h
    XSpline.h
    XTween.h
)

set(SOURCE
    meow_fft.c
    XCollision.cpp
    XComplex.cpp
    XDistance.cpp
    XEquation.cpp
    XFFT.cpp
    XIntersect.cpp
    XRandom.cpp
    XSpline.cpp
    XTween.cpp
)

add_library(${LIB_NAME} STATIC ${SOURCE} ${HEADER})
add_dependencies(${LIB_NAME} cocos2d)
use_cocos2dx_compile_define(${LIB_NAME})
use_cocos2dx_compile_options(${LIB_NAME})

if(BUILD_LUA_LIBS)
    target_compile_definitions(${LIB_NAME} PUBLIC _USRLUASTATIC)
    target_link_libraries(${LIB_NAME} PUBLIC luajit)
endif()

set_target_properties(${LIB_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIB_NAME})
endif()
