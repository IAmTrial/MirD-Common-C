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

#ifndef MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_NAME_MACRO_H_

#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "pair_name_macro.h"

#define MDC_INTERNAL_PAIR_UNINIT { 0 }

#define Mdc_Pair_kUninit(T_FirstT, T_SecondT) \
    MDC_MACRO_CONCAT(Mdc_Pair(T_FirstT, T_SecondT), kUninit)

#define MDC_INTERNAL_DEFINE_PAIR_UNINIT_CONST(T_CharT) \
    static MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_kUninit(T_FirstT, T_SecondT) = \
        MDC_INTERNAL_PAIR_UNINIT;

/**
 * Functions
 */

#define MDC_INTERNAL_DEFINE_PAIR_INIT_DEFAULT(T_FirstT, T_SecondT) \
    MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_InitDefault(T_FirstT, T_SecondT)(void) { \
      MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) pair; \
\
      pair.first = Mdc_Object_InitDefault(T_FirstT)(); \
      pair.second = Mdc_Object_InitDefault(T_SecondT)(); \
\
      return pair; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_INIT_FROM_FIRST_COPY_SECOND_COPY( \
    T_FirstT, \
    T_SecondT \
) \
    MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_InitFromFirstCopySecondCopy(T_FirstT, T_SecondT)( \
        MDC_T_PC(T_FirstT) first, \
        MDC_T_PC(T_SecondT) second \
    ) { \
      MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) pair; \
\
      pair.first = Mdc_Object_InitCopy(T_FirstT)(first); \
      pair.second = Mdc_Object_InitCopy(T_SecondT)(second); \
\
      return pair; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_INIT_COPY(T_FirstT, T_SecondT) \
    MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_InitCopy(T_FirstT, T_SecondT)( \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) src \
    ) { \
      MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) pair; \
\
      pair = Mdc_Pair_InitFromFirstCopySecondCopy(T_FirstT, T_SecondT)( \
          &src->first, \
          &src->second \
      ) \
\
      return pair; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_INIT_MOVE(T_FirstT, T_SecondT) \
    MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_InitCopy(T_FirstT, T_SecondT)( \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) src \
    ) { \
      MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) pair; \
\
      pair.first = Mdc_Object_InitMove(T_FirstT)(&src->first); \
      pair.second = Mdc_Object_InitMove(T_SecondT)(&src->second); \
\
      return pair; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_DEINIT(T_FirstT, T_SecondT) \
    void Mdc_Pair_Deinit(T_FirstT, T_SecondT)( \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) pair \
    ) { \
      Mdc_Object_Deinit(T_SecondT)(&pair->second); \
      Mdc_Object_Deinit(T_FirstT)(&pair->first); \
    }

/**
 * Assignment
 */

#define MDC_INTERNAL_DEFINE_PAIR_ASSIGN_COPY(T_FirstT, T_SecondT) \
    MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_AssignCopy(T_FirstT, T_SecondT)( \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) dest, \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) src \
    ) { \
      Mdc_Object_AssignCopy(T_FirstT)(&dest->first, &src->first); \
      Mdc_Object_AssignCopy(T_SecondT)(&dest->second, &src->second); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_ASSIGN_MOVE(T_FirstT, T_SecondT) \
    MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_AssignMove(T_FirstT, T_SecondT)( \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) dest, \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) src \
    ) { \
      Mdc_Object_AssignMove(T_FirstT)(&dest->first, &src->first); \
      Mdc_Object_AssignMove(T_SecondT)(&dest->second, &src->second); \
\
      return dest; \
    }

/**
 * Comparison
 */

#define MDC_INTERNAL_DEFINE_PAIR_EQUAL(T_FirstT, T_SecondT) \
    bool Mdc_Pair_Equal(T_FirstT, T_SecondT)( \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) pair1, \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) pair2 \
    ) { \
      bool is_equal_first; \
      bool is_equal_second; \
\
      if (pair1 == pair2) { \
        return true; \
      } \
\
      is_equal_first = Mdc_Object_DefaultEqual(T_FirstT, T_FirstT)( \
          &pair1->first, \
          &pair2->first \
      ); \
\
      if (!is_equal_first) { \
        return false; \
      } \
\
      is_equal_second = Mdc_Object_DefaultEqual(T_SecondT, T_SecondT)( \
          &pair1->second, \
          &pair2->second \
      ); \
\
      return is_equal_second; \
    }

#define MDC_INTERNAL_DEFINE_PAIR_COMPARE(T_FirstT, T_SecondT) \
    int Mdc_Pair_Compare(T_FirstT, T_SecondT)( \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) pair1, \
        MDC_T_PC(Mdc_Pair(T_FirstT, T_SecondT)) pair2 \
    ) { \
      int compare_first; \
      int compare_second; \
\
      if (pair1 == pair2) { \
        return 0; \
      } \
\
      compare_first = Mdc_Object_DefaultCompare(T_FirstT, T_FirstT)( \
          &pair1->first, \
          &pair2->first \
      ); \
\
      if (compare_first != 0) { \
        return compare_first; \
      } \
\
      compare_second = Mdc_Object_DefaultCompare(T_SecondT, T_SecondT)( \
          &pair1->second, \
          &pair2->second \
      ); \
\
      return compare_second; \
    }

/**
 * General Functions
 */

#define MDC_INTERNAL_DEFINE_PAIR_SWAP(T_FirstT, T_SecondT) \
    void Mdc_Pair_Swap(T_FirstT, T_SecondT)( \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) pair1, \
        MDC_T_P(Mdc_Pair(T_FirstT, T_SecondT)) pair2 \
    ) { \
      Mdc_Object_Swap(T_FirstT)(&pair1->first, &pair2->first); \
      Mdc_Object_Swap(T_SecondT)(&pair1->second, &pair2->second); \
    }

#define MDC_INTERNAL_DEFINE_PAIR_FUNCTIONS(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_INIT_DEFAULT(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_INIT_FROM_FIRST_COPY_SECOND_COPY( \
        T_FirstT, \
        T_SecondT \
    ) \
    MDC_INTERNAL_DEFINE_PAIR_INIT_COPY(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_INIT_MOVE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_DEINIT(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_ASSIGN_COPY(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_ASSIGN_MOVE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_EQUAL(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_COMPARE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DEFINE_PAIR_SWAP(T_FirstT, T_SecondT)

#endif /* MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_NAME_MACRO_H_ */
