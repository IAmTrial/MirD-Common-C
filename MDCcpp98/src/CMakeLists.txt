target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_define.inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/dllapi_undef.inc")

add_subdirectory("mdc")
