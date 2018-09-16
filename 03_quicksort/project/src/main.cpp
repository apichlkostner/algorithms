#include <fstream>
#include <iostream>
#include <vector>
#include "Quicksort.h"

int main() {
  std::fstream f;
  f.open("../../QuickSort.txt", std::ios_base::in);

  std::vector<int> Av;
  int val;
  while (f >> val) {
    Av.push_back(val);
  }

  f.close();

  uint32_t z = Quicksort::sort(Av);

  //for (auto v : Av) std::cout << v << " ";

  std::cout << "-> " << z << std::endl;

  return 0;
}