#include "gtest/gtest.h"
#include "Graph.h"

using namespace sgraph;
using namespace std;


TEST(RandomContractionTest, findEdgeTest) {
  Graph graph("../../test3.txt");
  
  Vertex *v0, *v1;
  
  graph.findEdge(0, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(2, v1->id_);

  graph.findEdge(1, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(3, v1->id_);

  graph.findEdge(6, &v0, &v1);
  EXPECT_EQ(3, v0->id_);
  EXPECT_EQ(1, v1->id_);

  graph.findEdge(11, &v0, &v1);
  EXPECT_EQ(4, v0->id_);
  EXPECT_EQ(3, v1->id_);

  graph.findEdge(12, &v0, &v1);
  EXPECT_EQ(nullptr, v0);
  EXPECT_EQ(nullptr, v1);
}

TEST(RandomContractionTest, mergeVerticesTest) {
  Graph graph("../../test3.txt");
  
  EXPECT_EQ(12, graph.numEdges());
  EXPECT_EQ(4, graph.numVertices());

  Vertex *v0, *v1;

  graph.findEdge(0, &v0, &v1);
  graph.mergeVertices(v0, v1);
  
  EXPECT_EQ(10, graph.numEdges());
  EXPECT_EQ(3, graph.numVertices());

  // remaining edges
  graph.findEdge(0, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(3, v1->id_);
  
  graph.findEdge(1, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(4, v1->id_);

  // both edges are twice now
  graph.findEdge(2, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(3, v1->id_);

  graph.findEdge(3, &v0, &v1);
  EXPECT_EQ(1, v0->id_);
  EXPECT_EQ(4, v1->id_);

  // next vertex
  graph.findEdge(4, &v0, &v1);
  EXPECT_EQ(3, v0->id_);
  EXPECT_EQ(1, v1->id_);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}