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

#include "../../../include/mdc/object/schar_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

signed char* Mdc_SChar_InitDefault(signed char* ch) {
  return Mdc_SChar_InitFromValue(ch, 0);
}

signed char* Mdc_SChar_InitFromValue(
    signed char* ch,
    signed char value
) {
  *ch = value;

  return ch;
}

signed char* Mdc_SChar_InitCopy(
    signed char* dest,
    const signed char* src
) {
  *dest = *src;

  return dest;
}

signed char* Mdc_SChar_InitMove(
    signed char* dest,
    signed char* src
) {
  return Mdc_SChar_InitCopy(dest, src);
}

void Mdc_SChar_Deinit(signed char* ch) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

signed char* Mdc_SChar_AssignCopy(
    signed char* dest,
    const signed char* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

signed char* Mdc_SChar_AssignMove(
    signed char* dest,
    signed char* src
) {
  return Mdc_SChar_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

signed char* Mdc_SChar_PreIncrement(
    signed char* ch
) {
  *ch += 1;

  return ch;
}

signed char* Mdc_SChar_PreDecrement(
    signed char* ch
) {
  *ch -= 1;

  return ch;
}

signed char* Mdc_SChar_PostIncrement(
    signed char* out,
    signed char* in
) {
  *out = *in;
  *in += 1;

  return out;
}

signed char* Mdc_SChar_PostDecrement(
    signed char* out,
    signed char* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

signed char* Mdc_SChar_Add(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 + *op2;

  return out;
}

signed char* Mdc_SChar_Subtract(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 - *op2;

  return out;
}

signed char* Mdc_SChar_Multiply(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 * *op2;

  return out;
}

signed char* Mdc_SChar_Divide(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 / *op2;

  return out;
}

signed char* Mdc_SChar_Modulo(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 % *op2;

  return out;
}

signed char* Mdc_SChar_BitwiseNot(
    signed char* out,
    const signed char* in
) {
  *out = ~(*in);

  return out;
}

signed char* Mdc_SChar_BitwiseAnd(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 & *op2;

  return out;
}

signed char* Mdc_SChar_BitwiseOr(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 | *op2;

  return out;
}

signed char* Mdc_SChar_BitwiseXor(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

signed char* Mdc_SChar_BitwiseLeftShift(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 << *op2;

  return out;
}

signed char* Mdc_SChar_BitwiseRightShift(
    signed char* out,
    const signed char* op1,
    const signed char* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_SChar_Equal(
    const signed char* ch1,
    const signed char* ch2
) {
  return Mdc_SChar_EqualValue(*ch1, *ch2);
}

bool Mdc_SChar_EqualValue(
    signed char value1,
    signed char value2
) {
  return value1 == value2;
}

int Mdc_SChar_Compare(
    const signed char* ch1,
    const signed char* ch2
) {
  return Mdc_SChar_CompareValue(*ch1, *ch2);
}

int Mdc_SChar_CompareValue(
    signed char value1,
    signed char value2
) {
  return value1 - value2;
}

/**
 * Etc. functions
 */

size_t Mdc_SChar_Hash(const signed char* ch) {
  return Mdc_SChar_HashValue(*ch);
}

size_t Mdc_SChar_HashValue(signed char ch) {
  return ch % (size_t) -1;
}

void Mdc_SChar_Swap(
    signed char* ch1,
    signed char* ch2
) {
  signed char temp;

  temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}
