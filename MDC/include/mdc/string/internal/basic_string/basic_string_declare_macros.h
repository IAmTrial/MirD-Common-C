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

#ifndef MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DECLARE_MACROS_H_
#define MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DECLARE_MACROS_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../std/stdbool.h"
#include "../char_traits/char_traits_name_macros.h"
#include "basic_string_name_macros.h"

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_STRUCT(CharT) \
    struct Mdc_BasicString(CharT) { \
      CharT* c_str_; \
      size_t length_; \
      size_t capacity_; \
    };

/**
 * Constants
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_K_NPOS(CharT) \
    const size_t Mdc_BasicString_kNpos(CharT);

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CONSTANTS(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_K_NPOS(CharT);

/**
 * Functions
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitEmpty(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromChar(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t count, \
        CharT ch \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitStrTail(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitSubstr(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromCStr(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromCStrTop(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitCopy(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitMove(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        struct Mdc_BasicString(CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(CharT) \
    void Mdc_BasicString_Deinit(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AssignCopy(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AssignMove(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        struct Mdc_BasicString(CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(CharT) \
    CharT* Mdc_BasicString_Access(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(CharT) \
    const CharT* Mdc_BasicString_AccessConst(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_AT(CharT) \
    CharT* Mdc_BasicString_At(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(CharT) \
    const CharT* Mdc_BasicString_AtConst(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendStr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendStrTail(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendSubstr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendCStr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const CharT* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendCStrTop(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const CharT* src, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(CharT) \
    CharT* Mdc_BasicString_Back(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(CharT) \
    const CharT* Mdc_BasicString_BackConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(CharT) \
    size_t Mdc_BasicString_Capacity(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(CharT) \
  int Mdc_BasicString_CompareStr(CharT)( \
      const struct Mdc_BasicString(CharT)* str1, \
      const struct Mdc_BasicString(CharT)* str2 \
  );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(CharT) \
    int Mdc_BasicString_CompareSubstr(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(CharT) \
    int Mdc_BasicString_CompareSubstrs(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(CharT)* str2, \
        size_t pos2, \
        size_t count2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(CharT) \
    int Mdc_BasicString_CompareCStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(CharT) \
    int Mdc_BasicString_CompareCSubstr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(CharT) \
    int Mdc_BasicString_CompareCSubstrs(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const CharT* c_str, \
        size_t count2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(CharT) \
    void Mdc_BasicString_Clear(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(CharT) \
    const CharT* Mdc_BasicString_CStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(CharT) \
    CharT* Mdc_BasicString_Data(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(CharT) \
    const CharT* Mdc_BasicString_DataConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(CharT) \
    bool Mdc_BasicString_Empty(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(CharT) \
    bool Mdc_BasicString_EqualStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        const struct Mdc_BasicString(CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(CharT) \
    bool Mdc_BasicString_EqualCStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(CharT) \
    CharT* Mdc_BasicString_Front(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(CharT) \
    const CharT* Mdc_BasicString_FrontConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(CharT) \
    size_t Mdc_BasicString_Length(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(CharT) \
    void Mdc_BasicString_PopBack(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(CharT) \
    void Mdc_BasicString_PushBack(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        CharT ch \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(CharT) \
    void Mdc_BasicString_Reserve(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t new_capacity \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(CharT) \
    void Mdc_BasicString_ShrinkToFit(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(CharT) \
    size_t Mdc_BasicString_Size(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(CharT) \
    void Mdc_BasicString_Swap(CharT)( \
        struct Mdc_BasicString(CharT)* str1, \
        struct Mdc_BasicString(CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FUNCTIONS(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_AT(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(CharT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING_FUNCTIONS(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_AT(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(CharT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_STRUCT(CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CONSTANTS(CharT) \
    MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING_FUNCTIONS(CharT)

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DECLARE_MACROS_H_ */
