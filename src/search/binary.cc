#include "algorithms/search/binary.h"

#include <functional>
#include <vector>

namespace algorithms::search::binary {

int Iterative(const std::vector<int>& list_sorted, int target) {
  int index{-1};
  int left{};
  int right{static_cast<int>(list_sorted.size()) - 1};

  while (left <= right) {
    const auto middle{left + ((right - left) / 2)};
    if (list_sorted[middle] < target) {
      left = middle + 1;
    } else if (list_sorted[middle] > target) {
      right = middle - 1;
    } else if (list_sorted[middle] == target) {
      index = middle;
      break;
    }
  }

  return index;
}

int Recursive(const std::vector<int>& list_sorted, int target) {
  int index{-1};
  int left{};
  int right{static_cast<int>(list_sorted.size()) - 1};

  std::function<int(int, int)> aux = [&](int left, int right) -> int {
    if (left <= right) {
      const auto middle{left + ((right - left) / 2)};
      if (list_sorted[middle] < target) {
        index = aux(middle + 1, right);
      } else if (list_sorted[middle] > target) {
        index = aux(left, middle - 1);
        right = middle - 1;
      } else if (list_sorted[middle] == target) {
        index = middle;
      }
    }
    return index;
  };

  return aux(left, right);
}

}  // namespace algorithms::search::binary
