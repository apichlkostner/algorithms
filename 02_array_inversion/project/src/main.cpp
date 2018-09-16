#include <fstream>
#include <iostream>
#include <vector>
#include "ArrayInversion.h"

int main() {
  std::fstream f;
  f.open("../../IntegerArray.txt", std::ios_base::in);

  std::vector<int> Av;
  int val;
  while (f >> val) {
    Av.push_back(val);
  }

  f.close();

  uint32_t z = ArrayInversion::sort_and_count(&Av[0], Av.size());

  std::cout << "-> " << z << std::endl;

  return 0;
}