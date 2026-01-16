//
// Created by alex on 1/16/26.
//

#include <stdio.h>
#include <emmintrin.h>

#define ARRAY_SIZE 8

int main() {
  alignas(16) float a[ARRAY_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  alignas(16) float b[ARRAY_SIZE] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};

  __m128 sum = _mm_setzero_ps();
  for (int i = 0; i < ARRAY_SIZE; i += 4) {
    __m128 a_vec = _mm_loadu_ps(&a[i]);
    __m128 b_vec = _mm_loadu_ps(&b[i]);
    __m128 prod = _mm_mul_ps(a_vec, b_vec);
    sum = _mm_add_ps(sum, prod);
  }

  float result[4];
  _mm_storeu_ps(result, sum);

  float scalar_product = result[0] + result[1] + result[2] + result[3];
  printf("The scalar product is %f\n", scalar_product);

  return 0;
}
