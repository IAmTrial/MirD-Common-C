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

#ifndef MDC_C_OBJECT_SHORT_H_
#define MDC_C_OBJECT_SHORT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_Short {
  short value_;
};

/**
 * Initialization/deinitialization
 */

DLLEXPORT struct Mdc_Short* Mdc_Short_InitDefault(struct Mdc_Short* shrt);

DLLEXPORT struct Mdc_Short* Mdc_Short_InitFromValue(
    struct Mdc_Short* shrt,
    short value
);

DLLEXPORT struct Mdc_Short* Mdc_Short_InitCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
);

DLLEXPORT struct Mdc_Short* Mdc_Short_InitMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
);

DLLEXPORT void Mdc_Short_Deinit(struct Mdc_Short* shrt);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Short_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT struct Mdc_Short* Mdc_Short_AssignCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
);

DLLEXPORT struct Mdc_Short* Mdc_Short_AssignMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT struct Mdc_Short* Mdc_Short_PreIncrement(
    struct Mdc_Short* shrt
);

DLLEXPORT struct Mdc_Short* Mdc_Short_PreDecrement(
    struct Mdc_Short* shrt
);

DLLEXPORT struct Mdc_Short* Mdc_Short_PostIncrement(
    struct Mdc_Short* shrt_out,
    struct Mdc_Short* shrt_in
);

DLLEXPORT struct Mdc_Short* Mdc_Short_PostDecrement(
    struct Mdc_Short* shrt_out,
    struct Mdc_Short* shrt_in
);

/**
 * Arithmetic operators
 */

DLLEXPORT struct Mdc_Short* Mdc_Short_Add(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_Subtract(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_Multiply(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_Divide(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_Modulo(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseNot(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseAnd(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseOr(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseXor(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseLeftShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

DLLEXPORT struct Mdc_Short* Mdc_Short_BitwiseRightShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Short_Equal(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* integer2
);

DLLEXPORT bool Mdc_Short_EqualValue(
    const struct Mdc_Short* shrt,
    short value
);

DLLEXPORT int Mdc_Short_Compare(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
);

DLLEXPORT int Mdc_Short_CompareValue(
    const struct Mdc_Short* shrt,
    short value
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_Short_Hash(const struct Mdc_Short* shrt);

DLLEXPORT void Mdc_Short_Swap(
    struct Mdc_Short* short1,
    struct Mdc_Short* short2
);

DLLEXPORT short Mdc_Short_GetValue(const struct Mdc_Short* shrt);

DLLEXPORT void Mdc_Short_SetValue(struct Mdc_Short* shrt, short value);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_SHORT_H_ */
