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

#include "../../../../include/mdc/filesystem/internal/path.h"

#include <windows.h>
#include <shlwapi.h>

#include "../../../../include/mdc/filesystem/internal/filesystem_functions.h"
#include "../../../../include/mdc/wchar_t/wide_decoding.h"

#if defined(_WIN32) || defined(_WIN64)

#define MDC_PATH_UNINIT { 0 }

static const struct Mdc_Fs_Path Mdc_Fs_Path_kUninit = MDC_PATH_UNINIT;

const wchar_t Mdc_Fs_Path_kPreferredSeparator = L'\\';

/**
 * Initialization/deinitialization
 */

struct Mdc_Fs_Path* Mdc_Fs_Path_InitEmpty(struct Mdc_Fs_Path* path) {
  struct Mdc_BasicString* init_path_str;

  init_path_str = Mdc_BasicString_InitEmpty(
      &path->path_str_,
      Mdc_CharTraitsWChar_GetCharTraits()
  );

  if (init_path_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromAsciiCStr(
    struct Mdc_Fs_Path* path,
    const char* src
) {
  struct Mdc_BasicString* init_str;

  init_str = Mdc_Wide_DecodeAscii(&path->path_str_, src);
  if (init_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromDefaultMultibyteCStr(
    struct Mdc_Fs_Path* path,
    const char* src
) {
  struct Mdc_BasicString* init_str;

  init_str = Mdc_Wide_DecodeDefaultMultibyte(&path->path_str_, src);
  if (init_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromUtf8CStr(
    struct Mdc_Fs_Path* path,
    const char* src
) {
  struct Mdc_BasicString* init_str;

  init_str = Mdc_Wide_DecodeUtf8(&path->path_str_, src);
  if (init_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromCWStr(
    struct Mdc_Fs_Path* path,
    const wchar_t* src
) {
  struct Mdc_BasicString* init_str;

  init_str = Mdc_BasicString_InitFromCStr(
      &path->path_str_,
      Mdc_CharTraitsWChar_GetCharTraits(),
      src
  );

  if (init_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

/**
 * Etc. functions
 */

bool Mdc_Fs_Path_IsAbsolute(const struct Mdc_Fs_Path* path) {
  return !Mdc_Fs_Path_IsRelative(path);
}

bool Mdc_Fs_Path_IsRelative(const struct Mdc_Fs_Path* path) {
  const Mdc_Fs_Path_ValueType* path_cstr;

  path_cstr = Mdc_Fs_Path_CStr(path);

  return PathIsRelativeW(path_cstr);
}

struct Mdc_Fs_Path* Mdc_Fs_Path_ParentPath(
    struct Mdc_Fs_Path* parent_path,
    const struct Mdc_Fs_Path* path
) {
  size_t i;
  BOOL is_path_remove_file_spec_success;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;
  const Mdc_Fs_Path_ValueType* current_path_char;

  Mdc_Fs_Path_ValueType* parent_path_cstr;
  size_t parent_path_len;

  struct Mdc_Fs_Path* init_parent_path;

  if (!Mdc_Fs_ExistsFromPath(path)) {
    goto return_bad;
  }

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  parent_path_cstr = malloc((path_len + 1) * sizeof(parent_path_cstr[0]));
  if (parent_path_cstr == NULL) {
    goto return_bad;
  }

  wcscpy(parent_path_cstr, path_cstr);

  /* Convert all path separators into back slashes. */
  for (i = 0; i < path_len; i += 1) {
    if (parent_path_cstr[i] == L'/') {
      parent_path_cstr[i] = Mdc_Fs_Path_kPreferredSeparator;
    }
  }

  /* Remove the file. */
  is_path_remove_file_spec_success = PathRemoveFileSpecW(parent_path_cstr);
  if (!is_path_remove_file_spec_success) {
    goto free_parent_path_cstr;
  }

  parent_path_len = wcslen(parent_path_cstr);

  /* Restore the path separators. */
  for (i = 0; i < parent_path_len; i += 1) {
    current_path_char = Mdc_BasicString_AtConst(path_str, i);

    if (parent_path_cstr[i] != *current_path_char) {
      parent_path_cstr[i] = *current_path_char;
    }
  }

  /* Init the path. */
  init_parent_path = Mdc_Fs_Path_InitFromCWStr(
      parent_path,
      parent_path_cstr
  );

  if (init_parent_path != parent_path) {
    goto free_parent_path_cstr;
  }

  free(parent_path_cstr);

  return parent_path;

free_parent_path_cstr:
  free(parent_path_cstr);

return_bad:
  return NULL;
}

#endif /* defined(_WIN32) || defined(_WIN64) */
