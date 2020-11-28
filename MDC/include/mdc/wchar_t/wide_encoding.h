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

#ifndef MDC_C_WCHAR_T_WIDE_ENCODING_H_
#define MDC_C_WCHAR_T_WIDE_ENCODING_H_

#include "../std/wchar.h"
#include "../string/string.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Creates a wide encoded copy of the specified 7-bit ASCII string.
 * The returned pointer must have free called on it by the client once
 * no longer in use.
 *
 * @param ascii_str the wide string to encode
 * @return pointer to the re-encoded string in multibyte characters,
 *    or NULL if failure
 */
DLLEXPORT struct Mdc_String Mdc_Wide_EncodeAscii(
    const wchar_t* wide_str
);

/**
 * Creates a multibyte encoded copy of the specified wide string. The
 * multibyte encoding is dependent on the default locale on process
 * launch. The returned pointer must have free called on it by the
 * client once no longer in use.
 *
 * @param wide_str the wide string to encode
 * @return pointer to the re-encoded string in multibyte characters,
 *    or NULL if failure
 */
DLLEXPORT struct Mdc_String Mdc_Wide_EncodeDefaultMultibyte(
    const wchar_t* wide_str
);

/**
 * Creates a UTF-8 encoded copy of the specified wide string. The
 * returned pointer must have free called on it by the client once no
 * longer in use.
 *
 * @param wide_str the wide string to encode
 * @return pointer to the re-encoded string in multibyte characters,
 *    or NULL if failure
 */
DLLEXPORT struct Mdc_String Mdc_Wide_EncodeUtf8(
    const wchar_t* wide_str
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_WCHAR_T_WIDE_ENCODING_H_ */
