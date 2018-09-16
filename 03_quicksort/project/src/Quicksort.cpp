#include "Quicksort.h"
#include <iostream>

#define PIVOT_LEFT 0
#define PIVOT_RIGHT 1
#define PIVOT_MEDIAN 2
#define PIVOT_TYPE PIVOT_MEDIAN

uint32_t Quicksort::sort(std::vector<int>& A) {
  return sort_rec(A, 0, A.size() - 1);
}

// sorts array with quicksort
// returns number of compares
uint32_t Quicksort::sort_rec(std::vector<int>& A, size_t l, size_t r) {
  size_t i = l + 1;

  int p = pivot(A, l, r);

  for (auto j = l + 1; j <= r; j++) {
    if (A[j] < p) {
      std::swap(A[i], A[j]);
      i++;
    }
  }

  A[l] = A[i - 1];
  A[i - 1] = p;

  size_t pos_p = i - 1;

  uint32_t nl = 0;
  uint32_t nr = 0;

  if (l < pos_p - 1) nl = sort_rec(A, l, pos_p - 1);
  if (r > pos_p + 1) nr = sort_rec(A, pos_p + 1, r);

  return nl + nr + (r - l);
}

// return the pivot for quicksort
int Quicksort::pivot(std::vector<int>& A, size_t l, size_t r) {
#if PIVOT_TYPE == PIVOT_LEFT
  int p = A[l];
#elif PIVOT_TYPE == PIVOT_RIGHT
  int p = A[r];
  A[r] = A[l];
#elif PIVOT_TYPE == PIVOT_MEDIAN
  // median of three
  size_t m = (l + r) / 2;
  size_t e0 = l;
  size_t e1 = m;
  size_t e2 = r;

  if (A[e2] < A[e0]) std::swap(e2, e0);
  if (A[e1] < A[e0]) std::swap(e1, e0);
  if (A[e2] < A[e1]) std::swap(e1, e2);

  int p = A[e1];
  A[e1] = A[l];
#endif

  return p;
}