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

#ifndef MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DEFINE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DEFINE_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"

#define Mdc_Pair(T_FirstT, T_SecondT) \
    MDC_MACRO_CONCAT( \
        Mdc_Pair, \
        MDC_MACRO_TEMPLATE_2(T_FirstT, T_SecondT) \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Pair_InitDefault(T_FirstT, T_SecondT) \
    Mdc_Object_InitDefault(Mdc_Pair(T_FirstT, T_SecondT))

#define Mdc_Pair_InitFromFirstCopySecondCopy(T_FirstT, T_SecondT) \
    Mdc_Object_InitFrom_2( \
        Mdc_Pair(T_FirstT, T_SecondT), \
        MDC_T_PC(T_FirstT), \
        MDC_T_PC(T_SecondT) \
    )

#define Mdc_Pair_InitCopy(T_FirstT, T_SecondT) \
    Mdc_Object_InitCopy(Mdc_Pair(T_FirstT, T_SecondT))

#define Mdc_Pair_InitMove(T_FirstT, T_SecondT) \
    Mdc_Object_InitMove(Mdc_Pair(T_FirstT, T_SecondT))

#define Mdc_Pair_Deinit(T_FirstT, T_SecondT) \
    Mdc_Object_Deinit(Mdc_Pair(T_FirstT, T_SecondT))

/**
 * Assignment
 */

#define Mdc_Pair_AssignCopy(T_FirstT, T_SecondT) \
    Mdc_Object_AssignCopy(Mdc_Pair(T_FirstT, T_SecondT))

#define Mdc_Pair_AssignMove(T_FirstT, T_SecondT) \
    Mdc_Object_AssignMove(Mdc_Pair(T_FirstT, T_SecondT))

/**
 * Comparison
 */

#define Mdc_Pair_Equal(T_FirstT, T_SecondT) \
    Mdc_Object_DefaultEqual( \
        Mdc_Pair(T_FirstT, T_SecondT), \
        Mdc_Pair(T_FirstT, T_SecondT) \
    )

#define Mdc_Pair_Compare(T_FirstT, T_SecondT) \
    Mdc_Object_DefaultCompare( \
        Mdc_Pair(T_FirstT, T_SecondT), \
        Mdc_Pair(T_FirstT, T_SecondT) \
    )

/**
 * General Functions
 */

#define Mdc_Pair_Swap(T_FirstT, T_SecondT) \
    Mdc_Object_Swap(Mdc_Pair(T_FirstT, T_SecondT))

#endif /* MDC_C_CONTAINER_INTERNAL_PAIR_PAIR_DEFINE_MACRO_H_ */
