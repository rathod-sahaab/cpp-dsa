#include "heap.hpp"
#include <functional>
int main() {
  std::vector<int> nums{5, 3, 2, 4, 1, 0};
  // max heap
  Heap<int, std::greater<int>> he(std::move(nums));
  he.print();

  // min heap
  Heap<int> h;
  h.insert(5);
  h.insert(2);
  h.insert(3);
  h.insert(4);
  h.insert(1);
  h.insert(0);
  h.print();
}
