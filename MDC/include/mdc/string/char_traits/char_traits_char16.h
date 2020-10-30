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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR16_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR16_H_

#include "../../std/stdbool.h"
#include "../../std/stdint.h"
#include "../../std/uchar.h"
#include "../char_traits.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

DLLEXPORT const struct Mdc_CharTraits*
Mdc_CharTraitsChar16_GetCharTraits(void);

DLLEXPORT void Mdc_CharTraitsChar16_AssignChar(
    char16_t* r,
    const char16_t* a
);

DLLEXPORT char16_t* Mdc_CharTraitsChar16_AssignStr(
    char16_t* p,
    size_t count,
    char16_t a
);

DLLEXPORT bool Mdc_CharTraitsChar16_EqualChar(char16_t a, char16_t b);
DLLEXPORT bool Mdc_CharTraitsChar16_LessThanChar(char16_t a, char16_t b);

DLLEXPORT char16_t* Mdc_CharTraitsChar16_CopyOverlapStr(
    char16_t* dest,
    const char16_t* src,
    size_t count
);

DLLEXPORT char16_t* Mdc_CharTraitsChar16_CopyNonoverlapStr(
    char16_t* dest,
    const char16_t* src,
    size_t count
);

DLLEXPORT int Mdc_CharTraitsChar16_CompareStr(
    const char16_t* s1,
    const char16_t* s2,
    size_t count
);

DLLEXPORT size_t Mdc_CharTraitsChar16_LengthStr(const char16_t* s);

DLLEXPORT const char16_t* Mdc_CharTraitsChar16_FindStr(
    const char16_t* p,
    size_t count,
    char16_t ch
);

DLLEXPORT char16_t Mdc_CharTraitsChar16_ToCharType(uint_least16_t c);
DLLEXPORT uint_least16_t Mdc_CharTraitsChar16_ToIntType(char16_t c);

DLLEXPORT bool Mdc_CharTraitsChar16_EqualIntType(
    uint_least16_t c1,
    uint_least16_t c2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR16_H_ */
