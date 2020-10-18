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

#include "../../../../include/mdc/filesystem/internal/filesystem_functions.h"

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
#include <shlwapi.h>

/*
* TODO (Mir Drualga): Delete this function implementation when
* Mdc_Fs_StatusFromPath is complete.
*/
bool Mdc_Fs_ExistsFromPath(
    const struct Mdc_Fs_Path* path
) {
  return PathFileExistsW(Mdc_Fs_Path_CStr(path));
}

struct Mdc_Fs_FileStatus* Mdc_Fs_StatusFromPath(
    struct Mdc_Fs_FileStatus* file_status,
    const struct Mdc_Fs_Path* path
) {
  /* TODO (Mir Drualga): Complete this function. */

  struct Mdc_Fs_FileStatus* init_file_status;
  const wchar_t* path_cstr;
  DWORD file_attributes;
  DWORD binary_type;

  enum Mdc_Fs_FileType file_type;
  enum Mdc_Fs_Perms permissions;

  HANDLE file_handle;

  permissions = Mdc_Fs_Perms_kOwnerRead
      | Mdc_Fs_Perms_kGroupRead
      | Mdc_Fs_Perms_kOthersRead;

  path_cstr = Mdc_Fs_Path_CStr(path);

  /* Check if file exists. */
  if (!PathFileExistsW(path_cstr)) {
    if (GetLastError() == ERROR_FILE_NOT_FOUND) {
      file_type = Mdc_Fs_FileType_kNotFound;
    } else {
      file_type = Mdc_Fs_FileType_kNone;
    }

    init_file_status = Mdc_Fs_FileStatus_InitFromType(
        file_status,
        file_type
    );

    if (init_file_status != file_status) {
      goto return_bad;
    }

    return file_status;
  }

  file_attributes = GetFileAttributesW(path_cstr);
  if (file_attributes == -1) {
    init_file_status = Mdc_Fs_FileStatus_InitFromType(
        file_status,
        Mdc_Fs_FileType_kUnknown
    );

    if (init_file_status != file_status) {
      goto return_bad;
    }

    return file_status;
  }

  /* Determine exec and write permissions. */
  if (GetBinaryTypeW(path_cstr, &binary_type)) {
    permissions |= Mdc_Fs_Perms_kOwnerExec
        | Mdc_Fs_Perms_kGroupExec
        | Mdc_Fs_Perms_kOthersExec;
  } else if ((file_attributes & FILE_ATTRIBUTE_READONLY) == 0) {
    permissions = permissions | Mdc_Fs_Perms_kOwnerWrite;
  }

  /* Determine file type. */
  file_handle = CreateFileW(
      path_cstr,
      0,
      0,
      NULL,
      OPEN_EXISTING,
      file_attributes,
      NULL
  );

  if (file_handle == INVALID_HANDLE_VALUE) {
    goto return_bad;
  }

  if ((file_attributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
    init_file_status = Mdc_Fs_FileStatus_InitFromType(
        file_status,
        Mdc_Fs_FileType_kDirectory
    );

    if (init_file_status != file_status) {
      goto return_bad;
    }

    return file_status;
  }

return_bad:
  return NULL;
}

#endif /* defined(_WIN32) || defined(_WIN64) */