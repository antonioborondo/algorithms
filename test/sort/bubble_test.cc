#include "algorithms/sort/bubble.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(BubbleTest, BaseTest,
                         testing::Values(&algorithms::sort::bubble::Basic,
                                         &algorithms::sort::bubble::Optimized));

}  // namespace algoriths::sort
