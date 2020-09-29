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

#include "map_string_int.h"

#include <mdc/std/threads.h>
#include "../pair_string_int/pair_string_int.h"

/**
 * Static functions
 */

static struct Mdc_MapMetadata* Mdc_MapStringInt_InitMapMetadata(
    struct Mdc_MapMetadata* map_metadata
) {
  map_metadata->pair_metadata = Mdc_PairStringInt_GetGlobalPairMetadata();

  return map_metadata;
}

static struct Mdc_MapMetadata global_map_metadata;
static once_flag global_map_metadata_init_flag = ONCE_FLAG_INIT;

static void Mdc_MapStringInt_InitGlobalMapMetadata(void) {
  Mdc_MapStringInt_InitMapMetadata(&global_map_metadata);
}

/**
 * External functions
 */

const struct Mdc_MapMetadata* Mdc_MapStringInt_GetGlobalMapMetadata(void) {
  call_once(
      &global_map_metadata_init_flag,
      &Mdc_MapStringInt_InitGlobalMapMetadata
  );

  return &global_map_metadata;
}
