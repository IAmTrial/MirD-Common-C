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

#include "wide_decoding_tests.hpp"

#include <mdc/std/assert.h>
#include <mdc/wchar_t/wide_decoding.hpp>
#include "wide_example_text/wide_example_text.hpp"

namespace mdc_test {
namespace wide_test {

static void AssertDecodeAscii() {
  ::std::wstring wide_str = ::mdc::wide::DecodeAscii(kAsciiExampleText);

  assert(wide_str == kAsciiExampleTextWide);
}

static void AssertDecodeDefaultMultibyteAscii() {
  ::std::wstring wide_str = ::mdc::wide::DecodeDefaultMultibyte(
      kAsciiExampleText
  );

  assert(wide_str == kAsciiExampleTextWide);
}

static void AssertDecodeUtf8() {
  ::std::wstring wide_str = ::mdc::wide::DecodeUtf8(
      kUtf8ExampleText
  );

  assert(wide_str == kUtf8ExampleTextWide);
}

void WideDecoding_RunTests() {
  AssertDecodeAscii();
  AssertDecodeDefaultMultibyteAscii();
  AssertDecodeUtf8();
}

} // namespace wide_test
} // namespace mdc_test
