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

#ifndef MDC_C_STD_STDINT_H_
#define MDC_C_STD_STDINT_H_

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

#include <stdint.h>

#else

typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef int64_t intmax_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
typedef uint64_t uintmax_t;

#if defined(_WIN64)

typedef __int64 intptr_t;
typedef unsigned __int64 uintptr_t;

#elif defined(_WIN32)

typedef __int32 intptr_t;
typedef unsigned __int32 uintptr_t;

#endif

#define INT8_MIN -128
#define INT16_MIN -32768
#define INT32_MIN -2147483648
#define INT64_MIN -9223372036854775808L

#if defined(_WIN64)
#define INTPTR_MIN INT64_MIN
#elif defined(_WIN32)
#define INTPTR_MIN INT32_MIN
#endif

#define INTMAX_MIN INT64_MIN

#define INT8_MAX 127
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807L

#if defined(_WIN64)
#define INTPTR_MAX INT64_MAX
#elif defined(_WIN32)
#define INTPTR_MAX INT32_MAX
#endif

#define INTMAX_MAX INT64_MAX

#define UINT8_MAX 255
#define UINT16_MAX 65535
#define UINT32_MAX 4294967295
#define UINT64_MAX 18446744073709551615L

#if defined(_WIN64)
#define UINTPTR_MAX UINT64_MAX
#elif defined(_WIN32)
#define UINTPTR_MAX UINT32_MAX
#endif

#define UINTMAX_MAX UINT64_MAX

#endif /* defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */

#endif /* MDC_C_STD_STDINT_H_ */
