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

#include "stdint_tests.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#if defined(__GNUC__)
#include <unistd.h>
#endif

#include <mdc/std/threads.h>

struct MutexedValue {
  mtx_t mutex;
  int value;
};

enum {
  kOnceDefaultValue = 0,
  kOnceTargetValue = 42
};

static int once_value = kOnceDefaultValue;

static int Increment(void* value) {
  int* actual_value = (int*) value;
  int temp;

  /* Separate operations on a copy forces a race condition. */
  temp = *actual_value;
  temp += 1;

  #if defined(_MSC_VER)
  Sleep(1);
  #elif defined(__GNUC__)
  usleep(1);
  #endif

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

static void SetOnceTarget(void) {
  size_t i;

  for (i = 0; i < kOnceTargetValue; i += 1) {
    Increment(&once_value);
  }
}

static int SetOnceTargetMultithread(void* arg) {
  enum {
    kIterationCount = 8
  };

  once_flag* flag = arg;
  size_t i;

  for (i = 0; i < kIterationCount; i += 1) {
    call_once(flag, &SetOnceTarget);
  }

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

static void Mdc_Threads_AssertMutexLockUnlockSingle(void) {
  struct MutexedValue value;

  int mtx_init_result;

  value.value = 0;

  mtx_init_result = mtx_init(&value.mutex, mtx_plain);
  assert(mtx_init_result == thrd_success);

  MutexedIncrement(&value);
  assert(value.value == 1);

  mtx_destroy(&value.mutex);
}

static void Mdc_Threads_AssertMutexLockUnlockMulti(void) {
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

static void Mdc_Threads_AssertCallOnceSingle(void) {
  const once_flag kInitOnceFlag = ONCE_FLAG_INIT;

  once_flag flag = ONCE_FLAG_INIT;

  once_value = kOnceDefaultValue;

  assert(memcmp(&flag, &kInitOnceFlag, sizeof(kInitOnceFlag)) == 0);

  SetOnceTargetMultithread(&flag);

  assert(once_value == kOnceTargetValue);
}

static void Mdc_Threads_AssertCallOnceMulti(void) {
  enum {
    kThreadsCount = 256
  };

  const once_flag kInitOnceFlag = ONCE_FLAG_INIT;

  thrd_t threads[kThreadsCount];
  once_flag flag = ONCE_FLAG_INIT;

  size_t i;
  int thread_create_result;
  int thread_join_result;

  once_value = kOnceDefaultValue;

  assert(memcmp(&flag, &kInitOnceFlag, sizeof(kInitOnceFlag)) == 0);

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_create_result = thrd_create(&threads[i], &SetOnceTargetMultithread, &flag);
    assert(thread_create_result == thrd_success);
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    thread_join_result = thrd_join(threads[i], NULL);
    assert(thread_join_result == thrd_success);
  }

  assert(once_value == kOnceTargetValue);
}

void Mdc_Threads_RunTests(void) {
  Mdc_Threads_AssertRaceCondition();
  Mdc_Threads_AssertMutexLockUnlockSingle();
  Mdc_Threads_AssertMutexLockUnlockMulti();
  Mdc_Threads_AssertCallOnceSingle();
  Mdc_Threads_AssertCallOnceMulti();
}
