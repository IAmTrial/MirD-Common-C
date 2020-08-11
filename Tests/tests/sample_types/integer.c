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

#include "integer.h"

struct Integer* Mdc_Integer_InitCopy(
    struct Integer* dest,
    const struct Integer* src
) {
  dest->value = src->value;

  return dest;
}

struct Integer* Mdc_Integer_InitMove(
    struct Integer* dest,
    struct Integer* src
) {
  dest->value = src->value;

  return dest;
}

void Mdc_Integer_Deinit(struct Integer* integer) {
}

int Mdc_Integer_Compare(
    const struct Integer* integer1,
    const struct Integer* integer2
) {
  return integer1->value - integer2->value;
}
