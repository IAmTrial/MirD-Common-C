cmake_minimum_required(VERSION 3.10)

project(MDCcpp98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Header and source files
set(INCLUDE_DIR include/mdc)

function(add_include_header VAR FILE)
    set(${VAR} ${${VAR}} ${INCLUDE_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(INCLUDE_HEADERS dllexport_define.inc dllexport_define.inc)
add_include_header(INCLUDE_HEADERS error/exit_on_error.hpp)
add_include_header(INCLUDE_HEADERS std/condition_variable.hpp)
add_include_header(INCLUDE_HEADERS std/mutex.hpp)
add_include_header(INCLUDE_HEADERS std/threads.hpp)
add_include_header(INCLUDE_HEADERS wchar_t/wide_decoding.hpp)
add_include_header(INCLUDE_HEADERS wchar_t/wide_encoding.hpp)

set(SRC_DIR src/mdc)

function(add_src_c_source VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

function(add_src_header VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(SRC_C "")
add_src_c_source(SRC_C error/exit_on_error.cpp)
add_src_c_source(SRC_C std/condition_variable/condition_variable.cpp)
add_src_c_source(SRC_C std/condition_variable/condition_variable_any.cpp)
add_src_c_source(SRC_C std/mutex/call_once.cpp)
add_src_c_source(SRC_C std/mutex/mutex.cpp)
add_src_c_source(SRC_C std/mutex/recursive_mutex.cpp)
add_src_c_source(SRC_C std/threads/threads.cpp)
add_src_c_source(SRC_C wchar_t/wide_decoding.cpp)
add_src_c_source(SRC_C wchar_t/wide_encoding.cpp)

add_library(MDCcpp98 STATIC ${SRC_C} ${INCLUDE_HEADERS})

target_include_directories(
    MDCcpp98
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDC/include/"
)

target_link_libraries(MDCcpp98 MDCc90)

add_dependencies(MDCcpp98 MDCc90)

add_library(MDCcpp98Dll SHARED ${SRC_C} ${INCLUDE_HEADERS})

target_compile_definitions(MDCcpp98Dll PRIVATE MDC_CPP98_DLLEXPORT)
target_compile_definitions(MDCcpp98Dll INTERFACE MDC_CPP98_DLLEXPORT)

target_include_directories(
    MDCcpp98Dll
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "../MDC/include/"
)

target_link_libraries(MDCcpp98Dll MDCc90)

add_dependencies(MDCcpp98Dll MDCc90)
