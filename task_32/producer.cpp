//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("wrong args\n");
    return 1;
  }

  int fd = open("mypipe", O_WRONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  if (write(fd, argv[1], strlen(argv[1])) == -1) {
    perror("write");
    return 1;
  }

  return 0;
}
