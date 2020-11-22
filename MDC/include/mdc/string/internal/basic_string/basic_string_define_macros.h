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

#define Mdc_BasicString_kUninit(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __kUninit)

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT_CONST(CharT) \
    static const struct Mdc_BasicString(CharT) \
    Mdc_BasicString_kUninit(CharT) = MDC_INTERNAL_BASIC_STRING_DEINIT;

/**
 * Constants
 */

#define MDC_INTERNAL_DEFINE_BASIC_STRING_K_NPOS(CharT) \
    const size_t Mdc_BasicString_kNpos(CharT) = (size_t) -1;

#define Mdc_BasicString_kNullChar(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __kNullChar)

#define MDC_INTERNAL_DEFINE_K_NULL_CHAR(CharT) \
    const CharT Mdc_BasicString_kNullChar(CharT) = '\0';

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CONSTANTS(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_K_NPOS(CharT) \
    MDC_INTERNAL_DEFINE_K_NULL_CHAR(CharT)

enum {
  kInitialCapacity = 4
};

/**
 * Functions
 */

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_EMPTY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitEmpty(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      str->capacity_ = kInitialCapacity; \
      str->c_str_ = Mdc_malloc(str->capacity_ * sizeof(str->c_str_[0])); \
      if (str->c_str_ == NULL) { \
        *str = Mdc_BasicString_kUninit(CharT); \
        return NULL; \
      } \
\
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[0], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
      str->length_ = 0; \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_CHAR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromChar(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t count, \
        CharT ch \
    ) { \
      str->capacity_ = count + 1; \
      str->c_str_ = Mdc_malloc(str->capacity_ * sizeof(str->c_str_[0])); \
      if (str->c_str_ == NULL) { \
        *str = Mdc_BasicString_kUninit(CharT); \
        return NULL; \
      } \
\
      str->length_ = count; \
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[count], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
      Mdc_CharTraits_AssignCStr(CharT)(str->c_str_, count, ch); \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_STR_TAIL(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitStrTail(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos \
    ) { \
      return Mdc_BasicString_InitSubstr(CharT)(str, \
          src, \
          pos, \
          Mdc_BasicString_kNpos(CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_SUBSTR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitSubstr(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos, \
        size_t count \
    ) { \
      if (count == Mdc_BasicString_kNpos(CharT)) { \
        count = src->length_ - pos; \
      } \
\
      return Mdc_BasicString_InitFromCStrTop(CharT)( \
          str, \
          &str->c_str_[pos], \
          count \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromCStr(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    ) { \
      return Mdc_BasicString_InitFromCStrTop(CharT)( \
          str, \
          c_str, \
          Mdc_CharTraits_LengthCStr(CharT)(c_str) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR_TOP(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitFromCStrTop(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str, \
        size_t count \
    ) { \
      str->capacity_ = count + 1; \
\
      str->c_str_ = Mdc_malloc(str->capacity_ * sizeof(str->c_str_[0])); \
      if (str->c_str_ == NULL) { \
        *str = Mdc_BasicString_kUninit(CharT); \
        return NULL; \
      } \
\
      str->length_ = count; \
      Mdc_CharTraits_CopyNonoverlapCStr(CharT)( \
          str->c_str_, \
          c_str, \
          count \
      ); \
\
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[count], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
\
      return str; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_COPY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitCopy(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    ) { \
      return Mdc_BasicString_InitStrTail(CharT)(dest, src, 0); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_MOVE(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_InitMove(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        struct Mdc_BasicString(CharT)* src \
    ) { \
      *dest = *src; \
      *src = Mdc_BasicString_kUninit(CharT); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT(CharT) \
    void Mdc_BasicString_Deinit(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      if (str->c_str_ != NULL) { \
        Mdc_free(str->c_str_); \
      } \
\
      *str = Mdc_BasicString_kUninit(CharT); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_COPY(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AssignCopy(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    ) { \
      struct Mdc_BasicString(CharT) temp_str; \
      const struct Mdc_BasicString(CharT)* init_temp_str; \
\
      const struct Mdc_BasicString(CharT)* assign_dest; \
\
      if (dest == src) { \
        return dest; \
      } \
\
      init_temp_str = Mdc_BasicString_InitCopy(CharT)(&temp_str, src); \
      if (init_temp_str != &temp_str) { \
        return NULL; \
      } \
\
      assign_dest = Mdc_BasicString_AssignMove(CharT)(dest, &temp_str); \
      if (assign_dest != dest) { \
        Mdc_BasicString_Deinit(CharT)(&temp_str); \
        return NULL; \
      } \
\
      Mdc_BasicString_Deinit(CharT)(&temp_str); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_MOVE(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AssignMove(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        struct Mdc_BasicString(CharT)* src \
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
      *src = Mdc_BasicString_kUninit(CharT); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS(CharT) \
    CharT* Mdc_BasicString_Access(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    ) { \
      return (CharT*) Mdc_BasicString_AccessConst(CharT)(str, pos); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS_CONST(CharT) \
    const CharT* Mdc_BasicString_AccessConst(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    ) { \
      return &str->c_str_[pos]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_AT(CharT) \
    CharT* Mdc_BasicString_At(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    ) { \
      return (CharT*) Mdc_BasicString_AtConst(CharT)(str, pos); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_AT_CONST(CharT) \
    const CharT* Mdc_BasicString_AtConst(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t pos \
    ) { \
      if (pos < 0 || pos >= str->length_) { \
        return NULL; \
      } \
\
      return &str->c_str_[pos]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendStr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src \
    ) { \
      return Mdc_BasicString_AppendStrTail(CharT)( \
          dest, \
          src, \
          0 \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR_TAIL(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendStrTail(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos \
    ) { \
      return Mdc_BasicString_AppendSubstr(CharT)( \
          dest, \
          src, \
          pos, \
          Mdc_BasicString_kNpos(CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_SUBSTR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendSubstr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const struct Mdc_BasicString(CharT)* src, \
        size_t pos, \
        size_t count \
    ) { \
      if (count == Mdc_BasicString_kNpos(CharT)) { \
        count = src->length_; \
      } \
\
      return Mdc_BasicString_AppendCStrTop(CharT)( \
          dest, \
          &src->c_str_[pos], \
          count \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendCStr(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const CharT* src \
    ) { \
      return Mdc_BasicString_AppendCStrTop(CharT)( \
          dest, \
          src, \
          Mdc_CharTraits_LengthCStr(CharT)(src) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR_TOP(CharT) \
    struct Mdc_BasicString(CharT)* Mdc_BasicString_AppendCStrTop(CharT)( \
        struct Mdc_BasicString(CharT)* dest, \
        const CharT* src, \
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
        Mdc_BasicString_Reserve(CharT)(dest, new_capacity); \
\
        if (dest->capacity_ < new_capacity) { \
          return NULL; \
        } \
      } \
\
      Mdc_CharTraits_CopyNonoverlapCStr(CharT)( \
          &dest->c_str_[dest->length_], \
          src, \
          count \
      ); \
\
      Mdc_CharTraits_AssignChar(CharT)( \
          &dest->c_str_[new_length], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
\
      dest->length_ = new_length; \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_BACK(CharT) \
    CharT* Mdc_BasicString_Back(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      return (CharT*) Mdc_BasicString_BackConst(CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_BACK_CONST(CharT) \
    const CharT* Mdc_BasicString_BackConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return &str->c_str_[str->length_ - 1]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CAPACITY(CharT) \
    size_t Mdc_BasicString_Capacity(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return str->capacity_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_STR(CharT) \
  int Mdc_BasicString_CompareStr(CharT)( \
      const struct Mdc_BasicString(CharT)* str1, \
      const struct Mdc_BasicString(CharT)* str2 \
  ) { \
    return Mdc_BasicString_CompareSubstr(CharT)( \
        str1, \
        0, \
        str1->length_, \
        str2 \
    ); \
  }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTR(CharT) \
    int Mdc_BasicString_CompareSubstr(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(CharT)* str2 \
    ) { \
      return Mdc_BasicString_CompareSubstrs(CharT)( \
          str1, \
          pos1, \
          count1, \
          str2, \
          0, \
          Mdc_BasicString_kNpos(CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTRS(CharT) \
    int Mdc_BasicString_CompareSubstrs(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        size_t pos1, \
        size_t count1, \
        const struct Mdc_BasicString(CharT)* str2, \
        size_t pos2, \
        size_t count2 \
    ) { \
      if (count2 == Mdc_BasicString_kNpos(CharT) \
          || count2 > str2->length_ - pos2) { \
        count2 = str2->length_ - pos2; \
      } \
\
      return Mdc_BasicString_CompareCSubstrs(CharT)( \
          str1, \
          pos1, \
          count1, \
          &str2->c_str_[pos2], \
          count2 \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_STR(CharT) \
    int Mdc_BasicString_CompareCStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    ) { \
      return Mdc_BasicString_CompareCSubstr(CharT)( \
          str, \
          0, \
          str->length_, \
          c_str \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTR(CharT) \
    int Mdc_BasicString_CompareCSubstr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const CharT* c_str \
    ) { \
      return Mdc_BasicString_CompareCSubstrs(CharT)( \
          str, \
          pos1, \
          count1, \
          c_str, \
          Mdc_CharTraits_LengthCStr(CharT)(c_str) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTRS(CharT) \
    int Mdc_BasicString_CompareCSubstrs(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        size_t pos1, \
        size_t count1, \
        const CharT* c_str, \
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
      compare_result = Mdc_CharTraits_CompareCStr(CharT)( \
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
        return Mdc_CharTraits_CompareCStr(CharT)( \
            &Mdc_BasicString_kNullChar(CharT), \
            &c_str[compare_length], \
            1 \
        ); \
      } else { \
        return Mdc_CharTraits_CompareCStr(CharT)( \
            &str->c_str_[compare_length], \
            &Mdc_BasicString_kNullChar(CharT), \
            1 \
        ); \
      } \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_CLEAR(CharT) \
    void Mdc_BasicString_Clear(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[0], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
\
      str->length_ = 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_C_STR(CharT) \
    const CharT* Mdc_BasicString_CStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return str->c_str_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DATA(CharT) \
    CharT* Mdc_BasicString_Data(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      return (CharT*) Mdc_BasicString_DataConst(CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_DATA_CONST(CharT) \
    const CharT* Mdc_BasicString_DataConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return Mdc_BasicString_CStr(CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EMPTY(CharT) \
    bool Mdc_BasicString_Empty(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return Mdc_BasicString_Length(CharT)(str) == 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_STR(CharT) \
    bool Mdc_BasicString_EqualStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str1, \
        const struct Mdc_BasicString(CharT)* str2 \
    ) { \
      int compare_result; \
\
      if (str1->length_ != str2->length_) { \
        return false; \
      } \
\
      compare_result = Mdc_CharTraits_CompareCStr(CharT)( \
          str1->c_str_, \
          str2->c_str_, \
          str1->length_ \
      ); \
\
      return (compare_result == 0); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_C_STR(CharT) \
    bool Mdc_BasicString_EqualCStr(CharT)( \
        const struct Mdc_BasicString(CharT)* str, \
        const CharT* c_str \
    ) { \
      int compare_result; \
\
      compare_result = Mdc_CharTraits_CompareCStr(CharT)( \
          str->c_str_, \
          c_str, \
          str->length_ \
      ); \
\
      if (compare_result != 0) { \
        return compare_result; \
      } \
\
      compare_result = Mdc_CharTraits_CompareCStr(CharT)( \
          &Mdc_BasicString_kNullChar(CharT), \
          &c_str[str->length_], \
          1 \
      ); \
\
      return compare_result == 0; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT(CharT) \
    CharT* Mdc_BasicString_Front(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      return (CharT*) Mdc_BasicString_FrontConst(CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT_CONST(CharT) \
    const CharT* Mdc_BasicString_FrontConst(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return &str->c_str_[0]; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_LENGTH(CharT) \
    size_t Mdc_BasicString_Length(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return str->length_; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_POP_BACK(CharT) \
    void Mdc_BasicString_PopBack(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      str->length_ -= 1; \
\
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[str->length_], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_PUSH_BACK(CharT) \
    void Mdc_BasicString_PushBack(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        CharT ch \
    ) { \
      size_t new_length; \
      size_t new_capacity; \
\
      new_length = str->length_ + 1; \
\
      if (new_length >= str->capacity_) { \
        new_capacity = str->capacity_ * 2; \
\
        Mdc_BasicString_Reserve(CharT)(str, new_capacity); \
      } \
\
      Mdc_CharTraits_AssignChar(CharT)(&str->c_str_[str->length_], &ch);\
      str->length_ += 1; \
\
      Mdc_CharTraits_AssignChar(CharT)( \
          &str->c_str_[str->length_], \
          &Mdc_BasicString_kNullChar(CharT) \
      ); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_RESERVE(CharT) \
    void Mdc_BasicString_Reserve(CharT)( \
        struct Mdc_BasicString(CharT)* str, \
        size_t new_capacity \
    ) { \
      CharT* realloc_c_str; \
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


#define MDC_INTERNAL_DEFINE_BASIC_STRING_SHRINK_TO_FIT(CharT) \
    void Mdc_BasicString_ShrinkToFit(CharT)( \
        struct Mdc_BasicString(CharT)* str \
    ) { \
      size_t new_cap; \
      CharT* realloc_c_str; \
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


#define MDC_INTERNAL_DEFINE_BASIC_STRING_SIZE(CharT) \
    size_t Mdc_BasicString_Size(CharT)( \
        const struct Mdc_BasicString(CharT)* str \
    ) { \
      return Mdc_BasicString_Length(CharT)(str); \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_SWAP(CharT) \
    void Mdc_BasicString_Swap(CharT)( \
        struct Mdc_BasicString(CharT)* str1, \
        struct Mdc_BasicString(CharT)* str2 \
    ) { \
      struct Mdc_BasicString(CharT) temp; \
\
      temp = *str1; \
      *str1 = *str2; \
      *str2 = temp; \
    }

#define MDC_INTERNAL_DEFINE_BASIC_STRING_FUNCTIONS(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_EMPTY(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_CHAR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_STR_TAIL(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_SUBSTR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_FROM_C_STR_TOP(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_COPY(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_INIT_MOVE(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DEINIT(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_COPY(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ASSIGN_MOVE(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_ACCESS_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_AT(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_AT_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_STR_TAIL(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_SUBSTR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_APPEND_C_STR_TOP(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_BACK(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_BACK_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_CAPACITY(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_SUBSTRS(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_COMPARE_C_SUBSTRS(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_CLEAR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_C_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DATA(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_DATA_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EMPTY(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_EQUAL_C_STR(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_FRONT_CONST(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_LENGTH(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_POP_BACK(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_PUSH_BACK(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_RESERVE(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SHRINK_TO_FIT(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SIZE(CharT) \
    MDC_INTERNAL_DEFINE_BASIC_STRING_SWAP(CharT)

#endif /* MDC_C_STRING_INTERNAL_BASIC_STRING_BASIC_STRING_DEFINE_MACROS_H_ */
