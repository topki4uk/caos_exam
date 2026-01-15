//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <cstdlib>
#include <signal.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Bad args\n");
    return 1;
  }

  int pid = atoi(argv[1]);
  if (kill(pid, SIGKILL) == -1) {
    perror("kill");
    return 1;
  }

  return 0;
}