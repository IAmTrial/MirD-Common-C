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

#include "wide_decoding_tests.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <mdc/malloc/malloc.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/wide_decoding.h>
#include "example_text/example_text.h"

static void Mdc_WideDecoding_AssertDecodeAscii(void) {
  wchar_t* wide_c_str;
  size_t wide_c_str_len;

  wchar_t* decode_result;

  wide_c_str_len = Mdc_Wide_DecodeAsciiLength(kAsciiExampleText);

  wide_c_str = Mdc_malloc((wide_c_str_len + 1) * sizeof(wide_c_str[0]));
  assert(wide_c_str != NULL);

  decode_result = Mdc_Wide_DecodeAscii(wide_c_str, kAsciiExampleText);
  assert(decode_result == wide_c_str);
  assert(wcscmp(wide_c_str, kAsciiExampleTextWide) == 0);

  Mdc_free(wide_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideDecoding_AssertDecodeDefaultMultibyteAscii(void) {
  wchar_t* wide_c_str;
  size_t wide_c_str_len;

  wchar_t* decode_result;

  wide_c_str_len = Mdc_Wide_DecodeAsciiLength(kAsciiExampleText);

  wide_c_str = Mdc_malloc((wide_c_str_len + 1) * sizeof(wide_c_str[0]));
  assert(wide_c_str != NULL);

  decode_result = Mdc_Wide_DecodeDefaultMultibyte(
      wide_c_str,
      kAsciiExampleText
  );
  assert(decode_result == wide_c_str);
  assert(wcscmp(wide_c_str, kAsciiExampleTextWide) == 0);

  Mdc_free(wide_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_WideDecoding_AssertDecodeUtf8(void) {
  wchar_t* wide_c_str;
  size_t wide_c_str_len;

  wchar_t* decode_result;

  wide_c_str_len = Mdc_Wide_DecodeAsciiLength(kAsciiExampleText);

  wide_c_str = Mdc_malloc((wide_c_str_len + 1) * sizeof(wide_c_str[0]));
  assert(wide_c_str != NULL);

  decode_result = Mdc_Wide_DecodeUtf8(wide_c_str, kUtf8ExampleText);
  assert(decode_result == wide_c_str);
  assert(wcscmp(wide_c_str, kUtf8ExampleTextWide) == 0);

  Mdc_free(wide_c_str);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_WideDecoding_RunTests(void) {
  Mdc_WideDecoding_AssertDecodeAscii();
  Mdc_WideDecoding_AssertDecodeDefaultMultibyteAscii();
  Mdc_WideDecoding_AssertDecodeUtf8();
}
