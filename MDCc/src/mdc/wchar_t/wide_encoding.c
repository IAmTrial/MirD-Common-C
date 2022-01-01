/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2022  Mir Drualga
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

#include "../../../include/mdc/wchar_t/wide_encoding.h"

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

static size_t Mdc_Wide_EncodeCharLength(
    const wchar_t* wide_c_str,
    UINT code_page
) {
  size_t char_c_str_capacity;

  /* Determine the number of characters needed, minus null terminator. */
  char_c_str_capacity = WideCharToMultiByte(
      code_page,
      0,
      wide_c_str,
      -1,
      NULL,
      0,
      NULL,
      NULL
  );

  return char_c_str_capacity - 1;
}

static char* Mdc_Wide_EncodeChar(
    char* char_c_str,
    const wchar_t* wide_c_str,
    UINT code_page
) {
  size_t char_c_str_len;

  size_t converted_chars_with_null_count;

  /* Determine the number of characters needed. */
  char_c_str_len = Mdc_Wide_EncodeCharLength(wide_c_str, code_page);

  if (char_c_str_len == 0) {
    goto return_bad;
  }

  /* Convert the char string to wide string. */
  converted_chars_with_null_count = WideCharToMultiByte(
      code_page,
      0,
      wide_c_str,
      -1,
      char_c_str,
      char_c_str_len + 1,
      NULL,
      NULL
  );

  if (converted_chars_with_null_count <= char_c_str_len) {
    goto return_bad;
  }

  return char_c_str;

return_bad:
  return NULL;
}

char* Mdc_Wide_EncodeAscii(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeChar(char_c_str, wide_c_str, 20127);
}

size_t Mdc_Wide_EncodeAsciiLength(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeCharLength(wide_c_str, 20127);
}

char* Mdc_Wide_EncodeDefaultMultibyte(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeChar(char_c_str, wide_c_str, CP_ACP);
}

size_t Mdc_Wide_EncodeDefaultMultibyteLength(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeCharLength(wide_c_str, CP_ACP);
}

char* Mdc_Wide_EncodeUtf8(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeChar(char_c_str, wide_c_str, CP_UTF8);
}

size_t Mdc_Wide_EncodeUtf8Length(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeCharLength(wide_c_str, CP_UTF8);
}

#endif /* defined(_WIN32) || defined(_WIN64) */
