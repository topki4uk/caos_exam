//
// Created by alex on 1/16/26.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<int> v;
std::mutex mtx1, mtx2;

void f() {
  mtx1.lock();

  for (int i = 0; i < 1'000'000; ++i) {
    mtx2.lock();
    v.push_back(i);
    mtx1.unlock();
  }

  mtx2.unlock();
}

int main() {
  std::thread t(f);

  f();

  t.join();
}