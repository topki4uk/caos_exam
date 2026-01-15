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

  int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  ftruncate(fd, 128);

  printf("Before mmap\n");
  getchar();

  char* str = static_cast<char*>(mmap(nullptr, 128,
    PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));

  if (str == MAP_FAILED) {
    perror("mmap");
    close(fd);
    return 1;
  }

  printf("Mmapped\n");
  getchar();

  printf("%s\n", str);

  const char* text = " hello from lexa\n";
  memcpy(str + strlen(str), text, strlen(text) + 1);
  printf("%s\n", str);

  if (msync(str, strlen(str), MS_SYNC) == -1) {
    perror("msync");
    close(fd);
    return 1;
  }

  if (munmap(str, 128) == -1) {
    perror("munmap");
  }
  close(fd);

  printf("Munmapped\n");
  getchar();

  return 0;
}