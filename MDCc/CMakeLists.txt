cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(MDCc)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# List all of the source files here
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

set(SOURCE_FILES
    "${INCLUDE_HEADERS}"
)

option(${PROJECT_NAME}_BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (${PROJECT_NAME}_BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    target_compile_definitions(${PROJECT_NAME}
        INTERFACE MDC_C_DLLIMPORT
        PRIVATE MDC_C_DLLEXPORT)
    target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/MDCc/include")
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
    target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/MDCc/include")
endif()

add_subdirectory("src")

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})
