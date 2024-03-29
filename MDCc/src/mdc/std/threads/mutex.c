/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2022  Mir Drualga
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

#if defined(_MSC_VER) || defined(__MINGW32__)

int mtx_init(mtx_t* mutex, int type) {
  mutex->mutex_ = CreateMutexA(NULL, FALSE, NULL);

  if (mutex->mutex_ == NULL) {
    goto return_bad;
  }

  mutex->type_ = type;
  mutex->is_owned_ = FALSE;

  return thrd_success;

return_bad:
  return thrd_error;
}

void mtx_destroy(mtx_t* mutex) {
  BOOL close_handle_result;

  close_handle_result = CloseHandle(mutex->mutex_);
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
  BOOL was_owned;

  was_owned = mutex->is_owned_;

  mutex->is_owned_ = FALSE;
  is_release_success = ReleaseMutex(mutex->mutex_);

  if (!is_release_success) {
    goto return_bad;
  }

  return thrd_success;

return_bad:
  mutex->is_owned_ = was_owned;

  return thrd_error;
}

#elif defined(__GNUC__)

#include <errno.h>

/* TODO (Mir Drualga): In Linux, if an error occurs, define _GNU_SOURCE */

int mtx_init(mtx_t* mutex, int type) {
  int init_attr_result;
  int init_mutex_result;

  int mutex_attr_type;
  pthread_mutexattr_t attr;

  init_attr_result = pthread_mutexattr_init(&attr);
  if (init_attr_result != 0) {
    goto return_bad;
  }

  if ((type & mtx_recursive) == mtx_recursive) {
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  } else {
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_DEFAULT);
  }

  init_mutex_result = pthread_mutex_init(mutex, &attr);
  if (init_mutex_result != 0) {
    goto destory_attr;
  }

  pthread_mutexattr_destroy(&attr);

  return thrd_success;

destory_attr:
  pthread_mutexattr_destroy(&attr);

return_bad:
  return thrd_error;
}

void mtx_destroy(mtx_t* mutex) {
  pthread_mutex_destroy(mutex);
}

int mtx_lock(mtx_t* mutex) {
  int result;

  result = pthread_mutex_lock(mutex);

  return (result == 0) ? thrd_success : thrd_error;
}

int mtx_trylock(mtx_t *mutex) {
  int result;

  result = pthread_mutex_lock(mutex);

  if (result == 0) {
    return thrd_success;
  } else if (result == EBUSY || result == EAGAIN) {
    return thrd_busy;
  } else {
    return thrd_error;
  }
}

int mtx_unlock(mtx_t *mutex) {
  int result;

  result = pthread_mutex_unlock(mutex);

  return (result == 0) ? thrd_success : thrd_error;
}

#endif

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
