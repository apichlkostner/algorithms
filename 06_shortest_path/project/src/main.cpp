#include "dijkstra.h"
#include <iostream>

int main() {
  // the graph
  graph_t g;
  read_graph_from_file(&g);  

  // find shortes paths with dijkstra algorithm
  auto shortes_path = run_dijkstra(&g);

  // result for quiz: shortes paths for the following vertices
  for (auto vertex : {7, 37, 59, 82, 99, 115, 133, 165, 188, 197}) {
    std::cout << shortes_path[vertex - 1] << ",";
  }
  std::cout << std::endl;
}