/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2021  Mir Drualga
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

#ifndef MDC_C_ERROR_EXIT_ON_ERROR_H_
#define MDC_C_ERROR_EXIT_ON_ERROR_H_

#include "../std/wchar.h"
#include "../wchar_t/filew.h"

#if defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
#endif /* defined(_WIN32) || defined(_WIN64) */

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum {
  Mdc_Error_kErrorMessageCapacity = 1024
};

DLLEXPORT void Mdc_Error_ExitOnGeneralError(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    ...
);

DLLEXPORT void Mdc_Error_ExitOnGeneralErrorV(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    va_list vlist
);

DLLEXPORT void Mdc_Error_ExitOnConstantMappingError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    int value
);

DLLEXPORT void Mdc_Error_ExitOnMemoryAllocError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
);

DLLEXPORT void Mdc_Error_ExitOnMdcFunctionError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    const wchar_t* function_name
);

DLLEXPORT void Mdc_Error_ExitOnStaticInitError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
);

#if defined(_WIN32) || defined(_WIN64)

DLLEXPORT void Mdc_Error_ExitOnWindowsFunctionError(
    const wchar_t* file_path_cwstr,
    unsigned int line,
    const wchar_t* function_name,
    DWORD last_error
);

#endif /* defined(_WIN32) || defined(_WIN64) */

#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_ERROR_EXIT_ON_ERROR_H_ */
