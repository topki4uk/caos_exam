//
// Created by alex on 1/14/26.
//

#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("failed to start\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  printf("Before mmap\n");
  getchar();

  char* str = static_cast<char*>(mmap(nullptr, 128,
    PROT_READ, MAP_PRIVATE, fd, 0));

  if (str == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  printf("Mmapped\n");
  getchar();

  printf("%s\n", str);

  munmap(str, 128);
  close(fd);

  printf("Munmapped\n");
  getchar();

  return 0;
}