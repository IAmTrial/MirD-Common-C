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

#include "../../macro/template_macro.h"
#include "../../object/object.h"
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

MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(struct, Mdc_Fs_FileStatus)

/**
 * Initialization/deinitialization
 */

#define Mdc_Fs_FileStatus_InitNone \
    Mdc_Object_InitDefault(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_INIT_DEFAULT(Mdc_Fs_FileStatus)

DLLEXPORT struct Mdc_Fs_FileStatus Mdc_Fs_FileStatus_InitNone(void);

#define Mdc_Fs_FileStatus_InitFromType \
    Mdc_Object_InitFrom_1(Mdc_Fs_FileStatus, MDC_T(Mdc_Fs_FileType))

DLLEXPORT struct Mdc_Fs_FileStatus Mdc_Fs_FileStatus_InitFromType(
    enum Mdc_Fs_FileType type
);

#define Mdc_Fs_FileStatus_InitFromTypeAndPerms \
    Mdc_Object_InitFrom_2( \
        Mdc_Fs_FileStatus, \
        MDC_T(Mdc_Fs_FileType), \
        MDC_T(Mdc_Fs_Perms) \
    )

DLLEXPORT struct Mdc_Fs_FileStatus Mdc_Fs_FileStatus_InitFromTypeAndPerms(
    enum Mdc_Fs_FileType type,
    enum Mdc_Fs_Perms permissions
);

#define Mdc_Fs_FileStatus_InitCopy \
    Mdc_Object_InitCopy(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_INIT_COPY(Mdc_Fs_FileStatus)

#define Mdc_Fs_FileStatus_InitMove \
    Mdc_Object_InitMove(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_INIT_MOVE(Mdc_Fs_FileStatus)

#define Mdc_Fs_FileStatus_Deinit \
    Mdc_Object_Deinit(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_DEINIT(Mdc_Fs_FileStatus)

/**
 * Assignment
 */

#define Mdc_Fs_FileStatus_AssignCopy \
    Mdc_Object_AssignCopy(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_ASSIGN_COPY(Mdc_Fs_FileStatus)

#define Mdc_Fs_FileStatus_AssignMove \
    Mdc_Object_AssignMove(Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_ASSIGN_MOVE(Mdc_Fs_FileStatus)

/**
 * Comparison functions
 */

#define Mdc_Fs_FileStatus_Equal \
    Mdc_Object_DefaultEqual(Mdc_Fs_FileStatus, Mdc_Fs_FileStatus)

DLLEXPORT MDC_DECLARE_OBJECT_DEFAULT_EQUAL( \
    Mdc_Fs_FileStatus, \
    Mdc_Fs_FileStatus \
)

/**
 * Etc. functions
 */

#define Mdc_Fs_FileStatus_GetType \
    Mdc_Object_MemberFunction_0(Mdc_Fs_FileStatus, GetType)

DLLEXPORT enum Mdc_Fs_FileType Mdc_Fs_FileStatus_GetType(
    const struct Mdc_Fs_FileStatus* file_status
);

#define Mdc_Fs_FileStatus_SetType \
    Mdc_Object_MemberFunction_1( \
        Mdc_Fs_FileStatus, \
        SetType, \
        MDC_T(Mdc_Fs_FileType) \
    )

DLLEXPORT void Mdc_Fs_FileStatus_SetType(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_FileType type
);

#define Mdc_Fs_FileStatus_GetPermissions \
    Mdc_Object_MemberFunction_0( \
        Mdc_Fs_FileStatus, \
        GetPermissions \
    )

DLLEXPORT enum Mdc_Fs_Perms Mdc_Fs_FileStatus_GetPermissions(
    const struct Mdc_Fs_FileStatus* file_status
);

#define Mdc_Fs_FileStatus_SetPermissions \
    Mdc_Object_MemberFunction_1( \
        Mdc_Fs_FileStatus, \
        SetPermissions, \
        MDC_T(Mdc_Fs_Perms) \
    )

DLLEXPORT void Mdc_Fs_FileStatus_SetPermissions(
    struct Mdc_Fs_FileStatus* file_status,
    enum Mdc_Fs_Perms permissions
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../dllexport_undefine.inc"
#endif /* MDC_C_FILESYSTEM_INTERNAL_FILE_STATUS_H_ */
