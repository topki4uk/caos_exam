//
// Created by alex on 1/13/26.
//

#include <cstdio>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
  char buffer[64] {'H', 'e', 'l', 'l', 'o', ',', ' '};

  if (read(0, buffer + 7, 57) == -1) {
    printf("read failed: %s\n", strerror(errno));
    return 1;
  }

  if (write(1, buffer, 64) == -1) {
    printf("write failed: %s\n", strerror(errno));
    return 1;
  }

  return 0;
}