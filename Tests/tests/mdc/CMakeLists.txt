target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/error_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/error_tests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/std_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/std_tests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/wchar_t_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/wchar_t_tests.h"
    PUBLIC)

add_subdirectory("error")
add_subdirectory("std")
add_subdirectory("wchar_t")
