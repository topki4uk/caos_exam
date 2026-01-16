//
// Created by alex on 1/16/26.
//

#include <stdio.h>

extern int is_simple(int);

int main() {
  int number;
  scanf("%d", &number);

  int res = is_simple(number);

  printf("Number %d is ", number);

  if (res == 0) {
    printf("prime\n");
  } else {
    printf("NOT prime\n");
  }

  return 0;
}
