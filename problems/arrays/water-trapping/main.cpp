#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int trap_water_oN_space(const vector<int> &arr) {

  int capacity = 0;
  vector<int> max_right(arr.size());

  max_right.back() = arr.back();
  for (int i = arr.size() - 2; i >= 0; --i) {
    max_right[i] = max(arr[i], max_right[i + 1]);
  }

  int max_left = 0;
  for (int i = 0; i < arr.size(); ++i) {
    max_left = max(max_left, arr[i]);

    capacity += min(max_left, max_right[i]) - arr[i];
  }

  return capacity;
}

int trap_water_o1_space(const vector<int> &arr) {
  int capacity = 0;

  int lo = 0, hi = arr.size() - 1;
  int left_max = 0, right_max = 0;

  while (lo <= hi) {
    if (arr[lo] < arr[hi]) {
      left_max = max(arr[lo], left_max);
      capacity += left_max - arr[lo];
      lo++;
    } else {
      right_max = max(arr[hi], right_max);
      capacity += right_max - arr[hi];
      hi--;
    }
  }

  return capacity;
}

int main() {
  vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "Capacity: " << trap_water_oN_space(arr)
       << " == " << trap_water_o1_space(arr) << "\n";
  return 0;
}
