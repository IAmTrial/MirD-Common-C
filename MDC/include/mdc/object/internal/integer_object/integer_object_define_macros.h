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

#ifndef MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_DEFINE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_DEFINE_MACROS_H_

#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "integer_object_typedef.h"
#include "integer_object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define MDC_DEFINE_INTEGER_INIT_DEFAULT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_InitDefault(T_IntT)(void) { \
      return 0; \
    }

#define MDC_DEFINE_INTEGER_INIT_FROM_VALUE(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_InitFromValue(T_IntT)( \
        MDC_T(T_IntT) value \
    ) { \
      return value; \
    }

#define MDC_DEFINE_INTEGER_INIT_COPY(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_InitCopy(T_IntT)( \
        MDC_T_PC(T_IntT) integer \
    ) { \
      return *integer; \
    }

#define MDC_DEFINE_INTEGER_INIT_MOVE(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_InitMove(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return *integer; \
    }

#define MDC_DEFINE_INTEGER_DEINIT(T_IntT) \
    void Mdc_Integer_Deinit(T_IntT)(MDC_T_P(T_IntT) integer) { \
      /* This is left empty on purpose. There is nothing to do. */ \
    }

/**
 * Assignment
 */

#define MDC_DEFINE_INTEGER_ASSIGN_COPY(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignCopy(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_MOVE(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignMove(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_P(T_IntT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_ADD(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignAdd(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest += *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_SUBTRACT(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignSubtract(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest -= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_MULTIPLY(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignMultiply(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest *= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_DIVIDE(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignDivide(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest /= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_MODULO(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignModulo(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest %= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_BITWISE_AND(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignBitwiseAnd(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest &= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_BITWISE_OR(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignBitwiseOr(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest |= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_BITWISE_XOR(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignBitwiseXor(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest ^= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_BITWISE_LEFT_SHIFT(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignBitwiseLeftShift(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest <<= *src; \
      return dest; \
    }

#define MDC_DEFINE_INTEGER_ASSIGN_BITWISE_RIGHT_SHIFT(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_AssignBitwiseRightShift(T_IntT)( \
        MDC_T_P(T_IntT) dest, \
        MDC_T_PC(T_IntT) src \
    ) { \
      *dest >>= *src; \
      return dest; \
    }

/**
 * Increment / Decrement
 */

#define MDC_DEFINE_INTEGER_PRE_INCREMENT(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_PreIncrement(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      ++(*integer); \
      return integer; \
    }

#define MDC_DEFINE_INTEGER_PRE_DECREMENT(T_IntT) \
    MDC_T_P(T_IntT) Mdc_Integer_PreDecrement(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      --(*integer); \
      return integer; \
    }

#define MDC_DEFINE_INTEGER_POST_INCREMENT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_PostIncrement(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return (*integer)++; \
    }

#define MDC_DEFINE_INTEGER_POST_DECREMENT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_PostDecrement(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return (*integer)--; \
    }

/**
 * Arithmetic
 */

#define MDC_DEFINE_INTEGER_UNARY_PLUS(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_UnaryPlus(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return Mdc_Integer_UnaryPlusConst(T_IntT)(integer); \
    }

#define MDC_DEFINE_INTEGER_UNARY_PLUS_CONST(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_UnaryPlusConst(T_IntT)( \
        MDC_T_PC(T_IntT) integer \
    ) { \
      return +(*integer); \
    }

#define MDC_DEFINE_INTEGER_UNARY_MINUS(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_UnaryMinus(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return Mdc_Integer_UnaryMinusConst(T_IntT)(integer); \
    }

#define MDC_DEFINE_INTEGER_UNARY_MINUS_CONST(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_UnaryMinusConst(T_IntT)( \
        MDC_T_PC(T_IntT) integer \
    ) { \
      return -(*integer); \
    }

#define MDC_DEFINE_INTEGER_ADD(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_Add(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) + (*integer2); \
    }

#define MDC_DEFINE_INTEGER_SUBTRACT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_Subtract(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) - (*integer2); \
    }

#define MDC_DEFINE_INTEGER_MULTIPLY(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_Multiply(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) * (*integer2); \
    }

#define MDC_DEFINE_INTEGER_DIVIDE(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_Divide(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) / (*integer2); \
    }

#define MDC_DEFINE_INTEGER_MODULO(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_Modulo(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) % (*integer2); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_NOT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseNot(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return Mdc_Integer_BitwiseNotConst(T_IntT)(integer); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_NOT_CONST(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseNotConst(T_IntT)( \
        MDC_T_PC(T_IntT) integer \
    ) { \
      return ~(*integer); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_AND(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseAnd(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) & (*integer2); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_OR(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseOr(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) | (*integer2); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_XOR(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseXor(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) ^ (*integer2); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_LEFT_SHIFT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseLeftShift(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) << (*integer2); \
    }

#define MDC_DEFINE_INTEGER_BITWISE_RIGHT_SHIFT(T_IntT) \
    MDC_T(T_IntT) Mdc_Integer_BitwiseRightShift(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) >> (*integer2); \
    }

/**
 * Logical
 */

#define MDC_DEFINE_INTEGER_LOGICAL_NOT(T_IntT) \
    bool Mdc_Integer_LogicalNot(T_IntT)( \
        MDC_T_P(T_IntT) integer \
    ) { \
      return Mdc_Integer_LogicalNotConst(T_IntT)(integer); \
    }

#define MDC_DEFINE_INTEGER_LOGICAL_NOT_CONST(T_IntT) \
    bool Mdc_Integer_LogicalNotConst(T_IntT)( \
        MDC_T_PC(T_IntT) integer \
    ) { \
      return !(*integer); \
    }

#define MDC_DEFINE_INTEGER_LOGICAL_AND(T_IntT) \
    bool Mdc_Integer_LogicalAnd(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) && (*integer2); \
    }

#define MDC_DEFINE_INTEGER_LOGICAL_OR(T_IntT) \
    bool Mdc_Integer_LogicalOr(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) || (*integer2); \
    }

/**
 * Comparison
 */

#define MDC_DEFINE_INTEGER_EQUAL(T_IntT) \
    bool Mdc_Integer_Equal(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      return (*integer1) == (*integer2); \
    }

#define MDC_DEFINE_INTEGER_COMPARE(T_IntT) \
    int Mdc_Integer_Compare(T_IntT)( \
        MDC_T_PC(T_IntT) integer1, \
        MDC_T_PC(T_IntT) integer2 \
    ) { \
      if (*integer1 < *integer2) { \
        return -1; \
      } else if (*integer1 > *integer2) { \
        return 1; \
      } else /* if (*integer1 == *integer2) */ { \
        return 0; \
      } \
    }

/**
 * General Functions
 */

#define MDC_DEFINE_INTEGER_SWAP(T_IntT) \
    void Mdc_Integer_Swap(T_IntT)( \
        MDC_T_P(T_IntT) integer1, \
        MDC_T_P(T_IntT) integer2 \
    ) { \
      MDC_T(T_IntT) temp_integer; \
\
      temp_integer = *integer1; \
      *integer1 = *integer2; \
      *integer2 = temp_integer; \
    }

#define MDC_INTERNAL_DEFINE_UNSIGNED_INTEGER_FUNCTIONS(T_IntT) \
    MDC_DEFINE_INTEGER_INIT_DEFAULT(T_IntT) \
    MDC_DEFINE_INTEGER_INIT_FROM_VALUE(T_IntT) \
    MDC_DEFINE_INTEGER_INIT_COPY(T_IntT) \
    MDC_DEFINE_INTEGER_INIT_MOVE(T_IntT) \
    MDC_DEFINE_INTEGER_DEINIT(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_COPY(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_MOVE(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_ADD(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_SUBTRACT(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_MULTIPLY(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_DIVIDE(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_MODULO(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_BITWISE_AND(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_BITWISE_OR(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_BITWISE_XOR(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_BITWISE_LEFT_SHIFT(T_IntT) \
    MDC_DEFINE_INTEGER_ASSIGN_BITWISE_RIGHT_SHIFT(T_IntT) \
    MDC_DEFINE_INTEGER_PRE_INCREMENT(T_IntT) \
    MDC_DEFINE_INTEGER_PRE_DECREMENT(T_IntT) \
    MDC_DEFINE_INTEGER_POST_INCREMENT(T_IntT) \
    MDC_DEFINE_INTEGER_POST_DECREMENT(T_IntT) \
    MDC_DEFINE_INTEGER_UNARY_PLUS(T_IntT) \
    MDC_DEFINE_INTEGER_UNARY_PLUS_CONST(T_IntT) \
    MDC_DEFINE_INTEGER_ADD(T_IntT) \
    MDC_DEFINE_INTEGER_SUBTRACT(T_IntT) \
    MDC_DEFINE_INTEGER_MULTIPLY(T_IntT) \
    MDC_DEFINE_INTEGER_DIVIDE(T_IntT) \
    MDC_DEFINE_INTEGER_MODULO(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_NOT(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_NOT_CONST(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_AND(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_OR(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_XOR(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_LEFT_SHIFT(T_IntT) \
    MDC_DEFINE_INTEGER_BITWISE_RIGHT_SHIFT(T_IntT) \
    MDC_DEFINE_INTEGER_LOGICAL_NOT(T_IntT) \
    MDC_DEFINE_INTEGER_LOGICAL_NOT_CONST(T_IntT) \
    MDC_DEFINE_INTEGER_LOGICAL_AND(T_IntT) \
    MDC_DEFINE_INTEGER_LOGICAL_OR(T_IntT) \
    MDC_DEFINE_INTEGER_EQUAL(T_IntT) \
    MDC_DEFINE_INTEGER_COMPARE(T_IntT) \
    MDC_DEFINE_INTEGER_SWAP(T_IntT)

#define MDC_INTERNAL_DEFINE_SIGNED_INTEGER_FUNCTIONS(T_IntT) \
    MDC_INTERNAL_DEFINE_UNSIGNED_INTEGER_FUNCTIONS(T_IntT) \
    MDC_DEFINE_INTEGER_UNARY_MINUS(T_IntT) \
    MDC_DEFINE_INTEGER_UNARY_MINUS_CONST(T_IntT)

#endif /* MDC_C_OBJECT_INTERNAL_INTEGER_OBJECT_INTEGER_OBJECT_DEFINE_MACROS_H_ */
