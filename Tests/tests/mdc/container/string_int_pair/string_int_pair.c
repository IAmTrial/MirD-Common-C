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

#include "string_int_pair.h"

#include "../../../sample_types/char_cstring.h"
#include "../../../sample_types/integer.h"

/**
 * Static functions
 */

static void* Mdc_CharCString_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_CharCString_InitCopy(dest, src);
}

static void* Mdc_Integer_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Integer_InitCopy(dest, src);
}

static void* Mdc_CharCString_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_CharCString_InitMove(dest, src);
}

static void* Mdc_Integer_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Integer_InitMove(dest, src);
}

static void Mdc_CharCString_DeinitAsVoid(void* str) {
  Mdc_CharCString_Deinit(str);
}

static void Mdc_Integer_DeinitAsVoid(void* integer) {
  Mdc_Integer_Deinit(integer);
}

static int Mdc_CharCString_CompareAsVoid(const void* str1, const void* str2) {
  return Mdc_CharCString_Compare(str1, str2);
}

static int Mdc_Integer_CompareAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_Integer_Compare(integer1, integer2);
}

static struct Mdc_PairFirstFunctions* Mdc_PairCharCStringIntFirstFunctions_Init(
    struct Mdc_PairFirstFunctions* first_functions
) {
  first_functions->init_copy = &Mdc_CharCString_InitCopyAsVoid;
  first_functions->init_move = &Mdc_CharCString_InitMoveAsVoid;
  first_functions->deinit = &Mdc_CharCString_DeinitAsVoid;
  first_functions->compare = &Mdc_CharCString_CompareAsVoid;

  return first_functions;
}

static struct Mdc_PairSecondFunctions* Mdc_PairCharCStringIntSecondFunctions_Init(
    struct Mdc_PairSecondFunctions* second_functions
) {
  second_functions->init_copy = &Mdc_Integer_InitCopyAsVoid;
  second_functions->init_move = &Mdc_Integer_InitMoveAsVoid;
  second_functions->deinit = &Mdc_Integer_DeinitAsVoid;
  second_functions->compare = &Mdc_Integer_CompareAsVoid;

  return second_functions;
}

/**
 * External functions
 */

struct Mdc_PairMetadata* Mdc_PairCharCStringIntMetadata_Init(
    struct Mdc_PairMetadata* metadata
) {
  metadata->size.first_size = sizeof(struct CharCString);
  metadata->size.second_size = sizeof(struct Integer);

  Mdc_PairCharCStringIntFirstFunctions_Init(
      &metadata->functions.first_functions
  );
  Mdc_PairCharCStringIntSecondFunctions_Init(
      &metadata->functions.second_functions
  );

  return metadata;
}
