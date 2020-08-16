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

#include "stdint_tests.h"

#include <assert.h>
#include <stdio.h>

#include <mdc/std/threads.h>

struct MutexedValue {
  mtx_t mutex;
  int value;
};

static int Increment(void* value) {
  int* actual_value = (int*) value;
  int temp;

  /* Separate operations on a copy forces a race condition. */
  temp = *actual_value;
  temp += 1;
  Sleep(1);

  *actual_value = temp;

  return 0;
}

static int MutexedIncrement(void* arg) {
  struct MutexedValue* mutexed_value = arg;
  int mtx_lock_result;
  int mtx_unlock_result;

  mtx_lock_result = mtx_lock(&mutexed_value->mutex);
  assert(mtx_lock_result == thrd_success);

  Increment(&mutexed_value->value);

  mtx_unlock_result = mtx_unlock(&mutexed_value->mutex);
  assert(mtx_unlock_result == thrd_success);

  return 0;
}

static void Mdc_Threads_AssertRaceCondition(void) {
  enum {
    kThreadsCount = 256
  };

  thrd_t threads[kThreadsCount];

  size_t i;
  int thread_create_result;
  int thread_join_result;

  int value;

  value = 0;

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_create_result = thrd_create(&threads[i], &Increment, &value);
    assert(thread_create_result == thrd_success);
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_join_result = thrd_join(threads[i], NULL);
    assert(thread_join_result == thrd_success);
  }

  assert(value > 0);
  assert(value <= kThreadsCount);
}

static void Mdc_Threads_AssertMutexLockUnlock(void) {
  enum {
    kThreadsCount = 256
  };

  thrd_t threads[kThreadsCount];
  struct MutexedValue value;

  size_t i;
  int mtx_init_result;
  int thread_create_result;
  int thread_join_result;

  value.value = 0;

  mtx_init_result = mtx_init(&value.mutex, mtx_plain);
  assert(mtx_init_result == thrd_success);

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_create_result = thrd_create(&threads[i], &MutexedIncrement, &value);
    assert(thread_create_result == thrd_success);
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_join_result = thrd_join(threads[i], NULL);
    assert(thread_join_result == thrd_success);
  }

  assert(value.value == kThreadsCount);

  mtx_destroy(&value.mutex);
}

void Mdc_Threads_RunTests(void) {
  Mdc_Threads_AssertRaceCondition();
  Mdc_Threads_AssertMutexLockUnlock();
}
