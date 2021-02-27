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

  bool empty() { return _data.empty(); }
  T top() { return _data.front(); }

  /*
  T pop() {
    std::swap(_data.front(), _data.back());
    _data.pop_back();

    for (int i = 0; i < _data.size(); ++i) {
      if (_comp(_data[i],
                std::min(_data[2 * i + 1], _data[2 * i + 2], _comp))) {
        break;
      } else if (_comp(_data[2 * i 1])) {
      }
    }
  }
  */
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
