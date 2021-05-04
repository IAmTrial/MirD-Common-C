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

#include "windows_file_version_info.h"

#if defined(_MSC_VER)

#include <stddef.h>
#include <string.h>
#include <windows.h>

#include "../../../include/mdc/error/exit_on_error.h"
#include "../../../include/mdc/malloc/malloc.h"

static void* FileVersionInfo_InitFromPath(const wchar_t* file_path) {
  DWORD ignored;

  BOOL is_get_file_version_info_success;

  void* file_version_info;
  DWORD file_version_info_size;

  /* Check file version info size. */
  file_version_info_size = GetFileVersionInfoSizeW(
      file_path,
      &ignored
  );

  if (file_version_info_size == 0) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoSizeW",
        GetLastError()
    );

    goto return_bad;
  }

  /* Get the file version info. */
  file_version_info = Mdc_malloc(file_version_info_size);
  if (file_version_info == NULL) {
    Mdc_Error_ExitOnMemoryAllocError(__FILEW__, __LINE__);
    goto return_bad;
  }

  ignored = 0;
  is_get_file_version_info_success = GetFileVersionInfoW(
      file_path,
      ignored,
      file_version_info_size,
      file_version_info
  );

  if (!is_get_file_version_info_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"GetFileVersionInfoW",
        GetLastError()
    );

    goto free_file_version_info;
  }

  return file_version_info;

free_file_version_info:
  Mdc_free(file_version_info);

return_bad:
  return NULL;
}

static void FileVersionInfo_Deinit(void* file_version_info) {
  Mdc_free(file_version_info);
}

void* Mdc_Windows_VerQueryValue(
    void* buffer,
    size_t buffer_size,
    const wchar_t* file_path,
    const wchar_t* sub_block
) {
  BOOL is_ver_query_value_success;

  void* file_version_info;

  UINT buffer_length;
  void* buffer_src;

  /* Get the file version info. */
  file_version_info = FileVersionInfo_InitFromPath(file_path);
  if (file_version_info == NULL) {
    goto return_bad;
  }

  /*
  * Gather all of the information into the specified buffer, then
  * check version info signature.
  */

  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      sub_block,
      &buffer_src,
      &buffer_length
  );

  if (!is_ver_query_value_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    goto deinit_file_version_info;
  }

  memcpy(buffer, buffer_src, buffer_size);

  FileVersionInfo_Deinit(file_version_info);

  return buffer;

deinit_file_version_info:
  FileVersionInfo_Deinit(file_version_info);

return_bad:
  return NULL;
}

UINT Mdc_Windows_VerQueryValueLength(
    const wchar_t* file_path,
    const wchar_t* sub_block
) {
  BOOL is_ver_query_value_success;

  void* file_version_info;

  UINT buffer_length;
  void* buffer_src;

  /* Get the file version info. */
  file_version_info = FileVersionInfo_InitFromPath(file_path);
  if (file_version_info == NULL) {
    goto return_bad;
  }

  /*
  * Gather all of the information into the specified buffer.
  */

  is_ver_query_value_success = VerQueryValueW(
      file_version_info,
      sub_block,
      &buffer_src,
      &buffer_length
  );

  if (!is_ver_query_value_success) {
    Mdc_Error_ExitOnWindowsFunctionError(
        __FILEW__,
        __LINE__,
        L"VerQueryValueW",
        GetLastError()
    );

    goto deinit_file_version_info;
  }

  FileVersionInfo_Deinit(file_version_info);

  return buffer_length;

deinit_file_version_info:
  FileVersionInfo_Deinit(file_version_info);

return_bad:
  return 0;
}

#endif /* defined(_MSC_VER) */
