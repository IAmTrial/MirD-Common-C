/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2022  Mir Drualga
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
#include <stddef.h>
#include <stdio.h>
#include <mdc/malloc/malloc.h>
#include <mdc/std/wchar.h>
#include <mdc/wchar_t/filew.h>

void Mdc_FileW_AssertFileW(void) {
  enum {
    kFileLength = sizeof(__FILEW__) / sizeof(__FILEW__[0])
  };

  size_t i;

  const char* file;
  const wchar_t* filew;

  file = __FILE__;
  filew = __FILEW__;

  for (i = 0; i < kFileLength; i += 1) {
    if (file[i] > 127 && filew[i] > 127) {
      continue;
    }

    if (file[i] != filew[i]) {
      printf("%u: %d == %d \n", i, file[i], filew[i]);
      assert(file[i] == filew[i]);
    }
  }

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_FileW_RunTests(void) {
  Mdc_FileW_AssertFileW();
}
