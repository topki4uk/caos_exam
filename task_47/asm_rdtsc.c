//
// Created by alex on 1/16/26.
//

#include <stdio.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
  uint32_t lo, hi;

  __asm__ volatile (
    "rdtsc"
    : "=a"(lo), "=d"(hi)
    :
    : "cc"
  );

  return ((uint64_t)hi << 32) | lo;
}

int main() {
  uint64_t start, end;

  start = rdtsc();

  volatile int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += i;
  }

  end = rdtsc();

  printf("All tacts: %lu\n", end - start);
  printf("%d\n", sum);

  return 0;
}