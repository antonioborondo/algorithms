#ifndef ALGORITHMS_SORT_INSERTION_H_
#define ALGORITHMS_SORT_INSERTION_H_

#include <vector>

namespace algorithms::sort::insertion {

std::vector<int> Basic(const std::vector<int>& list_unsorted);
std::vector<int> Optimized(const std::vector<int>& list_unsorted);
std::vector<int> Recursive(const std::vector<int>& list_unsorted);

}  // namespace algorithms::sort::insertion

#endif
