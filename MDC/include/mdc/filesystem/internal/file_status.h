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

#ifndef MDC_C_FILESYSTEM_INTERNAL_FILE_STATUS_H_
#define MDC_C_FILESYSTEM_INTERNAL_FILE_STATUS_H_

#include "../../object_metadata/object_metadata.h"
#include "file_type.h"
#include "perms.h"

#include "../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_Fs_FileStatus {
  enum Mdc_Fs_FileType type_;
  enum Mdc_Fs_Perms permissions_;
};

/**
 * Initialization/deinitialization
 */

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitNone(
    struct Mdc_Fs_FileStatus* file_status
);

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitFromType(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type
);

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitFromTypeAndPerms(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type,
    enum Mdc_Fs_Perms permissions
);

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitCopy(
    struct Mdc_Fs_FileStatus* dest,
    const struct Mdc_Fs_FileStatus* src
);

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_InitMove(
    struct Mdc_Fs_FileStatus* dest,
    struct Mdc_Fs_FileStatus* src
);

DLLEXPORT void Mdc_Fs_FileStatus_Deinit(
    struct Mdc_Fs_FileStatus* file_status
);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_Fs_FileStatus_GetObjectMetadata(void);

/**
 * Assignment
 */

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_AssignCopy(
    struct Mdc_Fs_FileStatus* dest,
    const struct Mdc_Fs_FileStatus* src
);

DLLEXPORT struct Mdc_Fs_FileStatus* Mdc_Fs_FileStatus_AssignMove(
    struct Mdc_Fs_FileStatus* dest,
    struct Mdc_Fs_FileStatus* src
);

/**
 * Comparison functions
 */

DLLEXPORT bool Mdc_Fs_FileStatus_Equal(
    const struct Mdc_Fs_FileStatus* file_status1,
    const struct Mdc_Fs_FileStatus* file_status2
);

/**
 * Etc. functions
 */

DLLEXPORT enum Mdc_Fs_FileType Mdc_Fs_FileStatus_GetType(
    const struct Mdc_Fs_FileStatus* file_status
);

DLLEXPORT void Mdc_Fs_FileStatus_SetType(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type
);

DLLEXPORT enum Mdc_Fs_Perms Mdc_Fs_FileStatus_GetPermissions(
    const struct Mdc_Fs_FileStatus* file_status
);

DLLEXPORT void Mdc_Fs_FileStatus_SetPermissions(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_Perms permissions
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_FILESYSTEM_INTERNAL_FILE_STATUS_H_ */
