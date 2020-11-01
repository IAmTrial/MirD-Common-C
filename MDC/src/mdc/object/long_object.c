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

#include "../../../include/mdc/object/long_object.h"

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

long* Mdc_Long_InitDefault(long* lng) {
  return Mdc_Long_InitFromValue(lng, 0);
}

long* Mdc_Long_InitFromValue(
    long* lng,
    long value
) {
  *lng = value;

  return lng;
}

long* Mdc_Long_InitCopy(
    long* dest,
    const long* src
) {
  *dest = *src;

  return dest;
}

long* Mdc_Long_InitMove(
    long* dest,
    long* src
) {
  return Mdc_Long_InitCopy(dest, src);
}

void Mdc_Long_Deinit(long* lng) {
  /* This is left empty on purpose. */
}

/**
 * Assignment functions
 */

long* Mdc_Long_AssignCopy(
    long* dest,
    const long* src
) {
  if (dest == src) {
    return dest;
  }

  *dest = *src;

  return dest;
}

long* Mdc_Long_AssignMove(
    long* dest,
    long* src
) {
  return Mdc_Long_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

long* Mdc_Long_PreIncrement(
    long* lng
) {
  *lng += 1;

  return lng;
}

long* Mdc_Long_PreDecrement(
    long* lng
) {
  *lng -= 1;

  return lng;
}

long* Mdc_Long_PostIncrement(
    long* out,
    long* in
) {
  *out = *in;
  *in += 1;

  return out;
}

long* Mdc_Long_PostDecrement(
    long* out,
    long* in
) {
  *out = *in;
  *in -= 1;

  return out;
}

/**
 * Arithmetic operators
 */

long* Mdc_Long_Add(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 + *op2;

  return out;
}

long* Mdc_Long_Subtract(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 - *op2;

  return out;
}

long* Mdc_Long_Multiply(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 * *op2;

  return out;
}

long* Mdc_Long_Divide(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 / *op2;

  return out;
}

long* Mdc_Long_Modulo(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 % *op2;

  return out;
}

long* Mdc_Long_BitwiseNot(
    long* out,
    const long* in
) {
  *out = ~(*in);

  return out;
}

long* Mdc_Long_BitwiseAnd(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 & *op2;

  return out;
}

long* Mdc_Long_BitwiseOr(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 | *op2;

  return out;
}

long* Mdc_Long_BitwiseXor(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 ^ *op2;

  return out;
}

long* Mdc_Long_BitwiseLeftShift(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 << *op2;

  return out;
}

long* Mdc_Long_BitwiseRightShift(
    long* out,
    const long* op1,
    const long* op2
) {
  *out = *op1 >> *op2;

  return out;
}

/**
 * Comparison operators
 */

bool Mdc_Long_Equal(
    const long* long1,
    const long* long2
) {
  return *long1 == *long2;
}

bool Mdc_Long_EqualValue(
    const long* lng,
    long value
) {
  return *lng == value;
}

int Mdc_Long_Compare(
    const long* long1,
    const long* long2
) {
  return *long1 - *long2;
}

int Mdc_Long_CompareValue(
    const long* lng,
    long value
) {
  return *lng - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Long_Hash(const long* lng) {
  return *lng % (size_t) -1;
}

void Mdc_Long_Swap(
    long* long1,
    long* long2
) {
  long temp;

  temp = *long1;
  *long1 = *long2;
  *long2 = temp;
}
