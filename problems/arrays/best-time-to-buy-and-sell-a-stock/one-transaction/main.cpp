#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  int min_yet = INT_MAX, max_profit = 0;

  for (const auto &num : numbers) {
    min_yet = min(min_yet, num);
    max_profit = max(max_profit, num - min_yet);
  }

  cout << max_profit << "\n";
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
