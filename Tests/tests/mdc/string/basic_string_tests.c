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

#include "basic_string_tests.h"

#include <assert.h>
#include <stdio.h>

#include <mdc/macro/concat_macro.h>
#include <mdc/malloc/malloc.h>
#include <mdc/string/string.h>

enum {
  kHelloWorld,
  kDog,
  k5a,
  kHelloWorld5a,
  kHelloWorlda,
  khelloworld
};

static const char* const kTestCStrings[] = {
  "Hello world!",
  "dog",
  "aaaaa",
  "Hello world!aaaaa",
  "Hello world!a",
  "hello world!"
};

static const wchar_t* const kTestCWStrings[] = {
  L"Hello world!",
  L"dog",
  L"aaaaa",
  L"Hello world!aaaaa",
  L"Hello world!a",
  L"hello world!"
};

/**
 * Names
 */

#define Mdc_BasicString_RunTest(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __RunTest)

#define Mdc_BasicString_AssertInitEmptyAndDeinit(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertInitEmptyAndDeinit)

#define Mdc_BasicString_AssertAtAndAccess(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertAtAndAccess)

#define Mdc_BasicString_AssertFrontAndBack(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertFrontAndBack)

#define Mdc_BasicString_AssertCompareAndEqual(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertCompareAndEqual)

#define Mdc_BasicString_AssertAppend(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertAppend)

#define Mdc_BasicString_AssertPushBackAndPopBack(CharT) \
    MDC_MACRO_CONCAT(Mdc_BasicString(CharT), __AssertPushBackAndPopBack)

/**
 * Defines
 */

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_INIT_EMPTY_AND_DEINIT(CharT) \
    static void Mdc_BasicString_AssertInitEmptyAndDeinit(CharT)( \
        const CharT** c_strs \
    ) { \
      struct Mdc_BasicString(CharT) str; \
\
      str = Mdc_BasicString_InitEmpty(CharT)(); \
\
      assert(Mdc_BasicString_Length(CharT)(&str) == 0); \
      assert(Mdc_BasicString_Length(CharT)(&str) \
          == Mdc_BasicString_Size(CharT)(&str)); \
      assert(*Mdc_BasicString_FrontConst(CharT)(&str) == '\0'); \
      assert(Mdc_BasicString_Empty(CharT)(&str)); \
\
      Mdc_BasicString_Deinit(CharT)(&str); \
\
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_AT_AND_ACCESS(CharT) \
    static void Mdc_BasicString_AssertAtAndAccess(CharT)( \
        const CharT** c_strs \
    ) { \
      enum { \
        kHelloWorldLength = 12 \
      }; \
\
      struct Mdc_BasicString(CharT) str; \
\
      CharT* at_result; \
      const CharT* at_const_result; \
      CharT* access_result; \
      const CharT* access_const_result; \
      const CharT* null_term_ptr; \
\
      str = Mdc_BasicString_InitFromCStr(CharT)( \
          c_strs[kHelloWorld] \
      ); \
\
      at_result = Mdc_BasicString_At(CharT)(&str, 3); \
      at_const_result = Mdc_BasicString_AtConst(CharT)(&str, 3); \
      access_result = Mdc_BasicString_Access(CharT)(&str, 3); \
      access_const_result = Mdc_BasicString_AccessConst(CharT)(&str, 3); \
\
      assert(*at_result == 'l'); \
      assert(at_result == at_const_result); \
      assert(at_const_result == access_result); \
      assert(access_result == access_const_result); \
\
      assert(Mdc_BasicString_Length(CharT)(&str) == kHelloWorldLength); \
      assert(Mdc_BasicString_Length(CharT)(&str) \
          == Mdc_BasicString_Size(CharT)(&str)); \
\
      *at_result = '2'; \
      assert(*at_result == '2'); \
\
      null_term_ptr = Mdc_BasicString_AccessConst(CharT)( \
          &str, \
          kHelloWorldLength \
      ); \
\
      assert(*null_term_ptr == '\0'); \
      assert(!Mdc_BasicString_Empty(CharT)(&str)); \
\
      Mdc_BasicString_Deinit(CharT)(&str); \
\
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_FRONT_AND_BACK(CharT) \
    static void Mdc_BasicString_AssertFrontAndBack(CharT)( \
        const CharT** c_strs \
    ) { \
      struct Mdc_BasicString(CharT) str; \
    \
      CharT* data_ptr; \
      CharT* front_ptr; \
      const CharT* front_const_ptr; \
      CharT* back_ptr; \
      const CharT* back_const_ptr; \
    \
      str = Mdc_BasicString_InitFromCStr(CharT)(c_strs[kHelloWorld]); \
    \
      data_ptr = Mdc_BasicString_Data(CharT)(&str); \
    \
      back_ptr = Mdc_BasicString_Back(CharT)(&str); \
      back_const_ptr = Mdc_BasicString_BackConst(CharT)(&str); \
    \
      front_ptr = Mdc_BasicString_Front(CharT)(&str); \
      front_const_ptr = Mdc_BasicString_FrontConst(CharT)(&str); \
    \
      assert(data_ptr == front_ptr); \
      assert(front_ptr == front_const_ptr); \
      assert(*front_ptr == 'H'); \
    \
      assert(back_ptr == back_const_ptr); \
      assert(*back_ptr == '!'); \
    \
      Mdc_BasicString_Deinit(CharT)(&str); \
    \
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_COMPARE_AND_EQUAL(CharT) \
    static void Mdc_BasicString_AssertCompareAndEqual(CharT)( \
        const CharT** c_strs \
    ) { \
      struct Mdc_BasicString(CharT) str1; \
      struct Mdc_BasicString(CharT) str2; \
\
      CharT* str1_data; \
      CharT* str2_data; \
\
      str1 = Mdc_BasicString_InitFromCStr(CharT)(c_strs[kHelloWorld]); \
      str2 = Mdc_BasicString_InitFromCStr(CharT)(c_strs[khelloworld]); \
\
      str1_data = Mdc_BasicString_Data(CharT)(&str1); \
      str2_data = Mdc_BasicString_Data(CharT)(&str2); \
\
      assert(Mdc_BasicString_CompareStr(CharT)(&str1, &str2) < 0); \
      assert(!Mdc_BasicString_EqualStr(CharT)(&str1, &str2)); \
\
      Mdc_CharTraits_AssignCStr(CharT)(str2_data, 1, 'H'); \
\
      assert(Mdc_BasicString_CompareStr(CharT)(&str1, &str2) == 0); \
      assert(Mdc_BasicString_EqualStr(CharT)(&str1, &str2)); \
\
      Mdc_CharTraits_AssignCStr(CharT)(str1_data, 1, 'h'); \
\
      assert(Mdc_BasicString_CompareStr(CharT)(&str1, &str2) > 0); \
      assert(!Mdc_BasicString_EqualStr(CharT)(&str1, &str2)); \
\
      Mdc_BasicString_Deinit(CharT)(&str2); \
      Mdc_BasicString_Deinit(CharT)(&str1); \
\
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_APPEND(CharT) \
    static void Mdc_BasicString_AssertAppend(CharT)( \
        const CharT** c_strs \
    ) { \
      struct Mdc_BasicString(CharT) str; \
\
      int compare_result; \
\
      str = Mdc_BasicString_InitFromCStr(CharT)(c_strs[kHelloWorld]); \
\
      Mdc_BasicString_AppendCStr(CharT)(&str, c_strs[k5a]); \
      assert(Mdc_BasicString_EqualCStr(CharT)( \
          &str, \
          c_strs[kHelloWorld5a]) \
      ); \
\
      compare_result = Mdc_BasicString_CompareCStr(CharT)( \
          &str, \
          c_strs[kHelloWorld5a] \
      ); \
\
      assert(compare_result == 0); \
\
      Mdc_BasicString_Deinit(CharT)(&str); \
\
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_PUSH_BACK_AND_POP_BACK(CharT) \
    static void Mdc_BasicString_AssertPushBackAndPopBack(CharT)( \
        const CharT** c_strs \
    ) { \
      struct Mdc_BasicString(CharT) str; \
\
      int compare_result; \
\
      str = Mdc_BasicString_InitFromCStr(CharT)(c_strs[kHelloWorld]); \
\
      Mdc_BasicString_PushBack(CharT)(&str, 'a'); \
      assert(Mdc_BasicString_EqualCStr(CharT)(&str, c_strs[kHelloWorlda])); \
\
      compare_result = Mdc_BasicString_CompareCStr(CharT)( \
          &str, \
          c_strs[kHelloWorlda] \
      ); \
      assert(compare_result == 0); \
\
      Mdc_BasicString_PopBack(CharT)(&str); \
      assert(Mdc_BasicString_EqualCStr(CharT)(&str, c_strs[kHelloWorld])); \
\
      compare_result = Mdc_BasicString_CompareCStr(CharT)( \
          &str, \
          c_strs[kHelloWorld] \
      ); \
      assert(compare_result == 0); \
\
      Mdc_BasicString_Deinit(CharT)(&str); \
\
      assert(Mdc_GetMallocDifference() == 0); \
    }

#define MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_FUNCTIONS(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_INIT_EMPTY_AND_DEINIT(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_AT_AND_ACCESS(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_FRONT_AND_BACK(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_COMPARE_AND_EQUAL(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_APPEND(CharT) \
    MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_PUSH_BACK_AND_POP_BACK(CharT)

#define MDC_TESTS_DEFINE_BASIC_STRING_RUN_TEST(CharT, c_strs) \
    static void Mdc_BasicString_RunTest(CharT)(void) { \
        Mdc_BasicString_AssertInitEmptyAndDeinit(CharT)(c_strs); \
        Mdc_BasicString_AssertAtAndAccess(CharT)(c_strs); \
        Mdc_BasicString_AssertFrontAndBack(CharT)(c_strs); \
        Mdc_BasicString_AssertCompareAndEqual(CharT)(c_strs); \
        Mdc_BasicString_AssertAppend(CharT)(c_strs); \
        Mdc_BasicString_AssertPushBackAndPopBack(CharT)(c_strs); \
    }

MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_FUNCTIONS(Mdc_Char)
MDC_TESTS_DEFINE_BASIC_STRING_ASSERT_FUNCTIONS(Mdc_WChar)

MDC_TESTS_DEFINE_BASIC_STRING_RUN_TEST(Mdc_Char, kTestCStrings)
MDC_TESTS_DEFINE_BASIC_STRING_RUN_TEST(Mdc_WChar, kTestCWStrings)

void Mdc_BasicString_RunTests(void) {
  Mdc_BasicString_RunTest(Mdc_Char)();
  Mdc_BasicString_RunTest(Mdc_WChar)();
}
