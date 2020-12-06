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

#ifndef MDC_C_CONTAINER_INTERNAL_MAP_MAP_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_MAP_MAP_NAME_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"
#include "../../pair.h"

#define Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    Mdc_Object_MemberFunction_1( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        CompareFirst, \
        MDC_T_PC(Mdc_Pair(T_KeyT, T_ValueT)) \
    )

#define Mdc_Map(T_KeyT, T_ValueT) \
    MDC_MACRO_CONCAT( \
        Mdc_Map, \
        MDC_MACRO_TEMPLATE_2(T_KeyT, T_ValueT) \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Map_InitEmpty(T_KeyT, T_ValueT) \
    Mdc_Object_InitDefault(Mdc_Map(T_KeyT, T_ValueT))

#define Mdc_Map_InitCopy(T_KeyT, T_ValueT) \
    Mdc_Object_InitCopy(Mdc_Map(T_KeyT, T_ValueT))

#define Mdc_Map_InitMove(T_KeyT, T_ValueT) \
    Mdc_Object_InitMove(Mdc_Map(T_KeyT, T_ValueT))

#define Mdc_Map_Deinit(T_KeyT, T_ValueT) \
    Mdc_Object_Deinit(Mdc_Map(T_KeyT, T_ValueT))

/**
 * Assignment
 */

#define Mdc_Map_AssignCopy(T_KeyT, T_ValueT) \
    Mdc_Object_AssignCopy(Mdc_Map(T_KeyT, T_ValueT))

#define Mdc_Map_AssignMove(T_KeyT, T_ValueT) \
    Mdc_Object_AssignMove(Mdc_Map(T_KeyT, T_ValueT))

/**
 * Comparison
 */

#define Mdc_Map_Equal(T_KeyT, T_ValueT) \
    Mdc_Object_DefaultEqual( \
        Mdc_Map(T_KeyT, T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT) \
    )

#define Mdc_Map_Compare(T_KeyT, T_ValueT) \
    Mdc_Object_DefaultCompare( \
        Mdc_Map(T_KeyT, T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT) \
    )

/**
 * Member access
 */

#define Mdc_Map_Access(T_KeyT, T_ValueT) \
    Mdc_Object_Subscript(Mdc_Map(T_KeyT, T_ValueT), MDC_T_PC(T_KeyT))

#define Mdc_Map_AccessConst(T_KeyT, T_ValueT) \
    Mdc_Object_SubscriptConst(Mdc_Map(T_KeyT, T_ValueT), MDC_T_PC(T_KeyT))

/**
 * General Functions
 */

#define Mdc_Map_At(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), At)

#define Mdc_Map_AtConst(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), AtConst)

#define Mdc_Map_Clear(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Clear)

#define Mdc_Map_Contains(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Contains)

#define Mdc_Map_Emplace_0(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace)

#define Mdc_Map_Emplace_1(T_KeyT, T_ValueT, A1) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Map_Emplace_2(T_KeyT, T_ValueT, A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Map_Emplace_3(T_KeyT, T_ValueT, A1, A2, A3) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_3(A1, A2, A3) \
    )

#define Mdc_Map_Emplace_4(T_KeyT, T_ValueT, A1, A2, A3, A4) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_4(A1, A2, A3, A4) \
    )

#define Mdc_Map_Emplace_5(T_KeyT, T_ValueT, A1, A2, A3, A4, A5) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_5(A1, A2, A3, A4, A5) \
    )

#define Mdc_Map_Emplace_6(T_KeyT, T_ValueT, A1, A2, A3, A4, A5, A6) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_6(A1, A2, A3, A4, A5, A6) \
    )

#define Mdc_Map_Emplace_7(T_KeyT, T_ValueT, A1, A2, A3, A4, A5, A6, A7) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_7(A1, A2, A3, A4, A5, A6, A7) \
    )

#define Mdc_Map_Emplace_8(T_KeyT, T_ValueT, A1, A2, A3, A4, A5, A6, A7, A8) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_8(A1, A2, A3, A4, A5, A6, A7, A8) \
    )

#define Mdc_Map_Emplace_9( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8, A9 \
) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Emplace), \
        MDC_MACRO_TEMPLATE_9(A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    )

#define Mdc_Map_Emplace(N_Args) \
    MDC_MACRO_CONCAT( \
        Mdc_Map_Emplace_, \
        N_Args \
    )

#define Mdc_Map_EmplaceKeyCopy_0(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy)

#define Mdc_Map_EmplaceKeyCopy_1(T_KeyT, T_ValueT, A1) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_1(A1) \
    )

#define Mdc_Map_EmplaceKeyCopy_2(T_KeyT, T_ValueT, A1, A2) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_2(A1, A2) \
    )

#define Mdc_Map_EmplaceKeyCopy_3(T_KeyT, T_ValueT, A1, A2, A3) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_3(A1, A2, A3) \
    )

#define Mdc_Map_EmplaceKeyCopy_4(T_KeyT, T_ValueT, A1, A2, A3, A4) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_4(A1, A2, A3, A4) \
    )

#define Mdc_Map_EmplaceKeyCopy_5(T_KeyT, T_ValueT, A1, A2, A3, A4, A5) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_5(A1, A2, A3, A4, A5) \
    )

#define Mdc_Map_EmplaceKeyCopy_6(T_KeyT, T_ValueT, A1, A2, A3, A4, A5, A6) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_6(A1, A2, A3, A4, A5, A6) \
    )

#define Mdc_Map_EmplaceKeyCopy_7( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7 \
) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_7(A1, A2, A3, A4, A5, A6, A7) \
    )

#define Mdc_Map_EmplaceKeyCopy_8( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8 \
) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_8(A1, A2, A3, A4, A5, A6, A7, A8) \
    )

#define Mdc_Map_EmplaceKeyCopy_9( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8, A9 \
) \
    MDC_MACRO_CONCAT( \
        Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), EmplaceKeyCopy), \
        MDC_MACRO_TEMPLATE_9(A1, A2, A3, A4, A5, A6, A7, A8, A9) \
    )

#define Mdc_Map_EmplaceKeyCopy(T_KeyT, T_ValueT) \
    MDC_MACRO_CONCAT( \
        Mdc_Map_EmplaceKeyCopy_, \
        N_Args \
    )

#define Mdc_Map_Empty(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Empty)

#define Mdc_Map_Erase(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Erase)

#define Mdc_Map_InsertPair(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), InsertPair)

#define Mdc_Map_InsertPairCopy(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), InsertPairCopy)

#define Mdc_Map_InsertOrAssign(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), InsertOrAssign)

#define Mdc_Map_InsertOrAssignKeyCopy(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), InsertOrAssignKeyCopy)

#define Mdc_Map_InsertOrAssignValueCopy(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), InsertOrAssignValueCopy)

#define Mdc_Map_InsertOrAssignKeyCopyValueCopy(T_KeyT, T_ValueT) \
    Mdc_Object_Member( \
        Mdc_Map(T_KeyT, T_ValueT), \
        InsertOrAssignKeyCopyValueCopy \
    )

#define Mdc_Map_Size(T_KeyT, T_ValueT) \
    Mdc_Object_Member(Mdc_Map(T_KeyT, T_ValueT), Size)

#define Mdc_Map_Swap(T_KeyT, T_ValueT) \
    Mdc_Object_Swap(Mdc_Map(T_KeyT, T_ValueT))

#endif /* MDC_C_CONTAINER_INTERNAL_MAP_MAP_NAME_MACRO_H_ */
