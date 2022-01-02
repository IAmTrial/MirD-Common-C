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

#ifndef MDC_CPP98_ERROR_EXIT_ON_ERROR_HPP_
#define MDC_CPP98_ERROR_EXIT_ON_ERROR_HPP_

#if defined(_WIN32) || defined(_WIN64)
  #include <windows.h>
#endif /* defined(_WIN32) || defined(_WIN64) */

#include <mdc/error/exit_on_error.h>

#include "../../../dllexport_define.inc"

namespace mdc {
namespace error {

enum {
  kErrorMessageCapacity = Mdc_Error_kErrorMessageCapacity,
};

DLLEXPORT void ExitOnGeneralError(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    ...
);

DLLEXPORT void ExitOnGeneralErrorV(
    const wchar_t* caption_text,
    const wchar_t* message_format,
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    va_list args
);

DLLEXPORT void ExitOnConstantMappingError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    int value
);

DLLEXPORT void ExitOnMemoryAllocError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
);

DLLEXPORT void ExitOnMdcFunctionError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    const wchar_t* function_name
);

DLLEXPORT void ExitOnStaticInitError(
    const wchar_t* file_path_c_wstr,
    unsigned int line
);

#if defined(_WIN32) || defined(_WIN64)

DLLEXPORT void ExitOnWindowsFunctionError(
    const wchar_t* file_path_c_wstr,
    unsigned int line,
    const wchar_t* function_name,
    DWORD last_error
);

#endif /* defined(_WIN32) || defined(_WIN64) */

} // namespace error
} // namespace mdc

#include "../../../dllexport_undefine.inc"
#endif /* MDC_CPP98_ERROR_EXIT_ON_ERROR_HPP_ */
