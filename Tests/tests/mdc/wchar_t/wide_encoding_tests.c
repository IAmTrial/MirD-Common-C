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

#include "wide_encoding_tests.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <mdc/malloc/malloc.h>
#include <mdc/std/wchar.h>
#include <mdc/string/basic_string.h>
#include <mdc/wchar_t/wide_encoding.h>
#include "example_text/example_text.h"

static void Mdc_WideEncoding_AssertEncodeAscii(void) {
  struct Mdc_BasicString ascii_str;
  struct Mdc_BasicString* init_ascii_str;

  init_ascii_str = Mdc_Wide_EncodeAscii(&ascii_str, kAsciiExampleTextWide);
  assert(init_ascii_str == &ascii_str);
  assert(Mdc_BasicString_CompareCStr(&ascii_str, kAsciiExampleText) == 0);

  Mdc_BasicString_Deinit(&ascii_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii(void) {
  struct Mdc_BasicString multibyte_ascii_str;
  struct Mdc_BasicString* init_multibyte_ascii_str;

  int compare_result;

  init_multibyte_ascii_str = Mdc_Wide_EncodeDefaultMultibyte(
      &multibyte_ascii_str,
      kAsciiExampleTextWide
  );
  assert(init_multibyte_ascii_str == &multibyte_ascii_str);

  compare_result = Mdc_BasicString_CompareCStr(
      &multibyte_ascii_str,
      kAsciiExampleText
  );
  assert(compare_result == 0);

  Mdc_BasicString_Deinit(&multibyte_ascii_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideEncoding_AssertEncodeUtf8(void) {
  struct Mdc_BasicString utf8_str;
  struct Mdc_BasicString* init_utf8_str;

  init_utf8_str = Mdc_Wide_EncodeUtf8(&utf8_str, kUtf8ExampleTextWide);
  assert(init_utf8_str == &utf8_str);
  assert(Mdc_BasicString_CompareCStr(&utf8_str, kUtf8ExampleText) == 0);

  Mdc_BasicString_Deinit(&utf8_str);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_WideEncoding_RunTests(void) {
  Mdc_WideEncoding_AssertEncodeAscii();
  Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii();
  Mdc_WideEncoding_AssertEncodeUtf8();
}
