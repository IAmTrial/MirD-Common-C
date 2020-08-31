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

#include "../../../../include/mdc/std/wchar.h"

#include <stddef.h>

#if !defined(__cplusplus) && __STDC_VERSION__ < 199409L

wchar_t* wmemcpy(wchar_t* dest, const wchar_t* src, size_t count) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    dest[i] = src[i];
  }

  return dest;
}

wchar_t* wmemmove(wchar_t* dest, const wchar_t* src, size_t count) {
  size_t i;
  ptrdiff_t position_diff;

  position_diff = dest - src;

  if (position_diff < 0) {
    for (i = 0; i < count; i += 1) {
      dest[i] = src[i];
    }
  } else {
    for (i = count; i > 0; i -= 1) {
      dest[i - 1] = src[i - 1];
    }
  }

  return dest;
}

int wmemcmp(const wchar_t* lhs, const wchar_t* rhs, size_t count) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    if (lhs[i] < rhs[i]) {
      return -1;
    } else if (lhs[i] > rhs[i]) {
      return 1;
    }
  }

  return 0;

}

wchar_t* wmemchr(const wchar_t* ptr, wchar_t ch, size_t count) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    if (ptr[i] == ch) {
      return (wchar_t*) &ptr[i];
    }
  }

  return NULL;
}

wchar_t* wmemset(wchar_t* dest, wchar_t ch, size_t count) {
  size_t i;

  for (i = 0; i < count; i += 1) {
    dest[i] = ch;
  }

  return dest;
}

#endif /* !defined(__cplusplus) && __STDC_VERSION__ < 199409L */
