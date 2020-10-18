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

#ifndef MDC_C_FILESYSTEM_INTERNAL_SPACE_INFO_H_
#define MDC_C_FILESYSTEM_INTERNAL_SPACE_INFO_H_

#include "../../std/stdbool.h"
#include "../../std/stdint.h"

#include "../../../../dllexport_define.inc"

struct Mdc_Fs_SpaceInfo {
  uintmax_t capacity;
  uintmax_t free;
  uintmax_t available;
};

DLLEXPORT bool Mdc_Fs_SpaceInfo_Equal(
    const struct Mdc_Fs_SpaceInfo* space_info1,
    const struct Mdc_Fs_SpaceInfo* space_info2
);

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_FILESYSTEM_INTERNAL_SPACE_INFO_H_ */
