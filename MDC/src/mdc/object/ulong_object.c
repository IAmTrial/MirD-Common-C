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

#include "../../../include/mdc/object/ulong_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

unsigned long* Mdc_ULong_InitDefault(unsigned long* lng) {
  return Mdc_ULong_InitFromValue(lng, 0);
}

unsigned long* Mdc_ULong_InitFromValue(
    unsigned long* lng,
    unsigned long value
) {
  *lng = value;

  return lng;
}

unsigned long* Mdc_ULong_InitCopy(
    unsigned long* dest,
    const unsigned long* src
) {
  *dest = *src;

  return dest;
}

unsigned long* Mdc_ULong_InitMove(
    unsigned long* dest,
    unsigned long* src
) {
  return Mdc_ULong_InitCopy(dest, src);
}

void Mdc_ULong_Deinit(unsigned long* lng) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

unsigned long* Mdc_ULong_AssignCopy(
    unsigned long* dest,
    const unsigned long* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

unsigned long* Mdc_ULong_AssignMove(
    unsigned long* dest,
    unsigned long* src
) {
  return Mdc_ULong_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

unsigned long* Mdc_ULong_PreIncrement(
    unsigned long* lng
) {
  *lng += 1;

  return lng;
}

unsigned long* Mdc_ULong_PreDecrement(
    unsigned long* lng
) {
  *lng -= 1;

  return lng;
}

unsigned long* Mdc_ULong_PostIncrement(
    unsigned long* out,
    unsigned long* in
) {
  *out = *in;
  *in += 1;

  return out;
}

unsigned long* Mdc_ULong_PostDecrement(
    unsigned long* out,
    unsigned long* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

unsigned long* Mdc_ULong_Add(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 + *op2;

  return out;
}

unsigned long* Mdc_ULong_Subtract(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 - *op2;

  return out;
}

unsigned long* Mdc_ULong_Multiply(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 * *op2;

  return out;
}

unsigned long* Mdc_ULong_Divide(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 / *op2;

  return out;
}

unsigned long* Mdc_ULong_Modulo(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 % *op2;

  return out;
}

unsigned long* Mdc_ULong_BitwiseNot(
    unsigned long* out,
    const unsigned long* in
) {
  *out = ~(*in);

  return out;
}

unsigned long* Mdc_ULong_BitwiseAnd(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 & *op2;

  return out;
}

unsigned long* Mdc_ULong_BitwiseOr(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 | *op2;

  return out;
}

unsigned long* Mdc_ULong_BitwiseXor(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

unsigned long* Mdc_ULong_BitwiseLeftShift(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 << *op2;

  return out;
}

unsigned long* Mdc_ULong_BitwiseRightShift(
    unsigned long* out,
    const unsigned long* op1,
    const unsigned long* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_ULong_Equal(
    const unsigned long* long1,
    const unsigned long* long2
) {
  return Mdc_ULong_EqualValue(*long1, *long2);
}

bool Mdc_ULong_EqualValue(
    unsigned long value1,
    unsigned long value2
) {
  return value1 == value2;
}

int Mdc_ULong_Compare(
    const unsigned long* long1,
    const unsigned long* long2
) {
  return Mdc_ULong_CompareValue(*long1, *long2);
}

int Mdc_ULong_CompareValue(
    unsigned long value1,
    unsigned long value2
) {
  if (value1 < value2) {
    return -1;
  } else if (value1 > value2) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * Etc. functions
 */

size_t Mdc_ULong_Hash(const unsigned long* lng) {
  return *lng % (size_t) -1;
}

void Mdc_ULong_Swap(
    unsigned long* long1,
    unsigned long* long2
) {
  unsigned long temp;

  temp = *long1;
  *long1 = *long2;
  *long2 = temp;
}
