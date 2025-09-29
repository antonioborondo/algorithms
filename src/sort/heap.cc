#include "algorithms/sort/heap.h"

#include <vector>

namespace algorithms::sort {

void Heapify(std::vector<int>& arr, int n, int i) {
  int largest = i;        // Initialize largest as root
  int left = 2 * i + 1;   // Left child
  int right = 2 * i + 2;  // Right child

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest]) largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest]) largest = right;

  // If largest is not root, swap and continue heapifying
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    Heapify(arr, n, largest);
  }
}

std::vector<int> Heap(const std::vector<int>& list_unsorted) {
  std::vector<int> result{list_unsorted};

  int n = result.size();

  // Step 1: Build max heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) {
    Heapify(result, n, i);
  }

  // Step 2: Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    // Move current root (max) to the end
    std::swap(result[0], result[i]);

    // Heapify the reduced heap
    Heapify(result, i, 0);
  }

  return result;
}

}  // namespace algorithms::sort
