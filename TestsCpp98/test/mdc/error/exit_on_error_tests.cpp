/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021  Mir Drualga
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

#include "exit_on_error_tests.hpp"

#include <mdc/error/exit_on_error.hpp>

namespace mdc {
namespace {

static void AssertExitOnGeneralError() {
  ::mdc::error::ExitOnGeneralError(
      L"Error Test",
      L"%ls, %d, %X",
      __FILEW__,
      __LINE__,
      L"Twenty-five",
      25,
      25
  );
}

static void AssertExitOnConstantMappingError() {
  ::mdc::error::ExitOnConstantMappingError(
      __FILEW__,
      __LINE__,
      128
  );
}

static void AssertExitOnMemoryAllocError() {
  ::mdc::error::ExitOnMemoryAllocError(__FILEW__, __LINE__);
}

static void AssertExitOnMdcFunctionError(void) {
  ::mdc::error::ExitOnMdcFunctionError(
      __FILEW__,
      __LINE__,
      L"Mdc_NotAFunction"
  );
}

static void AssertExitOnStaticInitError() {
  ::mdc::error::ExitOnStaticInitError(__FILEW__, __LINE__);
}

#if defined(_WIN32) || defined(_WIN64)

static void AssertExitOnWindowsFunctionError() {
  ::mdc::error::ExitOnWindowsFunctionError(
      __FILEW__,
      __LINE__,
      L"IsThisWindows9",
      42
  );
}

#endif /* defined(_WIN32) || defined(_WIN64) */

} // namespace

void ExitOnError_RunTests() {
  AssertExitOnGeneralError();
  AssertExitOnConstantMappingError();
  AssertExitOnMemoryAllocError();
  AssertExitOnMdcFunctionError();
  AssertExitOnStaticInitError();


#if defined(_WIN32) || defined(_WIN64)
  AssertExitOnWindowsFunctionError();
#endif /* defined(_WIN32) || defined(_WIN64) */
}

} // namespace mdc
