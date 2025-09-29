#include "algorithms/sort/heap.h"

#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

INSTANTIATE_TEST_SUITE_P(HeapTest, BaseTest,
                         testing::Values(&algorithms::sort::Heap));

}  // namespace algoriths::sort
