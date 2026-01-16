//
// Created by alex on 1/16/26.
//

#include <cstring>

void vulnerable() {
  char buf[16];
  strcpy(buf, "very long string that overflows buffer");
}

int main() {
  vulnerable();
}