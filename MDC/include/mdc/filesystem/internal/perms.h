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

#ifndef MDC_C_FILESYSTEM_INTERNAL_PERMS_H_
#define MDC_C_FILESYSTEM_INTERNAL_PERMS_H_

#include "../../macro/template_macro.h"

enum Mdc_Fs_Perms {
  Mdc_Fs_Perms_kNone = 0,

  Mdc_Fs_Perms_kOwnerRead = 0400,
  Mdc_Fs_Perms_kOwnerWrite = 0200,
  Mdc_Fs_Perms_kOwnerExec = 0100,
  Mdc_Fs_Perms_kOwnerAll = 0700,

  Mdc_Fs_Perms_kGroupRead = 040,
  Mdc_Fs_Perms_kGroupWrite = 020,
  Mdc_Fs_Perms_kGroupExec = 010,
  Mdc_Fs_Perms_kGroupAll = 070,

  Mdc_Fs_Perms_kOthersRead = 04,
  Mdc_Fs_Perms_kOthersWrite = 02,
  Mdc_Fs_Perms_kOthersExec = 01,
  Mdc_Fs_Perms_kOthersAll = 07,

  Mdc_Fs_Perms_kAll = 0777,

  Mdc_Fs_Perms_kSetUid = 04000,
  Mdc_Fs_Perms_kSetGid = 02000,
  Mdc_Fs_Perms_kStickyBit = 01000,
  Mdc_Fs_Perms_kMask = 07777,

  Mdc_Fs_Perms_kUnknown = 0xFFFF
};

MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(enum, Mdc_Fs_Perms)

#endif /* MDC_C_FILESYSTEM_INTERNAL_PERMS_H_ */
