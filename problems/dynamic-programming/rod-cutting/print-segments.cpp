#include <bits/stdc++.h>
using namespace std;

int cut_rods_print_path(const vector<int> &prices) {
  const int N = prices.size();

  vector<int> dp(N + 1, -1);
  // stores the length of first cut that should be made for current rod length
  vector<int> first_cut(N + 1);

  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    // rod length i
    for (int j = 1; j <= i; ++j) {
      // make a cut of j length
      const int j_cut_profit = prices[j - 1] + dp[i - j];
      if (dp[i] < j_cut_profit) {
        dp[i] = j_cut_profit;
        first_cut[i] = j;
      }
    }
  }

  {
    int rod_left = N;
    vector<int> path;
    while (rod_left) {
      path.push_back(first_cut[rod_left]);
      rod_left -= first_cut[rod_left];
    }

    cout << "Cuts of length: ";
    copy(std::begin(path), std::end(path),
         std::ostream_iterator<decltype(path[0])>{std::cout, " "});
    std::cout << "\n";
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

  int result_iter = cut_rods_print_path(prices);

  std::cout << result_iter << "\n";
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
