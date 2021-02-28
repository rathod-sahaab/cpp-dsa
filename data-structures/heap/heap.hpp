#ifndef HEAP_HPP
#define HEAP_HPP

#include <bits/stdc++.h>
#include <tuple>

template <typename T, typename Compare = std::less<T>>
void heapify(std::vector<T> &elements, Compare comp = Compare()) {
  for (int i = 1; i < elements.size(); ++i) {
    for (auto inserted_index = i; inserted_index != 0;) {
      auto parent_index = inserted_index / 2 - (inserted_index % 2 ? 0 : 1);

      if (comp(elements[inserted_index], elements[parent_index])) {
        std::swap(elements[inserted_index], elements[parent_index]);
      }
      inserted_index = parent_index;
    }
  }
}

template <typename T, typename Compare = std::less<T>> class Heap {
public:
  // constructors, asssignment, destructor
  Heap() = default;
  Heap(std::vector<T> &&data) : _data(std::move(data)) {
    heapify<T, Compare>(_data);
  }

  void insert(T val) {
    _data.push_back(val);

    for (auto inserted_index = _data.size() - 1; inserted_index != 0;) {
      auto parent_index = inserted_index / 2 - (inserted_index % 2 ? 0 : 1);

      if (_comp(_data[inserted_index], _data[parent_index])) {
        std::swap(_data[inserted_index], _data[parent_index]);
      }
      inserted_index = parent_index;
    }
  }

  bool empty() const noexcept { return _data.empty(); }
  T top() const noexcept { return _data.front(); }

  void pop() {
    if (_data.size() > 1) {
      std::swap(_data.front(), _data.back());
    }
    _data.pop_back();

    for (int i = 0; i < _data.size();) {
      int heapier_child = -1;
      // heapier: better accroding to heap property

      int left_child = 2 * i + 1;
      int right_child = 2 * i + 2;

      if (left_child < _data.size()) {
        if (right_child < _data.size() and
            _comp(_data[right_child], _data[left_child])) {
          // right_child exits and is heapier than left child
          heapier_child = right_child;
        } else {
          // right_child doesn't exits or is less heapier than left_child
          heapier_child = left_child;
        }

        if (_comp(_data[heapier_child], _data[i])) {
          // child is heapier than parent
          std::swap(_data[heapier_child], _data[i]);
        } else {
          // parent is heapier than both children, correct place
          break;
        }

      } else {
        // this node has no child already in correct postion
        break;
      }
    }
  }

  void print() {
    copy(begin(_data), end(_data),
         std::ostream_iterator<decltype(_data[0])>{std::cout, " "});
    std::cout << "\n";
  }

private:
  std::vector<T> _data;
  Compare _comp = Compare();
};

#endif // HEAP_HPP
