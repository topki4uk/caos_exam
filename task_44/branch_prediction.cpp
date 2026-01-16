//
// Created by alex on 1/16/26.
//

#include <algorithm>
#include <cstdlib>
#include <iostream>

const int size = 100'000;
int arr[size];

int main() {
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % 256;
  }

  // std::sort(arr, arr + size);

  long long sum = 0;
  for (int k = 0; k < 10000; ++k) {
    for (int i = 0; i < size; i++) {
      if (arr[i] >= 128) {
        sum += arr[i];
      }
    }
  }

  std::cout << sum << '\n';
}
