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

void Mdc_CharTraits_AssignChar(char)(char* r, const char* a) {
  *r = *a;
}

char* Mdc_CharTraits_AssignCStr(char)(char* p, size_t count, char a) {
  return memset(p, a, count);
}

bool Mdc_CharTraits_EqualChar(char)(char a, char b) {
  return (unsigned char) a == (unsigned char) b;
}

bool Mdc_CharTraits_LessThanChar(char)(char a, char b) {
  return (unsigned char) a < (unsigned char) b;
}

char* Mdc_CharTraits_CopyOverlapCStr(char)(
    char* dest,
    const char* src,
    size_t count
) {
  return memmove(dest, src, count);
}

char* Mdc_CharTraits_CopyNonoverlapCStr(char)(
    char* dest,
    const char* src,
    size_t count
) {
  return memcpy(dest, src, count);
}

int Mdc_CharTraits_CompareCStr(char)(
    const char* s1,
    const char* s2,
    size_t count
) {
  return memcmp(s1, s2, count);
}

size_t Mdc_CharTraits_LengthCStr(char)(const char* s) {
  return strlen(s);
}

const char* Mdc_CharTraits_FindCStr(char)(
    const char* p,
    size_t count,
    char ch
) {
  return memchr(p, ch, count);
}

char Mdc_CharTraits_ToCharType(char)(int c) {
  return (char) c;
}

int Mdc_CharTraits_ToIntType(char)(char c) {
  return (int) c;
}

bool Mdc_CharTraits_EqualIntType(char)(int c1, int c2) {
  return c1 == c2;
}

int Mdc_CharTraits_Eof(char)(void) {
  return EOF;
}

int Mdc_CharTraits_NotEof(char)(int e) {
  return Mdc_CharTraits_EqualIntType(char)(e, Mdc_CharTraits_Eof(char)())
      ? 0
      : e;
}
