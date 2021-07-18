cmake_minimum_required(VERSION 3.10)

project(MDC)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

# Header and source files
set(INCLUDE_HEADERS
    "dllexport_define.inc"
    "dllexport_define.inc"
    "include/mdc/error/exit_on_error.h"
    "include/mdc/malloc/malloc.h"
    "include/mdc/std/assert.h"
    "include/mdc/std/stdbool.h"
    "include/mdc/std/stdint.h"
    "include/mdc/std/threads.h"
    "include/mdc/std/wchar.h"
    "include/mdc/wchar_t/filew.h"
    "include/mdc/wchar_t/wide_decoding.h"
    "include/mdc/wchar_t/wide_encoding.h"
)

set(SRC_C
    "src/mdc/error/exit_on_error.c"
    "src/mdc/malloc/malloc.c"
    "src/mdc/std/threads/call_once.c"
    "src/mdc/std/threads/cond.c"
    "src/mdc/std/threads/mutex.c"
    "src/mdc/std/threads/threads.c"
    "src/mdc/std/wchar/wchar.c"
    "src/mdc/wchar_t/wide_decoding.c"
    "src/mdc/wchar_t/wide_encoding.c"
)

set(SRC_HEADERS)

# Output static LIB
add_library(libMDCc STATIC ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_include_directories(
    libMDCc
    PUBLIC "include"
)

# Output DLL
add_library(MDCc SHARED ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_compile_definitions(MDCc PRIVATE MDC_DLLEXPORT)
target_compile_definitions(MDCc INTERFACE MDC_DLLIMPORT)

target_include_directories(
    MDCc
    PUBLIC "include"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${INCLUDE_HEADERS})

install(TARGETS MDCc libMDCc)
