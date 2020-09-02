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

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_Pointer {
  void* ptr_;
};

#define MDC_POINTER_UNINIT { 0 }

const struct Mdc_Pointer Mdc_Pointer_kUninit;

DLLEXPORT struct Mdc_Pointer* Mdc_Pointer_InitFromPointer(
    struct Mdc_Pointer* pointer,
    void* value
);

DLLEXPORT struct Mdc_Pointer* Mdc_Pointer_InitFromValue(
    struct Mdc_Pointer* pointer,
    intptr_t value
);

DLLEXPORT struct Mdc_Pointer* Mdc_Pointer_InitCopy(
    struct Mdc_Pointer* dest,
    const struct Mdc_Pointer* src
);

DLLEXPORT struct Mdc_Pointer* Mdc_Pointer_InitMove(
    struct Mdc_Pointer* dest,
    struct Mdc_Pointer* src
);

DLLEXPORT void Mdc_Pointer_Deinit(struct Mdc_Pointer* pointer);

DLLEXPORT int Mdc_Pointer_Compare(
    const struct Mdc_Pointer* pointer1,
    const struct Mdc_Pointer* pointer2
);

DLLEXPORT bool Mdc_Pointer_Equal(
    const struct Mdc_Pointer* pointer1,
    const struct Mdc_Pointer* pointer2
);

DLLEXPORT void* Mdc_Pointer_GetPointer(const struct Mdc_Pointer* pointer);

DLLEXPORT void Mdc_Pointer_SetPointer(
    struct Mdc_Pointer* pointer,
    void* ptr
);

DLLEXPORT intptr_t Mdc_Pointer_GetValue(const struct Mdc_Pointer* pointer);

DLLEXPORT void Mdc_Pointer_SetValue(
    struct Mdc_Pointer* pointer,
    intptr_t value
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_POINTER_H_ */
