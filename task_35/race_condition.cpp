//
// Created by alex on 1/16/26.
//

#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

std::vector<int> v;

void f() {
  for (int i = 0; i < 1'000'000; ++i) {
    v.push_back(i);
  }
}

int main() {
  std::thread t(f);

  for (int i = 0; i < 1'000'000; ++i) {
    v.push_back(i);
  }

  t.join();
}