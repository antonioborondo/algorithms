#include "algorithms/sort/selection.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(SelectionTest, BaseTest,
                         testing::Values(&algorithms::sort::Selection));

}  // namespace algoriths::sort
