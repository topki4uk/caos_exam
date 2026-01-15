//
// Created by alex on 1/15/26.
//

#include <iostream>
#include <thread>
#include <unistd.h>

void f() {
  for (int i = 0; i < 1'000; ++i) {
    std::cout << i << std::endl;
  }
}

int main() {
  std::thread t(f);

  for (int i = 0; i < 1'000; ++i) {
    std::cout << i << std::endl;
  }
}