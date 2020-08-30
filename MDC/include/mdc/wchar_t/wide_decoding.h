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

#ifndef MDC_C_WCHAR_T_WIDE_DECODING_H_
#define MDC_C_WCHAR_T_WIDE_DECODING_H_

#include <wchar.h>

#include "../string/basic_string.h"

/**
 * Creates a wide encoded copy of the specified 7-bit ASCII string.
 * The returned pointer must have free called on it by the client once
 * no longer in use.
 *
 * @param ascii_str the 7-bit ASCII to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
struct Mdc_BasicString Mdc_Wide_DecodeAscii(const char* ascii_str);

/**
 * Creates a wide encoded copy of the specified multibyte string. The
 * multibyte encoding is dependent on the default locale on process
 * launch. The returned pointer must have free called on it by the
 * client once no longer in use.
 *
 * @param multibyte_str the multibyte string to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
struct Mdc_BasicString Mdc_Wide_DecodeDefaultMultibyte(const char* multibyte_str);

/**
 * Creates a wide encoded copy of the specified UTF-8 string. The
 * returned pointer must have free called on it by the client once no
 * longer in use.
 *
 * @param utf8_str the UTF-8 string to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
struct Mdc_BasicString Mdc_Wide_DecodeUtf8(const char* utf8_str);

#endif /* MDC_C_WCHAR_T_WIDE_DECODING_H_ */
