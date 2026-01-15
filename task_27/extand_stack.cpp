//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
  printf("Before stack increasing\n");
  struct rlimit rlim;
  getrlimit(RLIMIT_STACK, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);

  getchar();
  rlim.rlim_cur = 16 * 1024 * 1024;
  setrlimit(RLIMIT_STACK, &rlim);
  printf("After stack increasing\n");

  getrlimit(RLIMIT_STACK, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);
  getchar();
}