#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <array>
#include <vector>

class Quicksort {
 public:
  static uint32_t sort(std::vector<int>& A);
  static uint32_t sort_rec(std::vector<int>& A, size_t l, size_t r);

 private:
  static int pivot(std::vector<int>& A, size_t l, size_t r);
};

#endif