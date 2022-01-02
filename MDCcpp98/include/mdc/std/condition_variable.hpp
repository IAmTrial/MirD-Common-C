/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021-2022  Mir Drualga
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

#ifndef MDC_CPP98_STD_CONDITION_VARIABLE_HPP_
#define MDC_CPP98_STD_CONDITION_VARIABLE_HPP_

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

#include <condition_variable>

#else

#include <mdc/std/threads.h>

#include "mutex.hpp"

#include "../../../dllexport_define.inc"

namespace std {

/**
 * Condition variables
 */

class DLLEXPORT condition_variable {
 public:
  condition_variable();

  ~condition_variable();

  void notify_one() throw();

  void notify_all() throw();

  void wait(unique_lock<mutex>& lock);

  template <class Predicate>
  void wait(unique_lock<mutex>& lock, Predicate pred) {
    while (!pred()) {
      wait(lock);
    }
  }

 private:
  ::cnd_t condition_variable_;

  // Intentionally unimplemented to "delete" them.
  condition_variable(const condition_variable&);
  condition_variable& operator=(const condition_variable&);
};

class DLLEXPORT condition_variable_any {
 public:
  condition_variable_any();

  ~condition_variable_any();

  void notify_one() throw();

  void notify_all() throw();

  template <class Lock>
  void wait(Lock& lock) {
    ::cnd_wait(&this->condition_variable_, &lock.mutex()->native_handle());
  }

  template <class Lock, class Predicate>
  void wait(Lock& lock, Predicate pred) {
    while (!pred()) {
      wait(lock);
    }
  }

 private:
  ::cnd_t condition_variable_;

  // Intentionally unimplemented to "delete" them.
  condition_variable_any(const condition_variable_any&);
  condition_variable_any& operator=(const condition_variable_any&);
};

} // namespace std

#include "../../../dllexport_undefine.inc"
#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

#endif /* MDC_CPP98_STD_CONDITION_VARIABLE_HPP_ */