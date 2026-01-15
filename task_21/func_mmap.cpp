//
// Created by alex on 1/15/26.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char* argv[]) {
  const char* file_name = argv[1];
  int argument = atoi(argv[2]);

  int fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  struct stat st;
  fstat(fd, &st);

  void* addr = mmap(nullptr, st.st_size,
    PROT_READ | PROT_EXEC, MAP_PRIVATE,
    fd, 0);

  int (*func)(int) = (int (*)(int))((char *)addr + 0x40);
  close(fd);

  int result = func(argument);
  printf("Argument: %d\nResult: %d\n", argument, result);
  munmap(addr, st.st_size);
}