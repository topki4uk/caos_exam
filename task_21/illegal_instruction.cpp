//
// Created by alex on 1/15/26.
//

#include <vector>
#include <list>
#include <iostream>
#include <sys/mman.h>
#include <errno.h>

int main() {
  std::vector<char> v;
  for (int i = 0; i < 100000; ++i) {
    v.push_back(i);
  }

  std::cout << "Vector starts at " << (int*)&v[0] << std::endl;
  std::cout << mprotect(&v[0] - 16, 10000, PROT_READ | PROT_WRITE | PROT_EXEC) << std::endl;
  getchar();

  v[0] = 0x33;
  void (*f)() = (void(*)()) &v[0];
  f();
}