# Shortes path with Dijkstra algorthm

## Graph implementation

### Boost graph

```
auto [vertex_start, vertex_end] = boost::vertices(g)
auto [edgde_start, edge_end] = boost::out_edges(*vertex_it, g);
boost::num_edges(g)
boost::num_vertices(g)
```

## Build

Build with Ninja instead of make is a bit faster: `cmake .. -G Ninja`

Warning and error colors are enabled for Ninja in cmake.txt.