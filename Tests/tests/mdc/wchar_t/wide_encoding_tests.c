/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2021  Mir Drualga
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
#include <mdc/wchar_t/wide_encoding.h>
#include "wide_example_text/wide_example_text.h"

static void Mdc_WideEncoding_AssertEncodeAscii(void) {
  char* ascii_c_str;
  size_t ascii_c_str_len;

  char* encode_result;

  ascii_c_str_len = Mdc_Wide_EncodeAsciiLength(kAsciiExampleTextWide);

  ascii_c_str = Mdc_malloc((ascii_c_str_len + 1) * sizeof(ascii_c_str[0]));
  assert(ascii_c_str != NULL);

  encode_result = Mdc_Wide_EncodeAscii(ascii_c_str, kAsciiExampleTextWide);
  assert(encode_result == ascii_c_str);
  assert(strcmp(ascii_c_str, kAsciiExampleText) == 0);

  Mdc_free(ascii_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii(void) {
  char* multibyte_ascii_c_str;
  size_t multibyte_ascii_c_str_len;

  char* encode_result;

  multibyte_ascii_c_str_len = Mdc_Wide_EncodeDefaultMultibyteLength(
      kAsciiExampleTextWide
  );

  multibyte_ascii_c_str = Mdc_malloc(
      (multibyte_ascii_c_str_len + 1) * sizeof(multibyte_ascii_c_str[0])
  );
  assert(multibyte_ascii_c_str != NULL);

  encode_result = Mdc_Wide_EncodeDefaultMultibyte(
      multibyte_ascii_c_str,
      kAsciiExampleTextWide
  );
  assert(encode_result == multibyte_ascii_c_str);
  assert(strcmp(multibyte_ascii_c_str, kAsciiExampleText) == 0);

  Mdc_free(multibyte_ascii_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideEncoding_AssertEncodeUtf8(void) {
  char* utf8_c_str;
  size_t utf8_c_str_len;

  char* encode_result;

  utf8_c_str_len = Mdc_Wide_EncodeUtf8Length(kUtf8ExampleTextWide);

  utf8_c_str = Mdc_malloc((utf8_c_str_len + 1) * sizeof(utf8_c_str[0]));
  assert(utf8_c_str != NULL);

  encode_result = Mdc_Wide_EncodeUtf8(utf8_c_str, kUtf8ExampleTextWide);
  assert(encode_result == utf8_c_str);
  assert(strcmp(utf8_c_str, kUtf8ExampleText) == 0);

  Mdc_free(utf8_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_WideEncoding_RunTests(void) {
  Mdc_WideEncoding_AssertEncodeAscii();
  Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii();
  Mdc_WideEncoding_AssertEncodeUtf8();
}
