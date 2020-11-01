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

#ifndef MDC_C_OBJECT_USHORT_OBJECT_H_
#define MDC_C_OBJECT_USHORT_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT unsigned short* Mdc_UShort_InitDefault(unsigned short* shrt);

DLLEXPORT unsigned short* Mdc_UShort_InitFromValue(
    unsigned short* shrt,
    unsigned short value
);

DLLEXPORT unsigned short* Mdc_UShort_InitCopy(
    unsigned short* dest,
    const unsigned short* src
);

DLLEXPORT unsigned short* Mdc_UShort_InitMove(
    unsigned short* dest,
    unsigned short* src
);

DLLEXPORT void Mdc_UShort_Deinit(unsigned short* shrt);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_UShort_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT unsigned short* Mdc_UShort_AssignCopy(
    unsigned short* dest,
    const unsigned short* src
);

DLLEXPORT unsigned short* Mdc_UShort_AssignMove(
    unsigned short* dest,
    unsigned short* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT unsigned short* Mdc_UShort_PreIncrement(
    unsigned short* shrt
);

DLLEXPORT unsigned short* Mdc_UShort_PreDecrement(
    unsigned short* shrt
);

DLLEXPORT unsigned short* Mdc_UShort_PostIncrement(
    unsigned short* out,
    unsigned short* in
);

DLLEXPORT unsigned short* Mdc_UShort_PostDecrement(
    unsigned short* out,
    unsigned short* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT unsigned short* Mdc_UShort_Add(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_Subtract(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_Multiply(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_Divide(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_Modulo(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseNot(
    unsigned short* out,
    const unsigned short* in
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseAnd(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseOr(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseXor(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseLeftShift(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

DLLEXPORT unsigned short* Mdc_UShort_BitwiseRightShift(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_UShort_Equal(
    const unsigned short* short1,
    const unsigned short* short2
);

DLLEXPORT bool Mdc_UShort_EqualValue(
    unsigned short value1,
    unsigned short value2
);

DLLEXPORT int Mdc_UShort_Compare(
    const unsigned short* short1,
    const unsigned short* short2
);

DLLEXPORT int Mdc_UShort_CompareValue(
    unsigned short value1,
    unsigned short value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_UShort_Hash(const unsigned short* shrt);

DLLEXPORT size_t Mdc_UShort_HashValue(unsigned short shrt);

DLLEXPORT void Mdc_UShort_Swap(
    unsigned short* short1,
    unsigned short* short2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_USHORT_OBJECT_H_ */
