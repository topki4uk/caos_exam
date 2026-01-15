//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void siguser1_handler(int sig) {
  printf("Catch a signal %d, wake up!\n", sig);
}

int main() {
  signal(SIGUSR1, siguser1_handler);

  printf("This process has pid = %d\n", getpid());

  printf("Sleep with pause()...\n");
  pause();

  printf("Waked up\n");
  return 0;
}