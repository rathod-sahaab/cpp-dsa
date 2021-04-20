#include <bits/stdc++.h>
#include <cassert>
using namespace std;

void merge(int arr1[], int arr2[], const int n, const int m) {

  make_heap(arr2, arr2 + m, greater<int>());

  for (int i = 0; i < n; ++i) {
    if (arr1[i] > arr2[0]) {
      swap(arr1[i], arr2[0]);

      pop_heap(arr2, arr2 + m, greater<int>());
      push_heap(arr2, arr2 + m, greater<int>());
    }
  }

  sort(arr2, arr2 + m);
}

int main() {
  int arr1[] = {1, 3, 5, 7};
  int arr2[] = {0, 2, 6, 8, 9};
  int s1 = sizeof(arr1) / sizeof(int), s2 = sizeof(arr2) / sizeof(int);

  vector<int> result, expected{0, 1, 2, 3, 5, 6, 7, 8, 9},
      not_expected{1, 2, 3};

  result.reserve(s1 + s2);

  merge(arr1, arr2, s1, s2);

  for (int i = 0; i < s1; ++i) {
    cout << arr1[i] << ", ";
    result.push_back(arr1[i]);
  }
  cout << "\n";

  for (int i = 0; i < s2; ++i) {
    cout << arr2[i] << ", ";
    result.push_back(arr2[i]);
  }
  cout << "\n";

  assert(result == expected);
  assert(result != not_expected);

  return 0;
}
