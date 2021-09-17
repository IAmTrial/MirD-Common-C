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

#ifndef MDC_CPP98_STD_MUTEX_HPP_
#define MDC_CPP98_STD_MUTEX_HPP_

#if __cplusplus >= 201103L || _MSVC_LANG >= 201103L

#include <mutex>

#else

#include <stddef.h>

#include <stdexcept>

#include <mdc/std/threads.h>

#include "../../../dllexport_define.inc"

namespace std {

/**
 * Mutual exclusion
 */

class DLLEXPORT mutex {
 private:
  typedef ::mtx_t native_type;

 public:
  typedef native_type* native_handle_type;

  mutex() throw();

  ~mutex();

  void lock();

  bool try_lock();

  void unlock();

  native_handle_type native_handle();

 private:
  native_type mutex_;

  // Intentionally unimplemented to "delete" them.
  mutex(const mutex&);
  mutex& operator=(const mutex&);
};

class DLLEXPORT recursive_mutex {
 private:
  typedef ::mtx_t native_type;

 public:
  typedef native_type* native_handle_type;

  recursive_mutex() throw();

  ~recursive_mutex();

  void lock();

  bool try_lock();

  void unlock();

  native_handle_type native_handle();

 private:
  native_type mutex_;

  // Intentionally unimplemented to "delete" them.
  recursive_mutex(const recursive_mutex&);
  recursive_mutex& operator=(const recursive_mutex&);
};

/**
 * Generic mutex management
 */

template <class Mutex>
class lock_guard {
 public:
  typedef Mutex mutex_type;

  explicit lock_guard(mutex_type& m) {
    this->mutex_ = m;
    m.lock();
  }

  ~lock_guard() {
    mutex_.unlock();
  }

 private:
  mutex_type& mutex_;

  // Intentionally unimplemented to "delete" them.
  lock_guard(const lock_guard&);
  lock_guard& operator=(const lock_guard&);
};

template <class Mutex>
class unique_lock {
 public:
  typedef Mutex mutex_type;

  unique_lock() throw()
      : mutex_(NULL),
        is_owner_(false) {
  }

  explicit unique_lock(mutex_type& m) {
    m.lock();

    this->is_owner_ = true;
    this->mutex_ = &m;
  }

  ~unique_lock() {
    if (this->mutex_ != NULL && this->is_owner_) {
      this->mutex_->unlock();
    }
  }

  void lock() {
    if (this->mutex_ == NULL) {
      throw ::std::runtime_error("::std::unique_lock::lock failure");
    }

    if (this->is_owner_) {
      throw ::std::runtime_error("::std::unique_lock::lock failure");
    }

    this->mutex_->lock();
    this->is_owner_ = true;
  }

  bool try_lock() {
    if (this->mutex_ == NULL) {
      throw ::std::runtime_error("::std::unique_lock::try_lock failure");
    }

    if (this->is_owner_) {
      throw ::std::runtime_error("::std::unique_lock::try_lock failure");
    }

    bool is_try_lock_success = this->mutex_->try_lock();

    if (is_try_lock_success) {
      this->is_owner_ = true;
    }

    return is_try_lock_success;
  }

  void unlock() {
    if (this->mutex_ == NULL) {
      throw ::std::runtime_error("::std::unique_lock::unlock failure");
    }

    if (this->is_owner_) {
      throw ::std::runtime_error("::std::unique_lock::unlock failure");
    }

    this->mutex_->unlock();
    this->is_owner_ = false;
  }

  void swap(unique_lock<Mutex>& other) throw() {
    mutex_type* temp_mutex = this->mutex_;
    bool temp_is_owner = this->is_owner_;

    this->mutex_ = other.mutex_;
    this->is_owner_ = other.is_owner_;

    other.mutex_ = temp_mutex;
    other.is_owner_ = temp_is_owner;
  }

  mutex_type* release() throw() {
    mutex_type* release_mutex = this->mutex_;
    this->mutex_ = NULL;

    return release_mutex;
  }

  mutex_type* mutex() const throw() {
    return this->mutex_;
  }

  bool owns_lock() const throw() {
    return (this->mutex_ != NULL && this->is_owner_);
  }

 private:
  mutex_type* mutex_;
  bool is_owner_;

  // Intentionally unimplemented to "delete" them.
  unique_lock(const unique_lock&);
  unique_lock& operator=(const unique_lock&);
};

/**
 * Call once
 */

class DLLEXPORT once_flag {
 public:
  once_flag() throw();

  friend void call_once(once_flag& flag, void (*func)(void));

 private:
  static const ::once_flag kDefaultInit;

  ::once_flag once_flag_;

  // Intentionally unimplemented to "delete" them.
  once_flag(const once_flag&);
  once_flag& operator=(const once_flag&);
};

DLLEXPORT void call_once(once_flag& flag, void (*func)(void));

} // namespace std

#include "../../../dllexport_undefine.inc"
#endif // __cplusplus >= 201103L || _MSVC_LANG >= 201103L

#endif /* MDC_CPP98_STD_MUTEX_HPP_ */
