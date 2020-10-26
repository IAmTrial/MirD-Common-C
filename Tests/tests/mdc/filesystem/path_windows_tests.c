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

#include <mdc/filesystem/filesystem.h>
#include <mdc/std/assert.h>
#include <mdc/malloc/malloc.h>

static const wchar_t* const kSrcPaths[] = {
    // Drive paths
    L"C:/",
    L"C:/Hello world/test file.txt",
    L"C:Hello world/test file.txt",
    L"C:test file.txt",
    L"C:/Hello world/.git",
    L"C:/Hello world/.",
    L"C:/Hello world/..",
    L"C:/Hello world/...",
    L"C:/Hello world/. ",
    L"C://Hello world///test.txt",

    // Relative paths
    L"Hello world/",
    L"Hello world/test file.txt",
    L"Hello world/.git",
    L"Hello world/.",
    L"Hello world/..",
    L"Hello world/...",
    L"Hello world/. ",
    L"Hello world//test.txt",

    // UNC paths
    L"//./",
    L"//./Hello world/test file.txt",
    L"//./Hello world/.git",
    L"//./Hello world/.",
    L"//./Hello world/..",
    L"//./Hello world/...",
    L"//./Hello world/. ",
    L"//.//Hello world/test.txt",

    // UNC paths, no extensions
    L"//",
    L"//test file.txt",
    L"//.git",
    L"//.",
    L"//..",
    L"//...",
    L"//. ",

    // Relative UNC paths
    L"///",
    L"///test file.txt",
    L"///.git",
    L"///.",
    L"///..",
    L"///...",
    L"///. ",

    // Miscellaneous
    L"",
    L".",
    L"..",
    L"...",
    L". ",
    L".git",
    L"test file.txt/",
    L"test file.txt//",
    L"test file.txt",
};

enum {
  kSrcPathsCount = sizeof(kSrcPaths) / sizeof(kSrcPaths[0])
};

static void Mdc_Fs_Path_AssertInitEmptyDeinit(void) {
  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  init_path = Mdc_Fs_Path_InitEmpty(&path);
  assert(init_path == &path);

  assert(wcscmp(Mdc_Fs_Path_CStr(&path), L"") == 0);

  Mdc_Fs_Path_Deinit(&path);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertInitFromCWStr(void) {
  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    if (wcscmp(Mdc_Fs_Path_CStr(&path), kSrcPaths[i]) != 0) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));

      assert(wcscmp(Mdc_Fs_Path_CStr(&path), kSrcPaths[i]) == 0);
    }

    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertIsAbsoluteRelative(void) {
  static const bool kExpected[] = {
      // Drive paths
      true,
      true,
      false,
      false,
      true,
      true,
      true,
      true,
      true,
      true,

      // Relative paths
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false,

      // UNC paths
      true,
      true,
      true,
      true,
      true,
      true,
      true,
      true,

      // UNC paths, no extensions
      false,
      true,
      true,
      true,
      true,
      true,
      true,

      // Relative UNC paths
      false,
      false,
      false,
      false,
      false,
      false,
      false,

      // Miscellaneous
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false,
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    if (Mdc_Fs_Path_IsAbsolute(&path) != kExpected[i]
        || Mdc_Fs_Path_IsRelative(&path) == kExpected[i]) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));

      assert(Mdc_Fs_Path_IsAbsolute(&path) == kExpected[i]
          || Mdc_Fs_Path_IsRelative(&path) != kExpected[i]);
    }

    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertExtension(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"",
      L".txt",
      L".txt",
      L".txt",
      L"",
      L"",
      L"",
      L".",
      L"",
      L".txt",

      // Relative paths
      L"",
      L".txt",
      L"",
      L"",
      L"",
      L".",
      L"",
      L".txt",

      // UNC paths
      L"",
      L".txt",
      L"",
      L"",
      L"",
      L".",
      L"",
      L".txt",

      // UNC paths, no extensions
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // Relative UNC paths
      L"",
      L".txt",
      L"",
      L"",
      L"",
      L".",
      L"",

      // Miscellaneous
      L"",
      L"",
      L"",
      L".",
      L"",
      L"",
      L"",
      L"",
      L".txt",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  struct Mdc_Fs_Path actual_extension;
  struct Mdc_Fs_Path* init_actual_extension;

  struct Mdc_Fs_Path expected_extension;
  struct Mdc_Fs_Path* init_expected_extension;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    init_actual_extension = Mdc_Fs_Path_Extension(
        &actual_extension,
        &path
    );
    assert(init_actual_extension == &actual_extension);

    init_expected_extension = Mdc_Fs_Path_InitFromCWStr(
        &expected_extension,
        kExpected[i]
    );
    assert(init_expected_extension == &expected_extension);

    if (!Mdc_Fs_Path_Equal(&actual_extension, &expected_extension)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_extension));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_extension));

      assert(Mdc_Fs_Path_Equal(&actual_extension, &expected_extension));
    }

    Mdc_Fs_Path_Deinit(&expected_extension);
    Mdc_Fs_Path_Deinit(&actual_extension);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertRootName(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",
      L"C:",

      // Relative paths
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // UNC paths
      L"//.",
      L"//.",
      L"//.",
      L"//.",
      L"//.",
      L"//.",
      L"//.",
      L"//.",

      // UNC paths, no extensions
      L"",
      L"//test file.txt",
      L"//.git",
      L"//.",
      L"//..",
      L"//...",
      L"//. ",

      // Relative UNC paths
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // Miscellaneous
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  struct Mdc_Fs_Path actual_root_name;
  struct Mdc_Fs_Path* init_actual_root_name;

  struct Mdc_Fs_Path expected_root_name;
  struct Mdc_Fs_Path* init_expected_root_name;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    init_actual_root_name = Mdc_Fs_Path_RootName(
        &actual_root_name,
        &path
    );
    assert(init_actual_root_name == &actual_root_name);

    init_expected_root_name = Mdc_Fs_Path_InitFromCWStr(
        &expected_root_name,
        kExpected[i]
    );
    assert(init_expected_root_name == &expected_root_name);

    if (!Mdc_Fs_Path_Equal(&actual_root_name, &expected_root_name)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_name));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_name));

      assert(Mdc_Fs_Path_Equal(&actual_root_name, &expected_root_name));
    }

    Mdc_Fs_Path_Deinit(&expected_root_name);
    Mdc_Fs_Path_Deinit(&actual_root_name);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertRootDirectory(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"/",
      L"/",
      L"",
      L"",
      L"/",
      L"/",
      L"/",
      L"/",
      L"/",
      L"//",

      // Relative paths
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // UNC paths
      L"/",
      L"/",
      L"/",
      L"/",
      L"/",
      L"/",
      L"/",
      L"//",

      // UNC paths, no extensions
      L"//",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // Relative UNC paths
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",

      // Miscellaneous
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  struct Mdc_Fs_Path actual_root_directory;
  struct Mdc_Fs_Path* init_actual_root_directory;

  struct Mdc_Fs_Path expected_root_directory;
  struct Mdc_Fs_Path* init_expected_root_directory;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    init_actual_root_directory = Mdc_Fs_Path_RootDirectory(
        &actual_root_directory,
        &path
    );
    assert(init_actual_root_directory == &actual_root_directory);

    init_expected_root_directory = Mdc_Fs_Path_InitFromCWStr(
        &expected_root_directory,
        kExpected[i]
    );
    assert(init_expected_root_directory == &expected_root_directory);

    if (!Mdc_Fs_Path_Equal(&actual_root_directory, &expected_root_directory)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_directory));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_directory));

      assert(Mdc_Fs_Path_Equal(&actual_root_directory, &expected_root_directory));
    }

    Mdc_Fs_Path_Deinit(&expected_root_directory);
    Mdc_Fs_Path_Deinit(&actual_root_directory);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertRootPath(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"C:/",
      L"C:/",
      L"C:",
      L"C:",
      L"C:/",
      L"C:/",
      L"C:/",
      L"C:/",
      L"C:/",
      L"C://",

      // Relative paths
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",

      // UNC paths
      L"//./",
      L"//./",
      L"//./",
      L"//./",
      L"//./",
      L"//./",
      L"//./",
      L"//.//",

      // UNC paths, no extensions
      L"//",
      L"//test file.txt",
      L"//.git",
      L"//.",
      L"//..",
      L"//...",
      L"//. ",

      // Relative UNC paths
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",
      L"///",

      // Miscellaneous
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
      L"",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path* init_path;

  struct Mdc_Fs_Path actual_root_path;
  struct Mdc_Fs_Path* init_actual_root_path;

  struct Mdc_Fs_Path expected_root_path;
  struct Mdc_Fs_Path* init_expected_root_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    init_path = Mdc_Fs_Path_InitFromCWStr(&path, kSrcPaths[i]);
    assert(init_path == &path);

    init_actual_root_path = Mdc_Fs_Path_RootPath(
        &actual_root_path,
        &path
    );
    assert(init_actual_root_path == &actual_root_path);

    init_expected_root_path = Mdc_Fs_Path_InitFromCWStr(
        &expected_root_path,
        kExpected[i]
    );
    assert(init_expected_root_path == &expected_root_path);

    if (!Mdc_Fs_Path_Equal(&actual_root_path, &expected_root_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_path));

      assert(Mdc_Fs_Path_Equal(&actual_root_path, &expected_root_path));
    }

    Mdc_Fs_Path_Deinit(&expected_root_path);
    Mdc_Fs_Path_Deinit(&actual_root_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Fs_Path_RunTests(void) {
  Mdc_Fs_Path_AssertInitEmptyDeinit();
  Mdc_Fs_Path_AssertInitFromCWStr();
  Mdc_Fs_Path_AssertIsAbsoluteRelative();

  Mdc_Fs_Path_AssertExtension();

  Mdc_Fs_Path_AssertRootName();
  Mdc_Fs_Path_AssertRootDirectory();
  Mdc_Fs_Path_AssertRootPath();
}
