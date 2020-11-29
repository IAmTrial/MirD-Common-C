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

#ifndef MDC_C_OBJECT_INTERNAL_OBJECT_NAME_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_OBJECT_NAME_MACROS_H_

#include "../../macro/concat_macro.h"
#include "../../macro/template_macro.h"

#define Mdc_Object_Prefix(T) MDC_MACRO_CONCAT(T, _)

/**
 * Initialize / Deinitialize
 */

#define Mdc_Object_InitDefault(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitDefault)

#define Mdc_Object_InitFrom_0(T) \
    Mdc_Object_InitDefault(T)

#define Mdc_Object_InitFrom_1(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_InitFrom_2(T, A1, A2) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_InitFrom_3(T, A1, A2, A3) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_3(A1, A2, A3) \
    )

#define Mdc_Object_InitFrom_4(T, A1, A2, A3, A4) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_4(A1, A2, A3, A4) \
    )

#define Mdc_Object_InitFrom_5(T, A1, A2, A3, A4, A5) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_5(A1, A2, A3, A4, A5) \
    )

#define Mdc_Object_InitFrom_6(T, A1, A2, A3, A4, A5, A6) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_6(A1, A2, A3, A4, A5, A6) \
    )

#define Mdc_Object_InitFrom_7(T, A1, A2, A3, A4, A5, A6, A7) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_7(A1, A2, A3, A4, A5, A6, A7) \
    )

#define Mdc_Object_InitFrom_8(T, A1, A2, A3, A4, A5, A6, A7, A8) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_8(A1, A2, A3, A4, A5, A6, A7, A8) \
    )

#define Mdc_Object_InitFrom_9(T, A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), InitFrom), \
        MDC_MACRO_TEMPLATE_9(A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    )

#define Mdc_Object_InitFrom(N, AL) \
    MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(Mdc_Object_InitFrom_, N), AL)

#define Mdc_Object_InitCopy(T) \
    Mdc_Object_InitFrom_1(T, MDC_T_PC(T))

#define Mdc_Object_InitMove(T) \
    Mdc_Object_InitFrom_1(T, MDC_T_P(T))

#define Mdc_Object_Deinit(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), Deinit)

/**
 * Assignment
 */

#define Mdc_Object_AssignFrom(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignFrom), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignCopy(T) \
    Mdc_Object_AssignFrom(T, MDC_T_PC(T))

#define Mdc_Object_AssignMove(T) \
    Mdc_Object_AssignFrom(T, MDC_T_P(T))

#define Mdc_Object_AssignAdd(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignAdd), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignAdd(T) \
    Mdc_Object_AssignAdd(T, MDC_T_PC(T))

#define Mdc_Object_AssignAddConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignAddConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignSubtract(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignSubtract), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignSubtract(T) \
    Mdc_Object_AssignSubtract(T, MDC_T_PC(T))

#define Mdc_Object_AssignSubtractConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignSubtractConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignMultiply(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignMultiply), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignMultiply(T) \
    Mdc_Object_AssignMultiply(T, MDC_T_PC(T))

#define Mdc_Object_AssignMultiplyConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignMultiplyConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignDivide(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignDivide), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignDivide(T) \
    Mdc_Object_AssignDivide(T, MDC_T_PC(T))

#define Mdc_Object_AssignDivideConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignDivideConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignModulo(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignModulus), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignModulo(T) \
    Mdc_Object_AssignModulo(T, MDC_T_PC(T))

#define Mdc_Object_AssignModuloConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignModulusConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignBitwiseAnd(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseAnd), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignBitwiseAnd(T) \
    Mdc_Object_AssignBitwiseAnd(T, MDC_T_PC(T))

#define Mdc_Object_AssignBitwiseAndConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseAndConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignBitwiseOr(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseOr), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignBitwiseOr(T) \
    Mdc_Object_AssignBitwiseOr(T, MDC_T_PC(T))

#define Mdc_Object_AssignBitwiseOrConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseOrConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignBitwiseXor(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseXor), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignBitwiseXor(T) \
    Mdc_Object_AssignBitwiseXor(T, MDC_T_PC(T))

#define Mdc_Object_AssignBitwiseXorConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseXorConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignBitwiseLeftShift(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseLeftShift), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignBitwiseLeftShift(T) \
    Mdc_Object_AssignBitwiseLeftShift(T, MDC_T_PC(T))

#define Mdc_Object_AssignBitwiseLeftShiftConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT( \
            Mdc_Object_Prefix(T), \
            AssignBitwiseLeftShiftConst \
        ), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_AssignBitwiseRightShift(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AssignBitwiseRightShift), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_DefaultAssignBitwiseRightShift(T) \
    Mdc_Object_AssignBitwiseRightShift(T, MDC_T_PC(T))

#define Mdc_Object_AssignBitwiseRightShiftConst(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT( \
            Mdc_Object_Prefix(T), \
            AssignBitwiseRightShiftConst \
        ), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

/**
 * Increment / Decrement
 */

#define Mdc_Object_PreIncrement(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PreIncrement)

#define Mdc_Object_PreIncrementConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PreIncrementConst)

#define Mdc_Object_PreDecrement(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PreDecrement)

#define Mdc_Object_PreDecrementConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PreDecrementConst)

#define Mdc_Object_PostIncrement(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PostIncrement)

#define Mdc_Object_PostIncrementConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PostIncrementConst)

#define Mdc_Object_PostDecrement(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PostDecrement)

#define Mdc_Object_PostDecrementConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), PostDecrementConst)

/**
 * Arithmetic
 */

#define Mdc_Object_UnaryPlus(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), UnaryPlus)

#define Mdc_Object_UnaryPlusConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), UnaryPlusConst)

#define Mdc_Object_UnaryMinus(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), UnaryMinus)

#define Mdc_Object_UnaryMinusConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), UnaryMinusConst)

#define Mdc_Object_Add(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Add), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultAdd(TA1, TA2) \
    Mdc_Object_Add(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_Subtract(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Subtract), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultSubtract(TA1, TA2) \
    Mdc_Object_Subtract(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_Multiply(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Multiply), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultMultiply(TA1, TA2) \
    Mdc_Object_Multiply(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_Divide(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Divide), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultDivide(TA1, TA2) \
    Mdc_Object_Divide(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_Modulo(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Modulo), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultModulo(TA1, TA2) \
    Mdc_Object_Modulo(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_BitwiseNot(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), BitwiseNot)

#define Mdc_Object_BitwiseNotConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), BitwiseNotConst)

#define Mdc_Object_BitwiseAnd(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(BitwiseAnd), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultBitwiseAnd(TA1, TA2) \
    Mdc_Object_BitwiseAnd(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_BitwiseOr(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(BitwiseOr), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultBitwiseOr(TA1, TA2) \
    Mdc_Object_BitwiseOr(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_BitwiseXor(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(BitwiseXor), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultBitwiseXor(TA1, TA2) \
    Mdc_Object_BitwiseXor(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_BitwiseLeftShift(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(BitwiseLeftShift), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultBitwiseLeftShift(TA1, TA2) \
    Mdc_Object_BitwiseLeftShift(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_BitwiseRightShift(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(BitwiseRightShift), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultBitwiseRightShift(TA1, TA2) \
    Mdc_Object_BitwiseRightShift(MDC_T_PC(TA1), MDC_T_PC(TA2))

/**
 * Logical
 */

#define Mdc_Object_LogicalNot(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), LogicalNot)

#define Mdc_Object_LogicalNotConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), LogicalNotConst)

#define Mdc_Object_LogicalAnd(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(LogicalAnd), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultLogicalAnd(TA1, TA2) \
    Mdc_Object_LogicalAnd(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_LogicalOr(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(LogicalOr), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultLogicalOr(TA1, TA2) \
    Mdc_Object_LogicalOr(MDC_T_PC(TA1), MDC_T_PC(TA2))

/**
 * Comparison
 */

#define Mdc_Object_Equal(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Equal), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultEqual(TA1, TA2) \
    Mdc_Object_Equal(MDC_T_PC(TA1), MDC_T_PC(TA2))

#define Mdc_Object_Compare(A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(Compare), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_DefaultCompare(TA1, TA2) \
    Mdc_Object_Compare(MDC_T_PC(TA1), MDC_T_PC(TA2))

/**
 * Member access
 */

#define Mdc_Object_Subscript(T, A1) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), Subscript), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_SubscriptConst(T, K) \
    MDC_MACRO_CONCAT( \
        MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), SubscriptConst), \
        MDC_MACRO_TEMPLATE_1(K) \
    )

#define Mdc_Object_Indirect(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), Indirect)

#define Mdc_Object_IndirectConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), IndirectConst)

#define Mdc_Object_AddressOf(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AddressOf)

#define Mdc_Object_AddressOfConst(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), AddressOfConst)

/**
 * Other
 */

#define Mdc_Object_Call_0(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), Call)

#define Mdc_Object_CallConst_0(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), CallConst)

#define Mdc_Object_Call_1(T, A1) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_CallConst_1(T, A1) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Object_Call_2(T, A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_CallConst_2(T, A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Object_Call_3(T, A1, A2, A3) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_3(A1, A2, A3) \
    )

#define Mdc_Object_CallConst_3(T, A1, A2, A3) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_3(A1, A2, A3) \
    )

#define Mdc_Object_Call_4(T, A1, A2, A3, A4) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_4(A1, A2, A3, A4) \
    )

#define Mdc_Object_CallConst_4(T, A1, A2, A3, A4) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_4(A1, A2, A3, A4) \
    )

#define Mdc_Object_Call_5(T, A1, A2, A3, A4, A5) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_5(A1, A2, A3, A4, A5) \
    )

#define Mdc_Object_CallConst_5(T, A1, A2, A3, A4, A5) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_5(A1, A2, A3, A4, A5) \
    )

#define Mdc_Object_Call_6(T, A1, A2, A3, A4, A5, A6) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_6(A1, A2, A3, A4, A5, A6) \
    )

#define Mdc_Object_CallConst_6(T, A1, A2, A3, A4, A5, A6) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_6(A1, A2, A3, A4, A5, A6) \
    )

#define Mdc_Object_Call_7(T, A1, A2, A3, A4, A5, A6, A7) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_7(A1, A2, A3, A4, A5, A6, A7) \
    )

#define Mdc_Object_CallConst_7(T, A1, A2, A3, A4, A5, A6, A7) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_7(A1, A2, A3, A4, A5, A6, A7) \
    )

#define Mdc_Object_Call_8(T, A1, A2, A3, A4, A5, A6, A7, A8) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_8(A1, A2, A3, A4, A5, A6, A7, A8) \
    )

#define Mdc_Object_CallConst_8(T, A1, A2, A3, A4, A5, A6, A7, A8) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_8(A1, A2, A3, A4, A5, A6, A7, A8) \
    )

#define Mdc_Object_Call_9(T, A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), Call), \
        MDC_MACRO_TEMPLATE_9(A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    )

#define Mdc_Object_CallConst_9(T, A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Prefix(T), CallConst), \
        MDC_MACRO_TEMPLATE_9(A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    )

/**
 * General Functions
 */

#define Mdc_Object_Swap(T) \
    MDC_MACRO_CONCAT(Mdc_Object_Prefix(T), Swap)

#endif /* MDC_C_OBJECT_INTERNAL_OBJECT_NAME_MACROS_H_ */
