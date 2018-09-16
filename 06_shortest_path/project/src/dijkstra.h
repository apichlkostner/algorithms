#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <boost/graph/adjacency_list.hpp>

typedef boost::property<boost::edge_weight_t, int> weight_property;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
                              boost::no_property, weight_property>
    graph_t;
typedef boost::graph_traits<graph_t>::edge_descriptor edge_descriptor;


extern void read_graph_from_file(graph_t *g, std::string filename="../../dijkstraData.txt");
extern std::vector<int> run_dijkstra(graph_t *g);

#endif