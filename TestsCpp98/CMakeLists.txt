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
project(TestsCpp98)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Remove MinGW compiled binary "lib" prefix
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

set(SOURCE_FILES
    "${SRC_C}"
    "${SRC_HEADERS}"
)

# Output test EXE
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} MDCc MDCcpp98)
add_dependencies(${PROJECT_NAME} MDCc MDCcpp98)

# Output test EXE (static)
add_executable(${PROJECT_NAME}.static ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}.static libMDCc libMDCcpp98)
add_dependencies(${PROJECT_NAME}.static libMDCc libMDCcpp98)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}.static)
