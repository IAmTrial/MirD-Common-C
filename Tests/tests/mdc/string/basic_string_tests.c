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

#include <mdc/string/basic_string.h>

#define HELLO_WORLD_CSTR "Hello world!"
#define HELLO_WORLD_CWSTR L"Hello world!"

static void Mdc_BasicString_AssertInitEmptyDeinit(void) {
  struct Mdc_BasicString string = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  struct Mdc_BasicString* init_string;
  struct Mdc_BasicStringMetadata* init_metadata;

  init_metadata = Mdc_StringMetadata_InitMetadata(&metadata);
  assert(init_metadata == &metadata);

  init_string = Mdc_BasicString_InitEmpty(&string, &metadata);

  assert(init_string == &string);
  assert(Mdc_BasicString_Length(&string) == 0);
  assert(Mdc_BasicString_Length(&string) == Mdc_BasicString_Size(&string));
  assert(*(char*) Mdc_BasicString_AccessConst(&string, 0) == '\0');
  assert(Mdc_BasicString_Empty(&string));

  Mdc_BasicString_Deinit(&string);
}

static void Mdc_BasicString_AssertInitConcat(void) {
  enum {
    kHelloWorldLength = (sizeof(HELLO_WORLD_CSTR)
        / sizeof(HELLO_WORLD_CSTR[0])) - 1
  };

  struct Mdc_BasicString string1 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicString string2 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicString concat_string1 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicString concat_string2 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  const struct Mdc_BasicString* init_concat1;
  const struct Mdc_BasicString* init_concat2;

  Mdc_StringMetadata_InitMetadata(&metadata);

  Mdc_BasicString_InitFromCStr(&string1, &metadata, HELLO_WORLD_CSTR);
  Mdc_BasicString_InitFromCStr(&string2, &metadata, "dog");

  init_concat1 = Mdc_BasicString_InitConcatStrCopyWithCStr(
      &concat_string1,
      &string1,
      "dog"
  );
  assert(init_concat1 == &concat_string1);

  init_concat2 = Mdc_BasicString_InitConcatStrCopyWithCStr(
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
}

static void Mdc_BasicString_AssertAtAndAccess(void) {
  enum {
    kHelloWorldLength = (sizeof(HELLO_WORLD_CSTR)
        / sizeof(HELLO_WORLD_CSTR[0])) - 1
  };

  struct Mdc_BasicString string = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  void* at_result;
  const void* at_const_result;
  void* access_result;
  const void* access_const_result;
  const void* null_term_ptr;

  Mdc_StringMetadata_InitMetadata(&metadata);
  Mdc_BasicString_InitFromCStr(&string, &metadata, HELLO_WORLD_CSTR);

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
}

static void Mdc_BasicString_AssertFrontAndBack(void) {
  struct Mdc_BasicString string = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  void* data_ptr;
  void* front_ptr;
  const void* front_const_ptr;
  void* back_ptr;
  const void* back_const_ptr;

  Mdc_StringMetadata_InitMetadata(&metadata);
  Mdc_BasicString_InitFromCStr(&string, &metadata, HELLO_WORLD_CSTR);

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
}

static void Mdc_BasicString_AssertCompareAndEqual(void) {
  struct Mdc_BasicString string1 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicString string2 = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  Mdc_StringMetadata_InitMetadata(&metadata);
  Mdc_BasicString_InitFromCStr(&string1, &metadata, HELLO_WORLD_CSTR);
  Mdc_BasicString_InitFromCStr(&string2, &metadata, "hello world!");

  assert(Mdc_BasicString_CompareStr(&string1, &string2) < 0);
  assert(!Mdc_BasicString_EqualStr(&string1, &string2));

  *(char*) Mdc_BasicString_At(&string2, 0) = 'H';

  assert(Mdc_BasicString_CompareStr(&string1, &string2) == 0);
  assert(Mdc_BasicString_EqualStr(&string1, &string2));

  *(char*) Mdc_BasicString_At(&string1, 0) = 'h';

  assert(Mdc_BasicString_CompareStr(&string1, &string2) > 0);
  assert(!Mdc_BasicString_EqualStr(&string1, &string2));

  Mdc_BasicString_Deinit(&string2);
  Mdc_BasicString_Deinit(&string1);
}

static void Mdc_BasicString_AssertAppend(void) {
  struct Mdc_BasicString string = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  Mdc_StringMetadata_InitMetadata(&metadata);
  Mdc_BasicString_InitFromCStr(&string, &metadata, HELLO_WORLD_CSTR);

  Mdc_BasicString_AppendCStr(&string, "aaaaa");
  assert(Mdc_BasicString_EqualCStr(&string, "Hello world!aaaaa"));
  assert(Mdc_BasicString_CompareCStr(&string, "Hello world!aaaaa") == 0);

  Mdc_BasicString_Deinit(&string);
}

static void Mdc_BasicString_AssertPushBackAndPopBack(void) {
  struct Mdc_BasicString string = MDC_BASIC_STRING_UNINIT;
  struct Mdc_BasicStringMetadata metadata;

  Mdc_StringMetadata_InitMetadata(&metadata);
  Mdc_BasicString_InitFromCStr(&string, &metadata, HELLO_WORLD_CSTR);

  Mdc_BasicString_PushBack(&string, 'a');
  assert(Mdc_BasicString_EqualCStr(&string, "Hello world!a"));
  assert(Mdc_BasicString_CompareCStr(&string, "Hello world!a") == 0);

  Mdc_BasicString_PopBack(&string);
  assert(Mdc_BasicString_EqualCStr(&string, HELLO_WORLD_CSTR));
  assert(Mdc_BasicString_CompareCStr(&string, HELLO_WORLD_CSTR) == 0);

  Mdc_BasicString_Deinit(&string);
}

void Mdc_BasicString_RunTests(void) {
  Mdc_BasicString_AssertInitEmptyDeinit();
  Mdc_BasicString_AssertInitConcat();
  Mdc_BasicString_AssertAtAndAccess();
  Mdc_BasicString_AssertFrontAndBack();
  Mdc_BasicString_AssertCompareAndEqual();
  Mdc_BasicString_AssertAppend();
  Mdc_BasicString_AssertPushBackAndPopBack();
}
