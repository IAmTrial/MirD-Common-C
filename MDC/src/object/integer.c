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

#include "../../include/mdc/object/integer.h"

struct Mdc_Integer* Mdc_Integer_InitFromValue(
    struct Mdc_Integer* integer,
    int value
) {
  integer->value_ = value;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_InitCopy(
    struct Mdc_Integer* dest,
    const struct Mdc_Integer* src
) {
  dest->value_ = src->value_;

  return dest;
}

struct Mdc_Integer* Mdc_Integer_InitMove(
    struct Mdc_Integer* dest,
    struct Mdc_Integer* src
) {
  return Mdc_Integer_InitCopy(dest, src);
}

void Mdc_Integer_Deinit(struct Mdc_Integer* integer) {
  /* Intentionally left empty. */
}

int Mdc_Integer_Compare(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return integer1->value_ - integer2->value_;
}

bool Mdc_Integer_Equal(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return integer1->value_ == integer2->value_;
}

int Mdc_Integer_GetValue(const struct Mdc_Integer* integer) {
  return integer->value_;
}

void Mdc_Integer_SetValue(struct Mdc_Integer* integer, int value) {
  integer->value_ = value;
}
