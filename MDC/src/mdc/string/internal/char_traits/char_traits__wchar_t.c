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

#include "../../../../../include/mdc/string/internal/char_traits/char_traits__wchar_t.h"

#include <stdio.h>
#include <string.h>

void Mdc_CharTraits_AssignChar(wchar_t, wchar_t* r, const wchar_t* a) {
  *r = *a;
}

wchar_t* Mdc_CharTraits_AssignCStr(
    wchar_t,
    wchar_t* p,
    size_t count,
    wchar_t a
) {
  return wmemset(p, a, count);
}

bool Mdc_CharTraits_EqualChar(wchar_t, wchar_t a, wchar_t b) {
  return a == b;
}

bool Mdc_CharTraits_LessThanChar(wchar_t, wchar_t a, wchar_t b) {
  return a < b;
}

wchar_t* Mdc_CharTraits_CopyOverlapCStr(
    wchar_t,
    wchar_t* dest,
    const wchar_t* src,
    size_t count
) {
  return wmemmove(dest, src, count);
}

wchar_t* Mdc_CharTraits_CopyNonoverlapCStr(
    wchar_t,
    wchar_t* dest,
    const wchar_t* src,
    size_t count
) {
  return memcpy(dest, src, count);
}

int Mdc_CharTraits_CompareCStr(
    wchar_t,
    const wchar_t* s1,
    const wchar_t* s2,
    size_t count
) {
  return wmemcmp(s1, s2, count);
}

size_t Mdc_CharTraits_LengthCStr(wchar_t, const wchar_t* s) {
  return wcslen(s);
}

const wchar_t* Mdc_CharTraits_FindCStr(
    wchar_t,
    const wchar_t* p,
    size_t count,
    wchar_t ch
) {
  return wmemchr(p, ch, count);
}

wchar_t Mdc_CharTraits_ToCharType(wchar_t, wint_t c) {
  return (wchar_t) c;
}

wint_t Mdc_CharTraits_ToIntType(wchar_t, wchar_t c) {
  return (wint_t) c;
}

bool Mdc_CharTraits_EqualIntType(wchar_t, wint_t c1, wint_t c2) {
  return c1 == c2;
}

wint_t Mdc_CharTraits_Eof(wchar_t) {
  return EOF;
}

wint_t Mdc_CharTraits_NotEof(wchar_t, wint_t e) {
  return Mdc_CharTraits_EqualIntType(wchar_t, e, Mdc_CharTraits_Eof(wchar_t))
      ? 0
      : e;
}
