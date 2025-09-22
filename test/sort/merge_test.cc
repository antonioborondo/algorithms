#include "algorithms/sort/merge.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(MergeTest, BaseTest,
                         testing::Values(&algorithms::sort::merge::TopDown));

}  // namespace algoriths::sort
