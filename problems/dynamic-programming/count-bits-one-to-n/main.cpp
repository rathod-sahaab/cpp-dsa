#include <bits/stdc++.h>
using namespace std;

vector<int> bit_counts(int N) {
  vector<int> dp(N);
  dp[0] = 0;

  int last_power_of_2 = 1;
  for (int i = 1; i < N; ++i) {
    if (last_power_of_2 * 2 == i) {
      last_power_of_2 = i;
    }
    dp[i] = 1 + dp[i - last_power_of_2];
  }

  return dp;
}
void solve() {
  int N;
  cin >> N;

  vector<int> result = bit_counts(N);

  copy(std::begin(result), std::end(result),
       std::ostream_iterator<decltype(result[0])>{std::cout, " "});
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
