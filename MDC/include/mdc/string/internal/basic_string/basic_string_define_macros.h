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

#ifndef MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DEFINE_MACROS_H_
#define MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DEFINE_MACROS_H_

#include <stddef.h>

#include "../../../malloc/malloc.h"

#define MDC_INTERNAL_BASIC_STRING_DEINIT { 0 }

#define Mdc_BasicString_kUninit(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), __kUninit)

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT_CONST(T_CharT) \
    static const struct Mdc_BasicString(T_CharT) \
    Mdc_BasicString_kUninit(T_CharT) = MDC_INTERNAL_BASIC_STRING_DEINIT;

/**
 * Constants
 */

#define MDC_INTERNAL_DEFINE_BASIC_STRING_K_NPOS(T_CharT) \
    const size_t Mdc_BasicString_kNpos(T_CharT) = (size_t) -1;

#define Mdc_BasicString_kNullChar(T_CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(T_CharT), __kNullChar)

#define MDC_INTERNAL_DEFINE_K_NULL_CHAR(T_CharT) \
    const T_CharT Mdc_BasicString_kNullChar(T_CharT) = '\0';

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CONSTANTS(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_K_NPOS(T_CharT) \
    MDC_INTERNAL_DEFINE_K_NULL_CHAR(T_CharT)

enum {
  kInitialCapacity = 4
};

/**
 * Functions
 */

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_EMPTY(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitEmpty(T_CharT)( \
        void \
    ) { \
      struct Mdc_BasicString(T_CharT) str; \
\
      str.capacity_ = kInitialCapacity; \
      str.c_str_ = Mdc_malloc(str.capacity_ * sizeof(str.c_str_[0])); \
      if (str.c_str_ == NULL) { \
        return Mdc_BasicString_kUninit(T_CharT); \
      } \
\
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str.c_str_[0], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
      str.length_ = 0; \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_CHAR(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitFromChar(T_CharT)( \
        size_t count, \
        T_CharT ch \
    ) { \
      struct Mdc_BasicString(T_CharT) str; \
\
      str.capacity_ = count + 1; \
      str.c_str_ = Mdc_malloc(str.capacity_ * sizeof(str.c_str_[0])); \
      if (str.c_str_ == NULL) { \
        return Mdc_BasicString_kUninit(T_CharT); \
      } \
\
      str.length_ = count; \
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str.c_str_[count], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
      Mdc_CharTraits_AssignCStr(T_CharT)(str.c_str_, count, ch); \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_STR_TAIL(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitStrTail(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos \
    ) { \
      return Mdc_BasicString_InitSubstr(T_CharT)( \
          src, \
          pos, \
          Mdc_BasicString_kNpos(T_CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_SUBSTR(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitSubstr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos, \
        size_t count \
    ) { \
      if (count == Mdc_BasicString_kNpos(T_CharT)) { \
        count = src->length_ - pos; \
      } \
\
      return Mdc_BasicString_InitFromCStrTop(T_CharT)( \
          &src->c_str_[pos], \
          count \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitFromCStr(T_CharT)( \
        const T_CharT* c_str \
    ) { \
      return Mdc_BasicString_InitFromCStrTop(T_CharT)( \
          c_str, \
          Mdc_CharTraits_LengthCStr(T_CharT)(c_str) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR_TOP(T_CharT) \
    struct Mdc_BasicString(T_CharT) \
    Mdc_BasicString_InitFromCStrTop(T_CharT)( \
        const T_CharT* c_str, \
        size_t count \
    ) { \
      struct Mdc_BasicString(T_CharT) str; \
\
      str.capacity_ = count + 1; \
      str.c_str_ = Mdc_malloc(str.capacity_ * sizeof(str.c_str_[0])); \
      if (str.c_str_ == NULL) { \
        return Mdc_BasicString_kUninit(T_CharT); \
      } \
\
      str.length_ = count; \
      Mdc_CharTraits_CopyNonoverlapCStr(T_CharT)( \
          str.c_str_, \
          c_str, \
          count \
      ); \
\
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str.c_str_[count], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_COPY(T_CharT) \
    MDC_T(Mdc_BasicString(T_CharT)) Mdc_BasicString_InitCopy(T_CharT)( \
        MDC_T_PC(Mdc_BasicString(T_CharT)) src \
    ) { \
      return Mdc_BasicString_InitStrTail(T_CharT)(src, 0); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_MOVE(T_CharT) \
    struct Mdc_BasicString(T_CharT) Mdc_BasicString_InitMove(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* src \
    ) { \
      struct Mdc_BasicString(T_CharT) dest; \
      dest = *src; \
      *src = Mdc_BasicString_kUninit(T_CharT); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT(T_CharT) \
    void Mdc_BasicString_Deinit(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      if (str->c_str_ != NULL) { \
        Mdc_free(str->c_str_); \
      } \
\
      *str = Mdc_BasicString_kUninit(T_CharT); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_COPY(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AssignCopy(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src \
    ) { \
      struct Mdc_BasicString(T_CharT) temp_str; \
\
      const struct Mdc_BasicString(T_CharT)* assign_dest; \
\
      if (dest == src) { \
        return dest; \
      } \
\
      temp_str = Mdc_BasicString_InitCopy(T_CharT)(src); \
\
      assign_dest = Mdc_BasicString_AssignMove(T_CharT)(dest, &temp_str); \
      if (assign_dest != dest) { \
        Mdc_BasicString_Deinit(T_CharT)(&temp_str); \
        return NULL; \
      } \
\
      Mdc_BasicString_Deinit(T_CharT)(&temp_str); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_MOVE(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AssignMove(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        struct Mdc_BasicString(T_CharT)* src \
    ) { \
      if (dest == src) { \
        return dest; \
      } \
\
      if (dest->c_str_ != NULL) { \
        Mdc_free(dest->c_str_); \
      } \
\
      dest->length_ = src->length_; \
      dest->capacity_ = src->capacity_; \
      dest->c_str_ = src->c_str_; \
\
      *src = Mdc_BasicString_kUninit(T_CharT); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS(T_CharT) \
    T_CharT* Mdc_BasicString_Access(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    ) { \
      return (T_CharT*) Mdc_BasicString_AccessConst(T_CharT)(str, pos); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_AccessConst(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    ) { \
      return &str->c_str_[pos]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_AT(T_CharT) \
    T_CharT* Mdc_BasicString_At(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    ) { \
      return (T_CharT*) Mdc_BasicString_AtConst(T_CharT)(str, pos); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_AT_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_AtConst(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t pos \
    ) { \
      if (pos < 0 || pos >= str->length_) { \
        return NULL; \
      } \
\
      return &str->c_str_[pos]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendStr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src \
    ) { \
      return Mdc_BasicString_AppendStrTail(T_CharT)( \
          dest, \
          src, \
          0 \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR_TAIL(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendStrTail(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos \
    ) { \
      return Mdc_BasicString_AppendSubstr(T_CharT)( \
          dest, \
          src, \
          pos, \
          Mdc_BasicString_kNpos(T_CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_SUBSTR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendSubstr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const struct Mdc_BasicString(T_CharT)* src, \
        size_t pos, \
        size_t count \
    ) { \
      if (count == Mdc_BasicString_kNpos(T_CharT)) { \
        count = src->length_; \
      } \
\
      return Mdc_BasicString_AppendCStrTop(T_CharT)( \
          dest, \
          &src->c_str_[pos], \
          count \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendCStr(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const T_CharT* src \
    ) { \
      return Mdc_BasicString_AppendCStrTop(T_CharT)( \
          dest, \
          src, \
          Mdc_CharTraits_LengthCStr(T_CharT)(src) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR_TOP(T_CharT) \
    struct Mdc_BasicString(T_CharT)* Mdc_BasicString_AppendCStrTop(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* dest, \
        const T_CharT* src, \
        size_t count \
    ) { \
      size_t new_length; \
      size_t new_capacity; \
\
      new_length = dest->length_ + count; \
      new_capacity = dest->capacity_; \
\
      /* Increase capacity if needed. */ \
      if (new_length >= dest->capacity_) { \
        while (new_capacity <= new_length) { \
          new_capacity *= 2; \
        } \
\
        Mdc_BasicString_Reserve(T_CharT)(dest, new_capacity); \
\
        if (dest->capacity_ < new_capacity) { \
          return NULL; \
        } \
      } \
\
      Mdc_CharTraits_CopyNonoverlapCStr(T_CharT)( \
          &dest->c_str_[dest->length_], \
          src, \
          count \
      ); \
\
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &dest->c_str_[new_length], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
\
      dest->length_ = new_length; \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_BACK(T_CharT) \
    T_CharT* Mdc_BasicString_Back(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return (T_CharT*) Mdc_BasicString_BackConst(T_CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_BACK_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_BackConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return &str->c_str_[str->length_ - 1]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CAPACITY(T_CharT) \
    size_t Mdc_BasicString_Capacity(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return str->capacity_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_STR(T_CharT) \
  int Mdc_BasicString_CompareStr(T_CharT)( \
      const struct Mdc_BasicString(T_CharT)* str1, \
      const struct Mdc_BasicString(T_CharT)* str2 \
  ) { \
    return Mdc_BasicString_CompareSubstr(T_CharT)( \
        str1, \
        0, \
        str1->length_, \
        str2 \
    ); \
  }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTR(T_CharT) \
    int Mdc_BasicString_CompareSubstr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(T_CharT)* str2 \
    ) { \
      return Mdc_BasicString_CompareSubstrs(T_CharT)( \
          str1, \
          pos1, \
          count1, \
          str2, \
          0, \
          Mdc_BasicString_kNpos(T_CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTRS(T_CharT) \
    int Mdc_BasicString_CompareSubstrs(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(T_CharT)* str2, \
        size_t pos2, \
        size_t count2 \
    ) { \
      if (count2 == Mdc_BasicString_kNpos(T_CharT) \
          || count2 > str2->length_ - pos2) { \
        count2 = str2->length_ - pos2; \
      } \
\
      return Mdc_BasicString_CompareCSubstrs(T_CharT)( \
          str1, \
          pos1, \
          count1, \
          &str2->c_str_[pos2], \
          count2 \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_STR(T_CharT) \
    int Mdc_BasicString_CompareCStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        const T_CharT* c_str \
    ) { \
      return Mdc_BasicString_CompareCSubstr(T_CharT)( \
          str, \
          0, \
          str->length_, \
          c_str \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTR(T_CharT) \
    int Mdc_BasicString_CompareCSubstr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const T_CharT* c_str \
    ) { \
      return Mdc_BasicString_CompareCSubstrs(T_CharT)( \
          str, \
          pos1, \
          count1, \
          c_str, \
          Mdc_CharTraits_LengthCStr(T_CharT)(c_str) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTRS(T_CharT) \
    int Mdc_BasicString_CompareCSubstrs(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const T_CharT* c_str, \
        size_t count2 \
    ) { \
      bool is_str_length_equal; \
      bool is_str_length_less_than; \
\
      size_t compare_length; \
      int compare_result; \
\
      /* Limit count1 to the length of str. */ \
      if (count1 > str->length_ - pos1) { \
        count1 = str->length_ - pos1; \
      } \
\
      /* Compare the strings up to the length of the shorter one. */ \
      is_str_length_equal = (count1 == count2); \
      is_str_length_less_than = (count1 < count2); \
\
      if (is_str_length_less_than) { \
        compare_length = count1; \
      } else { \
        compare_length = count2; \
      } \
\
      compare_result = Mdc_CharTraits_CompareCStr(T_CharT)( \
          str->c_str_, \
          c_str, \
          compare_length \
      ); \
\
      if (compare_result != 0 || is_str_length_equal) { \
        return compare_result; \
      } \
\
      /* Treat the shorter one's end char as null-term. */ \
      if (is_str_length_less_than) { \
        return Mdc_CharTraits_CompareCStr(T_CharT)( \
            &Mdc_BasicString_kNullChar(T_CharT), \
            &c_str[compare_length], \
            1 \
        ); \
      } else { \
        return Mdc_CharTraits_CompareCStr(T_CharT)( \
            &str->c_str_[compare_length], \
            &Mdc_BasicString_kNullChar(T_CharT), \
            1 \
        ); \
      } \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CLEAR(T_CharT) \
    void Mdc_BasicString_Clear(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str->c_str_[0], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
\
      str->length_ = 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_C_STR(T_CharT) \
    const T_CharT* Mdc_BasicString_CStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return str->c_str_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DATA(T_CharT) \
    T_CharT* Mdc_BasicString_Data(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return (T_CharT*) Mdc_BasicString_DataConst(T_CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DATA_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_DataConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return Mdc_BasicString_CStr(T_CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EMPTY(T_CharT) \
    bool Mdc_BasicString_Empty(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return Mdc_BasicString_Length(T_CharT)(str) == 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_STR(T_CharT) \
    bool Mdc_BasicString_EqualStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str1, \
        const struct Mdc_BasicString(T_CharT)* str2 \
    ) { \
      int compare_result; \
\
      if (str1->length_ != str2->length_) { \
        return false; \
      } \
\
      compare_result = Mdc_CharTraits_CompareCStr(T_CharT)( \
          str1->c_str_, \
          str2->c_str_, \
          str1->length_ \
      ); \
\
      return (compare_result == 0); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_C_STR(T_CharT) \
    bool Mdc_BasicString_EqualCStr(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str, \
        const T_CharT* c_str \
    ) { \
      int compare_result; \
\
      compare_result = Mdc_CharTraits_CompareCStr(T_CharT)( \
          str->c_str_, \
          c_str, \
          str->length_ \
      ); \
\
      if (compare_result != 0) { \
        return compare_result; \
      } \
\
      compare_result = Mdc_CharTraits_CompareCStr(T_CharT)( \
          &Mdc_BasicString_kNullChar(T_CharT), \
          &c_str[str->length_], \
          1 \
      ); \
\
      return compare_result == 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT(T_CharT) \
    T_CharT* Mdc_BasicString_Front(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return (T_CharT*) Mdc_BasicString_FrontConst(T_CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT_CONST(T_CharT) \
    const T_CharT* Mdc_BasicString_FrontConst(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return &str->c_str_[0]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_LENGTH(T_CharT) \
    size_t Mdc_BasicString_Length(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return str->length_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_POP_BACK(T_CharT) \
    void Mdc_BasicString_PopBack(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      str->length_ -= 1; \
\
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str->c_str_[str->length_], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_PUSH_BACK(T_CharT) \
    void Mdc_BasicString_PushBack(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        T_CharT ch \
    ) { \
      size_t new_length; \
      size_t new_capacity; \
\
      new_length = str->length_ + 1; \
\
      if (new_length >= str->capacity_) { \
        new_capacity = str->capacity_ * 2; \
\
        Mdc_BasicString_Reserve(T_CharT)(str, new_capacity); \
      } \
\
      Mdc_CharTraits_AssignChar(T_CharT)(&str->c_str_[str->length_], &ch);\
      str->length_ += 1; \
\
      Mdc_CharTraits_AssignChar(T_CharT)( \
          &str->c_str_[str->length_], \
          &Mdc_BasicString_kNullChar(T_CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_RESERVE(T_CharT) \
    void Mdc_BasicString_Reserve(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str, \
        size_t new_capacity \
    ) { \
      T_CharT* realloc_c_str; \
\
      if (new_capacity <= str->capacity_) { \
        return; \
      } \
\
      realloc_c_str = Mdc_realloc( \
          str->c_str_, \
          new_capacity * sizeof(str->c_str_[0]) \
      ); \
\
      if (realloc_c_str == NULL) { \
        return; \
      } \
\
      str->c_str_ = realloc_c_str; \
      str->capacity_ = new_capacity; \
    }


#define MDC_INTERNAL_DEFINE_BASIC_STRING_SHRINK_TO_FIT(T_CharT) \
    void Mdc_BasicString_ShrinkToFit(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str \
    ) { \
      size_t new_cap; \
      T_CharT* realloc_c_str; \
\
      new_cap = str->length_ + 1; \
\
      realloc_c_str = Mdc_realloc( \
          str->c_str_, \
          new_cap * sizeof(str->c_str_[0]) \
      ); \
\
      if (realloc_c_str == NULL) { \
        return; \
      } \
\
      str->c_str_ = realloc_c_str; \
      str->capacity_ = new_cap; \
    }


#define MDC_INTERNAL_DEFINE_BASIC_STRING_SIZE(T_CharT) \
    size_t Mdc_BasicString_Size(T_CharT)( \
        const struct Mdc_BasicString(T_CharT)* str \
    ) { \
      return Mdc_BasicString_Length(T_CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_SWAP(T_CharT) \
    void Mdc_BasicString_Swap(T_CharT)( \
        struct Mdc_BasicString(T_CharT)* str1, \
        struct Mdc_BasicString(T_CharT)* str2 \
    ) { \
      struct Mdc_BasicString(T_CharT) temp; \
\
      temp = *str1; \
      *str1 = *str2; \
      *str2 = temp; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FUNCTIONS(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_EMPTY(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_CHAR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_STR_TAIL(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_SUBSTR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR_TOP(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_COPY(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_MOVE(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_COPY(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_MOVE(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_AT(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_AT_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR_TAIL(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_SUBSTR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR_TOP(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_BACK(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_BACK_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_CAPACITY(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTRS(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTRS(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_CLEAR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_C_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DATA(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DATA_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EMPTY(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_C_STR(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT_CONST(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_LENGTH(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_POP_BACK(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_PUSH_BACK(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_RESERVE(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SHRINK_TO_FIT(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SIZE(T_CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SWAP(T_CharT)

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DEFINE_MACROS_H_ */
