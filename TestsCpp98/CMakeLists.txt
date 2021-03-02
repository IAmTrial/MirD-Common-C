cmake_minimum_required(VERSION 3.10)

project(TestsCpp98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Header and source files
set(SRC_DIR tests/mdc)

function(add_src_c_source VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(SRC_C "")
add_src_c_source(SRC_C error/exit_on_error_tests.cpp)
add_src_c_source(SRC_C std/std_example_funcs/std_increment.cpp)
add_src_c_source(SRC_C std/mutex_tests.cpp)
add_src_c_source(SRC_C std/once_flag_tests.cpp)
add_src_c_source(SRC_C std/recursive_mutex_tests.cpp)
add_src_c_source(SRC_C std/thread_tests.cpp)
add_src_c_source(SRC_C wchar_t/wide_example_text/wide_example_text.cpp)
add_src_c_source(SRC_C wchar_t/wide_decoding_tests.cpp)
add_src_c_source(SRC_C wchar_t/wide_encoding_tests.cpp)
add_src_c_source(SRC_C error_tests.cpp)
add_src_c_source(SRC_C main.cpp)
add_src_c_source(SRC_C std_tests.cpp)
add_src_c_source(SRC_C wchar_t_tests.cpp)

function(add_src_header VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(SRC_HEADER "")
add_src_header(SRC_HEADER error/exit_on_error_tests.hpp)
add_src_header(SRC_HEADER std/std_example_funcs/std_increment.hpp)
add_src_header(SRC_HEADER std/mutex_tests.hpp)
add_src_header(SRC_HEADER std/once_flag_tests.hpp)
add_src_header(SRC_HEADER std/recursive_mutex_tests.hpp)
add_src_header(SRC_HEADER std/thread_tests.hpp)
add_src_header(SRC_HEADER wchar_t/wide_example_text/wide_example_text.hpp)
add_src_header(SRC_HEADER wchar_t/wide_decoding_tests.hpp)
add_src_header(SRC_HEADER wchar_t/wide_encoding_tests.hpp)
add_src_header(SRC_HEADER error_tests.hpp)
add_src_header(SRC_HEADER std_tests.hpp)
add_src_header(SRC_HEADER wchar_t_tests.hpp)

add_executable(TestsCpp98 ${SRC_C} ${SRC_HEADER})

target_include_directories(
    TestsCpp98
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDCcpp98/include/"
    PUBLIC "../MDC/include/"
)

target_link_libraries(TestsCpp98 MDCc90)
target_link_libraries(TestsCpp98 MDCcpp98)

add_dependencies(TestsCpp98 MDCc90)
add_dependencies(TestsCpp98 MDCcpp98)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${SRC_HEADER})
