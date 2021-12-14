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

cmake_minimum_required(VERSION 3.10)

project(MDCcpp98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Header and source files
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

# Output static LIB
add_library(libMDCcpp98 STATIC ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_include_directories(libMDCcpp98 PUBLIC "include")

target_link_libraries(libMDCcpp98 libMDCc)
add_dependencies(libMDCcpp98 libMDCc)

# Output DLL
add_library(MDCcpp98 SHARED ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_compile_definitions(MDCcpp98 PRIVATE MDC_CPP98_DLLEXPORT)
target_compile_definitions(MDCcpp98 INTERFACE MDC_CPP98_DLLEXPORT)

target_include_directories(MDCcpp98 PUBLIC "include")

target_link_libraries(MDCcpp98 MDCc)
add_dependencies(MDCcpp98 MDCc)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${INCLUDE_HEADERS})

install(TARGETS MDCcpp98 libMDCcpp98)
