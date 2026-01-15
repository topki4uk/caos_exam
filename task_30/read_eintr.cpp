//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void signal_handler(int sig) {
  printf("Signal %d recieved\n", sig);
}

int main() {
  signal(SIGINT, signal_handler);

  char buffer[100];
  ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));

  while (1) {
    ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (n == -1 && errno == EINTR) {
      continue;
    }

    if (n == -1) {
      perror("read failed");
      break;
    }

    printf("Read %zd bytes\n", bytes_read);
    break;
  }

  return 0;
}
