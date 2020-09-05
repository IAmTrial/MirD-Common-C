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

struct Mdc_Integer {
  int value_;
};

/**
 * Initialization/deinitialization
 */

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Init(
    struct Mdc_Integer* integer
);

DLLEXPORT void Mdc_Integer_Deinit(struct Mdc_Integer* integer);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Integer_GetObjectMetadata(void);

/**
 * Assignment functions
 */

DLLEXPORT struct Mdc_Integer* Mdc_Integer_AssignDefault(
    struct Mdc_Integer* integer
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_AssignFromValue(
    struct Mdc_Integer* integer,
    int value
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_AssignCopy(
    struct Mdc_Integer* dest,
    const struct Mdc_Integer* src
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_AssignMove(
    struct Mdc_Integer* dest,
    struct Mdc_Integer* src
);

/**
 * Increment/decrement operators
 */

DLLEXPORT struct Mdc_Integer* Mdc_Integer_PreIncrement(
    struct Mdc_Integer* integer
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_PreDecrement(
    struct Mdc_Integer* integer
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_PostIncrement(
    struct Mdc_Integer* integer_out,
    struct Mdc_Integer* integer_in
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_PostDecrement(
    struct Mdc_Integer* integer_out,
    struct Mdc_Integer* integer_in
);

/**
 * Arithmetic operators
 */

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Add(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Subtract(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Multiply(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Divide(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_Modulo(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseNot(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseAnd(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseOr(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseXor(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseLeftShift(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

DLLEXPORT struct Mdc_Integer* Mdc_Integer_BitwiseRightShift(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Integer_Equal(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
);

DLLEXPORT bool Mdc_Integer_EqualValue(
    const struct Mdc_Integer* integer,
    int value
);

DLLEXPORT int Mdc_Integer_Compare(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
);

DLLEXPORT int Mdc_Integer_CompareValue(
    const struct Mdc_Integer* integer,
    int value
);

/**
 * Etc. functions
 */

DLLEXPORT size_t Mdc_Integer_Hash(const struct Mdc_Integer* integer);

DLLEXPORT void Mdc_Integer_Swap(
    struct Mdc_Integer* integer1,
    struct Mdc_Integer* integer2
);

DLLEXPORT int Mdc_Integer_GetValue(const struct Mdc_Integer* integer);

DLLEXPORT void Mdc_Integer_SetValue(struct Mdc_Integer* integer, int value);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_INTEGER_OBJECT_H_ */
