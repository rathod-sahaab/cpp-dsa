#include "sqrt-decomposition.hpp"
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<int> nums(N);
  for (auto &num : nums) {
    cin >> num;
  }

  MinimumSqrtDecomposition<int> sd(nums);

  int queries;
  cin >> queries;

  for (int i = 0; i < queries; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      // query
      int l, r;
      cin >> l >> r;

      cout << sd.query(l, r) << "\n";
    } else {
      // update
      int index;
      int value;

      sd.update(index, value);
    }
  }
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
