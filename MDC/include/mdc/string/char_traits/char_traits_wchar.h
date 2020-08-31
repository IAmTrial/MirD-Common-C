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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_WCHAR_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_WCHAR_H_

#include <stddef.h>

#include "../../std/wchar.h"
#include "../char_traits.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT struct Mdc_CharTraits* Mdc_CharTraitsWChar_Init(
    struct Mdc_CharTraits* char_traits
);

DLLEXPORT void Mdc_CharTraitsWChar_AssignChar(wchar_t* r, const wchar_t* a);
DLLEXPORT wchar_t* Mdc_CharTraitsWChar_AssignStr(
    wchar_t* p,
    size_t count,
    wchar_t a
);

DLLEXPORT bool Mdc_CharTraitsWChar_EqualChar(wchar_t a, wchar_t b);
DLLEXPORT bool Mdc_CharTraitsWChar_LessThanChar(wchar_t a, wchar_t b);

DLLEXPORT wchar_t* Mdc_CharTraitsWChar_CopyOverlapStr(
    wchar_t* dest,
    const wchar_t* src,
    size_t count
);
DLLEXPORT wchar_t* Mdc_CharTraitsWChar_CopyNonoverlapStr(
    wchar_t* dest,
    const wchar_t* src,
    size_t count
);

DLLEXPORT int Mdc_CharTraitsWChar_CompareStr(
    const wchar_t* s1,
    const wchar_t* s2,
    size_t count
);

DLLEXPORT size_t Mdc_CharTraitsWChar_LengthStr(const wchar_t* s);

DLLEXPORT const wchar_t* Mdc_CharTraitsWChar_FindStr(
    const wchar_t* p,
    size_t count,
    wchar_t ch
);

DLLEXPORT wchar_t Mdc_CharTraitsWChar_ToCharType(wint_t c);
DLLEXPORT wint_t Mdc_CharTraitsWChar_ToIntType(wchar_t c);
DLLEXPORT bool Mdc_CharTraitsWChar_EqualIntType(wint_t c1, wint_t c2);

DLLEXPORT wint_t Mdc_CharTraitsWChar_Eof(void);
DLLEXPORT wint_t Mdc_CharTraitsWChar_NotEof(wint_t e);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_WCHAR_H_ */
