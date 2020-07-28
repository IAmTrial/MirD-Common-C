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

#include "../../../include/c/wchar_t/wide_encoding.h"

#include <stdlib.h>
#include <stddef.h>
#include <windows.h>

static char* Mdc_Wide_EncodeChar(
    const wchar_t* wide_str,
    UINT code_page
) {
  char* char_str;
  size_t char_str_len;
  size_t char_str_size;

  size_t converted_chars_with_null_count;

  /* Determine the number of bytes needed. */
  char_str_len = WideCharToMultiByte(
      code_page,
      0,
      wide_str,
      -1,
      NULL,
      0,
      NULL,
      NULL
  );

  if (char_str_len == 0) {
    goto return_bad;
  }

  char_str_len -= 1;

  /* Allocate the char string. */
  char_str_size = (char_str_len + 1) * sizeof(char_str[0]);
  char_str = malloc(char_str_size);

  if (char_str == NULL) {
    goto return_bad;
  }

  /* Convert the char string to wide string. */
  converted_chars_with_null_count = WideCharToMultiByte(
      code_page,
      0,
      wide_str,
      -1,
      char_str,
      char_str_len + 1,
      NULL,
      NULL
  );

  if (converted_chars_with_null_count <= char_str_len) {
    goto free_char_str;
  }

  return char_str;

free_char_str:
  free(char_str);

return_bad:
  return NULL;
}

wchar_t* Mdc_Wide_EncodeAscii(const wchar_t* wide_str) {
  return Mdc_Wide_EncodeChar(wide_str, 20127);
}

char* Mdc_Wide_EncodeDefaultMultibyte(const wchar_t* wide_str) {
  return Mdc_Wide_EncodeChar(wide_str, CP_ACP);
}

char* Mdc_Wide_EncodeUtf8(const wchar_t* wide_str) {
  return Mdc_Wide_EncodeChar(wide_str, CP_UTF8);
}
