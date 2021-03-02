#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <bits/stdc++.h>
#include <tuple>

template <typename T, typename Compare = std::less<T>>
int partition(std::vector<T> &arr, int l, int r) {
  static auto comp = Compare();
  const int pivot = arr[r];

  int inferiors_till = l - 1;
  for (int j = l; j < r; j++) {
    if (comp(arr[j], pivot)) {
      inferiors_till++;
      std::swap(arr[inferiors_till], arr[j]);
    }
  }

  std::swap(arr[inferiors_till + 1], arr[r]);

  return inferiors_till + 1;
}

template <typename T, typename Compare = std::less<T>>
void quicksort(std::vector<T> &arr, int l, int r) {
  if (l < r) {
    int pivot = partition<T, Compare>(arr, l, r);

    quicksort<T, Compare>(arr, l, pivot - 1);
    quicksort<T, Compare>(arr, pivot + 1, r);
  }
}

#endif // QUICK_SORT_HPP
