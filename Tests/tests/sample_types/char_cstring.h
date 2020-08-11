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

#ifndef MDC_TESTS_SAMPLE_TYPES_C_CHAR_CSTRING_H_
#define MDC_TESTS_SAMPLE_TYPES_C_CHAR_CSTRING_H_

struct CharCString {
  char* cstring;
};

struct CharCString* Mdc_CharCString_Init(
    struct CharCString* dest,
    const char* src
);

struct CharCString* Mdc_CharCString_InitCopy(
    struct CharCString* dest,
    const struct CharCString* src
);

struct CharCString* Mdc_CharCString_InitMove(
    struct CharCString* dest,
    struct CharCString* src
);

void Mdc_CharCString_Deinit(struct CharCString* str);

int Mdc_CharCString_Compare(
    const struct CharCString* str1,
    const struct CharCString* str2
);

#endif /* MDC_TESTS_SAMPLE_TYPES_C_CHAR_CSTRING_H_ */
