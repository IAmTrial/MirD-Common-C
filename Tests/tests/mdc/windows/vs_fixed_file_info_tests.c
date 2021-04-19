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

#include "vs_fixed_file_info_tests.h"

#include <assert.h>
#include <windows.h>

#include <mdc/malloc/malloc.h>
#include <mdc/windows/vs_fixed_file_info.h>

static void Mdc_Vs_FixedFileInfo_AssertGetFileVersion(void) {
  static const struct Mdc_Vs_FixedMajorMinorVersion kExpectedFileVersion = {
      0xDEAD, 0xBEEF, 0x1CAB, 0xECEA
  };

  VS_FIXEDFILEINFO fixed_file_info;
  struct Mdc_Vs_FixedMajorMinorVersion actual_file_version;

  int compare_result;

  fixed_file_info.dwFileVersionMS = 0xDEADBEEF;
  fixed_file_info.dwFileVersionLS = 0x1CABECEA;

  actual_file_version = VS_FIXEDFILEINFO_GetFileVersion(&fixed_file_info);
  compare_result = Mdc_Vs_FixedMajorMinorVersion_Compare(
      &kExpectedFileVersion,
      &actual_file_version
  );

  assert(compare_result == 0);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vs_FixedFileInfo_AssertGetProductVersion(void) {
  static const struct Mdc_Vs_FixedMajorMinorVersion
  kExpectedProductVersion = {
      0x1FAC, 0xADE1, 0x2D1A, 0xB102
  };

  VS_FIXEDFILEINFO fixed_file_info;
  struct Mdc_Vs_FixedMajorMinorVersion actual_product_version;

  int compare_result;

  fixed_file_info.dwProductVersionMS = 0x1FACADE1;
  fixed_file_info.dwProductVersionLS = 0x2D1AB102;

  actual_product_version = VS_FIXEDFILEINFO_GetProductVersion(
      &fixed_file_info
  );

  compare_result = Mdc_Vs_FixedMajorMinorVersion_Compare(
      &kExpectedProductVersion,
      &actual_product_version
  );

  assert(compare_result == 0);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Vs_FixedFileInfo_RunTests(void) {
  Mdc_Vs_FixedFileInfo_AssertGetFileVersion();
  Mdc_Vs_FixedFileInfo_AssertGetProductVersion();
}
