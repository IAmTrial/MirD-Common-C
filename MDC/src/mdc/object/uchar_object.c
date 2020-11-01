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

#include "../../../include/mdc/object/uchar_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

unsigned char* Mdc_UChar_InitDefault(unsigned char* ch) {
  return Mdc_UChar_InitFromValue(ch, 0);
}

unsigned char* Mdc_UChar_InitFromValue(
    unsigned char* ch,
    unsigned char value
) {
  *ch = value;

  return ch;
}

unsigned char* Mdc_UChar_InitCopy(
    unsigned char* dest,
    const unsigned char* src
) {
  *dest = *src;

  return dest;
}

unsigned char* Mdc_UChar_InitMove(
    unsigned char* dest,
    unsigned char* src
) {
  return Mdc_UChar_InitCopy(dest, src);
}

void Mdc_UChar_Deinit(unsigned char* ch) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

unsigned char* Mdc_UChar_AssignCopy(
    unsigned char* dest,
    const unsigned char* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

unsigned char* Mdc_UChar_AssignMove(
    unsigned char* dest,
    unsigned char* src
) {
  return Mdc_UChar_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

unsigned char* Mdc_UChar_PreIncrement(
    unsigned char* ch
) {
  *ch += 1;

  return ch;
}

unsigned char* Mdc_UChar_PreDecrement(
    unsigned char* ch
) {
  *ch -= 1;

  return ch;
}

unsigned char* Mdc_UChar_PostIncrement(
    unsigned char* out,
    unsigned char* in
) {
  *out = *in;
  *in += 1;

  return out;
}

unsigned char* Mdc_UChar_PostDecrement(
    unsigned char* out,
    unsigned char* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

unsigned char* Mdc_UChar_Add(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 + *op2;

  return out;
}

unsigned char* Mdc_UChar_Subtract(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 - *op2;

  return out;
}

unsigned char* Mdc_UChar_Multiply(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 * *op2;

  return out;
}

unsigned char* Mdc_UChar_Divide(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 / *op2;

  return out;
}

unsigned char* Mdc_UChar_Modulo(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 % *op2;

  return out;
}

unsigned char* Mdc_UChar_BitwiseNot(
    unsigned char* out,
    const unsigned char* in
) {
  *out = ~(*in);

  return out;
}

unsigned char* Mdc_UChar_BitwiseAnd(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 & *op2;

  return out;
}

unsigned char* Mdc_UChar_BitwiseOr(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 | *op2;

  return out;
}

unsigned char* Mdc_UChar_BitwiseXor(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

unsigned char* Mdc_UChar_BitwiseLeftShift(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 << *op2;

  return out;
}

unsigned char* Mdc_UChar_BitwiseRightShift(
    unsigned char* out,
    const unsigned char* op1,
    const unsigned char* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_UChar_Equal(
    const unsigned char* ch1,
    const unsigned char* ch2
) {
  return Mdc_UChar_EqualValue(*ch1, *ch2);
}

bool Mdc_UChar_EqualValue(
    unsigned char value1,
    unsigned char value2
) {
  return value1 == value2;
}

int Mdc_UChar_Compare(
    const unsigned char* ch1,
    const unsigned char* ch2
) {
  return Mdc_UChar_CompareValue(*ch1, *ch2);
}

int Mdc_UChar_CompareValue(
    unsigned char value1,
    unsigned char value2
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

size_t Mdc_UChar_Hash(const unsigned char* ch) {
  return Mdc_UChar_HashValue(*ch);
}

size_t Mdc_UChar_HashValue(unsigned char ch) {
  return ch % (size_t) -1;
}

void Mdc_UChar_Swap(
    unsigned char* ch1,
    unsigned char* ch2
) {
  unsigned char temp;

  temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}
