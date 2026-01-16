//
// Created by alex on 1/16/26.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<int> v;
std::mutex mtx;

void f() {
  for (int i = 0; i < 1'000'000; ++i) {
    mtx.lock();
    v.push_back(i);
    mtx.unlock();
  }
}

int main() {
  std::thread t(f);

  for (int i = 0; i < 1'000'000; ++i) {
    mtx.lock();
    v.push_back(i);
    mtx.unlock();
  }

  t.join();
}