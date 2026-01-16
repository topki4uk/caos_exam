//
// Created by alex on 1/16/26.
//

#include <sched.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int child_func(void *arg) {
  printf("Child thread: PID=%d, TID=%d\n", getpid(), gettid());
  return 0;
}

int main() {
  void *stack = mmap(NULL, 8192, PROT_READ | PROT_WRITE,
    MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, -1, 0);

  clone(child_func, (char*)stack + 8192, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD, NULL);

  sleep(1);
  return 0;
}