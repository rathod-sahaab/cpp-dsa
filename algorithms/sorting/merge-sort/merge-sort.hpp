#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <bits/stdc++.h>
#include <iostream>

template <typename T, typename Compare>
void merge(std::vector<T> &arr, int l, int mid, int r);

template <typename T, typename Compare = std::less<T>>
void merge_sort(std::vector<T> &arr, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    // l + (r - l) / 2; // (l+r)/2 but less overflow susceptible

    merge_sort<T, Compare>(arr, l, mid);
    merge_sort<T, Compare>(arr, mid + 1, r);

    merge<T, Compare>(arr, l, mid, r);
  }
}

template <typename T, typename Compare>
void merge(std::vector<T> &arr, int l, int mid, int r) {
  static auto comp = Compare();
  int l1 = mid - l + 1;
  int l2 = r - mid;

  // make copies
  T arr1[l1], arr2[l2];
  for (int i = 0; i < l1; ++i) {
    arr1[i] = arr[l + i];
  }
  for (int j = 0; j < l2; ++j) {
    arr2[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = l;

  while (i < l1 and j < l2) {
    if (comp(arr1[i], arr2[j])) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }

  while (i < l1) {
    arr[k++] = arr1[i++];
  }
  while (j < l2) {
    arr[k++] = arr2[j++];
  }
}

#endif // MERGE_SORT_HPP
