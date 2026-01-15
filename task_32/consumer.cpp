//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("mypipe", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char buffer[256];
  if (read(fd, buffer, 256) == -1) {
    perror("read");
    return 1;
  }

  printf("%s\n", buffer);
  return 0;
}