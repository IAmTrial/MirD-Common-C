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

#include "../../../include/mdc/object/string_literal_object.h"

#define MDC_DEFINE_STRING_LITERAL_OBJECT_FUNCS(name, type) \
\
/**
 * External
 */ \
\
/**
 * Initialization/deinitialization
 */ \
\
const type** name##_InitCopy( \
    const type** dest, \
    const type* const* src \
) { \
  *dest = *src; \
  return dest; \
} \
\
const type** name##_InitMove( \
    const type** dest, \
    const type** src \
) { \
  return name##_InitCopy(dest, src); \
} \
\
void name##_Deinit(const type** obj) { \
  /* This is left empty on purpose. */ \
} \
\
/**
 * Assignment functions
 */ \
\
const type** name##_AssignCopy( \
    const type** dest, \
    const type* const* src \
) { \
  if (dest == src) { \
    return dest; \
  } \
  *dest = *src; \
  return dest; \
} \
\
const type** name##_AssignMove( \
    const type** dest, \
    const type** src \
) { \
  return name##_AssignCopy(dest, src); \
} \
\
/**
 * Comparison operators
 */ \
\
bool name##_Equal( \
    const type* const* op1, \
    const type* const* op2 \
) { \
  size_t i; \
\
  for (i = 0; (*op1)[i] != '\0' || (*op2)[i] != '\0'; i += 1) { \
    if ((*op1)[i] != (*op2)[i]) { \
      return false; \
    } \
  } \
\
  return true; \
} \
\
int name##_Compare( \
    const type* const* op1, \
    const type* const* op2 \
) { \
  size_t i; \
\
  for (i = 0; (*op1)[i] != '\0' || (*op2)[i] != '\0'; i += 1) { \
    if ((*op1)[i] < (*op2)[i]) { \
      return -1; \
    } else if ((*op1)[i] > (*op2)[i]) { \
      return 1; \
    } else { \
      return 0; \
    } \
  } \
\
  return true; \
} \
\
/**
 * Etc. functions
 */ \
\
void name##_Swap( \
    const type** obj1, \
    const type** obj2 \
) { \
  const type* temp = *obj1; \
  *obj1 = *obj2; \
  *obj2 = temp; \
}

const char** Mdc_StringLiteral_InitDefault(const char** obj) {
  *obj = "";
  return obj;
}

const wchar_t** Mdc_WStringLiteral_InitDefault(const wchar_t** obj) {
  *obj = L"";
  return obj;
}

MDC_DEFINE_STRING_LITERAL_OBJECT_FUNCS(Mdc_StringLiteral, char)
MDC_DEFINE_STRING_LITERAL_OBJECT_FUNCS(Mdc_WStringLiteral, wchar_t)

#undef MDC_DEFINE_STRING_LITERAL_OBJECT_FUNCS
