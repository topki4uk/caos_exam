//
// Created by alex on 1/16/26.
//

int arr[64 * 1024 * 1024];

int main() {
  for (int k = 0; k < 30; ++k) {
    for (int i = 0; i < 64 * 1024 * 1024; i+=8) {
      arr[i] *= 3;
    }
  }
}