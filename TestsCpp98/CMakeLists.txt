cmake_minimum_required(VERSION 3.10)

project(TestsCpp98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Header and source files
set(SRC_C
    "tests/mdc/error/exit_on_error_tests.cpp"
    "tests/mdc/std/std_example_funcs/std_increment.cpp"
    "tests/mdc/std/mutex_tests.cpp"
    "tests/mdc/std/once_flag_tests.cpp"
    "tests/mdc/std/recursive_mutex_tests.cpp"
    "tests/mdc/std/thread_tests.cpp"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.cpp"
    "tests/mdc/wchar_t/wide_decoding_tests.cpp"
    "tests/mdc/wchar_t/wide_encoding_tests.cpp"
    "tests/mdc/error_tests.cpp"
    "tests/mdc/main.cpp"
    "tests/mdc/std_tests.cpp"
    "tests/mdc/wchar_t_tests.cpp"
)

set(SRC_HEADER
    "tests/mdc/error/exit_on_error_tests.hpp"
    "tests/mdc/std/std_example_funcs/std_increment.hpp"
    "tests/mdc/std/mutex_tests.hpp"
    "tests/mdc/std/once_flag_tests.hpp"
    "tests/mdc/std/recursive_mutex_tests.hpp"
    "tests/mdc/std/thread_tests.hpp"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.hpp"
    "tests/mdc/wchar_t/wide_decoding_tests.hpp"
    "tests/mdc/wchar_t/wide_encoding_tests.hpp"
    "tests/mdc/error_tests.hpp"
    "tests/mdc/std_tests.hpp"
    "tests/mdc/wchar_t_tests.hpp"
)

# Output test EXE
add_executable(TestsCpp98 ${SRC_C} ${SRC_HEADER})

target_include_directories(
    TestsCpp98
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDCcpp98/include/"
    PUBLIC "../MDC/include/"
)

target_link_libraries(TestsCpp98 MDCc MDCcpp98)
add_dependencies(TestsCpp98 MDCc MDCcpp98)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${SRC_HEADER})

install(TARGETS TestsCpp98)
