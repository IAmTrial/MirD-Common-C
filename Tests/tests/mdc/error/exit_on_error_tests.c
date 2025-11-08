/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2025  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C.
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

#include "mdc/error/exit_on_error_tests.h"

#include "mdc/error/exit_on_error.h"

#include "mdc/wchar_t/filew.h"

static void ExitOnGeneralError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnGeneralError(
      L"Error Test",
      L"%ls, %d, %X",
      __FILEW__,
      __LINE__,
      L"Twenty-five",
      25,
      25);
}

static void ExitOnConstantMappingError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnConstantMappingError(__FILEW__, __LINE__, 128);
}

static void ExitOnMemoryAllocError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
}

static void ExitOnMdcFunctionError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnMdcFunctionError(__FILEW__, __LINE__, L"Mdc_NotAFunction");
}

static void ExitOnStaticInitError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnStaticInitError(__FILEW__, __LINE__);
}

#if defined(_WIN32) || defined(_WIN64)

static void ExitOnWindowsFunctionError_ExitsWithMessage(void) {
  Mdc_Error_ExitOnWindowsFunctionError(__FILEW__, __LINE__, L"IsThisWindows9", 42);
}

#endif  /* defined(_WIN32) || defined(_WIN64) */

void Mdc_ExitOnError_RunTests(void) {
  ExitOnGeneralError_ExitsWithMessage();
  ExitOnConstantMappingError_ExitsWithMessage();
  ExitOnMemoryAllocError_ExitsWithMessage();
  ExitOnMdcFunctionError_ExitsWithMessage();
  ExitOnStaticInitError_ExitsWithMessage();

#if defined(_WIN32) || defined(_WIN64)
  ExitOnWindowsFunctionError_ExitsWithMessage();
#endif  /* defined(_WIN32) || defined(_WIN64) */
}
