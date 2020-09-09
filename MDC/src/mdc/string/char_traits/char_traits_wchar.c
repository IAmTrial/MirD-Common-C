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

#include "../../../../include/mdc/string/char_traits/char_traits_wchar.h"

#include "../../../../include/mdc/std/threads.h"
#include "../../../../include/mdc/std/wchar.h"

/**
 * Static functions
 */

static void Mdc_CharTraitsWChar_AssignCharAsVoid(void* r, const void* a) {
  Mdc_CharTraitsWChar_AssignChar((wchar_t*) r, (wchar_t*) a);
}

static void* Mdc_CharTraitsWChar_AssignStrAsVoid(
    void* p,
    size_t count,
    uintmax_t a
) {
  return Mdc_CharTraitsWChar_AssignStr((wchar_t*) p, count, (wchar_t) a);
}

static bool Mdc_CharTraitsWChar_EqualCharAsVoid(uintmax_t a, uintmax_t b) {
  return Mdc_CharTraitsWChar_EqualChar((wchar_t) a, (wchar_t) b);
}

static bool Mdc_CharTraitsWChar_LessThanCharAsVoid(uintmax_t a, uintmax_t b) {
  return Mdc_CharTraitsWChar_LessThanChar((wchar_t) a, (wchar_t) b);
}

static void* Mdc_CharTraitsWChar_CopyOverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsWChar_CopyOverlapStr(
      (wchar_t*) dest,
      (const wchar_t*) src,
      count
  );
}

static void* Mdc_CharTraitsWChar_CopyNonoverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsWChar_CopyNonoverlapStr(
      (wchar_t*) dest,
      (const wchar_t*) src,
      count
  );
}

static int Mdc_CharTraitsWChar_CompareStrAsVoid(
    const void* s1,
    const void* s2,
    size_t count
) {
  return Mdc_CharTraitsWChar_CompareStr(
      (const wchar_t*) s1,
      (const wchar_t*) s2,
      count
  );
}

static size_t Mdc_CharTraitsWChar_LengthStrAsVoid(const void* s) {
  return Mdc_CharTraitsWChar_LengthStr((const wchar_t*) s);
}

static const void* Mdc_CharTraitsWChar_FindStrAsVoid(
    const void* p,
    size_t count,
    uintmax_t ch
) {
  return Mdc_CharTraitsWChar_FindStr((wchar_t*) p, count, (wchar_t) ch);
}

static uintmax_t Mdc_CharTraitsWChar_ToCharTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsWChar_ToCharType((wint_t) c);
}

static uintmax_t Mdc_CharTraitsWChar_ToIntTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsWChar_ToIntType((wchar_t) c);
}

static bool Mdc_CharTraitsWChar_EqualIntTypeAsVoid(
    uintmax_t c1,
    uintmax_t c2
) {
  return Mdc_CharTraitsWChar_EqualIntType((wint_t) c1, (wint_t) c2);
}

static uintmax_t Mdc_CharTraitsWChar_EofAsVoid(void) {
  return Mdc_CharTraitsWChar_Eof();
}

static uintmax_t Mdc_CharTraitsWChar_NotEofAsVoid(uintmax_t e) {
  return Mdc_CharTraitsWChar_NotEof((wint_t) e);
}

static struct Mdc_CharTraits* Mdc_CharTraitsWChar_Init(
    struct Mdc_CharTraits* char_traits
) {
  struct Mdc_CharTraitsSizes* sizes = &char_traits->sizes;
  struct Mdc_CharTraitsFunctions* functions = &char_traits->functions;

  /* Set sizes. */
  sizes->ch_size = sizeof(wchar_t);
  sizes->int_size = sizeof(wint_t);

  /* Set functions. */
  functions->assign_char = &Mdc_CharTraitsWChar_AssignCharAsVoid;
  functions->assign_str = &Mdc_CharTraitsWChar_AssignStrAsVoid;
  functions->equal_char = &Mdc_CharTraitsWChar_EqualCharAsVoid;
  functions->less_than_char = &Mdc_CharTraitsWChar_LessThanCharAsVoid;
  functions->copy_overlap_str = &Mdc_CharTraitsWChar_CopyOverlapStrAsVoid;
  functions->copy_nonoverlap_str =
      &Mdc_CharTraitsWChar_CopyNonoverlapStrAsVoid;
  functions->compare_str = &Mdc_CharTraitsWChar_CompareStrAsVoid;
  functions->length_str = &Mdc_CharTraitsWChar_LengthStrAsVoid;
  functions->find_str = &Mdc_CharTraitsWChar_FindStrAsVoid;
  functions->to_char_type = &Mdc_CharTraitsWChar_ToCharTypeAsVoid;
  functions->to_int_type = &Mdc_CharTraitsWChar_ToIntTypeAsVoid;
  functions->equal_int_type = &Mdc_CharTraitsWChar_EqualIntTypeAsVoid;
  functions->eof = &Mdc_CharTraitsWChar_EofAsVoid;
  functions->not_eof = &Mdc_CharTraitsWChar_NotEofAsVoid;

  return char_traits;
}

static struct Mdc_CharTraits global_char_traits;
static once_flag global_char_traits_init_flag = ONCE_FLAG_INIT;

static void Mdc_CharTraitsWChar_InitGlobalCharTraits(void) {
  Mdc_CharTraitsWChar_Init(&global_char_traits);
}

/**
 * External functions
 */

const struct Mdc_CharTraits* Mdc_CharTraitsWChar_GetCharTraits(void) {
  call_once(
      &global_char_traits_init_flag,
      &Mdc_CharTraitsWChar_InitGlobalCharTraits
  );

  return &global_char_traits;
}

void Mdc_CharTraitsWChar_AssignChar(wchar_t* r, const wchar_t* a) {
  *r = *a;
}

wchar_t* Mdc_CharTraitsWChar_AssignStr(wchar_t* p, size_t count, wchar_t a) {
  wmemset(p, a, count);

  return p;
}

bool Mdc_CharTraitsWChar_EqualChar(wchar_t a, wchar_t b) {
  wchar_t ua;
  wchar_t ub;

  ua = a;
  ub = b;

  return ua == ub;
}

bool Mdc_CharTraitsWChar_LessThanChar(wchar_t a, wchar_t b) {
  wchar_t ua;
  wchar_t ub;

  ua = a;
  ub = b;

  return ua < ub;
}

wchar_t* Mdc_CharTraitsWChar_CopyOverlapStr(
    wchar_t* dest,
    const wchar_t* src,
    size_t count
) {
  wmemmove(dest, src, count);

  return dest;
}

wchar_t* Mdc_CharTraitsWChar_CopyNonoverlapStr(
    wchar_t* dest,
    const wchar_t* src,
    size_t count
) {
  wmemcpy(dest, src, count);

  return dest;
}

int Mdc_CharTraitsWChar_CompareStr(
    const wchar_t* s1,
    const wchar_t* s2,
    size_t count
) {
  return wmemcmp(s1, s2, count);
}

size_t Mdc_CharTraitsWChar_LengthStr(const wchar_t* s) {
  return wcslen(s);
}

const wchar_t* Mdc_CharTraitsWChar_FindStr(
    const wchar_t* p,
    size_t count,
    wchar_t ch
) {
  return wmemchr(p, ch, count);
}

wchar_t Mdc_CharTraitsWChar_ToCharType(wint_t c) {
  return (wchar_t) c;
}

wint_t Mdc_CharTraitsWChar_ToIntType(wchar_t c) {
  return (wint_t) c;
}

bool Mdc_CharTraitsWChar_EqualIntType(wint_t c1, wint_t c2) {
  return c1 == c2;
}

wint_t Mdc_CharTraitsWChar_Eof(void) {
  return WEOF;
}

wint_t Mdc_CharTraitsWChar_NotEof(wint_t e) {
  return Mdc_CharTraitsWChar_EqualIntType(e, Mdc_CharTraitsWChar_Eof())
      ? 0
      : e;
}
