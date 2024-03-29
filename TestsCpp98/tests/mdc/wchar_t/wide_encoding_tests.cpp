/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021-2022  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C++98.
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

#include "wide_encoding_tests.hpp"

#include <mdc/std/assert.h>
#include <mdc/wchar_t/wide_encoding.hpp>
#include "wide_example_text/wide_example_text.hpp"

namespace mdc_test {
namespace wide_test {

static void AssertEncodeAscii() {
  ::std::string ascii_str = ::mdc::wide::EncodeAscii(kAsciiExampleTextWide);

  assert(ascii_str == kAsciiExampleText);
}

static void AssertEncodeDefaultMultibyteAscii() {
  ::std::string multibyte_ascii_str = ::mdc::wide::EncodeDefaultMultibyte(
      kAsciiExampleTextWide
  );

  assert(multibyte_ascii_str == kAsciiExampleText);
}

static void AssertEncodeUtf8() {
  ::std::string utf8_str = ::mdc::wide::EncodeUtf8(
      kUtf8ExampleTextWide
  );

  assert(utf8_str == kUtf8ExampleText);
}

void WideEncoding_RunTests() {
  AssertEncodeAscii();
  AssertEncodeDefaultMultibyteAscii();
  AssertEncodeUtf8();
}

} // namespace wide_test
} // namespace mdc_test
