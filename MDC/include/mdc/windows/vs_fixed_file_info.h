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

#ifndef MDC_C_WINDOWS_VS_FIXED_INFO_H_
#define MDC_C_WINDOWS_VS_FIXED_INFO_H_
#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

#include "../filesystem/filesystem.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

DLLEXPORT VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitFromPath(
    VS_FIXEDFILEINFO* fixed_file_info,
    const struct Mdc_Fs_Path* file_path
);

DLLEXPORT VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitCopy(
    VS_FIXEDFILEINFO* dest,
    const VS_FIXEDFILEINFO* src
);

DLLEXPORT VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitMove(
    VS_FIXEDFILEINFO* dest,
    VS_FIXEDFILEINFO* src
);

DLLEXPORT void Mdc_VS_FIXEDFILEINFO_Deinit(
    VS_FIXEDFILEINFO* fixed_file_info
);

DLLEXPORT VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_AssignCopy(
    VS_FIXEDFILEINFO* dest,
    const VS_FIXEDFILEINFO* src
);

DLLEXPORT VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_AssignMove(
    VS_FIXEDFILEINFO* dest,
    VS_FIXEDFILEINFO* src
);

DLLEXPORT bool Mdc_VS_FIXEDFILEINFO_Equal(
    const VS_FIXEDFILEINFO* fixed_file_info1,
    const VS_FIXEDFILEINFO* fixed_file_info2
);

#include "../../../dllexport_undefine.inc"
#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* MDC_C_WINDOWS_VS_FIXED_INFO_H_ */