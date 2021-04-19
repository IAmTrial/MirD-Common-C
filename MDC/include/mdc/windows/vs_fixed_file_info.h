/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2021  Mir Drualga
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

#ifndef MDC_C_WINDOWS_VS_FIXED_FILE_INFO_H_
#define MDC_C_WINDOWS_VS_FIXED_FILE_INFO_H_

#if defined(_MSC_VER)

#include <windows.h>

#include "../std/wchar.h"

#include "../../../dllexport_define.inc"

struct Vs_FixedMajorMinorVersion {
  unsigned short major_high;
  unsigned short major_low;
  unsigned short minor_high;
  unsigned short minor_low;
};

DLLEXPORT int Vs_FixedMajorMinorVersion_Compare(
    const struct Vs_FixedMajorMinorVersion* version1,
    const struct Vs_FixedMajorMinorVersion* version2
);

DLLEXPORT VS_FIXEDFILEINFO VS_FIXEDFILEINFO_Read(
    const wchar_t* file_path
);

DLLEXPORT struct Vs_FixedMajorMinorVersion VS_FIXEDFILEINFO_GetFileVersion(
    const VS_FIXEDFILEINFO* fixed_file_info
);

DLLEXPORT struct Vs_FixedMajorMinorVersion
VS_FIXEDFILEINFO_GetProductVersion(
    const VS_FIXEDFILEINFO* fixed_file_info
);

#include "../../../dllexport_undefine.inc"

#endif /* defined(_MSC_VER) */

#endif /* MDC_C_WINDOWS_VS_FIXED_FILE_INFO_H_ */
