#include "algorithms/sort/insertion.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(
    InsertionTest, BaseTest,
    testing::Values(&algorithms::sort::insertion::Basic,
                    &algorithms::sort::insertion::Optimized,
                    &algorithms::sort::insertion::Recursive));

}  // namespace algoriths::sort
