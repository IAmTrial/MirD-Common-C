# Mir Drualga Common For C
# Copyright (C) 2020-2022  Mir Drualga
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
project(Tests)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Remove MinGW compiled binary "lib" prefix
set(SRC_C
    "tests/mdc/error/exit_on_error_tests.c"
    "tests/mdc/std/assert_tests.c"
    "tests/mdc/std/stdbool_tests.c"
    "tests/mdc/std/stdint_tests.c"
    "tests/mdc/std/threads_tests.c"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.c"
    "tests/mdc/wchar_t/filew_tests.c"
    "tests/mdc/wchar_t/wide_decoding_tests.c"
    "tests/mdc/wchar_t/wide_encoding_tests.c"
    "tests/mdc/error_tests.c"
    "tests/mdc/main.c"
    "tests/mdc/std_tests.c"
    "tests/mdc/wchar_t_tests.c"
)

set(SRC_HEADER
    "tests/mdc/error/exit_on_error_tests.h"
    "tests/mdc/std/assert_tests.h"
    "tests/mdc/std/stdbool_tests.h"
    "tests/mdc/std/stdint_tests.h"
    "tests/mdc/std/threads_tests.h"
    "tests/mdc/wchar_t/wide_example_text/wide_example_text.h"
    "tests/mdc/wchar_t/filew_tests.h"
    "tests/mdc/wchar_t/wide_decoding_tests.h"
    "tests/mdc/wchar_t/wide_encoding_tests.h"
    "tests/mdc/error_tests.h"
    "tests/mdc/std_tests.h"
    "tests/mdc/wchar_t_tests.h"
)

set(SOURCE_FILES
    "${SRC_C}"
    "${SRC_HEADERS}"
)

# Output test EXE
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} MDCc)
add_dependencies(${PROJECT_NAME} MDCc)

# Output test EXE (static)
add_executable(${PROJECT_NAME}.static ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}.static libMDCc)
add_dependencies(${PROJECT_NAME}.static libMDCc)

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}.static)
