cmake_minimum_required(VERSION 3.10)

project(Tests)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

# Header and source files
set(SRC_C
    "tests/mdc/error/exit_on_error_tests.c"
    "tests/mdc/std/assert_tests.c"
    "tests/mdc/std/stdbool_tests.c"
    "tests/mdc/std/stdint_tests.c"
    "tests/mdc/std/threads_tests.c"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.c"
    "tests/mdc/wchar_t/filew_tests.c"
    "tests/mdc/wchar_t/wide_decoding_tests.c"
    "tests/mdc/wchar_t/wide_encoding_tests.c"
    "tests/mdc/error_tests.c"
    "tests/mdc/main.c"
    "tests/mdc/std_tests.c"
    "tests/mdc/wchar_t_tests.c"
)

set(SRC_HEADER
    "tests/mdc/error/exit_on_error_tests.h"
    "tests/mdc/std/assert_tests.h"
    "tests/mdc/std/stdbool_tests.h"
    "tests/mdc/std/stdint_tests.h"
    "tests/mdc/std/threads_tests.h"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.h"
    "tests/mdc/wchar_t/filew_tests.h"
    "tests/mdc/wchar_t/wide_decoding_tests.h"
    "tests/mdc/wchar_t/wide_encoding_tests.h"
    "tests/mdc/error_tests.h"
    "tests/mdc/std_tests.h"
    "tests/mdc/wchar_t_tests.h"
)

# Output test EXE
add_executable(Tests ${SRC_C} ${SRC_HEADER})

target_include_directories(
    Tests
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDC/include/"
)

target_link_libraries(Tests MDCc)
add_dependencies(Tests MDCc)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${SRC_HEADER})

install(TARGETS Tests)
