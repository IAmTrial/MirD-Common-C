/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021-2022  Mir Drualga
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

#ifndef MDC_CPP98_WCHAR_T_WIDE_DECODING_HPP_
#define MDC_CPP98_WCHAR_T_WIDE_DECODING_HPP_

#include <stddef.h>

#include <string>

#include "../../../dllexport_define.inc"

namespace mdc {
namespace wide {

DLLEXPORT wchar_t* DecodeAscii(
    wchar_t* wide_c_str,
    const char* ascii_c_str
);

DLLEXPORT size_t DecodeAsciiLength(
    const char* ascii_c_str
);

DLLEXPORT wchar_t* DecodeDefaultMultibyte(
    wchar_t* wide_c_str,
    const char* multibyte_c_str
);

DLLEXPORT size_t DecodeDefaultMultibyteLength(
    const char* multibyte_c_str
);

DLLEXPORT wchar_t* DecodeUtf8(
    wchar_t* wide_c_str,
    const char* utf8_c_str
);

DLLEXPORT size_t DecodeUtf8Length(
    const char* utf8_c_str
);

inline ::std::wstring DecodeAscii(const char* ascii_c_str) {
  size_t wide_c_str_length = DecodeAsciiLength(ascii_c_str);

  ::std::wstring wide_str(wide_c_str_length, '\0');

  DecodeAscii(&wide_str[0], ascii_c_str);

  return wide_str;
}

inline ::std::wstring DecodeDefaultMultibyte(const char* multibyte_c_str) {
  size_t wide_c_str_length = DecodeDefaultMultibyteLength(multibyte_c_str);

  ::std::wstring wide_str(wide_c_str_length, '\0');

  DecodeDefaultMultibyte(&wide_str[0], multibyte_c_str);

  return wide_str;
}

inline ::std::wstring DecodeUtf8(const char* utf8_c_str) {
  size_t wide_c_str_length = DecodeUtf8Length(utf8_c_str);

  ::std::wstring wide_str(wide_c_str_length, '\0');

  DecodeUtf8(&wide_str[0], utf8_c_str);

  return wide_str;
}

} // namespace wide
} // namespace mdc

#include "../../../dllexport_undefine.inc"
#endif /* MDC_CPP98_WCHAR_T_WIDE_DECODING_HPP_ */
