#include "algorithms/graph/dijkstra.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algorithms::graph {

TEST(DijkstraTest, Dijkstra) {
  // https://www.youtube.com/watch?v=gdmfOwyQlcI

  Graph kGraph = {{{1, 4}, {2, 3}, {4, 7}},   // 0 - A
                  {{2, 6}, {3, 5}},           // 1 - B
                  {{3, 11}, {4, 8}},          // 2 - C
                  {{4, 2}, {5, 2}, {6, 10}},  // 3 - D
                  {{6, 5}},                   // 4 - E
                  {{6, 3}},                   // 5 - F
                  {}};                        // 6 - G

  const auto path_actual{algorithms::graph::Dijkstra(kGraph, 0, 5)};

  const std::vector<int> kPathExpected{0, 1, 3, 5};

  ASSERT_THAT(path_actual, testing::ContainerEq(kPathExpected));
}

}  // namespace algorithms::graph
