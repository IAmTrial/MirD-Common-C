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

#ifndef MDC_CPP98_WINDOWS_VS_FIXED_FILE_INFO_HPP_
#define MDC_CPP98_WINDOWS_VS_FIXED_FILE_INFO_HPP_

#if defined(_MSC_VER)

#include <windows.h>

#include <mdc/std/wchar.h>
#include <mdc/windows/vs_fixed_file_info.h>

#include "../../../dllexport_define.inc"

namespace mdc {
namespace vs {

class DLLEXPORT FixedMajorMinorVersion {
 public:
  FixedMajorMinorVersion();

  FixedMajorMinorVersion(
      unsigned short major_high,
      unsigned short major_low,
      unsigned short minor_high,
      unsigned short minor_low
  );

  static FixedMajorMinorVersion FromFileVerison(
      const VS_FIXEDFILEINFO& fixed_file_info
  );

  static FixedMajorMinorVersion FromProductVersion(
      const VS_FIXEDFILEINFO& fixed_file_info
  );

  friend bool operator==(
      const FixedMajorMinorVersion& version1,
      const FixedMajorMinorVersion& version2
  );

  friend bool operator!=(
      const FixedMajorMinorVersion& version1,
      const FixedMajorMinorVersion& version2
  );

  friend bool operator<(
      const FixedMajorMinorVersion& version1,
      const FixedMajorMinorVersion& version2
  );

  int Compare(const FixedMajorMinorVersion& version) const;

  void Swap(FixedMajorMinorVersion& version);
  void swap(FixedMajorMinorVersion& version);

  unsigned short major_high() const;
  unsigned short major_low() const;
  unsigned short minor_high() const;
  unsigned short minor_low() const;

 private:
  Mdc_Vs_FixedMajorMinorVersion version_;
};

} // namespace vs

DLLEXPORT VS_FIXEDFILEINFO VS_FIXEDFILEINFO_Read(
    const wchar_t* file_path
);

} // namespace mdc

#include "../../../dllexport_undefine.inc"

#endif /* defined(_MSC_VER) */

#endif /* MDC_CPP98_WINDOWS_VS_FIXED_FILE_INFO_HPP_ */
