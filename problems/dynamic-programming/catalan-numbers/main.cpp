#include <bits/stdc++.h>
using namespace std;

int nth_catalan_number(vector<int> &dp, int n) {
  if (n == 0) {
    return 1;
  }

  if (dp[n] != -1) {
    return dp[n];
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += nth_catalan_number(dp, n - 1 - i) * nth_catalan_number(dp, i);
  }
  return dp[n] = res;
}

int nth_catalan_number_iter(int n) {
  vector<int> catalans(n + 1);

  catalans[0] = 1;

  for (int i = 1; i <= n; ++i) {
    catalans[i] = 0;
    for (int j = 0; j < i; ++j) {
      catalans[i] += catalans[j] * catalans[i - 1 - j];
    }
  }

  return catalans[n];
}

void solve() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, -1);
  cout << nth_catalan_number(dp, n) << " " << nth_catalan_number_iter(n)
       << std::endl;
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
