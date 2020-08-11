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

static void* Mdc_String_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_CharCString_InitCopy(dest, src);
}

static int* Mdc_Int_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Int_InitCopy(dest, src);
}

static void* Mdc_String_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_CharCString_InitMove(dest, src);
}

static int* Mdc_Int_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Int_InitMove(dest, src);
}

static void Mdc_String_DeinitAsVoid(void* str) {
  Mdc_CharCString_Deinit(str);
}

static void Mdc_Int_DeinitAsVoid(void* integer) {
  Mdc_Int_Deinit(integer);
}

static int Mdc_String_CompareAsVoid(const void* str1, const void* str2) {
  return Mdc_CharCString_Compare(str1, str2);
}

static int Mdc_Int_CompareAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_Int_Compare(integer1, integer2);
}

static struct Mdc_PairFirstFunctions* Mdc_PairStringIntFirstFunctions_Init(
    struct Mdc_PairFirstFunctions* first_functions
) {
  first_functions->init_copy = &Mdc_String_InitCopyAsVoid;
  first_functions->init_move = &Mdc_String_InitMoveAsVoid;
  first_functions->deinit = &Mdc_String_DeinitAsVoid;
  first_functions->compare = &Mdc_String_CompareAsVoid;

  return first_functions;
}

static struct Mdc_PairSecondFunctions* Mdc_PairStringIntSecondFunctions_Init(
    struct Mdc_PairSecondFunctions* second_functions
) {
  second_functions->init_copy = &Mdc_Int_InitCopyAsVoid;
  second_functions->init_move = &Mdc_Int_InitMoveAsVoid;
  second_functions->deinit = &Mdc_Int_DeinitAsVoid;
  second_functions->compare = &Mdc_Int_CompareAsVoid;

  return second_functions;
}

/**
 * External functions
 */

struct Mdc_PairMetadata* Mdc_PairStringIntMetadata_Init(
    struct Mdc_PairMetadata* metadata
) {
  metadata->size.first_size = sizeof(char*);
  metadata->size.second_size = sizeof(int);

  Mdc_PairStringIntFirstFunctions_Init(
      &metadata->functions.first_functions
  );
  Mdc_PairStringIntSecondFunctions_Init(
      &metadata->functions.second_functions
  );

  return metadata;
}
