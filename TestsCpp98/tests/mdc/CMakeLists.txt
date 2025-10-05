target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/error_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/error_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/std_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/std_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wchar_t_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wchar_t_tests.hpp"
    PUBLIC)

add_subdirectory("error")
add_subdirectory("std")
add_subdirectory("wchar_t")
