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

#define Mdc_BasicString__wchar_t__ValueType wchar_t

/**
 * Declarations
 */

MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(wchar_t)

/**
 * Aliases
 */

#define Mdc_WString Mdc_BasicString(wchar_t)

#define Mdc_WString_ValueType wchar_t

#define Mdc_WString_kNpos Mdc_BasicString_kNpos(wchar_t)

#define Mdc_WString_InitEmpty Mdc_BasicString_InitEmpty(wchar_t)
#define Mdc_WString_InitFromChar Mdc_BasicString_InitFromChar(wchar_t)
#define Mdc_WString_InitStrTail Mdc_BasicString_InitStrTail(wchar_t)
#define Mdc_WString_InitSubstr Mdc_BasicString_InitSubstr(wchar_t)
#define Mdc_WString_InitFromCStr Mdc_BasicString_InitFromCStr(wchar_t)
#define Mdc_WString_InitFromCStrTop Mdc_BasicString_InitFromCStrTop(wchar_t)
#define Mdc_WString_InitCopy Mdc_BasicString_InitCopy(wchar_t)
#define Mdc_WString_InitMove Mdc_BasicString_InitMove(wchar_t)

#define Mdc_WString_Deinit Mdc_BasicString_Deinit(wchar_t)

#define Mdc_WString_AssignCopy Mdc_BasicString_AssignCopy(wchar_t)
#define Mdc_WString_AssignMove Mdc_BasicString_AssignMove(wchar_t)

#define Mdc_WString_Access Mdc_BasicString_Access(wchar_t)
#define Mdc_WString_AccessConst Mdc_BasicString_AccessConst(wchar_t)
#define Mdc_WString_At Mdc_BasicString_At(wchar_t)
#define Mdc_WString_AtConst Mdc_BasicString_AtConst(wchar_t)
#define Mdc_WString_AppendStr Mdc_BasicString_AppendStr(wchar_t)
#define Mdc_WString_AppendStrTail Mdc_BasicString_AppendStrTail(wchar_t)
#define Mdc_WString_AppendSubstr Mdc_BasicString_AppendSubstr(wchar_t)
#define Mdc_WString_AppendCStr Mdc_BasicString_AppendCStr(wchar_t)
#define Mdc_WString_AppendCStrTop Mdc_BasicString_AppendCStrTop(wchar_t)
#define Mdc_WString_Back Mdc_BasicString_Back(wchar_t)
#define Mdc_WString_BackConst Mdc_BasicString_BackConst(wchar_t)
#define Mdc_WString_Capacity Mdc_BasicString_Capacity(wchar_t)
#define Mdc_WString_CompareStr Mdc_BasicString_CompareStr(wchar_t)
#define Mdc_WString_CompareSubstr Mdc_BasicString_CompareSubstr(wchar_t)
#define Mdc_WString_CompareSubstrs Mdc_BasicString_CompareSubstrs(wchar_t)
#define Mdc_WString_CompareCStr Mdc_BasicString_CompareCStr(wchar_t)
#define Mdc_WString_CompareCSubstr Mdc_BasicString_CompareCSubstr(wchar_t)
#define Mdc_WString_CompareCSubstrs Mdc_BasicString_CompareCSubstrs(wchar_t)
#define Mdc_WString_Clear Mdc_BasicString_Clear(wchar_t)
#define Mdc_WString_CStr Mdc_BasicString_CStr(wchar_t)
#define Mdc_WString_Data Mdc_BasicString_Data(wchar_t)
#define Mdc_WString_DataConst Mdc_BasicString_DataConst(wchar_t)
#define Mdc_WString_Empty Mdc_BasicString_Empty(wchar_t)
#define Mdc_WString_EqualStr Mdc_BasicString_EqualStr(wchar_t)
#define Mdc_WString_EqualCStr Mdc_BasicString_EqualCStr(wchar_t)
#define Mdc_WString_Front Mdc_BasicString_Front(wchar_t)
#define Mdc_WString_FrontConst Mdc_BasicString_FrontConst(wchar_t)
#define Mdc_WString_Length Mdc_BasicString_Length(wchar_t)
#define Mdc_WString_PopBack Mdc_BasicString_PopBack(wchar_t)
#define Mdc_WString_PushBack Mdc_BasicString_PushBack(wchar_t)
#define Mdc_WString_Reserve Mdc_BasicString_Reserve(wchar_t)
#define Mdc_WString_ShrinkToFit Mdc_BasicString_ShrinkToFit(wchar_t)
#define Mdc_WString_Size Mdc_BasicString_Size(wchar_t)
#define Mdc_WString_Swap Mdc_BasicString_Swap(wchar_t)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__WCHAR_T_H_ */
