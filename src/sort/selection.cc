#include "algorithms/sort/selection.h"

#include <vector>

namespace algorithms::sort {

std::vector<int> Selection(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  for (std::size_t i{}; i < result.size(); ++i) {
    auto min{i};
    for (std::size_t j{i + 1}; j < result.size(); ++j) {
      if (result[j] < result[min]) {
        min = j;
      }
    }
    if (min != i) {
      std::swap(result[i], result[min]);
    }
  }

  return result;
}

}  // namespace algorithms::sort
