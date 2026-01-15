//
// Created by alex on 1/15/26.
//

#include <cerrno>
#include <csignal>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void sigpipe_handler(int sig) {
  printf("BROKEN PIPE!\n");
}

int main() {
  signal(SIGPIPE, sigpipe_handler);

  int pipefd[2];

  if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
  }

  close(pipefd[0]);
  const char* msg = "Hello, child process!";
  ssize_t result = write(pipefd[1], msg, strlen(msg) + 1);

  if (result == -1) {
    close(pipefd[1]);

    if (errno == EPIPE) {
      printf("failed write: %s\n", strerror(errno));
      return 1;
    }

    printf("failed write: %s\n", strerror(errno));
    return 1;
  }

  close(pipefd[1]);
  return 0;
}