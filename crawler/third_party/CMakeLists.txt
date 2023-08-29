file(MAKE_DIRECTORY ${LIBRARY_OUTPUT_DIRECTORY})

message("========== thrid-party BEGIN ============")
link_directories(/opt/homebrew/Cellar/brotli/1.0.9/lib)

message(STATUS "")
message(STATUS "========== thrid-party: httplib ============")
set(httplib_setup_log "httplib_setup.log")
set(httplib_compile_log "httplib_compile.log")
set(httplib_submodule_dir ${CMAKE_CURRENT_SOURCE_DIR}/cpp-httplib)
set(httplib_build_folder_name build)
set(httplib_build_dir ${httplib_submodule_dir}/${httplib_build_folder_name})
message(STATUS "executing 'meson setup'")
execute_process(
        COMMAND bash "-c" "meson setup --default-library=static --wipe ${httplib_build_folder_name}"
        WORKING_DIRECTORY ${httplib_submodule_dir}
        ERROR_FILE ${httplib_setup_log}
        OUTPUT_FILE ${httplib_setup_log}
        RESULT_VARIABLE httplibMesonResult
)
if (${httplibMesonResult})
    execute_process(
            COMMAND bash "-c" "cat ${httplib_setup_log}"
            WORKING_DIRECTORY ${httplib_submodule_dir}
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(FATAL_ERROR "execute 'meson setup' failed")
else()
    message(STATUS "execute 'meson setup' done")
endif()

message(STATUS "executing 'meson compile'")
execute_process(
        COMMAND bash "-c" "meson compile"
        WORKING_DIRECTORY ${httplib_build_dir}
        ERROR_FILE ${httplib_compile_log}
        OUTPUT_FILE ${httplib_compile_log}
        RESULT_VARIABLE httplibMesonResult
)
if (${httplibMesonResult})
    execute_process(
            COMMAND bash "-c" "cat ${httplib_compile_log}"
            WORKING_DIRECTORY ${httplib_build_dir}
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message(FATAL_ERROR "execute 'meson compile' failed")
else()
    message(STATUS "execute 'meson compile' done")
endif()

message(STATUS "executing 'cp libhttplib.a ${LIBRARY_OUTPUT_DIRECTORY}'")
execute_process(
        COMMAND bash "-c" "cp libhttplib.a ${LIBRARY_OUTPUT_DIRECTORY}"
        WORKING_DIRECTORY ${httplib_build_dir}
        RESULT_VARIABLE httplibCpResult
)
if (${httplibCpResult})
    message(FATAL_ERROR "execute 'cp libhttplib.a' failed")
else()
    message(STATUS "execute 'cp libhttplib.a' done")
endif()

message("========== thrid-party END ============")

