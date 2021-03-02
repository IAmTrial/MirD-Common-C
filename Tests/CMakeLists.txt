cmake_minimum_required(VERSION 3.10)

project(Tests)

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
add_src_c_source(SRC_C error/exit_on_error_tests.c)
add_src_c_source(SRC_C std/assert_tests.c)
add_src_c_source(SRC_C std/stdbool_tests.c)
add_src_c_source(SRC_C std/stdint_tests.c)
add_src_c_source(SRC_C std/threads_tests.c)
add_src_c_source(SRC_C wchar_t/wide_example_text/wide_example_text.c)
add_src_c_source(SRC_C wchar_t/filew_tests.c)
add_src_c_source(SRC_C wchar_t/wide_decoding_tests.c)
add_src_c_source(SRC_C wchar_t/wide_encoding_tests.c)
add_src_c_source(SRC_C error_tests.c)
add_src_c_source(SRC_C main.c)
add_src_c_source(SRC_C std_tests.c)
add_src_c_source(SRC_C wchar_t_tests.c)

function(add_src_header VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(SRC_HEADER "")
add_src_header(SRC_HEADER error/exit_on_error_tests.h)
add_src_header(SRC_HEADER std/assert_tests.h)
add_src_header(SRC_HEADER std/stdbool_tests.h)
add_src_header(SRC_HEADER std/stdint_tests.h)
add_src_header(SRC_HEADER std/threads_tests.h)
add_src_header(SRC_HEADER wchar_t/wide_example_text/wide_example_text.h)
add_src_header(SRC_HEADER wchar_t/filew_tests.h)
add_src_header(SRC_HEADER wchar_t/wide_decoding_tests.h)
add_src_header(SRC_HEADER wchar_t/wide_encoding_tests.h)
add_src_header(SRC_HEADER error_tests.h)
add_src_header(SRC_HEADER std_tests.h)
add_src_header(SRC_HEADER wchar_t_tests.h)

add_executable(Tests ${SRC_C} ${SRC_HEADER})

target_include_directories(
    Tests
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDC/include/"
)

target_link_libraries(Tests MDCc90)

add_dependencies(Tests MDCc90)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${SRC_HEADER})
