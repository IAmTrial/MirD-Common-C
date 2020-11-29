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

#include "../../../../../include/mdc/string/internal/char_traits/char_traits__char.h"

#include <stdio.h>
#include <string.h>

void Mdc_CharTraits_AssignChar(Mdc_Char)(Mdc_Char* r, const Mdc_Char* a) {
  *r = *a;
}

Mdc_Char* Mdc_CharTraits_AssignCStr(Mdc_Char)(Mdc_Char* p, size_t count, Mdc_Char a) {
  return memset(p, a, count);
}

bool Mdc_CharTraits_EqualChar(Mdc_Char)(Mdc_Char a, Mdc_Char b) {
  return (unsigned char) a == (unsigned char) b;
}

bool Mdc_CharTraits_LessThanChar(Mdc_Char)(Mdc_Char a, Mdc_Char b) {
  return (unsigned char) a < (unsigned char) b;
}

Mdc_Char* Mdc_CharTraits_CopyOverlapCStr(Mdc_Char)(
    Mdc_Char* dest,
    const Mdc_Char* src,
    size_t count
) {
  return memmove(dest, src, count);
}

Mdc_Char* Mdc_CharTraits_CopyNonoverlapCStr(Mdc_Char)(
    Mdc_Char* dest,
    const Mdc_Char* src,
    size_t count
) {
  return memcpy(dest, src, count);
}

int Mdc_CharTraits_CompareCStr(Mdc_Char)(
    const Mdc_Char* s1,
    const Mdc_Char* s2,
    size_t count
) {
  return memcmp(s1, s2, count);
}

size_t Mdc_CharTraits_LengthCStr(Mdc_Char)(const Mdc_Char* s) {
  return strlen(s);
}

const Mdc_Char* Mdc_CharTraits_FindCStr(Mdc_Char)(
    const Mdc_Char* p,
    size_t count,
    Mdc_Char ch
) {
  return memchr(p, ch, count);
}

Mdc_Char Mdc_CharTraits_ToCharType(Mdc_Char)(Mdc_Int c) {
  return (Mdc_Char) c;
}

Mdc_Int Mdc_CharTraits_ToIntType(Mdc_Char)(Mdc_Char c) {
  return (Mdc_Int) c;
}

bool Mdc_CharTraits_EqualIntType(Mdc_Char)(Mdc_Int c1, Mdc_Int c2) {
  return c1 == c2;
}

Mdc_Int Mdc_CharTraits_Eof(Mdc_Char)(void) {
  return EOF;
}

Mdc_Int Mdc_CharTraits_NotEof(Mdc_Char)(Mdc_Int e) {
  return Mdc_CharTraits_EqualIntType(Mdc_Char)(e, Mdc_CharTraits_Eof(Mdc_Char)())
      ? 0
      : e;
}
