//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
  printf("Before CPU decreasing\n");
  struct rlimit rlim;
  getrlimit(RLIMIT_CPU, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);

  getchar();
  rlim.rlim_cur = 0;
  setrlimit(RLIMIT_CPU, &rlim);
  printf("After CPU decreasing\n");

  getrlimit(RLIMIT_CPU, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);
  getchar();

  while (1) {

  }
}