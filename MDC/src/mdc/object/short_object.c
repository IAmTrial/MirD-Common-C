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

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

short* Mdc_Short_InitDefault(short* shrt) {
  return Mdc_Short_InitFromValue(shrt, 0);
}

short* Mdc_Short_InitFromValue(
    short* shrt,
    short value
) {
  *shrt = value;

  return shrt;
}

short* Mdc_Short_InitCopy(
    short* dest,
    const short* src
) {
  *dest = *src;

  return dest;
}

short* Mdc_Short_InitMove(
    short* dest,
    short* src
) {
  return Mdc_Short_InitCopy(dest, src);
}

void Mdc_Short_Deinit(short* shrt) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

short* Mdc_Short_AssignCopy(
    short* dest,
    const short* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

short* Mdc_Short_AssignMove(
    short* dest,
    short* src
) {
  return Mdc_Short_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

short* Mdc_Short_PreIncrement(
    short* shrt
) {
  *shrt += 1;

  return shrt;
}

short* Mdc_Short_PreDecrement(
    short* shrt
) {
  *shrt -= 1;

  return shrt;
}

short* Mdc_Short_PostIncrement(
    short* out,
    short* in
) {
  *out = *in;
  *in += 1;

  return out;
}

short* Mdc_Short_PostDecrement(
    short* out,
    short* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

short* Mdc_Short_Add(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 + *op2;

  return out;
}

short* Mdc_Short_Subtract(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 - *op2;

  return out;
}

short* Mdc_Short_Multiply(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 * *op2;

  return out;
}

short* Mdc_Short_Divide(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 / *op2;

  return out;
}

short* Mdc_Short_Modulo(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 % *op2;

  return out;
}

short* Mdc_Short_BitwiseNot(
    short* out,
    const short* in
) {
  *out = ~(*in);

  return out;
}

short* Mdc_Short_BitwiseAnd(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 & *op2;

  return out;
}

short* Mdc_Short_BitwiseOr(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 | *op2;

  return out;
}

short* Mdc_Short_BitwiseXor(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

short* Mdc_Short_BitwiseLeftShift(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 << *op2;

  return out;
}

short* Mdc_Short_BitwiseRightShift(
    short* out,
    const short* op1,
    const short* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_Short_Equal(
    const short* short1,
    const short* short2
) {
  return Mdc_Short_EqualValue(*short1, *short2);
}

bool Mdc_Short_EqualValue(
    short value1,
    short value2
) {
  return value1 == value2;
}

int Mdc_Short_Compare(
    const short* short1,
    const short* short2
) {
  return Mdc_Short_CompareValue(*short1, *short2);
}

int Mdc_Short_CompareValue(
    short value1,
    short value2
) {
  return value1 - value2;
}

/**
 * Etc. functions
 */

size_t Mdc_Short_Hash(const short* shrt) {
  return Mdc_Short_HashValue(*shrt);
}

size_t Mdc_Short_HashValue(short shrt) {
  return shrt % (size_t) -1;
}

void Mdc_Short_Swap(
    short* short1,
    short* short2
) {
  short temp;

  temp = *short1;
  *short1 = *short2;
  *short2 = temp;
}
