//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <unistd.h>

int main() {
  int pid = fork();

  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    printf("Child process has pid = %d\n", getpid());
    for (int i = 0; i < 100; ++i) {
      printf("Child i = %d\n", i);
    }
  } else {
    printf("Parent process has pid = %d\n", getpid());
    for (int i = 0; i < 10; ++i) {
      printf("Parent i = %d\n", i);
    }
  }

  return 0;
}