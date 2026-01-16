//
// Created by alex on 1/16/26.
//

#include <iostream>

int is_simple(int number) {
  if (number < 2) {
    return 1;
  }

  for (int d = 2; d < number; ++d) {
    if (number % d == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  int a;
  std::cin >> a;

  std::cout << is_simple(a) << std::endl;
  return 0;
}