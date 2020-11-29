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

#ifndef MDC_C_OBJECT_INTERNAL_OBJECT_DEFINE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_OBJECT_DEFINE_MACROS_H_

#include "object_name_macros.h"

#define MDC_DEFINE_OBJECT_INIT_DEFAULT(T, init_default_func) \
    T Mdc_Object_InitDefault(T)(void) { \
      return init_default_func(); \
    }

#define MDC_DEFINE_OBJECT_INIT_COPY(T, init_copy_func) \
    T Mdc_Object_InitCopy(T)(MDC_T_PC(T) src) { \
      return init_copy_func(src); \
    }

#define MDC_DEFINE_OBJECT_INIT_MOVE(T, init_move_func) \
    T Mdc_Object_InitMove(T)(MDC_T_P(T) src) { \
      return init_move_func(src); \
    }

#define MDC_DEFINE_OBJECT_DEINIT(T, deinit_func) \
    void Mdc_Object_Deinit(T)(MDC_T_P(T) obj) { \
      deinit_func(obj); \
    }

#define MDC_DEFINE_OBJECT_ASSIGN_COPY(T, assign_copy_func) \
    MDC_T_P(T) Mdc_Object_AssignCopy(MDC_T_P(T) dest, const T* src) { \
      return assign_copy_func(dest, src); \
    }

#define MDC_DEFINE_OBJECT_ASSIGN_MOVE(T, assign_move_func) \
    MDC_T_P(T) Mdc_Object_AssignMove(MDC_T_P(T) dest, MDC_T_P(T) src) { \
      return assign_move_func(dest, src); \
    }

#define MDC_DEFINE_OBJECT_PRE_INCREMENT(T, pre_increment_func) \
    MDC_T_P(T) Mdc_Object_PreIncrement(MDC_T_P(T) obj) { \
      return pre_increment_func(obj); \
    }

#define MDC_DEFINE_OBJECT_PRE_DECREMENT(T, pre_decrement_func) \
    MDC_T_P(T) Mdc_Object_PreDecrement(MDC_T_P(T) obj) { \
      return pre_decrement_func(obj); \
    }

#define MDC_DEFINE_OBJECT_POST_INCREMENT(T, post_increment_func) \
    MDC_T_P(T) Mdc_Object_PostIncrement(MDC_T_P(T) dest, MDC_T_P(T) op) { \
      return post_increment_func(dest, op); \
    }

#define MDC_DEFINE_OBJECT_POST_DECREMENT(T, post_decrement_func) \
    T* Mdc_Object_PostDecrement(T* dest, T* op) { \
      return post_decrement_func(dest, op); \
    }

#define MDC_DEFINE_OBJECT_ADD(R, T1, T2, add_func) \
    R* Mdc_Object_Add(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return add_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_SUBTRACT(R, T1, T2, subtract_func) \
    R* Mdc_Object_Subtract(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return subtract_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_MULTIPLY(R, T1, T2, multiply_func) \
    R* Mdc_Object_Multiply(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return multiply_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_DIVIDE(R, T1, T2, divide_func) \
    R* Mdc_Object_Divide(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return divide_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_MODULO(R, T1, T2, modulo_func) \
    R* Mdc_Object_Modulo(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return modulo_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_NOT(R, T, bitwise_not_func) \
    R* Mdc_Object_BitwiseNot(T)(R* dest, const T* op) { \
      return bitwise_not_func(dest, op); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_AND(R, T1, T2, bitwise_and_func) \
    R* Mdc_Object_BitwiseAnd(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return bitwise_and_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_OR(R, T1, T2, bitwise_or_func) \
    R* Mdc_Object_BitwiseOr(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return bitwise_or_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_XOR(R, T1, T2, bitwise_xor_func) \
    R* Mdc_Object_BitwiseXor(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return bitwise_xor_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_LEFT_SHIFT( \
    R, \
    T1, \
    T2, \
    bitwise_left_shift_func \
) \
    R* Mdc_Object_BitwiseLeftShift(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return bitwise_left_shift_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_BITWISE_RIGHT_SHIFT( \
    R, \
    T1, \
    T2, \
    bitwise_right_shift_func \
) \
    R* Mdc_Object_BitwiseRightShift(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return bitwise_right_shift_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_LOGICAL_NOT(R, T, logical_not_func) \
    R* Mdc_Object_LogicalNot(T)(R* dest, const T* op) { \
      return logical_not_func(dest, op); \
    }

#define MDC_DEFINE_OBJECT_LOGICAL_AND(R, T1, T2, logical_and_func) \
    R* Mdc_Object_LogicalAnd(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return logical_and_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_LOGICAL_OR(R, T1, T2, logical_or_func) \
    R* Mdc_Object_LogicalOr(T1, T2)( \
        R* dest, \
        const T1* op1, \
        const T2* op2 \
    ) { \
      return logical_or_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_ACCESS(R, T, K, access_func) \
    R* Mdc_Object_Access(T, A)(T* obj, const K* key) { \
      return access_func(obj, key); \
    }

#define MDC_DEFINE_OBJECT_ACCESS_CONST(R, T, K, access_const_func) \
    const R* Mdc_Object_AccessConst(T)(const T* obj, const K* key) { \
      return access_const_func(obj, key); \
    }

#define MDC_DEFINE_OBJECT_EQUAL(R, T1, T2, equal_func) \
    R* Mdc_Object_Equal(T1, T2)(R* dest, const T1* op1, const T2* op2) { \
      return equal_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_COMPARE(R, T1, T2, compare_func) \
    R* Mdc_Object_Compare(T1, T2)(R* dest, const T1* op1, const T2* op2) { \
      return compare_func(dest, op1, op2); \
    }

#define MDC_DEFINE_OBJECT_SWAP(T, swap_func) \
    void Mdc_Object_Swap(T)(T* obj1, T* obj2) { \
      return swap_func(obj1, obj2); \
    }

#endif /* MDC_C_OBJECT_INTERNAL_OBJECT_DEFINE_MACROS_H_ */
