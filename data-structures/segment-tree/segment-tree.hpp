#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <algorithm>
#include <bits/stdc++.h>

class SegmentTree {
public:
  // constructors, asssignment, destructor
  SegmentTree(std::vector<int> &&vec) noexcept
      : _data(vec.size() * 2), _n{vec.size()} {
    /* vec goes to end
     * same as
     * std::copy(vec.begin(), vec.end(), _data.begin() + _n);
     */
    std::copy(vec.rbegin(), vec.rend(), _data.rbegin());
    for (std::size_t i = _n - 1; i > 0; --i) {
      // index 0 unoccupied
      // TODO: accept a function that takes 2 params and returns a value
      _data[i] = _data[2 * i] + _data[2 * i + 1];
    }
  }
  void update(int index, int value) noexcept {
    index += _n;

    _data[index] = value;

    for (int i = index; i > 0; i /= 2) {
      // index ^ 1  is equivalent to:
      // index = index % 2 == 1 ? index - 1 : index + 1
      // sutract 1 if odd, add 1 if even
      _data[index / 2] = _data[index] + _data[index ^ 1];
    }
  };
  int get(int l, int r) const noexcept {

    int result = 0;

    for (l += _n, r += _n; l < r; l /= 2, r /= 2) {
      if (l & 1)
        result += _data[l++];

      if (r & 1)
        result += _data[--r];
    }

    return result;
  }

private:
  std::vector<int> _data;
  std::size_t _n;
};

#endif // SEGMENT_TREE_HPP
