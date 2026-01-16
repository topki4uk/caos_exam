//
// Created by alex on 1/16/26.
//

#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <atomic>

class FutexMutex {
  std::atomic<int> val; // 0 - свободен, 1 - занят
public:
  FutexMutex() : val(0) {}

  void lock() {
    int expected = 0;
    while (!val.compare_exchange_weak(expected, 1, std::memory_order_acquire)) {
      syscall(SYS_futex, &val, FUTEX_WAIT, 1, nullptr, nullptr, 0);
      expected = 0;
    }
  }

  void unlock() {
    val.store(0, std::memory_order_release);
    syscall(SYS_futex, &val, FUTEX_WAKE, 1, nullptr, nullptr, 0);
  }
};