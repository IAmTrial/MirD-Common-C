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

#include "../../../include/mdc/object/short_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

#define MDC_SHORT_UNINIT { 0 }

static const struct Mdc_Short Mdc_Short_kUninit = MDC_SHORT_UNINIT;

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

struct Mdc_Short* Mdc_Short_Init(struct Mdc_Short* shrt) {
  return shrt;
}

void Mdc_Short_Deinit(struct Mdc_Short* shrt) {
  *shrt = Mdc_Short_kUninit;
}

/**
 * Assignment functions
 */

struct Mdc_Short* Mdc_Short_AssignDefault(
    struct Mdc_Short* shrt
) {
  shrt->value_ = 0;

  return shrt;
}

struct Mdc_Short* Mdc_Short_AssignFromValue(
    struct Mdc_Short* shrt,
    short value
) {
  shrt->value_ = value;

  return shrt;
}

struct Mdc_Short* Mdc_Short_AssignCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
) {
  dest->value_ = src->value_;

  return dest;
}

struct Mdc_Short* Mdc_Short_AssignMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
) {
  return Mdc_Short_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

struct Mdc_Short* Mdc_Short_PreIncrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ += 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PreDecrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ -= 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PostIncrement(
    struct Mdc_Short* short_out,
    struct Mdc_Short* short_in
) {
  Mdc_Short_AssignCopy(short_out, short_in);
  short_in->value_ += 1;

  return short_out;
}

struct Mdc_Short* Mdc_Short_PostDecrement(
    struct Mdc_Short* short_out,
    struct Mdc_Short* short_in
) {
  Mdc_Short_AssignCopy(short_out, short_in);
  short_in->value_ -= 1;

  return short_out;
}

/**
 * Arithmetic operators
 */

struct Mdc_Short* Mdc_Short_Add(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ + short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Subtract(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ - short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Multiply(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ * short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Divide(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ / short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Modulo(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ % short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseNot(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in
) {
  Mdc_Short_AssignFromValue(
      short_out,
      ~(short_in->value_)
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseAnd(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ & short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseOr(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ | short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseXor(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ ^ short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseLeftShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ << short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseRightShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ >> short_in2->value_
  );

  return short_out;
}

/**
 * Comparison operators
 */

bool Mdc_Short_Equal(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return short1->value_ == short2->value_;
}

bool Mdc_Short_EqualValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return shrt->value_ == value;
}

int Mdc_Short_Compare(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return short1->value_ - short2->value_;
}

int Mdc_Short_CompareValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return shrt->value_ - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Short_Hash(const struct Mdc_Short* shrt) {
  return shrt->value_ % (size_t) -1;
}

void Mdc_Short_Swap(
    struct Mdc_Short* short1,
    struct Mdc_Short* short2
) {
  struct Mdc_Short temp;

  temp = *short1;
  *short1 = *short2;
  *short2 = temp;
}

short Mdc_Short_GetValue(const struct Mdc_Short* shrt) {
  return shrt->value_;
}

void Mdc_Short_SetValue(struct Mdc_Short* shrt, short value) {
  shrt->value_ = value;
}
