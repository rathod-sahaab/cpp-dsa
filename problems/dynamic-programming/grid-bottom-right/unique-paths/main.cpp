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

int n_paths_iter(int m, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 and j == m - 1) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    }
  }

  return dp[0][0];
}

int main(int argc, char *argv[]) {
  int n = 15, m = 18;

  vector<vector<int>> dp(n, vector<int>(m, -1));

  cout << n_paths_memoized(dp, n, m) << endl;
  cout << n_paths(n, m) << endl;
  return 0;
}
