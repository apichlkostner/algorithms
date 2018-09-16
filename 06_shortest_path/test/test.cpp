#include "dijkstra.h"
#include "gtest/gtest.h"

using namespace std;

TEST(DijkstraTest, dijkstra_test_graph) {
  // the graph
  graph_t g;
  read_graph_from_file(&g, "../dijkstra_test.txt");

  // find shortes paths with dijkstra algorithm
  auto shortes_path = run_dijkstra(&g);

  EXPECT_EQ(4, boost::num_vertices(g));
  EXPECT_EQ(6, boost::num_edges(g));

  EXPECT_EQ(100, shortes_path[1]);
  EXPECT_EQ(10, shortes_path[2]);
  EXPECT_EQ(105, shortes_path[3]);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}