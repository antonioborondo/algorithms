#include "algorithms/graph/dijkstra.h"

#include <algorithm>
#include <limits>
#include <vector>

namespace algorithms::graph {

std::vector<int> Dijkstra(const Graph& graph, int node_start, int node_end) {
  std::vector<int> visited;
  std::vector<int> distances(graph.size(), std::numeric_limits<int>::max());
  std::vector<int> previous(graph.size(), -1);

  int node_current{node_start};
  distances[node_current] = 0;

  do {
    visited.push_back(node_current);

    for (const auto& [neighbor, weight] : graph[node_current]) {
      int new_distance{distances[node_current] + weight};
      if (distances[neighbor] > new_distance) {
        distances[neighbor] = new_distance;
        previous[neighbor] = node_current;
      }
    }

    // Find the minimum value not visited
    int minimum_distance{std::numeric_limits<int>::max()};
    for (int node_next{0}; node_next < distances.size(); ++node_next) {
      if (std::find(visited.begin(), visited.end(), node_next) ==
          visited.end()) {
        if (distances[node_next] < minimum_distance) {
          minimum_distance = distances[node_next];
          node_current = node_next;
        }
      }
    }

  } while (visited.size() < graph.size());

  std::vector<int> path;
  int previous_index{node_end};
  while (previous_index != -1) {
    path.push_back(previous_index);
    previous_index = previous[previous_index];
  }

  std::reverse(path.begin(), path.end());

  return path;
}

}  // namespace algorithms::graph
