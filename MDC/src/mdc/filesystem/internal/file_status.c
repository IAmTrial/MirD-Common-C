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

#include "../../../../include/mdc/filesystem/filesystem.h"

#include <stddef.h>

#define MDC_FS_FILE_STATUS_UNINIT { 0 }

static const struct Mdc_Fs_FileStatus Mdc_Fs_FileStatus_kUninit =
    MDC_FS_FILE_STATUS_UNINIT;

/**
 * Initialization/deinitialization
 */

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitNone(
    struct Mdc_Fs_FileStatus* file_status
) {
  return Mdc_Fs_FileStatus_InitFromType(file_status, Mdc_Fs_FileType_kNone);
}

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitFromType(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type
) {
  return Mdc_Fs_FileStatus_InitFromTypeAndPerms(
      file_status,
      type,
      Mdc_Fs_Perms_kUnknown
  );
}

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitFromTypeAndPerms(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type,
    enum Mdc_Fs_Perms permissions
) {
  file_status->type_ = type;
  file_status->permissions_ = permissions;

  return file_status;
}

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitCopy(
    struct Mdc_Fs_FileStatus* dest,
    const struct Mdc_Fs_FileStatus* src
) {
  *dest = *src;

  return dest;
}

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitMove(
    struct Mdc_Fs_FileStatus* dest,
    struct Mdc_Fs_FileStatus* src
) {
  return Mdc_Fs_FileStatus_InitCopy(dest, src);
}

void Mdc_Fs_FileStatus_Deinit(
    struct Mdc_Fs_FileStatus* file_status
) {
  *file_status = Mdc_Fs_FileStatus_kUninit;
}

/**
 * Assignment
 */

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_AssignCopy(
    struct Mdc_Fs_FileStatus* dest,
    const struct Mdc_Fs_FileStatus* src
) {
  struct Mdc_Fs_FileStatus temp_file_status;
  struct Mdc_Fs_FileStatus* init_temp_file_status;

  struct Mdc_Fs_FileStatus* assign_dest;

  init_temp_file_status = Mdc_Fs_FileStatus_InitCopy(
      &temp_file_status,
      src
  );

  if (init_temp_file_status != &temp_file_status) {
    goto return_bad;
  }

  assign_dest = Mdc_Fs_FileStatus_AssignMove(
      dest,
      &temp_file_status
  );

  if (assign_dest != dest) {
    goto deinit_temp_file_status;
  }

  Mdc_Fs_FileStatus_Deinit(&temp_file_status);

  return dest;

deinit_temp_file_status:
  Mdc_Fs_FileStatus_Deinit(&temp_file_status);

return_bad:
  return NULL;
}

struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_AssignMove(
    struct Mdc_Fs_FileStatus* dest,
    struct Mdc_Fs_FileStatus* src
) {
  *dest = *src;

  return dest;
}

/**
 * Comparison functions
 */

bool Mdc_Fs_FileStatus_Equal(
    const struct Mdc_Fs_FileStatus* file_status1,
    const struct Mdc_Fs_FileStatus* file_status2
) {
  return file_status1->type_ == file_status2->type_
      && file_status1->permissions_ == file_status2->permissions_;
}

/**
 * Etc. functions
 */

enum Mdc_Fs_FileType Mdc_Fs_FileStatus_GetType(
    const struct Mdc_Fs_FileStatus* file_status
) {
  return file_status->type_;
}

void Mdc_Fs_FileStatus_SetType(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type
) {
  file_status->type_ = type;
}

enum Mdc_Fs_Perms Mdc_Fs_FileStatus_GetPermissions(
    const struct Mdc_Fs_FileStatus* file_status
) {
  return file_status->permissions_;
}

void Mdc_Fs_FileStatus_SetPermissions(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_Perms permissions
) {
  file_status->permissions_ = permissions;
}
