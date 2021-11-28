#ifndef SQRT_DECOMPOSITION_HPP
#define SQRT_DECOMPOSITION_HPP

#include <cmath>
#include <limits>
#include <vector>

#if ALL_DEBUG
#include <iostream>
#endif

template <typename T, class OperationPolicy> class SqrtDecomposition {
public:
  std::vector<T> _data;
  std::vector<T> _decomp;
  int _block_size;

  // constructors, asssignment, destructor
  explicit SqrtDecomposition(const std::vector<T> &data)
      : _data(data),
        _decomp(ceil(sqrt(data.size())), OperationPolicy::identitiy()),
        _block_size(::sqrt(data.size())) {

    int curr_block = -1;
    for (int i = 0; i < _data.size(); ++i) {
      if (i % _block_size == 0) {
        curr_block++;
      }
      auto &d = _decomp[curr_block];
      d = OperationPolicy::operation(d, _data[i]);
    }

#if ALL_DEBUG
    std::cout << "Construction completed.\n";

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
    T result = OperationPolicy::identitiy(); // identitiy
    for (; l <= r and l % _block_size != 0; l++) {
      // individuals before a block
      result = OperationPolicy::operation(result, _data[l]);
    }

    for (int i = l / _block_size; l + _block_size <= r; ++i, l += _block_size) {
      // block representatives
      result = OperationPolicy::operation(result, _decomp[i]);
    }

    for (; l <= r; ++l) {
      // individuals after a block
      result = OperationPolicy::operation(result, _data[l]);
    }
    return result;
  }

  void update(int index, T value) {
    int representating_block = index / _block_size;
    _decomp[representating_block] = OperationPolicy::block_update_calc(
        _decomp[representating_block], value, _data[index]);
    _data[index] = value;
  }
};

// interface
template <typename T> class DummyPolicy {
public:
  static T identitiy();
  static T operation(const T &a, const T &b);
  static T block_update_calc(const T old_block_value, const T new_data_value,
                             const T &old_data_value);
};

template <typename T> class AdditionPolicy {
public:
  static T identitiy() { return 0; }
  static T operation(const T &a, const T &b) { return a + b; }
  static T block_update_calc(const T old_block_value, const T new_data_value,
                             const T &old_data_value) {
    return old_block_value + new_data_value - old_data_value;
  }
};

template <typename T> class MultiplicationPolicy {
public:
  static T identitiy() { return 1; }
  static T operation(const T &a, const T &b) { return a * b; }
  static T block_update_calc(const T old_block_value, const T new_data_value,
                             const T &old_data_value) {
    return (old_block_value * new_data_value) / old_block_value;
  }
};

template <typename T> class MinimumPolicy {
public:
  static T identitiy() { return std::numeric_limits<T>::max(); }
  static T operation(const T &a, const T &b) { return std::min(a, b); }
  static T block_update_calc(const T old_block_value, const T new_data_value,
                             const T &old_data_value) {
    return std::min(old_block_value, new_data_value);
  }
};

template <typename T> class MaximumPolicy {
public:
  static T identitiy() { return std::numeric_limits<T>::min(); }
  static T operation(const T &a, const T &b) { return std::max(a, b); }
  static T block_update_calc(const T old_block_value, const T new_data_value,
                             const T &old_data_value) {
    return std::max(old_block_value, new_data_value);
  }
};

template <typename T>
using AdditionSqrtDecomposition = SqrtDecomposition<T, AdditionPolicy<T>>;

template <typename T>
using MultiplicationSqrtDecomposition =
    SqrtDecomposition<T, MultiplicationPolicy<T>>;

template <typename T>
using MinimumSqrtDecomposition = SqrtDecomposition<T, MinimumPolicy<T>>;

template <typename T>
using MaximumSqrtDecomposition = SqrtDecomposition<T, MaximumPolicy<T>>;

#endif // SQRT_DECOMPOSITION_HPP
