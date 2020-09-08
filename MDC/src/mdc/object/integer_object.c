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

#include "../../../include/mdc/object/integer_object.h"

/**
 * Static
 */

#define MDC_INTEGER_UNINIT { 0 }

static const struct Mdc_Integer Mdc_Integer_kUninit =
    MDC_INTEGER_UNINIT;

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

struct Mdc_Integer* Mdc_Integer_Init(
    struct Mdc_Integer* integer
) {
  return integer;
}

void Mdc_Integer_Deinit(struct Mdc_Integer* integer) {
  *integer = Mdc_Integer_kUninit;
}

/**
 * Assignment functions
 */

struct Mdc_Integer* Mdc_Integer_AssignDefault(
    struct Mdc_Integer* integer
) {
  integer->value_ = 0;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_AssignFromValue(
    struct Mdc_Integer* integer,
    int value
) {
  integer->value_ = value;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_AssignCopy(
    struct Mdc_Integer* dest,
    const struct Mdc_Integer* src
) {
  dest->value_ = src->value_;

  return dest;
}

struct Mdc_Integer* Mdc_Integer_AssignMove(
    struct Mdc_Integer* dest,
    struct Mdc_Integer* src
) {
  return Mdc_Integer_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

struct Mdc_Integer* Mdc_Integer_PreIncrement(
    struct Mdc_Integer* integer
) {
  integer->value_ += 1;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_PreDecrement(
    struct Mdc_Integer* integer
) {
  integer->value_ -= 1;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_PostIncrement(
    struct Mdc_Integer* integer_out,
    struct Mdc_Integer* integer_in
) {
  Mdc_Integer_AssignCopy(integer_out, integer_in);
  integer_in->value_ += 1;

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_PostDecrement(
    struct Mdc_Integer* integer_out,
    struct Mdc_Integer* integer_in
) {
  Mdc_Integer_AssignCopy(integer_out, integer_in);
  integer_in->value_ -= 1;

  return integer_out;
}

/**
 * Arithmetic operators
 */

struct Mdc_Integer* Mdc_Integer_Add(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ + integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_Subtract(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ - integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_Multiply(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ * integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_Divide(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ / integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_Modulo(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ % integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseNot(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      ~(integer_in->value_)
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseAnd(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ & integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseOr(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ | integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseXor(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ ^ integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseLeftShift(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ << integer_in2->value_
  );

  return integer_out;
}

struct Mdc_Integer* Mdc_Integer_BitwiseRightShift(
    struct Mdc_Integer* integer_out,
    const struct Mdc_Integer* integer_in1,
    const struct Mdc_Integer* integer_in2
) {
  Mdc_Integer_AssignFromValue(
      integer_out,
      integer_in1->value_ >> integer_in2->value_
  );

  return integer_out;
}

/**
 * Comparison operators
 */

bool Mdc_Integer_Equal(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return integer1->value_ == integer2->value_;
}

bool Mdc_Integer_EqualValue(
    const struct Mdc_Integer* integer,
    int value
) {
  return integer->value_ == value;
}

int Mdc_Integer_Compare(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return integer1->value_ - integer2->value_;
}

int Mdc_Integer_CompareValue(
    const struct Mdc_Integer* integer,
    int value
) {
  return integer->value_ - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Integer_Hash(const struct Mdc_Integer* integer) {
  return integer->value_ % (size_t) -1;
}

void Mdc_Integer_Swap(
    struct Mdc_Integer* integer1,
    struct Mdc_Integer* integer2
) {
  struct Mdc_Integer temp;

  temp = *integer1;
  *integer1 = *integer2;
  *integer2 = temp;
}

int Mdc_Integer_GetValue(const struct Mdc_Integer* integer) {
  return integer->value_;
}

void Mdc_Integer_SetValue(struct Mdc_Integer* integer, int value) {
  integer->value_ = value;
}
