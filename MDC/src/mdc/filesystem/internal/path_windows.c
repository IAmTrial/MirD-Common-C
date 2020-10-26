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

static struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromCWStrTop(
    struct Mdc_Fs_Path* path,
    const Mdc_Fs_Path_ValueType* cstr,
    size_t count
) {
  struct Mdc_BasicString* init_path_str;

  init_path_str = Mdc_BasicString_InitFromCStrTop(
      &path->path_str_,
      Mdc_CharTraitsWChar_GetCharTraits(),
      cstr,
      count
  );

  if (init_path_str != &path->path_str_) {
    goto return_bad;
  }

  return path;

return_bad:
  *path = Mdc_Fs_Path_kUninit;

  return NULL;
}

static enum Mdc_Fs_Path_RootNameType Mdc_Fs_Path_RootNameTypeFromPath(
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

    if (i_last_dot_char == 0) {
      /*
      * ".git" returns false
      * ". " returns false
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
  bool has_dot_ch;
  size_t i_dot_ch;
  enum Mdc_Fs_Path_RootNameType root_type;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  /* Locate the last path separator. */
  has_parent_separator = false;
  has_dot_ch = false;

  for (i = path_len - 1; i != (size_t) -1; i -= 1) {
    if (!has_parent_separator && Mdc_Fs_Path_IsSeparatorCh(path_cstr[i])) {
      has_parent_separator = true;
      i_parent_separator = i;

      break;
    }

    if (!has_dot_ch && path_cstr[i] == L'.') {
      has_dot_ch = true;
      i_dot_ch = i;
    }
  }

  root_type = Mdc_Fs_Path_RootNameTypeFromPath(path);

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
    init_extension = Mdc_Fs_Path_InitFromCWStr(
        extension,
        &path_cstr[i_dot_ch]
    );
  }

  if (init_extension != extension) {
    goto return_bad;
  }

  return extension;

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_Filename(
    struct Mdc_Fs_Path* filename,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_Fs_Path* init_filename;
  struct Mdc_Fs_Path* init_stem;

  struct Mdc_Fs_Path extension;
  struct Mdc_Fs_Path* init_extension;

  init_stem = Mdc_Fs_Path_Stem(filename, path);
  if (init_stem != filename) {
    goto return_bad;
  }

  init_extension = Mdc_Fs_Path_Extension(&extension, path);
  if (init_extension != &extension) {
    goto deinit_stem;
  }

  init_filename = Mdc_Fs_Path_ConcatPath(filename, &extension);
  if (init_filename != filename) {
    goto deinit_extension;
  }

  Mdc_Fs_Path_Deinit(&extension);

  return filename;

deinit_extension:
  Mdc_Fs_Path_Deinit(&extension);

deinit_stem:
  Mdc_Fs_Path_Deinit(filename);

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

  root_type = Mdc_Fs_Path_RootNameTypeFromPath(path);

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

struct Mdc_Fs_Path* Mdc_Fs_Path_ParentPath(
    struct Mdc_Fs_Path* parent_path,
    const struct Mdc_Fs_Path* path
) {
  Mdc_Fs_Path_ValueType previous_path_ch;

  struct Mdc_Fs_Path* init_parent_path;
  size_t parent_path_len;
  size_t relative_parent_path_len;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;

  struct Mdc_Fs_Path relative_path;
  struct Mdc_Fs_Path* init_relative_path;
  const struct Mdc_BasicString* relative_path_str;
  const Mdc_Fs_Path_ValueType* relative_path_cstr;
  size_t relative_path_len;

  struct Mdc_Fs_Path filename;
  struct Mdc_Fs_Path* init_filename;
  const struct Mdc_BasicString* filename_str;
  const Mdc_Fs_Path_ValueType* filename_cstr;
  size_t filename_len;

  struct Mdc_Fs_Path root_path;
  struct Mdc_Fs_Path* init_root_path;
  const struct Mdc_BasicString* root_path_str;
  size_t root_path_len;

  /*
  * Create the parent relative path to prevent cutting off root
  * directory.
  */
  init_relative_path = Mdc_Fs_Path_RelativePath(&relative_path, path);
  if (init_relative_path != &relative_path) {
    goto return_bad;
  }

  relative_path_str = Mdc_Fs_Path_Native(&relative_path);
  relative_path_cstr = Mdc_BasicString_DataConst(relative_path_str);
  relative_path_len = Mdc_BasicString_Length(relative_path_str);

  init_filename = Mdc_Fs_Path_Filename(&filename, path);
  if (init_filename != &filename) {
    goto deinit_relative_path;
  }

  filename_str = Mdc_Fs_Path_Native(&filename);
  filename_cstr = Mdc_BasicString_DataConst(filename_str);
  filename_len = Mdc_BasicString_Length(filename_str);

  /* Exclude the path separator. */
  relative_parent_path_len = relative_path_len - filename_len;
  while (relative_parent_path_len > 0) {
    previous_path_ch = relative_path_cstr[relative_parent_path_len - 1];

    if (!Mdc_Fs_Path_IsSeparatorCh(previous_path_ch)) {
      break;
    }

    relative_parent_path_len -= 1;
  }

  /* Determine the parent path's length. */
  init_root_path = Mdc_Fs_Path_RootPath(&root_path, path);
  if (init_root_path != &root_path) {
    goto deinit_filename;
  }

  root_path_str = Mdc_Fs_Path_Native(&root_path);
  root_path_len = Mdc_BasicString_Length(root_path_str);

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);

  parent_path_len = root_path_len + relative_parent_path_len;

  init_parent_path = Mdc_Fs_Path_InitFromCWStrTop(
      parent_path,
      path_cstr,
      parent_path_len
  );

  if (init_parent_path != parent_path) {
    goto deinit_root_path;
  }

  Mdc_Fs_Path_Deinit(&root_path);
  Mdc_Fs_Path_Deinit(&filename);
  Mdc_Fs_Path_Deinit(&relative_path);

  return parent_path;

deinit_root_path:
  Mdc_Fs_Path_Deinit(&root_path);

deinit_filename:
  Mdc_Fs_Path_Deinit(&filename);

deinit_relative_path:
  Mdc_Fs_Path_Deinit(&relative_path);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_RelativePath(
    struct Mdc_Fs_Path* relative_path,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_Fs_Path* init_relative_path;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;

  struct Mdc_Fs_Path root_path;
  struct Mdc_Fs_Path* init_root_path;
  const struct Mdc_BasicString* root_path_str;
  size_t root_path_len;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);

  init_root_path = Mdc_Fs_Path_RootPath(&root_path, path);
  if (init_root_path != &root_path) {
    goto return_bad;
  }

  root_path_str = Mdc_Fs_Path_Native(&root_path);
  root_path_len = Mdc_BasicString_Length(root_path_str);

  init_relative_path = Mdc_Fs_Path_InitFromCWStr(
      relative_path,
      &path_cstr[root_path_len]
  );

  if (init_relative_path != relative_path) {
    goto deinit_root_path;
  }

  Mdc_Fs_Path_Deinit(&root_path);

  return relative_path;

deinit_root_path:
  Mdc_Fs_Path_Deinit(&root_path);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_RootDirectory(
    struct Mdc_Fs_Path* root_directory,
    const struct Mdc_Fs_Path* path
) {
  size_t i;

  struct Mdc_Fs_Path* init_root_directory;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;
  size_t root_directory_len;

  struct Mdc_Fs_Path root_name;
  struct Mdc_Fs_Path* init_root_name;
  const struct Mdc_BasicString* root_name_str;
  size_t root_name_len;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  /* Use the root name to determine the start of the root directory. */
  init_root_name = Mdc_Fs_Path_RootName(&root_name, path);
  if (init_root_name != &root_name) {
    goto return_bad;
  }

  root_name_str = Mdc_Fs_Path_Native(&root_name);
  root_name_len = Mdc_BasicString_Length(root_name_str);

  for (i = root_name_len; i < path_len; i += 1) {
    if (!Mdc_Fs_Path_IsSeparatorCh(path_cstr[i])) {
      break;
    }
  }

  root_directory_len = i - root_name_len;

  init_root_directory = Mdc_Fs_Path_InitFromCWStrTop(
      root_directory,
      &path_cstr[root_name_len],
      root_directory_len
  );

  if (init_root_directory != root_directory) {
    goto deinit_root_name;
  }

  Mdc_Fs_Path_Deinit(&root_name);

  return root_directory;

deinit_root_name:
  Mdc_Fs_Path_Deinit(&root_name);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_RootName(
    struct Mdc_Fs_Path* root_name,
    const struct Mdc_Fs_Path* path
) {
  size_t i;

  struct Mdc_Fs_Path* init_root_name;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;

  enum Mdc_Fs_Path_RootNameType root_name_type;
  size_t i_unc_root_name_end;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  root_name_type = Mdc_Fs_Path_RootNameTypeFromPath(path);

  switch (root_name_type) {
    case Mdc_Fs_Path_RootNameType_kNone: {
      init_root_name = Mdc_Fs_Path_InitEmpty(root_name);

      break;
    }

    case Mdc_Fs_Path_RootNameType_kDrive: {
      init_root_name = Mdc_Fs_Path_InitFromCWStrTop(
          root_name,
          path_cstr,
          2
      );

      break;
    }

    case Mdc_Fs_Path_RootNameType_kUnc: {
      if (path_len < 3 || Mdc_Fs_Path_IsSeparatorCh(path_cstr[2])) {
        init_root_name = Mdc_Fs_Path_InitEmpty(root_name);
      } else {
        for (i = 3; i < path_len; i += 1) {
          if (Mdc_Fs_Path_IsSeparatorCh(path_cstr[i])) {
            break;
          }
        }

        i_unc_root_name_end = i;

        init_root_name = Mdc_Fs_Path_InitFromCWStrTop(
            root_name,
            path_cstr,
            i_unc_root_name_end
        );
      }

      break;
    }

    default: {
      goto return_bad;
    }
  }

  if (init_root_name != root_name) {
    goto return_bad;
  }

  return root_name;

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_RootPath(
    struct Mdc_Fs_Path* root_path,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_Fs_Path* append_root_path;
  struct Mdc_Fs_Path* init_root_name;

  struct Mdc_Fs_Path root_directory;
  struct Mdc_Fs_Path* init_root_directory;

  init_root_name = Mdc_Fs_Path_RootName(root_path, path);
  if (init_root_name != root_path) {
    goto return_bad;
  }

  init_root_directory = Mdc_Fs_Path_RootDirectory(&root_directory, path);
  if (init_root_directory != &root_directory) {
    goto deinit_root_name;
  }

  append_root_path = Mdc_Fs_Path_AppendPath(root_path, &root_directory);
  if (append_root_path != root_path) {
    goto deinit_root_directory;
  }

  Mdc_Fs_Path_Deinit(&root_directory);

  return root_path;

deinit_root_directory:
  Mdc_Fs_Path_Deinit(&root_directory);

deinit_root_name:
  Mdc_Fs_Path_Deinit(root_path);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_Stem(
    struct Mdc_Fs_Path* stem,
    const struct Mdc_Fs_Path* path
) {
  size_t i;

  struct Mdc_Fs_Path* init_stem;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;

  const Mdc_Fs_Path_ValueType* filename_cstr;
  size_t stem_len;

  bool has_parent_separator;
  size_t i_parent_separator;
  bool has_dot_ch;
  size_t i_dot_ch;
  enum Mdc_Fs_Path_RootNameType root_type;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  /* Locate the last path separator. */
  has_parent_separator = false;
  has_dot_ch = false;

  for (i = path_len - 1; i != (size_t) -1; i -= 1) {
    if (!has_parent_separator && Mdc_Fs_Path_IsSeparatorCh(path_cstr[i])) {
      has_parent_separator = true;
      i_parent_separator = i;

      break;
    }

    if (!has_dot_ch && path_cstr[i] == L'.') {
      has_dot_ch = true;
      i_dot_ch = i;
    }
  }

  root_type = Mdc_Fs_Path_RootNameTypeFromPath(path);

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

  if (filename_cstr == NULL) {
    init_stem = Mdc_Fs_Path_InitEmpty(stem);
  } else if (!Mdc_Fs_Path_HasExtensionFromFilename(filename_cstr)) {
    init_stem = Mdc_Fs_Path_InitFromCWStr(stem, filename_cstr);
  } else {
    assert(has_dot_ch);

    stem_len = filename_cstr - &path_cstr[i_dot_ch];

    init_stem = Mdc_Fs_Path_InitFromCWStrTop(
        stem,
        filename_cstr,
        stem_len
    );
  }

  if (init_stem != stem) {
    goto return_bad;
  }

  return stem;

return_bad:
  return NULL;
}

#endif /* defined(_WIN32) || defined(_WIN64) */
