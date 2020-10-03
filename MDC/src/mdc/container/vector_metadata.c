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

#include "../../../include/mdc/container/vector.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_Vector_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Vector_InitCopy(dest, src);
}

static void* Mdc_Vector_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Vector_InitMove(dest, src);
}

static void Mdc_Vector_DeinitAsVoid(void* vector) {
  Mdc_Vector_Deinit(vector);
}

/**
 * Object assignment functions
 */

static void* Mdc_Vector_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Vector_AssignCopy(dest, src);
}

static void* Mdc_Vector_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Vector_AssignMove(dest, src);
}

/**
 * Object comparison operators
 */

static bool Mdc_Vector_EqualAsVoid(const void* vector1, const void* vector2) {
  return Mdc_Vector_Equal(vector1, vector2);
}

static int Mdc_Vector_CompareAsVoid(const void* vector1, const void* vector2) {
  return Mdc_Vector_Compare(vector1, vector2);
}

/**
 * Etc. functions
 */

static void Mdc_Vector_SwapAsVoid(void* vector1, void* vector2) {
  Mdc_Vector_Swap(vector1, vector2);
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
  metadata->size = sizeof(struct Mdc_Vector);

  metadata->functions.init_copy = &Mdc_Vector_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Vector_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Vector_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_Vector_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Vector_AssignMoveAsVoid;

  metadata->functions.equal = &Mdc_Vector_EqualAsVoid;
  metadata->functions.compare = &Mdc_Vector_CompareAsVoid;

  metadata->functions.swap = &Mdc_Vector_SwapAsVoid;

  return metadata;
}

static void Mdc_Vector_InitGlobalObjectMetadata(void) {
  Mdc_Vector_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Vector_GetObjectMetadataTemplate(void) {
  call_once(
      &global_metadata_init_flag,
      &Mdc_Vector_InitGlobalObjectMetadata
  );

  return &global_metadata;
}

struct Mdc_VectorMetadata* Mdc_VectorMetadata_Init(
    struct Mdc_VectorMetadata* vector_metadata,
    const struct Mdc_ObjectMetadata* element_metadata
) {
  vector_metadata->element_metadata = element_metadata;

  return vector_metadata;
}
