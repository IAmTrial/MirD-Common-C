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

#ifndef MDC_C_STRING_CHAR_TRAITS_H_
#define MDC_C_STRING_CHAR_TRAITS_H_

#include <stddef.h>

#include "../std/stdbool.h"
#include "../std/stdint.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_CharTraitsSizes {
  size_t ch_size;
  size_t int_size;
};

struct Mdc_CharTraitsFunctions {
  void (*assign_char)(void* r, const void* a);
  void* (*assign_str)(void* p, size_t count, uintmax_t a);

  bool (*equal_char)(uintmax_t a, uintmax_t b);
  bool (*less_than_char)(uintmax_t a, uintmax_t b);

  void* (*copy_overlap_str)(void* dest, const void* src, size_t count);
  void* (*copy_nonoverlap_str)(void* dest, const void* src, size_t count);

  int (*compare_str)(const void* s1, const void* s2, size_t count);
  size_t (*length_str)(const void* s);
  const void* (*find_str)(const void* p, size_t count, uintmax_t ch);

  uintmax_t (*to_char_type)(uintmax_t c);
  uintmax_t (*to_int_type)(uintmax_t c);
  bool (*equal_int_type)(uintmax_t c1, uintmax_t c2);

  uintmax_t (*eof)(void);
  uintmax_t (*not_eof)(uintmax_t e);
};

struct Mdc_CharTraits {
  struct Mdc_CharTraitsSizes sizes;
  struct Mdc_CharTraitsFunctions functions;
};

#define MDC_CHAR_TRAITS_UNINIT { 0 };

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_CHAR_TRAITS_H_ */

#include "char_traits/char_traits_char.h"
#include "char_traits/char_traits_wchar.h"
