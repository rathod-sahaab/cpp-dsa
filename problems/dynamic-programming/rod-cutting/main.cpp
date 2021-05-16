#include <bits/stdc++.h>
using namespace std;

int cut_rods(const vector<int> &prices, const int length) {
  if (length == 0) {
    return 0;
  }

  const int N = prices.size();
  int result = -100;

  for (int i = 1; i <= N; ++i) {
    if (i <= length) {
      result = max(result, prices[i - 1] + cut_rods(prices, length - i));
      continue;
    }
  }
  return result;
}

int cut_rods_iter(const vector<int> &prices) {
  const int N = prices.size();

  vector<int> dp(N + 1, -1);

  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    // rod length
    for (int j = 1; j <= i; ++j) {
      // cut length
      dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
    }
  }

  return dp[N];
}

void solve() {
  int N;
  cin >> N;

  vector<int> prices(N);

  for (auto &price : prices) {
    cin >> price;
  }

  int result_recur = cut_rods(prices, N);
  int result_iter = cut_rods_iter(prices);

  std::cout << result_iter << " " << result_recur << "\n";
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
