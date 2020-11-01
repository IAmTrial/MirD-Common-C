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

#ifndef MDC_C_OBJECT_UCHAR_OBJECT_H_
#define MDC_C_OBJECT_UCHAR_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT unsigned char* Mdc_UChar_InitDefault(unsigned char* ch);

DLLEXPORT unsigned char* Mdc_UChar_InitFromValue(
    unsigned char* ch,
    unsigned char value
);

DLLEXPORT unsigned char* Mdc_UChar_InitCopy(
    unsigned char* dest,
    const unsigned char* src
);

DLLEXPORT unsigned char* Mdc_UChar_InitMove(
    unsigned char* dest,
    unsigned char* src
);

DLLEXPORT void Mdc_UChar_Deinit(unsigned char* ch);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_UChar_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT unsigned char* Mdc_UChar_AssignCopy(
    unsigned char* dest,
    const unsigned char* src
);

DLLEXPORT unsigned char* Mdc_UChar_AssignMove(
    unsigned char* dest,
    unsigned char* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT unsigned char* Mdc_UChar_PreIncrement(
    unsigned char* ch
);

DLLEXPORT unsigned char* Mdc_UChar_PreDecrement(
    unsigned char* ch
);

DLLEXPORT unsigned char* Mdc_UChar_PostIncrement(
    unsigned char* out,
    unsigned char* in
);

DLLEXPORT unsigned char* Mdc_UChar_PostDecrement(
    unsigned char* out,
    unsigned char* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT unsigned char* Mdc_UChar_Add(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_Subtract(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_Multiply(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_Divide(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_Modulo(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseNot(
    unsigned char* out,
    const unsigned char* in
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseAnd(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseOr(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseXor(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseLeftShift(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

DLLEXPORT unsigned char* Mdc_UChar_BitwiseRightShift(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_UChar_Equal(
    const unsigned char* ch1,
    const unsigned char* ch2
);

DLLEXPORT bool Mdc_UChar_EqualValue(
    unsigned char value1,
    unsigned char value2
);

DLLEXPORT int Mdc_UChar_Compare(
    const unsigned char* ch1,
    const unsigned char* ch2
);

DLLEXPORT int Mdc_UChar_CompareValue(
    unsigned char value1,
    unsigned char value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_UChar_Hash(const unsigned char* ch);

DLLEXPORT size_t Mdc_UChar_HashValue(unsigned char ch);

DLLEXPORT void Mdc_UChar_Swap(
    unsigned char* ch1,
    unsigned char* ch2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_UCHAR_OBJECT_H_ */
