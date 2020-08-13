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

#include "../../../../include/mdc/std/threads.h"

#if __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__)

int mtx_init(mtx_t* mutex, int type) {
  mutex->mutex_ = CreateMutexA(NULL, FALSE, NULL);

  if (mutex->mutex_ == NULL) {
    return thrd_error;
  }

  mutex->type_ = type;
  mutex->is_owned_ = FALSE;

  return thrd_success;
}

int mtx_lock(mtx_t* mutex) {
  DWORD wait_result;
  BOOL is_release_success;

  wait_result = WaitForSingleObject(mutex->mutex_, INFINITE);

  if (wait_result == WAIT_FAILED) {
    return thrd_error;
  }

  /*
  * If the mutex is not recursive, then error on recursive locking.
  */
  if (!(mutex->type_ & mtx_recursive) && mutex->is_owned_) {
    is_release_success = ReleaseMutex(mutex->mutex_);
    return thrd_error;
  }

  mutex->is_owned_ = TRUE;

  return thrd_success;
}

int mtx_trylock(mtx_t* mutex) {
  DWORD wait_result;
  BOOL is_release_success;

  wait_result = WaitForSingleObject(mutex->mutex_, 0);

  switch (wait_result) {
    case WAIT_TIMEOUT: {
      return thrd_busy;
    }

    case WAIT_FAILED: {
      return thrd_error;
    }

    default: {
      break;
    }
  }

  /*
  * If the mutex is not recursive, then return non-success on
  * recursive locking.
  */
  if (!(mutex->type_ & mtx_recursive) && mutex->is_owned_) {
    is_release_success = ReleaseMutex(mutex->mutex_);

    if (!is_release_success) {
      return thrd_error;
    }

    return thrd_busy;
  }

  mutex->is_owned_ = TRUE;

  return thrd_success;
}

int mtx_unlock(mtx_t *mutex) {
  BOOL is_release_success;

  is_release_success = ReleaseMutex(mutex);

  if (!is_release_success) {
    return thrd_error;
  }

  mutex->is_owned_ = FALSE;

  return thrd_success;
}

void mtx_destroy(mtx_t* mutex) {
  CloseHandle(mutex->mutex_);
}

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
