/**
 * Mir Drualga Common For C
 * Copyright (C) 2020  Mir Drualga
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

#ifndef MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_WINDOWS_INTEGER_OBJECT_TYPEDEF_H_
#define MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_WINDOWS_INTEGER_OBJECT_TYPEDEF_H_

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

/**
 * These typedefs are provided to allow the standard types to be used
 * in templates. The reason for this is that the template macros
 * cannot tolerate spaces in the type name.
 */

typedef UCHAR Mdc_UCHAR;

typedef SHORT Mdc_SHORT;
typedef INT Mdc_INT;
typedef LONG Mdc_LONG;
typedef LONGLONG Mdc_LONGLONG;

typedef USHORT Mdc_USHORT;
typedef UINT Mdc_UINT;
typedef ULONG Mdc_ULONG;
typedef ULONGLONG Mdc_ULONGLONG;

typedef BYTE Mdc_BYTE;
typedef WORD Mdc_WORD;
typedef DWORD Mdc_DWORD;
typedef DWORDLONG Mdc_DWORDLONG;

typedef DWORD32 Mdc_DWORD32;
typedef DWORD64 Mdc_DWORD64;

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_WINDOWS_INTEGER_OBJECT_TYPEDEF_H_ */
