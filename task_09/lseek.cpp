//
// Created by alex on 1/13/26.
//

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>

int main() {
  int fd = open("lseek.txt", O_WRONLY | O_CREAT, 0644);
  if (fd == -1) {
    printf("open failed: %s\n", strerror(errno));
    return 1;
  }

  if (write(fd, "START", 5) == -1) {
    printf("write failed: %s\n", strerror(errno));
    return 1;
  }

  lseek(fd, 1000, SEEK_SET);

  if (write(fd, "END", 3) == -1) {
    printf("write failed: %s\n", strerror(errno));
    return 1;
  }

  close(fd);
  return 0;
}