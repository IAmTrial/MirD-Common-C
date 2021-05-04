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

#include "../../../include/mdc/windows/windows_vs_fixed_file_info.h"

#if defined(_MSC_VER)

#include "../../../include/mdc/error/exit_on_error.h"
#include "../../../include/mdc/malloc/malloc.h"
#include "../../../include/mdc/std/assert.h"
#include "windows_file_version_info.h"

#define VS_FIXEDFILEINFO_UNINIT { 0 }

static const VS_FIXEDFILEINFO VS_FIXEDFILEINFO_kUninit =
    VS_FIXEDFILEINFO_UNINIT;

int Mdc_Vs_FixedMajorMinorVersion_Compare(
    const struct Mdc_Vs_FixedMajorMinorVersion* version1,
    const struct Mdc_Vs_FixedMajorMinorVersion* version2
) {
  if (version1 == version2) {
    return 0;
  }

  if (version1->major_high < version2->major_high) {
    return -1;
  } else if (version1->major_high > version2->major_high) {
    return 1;
  }

  assert(version1->major_high == version2->major_high);

  if (version1->major_low < version2->major_low) {
    return -1;
  } else if (version1->major_low > version2->major_low) {
    return 1;
  }

  assert(version1->major_low == version2->major_low);

  if (version1->minor_high < version2->minor_high) {
    return -1;
  } else if (version1->minor_high > version2->minor_high) {
    return 1;
  }

  assert(version1->minor_high == version2->minor_high);

  if (version1->minor_low < version2->minor_low) {
    return -1;
  } else if (version1->minor_low > version2->minor_low) {
    return 1;
  }

  assert(version1->minor_low == version2->minor_low);

  return 0;
}

VS_FIXEDFILEINFO VS_FIXEDFILEINFO_Read(
    const wchar_t* file_path
) {
  VS_FIXEDFILEINFO fixed_file_info;
  void* result;

  result = Mdc_Windows_VerQueryValue(
      &fixed_file_info,
      sizeof(fixed_file_info),
      file_path,
      L"\\"
  );

  if (result != &fixed_file_info) {
    goto return_bad;
  }

  return fixed_file_info;

return_bad:
  return VS_FIXEDFILEINFO_kUninit;
}

struct Mdc_Vs_FixedMajorMinorVersion VS_FIXEDFILEINFO_GetFileVersion(
    const VS_FIXEDFILEINFO* fixed_file_info
) {
  struct Mdc_Vs_FixedMajorMinorVersion version;

  version.major_high = HIWORD(fixed_file_info->dwFileVersionMS);
  version.major_low = LOWORD(fixed_file_info->dwFileVersionMS);
  version.minor_high = HIWORD(fixed_file_info->dwFileVersionLS);
  version.minor_low = LOWORD(fixed_file_info->dwFileVersionLS);

  return version;
}

struct Mdc_Vs_FixedMajorMinorVersion VS_FIXEDFILEINFO_GetProductVersion(
    const VS_FIXEDFILEINFO* fixed_file_info
) {
  struct Mdc_Vs_FixedMajorMinorVersion version;

  version.major_high = HIWORD(fixed_file_info->dwProductVersionMS);
  version.major_low = LOWORD(fixed_file_info->dwProductVersionMS);
  version.minor_high = HIWORD(fixed_file_info->dwProductVersionLS);
  version.minor_low = LOWORD(fixed_file_info->dwProductVersionLS);

  return version;
}

#endif /* defined(_MSC_VER) */
