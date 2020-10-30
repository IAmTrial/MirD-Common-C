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

#include "../../../../include/mdc/string/char_traits/char_traits_char16.h"

#include <string.h>
#include <stdio.h>

#include "../../../../include/mdc/std/stdint.h"
#include "../../../../include/mdc/std/threads.h"

/**
 * Static functions
 */

static void Mdc_CharTraitsChar16_AssignCharAsVoid(void* r, const void* a) {
  Mdc_CharTraitsChar16_AssignChar(r, a);
}

static void* Mdc_CharTraitsChar16_AssignStrAsVoid(
    void* p,
    size_t count,
    uintmax_t a
) {
  return Mdc_CharTraitsChar16_AssignStr(p, count, (char16_t) a);
}

static bool Mdc_CharTraitsChar16_EqualCharAsVoid(
    uintmax_t a,
    uintmax_t b
) {
  return Mdc_CharTraitsChar16_EqualChar((char16_t) a, (char16_t) b);
}

static bool Mdc_CharTraitsChar16_LessThanCharAsVoid(
    uintmax_t a,
    uintmax_t b
) {
  return Mdc_CharTraitsChar16_LessThanChar((char16_t) a, (char16_t) b);
}

static void* Mdc_CharTraitsChar16_CopyOverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar16_CopyOverlapStr(dest, src, count);
}

static void* Mdc_CharTraitsChar16_CopyNonoverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar16_CopyNonoverlapStr(dest, src, count);
}

static int Mdc_CharTraitsChar16_CompareStrAsVoid(
    const void* s1,
    const void* s2,
    size_t count
) {
  return Mdc_CharTraitsChar16_CompareStr(s1, s2, count);
}

static size_t Mdc_CharTraitsChar16_LengthStrAsVoid(const void* s) {
  return Mdc_CharTraitsChar16_LengthStr(s);
}

static const void* Mdc_CharTraitsChar16_FindStrAsVoid(
    const void* p,
    size_t count,
    uintmax_t ch
) {
  return Mdc_CharTraitsChar16_FindStr(p, count, (char16_t) ch);
}

static uintmax_t Mdc_CharTraitsChar16_ToCharTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar16_ToCharType((uint_least16_t) c);
}

static uintmax_t Mdc_CharTraitsChar16_ToIntTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar16_ToIntType((char16_t) c);
}

static bool Mdc_CharTraitsChar16_EqualIntTypeAsVoid(
    uintmax_t c1,
    uintmax_t c2
) {
  return Mdc_CharTraitsChar16_EqualIntType(
      (uint_least16_t) c1,
      (uint_least16_t) c2
  );
}

static struct Mdc_CharTraits* Mdc_CharTraitsChar16_Init(
    struct Mdc_CharTraits* char_traits
) {
  struct Mdc_CharTraitsSizes* sizes = &char_traits->sizes;
  struct Mdc_CharTraitsFunctions* functions = &char_traits->functions;

  /* Set sizes. */
  sizes->ch_size = sizeof(char16_t);
  sizes->int_size = sizeof(uint_least16_t);

  /* Set functions. */
  functions->assign_char = &Mdc_CharTraitsChar16_AssignCharAsVoid;
  functions->assign_str = &Mdc_CharTraitsChar16_AssignStrAsVoid;
  functions->equal_char = &Mdc_CharTraitsChar16_EqualCharAsVoid;
  functions->less_than_char = &Mdc_CharTraitsChar16_LessThanCharAsVoid;
  functions->copy_overlap_str = &Mdc_CharTraitsChar16_CopyOverlapStrAsVoid;
  functions->copy_nonoverlap_str =
      &Mdc_CharTraitsChar16_CopyNonoverlapStrAsVoid;
  functions->compare_str = &Mdc_CharTraitsChar16_CompareStrAsVoid;
  functions->length_str = &Mdc_CharTraitsChar16_LengthStrAsVoid;
  functions->find_str = &Mdc_CharTraitsChar16_FindStrAsVoid;
  functions->to_char_type = &Mdc_CharTraitsChar16_ToCharTypeAsVoid;
  functions->to_int_type = &Mdc_CharTraitsChar16_ToIntTypeAsVoid;
  functions->equal_int_type = &Mdc_CharTraitsChar16_EqualIntTypeAsVoid;

  return char_traits;
}

static struct Mdc_CharTraits global_char_traits;
static once_flag global_char_traits_init_flag = ONCE_FLAG_INIT;

static void Mdc_CharTraitsChar16_InitGlobalCharTraits(void) {
  Mdc_CharTraitsChar16_Init(&global_char_traits);
}

/**
 * External functions
 */

const struct Mdc_CharTraits* Mdc_CharTraitsChar16_GetCharTraits(void) {
  call_once(
      &global_char_traits_init_flag,
      &Mdc_CharTraitsChar16_InitGlobalCharTraits
  );

  return &global_char_traits;
}

void Mdc_CharTraitsChar16_AssignChar(char16_t* r, const char16_t* a) {
  *r = *a;
}

char16_t* Mdc_CharTraitsChar16_AssignStr(
    char16_t* p,
    size_t count,
    char16_t a
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    p[i] = a;
  }

  return p;
}

bool Mdc_CharTraitsChar16_EqualChar(char16_t a, char16_t b) {
  return a == b;
}

bool Mdc_CharTraitsChar16_LessThanChar(char16_t a, char16_t b) {
  return a < b;
}

char16_t* Mdc_CharTraitsChar16_CopyOverlapStr(
    char16_t* dest,
    const char16_t* src,
    size_t count
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    dest[i] = src[i];
  }

  return dest;
}

char16_t* Mdc_CharTraitsChar16_CopyNonoverlapStr(
    char16_t* dest,
    const char16_t* src,
    size_t count
) {
  size_t i;
  ptrdiff_t position_diff;

  position_diff = dest - src;

  if (position_diff < 0) {
    for (i = 0; i < count; i += 1) {
      dest[i] = src[i];
    }
  } else {
    for (i = count - 1; i != (size_t) -1; i -= 1) {
      dest[i] = src[i];
    }
  }

  return dest;
}

int Mdc_CharTraitsChar16_CompareStr(
    const char16_t* s1,
    const char16_t* s2,
    size_t count
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    if (s1[i] < s2[i]) {
      return -1;
    } else if (s1[i] > s2[i]) {
      return 1;
    }
  }

  return 0;
}

size_t Mdc_CharTraitsChar16_LengthStr(const char16_t* s) {
  size_t len;

  for (len = 0; s[len] != '\0'; len += 1);

  return len;
}

const char16_t* Mdc_CharTraitsChar16_FindStr(
    const char16_t* p,
    size_t count,
    char16_t ch
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    if (p[i] == ch) {
      return &p[i];
    }
  }

  return NULL;
}

char16_t Mdc_CharTraitsChar16_ToCharType(uint_least16_t c) {
  return (char16_t) c;
}

uint_least16_t Mdc_CharTraitsChar16_ToIntType(char16_t c) {
  return (uint_least16_t) c;
}

bool Mdc_CharTraitsChar16_EqualIntType(
    uint_least16_t c1,
    uint_least16_t c2
) {
  return c1 == c2;
}
