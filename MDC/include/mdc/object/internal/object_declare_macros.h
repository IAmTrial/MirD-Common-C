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

#ifndef MDC_C_OBJECT_INTERNAL_OBJECT_DECLARE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_OBJECT_DECLARE_MACROS_H_

#include <stddef.h>

#include "../../std/stdbool.h"
#include "object_name_macros.h"

/**
 * These macros are provided for reference purposes and are not
 * required in order to implement the interface used by MDC. However,
 * the use of these macros provide an additional safeguard by
 * declaring a conforming interface.
 */

#define MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR(func_name, R, A) \
    R func_name(A obj);

#define MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR_CONST(func_name, R, A) \
    R func_name(A obj);

#define MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR(func_name, R, A1, A2) \
    R func_name( \
        A1 op1, \
        A2 op2 \
    );

/**
 * Initialize / Deinitialize
 */

#define MDC_DECLARE_OBJECT_INIT_DEFAULT(T) \
    MDC_T(T) Mdc_Object_InitDefault(T)(void);

#define MDC_DECLARE_OBJECT_INIT_FROM(T, A1) \
    MDC_T(T) Mdc_Object_InitFrom(T, A1)(A1 arg1);

#define MDC_DECLARE_OBJECT_DEFAULT_INIT_FROM(T, TA1) \
    MDC_DECLARE_OBJECT_INIT_FROM(T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_INIT_COPY(T) \
    MDC_T(T) Mdc_Object_InitCopy(T)(MDC_T_PC(T) src);

#define MDC_DECLARE_OBJECT_INIT_MOVE(T) \
    MDC_T(T) Mdc_Object_InitMove(T)(MDC_T_P(T) src);

#define MDC_DECLARE_OBJECT_DEINIT(T) \
    void Mdc_Object_Deinit(T)(MDC_T_P(T) obj);

/**
 * Assignment
 */

#define MDC_DECLARE_OBJECT_ASSIGN_FROM(R, T, A1) \
    R Mdc_Object_AssignFrom(T, A1)(MDC_T_P(T) obj, A1 arg1);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_FROM(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_FROM(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_COPY(T) \
    MDC_T_P(T) Mdc_Object_AssignCopy(T)(MDC_T_P(T) dest, MDC_T_PC(T) src);

#define MDC_DECLARE_OBJECT_ASSIGN_MOVE(T) \
    MDC_T_P(T) Mdc_Object_AssignMove(T)(MDC_T_P(T) dest, MDC_T_P(T) src);

#define MDC_DECLARE_OBJECT_ASSIGN_ADD(R, T, A1) \
    R Mdc_Object_AssignAdd(T, A1)(MDC_T_P(T) dest, A1 op);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_ADD(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_ADD(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_SUBTRACT(R, T, A1) \
    R Mdc_Object_AssignSubtract(T, A1)(MDC_T_P(T) dest, A1 op);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_SUBTRACT(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_SUBTRACT(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_MULTIPLY(R, T, A1) \
    R Mdc_Object_AssignMultiply(T, A1)(MDC_T_P(T) dest, A1 op);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_MULTIPLY(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_MULTIPLY(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_DIVIDE(R, T, A1) \
    R Mdc_Object_AssignDivide(T, A1)(MDC_T_P(T) dest, A1 op);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_DIVIDE(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_DIVIDE(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_MODULO(R, T, A1) \
    R Mdc_Object_AssignModulo(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_MODULO(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_MODULO(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_BITWISE_AND(R, T, A1) \
    R Mdc_Object_AssignBitwiseAnd(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_BITWISE_AND(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_BITWISE_AND(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_BITWISE_OR(R, T, A1) \
    R Mdc_Object_AssignBitwiseOr(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_BITWISE_OR(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_BITWISE_OR(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_BITWISE_XOR(R, T, A1) \
    R Mdc_Object_AssignBitwiseXor(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_BITWISE_XOR(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_BITWISE_XOR(MDC_T_P(T), T, MDC_T_PC(TA1))

#define MDC_DECLARE_OBJECT_ASSIGN_BITWISE_LEFT_SHIFT(R, T, A1) \
    R Mdc_Object_AssignBitwiseLeftShift(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_BITWISE_LEFT_SHIFT(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_BITWISE_LEFT_SHIFT( \
        MDC_T_P(T), \
        T, \
        MDC_T_PC(TA1) \
    )

#define MDC_DECLARE_OBJECT_ASSIGN_BITWISE_RIGHT_SHIFT(R, T, A1) \
    R Mdc_Object_AssignBitwiseRightShift(T, A1)(MDC_T_P(T) dest, A1 src);

#define MDC_DECLARE_OBJECT_DEFAULT_ASSIGN_BITWISE_RIGHT_SHIFT(T, TA1) \
    MDC_DECLARE_OBJECT_ASSIGN_BITWISE_RIGHT_SHIFT( \
        MDC_T_P(T), \
        T, \
        MDC_T_PC(TA1) \
    )

/**
 * Increment / Decrement
 */

#define MDC_DECLARE_OBJECT_PRE_INCREMENT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_PreIncrement(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_PRE_INCREMENT(T) \
    MDC_DECLARE_OBJECT_PRE_INCREMENT(MDC_T_P(T), T)

#define MDC_DECLARE_OBJECT_PRE_DECREMENT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_PreDecrement(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_PRE_DECREMENT(T) \
    MDC_DECLARE_OBJECT_PRE_DECREMENT(MDC_T_P(T), T)

#define MDC_DECLARE_OBJECT_POST_INCREMENT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_PostIncrement(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_POST_INCREMENT(T) \
    MDC_DECLARE_OBJECT_POST_INCREMENT(MDC_T(T), T)

#define MDC_DECLARE_OBJECT_POST_DECREMENT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_PostDecrement(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_POST_DECREMENT(T) \
    MDC_DECLARE_OBJECT_POST_DECREMENT(MDC_T(T), T)

/**
 * Arithmetic
 */

#define MDC_DECLARE_OBJECT_UNARY_PLUS(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_UnaryPlus(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_UNARY_PLUS_CONST(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_UnaryPlusConst(T), \
        R, \
        MDC_T_PC(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_UNARY_PLUS_CONST(T) \
    MDC_DECLARE_OBJECT_UNARY_PLUS_CONST(MDC_T(T), T)

#define MDC_DECLARE_OBJECT_UNARY_MINUS(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_UnaryMinus(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_UNARY_MINUS_CONST(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_UnaryMinusConst(T), \
        R, \
        MDC_T_PC(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_UNARY_MINUS_CONST(T) \
    MDC_DECLARE_OBJECT_UNARY_MINUS_CONST(MDC_T(T), T)

#define MDC_DECLARE_OBJECT_ADD(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Add(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_ADD(T1, T2) \
    MDC_DECLARE_OBJECT_ADD(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_SUBTRACT(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Subtract(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_SUBTRACT(T1, T2) \
    MDC_DECLARE_OBJECT_SUBTRACT(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_MULTIPLY(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Multiply(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_MULTIPLY(T1, T2) \
    MDC_DECLARE_OBJECT_MULTIPLY(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_DIVIDE(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Divide(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_DIVIDE(T1, T2) \
    MDC_DECLARE_OBJECT_DIVIDE(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_MODULO(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Modulo(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_MODULO(T1, T2) \
    MDC_DECLARE_OBJECT_MODULO(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_BITWISE_NOT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_BitwiseNot(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_BITWISE_NOT_CONST(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_BitwiseNotConst(T), \
        R, \
        MDC_T_PC(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_NOT_CONST(T) \
    MDC_DECLARE_OBJECT_BITWISE_NOT_CONST(MDC_T(T), T)

#define MDC_DECLARE_OBJECT_BITWISE_AND(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_BitwiseAnd(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_AND(T1, T2) \
    MDC_DECLARE_OBJECT_BITWISE_AND(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_BITWISE_OR(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_BitwiseOr(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_OR(T1, T2) \
    MDC_DECLARE_OBJECT_BITWISE_OR(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_BITWISE_XOR(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_BitwiseXor(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_XOR(T1, T2) \
    MDC_DECLARE_OBJECT_BITWISE_XOR(MDC_T(T1), MDC_T_PC(T1), MDC_T_PC(T2))

#define MDC_DECLARE_OBJECT_BITWISE_LEFT_SHIFT(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_BitwiseLeftShift(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_LEFT_SHIFT(T1, T2) \
    MDC_DECLARE_OBJECT_BITWISE_LEFT_SHIFT( \
        MDC_T(T1), \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

#define MDC_DECLARE_OBJECT_BITWISE_RIGHT_SHIFT(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_BitwiseRightShift(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_BITWISE_RIGHT_SHIFT(T1, T2) \
    MDC_DECLARE_OBJECT_BITWISE_RIGHT_SHIFT( \
        MDC_T(T1), \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

/**
 * Logical
 */

#define MDC_DECLARE_OBJECT_LOGICAL_NOT(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_LogicalNot(T), \
        R, \
        MDC_T_P(T) \
    )

#define MDC_DECLARE_OBJECT_LOGICAL_NOT_CONST(R, T) \
    MDC_INTERNAL_DECLARE_OBJECT_UNARY_OPERATOR( \
        Mdc_Object_LogicalNotConst(T), \
        R, \
        MDC_T_PC(T) \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_NOT_CONST(T) \
    MDC_DECLARE_OBJECT_LOGICAL_NOT_CONST(bool, T)

#define MDC_DECLARE_OBJECT_LOGICAL_AND(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_LogicalAnd(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_AND(T1, T2) \
    MDC_DECLARE_OBJECT_LOGICAL_AND( \
        bool, \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

#define MDC_DECLARE_OBJECT_LOGICAL_OR(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_LogicalOr(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_OR(T1, T2) \
    MDC_DECLARE_OBJECT_LOGICAL_OR( \
        bool, \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

/**
 * Comparison
 */

#define MDC_DECLARE_OBJECT_EQUAL(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Equal(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_EQUAL(T1, T2) \
    MDC_DECLARE_OBJECT_EQUAL( \
        bool, \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

#define MDC_DECLARE_OBJECT_COMPARE(R, A1, A2) \
    MDC_INTERNAL_DECLARE_OBJECT_BINARY_OPERATOR( \
        Mdc_Object_Compare(A1, A2), \
        R, \
        A1, \
        A2 \
    )

#define MDC_DECLARE_OBJECT_DEFAULT_COMPARE(T1, T2) \
    MDC_DECLARE_OBJECT_COMPARE( \
        int, \
        MDC_T_PC(T1), \
        MDC_T_PC(T2) \
    )

/**
 * Member access
 */

#define MDC_DECLARE_OBJECT_SUBSCRIPT(R, T, AK) \
    R Mdc_Object_Subscript(T, AK)(MDC_T_P(T) obj, AK key);

#define MDC_DECLARE_OBJECT_SUBSCRIPT_CONST(R, T, AK) \
    R Mdc_Object_SubscriptConst(T, AK)(MDC_T_PC(T) obj, AK key);

#define MDC_DECLARE_OBJECT_CALL_0(R, T) \
    R Mdc_Object_Call_0(T)(MDC_T_P(T) obj);

#define MDC_DECLARE_OBJECT_CALL_CONST_0(R, T) \
    R Mdc_Object_CallConst_0(T)(MDC_T_PC(T) obj);

#define MDC_DECLARE_OBJECT_CALL_1(R, T, A1) \
    R Mdc_Object_Call_1(T, A1)( \
        MDC_T_P(T) obj, \
        A1 arg1 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_1(R, T, A1) \
    R Mdc_Object_CallConst_1(T, A1)( \
        MDC_T_PC(T) obj, \
        A1 arg1 \
    );

#define MDC_DECLARE_OBJECT_CALL_2(R, T, A1, A2) \
    R Mdc_Object_Call_2(T, A1, A2)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_2(R, T, A1, A2) \
    R Mdc_Object_CallConst_2(T, A1, A2)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2 \
    );

#define MDC_DECLARE_OBJECT_CALL_3(R, T, A1, A2, A3) \
    R Mdc_Object_Call_3(T, A1, A2, A3)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_3(R, T, A1, A2, A3) \
    R Mdc_Object_CallConst_3(T, A1, A2, A3)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3 \
    );

#define MDC_DECLARE_OBJECT_CALL_4(R, T, A1, A2, A3, A4) \
    R Mdc_Object_Call_4(T, A1, A2, A3, A4)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_4(R, T, A1, A2, A3, A4) \
    R Mdc_Object_CallConst_4(T, A1, A2, A3, A4)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4 \
    );

#define MDC_DECLARE_OBJECT_CALL_5(R, T, A1, A2, A3, A4, A5) \
    R Mdc_Object_Call_5(T, A1, A2, A3, A4, A5)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_5(R, T, A1, A2, A3, A4, A5) \
    R Mdc_Object_CallConst_5(T, A1, A2, A3, A4, A5)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5 \
    );

#define MDC_DECLARE_OBJECT_CALL_6(R, T, A1, A2, A3, A4, A5, A6) \
    R Mdc_Object_Call_6(T, A1, A2, A3, A4, A5, A6)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_6(R, T, A1, A2, A3, A4, A5, A6) \
    R Mdc_Object_CallConst_6(T, A1, A2, A3, A4, A5, A6)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6 \
    );

#define MDC_DECLARE_OBJECT_CALL_7(R, T, A1, A2, A3, A4, A5, A6, A7) \
    R Mdc_Object_Call_7(T, A1, A2, A3, A4, A5, A6, A7)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_7(R, T, A1, A2, A3, A4, A5, A6, A7) \
    R Mdc_Object_CallConst_7(T, A1, A2, A3, A4, A5, A6, A7)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7 \
    );

#define MDC_DECLARE_OBJECT_CALL_8(R, T, A1, A2, A3, A4, A5, A6, A7, A8) \
    R Mdc_Object_Call_8(T, A1, A2, A3, A4, A5, A6, A7, A8)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_8(R, T, A1, A2, A3, A4, A5, A6, A7, A8) \
    R Mdc_Object_CallConst_8(T, A1, A2, A3, A4, A5, A6, A7, A8)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8 \
    );

#define MDC_DECLARE_OBJECT_CALL_9(R, T, A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    R Mdc_Object_Call_9(T, A1, A2, A3, A4, A5, A6, A7, A8, A9)( \
        MDC_T_P(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8, \
        A9 arg9 \
    );

#define MDC_DECLARE_OBJECT_CALL_CONST_9(R, T, A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    R Mdc_Object_CallConst_9(T, A1, A2, A3, A4, A5, A6, A7, A8, A9)( \
        MDC_T_PC(T) obj, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8, \
        A9 arg9 \
    );

/**
 * General Functions
 */

#define MDC_DECLARE_OBJECT_SWAP(T) \
    void Mdc_Object_Swap(T)(MDC_T_P(T) obj1, MDC_T_P(T) obj2);

#endif /* MDC_C_OBJECT_INTERNAL_OBJECT_DECLARE_MACROS_H_ */
