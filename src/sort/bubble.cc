#include "algorithms/sort/bubble.h"

#include <vector>

namespace algorithms::sort::bubble {

std::vector<int> Basic(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  auto swapped{false};
  do {
    swapped = false;
    for (int i{}; i < result.size() - 1; ++i) {
      if (result.at(i) > result.at(i + 1)) {
        std::swap(result.at(i), result.at(i + 1));
        swapped = true;
      }
    }
  } while (swapped);

  return result;
}

std::vector<int> Optimized(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  std::size_t range{result.size() - 1};
  auto swapped{false};
  do {
    swapped = false;
    for (int i{}; i < range; ++i) {
      if (result.at(i) > result.at(i + 1)) {
        std::swap(result.at(i), result.at(i + 1));
        swapped = true;
      }
    }
    --range;
  } while (swapped);

  return result;
}

}  // namespace algorithms::sort::bubble
