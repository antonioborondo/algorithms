#include "algorithms/search/linear.h"

#include <vector>

#include <gtest/gtest.h>

namespace algoriths::search {

class LinearTest : public testing::Test {
 protected:
  const std::vector<int> kListUnsorted{3, 4, 1, 9, 2, 5, 7, 0, 8, 6};
  const std::vector<int> kListSorted{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int kTargetExisting{6};
  const int kTargetUnexisting{10};
};

TEST_F(LinearTest, BasicSearchFindsExistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Basic(kListUnsorted, kTargetExisting)};

  const auto index_expected{9};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(LinearTest, BasicSearchDoesNotFindUnexistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Basic(kListUnsorted, kTargetUnexisting)};

  const auto index_expected{-1};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(LinearTest, SentinelSearchFindsExistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Sentinel(kListUnsorted, kTargetExisting)};

  const auto index_expected{9};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(LinearTest, SentinelSearchDoesNotFindUnexistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Sentinel(kListUnsorted, kTargetUnexisting)};

  const auto index_expected{-1};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(LinearTest, SortedSearchFindsExistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Sorted(kListSorted, kTargetExisting)};

  const auto index_expected{6};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(LinearTest, SortedSearchDoesNotFindUnexistingTarget) {
  const auto index_actual{
      algorithms::search::linear::Sorted(kListSorted, kTargetUnexisting)};

  const auto index_expected{-1};
  ASSERT_EQ(index_expected, index_actual);
}

}  // namespace algoriths::search
