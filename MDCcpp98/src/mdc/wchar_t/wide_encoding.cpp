/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C++98.
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

#include "../../../include/mdc/wchar_t/wide_encoding.hpp"

#include <mdc/wchar_t/wide_encoding.h>

namespace mdc {
namespace wide {
namespace {

static ::std::string EncodeChar(
    const wchar_t* wide_c_str,
    char* (*encode_func)(char*, const wchar_t*),
    size_t (*length_func)(const wchar_t*)
) {
  size_t char_c_str_length = length_func(wide_c_str);

  ::std::string char_str(char_c_str_length, '\0');

  encode_func(&char_str[0], wide_c_str);

  return char_str;
}

} // namespace

::std::string EncodeAscii(
    const wchar_t* wide_c_str
) {
  return EncodeChar(
      wide_c_str,
      &EncodeAscii,
      &EncodeAsciiLength
  );
}

char* EncodeAscii(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeAscii(char_c_str, wide_c_str);
}

size_t EncodeAsciiLength(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeAsciiLength(wide_c_str);
}

::std::string EncodeDefaultMultibyte(
    const wchar_t* wide_c_str
) {
  return EncodeChar(
      wide_c_str,
      &EncodeDefaultMultibyte,
      &EncodeDefaultMultibyteLength
  );
}

char* EncodeDefaultMultibyte(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeDefaultMultibyte(char_c_str, wide_c_str);
}

size_t EncodeDefaultMultibyteLength(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeDefaultMultibyteLength(wide_c_str);
}

::std::string EncodeUtf8(
    const wchar_t* wide_c_str
) {
  return EncodeChar(
      wide_c_str,
      &EncodeUtf8,
      &EncodeUtf8Length
  );
}

char* EncodeUtf8(
    char* char_c_str,
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeUtf8(char_c_str, wide_c_str);
}

size_t EncodeUtf8Length(
    const wchar_t* wide_c_str
) {
  return Mdc_Wide_EncodeUtf8Length(wide_c_str);
}

} // namespace wide
} // namespace mdc
