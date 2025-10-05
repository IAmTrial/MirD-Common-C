target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/call_once.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/cond.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/mutex.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/threads.c"
    PUBLIC)
