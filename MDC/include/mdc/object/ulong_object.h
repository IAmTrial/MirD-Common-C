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

#ifndef MDC_C_OBJECT_ULONG_OBJECT_H_
#define MDC_C_OBJECT_ULONG_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT unsigned long* Mdc_ULong_InitDefault(unsigned long* lng);

DLLEXPORT unsigned long* Mdc_ULong_InitFromValue(
    unsigned long* lng,
    unsigned long value
);

DLLEXPORT unsigned long* Mdc_ULong_InitCopy(
    unsigned long* dest,
    const unsigned long* src
);

DLLEXPORT unsigned long* Mdc_ULong_InitMove(
    unsigned long* dest,
    unsigned long* src
);

DLLEXPORT void Mdc_ULong_Deinit(unsigned long* lng);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_ULong_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT unsigned long* Mdc_ULong_AssignCopy(
    unsigned long* dest,
    const unsigned long* src
);

DLLEXPORT unsigned long* Mdc_ULong_AssignMove(
    unsigned long* dest,
    unsigned long* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT unsigned long* Mdc_ULong_PreIncrement(
    unsigned long* lng
);

DLLEXPORT unsigned long* Mdc_ULong_PreDecrement(
    unsigned long* lng
);

DLLEXPORT unsigned long* Mdc_ULong_PostIncrement(
    unsigned long* out,
    unsigned long* in
);

DLLEXPORT unsigned long* Mdc_ULong_PostDecrement(
    unsigned long* out,
    unsigned long* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT unsigned long* Mdc_ULong_Add(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_Subtract(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_Multiply(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_Divide(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_Modulo(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseNot(
    unsigned long* out,
    const unsigned long* in
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseAnd(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseOr(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseXor(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseLeftShift(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

DLLEXPORT unsigned long* Mdc_ULong_BitwiseRightShift(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_ULong_Equal(
    const unsigned long* long1,
    const unsigned long* long2
);

DLLEXPORT bool Mdc_ULong_EqualValue(
    unsigned long value1,
    unsigned long value2
);

DLLEXPORT int Mdc_ULong_Compare(
    const unsigned long* long1,
    const unsigned long* long2
);

DLLEXPORT int Mdc_ULong_CompareValue(
    unsigned long value1,
    unsigned long value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_ULong_Hash(const unsigned long* lng);

DLLEXPORT size_t Mdc_ULong_HashValue(unsigned long lng);

DLLEXPORT void Mdc_ULong_Swap(
    unsigned long* long1,
    unsigned long* long2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_ULONG_OBJECT_H_ */
