#ifndef SQRT_DECOMPOSITION_HPP
#define SQRT_DECOMPOSITION_HPP

#include <cmath>
#include <vector>

#if ALL_DEBUG
#include <iostream>
#endif

template <typename T> class SqrtDecomposition {
private:
  std::vector<T> _data, _decomp;
  int _block_size;

public:
  // constructors, asssignment, destructor
  SqrtDecomposition(const std::vector<T> &data)
      : _data(data), _decomp(ceil(sqrt(data.size())), 0),
        _block_size(::sqrt(data.size())) {

    int curr_block = -1;
    for (int i = 0; i < _data.size(); ++i) {
      if (i % _block_size == 0) {
        curr_block++;
      }
      auto &d = _decomp[curr_block];
      d = d + _data[i];
    }

#if ALL_DEBUG
    std::cout << "Construction copleted.\n";

    for (const auto &elem : _data) {
      std::cout << elem << " ";
    }

    std::cout << "\n";

    for (const auto &elem : _decomp) {
      std::cout << elem << " ";
    }
    std::cout << "\n";
#endif
  }

  T query(int l, int r) {
    T result = 0; // identitiy
    for (; l <= r and l % _block_size != 0; l++) {
      // individuals before a block
      result = result + _data[l];
    }

    for (int i = l / _block_size; l + _block_size <= r; ++i, l += _block_size) {
      // block representatives
      result = result + _decomp[i];
    }

    for (; l <= r; ++l) {
      // individuals after a block
      result = result + _data[l];
    }
    return result;
  }

  void update(int index, T value) {
    int representating_block = index / _block_size;
    _decomp[representating_block] =
        _decomp[representating_block] + value - _data[index];
    _data[index] = value;
  }
};

#endif // SQRT_DECOMPOSITION_HPP
