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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_TCHAR_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_TCHAR_H_

#include "../char_traits.h"
#include "char_traits_char.h"
#include "char_traits_wchar.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if UNICODE

#define Mdc_CharTraitsTChar_GetCharTraits() \
    Mdc_CharTraitsWChar_GetCharTraits()

#define Mdc_CharTraitsTChar_AssignChar(r, a) \
    Mdc_CharTraitsWChar_AssignChar(r, a)

#define Mdc_CharTraitsTChar_AssignStr(p, count, a) \
    Mdc_CharTraitsWChar_AssignStr(p, count, a)

#define Mdc_CharTraitsTChar_EqualChar(a, b) \
    Mdc_CharTraitsWChar_EqualChar(a, b)

#define Mdc_CharTraitsTChar_LessThanChar(a, b) \
    Mdc_CharTraitsWChar_LessThanChar(a, b)

#define Mdc_CharTraitsTChar_CopyOverlapStr(dest, src, count) \
    Mdc_CharTraitsWChar_CopyOverlapStr(dest, src, count)

#define Mdc_CharTraitsTChar_CopyNonoverlapStr(dest, src, count) \
    Mdc_CharTraitsWChar_CopyNonoverlapStr(dest, src, count)

#define Mdc_CharTraitsTChar_CompareStr(s1, s2, count) \
    Mdc_CharTraitsWChar_CompareStr(s1, s2, count)

#define Mdc_CharTraitsTChar_LengthStr(s) \
    Mdc_CharTraitsWChar_LengthStr(s)

#define Mdc_CharTraitsTChar_FindStr(p, count, ch) \
    Mdc_CharTraitsWChar_FindStr(p, count, ch)

#define Mdc_CharTraitsTChar_ToCharType(c) \
    Mdc_CharTraitsWChar_ToCharType(c)

#define Mdc_CharTraitsTChar_ToIntType(c) \
    Mdc_CharTraitsWChar_ToIntType(c)

#define Mdc_CharTraitsTChar_EqualIntType(c1, c2) \
    Mdc_CharTraitsWChar_EqualIntType(c1, c2)

#define Mdc_CharTraitsTChar_Eof() \
    Mdc_CharTraitsWChar_Eof()

#define Mdc_CharTraitsTChar_NotEof(e) \
    Mdc_CharTraitsWChar_NotEof(e)

#else

#define Mdc_CharTraitsTChar_GetCharTraits() \
    Mdc_CharTraitsChar_GetCharTraits()

#define Mdc_CharTraitsTChar_AssignChar(r, a) \
    Mdc_CharTraitsChar_AssignChar(r, a)

#define Mdc_CharTraitsTChar_AssignStr(p, count, a) \
    Mdc_CharTraitsChar_AssignStr(p, count, a)

#define Mdc_CharTraitsTChar_EqualChar(a, b) \
    Mdc_CharTraitsChar_EqualChar(a, b)

#define Mdc_CharTraitsTChar_LessThanChar(a, b) \
    Mdc_CharTraitsChar_LessThanChar(a, b)

#define Mdc_CharTraitsTChar_CopyOverlapStr(dest, src, count) \
    Mdc_CharTraitsChar_CopyOverlapStr(dest, src, count)

#define Mdc_CharTraitsTChar_CopyNonoverlapStr(dest, src, count) \
    Mdc_CharTraitsChar_CopyNonoverlapStr(dest, src, count)

#define Mdc_CharTraitsTChar_CompareStr(s1, s2, count) \
    Mdc_CharTraitsChar_CompareStr(s1, s2, count)

#define Mdc_CharTraitsTChar_LengthStr(s) \
    Mdc_CharTraitsChar_LengthStr(s)

#define Mdc_CharTraitsTChar_FindStr(p, count, ch) \
    Mdc_CharTraitsChar_FindStr(p, count, ch)

#define Mdc_CharTraitsTChar_ToCharType(c) \
    Mdc_CharTraitsChar_ToCharType(c)

#define Mdc_CharTraitsTChar_ToIntType(c) \
    Mdc_CharTraitsChar_ToIntType(c)

#define Mdc_CharTraitsTChar_EqualIntType(c1, c2) \
    Mdc_CharTraitsChar_EqualIntType(c1, c2)

#define Mdc_CharTraitsTChar_Eof() \
    Mdc_CharTraitsChar_Eof()

#define Mdc_CharTraitsTChar_NotEof(e) \
    Mdc_CharTraitsChar_NotEof(e)

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_TCHAR_H_ */
