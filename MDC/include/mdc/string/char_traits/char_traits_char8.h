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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR8_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR8_H_

#include "../../std/stdbool.h"
#include "../../std/uchar.h"
#include "../char_traits.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT const struct Mdc_CharTraits*
Mdc_CharTraitsChar8_GetCharTraits(void);

DLLEXPORT void Mdc_CharTraitsChar8_AssignChar(char8_t* r, const char8_t* a);

DLLEXPORT char8_t* Mdc_CharTraitsChar8_AssignStr(
    char8_t* p,
    size_t count,
    char8_t a
);

DLLEXPORT bool Mdc_CharTraitsChar8_EqualChar(char8_t a, char8_t b);
DLLEXPORT bool Mdc_CharTraitsChar8_LessThanChar(char8_t a, char8_t b);

DLLEXPORT char8_t* Mdc_CharTraitsChar8_CopyOverlapStr(
    char8_t* dest,
    const char8_t* src,
    size_t count
);
DLLEXPORT char8_t* Mdc_CharTraitsChar8_CopyNonoverlapStr(
    char8_t* dest,
    const char8_t* src,
    size_t count
);

DLLEXPORT int Mdc_CharTraitsChar8_CompareStr(
    const char8_t* s1,
    const char8_t* s2,
    size_t count
);

DLLEXPORT size_t Mdc_CharTraitsChar8_LengthStr(const char8_t* s);

DLLEXPORT const char8_t* Mdc_CharTraitsChar8_FindStr(
    const char8_t* p,
    size_t count,
    char8_t ch
);

DLLEXPORT char8_t Mdc_CharTraitsChar8_ToCharType(unsigned int c);
DLLEXPORT unsigned int Mdc_CharTraitsChar8_ToIntType(char8_t c);

DLLEXPORT bool Mdc_CharTraitsChar8_EqualIntType(
    unsigned int c1,
    unsigned int c2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR8_H_ */
