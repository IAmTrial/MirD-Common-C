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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char** Mdc_CharCString_InitCopy(
    char** dest,
    const char* const* src
) {
  size_t src_len;
  size_t src_size;

  src_len = strlen(*src);
  src_size = (src_len + 1) * sizeof(**src);

  *dest = malloc(src_size);

  if (*dest == NULL) {
    return NULL;
  }

  strcpy(*dest, *src);

  return dest;
}

char** Mdc_CharCString_InitMove(
    char** dest,
    char** src
) {
  *dest = *src;
  *src = NULL;

  return dest;
}

void Mdc_CharCString_Deinit(char** str) {
}

int Mdc_CharCString_Compare(
    const char* const* str1,
    const char* const* str2
) {
  return strcmp(*str1, *str2);
}
