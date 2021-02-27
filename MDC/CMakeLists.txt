cmake_minimum_required(VERSION 3.10)

project(MDC)

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
add_include_header(INCLUDE_HEADERS error/exit_on_error.h)
add_include_header(INCLUDE_HEADERS malloc/malloc.h)
add_include_header(INCLUDE_HEADERS std/assert.h)
add_include_header(INCLUDE_HEADERS std/stdbool.h)
add_include_header(INCLUDE_HEADERS std/stdint.h)
add_include_header(INCLUDE_HEADERS std/threads.h)
add_include_header(INCLUDE_HEADERS std/wchar.h)
add_include_header(INCLUDE_HEADERS wchar_t/filew.h)
add_include_header(INCLUDE_HEADERS wchar_t/wide_decoding.h)
add_include_header(INCLUDE_HEADERS wchar_t/wide_encoding.h)

set(SRC_DIR src/mdc)

function(add_src_c_source VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

function(add_src_header VAR FILE)
    set(${VAR} ${${VAR}} ${SRC_DIR}/${FILE} PARENT_SCOPE)
endfunction()

set(SRC_C "")
add_src_c_source(SRC_C error/exit_on_error.c)
add_src_c_source(SRC_C malloc/malloc.c)
add_src_c_source(SRC_C std/threads/call_once.c)
add_src_c_source(SRC_C std/threads/cond.c)
add_src_c_source(SRC_C std/threads/mutex.c)
add_src_c_source(SRC_C std/threads/threads.c)
add_src_c_source(SRC_C std/wchar/wchar.c)
add_src_c_source(SRC_C wchar_t/wide_decoding.c)
add_src_c_source(SRC_C wchar_t/wide_encoding.c)

add_library(MDCc90 STATIC ${SRC_C} ${INCLUDE_HEADERS})

target_include_directories(
    MDCc90
    PUBLIC "${PROJECT_BINARY_DIR}"
)

add_library(MDCc90Dll SHARED ${SRC_C} ${INCLUDE_HEADERS})

target_compile_definitions(MDCc90Dll PRIVATE MDC_DLLEXPORT)
target_compile_definitions(MDCc90Dll INTERFACE MDC_DLLIMPORT)

target_include_directories(
    MDCc90Dll
    PUBLIC "${PROJECT_BINARY_DIR}"
)
