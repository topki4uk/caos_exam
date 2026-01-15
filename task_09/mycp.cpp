//
// Created by alex on 1/13/26.
//

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>

#define MAX_BUFFER_SIZE (16 * 1024)

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("input failed: 2 args\n");
    return 1;
  }

  int src_fd = open(argv[1], O_RDONLY);
  if (src_fd == -1) {
    printf("open failed: %s\n", strerror(errno));
    return 1;
  }

  char buffer[MAX_BUFFER_SIZE] {};
  if (read(src_fd, buffer, MAX_BUFFER_SIZE) == -1) {
    printf("read failed: %s\n", strerror(errno));
    close(src_fd);
    return 1;
  }
  close(src_fd);

  int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
  if (dest_fd == -1) {
    printf("open failed: %s\n", strerror(errno));
    return 1;
  }

  if (write(dest_fd, buffer, strlen(buffer)) == -1) {
    close(dest_fd);
    printf("write failed: %s\n", strerror(errno));
    return 1;
  }
  close(dest_fd);

  return 0;
}