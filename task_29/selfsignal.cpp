//
// Created by alex on 1/15/26.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void usr1_handler(int sig) {
  printf("Recived user signal 1\n");
}

int main() {
  signal(SIGUSR1, usr1_handler);

  int result = raise(SIGUSR1);
  if (result != 0) {
    perror("raise");
  }

  printf("signal sent\n");
  return 0;
}