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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR32_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR32_H_

#include "../../std/stdbool.h"
#include "../../std/stdint.h"
#include "../../std/uchar.h"
#include "../char_traits.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT const struct Mdc_CharTraits*
Mdc_CharTraitsChar32_GetCharTraits(void);

DLLEXPORT void Mdc_CharTraitsChar32_AssignChar(
    char32_t* r,
    const char32_t* a
);

DLLEXPORT char32_t* Mdc_CharTraitsChar32_AssignStr(
    char32_t* p,
    size_t count,
    char32_t a
);

DLLEXPORT bool Mdc_CharTraitsChar32_EqualChar(char32_t a, char32_t b);
DLLEXPORT bool Mdc_CharTraitsChar32_LessThanChar(char32_t a, char32_t b);

DLLEXPORT char32_t* Mdc_CharTraitsChar32_CopyOverlapStr(
    char32_t* dest,
    const char32_t* src,
    size_t count
);

DLLEXPORT char32_t* Mdc_CharTraitsChar32_CopyNonoverlapStr(
    char32_t* dest,
    const char32_t* src,
    size_t count
);

DLLEXPORT int Mdc_CharTraitsChar32_CompareStr(
    const char32_t* s1,
    const char32_t* s2,
    size_t count
);

DLLEXPORT size_t Mdc_CharTraitsChar32_LengthStr(const char32_t* s);

DLLEXPORT const char32_t* Mdc_CharTraitsChar32_FindStr(
    const char32_t* p,
    size_t count,
    char32_t ch
);

DLLEXPORT char32_t Mdc_CharTraitsChar32_ToCharType(uint_least32_t c);
DLLEXPORT uint_least32_t Mdc_CharTraitsChar32_ToIntType(char32_t c);

DLLEXPORT bool Mdc_CharTraitsChar32_EqualIntType(
    uint_least32_t c1,
    uint_least32_t c2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR32_H_ */
