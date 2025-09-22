#include "algorithms/sort/merge.h"

#include <functional>
#include <vector>

namespace {
void TopDownMerge(std::vector<int>& aux, std::size_t index_begin,
                  std::size_t index_middle, std::size_t index_end,
                  std::vector<int>& result) {
  std::size_t i{index_begin};
  std::size_t j{index_middle};

  for (std::size_t k{index_begin}; k < index_end; ++k) {
    if (i < index_middle && (j >= index_end || result[i] <= result[j])) {
      aux[k] = result[i];
      i++;
    } else {
      aux[k] = result[j];
      j++;
    }
  }
};

void TopDownSplitMerge(std::vector<int>& aux, std::size_t index_begin,
                       std::size_t index_end, std::vector<int>& result) {
  if (index_end - index_begin <= 1) {
    return;
  }

  auto index_middle{(index_end + index_begin) / 2};

  TopDownSplitMerge(result, index_begin, index_middle, aux);
  TopDownSplitMerge(result, index_middle, index_end, aux);

  TopDownMerge(aux, index_begin, index_middle, index_end, result);
}
}  // namespace

namespace algorithms::sort::merge {

std::vector<int> TopDown(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};
  std::vector<int> aux{list_unsorted};

  TopDownSplitMerge(result, 0, result.size(), aux);

  return result;
}

}  // namespace algorithms::sort::merge
