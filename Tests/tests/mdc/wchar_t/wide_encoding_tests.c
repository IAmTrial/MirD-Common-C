/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2025  Mir Drualga
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

#include "mdc/wchar_t/wide_encoding_tests.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "mdc/malloc/malloc.h"
#include "mdc/std/wchar.h"
#include "mdc/wchar_t/wide_encoding.h"

#include "mdc/wchar_t/wide_example_text/wide_example_text.h"

static void EncodeAscii_EncodesFromWide(void) {
  char* dest;
  size_t dest_length;
  char* encode_result;

  dest_length = Mdc_Wide_EncodeAsciiLength(kAsciiExampleTextWide);
  dest = Mdc_malloc((dest_length + 1) * sizeof(dest[0]));

  encode_result = Mdc_Wide_EncodeAscii(dest, kAsciiExampleTextWide);

  assert(encode_result == dest);
  assert(strcmp(dest, kAsciiExampleText) == 0);

  Mdc_free(dest);
}

static void EncodeDefaultMultibyte_AsciiText_EncodesFromWide(void) {
  char* dest;
  size_t dest_length;
  size_t required_capacity;
  char* encode_result;

  dest_length =
      Mdc_Wide_EncodeDefaultMultibyteLength(kAsciiExampleTextWide);
  required_capacity = (dest_length + 1) * sizeof(dest[0]);
  dest = Mdc_malloc(required_capacity);

  encode_result =
      Mdc_Wide_EncodeDefaultMultibyte(dest, kAsciiExampleTextWide);

  assert(encode_result == dest);
  assert(strcmp(dest, kAsciiExampleText) == 0);

  Mdc_free(dest);
}

static void EncodeUtf8_EncodesFromWide(void) {
  char* dest;
  size_t dest_length;
  char* encode_result;

  dest_length = Mdc_Wide_EncodeUtf8Length(kUtf8ExampleTextWide);
  dest = Mdc_malloc((dest_length + 1) * sizeof(dest[0]));

  encode_result = Mdc_Wide_EncodeUtf8(dest, kUtf8ExampleTextWide);

  assert(encode_result == dest);
  assert(strcmp(dest, kUtf8ExampleText) == 0);

  Mdc_free(dest);
}

void Mdc_WideEncoding_RunTests(void) {
  EncodeAscii_EncodesFromWide();
  EncodeDefaultMultibyte_AsciiText_EncodesFromWide();
  EncodeUtf8_EncodesFromWide();
}
