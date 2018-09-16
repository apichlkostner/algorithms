#include "ArrayInversion.h"
#include <iostream>

uint32_t ArrayInversion::sort_and_count(int *A, size_t n) {
  if (n == 1) {
    return 0;
  } else {
    auto B = A;
    size_t n_b = n / 2;
    auto C = A + n_b;
    size_t n_c = n - n_b;
    uint32_t x = sort_and_count(B, n_b);
    uint32_t y = sort_and_count(C, n_c);
    uint32_t z = count_split_inv(A, n);

    return x + y + z;
  }
}

uint32_t ArrayInversion::count_split_inv(int *A, size_t n) {
  auto B = A;
  size_t n_b = n / 2;
  auto C = A + n_b;
  size_t n_c = n - n_b;

  size_t i = 0;
  size_t j = 0;
  int z = 0;

  // intermediate array to store result
  int D[n];

  for (size_t k = 0; k < n; k++) {
    if ((j >= n_c) || ((B[i] < C[j]) && (i < n_b))) {
      D[k] = B[i];
      i++;
    } else {
      D[k] = C[j];
      j++;
      z += n_b - i;
    }
  }

  // copy back to A
  for (size_t k = 0; k < n; k++) {
    A[k] = D[k];
  }

#if 0
  std::cout << "n = " << n << " : ";
  for (size_t k = 0; k < n; k++) {
    std::cout << A[k] << " ";
  }
  std::cout << " z = " << z << std::endl;
#endif

  return z;
}