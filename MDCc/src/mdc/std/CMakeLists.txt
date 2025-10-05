target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/assert.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/stdbool.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/stdint.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/threads.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/wchar.h")

add_subdirectory("threads")
add_subdirectory("wchar")
