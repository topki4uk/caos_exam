//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
  printf("Before VM decreasing\n");
  struct rlimit rlim;
  getrlimit(RLIMIT_AS, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);

  getchar();
  rlim.rlim_cur = 32ul * 1024 * 1024 * 1024 * 1024 * 1024;
  setrlimit(RLIMIT_AS, &rlim);
  printf("After VM decreasing\n");

  getrlimit(RLIMIT_AS, &rlim);
  printf("Soft limit: %lu\nHard limit: %lu\n", rlim.rlim_cur, rlim.rlim_max);
  getchar();
}