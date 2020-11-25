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

#include "path_windows_tests.h"

#include <stddef.h>
#include <stdio.h>

#include <mdc/filesystem/current_executable_path.h>
#include <mdc/filesystem/filesystem.h>
#include <mdc/std/assert.h>
#include <mdc/malloc/malloc.h>
#include <mdc/string/string.h>

static void Mdc_Fs_Path_AssertGetCurrentExecutablePath(void) {
  struct Mdc_Fs_Path current_executable_path;
  struct Mdc_Fs_Path* init_current_executable_path;

  init_current_executable_path = Mdc_Fs_GetCurrentExecutablePath(
      &current_executable_path
  );

  assert(init_current_executable_path == &current_executable_path);
  assert(!Mdc_Fs_Path_Empty(&current_executable_path));

  Mdc_Fs_Path_Deinit(&current_executable_path);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Fs_CurrentExecutablePath_RunTests(void) {
  Mdc_Fs_Path_AssertGetCurrentExecutablePath();
}
