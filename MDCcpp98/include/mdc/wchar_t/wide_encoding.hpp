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

#ifndef MDC_CPP98_WCHAR_T_WIDE_ENCODING_HPP_
#define MDC_CPP98_WCHAR_T_WIDE_ENCODING_HPP_

#include <stddef.h>

#include <string>

#include "../../../dllexport_define.inc"

namespace mdc {
namespace wide {

DLLEXPORT ::std::string EncodeAscii(
    const wchar_t* wide_c_str
);

DLLEXPORT char* EncodeAscii(
    char* char_c_str,
    const wchar_t* wide_c_str
);

DLLEXPORT size_t EncodeAsciiLength(
    const wchar_t* wide_c_str
);

DLLEXPORT ::std::string EncodeDefaultMultibyte(
    const wchar_t* wide_c_str
);

DLLEXPORT char* EncodeDefaultMultibyte(
    char* char_c_str,
    const wchar_t* wide_c_str
);

DLLEXPORT size_t EncodeDefaultMultibyteLength(
    const wchar_t* wide_c_str
);

DLLEXPORT ::std::string EncodeUtf8(
    const wchar_t* wide_c_str
);

DLLEXPORT char* EncodeUtf8(
    char* char_c_str,
    const wchar_t* wide_c_str
);

DLLEXPORT size_t EncodeUtf8Length(
    const wchar_t* wide_c_str
);

} // namespace wide
} // namespace mdc

#include "../../../dllexport_undefine.inc"
#endif /* MDC_CPP98_WCHAR_T_WIDE_ENCODING_HPP_ */
