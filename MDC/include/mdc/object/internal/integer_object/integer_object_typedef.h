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

#ifndef MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_TYPEDEF_H_
#define MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_TYPEDEF_H_

#include <stddef.h>

#include "../../../std/stdint.h"

/**
 * These typedefs are provided to allow the standard types to be used
 * in templates. The reason for this is that the template macros
 * cannot tolerate spaces in the type name.
 */

typedef signed char Mdc_SChar;
typedef short Mdc_Short;
typedef int Mdc_Int;
typedef long Mdc_Long;

typedef unsigned char Mdc_UChar;
typedef unsigned short Mdc_UShort;
typedef unsigned int Mdc_UInt;
typedef unsigned long Mdc_ULong;

#if __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600

typedef long long Mdc_LLong;
typedef unsigned long long Mdc_ULLong;

#endif /* __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600 */

/**
 * These typedefs are simply to prevent namespace pollution with
 * function names.
 */

typedef int8_t Mdc_Int8;
typedef int16_t Mdc_Int16;
typedef int32_t Mdc_Int32;
typedef int64_t Mdc_Int64;

typedef int_least8_t Mdc_IntLeast8;
typedef int_least16_t Mdc_IntLeast16;
typedef int_least32_t Mdc_IntLeast32;
typedef int_least64_t Mdc_IntLeast64;

typedef intmax_t Mdc_IntMax;

typedef uint8_t Mdc_UInt8;
typedef uint16_t Mdc_UInt16;
typedef uint32_t Mdc_UInt32;
typedef uint64_t Mdc_UInt64;

typedef uint_least8_t Mdc_UIntLeast8;
typedef uint_least16_t Mdc_UIntLeast16;
typedef uint_least32_t Mdc_UIntLeast32;
typedef uint_least64_t Mdc_UIntLeast64;

typedef uintmax_t Mdc_UIntMax;

typedef intptr_t Mdc_Intptr;
typedef uintptr_t Mdc_UIntptr;

typedef size_t Mdc_Size;
typedef ptrdiff_t Mdc_Ptrdiff;

#endif /* MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_TYPEDEF_H_ */
