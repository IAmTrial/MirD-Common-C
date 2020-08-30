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

/**
 * Static functions
 */

static void Mdc_CharTraitsChar_AssignCharAsVoid(void* r, const void* a) {
  Mdc_CharTraitsChar_AssignChar(r, a);
}

static void* Mdc_CharTraitsChar_AssignStrAsVoid(
    void* p,
    size_t count,
    uintmax_t a
) {
  return Mdc_CharTraitsChar_AssignStr(p, count, (char) a);
}

static bool Mdc_CharTraitsChar_EqualCharAsVoid(uintmax_t a, uintmax_t b) {
  return Mdc_CharTraitsChar_EqualChar((char) a, (char) b);
}

static bool Mdc_CharTraitsChar_LessThanCharAsVoid(uintmax_t a, uintmax_t b) {
  return Mdc_CharTraitsChar_LessThanChar((char) a, (char) b);
}

static void* Mdc_CharTraitsChar_CopyOverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar_CopyOverlapStr(dest, src, count);
}

static void* Mdc_CharTraitsChar_CopyNonoverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar_CopyNonoverlapStr(dest, src, count);
}

static int Mdc_CharTraitsChar_CompareStrAsVoid(
    const void* s1,
    const void* s2,
    size_t count
) {
  return Mdc_CharTraitsChar_CompareStr(s1, s2, count);
}

static size_t Mdc_CharTraitsChar_LengthStrAsVoid(const void* s) {
  return Mdc_CharTraitsChar_LengthStr(s);
}

static const void* Mdc_CharTraitsChar_FindStrAsVoid(
    const void* p,
    size_t count,
    uintmax_t ch
) {
  return Mdc_CharTraitsChar_FindStr(p, count, (char) ch);
}

static uintmax_t Mdc_CharTraitsChar_ToCharTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar_ToCharType((int) c);
}

static uintmax_t Mdc_CharTraitsChar_ToIntTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar_ToIntType((char) c);
}

static bool Mdc_CharTraitsChar_EqualIntTypeAsVoid(
    uintmax_t c1,
    uintmax_t c2
) {
  return Mdc_CharTraitsChar_EqualIntType((int) c1, (int) c2);
}

static uintmax_t Mdc_CharTraitsChar_EofAsVoid(void) {
  return Mdc_CharTraitsChar_Eof();
}

static uintmax_t Mdc_CharTraitsChar_NotEofAsVoid(uintmax_t e) {
  return Mdc_CharTraitsChar_NotEof((int) e);
}

/**
 * External functions
 */

struct Mdc_CharTraits* Mdc_CharTraitsChar_Init(
    struct Mdc_CharTraits* char_traits
) {
  struct Mdc_CharTraitsSizes* sizes = &char_traits->sizes;
  struct Mdc_CharTraitsFunctions* functions = &char_traits->functions;

  /* Set sizes. */
  sizes->ch_size = sizeof(char);
  sizes->int_size = sizeof(int);

  /* Set functions. */
  functions->assign_char = &Mdc_CharTraitsChar_AssignCharAsVoid;
  functions->assign_str = &Mdc_CharTraitsChar_AssignStrAsVoid;
  functions->equal_char = &Mdc_CharTraitsChar_EqualCharAsVoid;
  functions->less_than_char = &Mdc_CharTraitsChar_LessThanCharAsVoid;
  functions->copy_overlap_str = &Mdc_CharTraitsChar_CopyOverlapStrAsVoid;
  functions->copy_nonoverlap_str =
      &Mdc_CharTraitsChar_CopyNonoverlapStrAsVoid;
  functions->compare_str = &Mdc_CharTraitsChar_CompareStrAsVoid;
  functions->length_str = &Mdc_CharTraitsChar_LengthStrAsVoid;
  functions->find_str = &Mdc_CharTraitsChar_FindStrAsVoid;
  functions->to_char_type = &Mdc_CharTraitsChar_ToCharTypeAsVoid;
  functions->to_int_type = &Mdc_CharTraitsChar_ToIntTypeAsVoid;
  functions->equal_int_type = &Mdc_CharTraitsChar_EqualIntTypeAsVoid;
  functions->eof = &Mdc_CharTraitsChar_EofAsVoid;
  functions->not_eof = &Mdc_CharTraitsChar_NotEofAsVoid;

  return char_traits;
}

void Mdc_CharTraitsChar_AssignChar(char* r, const char* a) {
  *r = *a;
}

char* Mdc_CharTraitsChar_AssignStr(char* p, size_t count, char a) {
  memset(p, a, count);

  return p;
}

bool Mdc_CharTraitsChar_EqualChar(char a, char b) {
  unsigned char ua;
  unsigned char ub;

  ua = a;
  ub = b;

  return ua == ub;
}

bool Mdc_CharTraitsChar_LessThanChar(char a, char b) {
  unsigned char ua;
  unsigned char ub;

  ua = a;
  ub = b;

  return ua < ub;
}

char* Mdc_CharTraitsChar_CopyOverlapStr(
    char* dest,
    const char* src,
    size_t count
) {
  memmove(dest, src, count);

  return dest;
}

char* Mdc_CharTraitsChar_CopyNonoverlapStr(
    char* dest,
    const char* src,
    size_t count
) {
  memcpy(dest, src, count);

  return dest;
}

int Mdc_CharTraitsChar_CompareStr(
    const char* s1,
    const char* s2,
    size_t count
) {
  return memcmp(s1, s2, count);
}

size_t Mdc_CharTraitsChar_LengthStr(const char* s) {
  return strlen(s);
}

const char* Mdc_CharTraitsChar_FindStr(
    const char* p,
    size_t count,
    char ch
) {
  return memchr(p, ch, count);
}

char Mdc_CharTraitsChar_ToCharType(int c) {
  return (char) c;
}

int Mdc_CharTraitsChar_ToIntType(char c) {
  return (int) c;
}

bool Mdc_CharTraitsChar_EqualIntType(int c1, int c2) {
  return c1 == c2;
}

int Mdc_CharTraitsChar_Eof(void) {
  return EOF;
}

int Mdc_CharTraitsChar_NotEof(int e) {
  return e != EOF;
}
