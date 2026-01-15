//
// Created by alex on 1/13/26.
//

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc <= 2) {
    printf("need more arguments\n");
    return 1;
  }

  char buffer[256];

  strcpy(buffer, argv[1]);

  int saved_out = dup(1);
  for (int i = 0; i < argc - 2; ++i) {
    int fd = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
      printf("open failed: %s\n", strerror(errno));
      continue;
    }

    dup2(fd, 1);
    std::cout << buffer << '\n';
    std::cout.flush();

    dup2(saved_out, 1);
    close(fd);
  }

  dup2(saved_out, 1);
  close(saved_out);

  return 0;
}