#include "min-heap.hpp"

int main() {

  MinHeap mh;

  for (auto a : {4, 2, 3, 5, 1, 2, 3}) {
    mh.push(a);
    std::cout << mh.top() << " ";
  }
  std::cout << "\n";

  while (not mh.empty()) {
    std::cout << mh.top() << " ";
    mh.pop();
  }
  std::cout << "\n";

  return 0;
}
