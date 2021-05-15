#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_profit_recur(const vector<int> &prices, vector<vector<vector<int>>> &dp,
                     int index, int transactions_left, bool bought) {

  if (index == prices.size() or transactions_left == 0) {
    return 0;
  }

  if (dp[bought][transactions_left][index] != -1) {
    return dp[bought][transactions_left][index];
  }

  // skip
  int result =
      max_profit_recur(prices, dp, index + 1, transactions_left, bought);

  if (bought) {
    // sell
    int sell_profit =
        max_profit_recur(prices, dp, index + 1, transactions_left - 1, false) +
        prices[index];
    result = max(result, sell_profit);
  } else {
    // buy
    int buy_profit =
        max_profit_recur(prices, dp, index + 1, transactions_left, true) -
        prices[index];
    result = max(result, buy_profit);
  }

  dp[bought][transactions_left][index] = result;
  return result;
}

int max_profit(const vector<int> &prices) {
  vector<vector<vector<int>>> dp(
      2, vector<vector<int>>(3, vector<int>(prices.size(), -1)));
  return max_profit_recur(prices, dp, 0, 2, false);
}

void solve() {
  int N;
  cin >> N;

  vector<int> prices(N);

  for (auto &price : prices) {
    cin >> price;
  }

  int result = max_profit(prices);

  cout << result << "\n";
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
