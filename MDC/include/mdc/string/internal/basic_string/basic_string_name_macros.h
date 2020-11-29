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

#ifndef MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_NAME_MACROS_H_
#define MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_NAME_MACROS_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"

#define Mdc_BasicString(T_CharT) \
    MDC_MACRO_CONCAT( \
        Mdc_BasicString, \
        MDC_MACRO_TEMPLATE_1(MDC_T(T_CharT)) \
    )

/**
 * Constants
 */

#define Mdc_BasicString_kNpos(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), kNpos)

/**
 * Initialize / Deinitialize
 */

#define Mdc_BasicString_InitEmpty(T_CharT) \
    Mdc_Object_InitDefault(Mdc_BasicString(T_CharT))

#define Mdc_BasicString_InitFromChar(T_CharT) \
    Mdc_Object_InitFrom_2( \
        Mdc_BasicString(T_CharT), \
        MDC_T(Mdc_Size), \
        MDC_T(T_CharT) \
    )

#define Mdc_BasicString_InitStrTail(T_CharT) \
    Mdc_Object_InitFrom_2( \
        Mdc_BasicString(T_CharT), \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T(Mdc_Size) \
    )

#define Mdc_BasicString_InitSubstr(T_CharT) \
    Mdc_Object_InitFrom_3( \
        Mdc_BasicString(T_CharT), \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T(Mdc_Size), \
        MDC_T(Mdc_Size) \
    )

#define Mdc_BasicString_InitFromCStr(T_CharT) \
    Mdc_Object_InitFrom_1(Mdc_BasicString(T_CharT), MDC_T_PC(T_CharT))

#define Mdc_BasicString_InitFromCStrTop(T_CharT) \
    Mdc_Object_InitFrom_2( \
        Mdc_BasicString(T_CharT), \
        MDC_T_PC(T_CharT), \
        MDC_T(Mdc_Size) \
    )

#define Mdc_BasicString_InitCopy(T_CharT) \
    Mdc_Object_InitCopy(Mdc_BasicString(T_CharT))

#define Mdc_BasicString_InitMove(T_CharT) \
    Mdc_Object_InitMove(Mdc_BasicString(T_CharT))

#define Mdc_BasicString_Deinit(T_CharT) \
    Mdc_Object_Deinit(Mdc_BasicString(T_CharT))

/**
 * Assignment
 */

#define Mdc_BasicString_AssignCopy(T_CharT) \
    Mdc_Object_AssignCopy(Mdc_BasicString(T_CharT))

#define Mdc_BasicString_AssignMove(T_CharT) \
    Mdc_Object_AssignMove(Mdc_BasicString(T_CharT))

/**
 * Comparison
 */

#define Mdc_BasicString_EqualStr(T_CharT) \
    Mdc_Object_Equal( \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T_PC(Mdc_BasicString(T_CharT)) \
    )

#define Mdc_BasicString_EqualCStr(T_CharT) \
    Mdc_Object_Equal( \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T_PC(T_CharT) \
    )

#define Mdc_BasicString_CompareStr(T_CharT) \
    Mdc_Object_Compare( \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T_PC(Mdc_BasicString(T_CharT)) \
    )

#define Mdc_BasicString_CompareSubstr(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), CompareSubstr)

#define Mdc_BasicString_CompareSubstrs(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), CompareSubstrs)

#define Mdc_BasicString_CompareCStr(T_CharT) \
    Mdc_Object_Compare( \
        MDC_T_PC(Mdc_BasicString(T_CharT)), \
        MDC_T_PC(T_CharT) \
    )

#define Mdc_BasicString_CompareCSubstr(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), CompareCSubstr)

#define Mdc_BasicString_CompareCSubstrs(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), CompareCSubstrs)

/**
 * General Functions
 */

#define Mdc_BasicString_Access(T_CharT) \
    Mdc_Object_Subscript(Mdc_BasicString(T_CharT), MDC_T(size_t))

#define Mdc_BasicString_AccessConst(T_CharT) \
    Mdc_Object_SubscriptConst(Mdc_BasicString(T_CharT), MDC_T(size_t))

#define Mdc_BasicString_At(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), At)

#define Mdc_BasicString_AtConst(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), AtConst)

#define Mdc_BasicString_AppendStr(T_CharT) \
    Mdc_Object_AssignAdd(Mdc_BasicString(T_CharT), Mdc_BasicString(T_CharT))

#define Mdc_BasicString_AppendStrTail(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), AppendStrTail)

#define Mdc_BasicString_AppendSubstr(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), AppendSubstr)

#define Mdc_BasicString_AppendCStr(T_CharT) \
    Mdc_Object_AssignAdd(Mdc_BasicString(T_CharT), MDC_T_PC(T_CharT))

#define Mdc_BasicString_AppendCStrTop(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), AppendCStrTop)

#define Mdc_BasicString_Back(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Back)

#define Mdc_BasicString_BackConst(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), BackConst)

#define Mdc_BasicString_Capacity(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Capacity)

#define Mdc_BasicString_Clear(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Clear)

#define Mdc_BasicString_CStr(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), CStr)

#define Mdc_BasicString_Data(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Data)

#define Mdc_BasicString_DataConst(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), DataConst)

#define Mdc_BasicString_Empty(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Empty)

#define Mdc_BasicString_Front(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Front)

#define Mdc_BasicString_FrontConst(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), FrontConst)

#define Mdc_BasicString_Length(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Length)

#define Mdc_BasicString_PopBack(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), PopBack)

#define Mdc_BasicString_PushBack(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), PushBack)

#define Mdc_BasicString_Reserve(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Reserve)

#define Mdc_BasicString_ShrinkToFit(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), ShrinkToFit)

#define Mdc_BasicString_Size(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), Size)

#define Mdc_BasicString_Swap(T_CharT) \
    Mdc_Object_Swap(Mdc_BasicString(T_CharT))

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_NAME_MACROS_H_ */
