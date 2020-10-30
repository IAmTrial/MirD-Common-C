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

#include "../../../../include/mdc/string/char_traits/char_traits_char8.h"

#include <string.h>
#include <stdio.h>

#include "../../../../include/mdc/std/stdint.h"
#include "../../../../include/mdc/std/threads.h"

/**
 * Static functions
 */

static void Mdc_CharTraitsChar8_AssignCharAsVoid(void* r, const void* a) {
  Mdc_CharTraitsChar8_AssignChar(r, a);
}

static void* Mdc_CharTraitsChar8_AssignStrAsVoid(
    void* p,
    size_t count,
    uintmax_t a
) {
  return Mdc_CharTraitsChar8_AssignStr(p, count, (char8_t) a);
}

static bool Mdc_CharTraitsChar8_EqualCharAsVoid(uintmax_t a, uintmax_t b) {
  return Mdc_CharTraitsChar8_EqualChar((char8_t) a, (char8_t) b);
}

static bool Mdc_CharTraitsChar8_LessThanCharAsVoid(
    uintmax_t a,
    uintmax_t b
) {
  return Mdc_CharTraitsChar8_LessThanChar((char8_t) a, (char8_t) b);
}

static void* Mdc_CharTraitsChar8_CopyOverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar8_CopyOverlapStr(dest, src, count);
}

static void* Mdc_CharTraitsChar8_CopyNonoverlapStrAsVoid(
    void* dest,
    const void* src,
    size_t count
) {
  return Mdc_CharTraitsChar8_CopyNonoverlapStr(dest, src, count);
}

static int Mdc_CharTraitsChar8_CompareStrAsVoid(
    const void* s1,
    const void* s2,
    size_t count
) {
  return Mdc_CharTraitsChar8_CompareStr(s1, s2, count);
}

static size_t Mdc_CharTraitsChar8_LengthStrAsVoid(const void* s) {
  return Mdc_CharTraitsChar8_LengthStr(s);
}

static const void* Mdc_CharTraitsChar8_FindStrAsVoid(
    const void* p,
    size_t count,
    uintmax_t ch
) {
  return Mdc_CharTraitsChar8_FindStr(p, count, (char8_t) ch);
}

static uintmax_t Mdc_CharTraitsChar8_ToCharTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar8_ToCharType((unsigned int) c);
}

static uintmax_t Mdc_CharTraitsChar8_ToIntTypeAsVoid(uintmax_t c) {
  return Mdc_CharTraitsChar8_ToIntType((char8_t) c);
}

static bool Mdc_CharTraitsChar8_EqualIntTypeAsVoid(
    uintmax_t c1,
    uintmax_t c2
) {
  return Mdc_CharTraitsChar8_EqualIntType(
      (unsigned int) c1,
      (unsigned int) c2
  );
}

static struct Mdc_CharTraits* Mdc_CharTraitsChar8_Init(
    struct Mdc_CharTraits* char_traits
) {
  struct Mdc_CharTraitsSizes* sizes = &char_traits->sizes;
  struct Mdc_CharTraitsFunctions* functions = &char_traits->functions;

  /* Set sizes. */
  sizes->ch_size = sizeof(char8_t);
  sizes->int_size = sizeof(unsigned int);

  /* Set functions. */
  functions->assign_char = &Mdc_CharTraitsChar8_AssignCharAsVoid;
  functions->assign_str = &Mdc_CharTraitsChar8_AssignStrAsVoid;
  functions->equal_char = &Mdc_CharTraitsChar8_EqualCharAsVoid;
  functions->less_than_char = &Mdc_CharTraitsChar8_LessThanCharAsVoid;
  functions->copy_overlap_str = &Mdc_CharTraitsChar8_CopyOverlapStrAsVoid;
  functions->copy_nonoverlap_str =
      &Mdc_CharTraitsChar8_CopyNonoverlapStrAsVoid;
  functions->compare_str = &Mdc_CharTraitsChar8_CompareStrAsVoid;
  functions->length_str = &Mdc_CharTraitsChar8_LengthStrAsVoid;
  functions->find_str = &Mdc_CharTraitsChar8_FindStrAsVoid;
  functions->to_char_type = &Mdc_CharTraitsChar8_ToCharTypeAsVoid;
  functions->to_int_type = &Mdc_CharTraitsChar8_ToIntTypeAsVoid;
  functions->equal_int_type = &Mdc_CharTraitsChar8_EqualIntTypeAsVoid;

  return char_traits;
}

static struct Mdc_CharTraits global_char_traits;
static once_flag global_char_traits_init_flag = ONCE_FLAG_INIT;

static void Mdc_CharTraitsChar8_InitGlobalCharTraits(void) {
  Mdc_CharTraitsChar8_Init(&global_char_traits);
}

/**
 * External functions
 */

const struct Mdc_CharTraits* Mdc_CharTraitsChar8_GetCharTraits(void) {
  call_once(
      &global_char_traits_init_flag,
      &Mdc_CharTraitsChar8_InitGlobalCharTraits
  );

  return &global_char_traits;
}

void Mdc_CharTraitsChar8_AssignChar(char8_t* r, const char8_t* a) {
  *r = *a;
}

char8_t* Mdc_CharTraitsChar8_AssignStr(
    char8_t* p,
    size_t count,
    char8_t a
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    p[i] = a;
  }

  return p;
}

bool Mdc_CharTraitsChar8_EqualChar(char8_t a, char8_t b) {
  return a == b;
}

bool Mdc_CharTraitsChar8_LessThanChar(char8_t a, char8_t b) {
  return a < b;
}

char8_t* Mdc_CharTraitsChar8_CopyOverlapStr(
    char8_t* dest,
    const char8_t* src,
    size_t count
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    dest[i] = src[i];
  }

  return dest;
}

char8_t* Mdc_CharTraitsChar8_CopyNonoverlapStr(
    char8_t* dest,
    const char8_t* src,
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

int Mdc_CharTraitsChar8_CompareStr(
    const char8_t* s1,
    const char8_t* s2,
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

size_t Mdc_CharTraitsChar8_LengthStr(const char8_t* s) {
  size_t len;

  for (len = 0; s[len] != '\0'; len += 1);

  return len;
}

const char8_t* Mdc_CharTraitsChar8_FindStr(
    const char8_t* p,
    size_t count,
    char8_t ch
) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    if (p[i] == ch) {
      return &p[i];
    }
  }

  return NULL;
}

char8_t Mdc_CharTraitsChar8_ToCharType(unsigned int c) {
  return (char8_t) c;
}

unsigned int Mdc_CharTraitsChar8_ToIntType(char8_t c) {
  return (unsigned int) c;
}

bool Mdc_CharTraitsChar8_EqualIntType(
    unsigned int c1,
    unsigned int c2
  ) {
  return c1 == c2;
}
