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

#include "../../../../include/mdc/std/threads.hpp"

#include <stdexcept>

#if __cplusplus < 201103L && _MSVC_LANG < 201103L

namespace std {

/**
 * thread
 */

thread::thread(int (*func)(void*), void* arg) {
  int create_result = thrd_create(&this->thread_, func, arg);

  if (create_result != thrd_success) {
    throw ::std::runtime_error("::std::thread::thread failure");
  }
}

void thread::join() {
  int result_code;

  int join_result = thrd_join(this->thread_, &result_code);

  if (join_result != thrd_success) {
    throw ::std::runtime_error("::std::thread::join failure");
  }
}

void thread::detach() {
  int detach_result = thrd_detach(this->thread_);
}

void thread::swap(thread& other) {
  thrd_t temp = this->thread_;
  this->thread_ = other.thread_;
  other.thread_ = temp;
}

} // namespace std

#endif // __cplusplus < 201103L && _MSVC_LANG < 201103L
