cmake_minimum_required(VERSION 3.25.1)

project(algorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(algorithms
  src/search/binary.cc
  src/search/linear.cc
  src/sort/bubble.cc
  src/sort/insertion.cc
  src/sort/merge.cc
  src/sort/quicksort.cc
  src/sort/selection.cc
)

target_include_directories(algorithms
  PUBLIC
  include
)

find_package(GTest REQUIRED)

add_executable(algorithms_test
  test/search/binary_test.cc
  test/search/linear_test.cc
  test/sort/base_test.cc
  test/sort/bubble_test.cc
  test/sort/insertion_test.cc
  test/sort/merge_test.cc
  test/sort/quicksort_test.cc
  test/sort/selection_test.cc
)

target_include_directories(algorithms_test
  PRIVATE
  test/
)

target_link_libraries(algorithms_test
  PRIVATE
  algorithms
  GTest::gmock
  GTest::gtest_main
)

enable_testing()

add_test(NAME algorithms_test COMMAND algorithms_test)
