# Mir Drualga Common For C
# Copyright (C) 2020-2021  Mir Drualga
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Additional permissions under GNU Affero General Public License version 3
# section 7
#
# If you modify this Program, or any covered work, by linking or combining
# it with any program (or a modified version of that program and its
# libraries), containing parts covered by the terms of an incompatible
# license, the licensors of this Program grant you additional permission
# to convey the resulting work.

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

set(SOURCE_FILES
    "${INCLUDE_HEADERS}"
    "${SRC_C}"
    "${SRC_HEADERS}"
)

# Output static LIB
add_library(lib${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(lib${PROJECT_NAME} PUBLIC "include")

# Output DLL
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PRIVATE MDC_C_DLLEXPORT)
target_compile_definitions(${PROJECT_NAME} INTERFACE MDC_C_DLLIMPORT)

target_include_directories(${PROJECT_NAME} PUBLIC "include")

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} lib${PROJECT_NAME})
