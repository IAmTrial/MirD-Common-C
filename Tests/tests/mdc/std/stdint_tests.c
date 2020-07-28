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

#include "stdint_tests.h"

#include <assert.h>

#include <mdc/std/stdint.h>

void Mdc_Std_AssertInt8Size(void) {
  assert(sizeof(int8_t) == 1);
}

void Mdc_Std_AssertInt16Size(void) {
  assert(sizeof(int16_t) == 2);
}

void Mdc_Std_AssertInt32Size(void) {
  assert(sizeof(int32_t) == 4);
}

void Mdc_Std_AssertUInt8Size(void) {
  assert(sizeof(uint8_t) == 1);
}

void Mdc_Std_AssertUInt16Size(void) {
  assert(sizeof(uint16_t) == 2);
}

void Mdc_Std_AssertUInt32Size(void) {
  assert(sizeof(uint32_t) == 4);
}

void Mdc_Std_AssertIntptrSize(void) {
  assert(sizeof(intptr_t) == sizeof(void*));
}

void Mdc_Std_AssertUintptrSize(void) {
  assert(sizeof(uintptr_t) == sizeof(void*));
}
