//
// Created by alex on 1/15/26.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void signal_handler(int sig) {
  printf("Signal %d recieved\n", sig);
}

int main() {
  char buffer[100];
  struct sigaction sa;

  sa.sa_handler = signal_handler;
  sa.sa_flags = SA_RESTART;
  sigemptyset(&sa.sa_mask);

  sigaction(SIGINT, &sa, NULL);

  ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
  printf("Read %zd bytes\n", bytes_read);

  return 0;
}
