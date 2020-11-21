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

#include "../../../include/mdc/windows/vs_fixed_file_info.h"

#if defined(_WIN32) || defined(_WIN64)

#include "../../../include/mdc/malloc/malloc.h"

VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitFromPath(
    VS_FIXEDFILEINFO* fixed_file_info,
    const struct Mdc_Fs_Path* file_path
) {
  DWORD ignored;

  const wchar_t* file_path_cstr;

  void* file_version_info;
  DWORD file_version_info_size;

  BOOL is_get_file_version_info_success;
  BOOL is_ver_query_value_success;

  VS_FIXEDFILEINFO* temp_fixed_file_info;
  UINT temp_file_info_size;

  /* Check version size. */
  file_path_cstr = Mdc_Fs_Path_CStr(file_path);

  file_version_info_size = GetFileVersionInfoSizeW(
      file_path_cstr,
      &ignored
  );

  if (file_version_info_size == 0) {
    goto return_bad;
  }

  /* Get the file version info.*/
  file_version_info = Mdc_malloc(file_version_info_size);

  if (file_version_info == NULL) {
    goto return_bad;
  }

  ignored = 0;
  is_get_file_version_info_success = GetFileVersionInfoW(
      file_path_cstr,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    goto free_file_version_info;
  }

  /* Gather all of the information into the specified buffer. */
  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      L"\\",
      (void**) &temp_fixed_file_info,
      &temp_file_info_size
  );

  if (!is_ver_query_value_success) {
    goto free_file_version_info;
  }

  /* Copy the file info into the parameter. */
  *fixed_file_info = *temp_fixed_file_info;

  Mdc_free(file_version_info);

  return fixed_file_info;

free_file_version_info:
  Mdc_free(file_version_info);

return_bad:
  return NULL;
}

VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitCopy(
    VS_FIXEDFILEINFO* dest,
    const VS_FIXEDFILEINFO* src
) {
  *dest = *src;
  return dest;
}

VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_InitMove(
    VS_FIXEDFILEINFO* dest,
    VS_FIXEDFILEINFO* src
) {
  return Mdc_VS_FIXEDFILEINFO_InitCopy(dest, src);
}

void Mdc_VS_FIXEDFILEINFO_Deinit(
    VS_FIXEDFILEINFO* fixed_file_info
) {
  /* This is intentionally left blank. */
}
VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_AssignCopy(
    VS_FIXEDFILEINFO* dest,
    const VS_FIXEDFILEINFO* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;
  return dest;
}

VS_FIXEDFILEINFO* Mdc_VS_FIXEDFILEINFO_AssignMove(
    VS_FIXEDFILEINFO* dest,
    VS_FIXEDFILEINFO* src
) {
  if (dest == src) {
    return dest;
  }

  return Mdc_VS_FIXEDFILEINFO_AssignCopy(dest, src);
}

bool Mdc_VS_FIXEDFILEINFO_Equal(
    const VS_FIXEDFILEINFO* fixed_file_info1,
    const VS_FIXEDFILEINFO* fixed_file_info2
) {
  int compare_result;

  compare_result = memcmp(
      fixed_file_info1,
      fixed_file_info2,
      sizeof(*fixed_file_info1)
  );

  return compare_result == 0;
}

#endif /* defined(_WIN32) || defined(_WIN64) */
