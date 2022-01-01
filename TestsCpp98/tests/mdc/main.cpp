/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021-2022  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C++98.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any program (or a modified version of that program and its
 *  libraries), containing parts covered by the terms of an incompatible
 *  license, the licensors of this Program grant you additional permission
 *  to convey the resulting work.
 */

#include <stdio.h>
#include <stddef.h>
#include <windows.h>

#include "error_tests.hpp"
#include "std_tests.hpp"
#include "wchar_t_tests.hpp"

int main(int argc, char** argv) {
#if defined(NDEBUG)
  MessageBoxA(NULL, "Tests must run in debug mode!", "Error", MB_OK);
  exit(EXIT_FAILURE);
#endif /* defined(NDEBUG) */

  // Commented out to prevent exit.
  // ::mdc_test::error_test::RunTests();

  ::mdc_test::std_test::RunTests();
  ::mdc_test::wide_test::RunTests();

  return 0;
}
