/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2022  Mir Drualga
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

#include "../../../include/mdc/error/exit_on_error.h"

#include <stdarg.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)

static const wchar_t* const kErrorMessageFormat =
    L"File: %ls \n"
    L"Line: %u \n"
    L"\n"
    L"%ls";

static wchar_t error_message_format[Mdc_Error_kErrorMessageCapacity];
static wchar_t error_message[Mdc_Error_kErrorMessageCapacity];

void Mdc_Error_ExitOnGeneralError(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    ...
) {
  va_list args;

  va_start(args, line);

  Mdc_Error_ExitOnGeneralErrorV(
      caption_text,
      message_format,
      file_path_c_wstr,
      line,
      args
  );

  va_end(args);
}

void Mdc_Error_ExitOnGeneralErrorV(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    va_list vlist
) {
  _snwprintf(
      error_message_format,
      Mdc_Error_kErrorMessageCapacity,
      kErrorMessageFormat,
      file_path_c_wstr,
      line,
      message_format
  );

  error_message_format[Mdc_Error_kErrorMessageCapacity - 1] = L'\0';

  _vsnwprintf(
      error_message,
      Mdc_Error_kErrorMessageCapacity,
      error_message_format,
      vlist
  );

  error_message[Mdc_Error_kErrorMessageCapacity - 1] = L'\0';

  MessageBoxW(
      NULL,
      error_message,
      caption_text,
      MB_OK | MB_ICONERROR
  );

  exit(EXIT_FAILURE);
}

void Mdc_Error_ExitOnConstantMappingError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    int value
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Constant with value %d could not be mapped.",
      file_path_c_wstr,
      line,
      value
  );
}

void Mdc_Error_ExitOnMemoryAllocError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Memory allocation error.",
      file_path_c_wstr,
      line
  );
}

void Mdc_Error_ExitOnMdcFunctionError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    const wchar_t* function_name
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"MDC function error on %ls.",
      file_path_c_wstr,
      line,
      function_name
  );
}

void Mdc_Error_ExitOnStaticInitError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Static init error.",
      file_path_c_wstr,
      line
  );
}

void Mdc_Error_ExitOnWindowsFunctionError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    const wchar_t* function_name,
    DWORD last_error
) {
  Mdc_Error_ExitOnGeneralError(
      L"Error",
      L"Windows function error on %ls with error code 0x%X.",
      file_path_c_wstr,
      line,
      function_name,
      last_error
  );
}

#endif /* defined(_WIN32) || defined(_WIN64) */
