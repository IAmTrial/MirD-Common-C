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

#ifndef MDC_C_WINDOWS_WINDOWS_FILE_VERSION_INFO_H_
#define MDC_C_WINDOWS_WINDOWS_FILE_VERSION_INFO_H_

#if defined(_MSC_VER)

#include <stddef.h>

#include "../../../include/mdc/std/wchar.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Wrapper for Windows' VerQueryValue, storing the requested value
 * from the specified sub block into the buffer. If the function
 * fails, the function returns NULL and GetLastError will contain
 * the error code. The buffer size represents the size of the buffer
 * in bytes and not the length or character capacity of strings.
 */
void* Mdc_Windows_VerQueryValue(
    void* buffer,
    size_t buffer_size,
    const wchar_t* file_path,
    const wchar_t* sub_block
);

/**
 * Wrapper for Windows' VerQueryValue, used to retrieve the character
 * length or size of the value at the specified sub block. If the
 * function fails, the function returns NULL and GetLastError contains
 * contain the error code.
 */
size_t Mdc_Windows_VerQueryValueCapacity(
    const wchar_t* file_path,
    const wchar_t* sub_block
);

/**
 * Same function as Mdc_Windows_VerQueryValueLength, can be called
 * instead for self-documenting purposes.
 */
size_t Mdc_Windows_VerQueryValueSize(
    const wchar_t* file_path,
    const wchar_t* sub_block
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"

#endif /* defined(_MSC_VER) */

#endif /* MDC_C_WINDOWS_WINDOWS_FILE_VERSION_INFO_H_ */
