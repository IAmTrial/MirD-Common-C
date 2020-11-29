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

#ifndef MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_DEFINE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_DEFINE_MACROS_H_

#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "floating_object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define MDC_DEFINE_FLOATING_INIT_DEFAULT(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_InitDefault(T_FloatingT)(void) { \
      /* Should actually return an unspecified value. */ \
      return 0; \
    }

#define MDC_DEFINE_FLOATING_INIT_FROM_VALUE(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_InitFromValue(T_FloatingT)( \
        MDC_T(T_FloatingT) value \
    ) { \
      return value; \
    }

#define MDC_DEFINE_FLOATING_INIT_COPY(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_InitCopy(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating \
    ) { \
      return *floating; \
    }

#define MDC_DEFINE_FLOATING_INIT_MOVE(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_InitMove(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return *floating; \
    }

#define MDC_DEFINE_FLOATING_DEINIT(T_FloatingT) \
    void Mdc_Floating_Deinit(T_FloatingT)(MDC_T_P(T_FloatingT) floating) { \
      /* This is left empty on purpose. There is nothing to do. */ \
    }

/**
 * Assignment
 */

#define MDC_DEFINE_FLOATING_ASSIGN_COPY(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignCopy(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_PC(T_FloatingT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

#define MDC_DEFINE_FLOATING_ASSIGN_MOVE(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignMove(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_P(T_FloatingT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

#define MDC_DEFINE_FLOATING_ASSIGN_ADD(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignAdd(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_PC(T_FloatingT) src \
    ) { \
      *dest += *src; \
      return dest; \
    }

#define MDC_DEFINE_FLOATING_ASSIGN_SUBTRACT(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignSubtract(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_PC(T_FloatingT) src \
    ) { \
      *dest -= *src; \
      return dest; \
    }

#define MDC_DEFINE_FLOATING_ASSIGN_MULTIPLY(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignMultiply(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_PC(T_FloatingT) src \
    ) { \
      *dest *= *src; \
      return dest; \
    }

#define MDC_DEFINE_FLOATING_ASSIGN_DIVIDE(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_AssignDivide(T_FloatingT)( \
        MDC_T_P(T_FloatingT) dest, \
        MDC_T_PC(T_FloatingT) src \
    ) { \
      *dest /= *src; \
      return dest; \
    }

/**
 * Increment / Decrement
 */

#define MDC_DEFINE_FLOATING_PRE_INCREMENT(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_PreIncrement(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      ++(*floating); \
      return floating; \
    }

#define MDC_DEFINE_FLOATING_PRE_DECREMENT(T_FloatingT) \
    MDC_T_P(T_FloatingT) Mdc_Floating_PreDecrement(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      --(*floating); \
      return floating; \
    }

#define MDC_DEFINE_FLOATING_POST_INCREMENT(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_PostIncrement(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return (*floating)++; \
    }

#define MDC_DEFINE_FLOATING_POST_DECREMENT(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_PostDecrement(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return (*floating)--; \
    }

/**
 * Arithmetic
 */

#define MDC_DEFINE_FLOATING_UNARY_PLUS(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_UnaryPlus(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return Mdc_Floating_UnaryPlusConst(T_FloatingT)(floating); \
    }

#define MDC_DEFINE_FLOATING_UNARY_PLUS_CONST(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_UnaryPlusConst(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating \
    ) { \
      return +(*floating); \
    }

#define MDC_DEFINE_FLOATING_UNARY_MINUS(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_UnaryMinus(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return Mdc_Floating_UnaryMinusConst(T_FloatingT)(floating); \
    }

#define MDC_DEFINE_FLOATING_UNARY_MINUS_CONST(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_UnaryMinusConst(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating \
    ) { \
      return -(*floating); \
    }

#define MDC_DEFINE_FLOATING_ADD(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_Add(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) + (*floating2); \
    }

#define MDC_DEFINE_FLOATING_SUBTRACT(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_Subtract(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) - (*floating2); \
    }

#define MDC_DEFINE_FLOATING_MULTIPLY(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_Multiply(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) * (*floating2); \
    }

#define MDC_DEFINE_FLOATING_DIVIDE(T_FloatingT) \
    MDC_T(T_FloatingT) Mdc_Floating_Divide(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) / (*floating2); \
    }

/**
 * Logical
 */

#define MDC_DEFINE_FLOATING_LOGICAL_NOT(T_FloatingT) \
    bool Mdc_Floating_LogicalNot(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating \
    ) { \
      return Mdc_Floating_LogicalNotConst(T_FloatingT)(floating); \
    }

#define MDC_DEFINE_FLOATING_LOGICAL_NOT_CONST(T_FloatingT) \
    bool Mdc_Floating_LogicalNotConst(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating \
    ) { \
      return !(*floating); \
    }

#define MDC_DEFINE_FLOATING_LOGICAL_AND(T_FloatingT) \
    bool Mdc_Floating_LogicalAnd(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) && (*floating2); \
    }

#define MDC_DEFINE_FLOATING_LOGICAL_OR(T_FloatingT) \
    bool Mdc_Floating_LogicalOr(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) || (*floating2); \
    }

/**
 * Comparison
 */

#define MDC_DEFINE_FLOATING_EQUAL(T_FloatingT) \
    bool Mdc_Floating_Equal(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      return (*floating1) == (*floating2); \
    }

#define MDC_DEFINE_FLOATING_COMPARE(T_FloatingT) \
    int Mdc_Floating_Compare(T_FloatingT)( \
        MDC_T_PC(T_FloatingT) floating1, \
        MDC_T_PC(T_FloatingT) floating2 \
    ) { \
      if (*floating1 < *floating2) { \
        return -1; \
      } else if (*floating1 > *floating2) { \
        return 1; \
      } else /* if (*floating1 == *floating2) */ { \
        return 0; \
      } \
    }

/**
 * General Functions
 */

#define MDC_DEFINE_FLOATING_SWAP(T_FloatingT) \
    void Mdc_Floating_Swap(T_FloatingT)( \
        MDC_T_P(T_FloatingT) floating1, \
        MDC_T_P(T_FloatingT) floating2 \
    ) { \
      MDC_T(T_FloatingT) temp_floating; \
\
      temp_floating = *floating1; \
      *floating1 = *floating2; \
      *floating2 = temp_floating; \
    }

#define MDC_INTERNAL_DEFINE_FLOATING_FUNCTIONS(T_FloatingT) \
    MDC_DEFINE_FLOATING_INIT_DEFAULT(T_FloatingT) \
    MDC_DEFINE_FLOATING_INIT_FROM_VALUE(T_FloatingT) \
    MDC_DEFINE_FLOATING_INIT_COPY(T_FloatingT) \
    MDC_DEFINE_FLOATING_INIT_MOVE(T_FloatingT) \
    MDC_DEFINE_FLOATING_DEINIT(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_COPY(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_MOVE(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_ADD(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_SUBTRACT(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_MULTIPLY(T_FloatingT) \
    MDC_DEFINE_FLOATING_ASSIGN_DIVIDE(T_FloatingT) \
    MDC_DEFINE_FLOATING_PRE_INCREMENT(T_FloatingT) \
    MDC_DEFINE_FLOATING_PRE_DECREMENT(T_FloatingT) \
    MDC_DEFINE_FLOATING_POST_INCREMENT(T_FloatingT) \
    MDC_DEFINE_FLOATING_POST_DECREMENT(T_FloatingT) \
    MDC_DEFINE_FLOATING_UNARY_PLUS(T_FloatingT) \
    MDC_DEFINE_FLOATING_UNARY_PLUS_CONST(T_FloatingT) \
    MDC_DEFINE_FLOATING_UNARY_MINUS(T_FloatingT) \
    MDC_DEFINE_FLOATING_UNARY_MINUS_CONST(T_FloatingT) \
    MDC_DEFINE_FLOATING_ADD(T_FloatingT) \
    MDC_DEFINE_FLOATING_SUBTRACT(T_FloatingT) \
    MDC_DEFINE_FLOATING_MULTIPLY(T_FloatingT) \
    MDC_DEFINE_FLOATING_DIVIDE(T_FloatingT) \
    MDC_DEFINE_FLOATING_LOGICAL_NOT(T_FloatingT) \
    MDC_DEFINE_FLOATING_LOGICAL_NOT_CONST(T_FloatingT) \
    MDC_DEFINE_FLOATING_LOGICAL_AND(T_FloatingT) \
    MDC_DEFINE_FLOATING_LOGICAL_OR(T_FloatingT) \
    MDC_DEFINE_FLOATING_EQUAL(T_FloatingT) \
    MDC_DEFINE_FLOATING_COMPARE(T_FloatingT) \
    MDC_DEFINE_FLOATING_SWAP(T_FloatingT)

#endif /* MDC_C_OBJECT_INTERNAL_FLOATING_OBJECT_FLOATING_OBJECT_DEFINE_MACROS_H_ */
