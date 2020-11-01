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

#ifndef MDC_C_OBJECT_UINTEGER_OBJECT_H_
#define MDC_C_OBJECT_UINTEGER_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initialization/deinitialization
 */

DLLEXPORT unsigned int* Mdc_UInteger_InitDefault(unsigned int* integer);

DLLEXPORT unsigned int* Mdc_UInteger_InitFromValue(
    unsigned int* integer,
    unsigned int value
);

DLLEXPORT unsigned int* Mdc_UInteger_InitCopy(
    unsigned int* dest,
    const unsigned int* src
);

DLLEXPORT unsigned int* Mdc_UInteger_InitMove(
    unsigned int* dest,
    unsigned int* src
);

DLLEXPORT void Mdc_UInteger_Deinit(unsigned int* integer);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_UInteger_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT unsigned int* Mdc_UInteger_AssignCopy(
    unsigned int* dest,
    const unsigned int* src
);

DLLEXPORT unsigned int* Mdc_UInteger_AssignMove(
    unsigned int* dest,
    unsigned int* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT unsigned int* Mdc_UInteger_PreIncrement(
    unsigned int* integer
);

DLLEXPORT unsigned int* Mdc_UInteger_PreDecrement(
    unsigned int* integer
);

DLLEXPORT unsigned int* Mdc_UInteger_PostIncrement(
    unsigned int* out,
    unsigned int* in
);

DLLEXPORT unsigned int* Mdc_UInteger_PostDecrement(
    unsigned int* out,
    unsigned int* in
);

/**
 * Arithmetic operators
 */

DLLEXPORT unsigned int* Mdc_UInteger_Add(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_Subtract(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_Multiply(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_Divide(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_Modulo(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseNot(
    unsigned int* out,
    const unsigned int* in
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseAnd(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseOr(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseXor(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseLeftShift(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

DLLEXPORT unsigned int* Mdc_UInteger_BitwiseRightShift(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_UInteger_Equal(
    const unsigned int* integer1,
    const unsigned int* integer2
);

DLLEXPORT bool Mdc_UInteger_EqualValue(
    unsigned int value1,
    unsigned int value2
);

DLLEXPORT int Mdc_UInteger_Compare(
    const unsigned int* integer1,
    const unsigned int* integer2
);

DLLEXPORT int Mdc_UInteger_CompareValue(
    unsigned int value1,
    unsigned int value2
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_UInteger_Hash(const unsigned int* integer);

DLLEXPORT size_t Mdc_UInteger_HashValue(unsigned int integer);

DLLEXPORT void Mdc_UInteger_Swap(
    unsigned int* integer1,
    unsigned int* integer2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_UINTEGER_OBJECT_H_ */
