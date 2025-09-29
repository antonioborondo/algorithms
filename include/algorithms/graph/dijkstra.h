#ifndef ALGORITHMS_GRAPH_DIJKSTRA_H_
#define ALGORITHMS_GRAPH_DIJKSTRA_H_

#include <utility>
#include <vector>

namespace algorithms::graph {

using Neighbor = int;
using Weight = int;
using Edge = std::pair<Neighbor, Weight>;
using Graph = std::vector<std::vector<Edge>>;

std::vector<int> Dijkstra(const Graph& graph, int start, int end);

}  // namespace algorithms::graph

#endif
