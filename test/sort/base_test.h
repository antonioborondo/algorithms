#ifndef ALGORITHMS_SORT_BASE_TEST_H_
#define ALGORITHMS_SORT_BASE_TEST_H_

#include <functional>
#include <vector>

#include <gtest/gtest.h>

namespace algoriths::sort {

using FunctionParam = std::function<std::vector<int>(const std::vector<int>&)>;

class BaseTest : public testing::TestWithParam<FunctionParam> {
 protected:
  const std::vector<int> kListUnsorted{3, 4, 1, 9, 2, 5, 7, 0, 8, 6};
  const std::vector<int> kListExpected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

}  // namespace algoriths::sort

#endif
