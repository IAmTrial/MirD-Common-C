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

#ifndef MDC_C_STD_UCHAR_H_
#define MDC_C_STD_UCHAR_H_

#include "stdint.h"

#include "../../../dllexport_define.inc"

#if __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER > 1200

#include <uchar.h>

#else

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if __cplusplus >= 202002L \
      || __STDC_VERSION__ >= 999999L /* TODO: Replace once C2X finishes. */ \
      || _MSC_VER > 999999 /* TODO: Replace when C2X is supported */

typedef unsigned char char8_t;

#endif

typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_STD_UCHAR_H_ */
