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

#include "../../../include/mdc/object/ushort_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

unsigned short* Mdc_UShort_InitDefault(unsigned short* shrt) {
  return Mdc_UShort_InitFromValue(shrt, 0);
}

unsigned short* Mdc_UShort_InitFromValue(
    unsigned short* shrt,
    unsigned short value
) {
  *shrt = value;

  return shrt;
}

unsigned short* Mdc_UShort_InitCopy(
    unsigned short* dest,
    const unsigned short* src
) {
  *dest = *src;

  return dest;
}

unsigned short* Mdc_UShort_InitMove(
    unsigned short* dest,
    unsigned short* src
) {
  return Mdc_UShort_InitCopy(dest, src);
}

void Mdc_UShort_Deinit(unsigned short* shrt) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

unsigned short* Mdc_UShort_AssignCopy(
    unsigned short* dest,
    const unsigned short* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

unsigned short* Mdc_UShort_AssignMove(
    unsigned short* dest,
    unsigned short* src
) {
  return Mdc_UShort_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

unsigned short* Mdc_UShort_PreIncrement(
    unsigned short* shrt
) {
  *shrt += 1;

  return shrt;
}

unsigned short* Mdc_UShort_PreDecrement(
    unsigned short* shrt
) {
  *shrt -= 1;

  return shrt;
}

unsigned short* Mdc_UShort_PostIncrement(
    unsigned short* out,
    unsigned short* in
) {
  *out = *in;
  *in += 1;

  return out;
}

unsigned short* Mdc_UShort_PostDecrement(
    unsigned short* out,
    unsigned short* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

unsigned short* Mdc_UShort_Add(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 + *op2;

  return out;
}

unsigned short* Mdc_UShort_Subtract(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 - *op2;

  return out;
}

unsigned short* Mdc_UShort_Multiply(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 * *op2;

  return out;
}

unsigned short* Mdc_UShort_Divide(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 / *op2;

  return out;
}

unsigned short* Mdc_UShort_Modulo(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 % *op2;

  return out;
}

unsigned short* Mdc_UShort_BitwiseNot(
    unsigned short* out,
    const unsigned short* in
) {
  *out = ~(*in);

  return out;
}

unsigned short* Mdc_UShort_BitwiseAnd(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 & *op2;

  return out;
}

unsigned short* Mdc_UShort_BitwiseOr(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 | *op2;

  return out;
}

unsigned short* Mdc_UShort_BitwiseXor(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

unsigned short* Mdc_UShort_BitwiseLeftShift(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 << *op2;

  return out;
}

unsigned short* Mdc_UShort_BitwiseRightShift(
    unsigned short* out,
    const unsigned short* op1,
    const unsigned short* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_UShort_Equal(
    const unsigned short* short1,
    const unsigned short* short2
) {
  return *short1 == *short2;
}

bool Mdc_UShort_EqualValue(
    const unsigned short* shrt,
    unsigned short value
) {
  return *shrt == value;
}

int Mdc_UShort_Compare(
    const unsigned short* short1,
    const unsigned short* short2
) {
  return *short1 - *short2;
}

int Mdc_UShort_CompareValue(
    const unsigned short* shrt,
    unsigned short value
) {
  return *shrt - value;
}

/**
 * Etc. functions
 */

size_t Mdc_UShort_Hash(const unsigned short* shrt) {
  return *shrt % (size_t) -1;
}

void Mdc_UShort_Swap(
    unsigned short* short1,
    unsigned short* short2
) {
  unsigned short temp;

  temp = *short1;
  *short1 = *short2;
  *short2 = temp;
}
