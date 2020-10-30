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

#include "../../../../include/mdc/string/basic_string/u8string.h"

#include "../../../../include/mdc/std/threads.h"

/**
 * Initialization/deinitialization
 */

static void* Mdc_U8String_InitEmptyAsVoid(void* str) {
  return Mdc_U8String_InitEmpty(str);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata* Mdc_U8String_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  *metadata = *Mdc_BasicString_GetObjectMetadataTemplate();

  metadata->functions.init_default = &Mdc_U8String_InitEmptyAsVoid;

  return metadata;
}

static struct Mdc_ObjectMetadata global_metadata;
static once_flag global_metadata_init_flag = ONCE_FLAG_INIT;

static void Mdc_U8String_InitGlobalObjectMetadata(void) {
  Mdc_U8String_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_U8String_GetObjectMetadata(void) {
  call_once(
      &global_metadata_init_flag,
      &Mdc_U8String_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
