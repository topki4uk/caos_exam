//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <unistd.h>

#include <sys/wait.h>

int main() {
  int pid = fork();

  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    printf("Child process has pid = %d\n", getpid());
    sleep(10);
    printf("Child process finished\n");
  } else {
    printf("Parent process has pid = %d\n", getpid());

    getchar();

    int res;
    int child_pid = wait(&res);
    printf("Child with pid = %d stopped\n", child_pid);
  }

  return 0;
}