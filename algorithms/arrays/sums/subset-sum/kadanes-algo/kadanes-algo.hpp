#ifndef KADANES_ALGO_HPP
#define KADANES_ALGO_HPP

#include <bits/stdc++.h>
template <typename T> int kadanes_max_subset_sum(const std::vector<T> &arr) {
  if (arr.empty()) {
    return 0;
  }

  T current_max = arr[0];
  T max_sum = arr[0];

  for (const auto &element : arr) {
    current_max = max(current_max + element, element);
    max_sum = max(max_sum, current_max);
  }

  return max_sum;
}

#endif // KADANES_ALGO_HPP
