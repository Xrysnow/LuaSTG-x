# Keep the build tree usable, and assemble a separate relocatable Linux bundle.
# Read the linked ELF dependency graph instead of approximating CMake link edges.
set(_LSTGX_LINUX_RUNTIME_SCRIPT "${CMAKE_CURRENT_LIST_DIR}/DeployLinuxRuntime.cmake")

function(lstgx_deploy_linux_runtime target)
    cmake_parse_arguments(runtime "" "" "RESOURCE_DIRS" ${ARGN})
    if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
        message(FATAL_ERROR "Linux runtime deployment requires a Linux target")
    endif()
    if(CMAKE_SKIP_RPATH OR CMAKE_SKIP_INSTALL_RPATH)
        message(FATAL_ERROR "Linux runtime deployment requires RPATH support")
    endif()
    if(NOT CMAKE_OBJDUMP)
        find_program(CMAKE_OBJDUMP NAMES objdump)
    endif()
    if(NOT CMAKE_OBJDUMP)
        message(FATAL_ERROR "Linux runtime deployment requires objdump")
    endif()

    # INSTALL_RPATH reserves enough space for RPATH_CHANGE on the bundle copy.
    # DT_RPATH also covers private dependencies of prebuilt shared libraries.
    # Their copied RPATH/RUNPATH is removed below; vendor binaries stay intact.
    set_target_properties(${target} PROPERTIES
        BUILD_RPATH_USE_ORIGIN TRUE
        BUILD_WITH_INSTALL_RPATH FALSE
        SKIP_BUILD_RPATH FALSE
        INSTALL_RPATH "$ORIGIN"
        INSTALL_RPATH_USE_LINK_PATH FALSE
    )
    target_link_options(${target} PRIVATE "LINKER:--disable-new-dtags")

    set(bundle "${CMAKE_BINARY_DIR}/deploy/${target}/$<CONFIG>")
    set(script "${CMAKE_CURRENT_BINARY_DIR}/deploy-${target}-$<CONFIG>.cmake")
    file(GENERATE OUTPUT "${script}" CONTENT
"set(LSTGX_RUNTIME_EXECUTABLE [==[$<TARGET_FILE:${target}>]==])
set(LSTGX_RUNTIME_DESTINATION [==[${bundle}]==])
set(LSTGX_RUNTIME_RESOURCES [==[${runtime_RESOURCE_DIRS}]==])
set(CMAKE_GET_RUNTIME_DEPENDENCIES_PLATFORM linux+elf)
set(CMAKE_GET_RUNTIME_DEPENDENCIES_TOOL objdump)
set(CMAKE_GET_RUNTIME_DEPENDENCIES_COMMAND [==[${CMAKE_OBJDUMP}]==])
include([==[${_LSTGX_LINUX_RUNTIME_SCRIPT}]==])
")
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -P "${script}"
        COMMENT "Deploying Linux runtime for ${target}"
        VERBATIM
    )
    # Also refresh when resources or a private prebuilt dependency change without
    # relinking the executable. This explicit target always runs the scan/copy.
    add_custom_target(deploy-${target}
        COMMAND "${CMAKE_COMMAND}" -P "${script}"
        DEPENDS ${target}
        COMMENT "Refreshing Linux runtime for ${target}"
        VERBATIM
    )
endfunction()
