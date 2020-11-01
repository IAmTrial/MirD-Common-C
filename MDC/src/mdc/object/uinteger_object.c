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

#include "../../../include/mdc/object/uinteger_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

unsigned int* Mdc_UInteger_InitDefault(unsigned int* integer) {
  return Mdc_UInteger_InitFromValue(integer, 0);
}

unsigned int* Mdc_UInteger_InitFromValue(
    unsigned int* integer,
    unsigned int value
) {
  *integer = value;

  return integer;
}

unsigned int* Mdc_UInteger_InitCopy(
    unsigned int* dest,
    const unsigned int* src
) {
  *dest = *src;

  return dest;
}

unsigned int* Mdc_UInteger_InitMove(
    unsigned int* dest,
    unsigned int* src
) {
  return Mdc_UInteger_InitCopy(dest, src);
}

void Mdc_UInteger_Deinit(unsigned int* integer) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

unsigned int* Mdc_UInteger_AssignCopy(
    unsigned int* dest,
    const unsigned int* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

unsigned int* Mdc_UInteger_AssignMove(
    unsigned int* dest,
    unsigned int* src
) {
  return Mdc_UInteger_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

unsigned int* Mdc_UInteger_PreIncrement(
    unsigned int* integer
) {
  *integer += 1;

  return integer;
}

unsigned int* Mdc_UInteger_PreDecrement(
    unsigned int* integer
) {
  *integer -= 1;

  return integer;
}

unsigned int* Mdc_UInteger_PostIncrement(
    unsigned int* out,
    unsigned int* in
) {
  *out = *in;
  *in += 1;

  return out;
}

unsigned int* Mdc_UInteger_PostDecrement(
    unsigned int* out,
    unsigned int* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

unsigned int* Mdc_UInteger_Add(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 + *op2;

  return out;
}

unsigned int* Mdc_UInteger_Subtract(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 - *op2;

  return out;
}

unsigned int* Mdc_UInteger_Multiply(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 * *op2;

  return out;
}

unsigned int* Mdc_UInteger_Divide(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 / *op2;

  return out;
}

unsigned int* Mdc_UInteger_Modulo(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 % *op2;

  return out;
}

unsigned int* Mdc_UInteger_BitwiseNot(
    unsigned int* out,
    const unsigned int* in
) {
  *out = ~(*in);

  return out;
}

unsigned int* Mdc_UInteger_BitwiseAnd(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 & *op2;

  return out;
}

unsigned int* Mdc_UInteger_BitwiseOr(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 | *op2;

  return out;
}

unsigned int* Mdc_UInteger_BitwiseXor(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

unsigned int* Mdc_UInteger_BitwiseLeftShift(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 << *op2;

  return out;
}

unsigned int* Mdc_UInteger_BitwiseRightShift(
    unsigned int* out,
    const unsigned int* op1,
    const unsigned int* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_UInteger_Equal(
    const unsigned int* integer1,
    const unsigned int* integer2
) {
  return Mdc_UInteger_EqualValue(*integer1, *integer2);
}

bool Mdc_UInteger_EqualValue(
    unsigned int value1,
    unsigned int value2
) {
  return value1 == value2;
}

int Mdc_UInteger_Compare(
    const unsigned int* integer1,
    const unsigned int* integer2
) {
  return Mdc_UInteger_CompareValue(*integer1, *integer2);
}

int Mdc_UInteger_CompareValue(
    unsigned int value1,
    unsigned int value2
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

size_t Mdc_UInteger_Hash(const unsigned int* integer) {
  return *integer % (size_t) -1;
}

void Mdc_UInteger_Swap(
    unsigned int* integer1,
    unsigned int* integer2
) {
  unsigned int temp;

  temp = *integer1;
  *integer1 = *integer2;
  *integer2 = temp;
}
