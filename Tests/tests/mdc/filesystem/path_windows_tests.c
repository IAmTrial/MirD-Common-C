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

static void Mdc_Fs_Path_AssertInitEmptyAndDeinit(void) {
  struct Mdc_Fs_Path path;

  path = Mdc_Fs_Path_InitEmpty();

  assert(wcscmp(Mdc_Fs_Path_CStr(&path), L"") == 0);

  Mdc_Fs_Path_Deinit(&path);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertInitFromCWStr(void) {
  size_t i;

  struct Mdc_Fs_Path path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);

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

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);

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

static void Mdc_Fs_Path_AssertClear(void) {
  static const wchar_t* const kExpected = L"";

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_path;
  struct Mdc_Fs_Path expected_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_path = Mdc_Fs_Path_InitCopy(&path);

    Mdc_Fs_Path_Clear(&actual_path);

    expected_path = Mdc_Fs_Path_InitFromCWStr(kExpected);

    if (!Mdc_Fs_Path_EqualPath(&actual_path, &expected_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_path, &expected_path));
    }

    Mdc_Fs_Path_Deinit(&expected_path);
    Mdc_Fs_Path_Deinit(&actual_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertMakePreferred(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"C:\\",
      L"C:\\Hello world\\test file.txt",
      L"C:Hello world\\test file.txt",
      L"C:test file.txt",
      L"C:\\Hello world\\.git",
      L"C:\\Hello world\\.",
      L"C:\\Hello world\\..",
      L"C:\\Hello world\\...",
      L"C:\\Hello world\\. ",
      L"C:\\\\Hello world\\\\\\test.txt",

      // Relative paths
      L"Hello world\\",
      L"Hello world\\test file.txt",
      L"Hello world\\.git",
      L"Hello world\\.",
      L"Hello world\\..",
      L"Hello world\\...",
      L"Hello world\\. ",
      L"Hello world\\\\test.txt",

      // UNC paths
      L"\\\\.\\",
      L"\\\\.\\Hello world\\test file.txt",
      L"\\\\.\\Hello world\\.git",
      L"\\\\.\\Hello world\\.",
      L"\\\\.\\Hello world\\..",
      L"\\\\.\\Hello world\\...",
      L"\\\\.\\Hello world\\. ",
      L"\\\\.\\\\Hello world\\test.txt",

      // UNC paths, no extensions
      L"\\\\",
      L"\\\\test file.txt",
      L"\\\\.git",
      L"\\\\.",
      L"\\\\..",
      L"\\\\...",
      L"\\\\. ",

      // Relative UNC paths
      L"\\\\\\",
      L"\\\\\\test file.txt",
      L"\\\\\\.git",
      L"\\\\\\.",
      L"\\\\\\..",
      L"\\\\\\...",
      L"\\\\\\. ",

      // Miscellaneous
      L"",
      L".",
      L"..",
      L"...",
      L". ",
      L".git",
      L"test file.txt\\",
      L"test file.txt\\\\",
      L"test file.txt",
  };

  size_t i;

  struct Mdc_Fs_Path path;

  struct Mdc_Fs_Path actual;
  struct Mdc_Fs_Path* preferred_actual;

  struct Mdc_Fs_Path expected;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual = Mdc_Fs_Path_InitCopy(&path);
    preferred_actual = Mdc_Fs_Path_MakePreferred(&actual);

    expected = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual, &expected)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual));

      assert(Mdc_Fs_Path_EqualPath(&actual, &expected));
    }

    Mdc_Fs_Path_Deinit(&expected);
    Mdc_Fs_Path_Deinit(&actual);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertStem(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"",
      L"test file",
      L"test file",
      L"test file",
      L".git",
      L".",
      L"..",
      L"..",
      L". ",
      L"test",

      // Relative paths
      L"",
      L"test file",
      L".git",
      L".",
      L"..",
      L"..",
      L". ",
      L"test",

      // UNC paths
      L"",
      L"test file",
      L".git",
      L".",
      L"..",
      L"..",
      L". ",
      L"test",

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
      L"test file",
      L".git",
      L".",
      L"..",
      L"..",
      L". ",

      // Miscellaneous
      L"",
      L".",
      L"..",
      L"..",
      L". ",
      L".git",
      L"",
      L"",
      L"test file",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_stem;
  struct Mdc_Fs_Path expected_stem;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);

    actual_stem = Mdc_Fs_Path_Stem(&path);
    expected_stem = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_stem, &expected_stem)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_stem));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_stem));

      assert(Mdc_Fs_Path_EqualPath(&actual_stem, &expected_stem));
    }

    Mdc_Fs_Path_Deinit(&expected_stem);
    Mdc_Fs_Path_Deinit(&actual_stem);
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
  struct Mdc_Fs_Path actual_extension;
  struct Mdc_Fs_Path expected_extension;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);

    actual_extension = Mdc_Fs_Path_Extension(&path);
    expected_extension = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_extension, &expected_extension)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_extension));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_extension));

      assert(Mdc_Fs_Path_EqualPath(&actual_extension, &expected_extension));
    }

    Mdc_Fs_Path_Deinit(&expected_extension);
    Mdc_Fs_Path_Deinit(&actual_extension);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertFilename(void) {
  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"",
      L"test file.txt",
      L"test file.txt",
      L"test file.txt",
      L".git",
      L".",
      L"..",
      L"...",
      L". ",
      L"test.txt",

      // Relative paths
      L"",
      L"test file.txt",
      L".git",
      L".",
      L"..",
      L"...",
      L". ",
      L"test.txt",

      // UNC paths
      L"",
      L"test file.txt",
      L".git",
      L".",
      L"..",
      L"...",
      L". ",
      L"test.txt",

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
      L"test file.txt",
      L".git",
      L".",
      L"..",
      L"...",
      L". ",

      // Miscellaneous
      L"",
      L".",
      L"..",
      L"...",
      L". ",
      L".git",
      L"",
      L"",
      L"test file.txt",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_filename;
  struct Mdc_Fs_Path expected_filename;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_filename = Mdc_Fs_Path_Filename(&path);
    expected_filename = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_filename, &expected_filename)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_filename));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_filename));

      assert(Mdc_Fs_Path_EqualPath(&actual_filename, &expected_filename));
    }

    Mdc_Fs_Path_Deinit(&expected_filename);
    Mdc_Fs_Path_Deinit(&actual_filename);
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
  struct Mdc_Fs_Path actual_root_name;
  struct Mdc_Fs_Path expected_root_name;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);

    actual_root_name = Mdc_Fs_Path_RootName(&path);
    expected_root_name = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_root_name, &expected_root_name)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_name));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_name));

      assert(Mdc_Fs_Path_EqualPath(&actual_root_name, &expected_root_name));
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
  struct Mdc_Fs_Path actual_root_directory;
  struct Mdc_Fs_Path expected_root_directory;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_root_directory = Mdc_Fs_Path_RootDirectory(&path);
    expected_root_directory = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_root_directory, &expected_root_directory)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_directory));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_directory));

      assert(Mdc_Fs_Path_EqualPath(&actual_root_directory, &expected_root_directory));
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
  struct Mdc_Fs_Path actual_root_path;
  struct Mdc_Fs_Path expected_root_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_root_path = Mdc_Fs_Path_RootPath(&path);
    expected_root_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_root_path, &expected_root_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_root_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_root_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_root_path, &expected_root_path));
    }

    Mdc_Fs_Path_Deinit(&expected_root_path);
    Mdc_Fs_Path_Deinit(&actual_root_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertParentPath(void) {
  static const wchar_t* const kExpected[] = {
    // Drive paths
    L"C:/",
    L"C:/Hello world",
    L"C:Hello world",
    L"C:",
    L"C:/Hello world",
    L"C:/Hello world",
    L"C:/Hello world",
    L"C:/Hello world",
    L"C:/Hello world",
    L"C://Hello world",

    // Relative paths
    L"Hello world",
    L"Hello world",
    L"Hello world",
    L"Hello world",
    L"Hello world",
    L"Hello world",
    L"Hello world",
    L"Hello world",

    // UNC paths
    L"//./",
    L"//./Hello world",
    L"//./Hello world",
    L"//./Hello world",
    L"//./Hello world",
    L"//./Hello world",
    L"//./Hello world",
    L"//.//Hello world",

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
    L"test file.txt",
    L"test file.txt",
    L"",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_parent_path;
  struct Mdc_Fs_Path expected_parent_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_parent_path = Mdc_Fs_Path_ParentPath(&path);
    expected_parent_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_parent_path, &expected_parent_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_parent_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_parent_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_parent_path, &expected_parent_path));
    }

    Mdc_Fs_Path_Deinit(&expected_parent_path);
    Mdc_Fs_Path_Deinit(&actual_parent_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertRelativePath(void) {
  static const wchar_t* const kExpected[] = {
    // Drive paths
    L"",
    L"Hello world/test file.txt",
    L"Hello world/test file.txt",
    L"test file.txt",
    L"Hello world/.git",
    L"Hello world/.",
    L"Hello world/..",
    L"Hello world/...",
    L"Hello world/. ",
    L"Hello world///test.txt",

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
    L"",
    L"Hello world/test file.txt",
    L"Hello world/.git",
    L"Hello world/.",
    L"Hello world/..",
    L"Hello world/...",
    L"Hello world/. ",
    L"Hello world/test.txt",

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
    L"test file.txt",
    L".git",
    L".",
    L"..",
    L"...",
    L". ",

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

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_relative_path;
  struct Mdc_Fs_Path expected_relative_path;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_relative_path = Mdc_Fs_Path_RelativePath(&path);
    expected_relative_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_relative_path, &expected_relative_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_relative_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_relative_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_relative_path, &expected_relative_path));
    }

    Mdc_Fs_Path_Deinit(&expected_relative_path);
    Mdc_Fs_Path_Deinit(&actual_relative_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertRemoveFilename(void) {
  static const wchar_t* const kExpected[] = {
    // Drive paths
    L"C:/",
    L"C:/Hello world/",
    L"C:Hello world/",
    L"C:",
    L"C:/Hello world/",
    L"C:/Hello world/",
    L"C:/Hello world/",
    L"C:/Hello world/",
    L"C:/Hello world/",
    L"C://Hello world///",

    // Relative paths
    L"Hello world/",
    L"Hello world/",
    L"Hello world/",
    L"Hello world/",
    L"Hello world/",
    L"Hello world/",
    L"Hello world/",
    L"Hello world//",

    // UNC paths
    L"//./",
    L"//./Hello world/",
    L"//./Hello world/",
    L"//./Hello world/",
    L"//./Hello world/",
    L"//./Hello world/",
    L"//./Hello world/",
    L"//.//Hello world/",

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
    L"test file.txt/",
    L"test file.txt//",
    L"",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path actual_path;
  struct Mdc_Fs_Path expected_path;

  struct Mdc_Fs_Path* remove_filename;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    actual_path = Mdc_Fs_Path_InitCopy(&path);

    remove_filename = Mdc_Fs_Path_RemoveFilename(&actual_path);

    assert(remove_filename == &actual_path);

    expected_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_path, &expected_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_path, &expected_path));
    }

    Mdc_Fs_Path_Deinit(&expected_path);
    Mdc_Fs_Path_Deinit(&actual_path);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertReplaceFilename(void) {
  static const wchar_t* const kReplacement =
      L"path_test-not a%20coincidence.file.txt";

  static const wchar_t* const kExpected[] = {
    // Drive paths
    L"C:/path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C:Hello world/path_test-not a%20coincidence.file.txt",
    L"C:path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C:/Hello world/path_test-not a%20coincidence.file.txt",
    L"C://Hello world///path_test-not a%20coincidence.file.txt",

    // Relative paths
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world/path_test-not a%20coincidence.file.txt",
    L"Hello world//path_test-not a%20coincidence.file.txt",

    // UNC paths
    L"//./path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//./Hello world/path_test-not a%20coincidence.file.txt",
    L"//.//Hello world/path_test-not a%20coincidence.file.txt",

    // UNC paths, no extensions
    L"//path_test-not a%20coincidence.file.txt",
    L"//test file.txt\\path_test-not a%20coincidence.file.txt",
    L"//.git\\path_test-not a%20coincidence.file.txt",
    L"//.\\path_test-not a%20coincidence.file.txt",
    L"//..\\path_test-not a%20coincidence.file.txt",
    L"//...\\path_test-not a%20coincidence.file.txt",
    L"//. \\path_test-not a%20coincidence.file.txt",

    // Relative UNC paths
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",
    L"///path_test-not a%20coincidence.file.txt",

    // Miscellaneous
    L"path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
    L"test file.txt/path_test-not a%20coincidence.file.txt",
    L"test file.txt//path_test-not a%20coincidence.file.txt",
    L"path_test-not a%20coincidence.file.txt",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path replacement;
  struct Mdc_Fs_Path actual_path;
  struct Mdc_Fs_Path expected_path;

  struct Mdc_Fs_Path* replace_filename;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    replacement = Mdc_Fs_Path_InitFromCWStr(kReplacement);
    actual_path = Mdc_Fs_Path_InitCopy(&path);

    replace_filename = Mdc_Fs_Path_ReplaceFilename(
        &actual_path,
        &replacement
    );

    assert(replace_filename == &actual_path);

    expected_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_path, &expected_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_path, &expected_path));
    }

    Mdc_Fs_Path_Deinit(&expected_path);
    Mdc_Fs_Path_Deinit(&actual_path);
    Mdc_Fs_Path_Deinit(&replacement);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Fs_Path_AssertReplaceExtension(void) {
  static const wchar_t* const kReplacement =
      L".path_test-not_a%20coincidence";

  static const wchar_t* const kExpected[] = {
      // Drive paths
      L"C:/.path_test-not_a%20coincidence",
      L"C:/Hello world/test file.path_test-not_a%20coincidence",
      L"C:Hello world/test file.path_test-not_a%20coincidence",
      L"C:test file.path_test-not_a%20coincidence",
      L"C:/Hello world/.git.path_test-not_a%20coincidence",
      L"C:/Hello world/..path_test-not_a%20coincidence",
      L"C:/Hello world/...path_test-not_a%20coincidence",
      L"C:/Hello world/...path_test-not_a%20coincidence",
      L"C:/Hello world/. .path_test-not_a%20coincidence",
      L"C://Hello world///test.path_test-not_a%20coincidence",

      // Relative paths
      L"Hello world/.path_test-not_a%20coincidence",
      L"Hello world/test file.path_test-not_a%20coincidence",
      L"Hello world/.git.path_test-not_a%20coincidence",
      L"Hello world/..path_test-not_a%20coincidence",
      L"Hello world/...path_test-not_a%20coincidence",
      L"Hello world/...path_test-not_a%20coincidence",
      L"Hello world/. .path_test-not_a%20coincidence",
      L"Hello world//test.path_test-not_a%20coincidence",

      // UNC paths
      L"//./.path_test-not_a%20coincidence",
      L"//./Hello world/test file.path_test-not_a%20coincidence",
      L"//./Hello world/.git.path_test-not_a%20coincidence",
      L"//./Hello world/..path_test-not_a%20coincidence",
      L"//./Hello world/...path_test-not_a%20coincidence",
      L"//./Hello world/...path_test-not_a%20coincidence",
      L"//./Hello world/. .path_test-not_a%20coincidence",
      L"//.//Hello world/test.path_test-not_a%20coincidence",

      // UNC paths, no extensions
      L"//.path_test-not_a%20coincidence",
      L"//test file.txt.path_test-not_a%20coincidence",
      L"//.git.path_test-not_a%20coincidence",
      L"//..path_test-not_a%20coincidence",
      L"//...path_test-not_a%20coincidence",
      L"//....path_test-not_a%20coincidence",
      L"//. .path_test-not_a%20coincidence",

      // Relative UNC paths
      L"///.path_test-not_a%20coincidence",
      L"///test file.path_test-not_a%20coincidence",
      L"///.git.path_test-not_a%20coincidence",
      L"///..path_test-not_a%20coincidence",
      L"///...path_test-not_a%20coincidence",
      L"///...path_test-not_a%20coincidence",
      L"///. .path_test-not_a%20coincidence",

      // Miscellaneous
      L".path_test-not_a%20coincidence",
      L"..path_test-not_a%20coincidence",
      L"...path_test-not_a%20coincidence",
      L"...path_test-not_a%20coincidence",
      L". .path_test-not_a%20coincidence",
      L".git.path_test-not_a%20coincidence",
      L"test file.txt/.path_test-not_a%20coincidence",
      L"test file.txt//.path_test-not_a%20coincidence",
      L"test file.path_test-not_a%20coincidence",
  };

  size_t i;

  struct Mdc_Fs_Path path;
  struct Mdc_Fs_Path replacement;
  struct Mdc_Fs_Path actual_path;
  struct Mdc_Fs_Path expected_path;

  struct Mdc_Fs_Path* replace_extension;

  for (i = 0; i < kSrcPathsCount; i += 1) {
    path = Mdc_Fs_Path_InitFromCWStr(kSrcPaths[i]);
    replacement = Mdc_Fs_Path_InitFromCWStr(kReplacement);
    actual_path = Mdc_Fs_Path_InitCopy(&path);

    replace_extension = Mdc_Fs_Path_ReplaceExtension(
        &actual_path,
        &replacement
    );

    assert(replace_extension == &actual_path);

    expected_path = Mdc_Fs_Path_InitFromCWStr(kExpected[i]);

    if (!Mdc_Fs_Path_EqualPath(&actual_path, &expected_path)) {
      wprintf(L"Path: \"%s\" \n", Mdc_Fs_Path_CStr(&path));
      wprintf(L"Expected: \"%s\" \n", Mdc_Fs_Path_CStr(&expected_path));
      wprintf(L"Actual: \"%s\" \n", Mdc_Fs_Path_CStr(&actual_path));

      assert(Mdc_Fs_Path_EqualPath(&actual_path, &expected_path));
    }

    Mdc_Fs_Path_Deinit(&expected_path);
    Mdc_Fs_Path_Deinit(&actual_path);
    Mdc_Fs_Path_Deinit(&replacement);
    Mdc_Fs_Path_Deinit(&path);
  }

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Fs_Path_RunTests(void) {
  Mdc_Fs_Path_AssertInitEmptyAndDeinit();
  Mdc_Fs_Path_AssertInitFromCWStr();
  Mdc_Fs_Path_AssertIsAbsoluteRelative();

  Mdc_Fs_Path_AssertClear();
  Mdc_Fs_Path_AssertMakePreferred();

  Mdc_Fs_Path_AssertStem();
  Mdc_Fs_Path_AssertExtension();
  Mdc_Fs_Path_AssertFilename();

  Mdc_Fs_Path_AssertRootName();
  Mdc_Fs_Path_AssertRootDirectory();
  Mdc_Fs_Path_AssertRootPath();

  Mdc_Fs_Path_AssertParentPath();
  Mdc_Fs_Path_AssertRelativePath();

  Mdc_Fs_Path_AssertRemoveFilename();
  Mdc_Fs_Path_AssertReplaceFilename();
  Mdc_Fs_Path_AssertReplaceExtension();
}
