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
#include "../../../../include/mdc/std/assert.h"
#include "../../../../include/mdc/std/wchar.h"
#include "../../../../include/mdc/wchar_t/wide_decoding.h"
#include "path_separator.h"

#if defined(_WIN32) || defined(_WIN64)

#define MDC_PATH_UNINIT { 0 }

static const struct Mdc_Fs_Path Mdc_Fs_Path_kUninit = MDC_PATH_UNINIT;

/**
 * Static functions
 */

enum Mdc_Fs_Path_RootNameType {
  Mdc_Fs_Path_RootNameType_kNone,
  Mdc_Fs_Path_RootNameType_kDrive,
  Mdc_Fs_Path_RootNameType_kUnc,
};

static enum Mdc_Fs_Path_RootNameType Mdc_Fs_Path_GetRootNameType(
    const struct Mdc_Fs_Path* path
) {
  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_str_len;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_str_len = Mdc_BasicString_Length(path_str);

  if (path_str_len < 2) {
    return Mdc_Fs_Path_RootNameType_kNone;
  }

  /* Detect drive root paths. */
  if (iswalpha(path_cstr[0])
      && path_cstr[1] == L':') {
    return Mdc_Fs_Path_RootNameType_kDrive;
  }

  /* UNC names start with two path separators. */
  if (Mdc_Fs_Path_IsSeparatorCh(path_cstr[0])
      && Mdc_Fs_Path_IsSeparatorCh(path_cstr[1])) {
    return Mdc_Fs_Path_RootNameType_kUnc;
  }

  return Mdc_Fs_Path_RootNameType_kNone;
}

static bool Mdc_Fs_Path_HasExtensionFromFilename(
    const Mdc_Fs_Path_ValueType* filename
) {
  size_t i;

  size_t filename_len;

  bool has_dot_char;
  size_t i_last_dot_char;

  filename_len = wcslen(filename);

  if (filename_len == 0) {
    return false;
  }

  has_dot_char = false;

  for (i = filename_len - 1; i != (size_t) -1; i -= 1) {
    if (Mdc_Fs_Path_IsSeparatorCh(filename[i])) {
      break;
    }

    if (filename[i] == L'.') {
      has_dot_char = true;
      i_last_dot_char = i;

      break;
    }
  }

  if (!has_dot_char) {
    return false;
  }

  if (filename[0] == L'.') {
    if (filename[1] == L'\0') {
      /* "." returns false */
      return false;
    }

    assert(filename_len >= 2);

    if (filename[1] == L'.' && filename[2] == L'\0') {
      /* ".." returns false */
      return false;
    }

    if (i_last_dot_char == 0 && !iswspace(filename[1])) {
      /*
      * ".git" returns false
      * ". " returns true
      */
      return false;
    }
  }

  return true;
}

/**
 * External functions
 */

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

struct Mdc_Fs_Path* Mdc_Fs_Path_Extension(
    struct Mdc_Fs_Path* extension,
    const struct Mdc_Fs_Path* path
) {
  size_t i;

  struct Mdc_Fs_Path* init_extension;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;

  const Mdc_Fs_Path_ValueType* filename_cstr;

  bool has_parent_separator;
  size_t i_parent_separator;
  enum Mdc_Fs_Path_RootNameType root_type;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  /* Locate the last path separator. */
  has_parent_separator = false;

  for (i = path_len - 1; i != (size_t) -1; i -= 1) {
    if (!has_parent_separator && Mdc_Fs_Path_IsSeparatorCh(path_cstr[i])) {
      has_parent_separator = true;
      i_parent_separator = i;

      break;
    }
  }

  root_type = Mdc_Fs_Path_GetRootNameType(path);

  if (!has_parent_separator) {
    /*
    * If there is no path separator, then there is either no root
    * name or the root name is a drive path.
    */
    switch (root_type) {
      case Mdc_Fs_Path_RootNameType_kNone: {
        filename_cstr = path_cstr;
        break;
      }

      case Mdc_Fs_Path_RootNameType_kDrive: {
        filename_cstr = &path_cstr[2];
        break;
      }

      default: {
        goto return_bad;
      }
    }
  } else {
    switch (root_type) {
      case Mdc_Fs_Path_RootNameType_kNone:
      case Mdc_Fs_Path_RootNameType_kDrive: {
        filename_cstr = &path_cstr[i_parent_separator + 1];
        break;
      }

      case Mdc_Fs_Path_RootNameType_kUnc: {
        if (i_parent_separator == 1) {
          filename_cstr = NULL;
        } else {
          filename_cstr = &path_cstr[i_parent_separator + 1];
        }

        break;
      }

      default: {
        goto return_bad;
      }
    }
  }

  if (filename_cstr == NULL
      || !Mdc_Fs_Path_HasExtensionFromFilename(filename_cstr)) {
    init_extension = Mdc_Fs_Path_InitEmpty(extension);
  } else {
    init_extension = Mdc_Fs_Path_InitFromCWStr(extension, filename_cstr);
  }

  if (init_extension != extension) {
    goto return_bad;
  }

  return extension;

return_bad:
  return NULL;
}

bool Mdc_Fs_Path_IsAbsolute(const struct Mdc_Fs_Path* path) {
  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_str_len;

  enum Mdc_Fs_Path_RootNameType root_type;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_str_len = Mdc_BasicString_Length(path_str);

  root_type = Mdc_Fs_Path_GetRootNameType(path);

  if (path_str_len < 3 || path_cstr[2] == L'\0') {
    return false;
  }

  switch (root_type) {
    case Mdc_Fs_Path_RootNameType_kDrive: {
      return Mdc_Fs_Path_IsSeparatorCh(path_cstr[2]);
    }

    case Mdc_Fs_Path_RootNameType_kUnc: {
      return !Mdc_Fs_Path_IsSeparatorCh(path_cstr[2]);
    }

    case Mdc_Fs_Path_RootNameType_kNone: {
      return false;
    }
  }

  return false;
}

bool Mdc_Fs_Path_IsRelative(const struct Mdc_Fs_Path* path) {
  return !Mdc_Fs_Path_IsAbsolute(path);
}

#endif /* defined(_WIN32) || defined(_WIN64) */
