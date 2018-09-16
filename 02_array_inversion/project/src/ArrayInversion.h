#ifndef ARRAYINVERSION_H_
#define ARRAYINVERSION_H_

#include <array>

class ArrayInversion {
 public:
  static uint32_t sort_and_count(int *A, size_t n);
  static uint32_t count_split_inv(int *A, size_t n);
};

#endif