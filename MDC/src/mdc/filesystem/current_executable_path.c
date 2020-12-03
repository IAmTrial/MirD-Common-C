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

#include "../../../include/mdc/filesystem/current_executable_path.h"

#include "../../../include/mdc/malloc/malloc.h"
#include "../../../include/mdc/std/threads.h"
#include "../../../include/mdc/filesystem/filesystem.h"

#if defined(_WIN32) || defined(_WIN64)

struct Mdc_Fs_Path Mdc_Fs_GetCurrentExecutablePath(void) {
  enum {
    kPathInitialCapacity = 8
  };

  void* realloc_result;

  struct Mdc_Fs_Path current_executable_path;
  wchar_t* current_executable_path_cstr;
  size_t current_executable_path_capacity;
  size_t current_executable_path_new_capacity;
  wchar_t current_executable_path_back_value;

  /* Copy the game executable path into the C string. */
  current_executable_path_cstr = NULL;
  current_executable_path_new_capacity = kPathInitialCapacity;

  do {
    current_executable_path_capacity = current_executable_path_new_capacity;

    realloc_result = Mdc_realloc(
        current_executable_path_cstr,
        current_executable_path_capacity
            * sizeof(current_executable_path_cstr[0])
    );

    if (realloc_result == NULL) {
      goto free_current_executable_path_cstr;
    }

    current_executable_path_cstr = realloc_result;
    current_executable_path_cstr[current_executable_path_capacity - 2]
        = L'\0';

    GetModuleFileNameW(
        NULL,
        current_executable_path_cstr,
        current_executable_path_capacity
    );

    current_executable_path_new_capacity *= 2;

    current_executable_path_back_value =
        current_executable_path_cstr[current_executable_path_capacity - 2];
  } while (current_executable_path_back_value != L'\0');

  /* The C string now contains the exectuable path. Init the path. */
  current_executable_path = Mdc_Fs_Path_InitFromCWStr(
      current_executable_path_cstr
  );

  Mdc_free(current_executable_path_cstr);

  return current_executable_path;

free_current_executable_path_cstr:
  Mdc_free(current_executable_path_cstr);
}

#endif
