//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <unistd.h>

int main() {
  char* argv[] = {"/bin/ls", "-la", ".", nullptr};
  char* envp[] = {nullptr};
  printf("# ls -la .\n");

  execve("/bin/ls", argv, envp);
  perror("execve");

  return 1;
}