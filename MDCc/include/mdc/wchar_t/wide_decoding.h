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

#ifndef MDC_C_WCHAR_T_WIDE_DECODING_H_
#define MDC_C_WCHAR_T_WIDE_DECODING_H_

#include <stddef.h>

#include "../std/wchar.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Decode the specified 7-bit ASCII string into a wide string.
 *
 * @param ascii_c_str the 7-bit ASCII to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
DLLEXPORT wchar_t* Mdc_Wide_DecodeAscii(
    wchar_t* wide_c_str,
    const char* ascii_c_str
);

DLLEXPORT size_t Mdc_Wide_DecodeAsciiLength(
    const char* ascii_c_str
);

/**
 * Creates a wide encoded copy of the specified multibyte string. The
 * multibyte encoding is dependent on the default locale on process
 * launch. The returned pointer must have free called on it by the
 * client once no longer in use.
 *
 * @param multibyte_c_str the multibyte string to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
DLLEXPORT wchar_t* Mdc_Wide_DecodeDefaultMultibyte(
    wchar_t* wide_c_str,
    const char* multibyte_c_str
);

DLLEXPORT size_t Mdc_Wide_DecodeDefaultMultibyteLength(
    const char* multibyte_c_str
);

/**
 * Creates a wide encoded copy of the specified UTF-8 string. The
 * returned pointer must have free called on it by the client once no
 * longer in use.
 *
 * @param utf8_c_str the UTF-8 string to decode
 * @return pointer to the converted string in wide characters, or NULL
 *    if failure
 */
DLLEXPORT wchar_t* Mdc_Wide_DecodeUtf8(
    wchar_t* wide_c_str,
    const char* utf8_c_str
);

DLLEXPORT size_t Mdc_Wide_DecodeUtf8Length(
    const char* utf8_c_str
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_WCHAR_T_WIDE_DECODING_H_ */
