//
// Created by alex on 1/14/26.
//

#include <cstdio>
#include <vector>

int main() {
  std::vector<int> v;

  getchar();
  for (int i = 0; i < 100'000'000; ++i) {
    v.push_back(i);
  }

  return 0;
}