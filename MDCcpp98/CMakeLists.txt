# Mir Drualga Common For C++98
# Copyright (C) 2021  Mir Drualga
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
project(MDCcpp98)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
    "include/mdc/error/exit_on_error.hpp"
    "include/mdc/std/condition_variable.hpp"
    "include/mdc/std/mutex.hpp"
    "include/mdc/std/threads.hpp"
    "include/mdc/wchar_t/wide_decoding.hpp"
    "include/mdc/wchar_t/wide_encoding.hpp"
)

set(SRC_C
    "src/mdc/error/exit_on_error.cpp"
    "src/mdc/std/condition_variable/condition_variable.cpp"
    "src/mdc/std/condition_variable/condition_variable_any.cpp"
    "src/mdc/std/mutex/call_once.cpp"
    "src/mdc/std/mutex/mutex.cpp"
    "src/mdc/std/mutex/recursive_mutex.cpp"
    "src/mdc/std/threads/threads.cpp"
    "src/mdc/wchar_t/wide_decoding.cpp"
    "src/mdc/wchar_t/wide_encoding.cpp"
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

target_link_libraries(lib${PROJECT_NAME} libMDCc)
add_dependencies(lib${PROJECT_NAME} libMDCc)

# Output DLL
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PRIVATE MDC_CPP98_DLLEXPORT)
target_compile_definitions(${PROJECT_NAME} INTERFACE MDC_CPP98_DLLEXPORT)

target_include_directories(${PROJECT_NAME} PUBLIC "include")

target_link_libraries(${PROJECT_NAME} MDCc)
add_dependencies(${PROJECT_NAME} MDCc)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} lib${PROJECT_NAME})
