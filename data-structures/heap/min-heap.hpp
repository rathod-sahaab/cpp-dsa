#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <bits/stdc++.h>

class MinHeap {
  std::vector<int> data = {0};

public:
  void push(int val) {
    data.push_back(val);
    int i = data.size() - 1;
    while (i > 1) {
      // i is 1-based so always use i - 1
      const auto parent = i / 2;

      // modify < to > if creating maxHeap
      if (data[parent] < data[i]) {
        break;
      }

      std::swap(data[parent], data[i]);
      i = parent;
    }
  }
  void pop() {
    std::swap(data[1], data.back());
    data.pop_back();

    if (data.size() < 2) {
      return;
    }

    // Bubble down
    int i = 1;
    while (i < data.size() / 2) {
      int left_child = i * 2, right_child = i * 2 + 1;

      int min_child =
          data[left_child] < data[right_child] ? left_child : right_child;

      if (data[i] < data[min_child]) {
        break;
      }

      std::swap(data[i], data[min_child]);
      i = min_child;
    }
  }
  int top() { return data[1]; }
  bool empty() {
    return data.size() < 2;
    // one element is reserved
  }
};

#endif // MIN_HEAP_HPP
