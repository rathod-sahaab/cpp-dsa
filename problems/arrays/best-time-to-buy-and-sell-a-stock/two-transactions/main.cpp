#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_profit(const vector<int> &prices) {
  const int N = prices.size();

  vector<int> left_profits(N), right_profits(N);
  left_profits.front() = right_profits.back() = 0;

  {
    // calculate left_profits
    int min_left = prices.front();
    for (int i = 1; i < N; i++) {
      left_profits[i] = max(left_profits[i - 1], prices[i] - min_left);
      min_left = min(min_left, prices[i]);
    }
  }

  {
    int max_right = prices.back();
    for (int i = N - 2; i >= 0; --i) {
      right_profits[i] = max(right_profits[i + 1], max_right - prices[i]);
      max_right = max(max_right, prices[i]);
    }
  }

  int result = 0;

  for (int i = 0; i < N; ++i) {
    result = max(result, left_profits[i] + right_profits[i]);
  }

  return result;
}

void solve() {
  int N;
  cin >> N;

  vector<int> prices(N);

  for (auto &price : prices) {
    cin >> price;
  }

  const auto result = max_profit(prices);
  std::cout << result << "\n";
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
