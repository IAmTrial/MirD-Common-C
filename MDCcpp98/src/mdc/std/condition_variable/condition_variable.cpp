/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C++98.
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

#include "../../../../include/mdc/std/condition_variable.hpp"

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

#include <stdexcept>

namespace std {

condition_variable::condition_variable() {
  int init_result = ::cnd_init(&this->condition_variable_);

  if (init_result != thrd_success) {
    throw ::std::runtime_error(
        "::std::condition_variable::condition_variable failure"
    );
  }
}

condition_variable::~condition_variable() {
  ::cnd_destroy(&this->condition_variable_);
}

void condition_variable::notify_one() throw() {
  ::cnd_signal(&this->condition_variable_);
}

void condition_variable::notify_all() throw() {
  ::cnd_broadcast(&this->condition_variable_);
}

void condition_variable::wait(unique_lock<mutex>& lock) {
  ::cnd_wait(&this->condition_variable_, lock.mutex()->native_handle());
}

} // namespace std

#endif // __cplusplus < 201103L && _MSVC_LANG < 201103L
