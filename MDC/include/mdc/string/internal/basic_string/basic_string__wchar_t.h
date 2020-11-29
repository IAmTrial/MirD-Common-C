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

#ifndef MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__WCHAR_T_H_
#define MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__WCHAR_T_H_

#include "../char_traits/char_traits__wchar_t.h"
#include "basic_string_declare_macros.h"
#include "basic_string_name_macros.h"

#include "../../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Types
 */

#define Mdc_BasicString__Mdc_WChar__ValueType Mdc_WChar

/**
 * Declarations
 */

MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(Mdc_WChar)

/**
 * Aliases
 */

#define Mdc_WString Mdc_BasicString(Mdc_WChar)

#define Mdc_WString_ValueType Mdc_WChar

#define Mdc_WString_kNpos Mdc_BasicString_kNpos(Mdc_WChar)

#define Mdc_WString_InitEmpty Mdc_BasicString_InitEmpty(Mdc_WChar)
#define Mdc_WString_InitFromChar Mdc_BasicString_InitFromChar(Mdc_WChar)
#define Mdc_WString_InitStrTail Mdc_BasicString_InitStrTail(Mdc_WChar)
#define Mdc_WString_InitSubstr Mdc_BasicString_InitSubstr(Mdc_WChar)
#define Mdc_WString_InitFromCStr Mdc_BasicString_InitFromCStr(Mdc_WChar)
#define Mdc_WString_InitFromCStrTop Mdc_BasicString_InitFromCStrTop(Mdc_WChar)
#define Mdc_WString_InitCopy Mdc_BasicString_InitCopy(Mdc_WChar)
#define Mdc_WString_InitMove Mdc_BasicString_InitMove(Mdc_WChar)

#define Mdc_WString_Deinit Mdc_BasicString_Deinit(Mdc_WChar)

#define Mdc_WString_AssignCopy Mdc_BasicString_AssignCopy(Mdc_WChar)
#define Mdc_WString_AssignMove Mdc_BasicString_AssignMove(Mdc_WChar)

#define Mdc_WString_Access Mdc_BasicString_Access(Mdc_WChar)
#define Mdc_WString_AccessConst Mdc_BasicString_AccessConst(Mdc_WChar)
#define Mdc_WString_At Mdc_BasicString_At(Mdc_WChar)
#define Mdc_WString_AtConst Mdc_BasicString_AtConst(Mdc_WChar)
#define Mdc_WString_AppendStr Mdc_BasicString_AppendStr(Mdc_WChar)
#define Mdc_WString_AppendStrTail Mdc_BasicString_AppendStrTail(Mdc_WChar)
#define Mdc_WString_AppendSubstr Mdc_BasicString_AppendSubstr(Mdc_WChar)
#define Mdc_WString_AppendCStr Mdc_BasicString_AppendCStr(Mdc_WChar)
#define Mdc_WString_AppendCStrTop Mdc_BasicString_AppendCStrTop(Mdc_WChar)
#define Mdc_WString_Back Mdc_BasicString_Back(Mdc_WChar)
#define Mdc_WString_BackConst Mdc_BasicString_BackConst(Mdc_WChar)
#define Mdc_WString_Capacity Mdc_BasicString_Capacity(Mdc_WChar)
#define Mdc_WString_CompareStr Mdc_BasicString_CompareStr(Mdc_WChar)
#define Mdc_WString_CompareSubstr Mdc_BasicString_CompareSubstr(Mdc_WChar)
#define Mdc_WString_CompareSubstrs Mdc_BasicString_CompareSubstrs(Mdc_WChar)
#define Mdc_WString_CompareCStr Mdc_BasicString_CompareCStr(Mdc_WChar)
#define Mdc_WString_CompareCSubstr Mdc_BasicString_CompareCSubstr(Mdc_WChar)
#define Mdc_WString_CompareCSubstrs Mdc_BasicString_CompareCSubstrs(Mdc_WChar)
#define Mdc_WString_Clear Mdc_BasicString_Clear(Mdc_WChar)
#define Mdc_WString_CStr Mdc_BasicString_CStr(Mdc_WChar)
#define Mdc_WString_Data Mdc_BasicString_Data(Mdc_WChar)
#define Mdc_WString_DataConst Mdc_BasicString_DataConst(Mdc_WChar)
#define Mdc_WString_Empty Mdc_BasicString_Empty(Mdc_WChar)
#define Mdc_WString_EqualStr Mdc_BasicString_EqualStr(Mdc_WChar)
#define Mdc_WString_EqualCStr Mdc_BasicString_EqualCStr(Mdc_WChar)
#define Mdc_WString_Front Mdc_BasicString_Front(Mdc_WChar)
#define Mdc_WString_FrontConst Mdc_BasicString_FrontConst(Mdc_WChar)
#define Mdc_WString_Length Mdc_BasicString_Length(Mdc_WChar)
#define Mdc_WString_PopBack Mdc_BasicString_PopBack(Mdc_WChar)
#define Mdc_WString_PushBack Mdc_BasicString_PushBack(Mdc_WChar)
#define Mdc_WString_Reserve Mdc_BasicString_Reserve(Mdc_WChar)
#define Mdc_WString_ShrinkToFit Mdc_BasicString_ShrinkToFit(Mdc_WChar)
#define Mdc_WString_Size Mdc_BasicString_Size(Mdc_WChar)
#define Mdc_WString_Swap Mdc_BasicString_Swap(Mdc_WChar)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__WCHAR_T_H_ */
