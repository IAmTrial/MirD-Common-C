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

void Mdc_CharTraits_AssignChar(Mdc_WChar)(Mdc_WChar* r, const Mdc_WChar* a) {
  *r = *a;
}

Mdc_WChar* Mdc_CharTraits_AssignCStr(Mdc_WChar)(
    Mdc_WChar* p,
    size_t count,
    Mdc_WChar a
) {
  return wmemset(p, a, count);
}

bool Mdc_CharTraits_EqualChar(Mdc_WChar)(Mdc_WChar a, Mdc_WChar b) {
  return a == b;
}

bool Mdc_CharTraits_LessThanChar(Mdc_WChar)(Mdc_WChar a, Mdc_WChar b) {
  return a < b;
}

Mdc_WChar* Mdc_CharTraits_CopyOverlapCStr(Mdc_WChar)(
    Mdc_WChar* dest,
    const Mdc_WChar* src,
    size_t count
) {
  return wmemmove(dest, src, count);
}

Mdc_WChar* Mdc_CharTraits_CopyNonoverlapCStr(Mdc_WChar)(
    Mdc_WChar* dest,
    const Mdc_WChar* src,
    size_t count
) {
  return memcpy(dest, src, count);
}

int Mdc_CharTraits_CompareCStr(Mdc_WChar)(
    const Mdc_WChar* s1,
    const Mdc_WChar* s2,
    size_t count
) {
  return wmemcmp(s1, s2, count);
}

size_t Mdc_CharTraits_LengthCStr(Mdc_WChar)(const Mdc_WChar* s) {
  return wcslen(s);
}

const Mdc_WChar* Mdc_CharTraits_FindCStr(Mdc_WChar)(
    const Mdc_WChar* p,
    size_t count,
    Mdc_WChar ch
) {
  return wmemchr(p, ch, count);
}

Mdc_WChar Mdc_CharTraits_ToCharType(Mdc_WChar)(Mdc_WInt c) {
  return (Mdc_WChar) c;
}

Mdc_WInt Mdc_CharTraits_ToIntType(Mdc_WChar)(Mdc_WChar c) {
  return (Mdc_WInt) c;
}

bool Mdc_CharTraits_EqualIntType(Mdc_WChar)(Mdc_WInt c1, Mdc_WInt c2) {
  return c1 == c2;
}

Mdc_WInt Mdc_CharTraits_Eof(Mdc_WChar)(void) {
  return EOF;
}

Mdc_WInt Mdc_CharTraits_NotEof(Mdc_WChar)(Mdc_WInt e) {
  bool equal_int_type;

  equal_int_type = Mdc_CharTraits_EqualIntType(Mdc_WChar)(
      e,
      Mdc_CharTraits_Eof(Mdc_WChar)()
  );

  return equal_int_type
      ? 0
      : e;
}
