#include "Graph.h"
#include <assert.h>
#include <algorithm>

namespace sgraph {

Graph::Graph(std::string fn) : num_edges_(0) {
  std::fstream f;
  f.open(fn, std::ios_base::in);

  for (auto i = 0u; i < 200; i++) {
    sgraph::Vertex v(i + 1);
    vertices_v_.push_back(v);
  }

  std::string line;
  while (std::getline(f, line)) {
    std::istringstream iss(line);
    int val;

    iss >> val;

    auto& vertex = vertices_v_[val - 1];

    while (iss >> val) {
      num_edges_++;
      vertex.edges_.push_back(&vertices_v_[val - 1]);
    }

    addVertex(&vertex);
  }

  f.close();
}

void Graph::mergeVertices(Vertex* v0, Vertex* v1) {
  size_t old_size = v0->edges_.size();
  num_edges_ -= v1->edges_.size();

  // the following would be self references
  v0->edges_.remove(v1);
  v1->edges_.remove(v0);
  num_edges_ -= old_size - v0->edges_.size();

  vertices_.remove(v1);

  // map all edges from the old to the new merged vertex
  for (auto& conn_vertex : v1->edges_) {
    auto& vedges = conn_vertex->edges_;

    std::replace(vedges.begin(), vedges.end(), v1, v0);

    v0->edges_.push_back(conn_vertex);
    num_edges_++;
  }

  assert(countEdges() == num_edges_);
}

void Graph::findEdge(size_t pos, Vertex** v0, Vertex** v1) {
  *v0 = nullptr;
  *v1 = nullptr;

  for (auto v : vertices_) {
    if (v->edges_.size() <= pos) {
      pos -= v->edges_.size();
    } else {
      *v0 = v;

      auto v_it = v->edges_.begin();
      std::advance(v_it, pos);

      *v1 = *v_it;

      break;
    }
  }
}

std::string Graph::to_string() {
  std::string ret_str;
  for (auto v : vertices_) {
    ret_str += std::to_string(v->id_);
    for (auto e : v->edges_) {
      ret_str += " " + std::to_string(e->id_);
    }
    ret_str += "\n";
  }

  return ret_str;
}

}  // namespace sgraph