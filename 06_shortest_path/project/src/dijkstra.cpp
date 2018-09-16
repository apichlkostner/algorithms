#include "dijkstra.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <numeric>

void read_graph_from_file(graph_t *g, std::string filename) {
  // read graph from file
  std::fstream f;
  f.open(filename, std::ios_base::in);

  std::string line;
  while (std::getline(f, line)) {
    std::vector<std::string> tokens;

    // split with tab
    boost::split(tokens, line, [](char c) { return c == '\t'; });

    // first token is the start vertex, vertex number in file starts with 1
    // so subtract 1 since boost vertices start with 0
    int start = std::stoi(tokens[0]) - 1;
    for (auto token_iter = tokens.begin() + 1; token_iter != tokens.end();
         token_iter++) {
      // following tokens are <end vertex>,<edge length>
      std::vector<std::string> subtokens(2);
      boost::split(subtokens, *token_iter, [](char c) { return c == ','; });
      if (subtokens.size() == 2) {
        int end = std::stoi(subtokens[0]) - 1;
        auto weight = weight_property(std::stoi(subtokens[1]));
        boost::add_edge(start, end, weight, *g);
      }
    }
  }
}

std::vector<int> run_dijkstra(graph_t *g) {
  boost::property_map<graph_t, boost::edge_weight_t>::type weightmap =
      boost::get(boost::edge_weight, *g);
  int num_vertices = boost::num_vertices(*g);
  constexpr int start_vertex = 0;

  // sets with processed and unprocessed vertices
  // start with node 0
  std::vector<int> processed_v{start_vertex};
  // other nodes are still not processed
  std::vector<int> unprocessed_v(num_vertices - 1);
  // TODO: only works with start vertex 0
  std::iota(std::begin(unprocessed_v), std::end(unprocessed_v), 1);
  // shortest paths
  std::vector<int> shortes_path(num_vertices, std::numeric_limits<int>::max());
  shortes_path[start_vertex] = 0;

  while (!unprocessed_v.empty()) {
    int min_dist = std::numeric_limits<int>::max();
    int min_vertex = 0;
    std::vector<int>::iterator min_vertex_it;

    for (auto vertex : processed_v) {
      auto [edgde_start, edge_end] = boost::out_edges(vertex, *g);

      for (auto edge_it = edgde_start; edge_it != edge_end; ++edge_it) {
        int dist = shortes_path[vertex] + weightmap[*edge_it];

        if (dist < min_dist) {
          // TODO: improve efficiency -> save relevant edges in a heap
          auto f = std::find(unprocessed_v.begin(), unprocessed_v.end(),
                             (*edge_it).m_target);
          if (f != unprocessed_v.end()) {
            min_dist = dist;
            min_vertex_it = f;
            min_vertex = (*edge_it).m_target;
          }
        }
      }
    }
    shortes_path[min_vertex] = min_dist;
    processed_v.push_back(min_vertex);
    unprocessed_v.erase(min_vertex_it);
  }

  return shortes_path;
}