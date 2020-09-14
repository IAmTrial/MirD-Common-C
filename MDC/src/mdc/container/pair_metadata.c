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

#include "../../../include/mdc/container/pair.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_Pair_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Pair_InitCopy(dest, src);
}

static void* Mdc_Pair_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Pair_InitMove(dest, src);
}

static void Mdc_Pair_DeinitAsVoid(void* pair) {
  Mdc_Pair_Deinit(pair);
}

/**
 * Object assignment functions
 */

static void* Mdc_Pair_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Pair_AssignCopy(dest, src);
}

static void* Mdc_Pair_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Pair_AssignMove(dest, src);
}

/**
 * Object comparison operators
 */

static bool Mdc_Pair_EqualAsVoid(const void* pair1, const void* pair2) {
  return Mdc_Pair_Equal(pair1, pair2);
}

static int Mdc_Pair_CompareAsVoid(const void* pair1, const void* pair2) {
  return Mdc_Pair_Compare(pair1, pair2);
}

/**
 * Etc. functions
 */

static void Mdc_Pair_SwapAsVoid(void* pair1, void* pair2) {
  return Mdc_Pair_Swap(pair1, pair2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_init_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_Pair_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mdc_Pair);

  metadata->functions.init_copy = &Mdc_Pair_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Pair_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Pair_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_Pair_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Pair_AssignMoveAsVoid;

  metadata->functions.equal = &Mdc_Pair_EqualAsVoid;
  metadata->functions.compare = &Mdc_Pair_CompareAsVoid;

  metadata->functions.swap = &Mdc_Pair_SwapAsVoid;

  return metadata;
}

static void Mdc_Pair_InitGlobalObjectMetadata(void) {
  Mdc_Pair_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Pair_GetObjectMetadataTemplate(void) {
  call_once(
      &global_metadata_init_flag,
      &Mdc_Pair_InitGlobalObjectMetadata
  );

  return &global_metadata;
}

struct Mdc_PairMetadata* Mdc_PairMetadata_Init(
    struct Mdc_PairMetadata* metadata,
    const struct Mdc_ObjectMetadata* first_metadata,
    const struct Mdc_ObjectMetadata* second_metadata
) {
  metadata->first_metadata = first_metadata;
  metadata->second_metadata = second_metadata;

  return metadata;
}
