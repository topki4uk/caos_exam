//
// Created by alex on 1/16/26.
//

int main() {
  int steps = 1024 * 1024 * 1024;
  int a[2] = {0, 0};

  // Loop 1
  // for (int i=0; i<steps; i++) { a[0]++; a[0]++; }

  // Loop 2
  for (int i=0; i<steps; i++) { a[0]++; a[1]++; }

  return 0;
}