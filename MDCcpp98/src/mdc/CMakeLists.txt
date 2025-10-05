target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_cpp98_define.inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_cpp98_undef.inc")

add_subdirectory("error")
add_subdirectory("std")
add_subdirectory("wchar_t")
