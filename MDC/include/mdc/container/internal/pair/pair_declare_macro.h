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

#ifndef MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DECLARE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DECLARE_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "pair_name_macro.h"

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_PAIR_STRUCT(T_FirstT, T_SecondT) \
    struct Mdc_Pair(T_FirstT, T_SecondT) { \
      MDC_T(T_FirstT) first; \
      MDC_T(T_SecondT) second; \
    }; \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(struct, Mdc_Pair(T_FirstT, T_SecondT))

/**
 * Functions
 */

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DECLARE_PAIR_INIT_DEFAULT(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT(Mdc_Pair(T_FirstT, T_SecondT))

#define MDC_INTERNAL_DECLARE_PAIR_INIT_FROM_FIRST_COPY_SECOND_COPY( \
    T_FirstT, \
    T_SecondT \
) \
    MDC_T(Mdc_Pair(T_FirstT, T_SecondT)) \
    Mdc_Pair_InitFromFirstCopySecondCopy(T_FirstT, T_SecondT)( \
        MDC_T_PC(T_FirstT) first, \
        MDC_T_PC(T_SecondT) second \
    );

#define MDC_INTERNAL_DECLARE_PAIR_INIT_COPY(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_INIT_COPY(Mdc_Pair(T_FirstT, T_SecondT))

#define MDC_INTERNAL_DECLARE_PAIR_INIT_MOVE(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_INIT_MOVE(Mdc_Pair(T_FirstT, T_SecondT))

#define MDC_INTERNAL_DECLARE_PAIR_DEINIT(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_DEINIT(Mdc_Pair(T_FirstT, T_SecondT))

/**
 * Assignment
 */

#define MDC_INTERNAL_DECLARE_PAIR_ASSIGN_COPY(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_ASSIGN_COPY(Mdc_Pair(T_FirstT, T_SecondT))

#define MDC_INTERNAL_DECLARE_PAIR_ASSIGN_MOVE(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_ASSIGN_MOVE(Mdc_Pair(T_FirstT, T_SecondT))

/**
 * Comparison
 */

#define MDC_INTERNAL_DECLARE_PAIR_EQUAL(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_DEFAULT_EQUAL( \
        Mdc_Pair(T_FirstT, T_SecondT), \
        Mdc_Pair(T_FirstT, T_SecondT) \
    )

#define MDC_INTERNAL_DECLARE_PAIR_COMPARE(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_DEFAULT_COMPARE( \
        Mdc_Pair(T_FirstT, T_SecondT), \
        Mdc_Pair(T_FirstT, T_SecondT) \
    )

/**
 * General Functions
 */

#define MDC_INTERNAL_DECLARE_PAIR_SWAP(T_FirstT, T_SecondT) \
    MDC_DECLARE_OBJECT_SWAP(Mdc_Pair(T_FirstT, T_SecondT))

#define MDC_INTERNAL_DECLARE_PAIR_FUNCTIONS(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_INIT_DEFAULT(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_INIT_FROM_FIRST_COPY_SECOND_COPY( \
        T_FirstT, \
        T_SecondT \
    ) \
    MDC_INTERNAL_DECLARE_PAIR_INIT_COPY(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_INIT_MOVE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_DEINIT(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_ASSIGN_COPY(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_ASSIGN_MOVE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_EQUAL(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_COMPARE(T_FirstT, T_SecondT) \
    MDC_INTERNAL_DECLARE_PAIR_SWAP(T_FirstT, T_SecondT)

#endif /* MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DECLARE_MACRO_H_ */
