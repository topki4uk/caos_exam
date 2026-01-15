//
// Created by alex on 1/15/26.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int pipefd[2];
  pid_t pid1, pid2;

  if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
  }

  pid1 = fork();
  if (pid1 == 0) {
    dup2(pipefd[1], STDOUT_FILENO);

    close(pipefd[0]);
    close(pipefd[1]);

    execlp("ls", "ls", "-la", NULL);
    perror("execlp ls");
    return 1;
  }

  pid2 = fork();
  if (pid2 == 0) {
    dup2(pipefd[0], STDIN_FILENO);

    close(pipefd[0]);
    close(pipefd[1]);

    execlp("grep", "grep", "c", NULL);
    perror("execlp");
    return 1;
  }

  close(pipefd[0]);
  close(pipefd[1]);

  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);

  return 0;
}