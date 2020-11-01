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

#ifndef MDC_C_OBJECT_INTEGER_OBJECT_H_
#define MDC_C_OBJECT_INTEGER_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT int* Mdc_Integer_InitDefault(int* integer);

DLLEXPORT int* Mdc_Integer_InitFromValue(
    int* integer,
    int value
);

DLLEXPORT int* Mdc_Integer_InitCopy(
    int* dest,
    const int* src
);

DLLEXPORT int* Mdc_Integer_InitMove(
    int* dest,
    int* src
);

DLLEXPORT void Mdc_Integer_Deinit(int* integer);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Integer_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT int* Mdc_Integer_AssignCopy(
    int* dest,
    const int* src
);

DLLEXPORT int* Mdc_Integer_AssignMove(
    int* dest,
    int* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT int* Mdc_Integer_PreIncrement(
    int* integer
);

DLLEXPORT int* Mdc_Integer_PreDecrement(
    int* integer
);

DLLEXPORT int* Mdc_Integer_PostIncrement(
    int* out,
    int* in
);

DLLEXPORT int* Mdc_Integer_PostDecrement(
    int* out,
    int* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT int* Mdc_Integer_Add(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_Subtract(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_Multiply(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_Divide(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_Modulo(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_BitwiseNot(
    int* out,
    const int* in
);

DLLEXPORT int* Mdc_Integer_BitwiseAnd(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_BitwiseOr(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_BitwiseXor(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_BitwiseLeftShift(
    int* out,
    const int* op1,
    const int* op2
);

DLLEXPORT int* Mdc_Integer_BitwiseRightShift(
    int* out,
    const int* op1,
    const int* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Integer_Equal(
    const int* integer1,
    const int* integer2
);

DLLEXPORT bool Mdc_Integer_EqualValue(
    int value1,
    int value2
);

DLLEXPORT int Mdc_Integer_Compare(
    const int* integer1,
    const int* integer2
);

DLLEXPORT int Mdc_Integer_CompareValue(
    int value1,
    int value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_Integer_Hash(const int* integer);

DLLEXPORT void Mdc_Integer_Swap(
    int* integer1,
    int* integer2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_INTEGER_OBJECT_H_ */
