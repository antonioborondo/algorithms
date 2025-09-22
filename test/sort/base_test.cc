#include "sort/base_test.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace algoriths::sort {

TEST_P(BaseTest, SortUnsortedList) {
  auto function{GetParam()};
  const auto list_actual{function(kListUnsorted)};

  ASSERT_THAT(list_actual, testing::ContainerEq(kListExpected));
}

}  // namespace algoriths::sort
