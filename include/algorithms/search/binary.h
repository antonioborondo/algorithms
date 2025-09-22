#ifndef ALGORITHMS_SEARCH_BINARY_H_
#define ALGORITHMS_SEARCH_BINARY_H_

#include <vector>

namespace algorithms::search::binary {

int Iterative(const std::vector<int>& list_sorted, int target);
int Recursive(const std::vector<int>& list_sorted, int target);

}  // namespace algorithms::search::binary

#endif
