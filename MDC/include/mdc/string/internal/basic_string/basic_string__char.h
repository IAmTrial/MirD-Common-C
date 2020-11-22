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

#ifndef MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__CHAR_H_
#define MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__CHAR_H_

#include "../char_traits/char_traits__char.h"
#include "basic_string_declare_macros.h"
#include "basic_string_name_macros.h"

#include "../../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(char)

#define Mdc_String Mdc_BasicString(char)

#define Mdc_String_ValueType Mdc_BasicString_ValueType(char)

#define Mdc_String_kNpos Mdc_BasicString_kNpos(char)

#define Mdc_String_InitEmpty Mdc_BasicString_InitEmpty(char)
#define Mdc_String_InitFromChar Mdc_BasicString_InitFromChar(char)
#define Mdc_String_InitStrTail Mdc_BasicString_InitStrTail(char)
#define Mdc_String_InitSubstr Mdc_BasicString_InitSubstr(char)
#define Mdc_String_InitFromCStr Mdc_BasicString_InitFromCStr(char)
#define Mdc_String_InitInitFromCStrTop Mdc_BasicString_InitFromCStrTop(char)
#define Mdc_String_InitCopy Mdc_BasicString_InitCopy(char)
#define Mdc_String_InitMove Mdc_BasicString_InitMove(char)

#define Mdc_String_Deinit Mdc_BasicString_Deinit(char)

#define Mdc_String_AssignCopy Mdc_BasicString_AssignCopy(char)
#define Mdc_String_AssignMove Mdc_BasicString_AssignMove(char)

#define Mdc_String_Access Mdc_BasicString_Access(char)
#define Mdc_String_AccessConst Mdc_BasicString_AccessConst(char)
#define Mdc_String_At Mdc_BasicString_At(char)
#define Mdc_String_AtConst Mdc_BasicString_AtConst(char)
#define Mdc_String_AppendStr Mdc_BasicString_AppendStr(char)
#define Mdc_String_AppendStrTail Mdc_BasicString_AppendStrTail(char)
#define Mdc_String_AppendSubstr Mdc_BasicString_AppendSubstr(char)
#define Mdc_String_AppendCStr Mdc_BasicString_AppendCStr(char)
#define Mdc_String_AppendCStrTop Mdc_BasicString_AppendCStrTop(char)
#define Mdc_String_Back Mdc_BasicString_Back(char)
#define Mdc_String_BackConst Mdc_BasicString_BackConst(char)
#define Mdc_String_Capacity Mdc_BasicString_Capacity(char)
#define Mdc_String_CompareStr Mdc_BasicString_CompareStr(char)
#define Mdc_String_CompareSubstr Mdc_BasicString_CompareSubstr(char)
#define Mdc_String_CompareSubstrs Mdc_BasicString_CompareSubstrs(char)
#define Mdc_String_CompareCStr Mdc_BasicString_CompareCStr(char)
#define Mdc_String_CompareCSubstr Mdc_BasicString_CompareCSubstr(char)
#define Mdc_String_CompareCSubstrs Mdc_BasicString_CompareCSubstrs(char)
#define Mdc_String_Clear Mdc_BasicString_Clear(char)
#define Mdc_String_CStr Mdc_BasicString_CStr(char)
#define Mdc_String_Data Mdc_BasicString_Data(char)
#define Mdc_String_DataConst Mdc_BasicString_DataConst(char)
#define Mdc_String_Empty Mdc_BasicString_Empty(char)
#define Mdc_String_EqualStr Mdc_BasicString_EqualStr(char)
#define Mdc_String_EqualCStr Mdc_BasicString_EqualCStr(char)
#define Mdc_String_Front Mdc_BasicString_Front(char)
#define Mdc_String_FrontConst Mdc_BasicString_FrontConst(char)
#define Mdc_String_Length Mdc_BasicString_Length(char)
#define Mdc_String_PopBack Mdc_BasicString_PopBack(char)
#define Mdc_String_PushBack Mdc_BasicString_PushBack(char)
#define Mdc_String_Reserve Mdc_BasicString_Reserve(char)
#define Mdc_String_ShrinkToFit Mdc_BasicString_ShrinkToFit(char)
#define Mdc_String_Size Mdc_BasicString_Size(char)
#define Mdc_String_Swap Mdc_BasicString_Swap(char)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__CHAR_H_ */
