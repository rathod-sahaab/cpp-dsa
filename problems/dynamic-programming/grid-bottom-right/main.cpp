#include <bits/stdc++.h>
using namespace std;
int n_paths(const int n, const int m, int i = 1, int j = 1) {
  if (i == n and j == m) {
    return 1;
  }
  if (i > n or j > m) {
    return 0;
  }
  return n_paths(n, m, i + 1, j) + n_paths(n, m, i, j + 1);
}

int n_paths_memoized(vector<vector<int>> &dp, const int n, const int m,
                     int i = 1, int j = 1) {
  if (i == n and j == m) {
    return 1;
  }
  if (i > n or j > m) {
    return 0;
  }
  if (dp[i - 1][j - 1] != -1) {
    return dp[i - 1][j - 1];
  }
  return (dp[i - 1][j - 1] = n_paths_memoized(dp, n, m, i + 1, j) +
                             n_paths_memoized(dp, n, m, i, j + 1));
}

int main(int argc, char *argv[]) {
  int n = 15, m = 18;

  vector<vector<int>> dp(n, vector<int>(m, -1));

  cout << n_paths_memoized(dp, n, m) << endl;
  cout << n_paths(n, m) << endl;
  return 0;
}
