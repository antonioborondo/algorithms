#include "algorithms/search/linear.h"

#include <vector>

namespace algorithms::search::linear {

int Basic(const std::vector<int>& list_unsorted, int target) {
  int index{-1};
  for (std::size_t i{}; i < list_unsorted.size(); ++i) {
    if (list_unsorted[i] == target) {
      index = i;
      break;
    }
  }

  return index;
}

int Sentinel(const std::vector<int>& list_unsorted, int target) {
  std::vector<int> list_aux{list_unsorted};
  const std::size_t list_aux_size{list_aux.size()};
  list_aux.push_back(target);  // Add sentinel equal to target

  int index{-1};
  for (std::size_t i{};; ++i) {
    if (list_aux[i] == target) {
      if (i < list_aux_size) {
        index = i;
      }
      break;
    }
  }

  return index;
}

int Sorted(const std::vector<int>& list_sorted, int target) {
  std::vector<int> list_aux{list_sorted};
  list_aux.push_back(target + 1);  // Add sentinel bigger than target

  int index{-1};
  for (std::size_t i{};; ++i) {
    if (list_aux[i] >= target) {
      if (list_aux[i] == target) {
        index = i;
      }
      break;
    }
  }

  return index;
}

}  // namespace algorithms::search::linear
