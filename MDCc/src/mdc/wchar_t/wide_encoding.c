/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2025  Mir Drualga
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

#include "mdc/wchar_t/wide_encoding.h"

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

static size_t Mdc_Wide_EncodeCharLength(const wchar_t* str, UINT code_page) {
  size_t encoded_required_capacity;

  /* Determine the number of characters needed, minus null terminator. */
  encoded_required_capacity =
      WideCharToMultiByte(code_page, 0, str, -1, NULL, 0, NULL, NULL);

  return encoded_required_capacity - 1;
}

static char* Mdc_Wide_EncodeChar(
    char* dest, const wchar_t* src, UINT code_page) {
  size_t dest_len;

  size_t encoded_with_null_count;

  /* Determine the number of characters needed. */
  dest_len = Mdc_Wide_EncodeCharLength(src, code_page);

  if (dest_len == 0) {
    goto return_bad;
  }

  /* Convert the char string to wide string. */
  encoded_with_null_count =
      WideCharToMultiByte(
          code_page, 0, src, -1, dest, dest_len + 1, NULL, NULL);

  if (encoded_with_null_count <= dest_len) {
    goto return_bad;
  }

  return dest;

return_bad:
  return NULL;
}

char* Mdc_Wide_EncodeAscii(char* dest, const wchar_t* src) {
  return Mdc_Wide_EncodeChar(dest, src, 20127);
}

size_t Mdc_Wide_EncodeAsciiLength(const wchar_t* str) {
  return Mdc_Wide_EncodeCharLength(str, 20127);
}

char* Mdc_Wide_EncodeDefaultMultibyte(char* dest, const wchar_t* src) {
  return Mdc_Wide_EncodeChar(dest, src, CP_ACP);
}

size_t Mdc_Wide_EncodeDefaultMultibyteLength(const wchar_t* str) {
  return Mdc_Wide_EncodeCharLength(str, CP_ACP);
}

char* Mdc_Wide_EncodeUtf8(char* dest, const wchar_t* src) {
  return Mdc_Wide_EncodeChar(dest, src, CP_UTF8);
}

size_t Mdc_Wide_EncodeUtf8Length(const wchar_t* str) {
  return Mdc_Wide_EncodeCharLength(str, CP_UTF8);
}

#endif  /* defined(_WIN32) || defined(_WIN64) */
