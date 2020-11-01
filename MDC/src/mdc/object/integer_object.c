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
 * External
 */

/**
 * Initialization/deinitialization
 */

int* Mdc_Integer_InitDefault(int* integer) {
  return Mdc_Integer_InitFromValue(integer, 0);
}

int* Mdc_Integer_InitFromValue(
    int* integer,
    int value
) {
  *integer = value;

  return integer;
}

int* Mdc_Integer_InitCopy(
    int* dest,
    const int* src
) {
  *dest = *src;

  return dest;
}

int* Mdc_Integer_InitMove(
    int* dest,
    int* src
) {
  return Mdc_Integer_InitCopy(dest, src);
}

void Mdc_Integer_Deinit(int* integer) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

int* Mdc_Integer_AssignCopy(
    int* dest,
    const int* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

int* Mdc_Integer_AssignMove(
    int* dest,
    int* src
) {
  return Mdc_Integer_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

int* Mdc_Integer_PreIncrement(
    int* integer
) {
  *integer += 1;

  return integer;
}

int* Mdc_Integer_PreDecrement(
    int* integer
) {
  *integer -= 1;

  return integer;
}

int* Mdc_Integer_PostIncrement(
    int* out,
    int* in
) {
  *out = *in;
  *in += 1;

  return out;
}

int* Mdc_Integer_PostDecrement(
    int* out,
    int* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

int* Mdc_Integer_Add(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 + *op2;

  return out;
}

int* Mdc_Integer_Subtract(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 - *op2;

  return out;
}

int* Mdc_Integer_Multiply(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 * *op2;

  return out;
}

int* Mdc_Integer_Divide(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 / *op2;

  return out;
}

int* Mdc_Integer_Modulo(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 % *op2;

  return out;
}

int* Mdc_Integer_BitwiseNot(
    int* out,
    const int* in
) {
  *out = ~(*in);

  return out;
}

int* Mdc_Integer_BitwiseAnd(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 & *op2;

  return out;
}

int* Mdc_Integer_BitwiseOr(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 | *op2;

  return out;
}

int* Mdc_Integer_BitwiseXor(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

int* Mdc_Integer_BitwiseLeftShift(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 << *op2;

  return out;
}

int* Mdc_Integer_BitwiseRightShift(
    int* out,
    const int* op1,
    const int* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_Integer_Equal(
    const int* integer1,
    const int* integer2
) {
  return Mdc_Integer_EqualValue(*integer1, *integer2);
}

bool Mdc_Integer_EqualValue(
    int value1,
    int value2
) {
  return value1 == value2;
}

int Mdc_Integer_Compare(
    const int* integer1,
    const int* integer2
) {
  return Mdc_Integer_CompareValue(*integer1, *integer2);
}

int Mdc_Integer_CompareValue(
    int value1,
    int value2
) {
  return value1 - value2;
}

/**
 * Etc. functions
 */

size_t Mdc_Integer_Hash(const int* integer) {
  return Mdc_Integer_HashValue(*integer);
}

size_t Mdc_Integer_HashValue(int integer) {
  return integer % (size_t) -1;
}

void Mdc_Integer_Swap(
    int* integer1,
    int* integer2
) {
  int temp;

  temp = *integer1;
  *integer1 = *integer2;
  *integer2 = temp;
}
