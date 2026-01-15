//
// Created by alex on 1/15/26.
//

#include <csignal>
#include <cstdio>

void sigsegv_handler(int sig) {
  printf("SIGSEGV handled\n");
  sleep(3);
  printf("SIGSEGV finished\n");
}

int main() {
  signal(SIGSEGV, sigsegv_handler);

  printf("This program has pid %d\n", getpid());
  getchar();

  return 0;
}
