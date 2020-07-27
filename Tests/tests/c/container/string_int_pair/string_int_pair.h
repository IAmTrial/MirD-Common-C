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

#ifndef MDC_TESTS_C_CONTAINER_STRING_INT_PAIR_STRING_INT_PAIR_H_
#define MDC_TESTS_C_CONTAINER_STRING_INT_PAIR_STRING_INT_PAIR_H_

#include <c/container/pair.h>

char** Mdc_String_InitCopy(
    char** dest,
    const char* const* src
);

int* Mdc_Int_InitCopy(
    int* dest,
    const int* src
);

char** Mdc_String_InitMove(
    char** dest,
    char** src
);

int* Mdc_Int_InitMove(
    int* dest,
    int* src
);

void Mdc_String_Deinit(char** str);

void Mdc_Int_Deinit(int* integer);

int Mdc_String_Compare(
    const char* const* str1,
    const char* const* str2
);

int Mdc_Int_Compare(
    const int* integer1,
    const int* integer2
);

struct Mdc_PairMetadata* Mdc_PairStringIntMetadata_Init(
    struct Mdc_PairMetadata* metadata
);

#endif /* MDC_TESTS_C_CONTAINER_STRING_INT_PAIR_STRING_INT_PAIR_H_ */
