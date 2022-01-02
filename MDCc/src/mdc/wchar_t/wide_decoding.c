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

#include "../../../include/mdc/wchar_t/wide_decoding.h"

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

static size_t Mdc_Wide_DecodeCharLength(
    const char* char_c_str,
    UINT code_page
) {
  size_t wide_c_str_capacity;

  /* Determine the number of characters needed, minus null terminator. */
  wide_c_str_capacity = MultiByteToWideChar(
      code_page,
      0,
      char_c_str,
      -1,
      NULL,
      0
  );

  return wide_c_str_capacity - 1;
}

static wchar_t* Mdc_Wide_DecodeChar(
    wchar_t* wide_c_str,
    const char* char_c_str,
    UINT code_page
) {
  size_t wide_c_str_len;

  size_t converted_chars_with_null_count;

  /* Determine the number of characters needed. */
  wide_c_str_len = Mdc_Wide_DecodeCharLength(char_c_str, code_page);

  if (wide_c_str_len == 0) {
    goto return_bad;
  }

  /* Convert the char string to wide string. */
  converted_chars_with_null_count = MultiByteToWideChar(
      code_page,
      0,
      char_c_str,
      -1,
      wide_c_str,
      wide_c_str_len + 1
  );

  if (converted_chars_with_null_count == 0
      || converted_chars_with_null_count <= wide_c_str_len) {
    goto return_bad;
  }

  return wide_c_str;

return_bad:
  return NULL;
}

wchar_t* Mdc_Wide_DecodeAscii(
    wchar_t* wide_c_str,
    const char* ascii_c_str
) {
  return Mdc_Wide_DecodeChar(wide_c_str, ascii_c_str, 20127);
}

size_t Mdc_Wide_DecodeAsciiLength(
    const char* ascii_c_str
) {
  return Mdc_Wide_DecodeCharLength(ascii_c_str, 20127);
}

wchar_t* Mdc_Wide_DecodeDefaultMultibyte(
    wchar_t* wide_c_str,
    const char* multibyte_c_str
) {
  return Mdc_Wide_DecodeChar(wide_c_str, multibyte_c_str, CP_ACP);
}

size_t Mdc_Wide_DecodeDefaultMultibyteLength(
    const char* ascii_c_str
) {
  return Mdc_Wide_DecodeCharLength(ascii_c_str, CP_ACP);
}

wchar_t* Mdc_Wide_DecodeUtf8(
    wchar_t* wide_c_str,
    const char* utf8_c_str
) {
  return Mdc_Wide_DecodeChar(wide_c_str, utf8_c_str, CP_UTF8);
}

size_t Mdc_Wide_DecodeUtf8Length(
    const char* utf8_c_str
) {
  return Mdc_Wide_DecodeCharLength(utf8_c_str, CP_UTF8);
}

#endif /* defined(_WIN32) || defined(_WIN64) */
