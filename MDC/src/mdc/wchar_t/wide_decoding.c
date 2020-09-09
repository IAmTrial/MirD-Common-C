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

#include "../../../include/mdc/wchar_t/wide_decoding.h"

#include <stdlib.h>
#include <stddef.h>
#include <windows.h>

#include "../../../include/mdc/std/threads.h"

static struct Mdc_BasicString Mdc_Wide_DecodeChar(
    const char* char_str,
    UINT code_page
) {
  struct Mdc_BasicString wide_str;
  struct Mdc_BasicString* init_wide_str;
  struct Mdc_BasicString* assign_wide_str;
  size_t wide_str_len;

  size_t converted_chars_with_null_count;

  /* Determine the number of characters needed. */
  wide_str_len = MultiByteToWideChar(
      code_page,
      0,
      char_str,
      -1,
      NULL,
      0
  );

  if (wide_str_len == 0) {
    goto return_bad;
  }

  wide_str_len -= 1;

  /* Allocate the wide string. */
  init_wide_str = Mdc_WString_Init(&wide_str);
  if (init_wide_str != &wide_str) {
    goto return_bad;
  }

  assign_wide_str = Mdc_BasicString_AssignFromChar(
      &wide_str,
      wide_str_len,
      L'\0'
  );
  if (assign_wide_str != &wide_str) {
    goto deinit_wide_str;
  }

  /* Convert the char string to wide string. */
  converted_chars_with_null_count = MultiByteToWideChar(
      code_page,
      0,
      char_str,
      -1,
      Mdc_BasicString_Data(&wide_str),
      wide_str_len + 1
  );

  if (converted_chars_with_null_count == 0
      || converted_chars_with_null_count <= wide_str_len) {
    goto deinit_wide_str;
  }

  return wide_str;

deinit_wide_str:
  Mdc_BasicString_Deinit(&wide_str);

return_bad:
  return wide_str;
}

struct Mdc_BasicString Mdc_Wide_DecodeAscii(const char* ascii_str) {
  return Mdc_Wide_DecodeChar(ascii_str, 20127);
}

struct Mdc_BasicString Mdc_Wide_DecodeDefaultMultibyte(const char* multibyte_str) {
  return Mdc_Wide_DecodeChar(multibyte_str, CP_ACP);
}

struct Mdc_BasicString Mdc_Wide_DecodeUtf8(const char* utf8_str) {
  return Mdc_Wide_DecodeChar(utf8_str, CP_UTF8);
}
