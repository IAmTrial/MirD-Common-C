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

#include "mdc/wchar_t/wide_decoding_tests.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "mdc/malloc/malloc.h"
#include "mdc/std/wchar.h"
#include "mdc/wchar_t/wide_decoding.h"

#include "mdc/wchar_t/wide_example_text/wide_example_text.h"

static void DecodeAscii_DecodesToWide(void) {
  wchar_t* dest;
  size_t dest_length;
  wchar_t* decode_result;

  dest_length = Mdc_Wide_DecodeAsciiLength(kAsciiExampleText);
  dest = Mdc_malloc((dest_length + 1) * sizeof(dest[0]));

  decode_result = Mdc_Wide_DecodeAscii(dest, kAsciiExampleText);

  assert(decode_result == dest);
  assert(wcscmp(dest, kAsciiExampleTextWide) == 0);

  Mdc_free(dest);
}

static void DecodeDefaultMultiByte_AsciiText_DecodesToWide(void) {
  wchar_t* dest;
  size_t dest_length;
  wchar_t* decode_result;

  dest_length = Mdc_Wide_DecodeAsciiLength(kAsciiExampleText);
  dest = Mdc_malloc((dest_length + 1) * sizeof(dest[0]));

  decode_result = Mdc_Wide_DecodeDefaultMultibyte(dest, kAsciiExampleText);

  assert(decode_result == dest);
  assert(wcscmp(dest, kAsciiExampleTextWide) == 0);

  Mdc_free(dest);
}

static void DecodeUtf8_DecodesToWide(void) {
  wchar_t* dest;
  size_t dest_length;
  wchar_t* decode_result;

  dest_length = Mdc_Wide_DecodeUtf8Length(kUtf8ExampleText);
  dest = Mdc_malloc((dest_length + 1) * sizeof(dest[0]));

  decode_result = Mdc_Wide_DecodeUtf8(dest, kUtf8ExampleText);

  assert(decode_result == dest);
  assert(wcscmp(dest, kUtf8ExampleTextWide) == 0);

  Mdc_free(dest);
}

void Mdc_WideDecoding_RunTests(void) {
  DecodeAscii_DecodesToWide();
  DecodeDefaultMultiByte_AsciiText_DecodesToWide();
  DecodeUtf8_DecodesToWide();
}
