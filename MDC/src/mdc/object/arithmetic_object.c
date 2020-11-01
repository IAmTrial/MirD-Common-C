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

#include "../../../include/mdc/object/arithmetic_object.h"

#define MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(name, type) \
\
/**
 * External
 */ \
\
/**
 * Initialization/deinitialization
 */ \
\
type* name##_InitDefault(type* obj) { \
  return name##_InitFromValue(obj, 0); \
} \
\
type* name##_InitFromValue(type* obj, type value) { \
  *obj = value; \
  return obj; \
} \
\
type* name##_InitCopy(type* dest, const type* src) { \
  *dest = *src; \
  return dest; \
} \
\
type* name##_InitMove( \
    type* dest, \
    type* src \
) { \
  return name##_InitCopy(dest, src); \
} \
\
void name##_Deinit(type* obj) { \
  /* This is left empty on purpose. */ \
} \
\
/**
 * Assignment functions
 */ \
\
type* name##_AssignCopy(type* dest, const type* src) { \
  if (dest == src) { \
    return dest; \
  } \
  *dest = *src; \
  return dest; \
} \
\
type* name##_AssignMove(type* dest, type* src) { \
  return name##_AssignCopy(dest, src); \
} \
\
/**
 * Increment/decrement operators
 */ \
\
type* name##_PreIncrement(type* obj) { \
  *obj += 1; \
  return obj; \
} \
\
type* name##_PreDecrement(type* obj) { \
  *obj -= 1; \
  return obj; \
} \
\
type* name##_PostIncrement(type* out, type* in) { \
  *out = *in; \
  *in += 1; \
  return out; \
} \
\
type* name##_PostDecrement(type* out, type* in) { \
  *out = *in; \
  *in -= 1; \
  return out; \
} \
\
/**
 * Arithmetic operators
 */ \
\
type* name##_Add( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 + *op2; \
  return out; \
} \
\
type* name##_Subtract( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 - *op2; \
  return out; \
} \
\
type* name##_Multiply( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 * *op2; \
  return out; \
} \
\
type* name##_Divide( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 / *op2; \
  return out; \
} \
\
type* name##_Modulo( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 % *op2; \
  return out; \
} \
\
type* name##_BitwiseNot(type* out, const type* in) { \
  *out = ~(*in); \
  return out; \
} \
\
type* name##_BitwiseAnd( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 & *op2; \
  return out; \
} \
\
type* name##_BitwiseOr( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 | *op2; \
  return out; \
} \
\
type* name##_BitwiseXor( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 ^ *op2; \
  return out; \
} \
\
type* name##_BitwiseLeftShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 << *op2; \
  return out; \
} \
\
type* name##_BitwiseRightShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = *op1 >> *op2; \
  return out; \
} \
\
/**
 * Comparison operators
 */ \
\
bool name##_Equal(const type* op1, const type* op2) { \
  return name##_EqualValue(*op1, *op2); \
} \
\
bool name##_EqualValue(type value1, type value2) { \
  return value1 == value2; \
} \
\
int name##_Compare(const type* op1, const type* op2) { \
  return name##_CompareValue(*op1, *op2); \
} \
\
int name##_CompareValue(type value1, type value2) { \
  if (value1 < value2) { \
    return -1; \
  } else if (value1 > value2) { \
    return 1; \
  } else { \
    return 0; \
  } \
} \
\
/**
 * Etc. functions
 */ \
\
size_t name##_Hash(const type* obj) { \
  return name##_HashValue(*obj); \
} \
\
size_t name##_HashValue(type obj) { \
  return obj % (size_t) -1; \
} \
\
void name##_Swap( \
    type* obj1, \
    type* obj2 \
) { \
  type temp = *obj1; \
  *obj1 = *obj2; \
  *obj2 = temp; \
}

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Boolean, bool);

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_SChar, signed char);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Short, short);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Integer, int);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Long, long);

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UChar, unsigned char);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UShort, unsigned short);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UInteger, unsigned int);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_ULong, unsigned long);

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Int8, int8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Int16, int16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Int32, int32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_Int64, int64_t);

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UInt8, uint8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UInt16, uint16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UInt32, uint32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_UInt64, uint64_t);

#if __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600

MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_LLong, long long);
MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS(Mdc_ULLong, unsigned long long);

#endif /* __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600 */

#undef MDC_DEFINE_ARITHMETIC_OBJECT_FUNCS
