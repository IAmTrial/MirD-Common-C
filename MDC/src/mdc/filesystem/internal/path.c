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

static bool Mdc_Fs_Path_HasPathElement(
    const struct Mdc_Fs_Path* path,
    bool (*get_element_func)(struct Mdc_Fs_Path*, const struct Mdc_Fs_Path*)
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
  struct Mdc_BasicString* dest_path_str;
  const Mdc_Fs_Path_ValueType* dest_path_cstr;
  size_t dest_path_len;

  const struct Mdc_BasicString* path_str;
  const Mdc_Fs_Path_ValueType* path_cstr;

  struct Mdc_BasicString* append_str;
  struct Mdc_Fs_Path* concat_path;

  dest_path_str = &dest->path_str_;
  dest_path_cstr = Mdc_BasicString_DataConst(dest_path_str);
  dest_path_len = Mdc_BasicString_Length(dest_path_str);

  path_str = Mdc_Fs_Path_Native(path);
  path_cstr = Mdc_BasicString_DataConst(path_str);

  if (!Mdc_Path_IsPathSeparator(dest_path_cstr[dest_path_len - 1])
      || !Mdc_Path_IsPathSeparator(path_cstr[0])) {
    append_str = Mdc_BasicString_AppendChar(
        dest_path_str,
        1,
        Mdc_Fs_Path_kPreferredSeparator
    );

    if (append_str != &dest->path_str_) {
      goto return_bad;
    }
  }

  concat_path = Mdc_Fs_Path_ConcatPath(dest, path);
  if (concat_path != dest) {
    goto return_bad;
  }

  return dest;

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
