//
// Created by alex on 1/14/26.
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc < 3  || argc > 4) {
    printf("Usage: ./myln [-s] [filename] [linkname]\n");
    return 1;
  }

  if (argc == 3) {
    if (link(argv[1], argv[2]) == -1) {
      printf("link error: %s\n", strerror(errno));
      return 1;
    }
  }

  if (argc == 4 && strcmp(argv[1], "-s") == 0) {
    if (symlink(argv[2], argv[3]) == -1) {
      printf("symlink error: %s\n", strerror(errno));
      return 1;
    }
  }

  return 0;
}