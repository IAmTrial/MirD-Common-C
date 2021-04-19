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

#include "../../../include/mdc/windows/vs_fixed_file_info.hpp"

#if defined(_MSC_VER)

namespace mdc {
namespace vs {

FixedMajorMinorVersion::FixedMajorMinorVersion()
    : version_() {
}

FixedMajorMinorVersion::FixedMajorMinorVersion(
    unsigned short major_high,
    unsigned short major_low,
    unsigned short minor_high,
    unsigned short minor_low
)
    : version_() {
  this->version_.major_high = major_high;
  this->version_.major_low = major_low;
  this->version_.minor_high = minor_high;
  this->version_.minor_low = minor_low;
}

FixedMajorMinorVersion FixedMajorMinorVersion::FromFileVersion(
    const VS_FIXEDFILEINFO& fixed_file_info
) {
  FixedMajorMinorVersion version;

  version.version_ = VS_FIXEDFILEINFO_GetFileVersion(&fixed_file_info);

  return version;
}

FixedMajorMinorVersion FixedMajorMinorVersion::FromProductVersion(
    const VS_FIXEDFILEINFO& fixed_file_info
) {
  FixedMajorMinorVersion version;

  version.version_ = VS_FIXEDFILEINFO_GetProductVersion(&fixed_file_info);

  return version;
}

bool operator==(
    const FixedMajorMinorVersion& version1,
    const FixedMajorMinorVersion& version2
) {
  return (version1.Compare(version2) == 0);
}

bool operator!=(
    const FixedMajorMinorVersion& version1,
    const FixedMajorMinorVersion& version2
) {
  return (version1.Compare(version2) != 0);
}

bool operator<(
    const FixedMajorMinorVersion& version1,
    const FixedMajorMinorVersion& version2
) {
  return (version1.Compare(version2) < 0);
}

int FixedMajorMinorVersion::Compare(
    const FixedMajorMinorVersion& version
) const {
  return Mdc_Vs_FixedMajorMinorVersion_Compare(
      &this->version_,
      &version.version_
  );
}

void FixedMajorMinorVersion::Swap(FixedMajorMinorVersion& version) {
  FixedMajorMinorVersion temp = *this;
  *this = version;
  version = temp;
}

void FixedMajorMinorVersion::swap(FixedMajorMinorVersion& version) {
  this->Swap(version);
}

unsigned short FixedMajorMinorVersion::major_high() const {
  return this->version_.major_high;
}

unsigned short FixedMajorMinorVersion::major_low() const {
  return this->version_.major_low;
}

unsigned short FixedMajorMinorVersion::minor_high() const {
  return this->version_.minor_high;
}

unsigned short FixedMajorMinorVersion::minor_low() const {
  return this->version_.minor_low;
}

} // namespace vs

VS_FIXEDFILEINFO VS_FIXEDFILEINFO_Read(
    const wchar_t* file_path
) {
  return ::VS_FIXEDFILEINFO_Read(file_path);
}

} // namespace mdc

#endif /* defined(_MSC_VER) */
