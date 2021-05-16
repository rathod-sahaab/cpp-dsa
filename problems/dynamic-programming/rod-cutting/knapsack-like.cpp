#include <bits/stdc++.h>
using namespace std;

int max_profit_rod_cuts_recur(const vector<int> &prices);
int max_profit_rod_cuts_iter(const vector<int> &prices);

void solve() {
  int N;
  cin >> N;

  vector<int> prices(N);

  for (auto &price : prices) {
    cin >> price;
  }

  int result_recur = max_profit_rod_cuts_recur(prices);
  int result_iter = max_profit_rod_cuts_iter(prices);

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

int max_profit_rod_cuts_recur_helper(const vector<int> &prices,
                                     vector<vector<int>> &dp, const int index,
                                     int length) {
  if (index == 0 or length == 0) {
    return 0;
  }

  if (dp[index][length] != -1) {
    return dp[index][length];
  }

  // don't make a cut of this length
  int skip = max_profit_rod_cuts_recur_helper(prices, dp, index - 1, length);

  if (index > length) {
    return skip;
  }
  // make cut of this length
  int take = prices[index - 1] + max_profit_rod_cuts_recur_helper(
                                     prices, dp, index, length - (index));

  return max(take, skip);
}

int max_profit_rod_cuts_recur(const vector<int> &prices) {
  const int N = prices.size();

  vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

  return max_profit_rod_cuts_recur_helper(prices, dp, N, N);
}

int max_profit_rod_cuts_iter(const vector<int> &prices) {
  const int N = prices.size();
  vector<vector<int>> table(N + 1, vector<int>(N + 1, -1));

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (i == 0 or j == 0) {
        table[i][j] = 0;
        continue;
      }
      int skip = table[i - 1][j];
      if (i > j) {
        table[i][j] = skip;
        continue;
      }
      int take = prices[i - 1] + table[i][j - i];
      table[i][j] = max(skip, take);
    }
  }
  return table[N][N];
}
