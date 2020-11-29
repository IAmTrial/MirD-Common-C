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

/**
 * Types
 */

#define Mdc_BasicString__Mdc_Char__ValueType Mdc_Char

/**
 * Declarations
 */

MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(Mdc_Char)

/**
 * Aliases
 */

#define Mdc_String Mdc_BasicString(Mdc_Char)

#define Mdc_String_ValueType Mdc_Char

#define Mdc_String_kNpos Mdc_BasicString_kNpos(Mdc_Char)

#define Mdc_String_InitEmpty Mdc_BasicString_InitEmpty(Mdc_Char)
#define Mdc_String_InitFromChar Mdc_BasicString_InitFromChar(Mdc_Char)
#define Mdc_String_InitStrTail Mdc_BasicString_InitStrTail(Mdc_Char)
#define Mdc_String_InitSubstr Mdc_BasicString_InitSubstr(Mdc_Char)
#define Mdc_String_InitFromCStr Mdc_BasicString_InitFromCStr(Mdc_Char)
#define Mdc_String_InitFromCStrTop Mdc_BasicString_InitFromCStrTop(Mdc_Char)
#define Mdc_String_InitCopy Mdc_BasicString_InitCopy(Mdc_Char)
#define Mdc_String_InitMove Mdc_BasicString_InitMove(Mdc_Char)

#define Mdc_String_Deinit Mdc_BasicString_Deinit(Mdc_Char)

#define Mdc_String_AssignCopy Mdc_BasicString_AssignCopy(Mdc_Char)
#define Mdc_String_AssignMove Mdc_BasicString_AssignMove(Mdc_Char)

#define Mdc_String_Access Mdc_BasicString_Access(Mdc_Char)
#define Mdc_String_AccessConst Mdc_BasicString_AccessConst(Mdc_Char)
#define Mdc_String_At Mdc_BasicString_At(Mdc_Char)
#define Mdc_String_AtConst Mdc_BasicString_AtConst(Mdc_Char)
#define Mdc_String_AppendStr Mdc_BasicString_AppendStr(Mdc_Char)
#define Mdc_String_AppendStrTail Mdc_BasicString_AppendStrTail(Mdc_Char)
#define Mdc_String_AppendSubstr Mdc_BasicString_AppendSubstr(Mdc_Char)
#define Mdc_String_AppendCStr Mdc_BasicString_AppendCStr(Mdc_Char)
#define Mdc_String_AppendCStrTop Mdc_BasicString_AppendCStrTop(Mdc_Char)
#define Mdc_String_Back Mdc_BasicString_Back(Mdc_Char)
#define Mdc_String_BackConst Mdc_BasicString_BackConst(Mdc_Char)
#define Mdc_String_Capacity Mdc_BasicString_Capacity(Mdc_Char)
#define Mdc_String_CompareStr Mdc_BasicString_CompareStr(Mdc_Char)
#define Mdc_String_CompareSubstr Mdc_BasicString_CompareSubstr(Mdc_Char)
#define Mdc_String_CompareSubstrs Mdc_BasicString_CompareSubstrs(Mdc_Char)
#define Mdc_String_CompareCStr Mdc_BasicString_CompareCStr(Mdc_Char)
#define Mdc_String_CompareCSubstr Mdc_BasicString_CompareCSubstr(Mdc_Char)
#define Mdc_String_CompareCSubstrs Mdc_BasicString_CompareCSubstrs(Mdc_Char)
#define Mdc_String_Clear Mdc_BasicString_Clear(Mdc_Char)
#define Mdc_String_CStr Mdc_BasicString_CStr(Mdc_Char)
#define Mdc_String_Data Mdc_BasicString_Data(Mdc_Char)
#define Mdc_String_DataConst Mdc_BasicString_DataConst(Mdc_Char)
#define Mdc_String_Empty Mdc_BasicString_Empty(Mdc_Char)
#define Mdc_String_EqualStr Mdc_BasicString_EqualStr(Mdc_Char)
#define Mdc_String_EqualCStr Mdc_BasicString_EqualCStr(Mdc_Char)
#define Mdc_String_Front Mdc_BasicString_Front(Mdc_Char)
#define Mdc_String_FrontConst Mdc_BasicString_FrontConst(Mdc_Char)
#define Mdc_String_Length Mdc_BasicString_Length(Mdc_Char)
#define Mdc_String_PopBack Mdc_BasicString_PopBack(Mdc_Char)
#define Mdc_String_PushBack Mdc_BasicString_PushBack(Mdc_Char)
#define Mdc_String_Reserve Mdc_BasicString_Reserve(Mdc_Char)
#define Mdc_String_ShrinkToFit Mdc_BasicString_ShrinkToFit(Mdc_Char)
#define Mdc_String_Size Mdc_BasicString_Size(Mdc_Char)
#define Mdc_String_Swap Mdc_BasicString_Swap(Mdc_Char)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING__CHAR_H_ */
