#ifndef GRAPH_C_
#define GRAPH_C_

#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace sgraph {
// class Vertex;

// struct Edge {
//   Edge(Vertex& vertex) : vertex(vertex) {}
//   Edge& operator=(const Edge& e) {
//       vertex = e.vertex;
//   }

//   bool operator==(const Edge& e) {
//       return (vertex == e.vertex);
//   }
//   Vertex& vertex;
// };

class Vertex {
 public:
  Vertex(size_t id) : id_(id){};
  Vertex() : id_(0){};
  Vertex(Vertex&& v) : edges_(std::move(v.edges_)), id_(v.id_){};
  Vertex(const Vertex& v) : edges_(v.edges_), id_(v.id_){};

  bool operator==(const Vertex& b) const { return id_ == b.id_; }

  std::list<Vertex*> edges_;
  int id_;
};

class Graph {
 public:
  Graph() : num_edges_(0){};
  // constructor loads file with adjacency list
  Graph(std::string fn);

  // merges vertices v0 and v1
  void mergeVertices(Vertex* v0, Vertex* v1);

  // adds new vertex
  void addVertex(Vertex* v) { vertices_.push_back(v); }

  // counts the number of edges for assert
  size_t countEdges() {
    size_t b = 0;
    for (auto v : vertices_) {
      b += v->edges_.size();
    }
    return b;
  }

  // finds edge starting from first vertex, first edge
  void findEdge(size_t pos, Vertex** v0, Vertex** v1);

  std::string to_string();

  size_t numVertices() { return vertices_.size(); }
  size_t numEdges() { return num_edges_; }

 private:
  // list with vertices
  std::list<Vertex*> vertices_;
  // for efficient read of adjacency list file
  std::vector<sgraph::Vertex> vertices_v_;
  // number of egdes
  size_t num_edges_;
};
}  // namespace sgraph

#endif