//
// Created by alex on 1/13/26.
//

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>

int main() {
  int fd = open("text.txt", O_WRONLY);

  if (fd == -1) {
    printf("open failed: %s\n", strerror(errno));
    return 1;
  }

  char buffer[256];
  if (read(0, buffer, 256) == -1) {
    printf("read failed: %s\n", strerror(errno));
    return 1;
  }

  if (write(fd, buffer, strlen(buffer)) == -1) {
    printf("write failed: %s\n", strerror(errno));
    return 1;
  }

  close(fd);
  return 0;
}