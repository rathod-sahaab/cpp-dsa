#include "heap.hpp"
#include <functional>

template <typename Popable> void popper(Popable &h) {
  {
    int poped = h.top();
    std::cout << "removed:" << poped << "\n";
  }
  h.pop();
  h.print();
}

int main() {
  std::vector<int> nums{5, 3, 2, 4, 1, 0};
  // max heap
  Heap<int, std::greater<int>> he(std::move(nums));
  std::cout << "--- heap1 ---\n";
  he.print();

  std::cout << "--- heap2 ---\n";
  // min heap
  Heap<int> h;
  h.insert(5);
  h.print();
  popper(h);
  h.insert(2);
  h.insert(3);
  h.insert(4);
  h.print();
  popper(h);
  h.insert(1);
  h.insert(0);
  popper(h);

  return 0;
}
