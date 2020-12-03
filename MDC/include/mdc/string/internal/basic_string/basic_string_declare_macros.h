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
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "../char_traits/char_traits_name_macros.h"
#include "basic_string_name_macros.h"

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_STRUCT(T_CharT) \
    struct Mdc_BasicString(T_CharT) { \
      MDC_T_P(T_CharT) c_str_; \
      size_t length_; \
      size_t capacity_; \
    }; \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(struct, Mdc_BasicString(T_CharT))

/**
 * Constants
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_K_NPOS(T_CharT) \
    extern const size_t Mdc_BasicString_kNpos(T_CharT);

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CONSTANTS(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_K_NPOS(T_CharT);

#define MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING_CONSTANTS(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_K_NPOS(T_CharT);

/**
 * Functions
 */

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(T_CharT) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT(Mdc_BasicString(T_CharT))

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitFromChar(T_CharT)( \
        size_t count, \
        MDC_T(T_CharT) ch \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitStrTail(T_CharT)( \
        MDC_T_PC(Mdc_BasicString(T_CharT)) src, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitSubstr(T_CharT)( \
        MDC_T_PC(Mdc_BasicString(T_CharT)) src, \
        size_t pos, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitFromCStr(T_CharT)( \
        const T_CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitFromCStrTop(T_CharT)( \
        const T_CharT* c_str, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitCopy(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitMove(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(T_CharT) \
    void Mdc_BasicString_Deinit(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AssignCopy(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AssignMove(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        struct Mdc_BasicString(T_CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(T_CharT) \
    T_CharT* Mdc_BasicString_Access(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_AccessConst(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_AT(T_CharT) \
    T_CharT* Mdc_BasicString_At(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_AtConst(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendStr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendStrTail(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendSubstr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendCStr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const T_CharT* src \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendCStrTop(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const T_CharT* src, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(T_CharT) \
    T_CharT* Mdc_BasicString_Back(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_BackConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(T_CharT) \
    size_t Mdc_BasicString_Capacity(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(T_CharT) \
  int Mdc_BasicString_CompareStr(T_CharT)( \
      const struct Mdc_BasicString(T_CharT)* str1, \
      const struct Mdc_BasicString(T_CharT)* str2 \
  );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(T_CharT) \
    int Mdc_BasicString_CompareSubstr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(T_CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(T_CharT) \
    int Mdc_BasicString_CompareSubstrs(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(T_CharT)* str2, \
        size_t pos2, \
        size_t count2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(T_CharT) \
    int Mdc_BasicString_CompareCStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        const T_CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(T_CharT) \
    int Mdc_BasicString_CompareCSubstr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const T_CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(T_CharT) \
    int Mdc_BasicString_CompareCSubstrs(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const T_CharT* c_str, \
        size_t count2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(T_CharT) \
    void Mdc_BasicString_Clear(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(T_CharT) \
    const T_CharT* Mdc_BasicString_CStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(T_CharT) \
    T_CharT* Mdc_BasicString_Data(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_DataConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(T_CharT) \
    bool Mdc_BasicString_Empty(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(T_CharT) \
    bool Mdc_BasicString_EqualStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        const struct Mdc_BasicString(T_CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(T_CharT) \
    bool Mdc_BasicString_EqualCStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        const T_CharT* c_str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(T_CharT) \
    T_CharT* Mdc_BasicString_Front(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_FrontConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(T_CharT) \
    size_t Mdc_BasicString_Length(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(T_CharT) \
    void Mdc_BasicString_PopBack(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(T_CharT) \
    void Mdc_BasicString_PushBack(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        T_CharT ch \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(T_CharT) \
    void Mdc_BasicString_Reserve(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t new_capacity \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(T_CharT) \
    void Mdc_BasicString_ShrinkToFit(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(T_CharT) \
    size_t Mdc_BasicString_Size(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(T_CharT) \
    void Mdc_BasicString_Swap(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str1, \
        struct Mdc_BasicString(T_CharT)* str2 \
    );

#define MDC_INTERNAL_DECLARE_BASIC_STRING_FUNCTIONS(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_AT(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(T_CharT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING_FUNCTIONS(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_EMPTY(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_CHAR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_STR_TAIL(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_SUBSTR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_FROM_C_STR_TOP(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_COPY(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_INIT_MOVE(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DEINIT(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_COPY(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ASSIGN_MOVE(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_ACCESS_CONST(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_AT(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_AT_CONST(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_STR_TAIL(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_SUBSTR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_APPEND_C_STR_TOP(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_BACK(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_BACK_CONST(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_CAPACITY(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_SUBSTRS(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_COMPARE_C_SUBSTRS(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_CLEAR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_C_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DATA(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_DATA_CONST(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EMPTY(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_EQUAL_C_STR(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_FRONT_CONST(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_LENGTH(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_POP_BACK(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_PUSH_BACK(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_RESERVE(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SHRINK_TO_FIT(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SIZE(T_CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_BASIC_STRING_SWAP(T_CharT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_STRUCT(T_CharT) \
    MDC_INTERNAL_DECLARE_BASIC_STRING_CONSTANTS(T_CharT) \
    MDC_INTERNAL_DECLARE_DLLEXPORT_BASIC_STRING_FUNCTIONS(T_CharT)

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DECLARE_MACROS_H_ */
