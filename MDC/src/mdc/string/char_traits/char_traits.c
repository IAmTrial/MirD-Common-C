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

#include "../../../../include/mdc/string/char_traits.h"

#include <string.h>
#include <stdio.h>

void Mdc_CharTraits_AssignChar(char* r, const char* a) {
  *r = *a;
}

char* Mdc_CharTraits_AssignStr(char* p, size_t count, char a) {
  memset(p, a, count);

  return p;
}

bool Mdc_CharTraits_EqualChar(char a, char b) {
  unsigned char ua;
  unsigned char ub;

  ua = a;
  ub = b;

  return ua == ub;
}

bool Mdc_CharTraits_LessThanChar(char a, char b) {
  unsigned char ua;
  unsigned char ub;

  ua = a;
  ub = b;

  return ua < ub;
}

char* Mdc_CharTraits_MoveStr(char* dest, const char* src, size_t count) {
  memmove(dest, src, count);

  return dest;
}

char* Mdc_CharTraits_CopyStr(char* dest, const char* src, size_t count) {
  memcpy(dest, src, count);

  return dest;
}

int Mdc_CharTraits_CompareStr(const char* s1, const char* s2, size_t count) {
  return memcmp(s1, s2, count);
}

size_t Mdc_CharTraits_LengthStr(const char* s) {
  return strlen(s);
}

const char* Mdc_CharTraits_FindStr(const char* p, size_t count, char ch) {
  return memchr(p, ch, count);
}

char Mdc_CharTraits_ToCharType(int c) {
  return (char) c;
}

int Mdc_CharTraits_ToIntType(char c) {
  return (int) c;
}

bool Mdc_CharTraits_EqualIntType(int c1, int c2) {
  return c1 == c2;
}

int Mdc_CharTraits_Eof(void) {
  return EOF;
}

int Mdc_CharTraits_NotEof(int e) {
  return e != EOF;
}
