#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

int main() {
  size_t amin = 10000000;
  std::random_device rd;
  std::mt19937 gen(rd());

  for (size_t i = 0; i < 1000; i++) {
    sgraph::Graph graph("../../kargerMinCut.txt");

    while (graph.numVertices() > 2) {
      auto msize = graph.numEdges();

      // take one edge randomly chosen
      std::uniform_int_distribution<> dis(0, msize - 1);
      size_t a = dis(gen);
      sgraph::Vertex *a1 = nullptr, *a2 = nullptr;
      graph.findEdge(a, &a1, &a2);

      // merge the vertices of this edge
      graph.mergeVertices(a1, a2);
    }

    // take half of the edges since the graph is undirected
    size_t current = graph.numEdges() / 2;
    
    if (amin > current) {
      amin = current;
      std::cout << "\nMinCut = " << amin << std::endl;
      std::cout << graph.to_string();
    }

    // show user program is still running
    if (i % 100 == 99) std::cout << "." << std::flush;
  }

  return 0;
}