#include "algorithms/sort/quicksort.h"

#include <vector>

namespace algorithms::sort {

namespace {

int Partition(std::vector<int>& result, int index_low, int index_high) {
  int index_pivot{result[index_high]};
  int i{index_low - 1};

  for (int j{index_low}; j < index_high; ++j) {
    if (result[j] <= index_pivot) {
      i++;
      std::swap(result[i], result[j]);
    }
  }
  std::swap(result[i + 1], result[index_high]);
  return i + 1;
}

void QuicksortRecursive(std::vector<int>& result, int index_low,
                        int index_high) {
  if (index_low < index_high) {
    int index_pivot{Partition(result, index_low, index_high)};

    QuicksortRecursive(result, index_low, index_pivot - 1);
    QuicksortRecursive(result, index_pivot + 1, index_high);
  }
}

}  // namespace

std::vector<int> Quicksort(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  QuicksortRecursive(result, 0, result.size() - 1);

  return result;
}

}  // namespace algorithms::sort
