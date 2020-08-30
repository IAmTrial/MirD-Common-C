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

#ifndef MDC_C_OBJECT_POINTER_H_
#define MDC_C_OBJECT_POINTER_H_

#include "../std/stdbool.h"
#include "../std/stdint.h"

struct Mdc_Pointer {
  union {
    void* ptr_;
    intptr_t value_;
  };
};

struct Mdc_Pointer* Mdc_Pointer_InitFromPointer(
    struct Mdc_Pointer* pointer,
    void* value
);

struct Mdc_Pointer* Mdc_Pointer_InitFromValue(
    struct Mdc_Pointer* pointer,
    intptr_t value
);

struct Mdc_Pointer* Mdc_Pointer_InitCopy(
    struct Mdc_Pointer* dest,
    const struct Mdc_Pointer* src
);

struct Mdc_Pointer* Mdc_Pointer_InitMove(
    struct Mdc_Pointer* dest,
    struct Mdc_Pointer* src
);

void Mdc_Pointer_Deinit(struct Mdc_Pointer* pointer);

int Mdc_Pointer_Compare(
    const struct Mdc_Pointer* pointer1,
    const struct Mdc_Pointer* pointer2
);

bool Mdc_Pointer_Equal(
    const struct Mdc_Pointer* pointer1,
    const struct Mdc_Pointer* pointer2
);

void* Mdc_Pointer_GetPointer(const struct Mdc_Pointer* pointer);

void Mdc_Pointer_SetPointer(struct Mdc_Pointer* pointer, void* ptr);

intptr_t Mdc_Pointer_GetValue(const struct Mdc_Pointer* pointer);

void Mdc_Pointer_SetValue(struct Mdc_Pointer* pointer, intptr_t value);

#endif /* MDC_C_OBJECT_POINTER_H_ */
