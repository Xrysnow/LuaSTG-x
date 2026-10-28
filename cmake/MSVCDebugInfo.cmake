# Keep full debug symbols without the compiler PDB service that can fail with C1902.
# CMP0141 is NEW through the top-level CMake minimum; non-MSVC compilers ignore this.
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")

# Older build caches may still contain /Zi or /ZI in their language flags.
# Shadow those flags for this configure instead of rewriting the user's cache.
foreach(_lstgx_msvc_lang IN ITEMS C CXX)
    foreach(_lstgx_msvc_config IN ITEMS DEBUG RELWITHDEBINFO)
        set(_lstgx_msvc_flag_var "CMAKE_${_lstgx_msvc_lang}_FLAGS_${_lstgx_msvc_config}")
        if(DEFINED ${_lstgx_msvc_flag_var})
            while("${${_lstgx_msvc_flag_var}}" MATCHES "(^|[ \t])[-/]Z[iI]([ \t]|$)")
                string(REGEX REPLACE "(^|[ \t])[-/]Z[iI]([ \t]|$)" "\\1\\2"
                    ${_lstgx_msvc_flag_var} "${${_lstgx_msvc_flag_var}}")
            endwhile()
        endif()
    endforeach()
endforeach()
unset(_lstgx_msvc_lang)
unset(_lstgx_msvc_config)
unset(_lstgx_msvc_flag_var)
