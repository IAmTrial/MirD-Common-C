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

#ifndef MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR_H_
#define MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR_H_

#include "../char_traits.h"

struct Mdc_CharTraits* Mdc_CharTraitsChar_Init(
    struct Mdc_CharTraits* char_traits
);

void Mdc_CharTraitsChar_AssignChar(char* r, const char* a);
char* Mdc_CharTraitsChar_AssignStr(char* p, size_t count, char a);

bool Mdc_CharTraitsChar_EqualChar(char a, char b);
bool Mdc_CharTraitsChar_LessThanChar(char a, char b);

char* Mdc_CharTraitsChar_CopyOverlapStr(
    char* dest,
    const char* src,
    size_t count
);
char* Mdc_CharTraitsChar_CopyNonoverlapStr(
    char* dest,
    const char* src,
    size_t count
);

int Mdc_CharTraitsChar_CompareStr(
    const char* s1,
    const char* s2,
    size_t count
);

size_t Mdc_CharTraitsChar_LengthStr(const char* s);

const char* Mdc_CharTraitsChar_FindStr(
    const char* p,
    size_t count,
    char ch
);

char Mdc_CharTraitsChar_ToCharType(int c);
int Mdc_CharTraitsChar_ToIntType(char c);
bool Mdc_CharTraitsChar_EqualIntType(int c1, int c2);

int Mdc_CharTraitsChar_Eof(void);
int Mdc_CharTraitsChar_NotEof(int e);

#endif /* MDC_C_STRING_CHAR_TRAITS_CHAR_TRAITS_CHAR_H_ */
