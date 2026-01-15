//
// Created by alex on 1/14/26.
//

#include <cstdio>
#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("secret.txt", O_RDONLY);

  if (fd == -1) {
    printf("open failed: %s\n", strerror(errno));
    return 1;
  }

  char buffer[256];
  if (read(fd, buffer, 256) == -1) {
    printf("read failed: %s\n", strerror(errno));
    return 1;
  }

  printf("%s\n", buffer);
  return 0;
}