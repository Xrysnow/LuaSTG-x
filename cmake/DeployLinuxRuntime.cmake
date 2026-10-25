cmake_minimum_required(VERSION 3.16)

if(NOT EXISTS "${LSTGX_RUNTIME_EXECUTABLE}" OR NOT LSTGX_RUNTIME_DESTINATION)
    message(FATAL_ERROR "Linux deployment requires an executable and destination")
endif()
get_filename_component(source_dir "${LSTGX_RUNTIME_EXECUTABLE}" DIRECTORY)
get_filename_component(source_dir "${source_dir}" REALPATH)
get_filename_component(destination "${LSTGX_RUNTIME_DESTINATION}" REALPATH)
if(source_dir STREQUAL destination)
    message(FATAL_ERROR "Deploy to a separate directory, not the original build output")
endif()

function(read_dynamic file prefix)
    execute_process(COMMAND "${CMAKE_GET_RUNTIME_DEPENDENCIES_COMMAND}" -p "${file}"
        RESULT_VARIABLE result OUTPUT_VARIABLE dynamic ERROR_VARIABLE error)
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Cannot inspect ${file}: ${error}")
    endif()
    if(dynamic MATCHES "[\r\n][ \t]*NEEDED[ \t]+[^\r\n]*/")
        message(FATAL_ERROR "Non-relocatable DT_NEEDED path in ${file}; rebuild it with a SONAME")
    endif()
    set(rpath "")
    set(runpath "")
    if(dynamic MATCHES "[\r\n][ \t]*RPATH[ \t]+([^\r\n]*)")
        string(STRIP "${CMAKE_MATCH_1}" rpath)
    endif()
    if(dynamic MATCHES "[\r\n][ \t]*RUNPATH[ \t]+([^\r\n]*)")
        string(STRIP "${CMAKE_MATCH_1}" runpath)
    endif()
    set(${prefix}_rpath "${rpath}" PARENT_SCOPE)
    set(${prefix}_runpath "${runpath}" PARENT_SCOPE)
endfunction()

read_dynamic("${LSTGX_RUNTIME_EXECUTABLE}" executable)
if(executable_runpath OR NOT executable_rpath)
    message(FATAL_ERROR "Linux bundle requires executable DT_RPATH (not DT_RUNPATH)")
endif()

# Keep distribution-provided libraries on the destination system. Bundle linked
# libraries outside these system directories, including custom /usr/local libs.
# Missing dependencies and name conflicts are errors, never silently skipped.
file(GET_RUNTIME_DEPENDENCIES
    EXECUTABLES "${LSTGX_RUNTIME_EXECUTABLE}"
    RESOLVED_DEPENDENCIES_VAR dependencies
    UNRESOLVED_DEPENDENCIES_VAR missing
    CONFLICTING_DEPENDENCIES_PREFIX conflicts
    POST_EXCLUDE_REGEXES "^/(lib|lib32|lib64|usr/lib|usr/lib32|usr/lib64)/"
)
if(missing)
    message(FATAL_ERROR "Unresolved Linux runtime dependencies: ${missing}")
endif()
if(conflicts_FILENAMES)
    message(FATAL_ERROR "Conflicting Linux runtime dependencies: ${conflicts_FILENAMES}")
endif()
# Validate every binary before copying. Runtime-loaded plugins without DT_NEEDED
# edges must be deployed separately; this scan only covers linked dependencies.
foreach(dependency IN LISTS dependencies)
    read_dynamic("${dependency}" dependency)
endforeach()

file(MAKE_DIRECTORY "${destination}")
file(COPY "${LSTGX_RUNTIME_EXECUTABLE}" DESTINATION "${destination}")
get_filename_component(executable_name "${LSTGX_RUNTIME_EXECUTABLE}" NAME)
file(RPATH_CHANGE FILE "${destination}/${executable_name}"
    OLD_RPATH "${executable_rpath}" NEW_RPATH "$ORIGIN")

foreach(dependency IN LISTS dependencies)
    # Preserve SONAME symlinks and the actual versioned library together.
    file(COPY "${dependency}" DESTINATION "${destination}" FOLLOW_SYMLINK_CHAIN)
    get_filename_component(real_dependency "${dependency}" REALPATH)
    get_filename_component(library_name "${real_dependency}" NAME)
    file(RPATH_REMOVE FILE "${destination}/${library_name}")
endforeach()
foreach(resource IN LISTS LSTGX_RUNTIME_RESOURCES)
    file(COPY "${resource}" DESTINATION "${destination}")
endforeach()
message(STATUS "Linux runtime deployed to ${destination}")
