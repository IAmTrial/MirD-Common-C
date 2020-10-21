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

#ifndef MDC_C_FILESYSTEM_INTERNAL_PATH_H_
#define MDC_C_FILESYSTEM_INTERNAL_PATH_H_

#include "../../object_metadata/object_metadata.h"
#include "../../std/stdbool.h"
#include "../../std/wchar.h"
#include "../../string/basic_string.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_Fs_Path {
  struct Mdc_BasicString path_str_;
};

#if defined(_WIN32) || defined(_WIN64)
  #define Mdc_Fs_Path_ValueType wchar_t
#else
  #define Mdc_Fs_Path_ValueType char
#endif

DLLEXPORT const Mdc_Fs_Path_ValueType Mdc_Fs_Path_kPreferredSeparator;

/**
 * Initialization/deinitialization
 */

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitEmpty(
    struct Mdc_Fs_Path* path
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromAsciiCStr(
    struct Mdc_Fs_Path* path,
    const char* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromDefaultMultibyteCStr(
    struct Mdc_Fs_Path* path,
    const char* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromUtf8CStr(
    struct Mdc_Fs_Path* path,
    const char* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitFromCWStr(
    struct Mdc_Fs_Path* path,
    const wchar_t* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitCopy(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_InitMove(
    struct Mdc_Fs_Path* dest,
    struct Mdc_Fs_Path* src
);

DLLEXPORT void Mdc_Fs_Path_Deinit(struct Mdc_Fs_Path* path);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Fs_Path_GetObjectMetadata(void);

/**
 * Assignment
 */

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_AssignCopy(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* src
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_AssignMove(
    struct Mdc_Fs_Path* dest,
    struct Mdc_Fs_Path* src
);

/**
 * Comparison operators
 */

DLLEXPORT bool Mdc_Fs_Path_Equal(
    const struct Mdc_Fs_Path* path1,
    const struct Mdc_Fs_Path* path2
);

DLLEXPORT int Mdc_Fs_Path_Compare(
    const struct Mdc_Fs_Path* path1,
    const struct Mdc_Fs_Path* path2
);

/**
 * Etc. functions
 */

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_AppendPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* path
);

DLLEXPORT const Mdc_Fs_Path_ValueType* Mdc_Fs_Path_CStr(
    const struct Mdc_Fs_Path* path
);

DLLEXPORT void Mdc_Fs_Path_Clear(struct Mdc_Fs_Path* path);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_ConcatPath(
    struct Mdc_Fs_Path* dest,
    const struct Mdc_Fs_Path* path
);

DLLEXPORT bool Mdc_Fs_Path_Empty(const struct Mdc_Fs_Path* path);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_Extension(
    struct Mdc_Fs_Path* extension,
    const struct Mdc_Fs_Path* path
);

DLLEXPORT bool Mdc_Fs_Path_IsAbsolute(const struct Mdc_Fs_Path* path);

DLLEXPORT bool Mdc_Fs_Path_IsRelative(const struct Mdc_Fs_Path* path);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_MakePreferred(
    struct Mdc_Fs_Path* path
);

DLLEXPORT const struct Mdc_BasicString* Mdc_Fs_Path_Native(
    const struct Mdc_Fs_Path* path
);

DLLEXPORT struct Mdc_Fs_Path* Mdc_Fs_Path_ParentPath(
    struct Mdc_Fs_Path* parent_path,
    const struct Mdc_Fs_Path* path
);

DLLEXPORT const struct Mdc_BasicString* Mdc_Fs_Path_StrType(
    struct Mdc_BasicString* str,
    const struct Mdc_Fs_Path* path
);

DLLEXPORT void Mdc_Fs_Path_Swap(
    struct Mdc_Fs_Path* path1,
    struct Mdc_Fs_Path* path2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_FILESYSTEM_INTERNAL_PATH_H_ */
