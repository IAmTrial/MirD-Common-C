target_sources(${PROJECT_NAME}
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/condition_variable.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/mutex.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/threads.hpp")

add_subdirectory("condition_variable")
add_subdirectory("mutex")
add_subdirectory("threads")
