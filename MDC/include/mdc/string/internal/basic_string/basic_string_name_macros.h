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

#define Mdc_BasicString(CharT) \
    Mdc_BasicString__##CharT

/**
 * Types
 */

#define Mdc_BasicString_TraitsType(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __TraitsType)

#define Mdc_BasicString_ValueType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __ValueType)

/**
 * Constants
 */

#define Mdc_BasicString_kNpos(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __kNpos)

/**
 * Functions
 */

#define Mdc_BasicString_InitEmpty(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitEmpty)

#define Mdc_BasicString_InitFromChar(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitFromChar)

#define Mdc_BasicString_InitStrTail(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitStrTail)

#define Mdc_BasicString_InitSubstr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitSubstr)

#define Mdc_BasicString_InitFromCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitFromCStr)

#define Mdc_BasicString_InitFromCStrTop(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitFromCStrTop)

#define Mdc_BasicString_InitCopy(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitCopy)

#define Mdc_BasicString_InitMove(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __InitMove)

#define Mdc_BasicString_Deinit(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Deinit)

#define Mdc_BasicString_AssignCopy(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssignCopy)

#define Mdc_BasicString_AssignMove(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssignMove)

#define Mdc_BasicString_Access(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Access)

#define Mdc_BasicString_AccessConst(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AccessConst)

#define Mdc_BasicString_At(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __At)

#define Mdc_BasicString_AtConst(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AtConst)

#define Mdc_BasicString_AppendStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AppendStr)

#define Mdc_BasicString_AppendStrTail(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AppendStrTail)

#define Mdc_BasicString_AppendSubstr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AppendSubstr)

#define Mdc_BasicString_AppendCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AppendCStr)

#define Mdc_BasicString_AppendCStrTop(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AppendCStrTop)

#define Mdc_BasicString_Back(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Back)

#define Mdc_BasicString_BackConst(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __BackConst)

#define Mdc_BasicString_Capacity(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Capacity)

#define Mdc_BasicString_CompareStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareStr)

#define Mdc_BasicString_CompareSubstr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareSubstr)

#define Mdc_BasicString_CompareSubstrs(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareSubstrs)

#define Mdc_BasicString_CompareCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareCStr)

#define Mdc_BasicString_CompareCSubstr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareCSubstr)

#define Mdc_BasicString_CompareCSubstrs(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CompareCSubstrs)

#define Mdc_BasicString_Clear(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Clear)

#define Mdc_BasicString_CStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __CStr)

#define Mdc_BasicString_Data(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Data)

#define Mdc_BasicString_DataConst(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __DataConst)

#define Mdc_BasicString_Empty(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Empty)

#define Mdc_BasicString_EqualStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __EqualStr)

#define Mdc_BasicString_EqualCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __EqualCStr)

#define Mdc_BasicString_Front(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Front)

#define Mdc_BasicString_FrontConst(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __FrontConst)

#define Mdc_BasicString_Length(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Length)

#define Mdc_BasicString_PopBack(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __PopBack)

#define Mdc_BasicString_PushBack(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __PushBack)

#define Mdc_BasicString_Reserve(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Reserve)

#define Mdc_BasicString_ShrinkToFit(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __ShrinkToFit)

#define Mdc_BasicString_Size(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Size)

#define Mdc_BasicString_Swap(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __Swap)

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_NAME_MACROS_H_ */
