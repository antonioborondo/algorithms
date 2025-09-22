#include "algorithms/search/binary.h"

#include <vector>

#include <gtest/gtest.h>

namespace algoriths::search {

class BinaryTest : public testing::Test {
 protected:
  const std::vector<int> kListSorted{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int kTargetExisting{6};
  const int kTargetUnexisting{10};
};

TEST_F(BinaryTest, IterativeSearchFindsExistingTarget) {
  const auto index_actual{
      algorithms::search::binary::Iterative(kListSorted, kTargetExisting)};

  const auto index_expected{6};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(BinaryTest, IterativeSearchDoesNotFindUnexistingTarget) {
  const auto index_actual{
      algorithms::search::binary::Iterative(kListSorted, kTargetUnexisting)};

  const auto index_expected{-1};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(BinaryTest, RecursiveSearchFindsExistingTarget) {
  const auto index_actual{
      algorithms::search::binary::Recursive(kListSorted, kTargetExisting)};

  const auto index_expected{6};
  ASSERT_EQ(index_expected, index_actual);
}

TEST_F(BinaryTest, RecursiveSearchDoesNotFindUnexistingTarget) {
  const auto index_actual{
      algorithms::search::binary::Recursive(kListSorted, kTargetUnexisting)};

  const auto index_expected{-1};
  ASSERT_EQ(index_expected, index_actual);
}

}  // namespace algoriths::search
