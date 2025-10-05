target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/call_once.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/mutex.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/recursive_mutex.cpp"
    PUBLIC)
