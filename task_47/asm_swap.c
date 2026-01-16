//
// Created by alex on 1/16/26.
//

#include <stdio.h>

int main() {
  int a = 10, b = 20;

  printf("a = %d, b = %d\n", a, b);

  __asm__ volatile (
    "xor %1, %0\n\t"
    "xor %0, %1\n\t"
    "xor %1, %0"
    : "+r"(a), "+r"(b)
    :
    : "cc"
  );

  printf("a = %d, b = %d\n", a, b);
  return 0;
}