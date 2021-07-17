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

#include "../../../include/mdc/wchar_t/wide_decoding.hpp"

#include <mdc/wchar_t/wide_decoding.h>

namespace mdc {
namespace wide {

wchar_t* DecodeAscii(
    wchar_t* wide_c_str,
    const char* ascii_c_str
) {
  return Mdc_Wide_DecodeAscii(wide_c_str, ascii_c_str);
}

size_t DecodeAsciiLength(
    const char* ascii_c_str
) {
  return Mdc_Wide_DecodeAsciiLength(ascii_c_str);
}

wchar_t* DecodeDefaultMultibyte(
    wchar_t* wide_c_str,
    const char* multibyte_c_str
) {
  return Mdc_Wide_DecodeDefaultMultibyte(wide_c_str, multibyte_c_str);
}

size_t DecodeDefaultMultibyteLength(
    const char* multibyte_c_str
) {
  return Mdc_Wide_DecodeDefaultMultibyteLength(multibyte_c_str);
}

wchar_t* DecodeUtf8(
    wchar_t* wide_c_str,
    const char* utf8_c_str
) {
  return Mdc_Wide_DecodeUtf8(wide_c_str, utf8_c_str);
}

size_t DecodeUtf8Length(
    const char* utf8_c_str
) {
  return Mdc_Wide_DecodeUtf8Length(utf8_c_str);
}

} // namespace wide
} // namespace mdc
