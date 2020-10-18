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

#include "../../../../include/mdc/std/stdbool.h"
#include "../../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_Path_InitEmptyAsVoid(void* dest) {
  return Mdc_Fs_Path_InitEmpty(dest);
}

static void* Mdc_Path_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Fs_Path_InitCopy(dest, src);
}

static void* Mdc_Path_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Fs_Path_InitMove(dest, src);
}

static void Mdc_Path_DeinitAsVoid(void* path) {
  Mdc_Fs_Path_Deinit(path);
}

/**
 * Object assignment functions
 */

static void* Mdc_Path_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Fs_Path_AssignCopy(dest, src);
}

static void* Mdc_Path_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Fs_Path_AssignMove(dest, src);
}

/**
 * Object comparison operators
 */

static bool Mdc_Path_EqualAsVoid(const void* path1, const void* path2) {
  return Mdc_Fs_Path_Equal(path1, path2);
}

static int Mdc_Path_CompareAsVoid(const void* path1, const void* path2) {
  return Mdc_Fs_Path_Compare(path1, path2);
}

/**
 * Etc. functions
 */

static void Mdc_Path_SwapAsVoid(void* path1, void* path2) {
  Mdc_Fs_Path_Swap(path1, path2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_init_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_Path_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mdc_Fs_Path);

  metadata->functions.init_copy = &Mdc_Path_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Path_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Path_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_Path_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Path_AssignMoveAsVoid;

  metadata->functions.equal = &Mdc_Path_EqualAsVoid;
  metadata->functions.compare = &Mdc_Path_CompareAsVoid;

  metadata->functions.swap = &Mdc_Path_SwapAsVoid;

  return metadata;
}

static void Mdc_Path_InitGlobalObjectMetadata(void) {
  Mdc_Path_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Fs_Path_GetObjectMetadata(void) {
  call_once(
      &global_metadata_init_flag,
      &Mdc_Path_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
