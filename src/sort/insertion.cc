#include "algorithms/sort/insertion.h"

#include <functional>
#include <vector>

namespace algorithms::sort::insertion {

std::vector<int> Basic(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  for (std::size_t i{1}; i < result.size(); ++i) {
    for (std::size_t j{i}; (j > 0) && (result[j - 1] > result[j]); --j) {
      std::swap(result[j], result[j - 1]);
    }
  }

  return result;
}

std::vector<int> Optimized(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  for (std::size_t i{1}; i < result.size(); ++i) {
    const auto x{result[i]};
    std::size_t j{i};
    while ((j > 0) && (result[j - 1] > x)) {
      result[j] = result[j - 1];
      --j;
    }
    result[j] = x;
  }

  return result;
}

std::vector<int> Recursive(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  std::function<void(int n)> aux = [&](int n) {
    if (n > 0) {
      aux(n - 1);
      const auto x{result[n]};
      std::size_t j{static_cast<std::size_t>(n - 1)};
      while ((j >= 0) && (result[j] > x)) {
        result[j + 1] = result[j];
        --j;
      }
      result[j + 1] = x;
    }
  };

  aux(result.size() - 1);

  return result;
}

}  // namespace algorithms::sort::insertion
