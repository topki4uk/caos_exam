//
// Created by alex on 1/14/26.
//

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: ./myrm [path]\n");
    return 1;
  }

  if (unlink(argv[1]) == -1) {
    printf("unlink failed: %s\n", strerror(errno));
    return 1;
  }

  return 0;
}