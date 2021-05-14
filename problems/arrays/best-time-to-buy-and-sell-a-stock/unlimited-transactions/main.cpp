#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <ranges>
using namespace std;

int max_profit_stl(const vector<int> &prices) {
  vector<int> adj_diff(prices.size());

  adjacent_difference(prices.begin(), prices.end(), adj_diff.begin());
  adj_diff.front() = 0;
  // we never sell on first day but adjacent_difference makes it equal to
  // element on the first day calculates it
  //
  transform(adj_diff.begin(), adj_diff.end(), adj_diff.begin(),
            [](int a) { return a > 0 ? a : 0; });

  return accumulate(adj_diff.cbegin(), adj_diff.cend(), 0);
}
int max_profit(const vector<int> &prices) {
  int profit = 0;

  int prev = INT_MAX;
  for (const auto &price : prices) {
    if (prev < price) {
      profit += price - prev;
    }
    prev = price;
  }

  return profit;
}

void solve() {
  int N;
  cin >> N;

  vector<int> prices(N);
  for (auto &price : prices) {
    cin >> price;
  }

  const int result_stl = max_profit_stl(prices);
  const int result = max_profit(prices);

  cout << result << " " << result_stl << "\n";
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
