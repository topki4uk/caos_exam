//
// Created by alex on 1/14/26.
//

#include <cstdio>
#include <cstring>
#include <sys/mman.h>

int main() {
  printf("Before mmap\n");
  getchar();

  char* str = static_cast<char*>(mmap(nullptr, 128 * 1024 * 1024,
    PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

  if (str == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  printf("Mmapped\n");
  getchar();

  strcpy(str, "Hello, mmap!");
  printf("Say it: %s\n", str);

  char* new_str = static_cast<char*>(
    mremap(str, 128 * 1024 *1024, 196 * 1024 * 1024, MREMAP_MAYMOVE)
    );

  if (new_str == MAP_FAILED) {
    perror("mremap");
    return 1;
  }

  printf("Mremapped\n");
  getchar();

  if (munmap(new_str, 196 * 1024 * 1024) == -1) {
    perror("munmap");
    return 1;
  }

  return 0;
}