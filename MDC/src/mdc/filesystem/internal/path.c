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

#include "path_internal.h"

const struct Mdc_Fs_Path Mdc_Fs_Path_kUninit = MDC_PATH_UNINIT;

/**
 * Static functions
 */

typedef struct Mdc_Fs_Path*
(*Mdc_Fs_Path_GetPathElementFunc)(struct Mdc_Fs_Path*, const struct Mdc_Fs_Path*);

static bool Mdc_Fs_Path_HasPathElement(
    const struct Mdc_Fs_Path* path,
    Mdc_Fs_Path_GetPathElementFunc get_element_func
) {
  struct Mdc_Fs_Path path_element;
  struct Mdc_Fs_Path* init_path_element;
  bool is_empty;

  init_path_element = get_element_func(&path_element, path);
  if (init_path_element != &path_element) {
    goto return_bad;
  }

  is_empty = Mdc_Fs_Path_Empty(&path_element);

  Mdc_Fs_Path_Deinit(&path_element);

  return !is_empty;

return_bad:
  return false;
}

/**
 * Internal functions
 */

bool Mdc_Fs_Path_IsSeparatorCh(Mdc_Fs_Path_ValueType ch) {
  return ch == Mdc_Fs_Path_kSlashSeparator
      || ch == Mdc_Fs_Path_kPreferredSeparator;
}

/**
 * External functions
 */

struct Mdc_Fs_Path* Mdc_Fs_Path_InitCopy(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src
) {
  struct Mdc_BasicString* init_dest_path_str;

  init_dest_path_str = Mdc_BasicString_InitCopy(
      &dest->path_str_,
      &src->path_str_
  );

  if (init_dest_path_str != &dest->path_str_) {
    goto return_bad;
  }

  return dest;

return_bad:
  *dest = Mdc_Fs_Path_kUninit;

  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_InitMove(
    struct Mdc_Fs_Path* dest,
    struct Mdc_Fs_Path* src
) {
  struct Mdc_BasicString* init_dest_path_str;

  init_dest_path_str = Mdc_BasicString_InitMove(
      &dest->path_str_,
      &src->path_str_
  );

  if (init_dest_path_str != &dest->path_str_) {
    goto return_bad;
  }

  return dest;

return_bad:
  *dest = Mdc_Fs_Path_kUninit;

  return NULL;
}

void Mdc_Fs_Path_Deinit(struct Mdc_Fs_Path* path) {
  Mdc_BasicString_Deinit(&path->path_str_);
}

struct Mdc_Fs_Path* Mdc_Fs_Path_AssignCopy(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src
) {
  struct Mdc_Fs_Path temp_path;
  struct Mdc_Fs_Path* init_temp_path;

  struct Mdc_Fs_Path* assign_dest;

  init_temp_path = Mdc_Fs_Path_InitCopy(&temp_path, src);
  if (init_temp_path != &temp_path) {
    goto return_bad;
  }

  assign_dest = Mdc_Fs_Path_AssignMove(dest, &temp_path);
  if (assign_dest != dest) {
    goto deinit_temp_path;
  }

  Mdc_Fs_Path_Deinit(&temp_path);

  return dest;

deinit_temp_path:
  Mdc_Fs_Path_Deinit(&temp_path);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_AssignMove(
    struct Mdc_Fs_Path* dest,
    struct Mdc_Fs_Path* src
) {
  struct Mdc_BasicString* assign_dest_path_str;

  assign_dest_path_str = Mdc_BasicString_AssignMove(
      &dest->path_str_,
      &src->path_str_
  );

  if (assign_dest_path_str != &dest->path_str_) {
    goto return_bad;
  }

  return dest;

return_bad:
  return NULL;
}

/**
 * Append functions
 */

struct Mdc_Fs_Path* Mdc_Fs_Path_AppendPathWithPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src1,
    const struct Mdc_Fs_Path* src2
) {
  struct Mdc_Fs_Path* init_dest;
  struct Mdc_Fs_Path* append_path;

  init_dest = Mdc_Fs_Path_InitCopy(dest, src1);
  if (init_dest != dest) {
    goto return_bad;
  }

  append_path = Mdc_Fs_Path_AppendPath(dest, src2);
  if (append_path != dest) {
    goto deinit_dest;
  }

  return dest;

deinit_dest:
  Mdc_Fs_Path_Deinit(dest);

return_bad:
  return NULL;
}

/**
 * Concat functions
 */

struct Mdc_Fs_Path* Mdc_Fs_Path_ConcatPathWithPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src1,
    const struct Mdc_Fs_Path* src2
) {
  struct Mdc_Fs_Path* init_dest;
  struct Mdc_Fs_Path* concat_path;

  init_dest = Mdc_Fs_Path_InitCopy(dest, src1);
  if (init_dest != dest) {
    goto return_bad;
  }

  concat_path = Mdc_Fs_Path_ConcatPath(dest, src2);
  if (concat_path != dest) {
    goto deinit_dest;
  }

  return dest;

deinit_dest:
  Mdc_Fs_Path_Deinit(dest);

return_bad:
  return NULL;
}

/**
 * Comparison operators
 */

bool Mdc_Fs_Path_Equal(
    const struct Mdc_Fs_Path* path1,
    const struct Mdc_Fs_Path* path2
) {
  return Mdc_BasicString_EqualStr(&path1->path_str_, &path2->path_str_);
}

int Mdc_Fs_Path_Compare(
    const struct Mdc_Fs_Path* path1,
    const struct Mdc_Fs_Path* path2
) {
  return Mdc_BasicString_CompareStr(&path1->path_str_, &path2->path_str_);
}

/**
 * Etc. functions
 */

struct Mdc_Fs_Path* Mdc_Fs_Path_AppendPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_Fs_Path* assign_dest;

  struct Mdc_Fs_Path dest_root_name;
  struct Mdc_Fs_Path* init_dest_root_name;

  struct Mdc_Fs_Path path_root_name;
  struct Mdc_Fs_Path* init_path_root_name;

  struct Mdc_Fs_Path path_separator;
  struct Mdc_Fs_Path* init_path_separator;
  struct Mdc_Fs_Path* concat_path_separator;

  struct Mdc_Fs_Path path_root_directory;
  struct Mdc_Fs_Path* init_path_root_directory;
  struct Mdc_Fs_Path* concat_path_root_directory;

  struct Mdc_Fs_Path path_relative_path;
  struct Mdc_Fs_Path* init_path_relative_path;
  struct Mdc_Fs_Path* concat_path_relative_path;

  if (Mdc_Fs_Path_IsAbsolute(path)) {
    /* Replace the entire dest with path. */
    assign_dest = Mdc_Fs_Path_AssignCopy(dest, path);

    if (assign_dest != dest) {
      goto return_bad;
    }

    return dest;
  }

  if (Mdc_Fs_Path_HasRootName(path)) {
    init_dest_root_name = Mdc_Fs_Path_RootName(&dest_root_name, dest);
    if (init_dest_root_name != &dest_root_name) {
      goto return_bad;
    }

    init_path_root_name = Mdc_Fs_Path_RootName(&path_root_name, dest);
    if (init_path_root_name != &path_root_name) {
      Mdc_Fs_Path_Deinit(&dest_root_name);
      goto return_bad;
    }

    if (!Mdc_Fs_Path_Equal(&dest_root_name, &path_root_name)) {
      /* Replace the entire dest with path. */
      assign_dest = Mdc_Fs_Path_AssignCopy(dest, path);

      if (assign_dest != dest) {
        Mdc_Fs_Path_Deinit(&path_root_name);
        Mdc_Fs_Path_Deinit(&dest_root_name);
        goto return_bad;
      }

      Mdc_Fs_Path_Deinit(&path_root_name);
      Mdc_Fs_Path_Deinit(&dest_root_name);

      return dest;
    }

    Mdc_Fs_Path_Deinit(&path_root_name);
    Mdc_Fs_Path_Deinit(&dest_root_name);
  }

  if (Mdc_Fs_Path_HasRootDirectory(path)) {
    /*
    * Remove the dest's root directory and relative path, leaving only
    * the root name.
    */
    init_dest_root_name = Mdc_Fs_Path_RootName(&dest_root_name, dest);
    if (init_dest_root_name != &dest_root_name) {
      goto return_bad;
    }

    assign_dest = Mdc_Fs_Path_AssignMove(dest, &dest_root_name);
    if (assign_dest != dest) {
      Mdc_Fs_Path_Deinit(&dest_root_name);
      goto return_bad;
    }

    Mdc_Fs_Path_Deinit(&dest_root_name);
  } else if (Mdc_Fs_Path_HasFilename(dest)
      || (!Mdc_Fs_Path_HasRootDirectory(dest)
          && Mdc_Fs_Path_IsAbsolute(dest))) {
    /* Append preferred path separator. */
    init_path_separator = Mdc_Fs_Path_InitFromCWStrTop(
        &path_separator,
        &Mdc_Fs_Path_kPreferredSeparator,
        1
    );

    if (init_path_separator != &path_separator) {
      Mdc_Fs_Path_Deinit(&path_separator);
      goto return_bad;
    }

    concat_path_separator = Mdc_Fs_Path_ConcatPath(dest, &path_separator);
    if (concat_path_separator != dest) {
      Mdc_Fs_Path_Deinit(&path_separator);
      goto return_bad;
    }

    Mdc_Fs_Path_Deinit(&path_separator);
  }

  /* Concat path without root to dest. */
  init_path_root_directory = Mdc_Fs_Path_RootDirectory(
      &path_root_directory,
      path
  );

  if (init_path_root_directory != &path_root_directory) {
    goto return_bad;
  }

  init_path_relative_path = Mdc_Fs_Path_RelativePath(
      &path_relative_path,
      path
  );

  if (init_path_relative_path != &path_relative_path) {
    goto deinit_path_nameless_root;
  }

  concat_path_root_directory = Mdc_Fs_Path_ConcatPath(
      dest,
      &path_root_directory
  );

  if (concat_path_root_directory != dest) {
    goto deinit_path_relative_path;
  }

  concat_path_relative_path = Mdc_Fs_Path_ConcatPath(
      dest,
      &path_relative_path
  );

  if (concat_path_relative_path != dest) {
    goto deinit_path_relative_path;
  }

  Mdc_Fs_Path_Deinit(&path_relative_path);
  Mdc_Fs_Path_Deinit(&path_root_directory);

  return dest;

deinit_path_relative_path:
  Mdc_Fs_Path_Deinit(&path_relative_path);

deinit_path_nameless_root:
  Mdc_Fs_Path_Deinit(&path_root_directory);

return_bad:
  return NULL;
}

const Mdc_Fs_Path_ValueType* Mdc_Fs_Path_CStr(
    const struct Mdc_Fs_Path* path
) {
  return Mdc_BasicString_CStr(Mdc_Fs_Path_Native(path));
}

void Mdc_Fs_Path_Clear(struct Mdc_Fs_Path* path) {
  Mdc_BasicString_Clear(&path->path_str_);
}

struct Mdc_Fs_Path* Mdc_Fs_Path_ConcatPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_BasicString* concat_str;

  concat_str = Mdc_BasicString_AppendStr(
      &dest->path_str_,
      &path->path_str_
  );

  if (concat_str != &dest->path_str_) {
    goto return_bad;
  }

  return dest;

return_bad:
  return NULL;
}

bool Mdc_Fs_Path_Empty(const struct Mdc_Fs_Path* path) {
  return Mdc_BasicString_Empty(&path->path_str_);
}

bool Mdc_Fs_Path_HasExtension(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_Extension);
}

bool Mdc_Fs_Path_HasFilename(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_Filename);
}

bool Mdc_Fs_Path_HasParentPath(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_ParentPath);
}

bool Mdc_Fs_Path_HasRelativePath(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_RelativePath);
}

bool Mdc_Fs_Path_HasRootDirectory(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_RootDirectory);
}

bool Mdc_Fs_Path_HasRootName(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_RootName);
}

bool Mdc_Fs_Path_HasRootPath(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_RootPath);
}

bool Mdc_Fs_Path_HasStem(const struct Mdc_Fs_Path* path) {
  return Mdc_Fs_Path_HasPathElement(path, &Mdc_Fs_Path_Stem);
}

struct Mdc_Fs_Path* Mdc_Fs_Path_MakePreferred(struct Mdc_Fs_Path* path) {
  size_t i;
  size_t path_len;

  Mdc_Fs_Path_ValueType* current_char;

  path_len = Mdc_BasicString_Size(&path->path_str_);

  for (i = 0; i < path_len; i += 1) {
    current_char = Mdc_BasicString_At(&path->path_str_, i);

    if (*current_char == Mdc_Fs_Path_kSlashSeparator) {
      *current_char = Mdc_Fs_Path_kPreferredSeparator;
    }
  }

  return path;
}

const struct Mdc_BasicString* Mdc_Fs_Path_Native(
    const struct Mdc_Fs_Path* path
) {
  return &path->path_str_;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_RemoveFilename(
    struct Mdc_Fs_Path* path
) {
  struct Mdc_Fs_Path* assign_path;
  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;

  struct Mdc_Fs_Path filename;
  struct Mdc_Fs_Path* init_filename;
  const struct Mdc_BasicString* filename_str;
  size_t filename_len;
  size_t i_filename;

  struct Mdc_Fs_Path filename_less_path;
  struct Mdc_Fs_Path* init_filename_less_path;

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  /* Get the filename length, which will determine the string top. */
  init_filename = Mdc_Fs_Path_Filename(&filename, path);
  if (init_filename != &filename) {
    goto return_bad;
  }

  filename_str = Mdc_Fs_Path_Native(&filename);
  filename_len = Mdc_BasicString_Length(filename_str);

  i_filename = path_len - filename_len;

  /* Assign the path top to the path. */
  init_filename_less_path = Mdc_Fs_Path_InitFromCWStrTop(
      &filename_less_path,
      path_cstr,
      i_filename
  );

  if (init_filename_less_path != &filename_less_path) {
    goto deinit_filename;
  }

  assign_path = Mdc_Fs_Path_AssignMove(path, &filename_less_path);
  if (assign_path != path) {
    goto deinit_filename_less_path;
  }

  Mdc_Fs_Path_Deinit(&filename_less_path);
  Mdc_Fs_Path_Deinit(&filename);

  return path;

deinit_filename_less_path:
  Mdc_Fs_Path_Deinit(&filename_less_path);

deinit_filename:
  Mdc_Fs_Path_Deinit(&filename);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_ReplaceExtension(
    struct Mdc_Fs_Path* path,
    const struct Mdc_Fs_Path* extension
) {
  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;
  size_t path_len;
  struct Mdc_Fs_Path* assign_path;

  struct Mdc_Fs_Path path_extension;
  struct Mdc_Fs_Path* init_path_extension;
  const struct Mdc_BasicString* path_extension_str;
  size_t path_extension_len;

  struct Mdc_Fs_Path new_extension_path;
  struct Mdc_Fs_Path* init_new_extension_path;
  struct Mdc_Fs_Path* concat_new_extension_path;

  /* Remove the extension from the path. */
  init_path_extension = Mdc_Fs_Path_Extension(
      &path_extension,
      path
  );

  if (init_path_extension != &path_extension) {
    goto return_bad;
  }

  path_extension_str = Mdc_Fs_Path_Native(&path_extension);
  path_extension_len = Mdc_BasicString_Length(path_extension_str);

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);
  path_len = Mdc_BasicString_Length(path_str);

  init_new_extension_path = Mdc_Fs_Path_InitFromCWStrTop(
      &new_extension_path,
      path_cstr,
      path_len - path_extension_len
  );

  if (init_new_extension_path != &new_extension_path) {
    goto deinit_path_extension;
  }

  /* Append the new extension onto the path. */
  concat_new_extension_path = Mdc_Fs_Path_ConcatPath(
      &new_extension_path,
      extension
  );

  if (concat_new_extension_path != &new_extension_path) {
    goto deinit_new_extension_path;
  }

  assign_path = Mdc_Fs_Path_AssignMove(path, &new_extension_path);
  if (assign_path != path) {
    goto deinit_new_extension_path;
  }

  Mdc_Fs_Path_Deinit(&new_extension_path);
  Mdc_Fs_Path_Deinit(&path_extension);

  return path;

deinit_new_extension_path:
  Mdc_Fs_Path_Deinit(&new_extension_path);

deinit_path_extension:
  Mdc_Fs_Path_Deinit(&path_extension);

return_bad:
  return NULL;
}

struct Mdc_Fs_Path* Mdc_Fs_Path_ReplaceFilename(
    struct Mdc_Fs_Path* path,
    const struct Mdc_Fs_Path* filename
) {
  struct Mdc_Fs_Path* remove_filename;
  struct Mdc_Fs_Path* append_filename;

  remove_filename = Mdc_Fs_Path_RemoveFilename(path);
  if (remove_filename != path) {
    goto return_bad;
  }

  append_filename = Mdc_Fs_Path_AppendPath(path, filename);
  if (append_filename != path) {
    goto return_bad;
  }

  return path;

return_bad:
  return NULL;
}

const struct Mdc_BasicString* Mdc_Fs_Path_StrType(
    struct Mdc_BasicString* str,
    const struct Mdc_Fs_Path* path
) {
  struct Mdc_BasicString* init_str;

  init_str = Mdc_BasicString_InitCopy(str, &path->path_str_);
  if (init_str != &path->path_str_) {
    goto return_bad;
  }

  return str;

return_bad:
  return NULL;
}

void Mdc_Fs_Path_Swap(
    struct Mdc_Fs_Path* path1,
    struct Mdc_Fs_Path* path2
) {
  struct Mdc_Fs_Path temp;

  temp = *path1;
  *path1 = *path2;
  *path2 = temp;
}
