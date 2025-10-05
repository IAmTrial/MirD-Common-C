target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_c_define.inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_c_undef.inc")

add_subdirectory("error")
add_subdirectory("malloc")
add_subdirectory("std")
add_subdirectory("wchar_t")
