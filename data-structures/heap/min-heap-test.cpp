#include "min-heap.hpp"

int main() {

  MinHeap mh;

  for (auto a : {4, 2, 3, 5, 1, 2, 3, 2}) {
    mh.push(a);
    std::cout << mh.top() << " ";
  }
  std::cout << "\n";

  while (not mh.empty()) {
    std::cout << mh.top() << " ";
    mh.pop();
  }
  std::cout << "\n";

  std::vector<int> arr = {0, 4, 5, 2, 3, 3, 3, 5, 6, 7, 3};

  MinHeap::heapify(arr);

  copy(std::begin(arr) + 1, std::end(arr),
       std::ostream_iterator<decltype(arr[0])>{std::cout, " "});
  std::cout << "\n";

  return 0;
}
