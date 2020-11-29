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

#ifndef MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_NAME_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_NAME_MACROS_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define Mdc_Floating_InitDefault(T_FloatingT) \
    Mdc_Object_InitDefault(T_FloatingT)

#define Mdc_Floating_InitFromValue(T_FloatingT) \
    Mdc_Object_InitFrom_1(T_FloatingT, MDC_T(T_FloatingT))

#define Mdc_Floating_InitCopy(T_FloatingT) \
    Mdc_Object_InitCopy(T_FloatingT)

#define Mdc_Floating_InitMove(T_FloatingT) \
    Mdc_Object_InitMove(T_FloatingT)

#define Mdc_Floating_Deinit(T_FloatingT) \
    Mdc_Object_Deinit(T_FloatingT)

/**
 * Assignment
 */

#define Mdc_Floating_AssignCopy(T_FloatingT) \
    Mdc_Object_AssignCopy(T_FloatingT)

#define Mdc_Floating_AssignMove(T_FloatingT) \
    Mdc_Object_AssignMove(T_FloatingT)

#define Mdc_Floating_AssignAdd(T_FloatingT) \
    Mdc_Object_DefaultAssignAdd(T_FloatingT)

#define Mdc_Floating_AssignSubtract(T_FloatingT) \
    Mdc_Object_DefaultAssignSubtract(T_FloatingT)

#define Mdc_Floating_AssignMultiply(T_FloatingT) \
    Mdc_Object_DefaultAssignMultiply(T_FloatingT)

#define Mdc_Floating_AssignDivide(T_FloatingT) \
    Mdc_Object_DefaultAssignDivide(T_FloatingT)

/**
 * Increment / Decrement
 */

#define Mdc_Floating_PreIncrement(T_FloatingT) \
    Mdc_Object_PreIncrement(T_FloatingT)

#define Mdc_Floating_PreDecrement(T_FloatingT) \
    Mdc_Object_PreDecrement(T_FloatingT)

#define Mdc_Floating_PostIncrement(T_FloatingT) \
    Mdc_Object_PostIncrement(T_FloatingT)

#define Mdc_Floating_PostDecrement(T_FloatingT) \
    Mdc_Object_PostDecrement(T_FloatingT)

/**
 * Arithmetic
 */

#define Mdc_Floating_UnaryPlus(T_FloatingT) \
    Mdc_Object_UnaryPlus(T_FloatingT)

#define Mdc_Floating_UnaryPlusConst(T_FloatingT) \
    Mdc_Object_UnaryPlusConst(T_FloatingT)

#define Mdc_Floating_UnaryMinus(T_FloatingT) \
    Mdc_Object_UnaryMinus(T_FloatingT)

#define Mdc_Floating_UnaryMinusConst(T_FloatingT) \
    Mdc_Object_UnaryMinusConst(T_FloatingT)

#define Mdc_Floating_Add(T_FloatingT) \
    Mdc_Object_DefaultAdd(T_FloatingT, T_FloatingT)

#define Mdc_Floating_Subtract(T_FloatingT) \
    Mdc_Object_DefaultSubtract(T_FloatingT, T_FloatingT)

#define Mdc_Floating_Multiply(T_FloatingT) \
    Mdc_Object_DefaultMultiply(T_FloatingT, T_FloatingT)

#define Mdc_Floating_Divide(T_FloatingT) \
    Mdc_Object_DefaultDivide(T_FloatingT, T_FloatingT)

/**
 * Logical
 */

#define Mdc_Floating_LogicalNot(T_FloatingT) \
    Mdc_Object_LogicalNot(T_FloatingT)

#define Mdc_Floating_LogicalNotConst(T_FloatingT) \
    Mdc_Object_LogicalNotConst(T_FloatingT)

#define Mdc_Floating_LogicalAnd(T_FloatingT) \
    Mdc_Object_DefaultLogicalAnd(T_FloatingT, T_FloatingT)

#define Mdc_Floating_LogicalOr(T_FloatingT) \
    Mdc_Object_DefaultLogicalOr(T_FloatingT, T_FloatingT)

/**
 * Comparison
 */

#define Mdc_Floating_Equal(T_FloatingT) \
    Mdc_Object_DefaultEqual(T_FloatingT, T_FloatingT)

#define Mdc_Floating_Compare(T_FloatingT) \
    Mdc_Object_DefaultCompare(T_FloatingT, T_FloatingT)

/**
 * General Functions
 */

#define Mdc_Floating_Swap(T_FloatingT) \
    Mdc_Object_Swap(T_FloatingT)

#endif /* MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_NAME_MACROS_H_ */
