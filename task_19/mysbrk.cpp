//
// Created by alex on 1/14/26.
//

#include <iostream>
#include <unistd.h>

int main() {
  int delta = 8 * 1024;
  getchar();
  char* str = static_cast<char*>(sbrk(delta));

  for (int i = 0; i < delta; ++i) {
    str[i] = 'a';
  }

  str[delta - 1] = '\0';
  getchar();
}