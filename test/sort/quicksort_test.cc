#include "algorithms/sort/quicksort.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(QuicksortTest, BaseTest,
                         testing::Values(&algorithms::sort::Quicksort));

}  // namespace algoriths::sort
