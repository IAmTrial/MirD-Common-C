target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/dllexport_define.inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/dllexport_undefine.inc")

add_subdirectory("mdc")
