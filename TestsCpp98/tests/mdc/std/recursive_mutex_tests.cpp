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

#include "recursive_mutex_tests.hpp"

#include <mdc/std/assert.h>
#include <mdc/std/mutex.hpp>
#include <mdc/std/threads.hpp>
#include "std_example_funcs/std_increment.hpp"

namespace mdc_test {
namespace std_test {
namespace {

struct MutexedValue {
  ::std::recursive_mutex mutex;
  int value;
};

static int RecursiveMutexedIncrement(void* arg) {
  MutexedValue* mutexed_value = reinterpret_cast<MutexedValue*>(arg);

  mutexed_value->mutex.lock();
  mutexed_value->mutex.lock();
  mutexed_value->mutex.lock();
  mutexed_value->mutex.lock();
  mutexed_value->mutex.lock();

  Increment(&mutexed_value->value);

  mutexed_value->mutex.unlock();
  mutexed_value->mutex.unlock();
  mutexed_value->mutex.unlock();
  mutexed_value->mutex.unlock();
  mutexed_value->mutex.unlock();

  return 0;
}

static void AssertMutexLockUnlockSingle() {
  MutexedValue value;

  value.value = 0;

  RecursiveMutexedIncrement(&value);
  assert(value.value == 1);
}

static void AssertMutexLockUnlockMulti() {
  enum {
    kThreadsCount = 256
  };

  size_t i;

  ::std::thread* threads[kThreadsCount];
  MutexedValue value;

  value.value = 0;

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i] = new ::std::thread(
        &RecursiveMutexedIncrement,
        &value
    );
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i]->join();
    delete threads[i];
  }

  assert(value.value == kThreadsCount);
}

} // namespace

void RecursiveMutex_RunTests() {
  AssertMutexLockUnlockSingle();
  AssertMutexLockUnlockMulti();
}

} // namespace std_test
} // namespace mdc_test