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

#ifndef MDC_C_FILESYSTEM_INTERNAL_PATH_IMPL_H_
#define MDC_C_FILESYSTEM_INTERNAL_PATH_IMPL_H_

#include "../../../../include/mdc/filesystem/internal/path.h"
#include "../../../../include/mdc/std/stdbool.h"

#define MDC_PATH_UNINIT { 0 }

const struct Mdc_Fs_Path Mdc_Fs_Path_kUninit;

const Mdc_Fs_Path_ValueType Mdc_Fs_Path_kSlashSeparator;
const Mdc_Fs_Path_ValueType Mdc_Fs_Path_kNullTerminator;

struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromCWStrTop(
    struct Mdc_Fs_Path* path,
    const Mdc_Fs_Path_ValueType* cstr,
    size_t count
);

bool Mdc_Fs_Path_IsSeparatorCh(Mdc_Fs_Path_ValueType ch);

#endif /* MDC_C_FILESYSTEM_INTERNAL_PATH_IMPL_H_ */
