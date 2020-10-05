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

#include <mdc/malloc/malloc.h>
#include <mdc/string/basic_string.h>

enum {
  kHelloWorld,
  kDog,
  k5a,
  kHelloWorld5a,
  kHelloWorlda,
  khelloworld
};

static const char* kTestCStrings[] = {
  "Hello world!",
  "dog",
  "aaaaa",
  "Hello world!aaaaa",
  "Hello world!a",
  "hello world!"
};

static const wchar_t* kTestCWStrings[] = {
  L"Hello world!",
  L"dog",
  L"aaaaa",
  L"Hello world!aaaaa",
  L"Hello world!a",
  L"hello world!"
};

#if UNICODE

#define kTestCTStrings kTestCWStrings

#else

#define kTestCTStrings kTestCStrings

#endif

static void Mdc_BasicString_AssertInitEmptyDeinit(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string;
  struct Mdc_BasicString* init_string;

  init_string = Mdc_BasicString_InitEmpty(&string, char_traits);

  assert(init_string == &string);
  assert(Mdc_BasicString_Length(&string) == 0);
  assert(Mdc_BasicString_Length(&string) == Mdc_BasicString_Size(&string));
  assert(*(char*) Mdc_BasicString_AccessConst(&string, 0) == '\0');
  assert(Mdc_BasicString_Empty(&string));

  Mdc_BasicString_Deinit(&string);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertInitConcat(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string1;
  struct Mdc_BasicString string2;
  struct Mdc_BasicString concat_string1;
  struct Mdc_BasicString concat_string2;

  const struct Mdc_BasicString* init_concat1;
  const struct Mdc_BasicString* init_concat2;

  Mdc_BasicString_InitFromCStr(&string1, char_traits, c_strings[kHelloWorld]);
  Mdc_BasicString_InitFromCStr(&string2, char_traits, c_strings[kDog]);

  init_concat1 = Mdc_BasicString_ConcatStrCopyWithCStr(
      &concat_string1,
      &string1,
      c_strings[1]
  );
  assert(init_concat1 == &concat_string1);

  init_concat2 = Mdc_BasicString_ConcatStrCopyWithCStr(
      &concat_string2,
      &string1,
      &string2
  );
  assert(init_concat2 == &concat_string2);

  Mdc_BasicString_EqualStr(&concat_string1, &concat_string2);

  Mdc_BasicString_Deinit(&concat_string2);
  Mdc_BasicString_Deinit(&concat_string1);
  Mdc_BasicString_Deinit(&string2);
  Mdc_BasicString_Deinit(&string1);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertAtAndAccess(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  enum {
    kHelloWorldLength = 12
  };

  struct Mdc_BasicString string;

  void* at_result;
  const void* at_const_result;
  void* access_result;
  const void* access_const_result;
  const void* null_term_ptr;

  Mdc_BasicString_InitFromCStr(&string, char_traits, c_strings[kHelloWorld]);

  at_result = Mdc_BasicString_At(&string, 3);
  at_const_result = Mdc_BasicString_AtConst(&string, 3);
  access_result = Mdc_BasicString_Access(&string, 3);
  access_const_result = Mdc_BasicString_AccessConst(&string, 3);

  assert(*(char*) at_result == 'l');
  assert(at_result == at_const_result);
  assert(at_const_result == access_result);
  assert(access_result == access_const_result);

  assert(Mdc_BasicString_Length(&string) == kHelloWorldLength);
  assert(Mdc_BasicString_Length(&string) == Mdc_BasicString_Size(&string));

  *(char*) at_result = '2';
  assert(*(char*) at_result == '2');

  null_term_ptr = Mdc_BasicString_AccessConst(&string, kHelloWorldLength);
  assert(*(char*) null_term_ptr == '\0');
  assert(!Mdc_BasicString_Empty(&string));

  Mdc_BasicString_Deinit(&string);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertFrontAndBack(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string;

  void* data_ptr;
  void* front_ptr;
  const void* front_const_ptr;
  void* back_ptr;
  const void* back_const_ptr;

  Mdc_BasicString_InitFromCStr(&string, char_traits, c_strings[kHelloWorld]);

  data_ptr = Mdc_BasicString_Data(&string);

  back_ptr = Mdc_BasicString_Back(&string);
  back_const_ptr = Mdc_BasicString_BackConst(&string);

  front_ptr = Mdc_BasicString_Front(&string);
  front_const_ptr = Mdc_BasicString_FrontConst(&string);

  assert(data_ptr == front_ptr);
  assert(front_ptr == front_const_ptr);
  assert(*(char*) front_ptr == 'H');

  assert(back_ptr == back_const_ptr);
  assert(*(char*) back_ptr == '!');

  Mdc_BasicString_Deinit(&string);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertCompareAndEqual(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string1;
  struct Mdc_BasicString string2;

  void* string1_data;
  void* string2_data;

  Mdc_BasicString_InitFromCStr(&string1, char_traits, c_strings[kHelloWorld]);
  Mdc_BasicString_InitFromCStr(&string2, char_traits, c_strings[khelloworld]);

  string1_data = Mdc_BasicString_Data(&string1);
  string2_data = Mdc_BasicString_Data(&string2);

  assert(Mdc_BasicString_CompareStr(&string1, &string2) < 0);
  assert(!Mdc_BasicString_EqualStr(&string1, &string2));

  char_traits->functions.assign_str(string2_data, 1, 'H');

  assert(Mdc_BasicString_CompareStr(&string1, &string2) == 0);
  assert(Mdc_BasicString_EqualStr(&string1, &string2));

  char_traits->functions.assign_str(string1_data, 1, 'h');

  assert(Mdc_BasicString_CompareStr(&string1, &string2) > 0);
  assert(!Mdc_BasicString_EqualStr(&string1, &string2));

  Mdc_BasicString_Deinit(&string2);
  Mdc_BasicString_Deinit(&string1);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertAppend(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string;

  Mdc_BasicString_InitFromCStr(&string, char_traits, c_strings[kHelloWorld]);

  Mdc_BasicString_AppendCStr(&string, c_strings[k5a]);
  assert(Mdc_BasicString_EqualCStr(&string, c_strings[kHelloWorld5a]));
  assert(Mdc_BasicString_CompareCStr(&string, c_strings[kHelloWorld5a]) == 0);

  Mdc_BasicString_Deinit(&string);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_BasicString_AssertPushBackAndPopBack(
    const struct Mdc_CharTraits* char_traits,
    const void** c_strings
) {
  struct Mdc_BasicString string;

  Mdc_BasicString_InitFromCStr(&string, char_traits, c_strings[kHelloWorld]);

  Mdc_BasicString_PushBack(&string, 'a');
  assert(Mdc_BasicString_EqualCStr(&string, c_strings[kHelloWorlda]));
  assert(Mdc_BasicString_CompareCStr(&string, c_strings[kHelloWorlda]) == 0);

  Mdc_BasicString_PopBack(&string);
  assert(Mdc_BasicString_EqualCStr(&string, c_strings[kHelloWorld]));
  assert(Mdc_BasicString_CompareCStr(&string, c_strings[kHelloWorld]) == 0);

  Mdc_BasicString_Deinit(&string);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_BasicString_RunTests(void) {
  enum {
    kStringSpecializationCount = 3
  };

  struct {
    const struct Mdc_CharTraits* char_traits;
    const void** c_strings;
  } test_args[kStringSpecializationCount];

  size_t i;

  test_args[0].char_traits = Mdc_CharTraitsChar_GetCharTraits();
  test_args[0].c_strings = kTestCStrings;

  test_args[1].char_traits = Mdc_CharTraitsWChar_GetCharTraits();
  test_args[1].c_strings = kTestCWStrings;

  test_args[2].char_traits = Mdc_CharTraitsTChar_GetCharTraits();
  test_args[2].c_strings = kTestCTStrings;

  for (i = 0; i < kStringSpecializationCount; i += 1) {
    Mdc_BasicString_AssertInitEmptyDeinit(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertInitConcat(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertAtAndAccess(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertFrontAndBack(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertCompareAndEqual(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertAppend(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
    Mdc_BasicString_AssertPushBackAndPopBack(
        test_args[i].char_traits,
        test_args[i].c_strings
    );
  }
}
