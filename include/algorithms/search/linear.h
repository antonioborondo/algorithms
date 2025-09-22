#ifndef ALGORITHMS_SEARCH_LINEAR_H_
#define ALGORITHMS_SEARCH_LINEAR_H_

#include <vector>

namespace algorithms::search::linear {

int Basic(const std::vector<int>& list_unsorted, int target);
int Sentinel(const std::vector<int>& list_unsorted, int target);
int Sorted(const std::vector<int>& list_sorted, int target);

}  // namespace algorithms::search::linear

#endif
