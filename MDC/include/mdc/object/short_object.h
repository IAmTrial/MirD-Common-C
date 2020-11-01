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

#ifndef MDC_C_OBJECT_SHORT_OBJECT_H_
#define MDC_C_OBJECT_SHORT_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT short* Mdc_Short_InitDefault(short* shrt);

DLLEXPORT short* Mdc_Short_InitFromValue(
    short* shrt,
    short value
);

DLLEXPORT short* Mdc_Short_InitCopy(
    short* dest,
    const short* src
);

DLLEXPORT short* Mdc_Short_InitMove(
    short* dest,
    short* src
);

DLLEXPORT void Mdc_Short_Deinit(short* shrt);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Short_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT short* Mdc_Short_AssignCopy(
    short* dest,
    const short* src
);

DLLEXPORT short* Mdc_Short_AssignMove(
    short* dest,
    short* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT short* Mdc_Short_PreIncrement(
    short* shrt
);

DLLEXPORT short* Mdc_Short_PreDecrement(
    short* shrt
);

DLLEXPORT short* Mdc_Short_PostIncrement(
    short* out,
    short* in
);

DLLEXPORT short* Mdc_Short_PostDecrement(
    short* out,
    short* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT short* Mdc_Short_Add(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_Subtract(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_Multiply(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_Divide(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_Modulo(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_BitwiseNot(
    short* out,
    const short* in
);

DLLEXPORT short* Mdc_Short_BitwiseAnd(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_BitwiseOr(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_BitwiseXor(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_BitwiseLeftShift(
    short* out,
    const short* op1,
    const short* op2
);

DLLEXPORT short* Mdc_Short_BitwiseRightShift(
    short* out,
    const short* op1,
    const short* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Short_Equal(
    const short* short1,
    const short* short2
);

DLLEXPORT bool Mdc_Short_EqualValue(
    short value1,
    short value2
);

DLLEXPORT int Mdc_Short_Compare(
    const short* short1,
    const short* short2
);

DLLEXPORT int Mdc_Short_CompareValue(
    short value1,
    short value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_Short_Hash(const short* shrt);

DLLEXPORT size_t Mdc_Short_HashValue(short shrt);

DLLEXPORT void Mdc_Short_Swap(
    short* short1,
    short* short2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_SHORT_OBJECT_H_ */
