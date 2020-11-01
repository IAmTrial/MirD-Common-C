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

#ifndef MDC_C_OBJECT_LONG_OBJECT_H_
#define MDC_C_OBJECT_LONG_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT long* Mdc_Long_InitDefault(long* lng);

DLLEXPORT long* Mdc_Long_InitFromValue(
    long* lng,
    long value
);

DLLEXPORT long* Mdc_Long_InitCopy(
    long* dest,
    const long* src
);

DLLEXPORT long* Mdc_Long_InitMove(
    long* dest,
    long* src
);

DLLEXPORT void Mdc_Long_Deinit(long* lng);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Long_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT long* Mdc_Long_AssignCopy(
    long* dest,
    const long* src
);

DLLEXPORT long* Mdc_Long_AssignMove(
    long* dest,
    long* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT long* Mdc_Long_PreIncrement(
    long* lng
);

DLLEXPORT long* Mdc_Long_PreDecrement(
    long* lng
);

DLLEXPORT long* Mdc_Long_PostIncrement(
    long* out,
    long* in
);

DLLEXPORT long* Mdc_Long_PostDecrement(
    long* out,
    long* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT long* Mdc_Long_Add(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_Subtract(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_Multiply(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_Divide(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_Modulo(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_BitwiseNot(
    long* out,
    const long* in
);

DLLEXPORT long* Mdc_Long_BitwiseAnd(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_BitwiseOr(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_BitwiseXor(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_BitwiseLeftShift(
    long* out,
    const long* op1,
    const long* op2
);

DLLEXPORT long* Mdc_Long_BitwiseRightShift(
    long* out,
    const long* op1,
    const long* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Long_Equal(
    const long* long1,
    const long* long2
);

DLLEXPORT bool Mdc_Long_EqualValue(
    const long* lng,
    long value
);

DLLEXPORT int Mdc_Long_Compare(
    const long* long1,
    const long* long2
);

DLLEXPORT int Mdc_Long_CompareValue(
    const long* lng,
    long value
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_Long_Hash(const long* lng);

DLLEXPORT void Mdc_Long_Swap(
    long* long1,
    long* long2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_LONG_OBJECT_H_ */
