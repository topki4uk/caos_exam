//
// Created by alex on 1/15/26.
//

#include <iostream>
#include <vector>
#include <thread>

std::vector<int> v;
long long arr[2];

void sum(int index, int from, int to) {
  long long result = 0;
  for (int i = from; i < to; ++i) {
    result += v[i];
  }

  arr[index] = result;
  std::cout << index << ' ' << result << std::endl;
}

int main() {
  v.resize(200'000);
  for (auto& x : v) {
    x = rand();
  }

  std::thread t1(sum, 0, 0, 100'000);
  std::thread t2(sum, 1, 100'000, 200'000);

  t1.join();
  t2.join();

  long long result = 0;
  for (int i = 0; i < 2; ++i) {
    result += arr[i];
  }
  std::cout << result << std::endl;

  return 0;
}