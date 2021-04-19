/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021  Mir Drualga
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

#include "vs_fixed_file_info_tests.hpp"

#include <windows.h>

#include <mdc/std/assert.h>
#include <mdc/windows/vs_fixed_file_info.hpp>

namespace mdc_test {
namespace windows_test {
namespace {

static void Vs_FixedFileInfo_AssertFromFileVersion() {
  static const ::mdc::vs::FixedMajorMinorVersion kExpectedFileVersion(
      0xDEAD, 0xBEEF, 0x1CAB, 0xECEA
  );

  ::VS_FIXEDFILEINFO fixed_file_info;
  fixed_file_info.dwFileVersionMS = 0xDEADBEEF;
  fixed_file_info.dwFileVersionLS = 0x1CABECEA;

  ::mdc::vs::FixedMajorMinorVersion actual_file_version =
      ::mdc::vs::FixedMajorMinorVersion::FromFileVersion(fixed_file_info);

  assert(kExpectedFileVersion == actual_file_version);
}

static void Vs_FixedFileInfo_AssertFromProductVersion() {
  static const ::mdc::vs::FixedMajorMinorVersion kExpectedProductVersion(
      0x1FAC, 0xADE1, 0x2D1A, 0xB102
  );

  ::VS_FIXEDFILEINFO fixed_file_info;
  fixed_file_info.dwProductVersionMS = 0x1FACADE1;
  fixed_file_info.dwProductVersionLS = 0x2D1AB102;

  ::mdc::vs::FixedMajorMinorVersion actual_product_version =
      ::mdc::vs::FixedMajorMinorVersion::FromProductVersion(fixed_file_info);

  assert(kExpectedProductVersion == actual_product_version);
}

} // namespace

void Vs_FixedFileInfo_RunTests() {
  Vs_FixedFileInfo_AssertFromFileVersion();
  Vs_FixedFileInfo_AssertFromProductVersion();
}

} // namespace windows_test
} // namespace mdc_test
