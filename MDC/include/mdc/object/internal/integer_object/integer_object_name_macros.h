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

#ifndef MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_NAME_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_NAME_MACROS_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define Mdc_Integer_InitDefault(T_IntT) \
    Mdc_Object_InitDefault(T_IntT)

#define Mdc_Integer_InitFromValue(T_IntT) \
    Mdc_Object_InitFrom_1(T_IntT, MDC_T(T_IntT))

#define Mdc_Integer_InitCopy(T_IntT) \
    Mdc_Object_InitCopy(T_IntT)

#define Mdc_Integer_InitMove(T_IntT) \
    Mdc_Object_InitMove(T_IntT)

#define Mdc_Integer_Deinit(T_IntT) \
    Mdc_Object_Deinit(T_IntT)

/**
 * Assignment
 */

#define Mdc_Integer_AssignCopy(T_IntT) \
    Mdc_Object_AssignCopy(T_IntT)

#define Mdc_Integer_AssignMove(T_IntT) \
    Mdc_Object_AssignMove(T_IntT)

#define Mdc_Integer_AssignAdd(T_IntT) \
    Mdc_Object_DefaultAssignAdd(T_IntT)

#define Mdc_Integer_AssignSubtract(T_IntT) \
    Mdc_Object_DefaultAssignSubtract(T_IntT)

#define Mdc_Integer_AssignMultiply(T_IntT) \
    Mdc_Object_DefaultAssignMultiply(T_IntT)

#define Mdc_Integer_AssignDivide(T_IntT) \
    Mdc_Object_DefaultAssignDivide(T_IntT)

#define Mdc_Integer_AssignModulo(T_IntT) \
    Mdc_Object_DefaultAssignModulo(T_IntT)

#define Mdc_Integer_AssignBitwiseAnd(T_IntT) \
    Mdc_Object_DefaultAssignBitwiseAnd(T_IntT)

#define Mdc_Integer_AssignBitwiseOr(T_IntT) \
    Mdc_Object_DefaultAssignBitwiseOr(T_IntT)

#define Mdc_Integer_AssignBitwiseXor(T_IntT) \
    Mdc_Object_DefaultAssignBitwiseXor(T_IntT)

#define Mdc_Integer_AssignBitwiseLeftShift(T_IntT) \
    Mdc_Object_DefaultAssignBitwiseLeftShift(T_IntT)

#define Mdc_Integer_AssignBitwiseRightShift(T_IntT) \
    Mdc_Object_DefaultAssignBitwiseRightShift(T_IntT)

/**
 * Increment / Decrement
 */

#define Mdc_Integer_PreIncrement(T_IntT) \
    Mdc_Object_PreIncrement(T_IntT)

#define Mdc_Integer_PreDecrement(T_IntT) \
    Mdc_Object_PreDecrement(T_IntT)

#define Mdc_Integer_PostIncrement(T_IntT) \
    Mdc_Object_PostIncrement(T_IntT)

#define Mdc_Integer_PostDecrement(T_IntT) \
    Mdc_Object_PostDecrement(T_IntT)

/**
 * Arithmetic
 */

#define Mdc_Integer_UnaryPlus(T_IntT) \
    Mdc_Object_UnaryPlus(T_IntT)

#define Mdc_Integer_UnaryPlusConst(T_IntT) \
    Mdc_Object_UnaryPlusConst(T_IntT)

#define Mdc_Integer_UnaryMinus(T_IntT) \
    Mdc_Object_UnaryMinus(T_IntT)

#define Mdc_Integer_UnaryMinusConst(T_IntT) \
    Mdc_Object_UnaryMinusConst(T_IntT)

#define Mdc_Integer_Add(T_IntT) \
    Mdc_Object_DefaultAdd(T_IntT, T_IntT)

#define Mdc_Integer_Subtract(T_IntT) \
    Mdc_Object_DefaultSubtract(T_IntT, T_IntT)

#define Mdc_Integer_Multiply(T_IntT) \
    Mdc_Object_DefaultMultiply(T_IntT, T_IntT)

#define Mdc_Integer_Divide(T_IntT) \
    Mdc_Object_DefaultDivide(T_IntT, T_IntT)

#define Mdc_Integer_Modulo(T_IntT) \
    Mdc_Object_DefaultModulo(T_IntT, T_IntT)

#define Mdc_Integer_BitwiseNot(T_IntT) \
    Mdc_Object_BitwiseNot(T_IntT)

#define Mdc_Integer_BitwiseNotConst(T_IntT) \
    Mdc_Object_BitwiseNotConst(T_IntT)

#define Mdc_Integer_BitwiseAnd(T_IntT) \
    Mdc_Object_DefaultBitwiseAnd(T_IntT, T_IntT)

#define Mdc_Integer_BitwiseOr(T_IntT) \
    Mdc_Object_DefaultBitwiseOr(T_IntT, T_IntT)

#define Mdc_Integer_BitwiseXor(T_IntT) \
    Mdc_Object_DefaultBitwiseXor(T_IntT, T_IntT)

#define Mdc_Integer_BitwiseLeftShift(T_IntT) \
    Mdc_Object_BitwiseLeftShift(T_IntT, T_IntT)

#define Mdc_Integer_BitwiseRightShift(T_IntT) \
    Mdc_Object_BitwiseRightShift(T_IntT, T_IntT)

/**
 * Logical
 */

#define Mdc_Integer_LogicalNot(T_IntT) \
    Mdc_Object_LogicalNot(T_IntT)

#define Mdc_Integer_LogicalNotConst(T_IntT) \
    Mdc_Object_LogicalNotConst(T_IntT)

#define Mdc_Integer_LogicalAnd(T_IntT) \
    Mdc_Object_DefaultLogicalAnd(T_IntT, T_IntT)

#define Mdc_Integer_LogicalOr(T_IntT) \
    Mdc_Object_DefaultLogicalOr(T_IntT, T_IntT)

/**
 * Comparison
 */

#define Mdc_Integer_Equal(T_IntT) \
    Mdc_Object_DefaultEqual(T_IntT, T_IntT)

#define Mdc_Integer_Compare(T_IntT) \
    Mdc_Object_DefaultCompare(T_IntT, T_IntT)

/**
 * General Functions
 */

#define Mdc_Integer_Swap(T_IntT) \
    Mdc_Object_Swap(T_IntT)

#endif /* MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_NAME_MACROS_H_ */
