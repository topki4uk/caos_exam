//
// Created by alex on 1/13/26.
//

#include <iostream>

int fibonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int a = 5;
  int f = fibonacci(a);

  std::cout << f << '\n';
}
