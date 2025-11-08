/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021-2025  Mir Drualga
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

#include <stdexcept>

#include "mdc/std/threads.h"

#include "mdc/std/mutex.hpp"

namespace std {

/**
 * Condition variables
 */

class condition_variable {
 public:
  inline condition_variable() {
    int init_result = ::cnd_init(&this->condition_variable_);

    if (init_result != thrd_success) {
      throw ::std::runtime_error(
          "::std::condition_variable::condition_variable failure");
    }
  }

  inline ~condition_variable() {
    ::cnd_destroy(&this->condition_variable_);
  }

  inline void notify_one() throw() {
    ::cnd_signal(&this->condition_variable_);
  }

  inline void notify_all() throw() {
    ::cnd_broadcast(&this->condition_variable_);
  }

  inline void wait(unique_lock<mutex>& lock) {
    ::cnd_wait(&this->condition_variable_, lock.mutex()->native_handle());
  }

  template <class Predicate>
  inline void wait(unique_lock<mutex>& lock, Predicate pred) {
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

class condition_variable_any {
 public:
  inline condition_variable_any() {
    int init_result = ::cnd_init(&this->condition_variable_);

    if (init_result != thrd_success) {
      throw ::std::runtime_error(
          "::std::condition_variable_any::condition_variable_any failure");
    }
  }

  inline ~condition_variable_any() {
    ::cnd_destroy(&this->condition_variable_);
  }

  inline void notify_one() throw() {
    ::cnd_signal(&this->condition_variable_);
  }

  inline void notify_all() throw() {
    ::cnd_broadcast(&this->condition_variable_);
  }

  template <class Lock>
  inline void wait(Lock& lock) {
    ::cnd_wait(&this->condition_variable_, &lock.mutex()->native_handle());
  }

  template <class Lock, class Predicate>
  inline void wait(Lock& lock, Predicate pred) {
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

}  // namespace std

#endif  // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

#endif  /* MDC_CPP98_STD_CONDITION_VARIABLE_HPP_ */
