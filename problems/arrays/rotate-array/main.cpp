#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void rotate_array(vector<int> &numbers, int k) {
  k = k % numbers.size();
  if (k < 0) {
    return;
  }
  reverse(numbers.begin(), numbers.end());
  reverse(numbers.begin(), numbers.begin() + k);
  reverse(numbers.begin() + k, numbers.end());
}

void solve() {
  int N, k;
  cin >> N >> k;

  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  rotate_array(numbers, k);

  copy(std::begin(numbers), std::end(numbers),
       std::ostream_iterator<decltype(numbers[0])>{std::cout, " "});
  std::cout << "\n";
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
