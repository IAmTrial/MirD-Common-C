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
#include <wchar.h>

#include <mdc/wchar_t/wide_encoding.h>
#include "example_text/example_text.h"

static void Mdc_WideEncoding_AssertEncodeAscii(void) {
  char* ascii_str;

  ascii_str = Mdc_Wide_EncodeAscii(kAsciiExampleTextWide);
  assert(strcmp(ascii_str, kAsciiExampleText) == 0);

  free(ascii_str);
}

static void Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii(void) {
  char* multibyte_ascii_str;

  multibyte_ascii_str = Mdc_Wide_EncodeDefaultMultibyte(
      kAsciiExampleTextWide
  );
  assert(strcmp(multibyte_ascii_str, kAsciiExampleText) == 0);

  free(multibyte_ascii_str);
}

static void Mdc_WideEncoding_AssertEncodeUtf8(void) {
  char* utf8_str;

  utf8_str = Mdc_Wide_EncodeUtf8(kUtf8ExampleTextWide);
  assert(strcmp(utf8_str, kUtf8ExampleText) == 0);

  free(utf8_str);
}

void Mdc_WideEncoding_RunTests(void) {
  Mdc_WideEncoding_AssertEncodeAscii();
  Mdc_WideEncoding_AssertEncodeDefaultMultibyteAscii();
  Mdc_WideEncoding_AssertEncodeUtf8();
}
