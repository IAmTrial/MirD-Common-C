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

DLLEXPORT signed char* Mdc_SChar_InitDefault(signed char* ch);

DLLEXPORT signed char* Mdc_SChar_InitFromValue(
    signed char* ch,
    signed char value
);

DLLEXPORT signed char* Mdc_SChar_InitCopy(
    signed char* dest,
    const signed char* src
);

DLLEXPORT signed char* Mdc_SChar_InitMove(
    signed char* dest,
    signed char* src
);

DLLEXPORT void Mdc_SChar_Deinit(signed char* ch);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_SChar_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT signed char* Mdc_SChar_AssignCopy(
    signed char* dest,
    const signed char* src
);

DLLEXPORT signed char* Mdc_SChar_AssignMove(
    signed char* dest,
    signed char* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT signed char* Mdc_SChar_PreIncrement(
    signed char* ch
);

DLLEXPORT signed char* Mdc_SChar_PreDecrement(
    signed char* ch
);

DLLEXPORT signed char* Mdc_SChar_PostIncrement(
    signed char* out,
    signed char* in
);

DLLEXPORT signed char* Mdc_SChar_PostDecrement(
    signed char* out,
    signed char* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT signed char* Mdc_SChar_Add(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_Subtract(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_Multiply(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_Divide(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_Modulo(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_BitwiseNot(
    signed char* out,
    const signed char* in
);

DLLEXPORT signed char* Mdc_SChar_BitwiseAnd(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_BitwiseOr(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_BitwiseXor(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_BitwiseLeftShift(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

DLLEXPORT signed char* Mdc_SChar_BitwiseRightShift(
    signed char* out,
    const signed char* op1,
    const signed char* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_SChar_Equal(
    const signed char* ch1,
    const signed char* ch2
);

DLLEXPORT bool Mdc_SChar_EqualValue(
    signed char value1,
    signed char value2
);

DLLEXPORT int Mdc_SChar_Compare(
    const signed char* ch1,
    const signed char* ch2
);

DLLEXPORT int Mdc_SChar_CompareValue(
    signed char value1,
    signed char value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_SChar_Hash(const signed char* ch);

DLLEXPORT size_t Mdc_SChar_HashValue(signed char ch);

DLLEXPORT void Mdc_SChar_Swap(
    signed char* ch1,
    signed char* ch2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_SHORT_OBJECT_H_ */
