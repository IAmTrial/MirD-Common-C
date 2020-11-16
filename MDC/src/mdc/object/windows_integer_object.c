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

#include "../../../include/mdc/object/windows_integer_object.h"

#if defined(_WIN32) || defined(_WIN64)

#define MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(name, type) \
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
  *obj = name##_PreIncrementValue(*obj); \
  return obj; \
} \
\
type name##_PreIncrementValue(type op) { \
  return ++op; \
} \
\
type* name##_PreDecrement(type* obj) { \
  *obj = name##_PreDecrementValue(*obj); \
  return obj; \
} \
\
type name##_PreDecrementValue(type op) { \
  return --op; \
} \
\
type* name##_PostIncrement(type* out, type* in) { \
  *out = name##_PostIncrementValue(in); \
  return out; \
} \
\
type name##_PostIncrementValue(type* op) { \
  return (*op)++; \
} \
\
type* name##_PostDecrement(type* out, type* in) { \
  *out = name##_PostDecrementValue(in); \
  return out; \
} \
\
type name##_PostDecrementValue(type* op) { \
  return (*op)--; \
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
  *out = name##_AddValue(*op1, *op2); \
  return out; \
} \
\
type name##_AddValue(type op1, type op2) { \
  return op1 + op2; \
} \
\
type* name##_Subtract( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_SubtractValue(*op1, *op2); \
  return out; \
} \
\
type name##_SubtractValue(type op1, type op2) { \
  return op1 - op2; \
} \
\
type* name##_Multiply( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_MultiplyValue(*op1, *op2); \
  return out; \
} \
\
type name##_MultiplyValue(type op1, type op2) { \
  return op1 * op2; \
} \
\
type* name##_Divide( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_DivideValue(*op1, *op2); \
  return out; \
} \
\
type name##_DivideValue(type op1, type op2) { \
  return op1 / op2; \
} \
\
type* name##_Modulo( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_ModuloValue(*op1, *op2); \
  return out; \
} \
\
type name##_ModuloValue(type op1, type op2) { \
  return op1 % op2; \
} \
\
type* name##_BitwiseNot(type* out, const type* in) { \
  *out = name##_BitwiseNotValue(*in); \
  return out; \
} \
\
type name##_BitwiseNotValue(type op) { \
  return ~op; \
} \
\
type* name##_BitwiseAnd( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_BitwiseAndValue(*op1, *op2); \
  return out; \
} \
\
type name##_BitwiseAndValue(type op1, type op2) { \
  return op1 & op2; \
} \
\
type* name##_BitwiseOr( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_BitwiseOrValue(*op1, *op2); \
  return out; \
} \
\
type name##_BitwiseOrValue(type op1, type op2) { \
  return op1 | op2; \
} \
\
type* name##_BitwiseXor( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_BitwiseXorValue(*op1, *op2); \
  return out; \
} \
\
type name##_BitwiseXorValue(type op1, type op2) { \
  return op1 ^ op2; \
} \
\
type* name##_BitwiseLeftShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_BitwiseLeftShiftValue(*op1, *op2); \
  return out; \
} \
\
type name##_BitwiseLeftShiftValue(type op1, type op2) { \
  return op1 << op2; \
} \
\
type* name##_BitwiseRightShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
) { \
  *out = name##_BitwiseRightShiftValue(*op1, *op2); \
  return out; \
} \
\
type name##_BitwiseRightShiftValue(type op1, type op2) { \
  return op1 >> op2; \
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

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_BOOL, BOOL);

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_CHAR, CHAR);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_UCHAR, UCHAR);

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_SHORT, SHORT);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_INT, INT);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_LONG, LONG);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_LONGLONG, LONGLONG);

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_USHORT, USHORT);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_UINT, UINT);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_ULONG, ULONG);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_ULONGLONG, ULONGLONG);

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_BYTE, BYTE);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_WORD, WORD);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD, DWORD);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORDLONG, DWORDLONG);

MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD32, DWORD32);
MDC_DEFINE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD64, DWORD64);

#undef MDC_DEFINE_INTEGER_OBJECT_FUNCS

#endif /* defined(_WIN32) || defined(_WIN64) */
