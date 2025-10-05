target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/mutex_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/mutex_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/once_flag_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/once_flag_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/recursive_mutex_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/recursive_mutex_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/thread_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/thread_tests.hpp"
    PUBLIC)

add_subdirectory("std_example_funcs")
