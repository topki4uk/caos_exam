//
// Created by alex on 1/15/26.
//

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  int pipefd[2];
  pid_t pid;
  char buffer[100];

  if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
  }

  pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    close(pipefd[1]);

    ssize_t n_bytes = read(pipefd[0], buffer, sizeof(buffer));
    if (n_bytes > 0) {
      printf("Child received: %s\n", buffer);
    }

    close(pipefd[0]);
  } else {
    close(pipefd[0]);

    const char* msg = "Hello, child process!";
    write(pipefd[1], msg, strlen(msg) + 1);
    printf("Parent sent: %s\n", msg);

    close(pipefd[1]);
    wait(NULL);
  }

  return 0;
}