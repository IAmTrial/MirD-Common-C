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

#include "../../../include/mdc/string/basic_string.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Initialization/deinitialization
 */

static void Mdc_BasicString_DeinitAsVoid(void* str) {
  return Mdc_BasicString_Deinit(str);
}

/**
 * Assignment functions
 */

static void* Mdc_BasicString_AssignEmptyAsVoid(void* str) {
  return Mdc_BasicString_AssignEmpty(str);
}

static void* Mdc_BasicString_AssignConcatStrCopyWithStrCopyAsVoid(
    void* dest,
    const void* src1,
    const void* src2
) {
  return Mdc_BasicString_ConcatStrCopyWithStrCopy(dest, src1, src2);
}

static void* Mdc_BasicString_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_BasicString_AssignCopy(dest, src);
}

static void* Mdc_BasicString_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_BasicString_AssignMove(dest, src);
}

/**
 * Comparison operators
 */

static bool Mdc_BasicString_EqualAsVoid(
    const void* str1,
    const void* str2
) {
  return Mdc_BasicString_EqualStr(str1, str2);
}

static int Mdc_BasicString_CompareAsVoid(
    const void* str1,
    const void* str2
) {
  return Mdc_BasicString_CompareStr(str1, str2);
}

/**
 * Etc. functions
 */

static void Mdc_BasicString_SwapAsVoid(
    void* str1,
    void* str2
) {
  Mdc_BasicString_Swap(str1, str2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_BasicString_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mdc_BasicString);

  /*
  * metadata->functions.init needs to be filled out by a
  * specialization of BasicString.
  */
  metadata->functions.deinit = &Mdc_BasicString_DeinitAsVoid;

  metadata->functions.assign_default = &Mdc_BasicString_AssignEmptyAsVoid;
  metadata->functions.assign_copy = &Mdc_BasicString_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_BasicString_AssignMoveAsVoid;

  metadata->functions.add =
      &Mdc_BasicString_AssignConcatStrCopyWithStrCopyAsVoid;

  metadata->functions.equal = &Mdc_BasicString_EqualAsVoid;
  metadata->functions.compare = &Mdc_BasicString_CompareAsVoid;

  /* TODO (Mir Drualga): Implement a Hash function. */
  /* metadata->functions.hash = &Mdc_BasicString_HashAsVoid; */
  metadata->functions.swap = &Mdc_BasicString_SwapAsVoid;

  return metadata;
}

static void Mdc_BasicString_InitGlobalObjectMetadata(void) {
  Mdc_BasicString_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata*
Mdc_BasicString_GetObjectMetadataTemplate(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_BasicString_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
