#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

int nCr(vector<vector<int>> &dp, int n, int r) {
  if (r == 0 or r == n) {
    return 1;
  }

  if (dp[n][r] != -1)
    return dp[n][r];

  return dp[n][r] = (nCr(dp, n - 1, r - 1) + nCr(dp, n - 1, r)) % MOD;
}

int nCr(int n, int r) {
  if (r > n - r) {
    r = n - r;
  }
  vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

  return nCr(dp, n, r);
}

int nCr_iter(int n, int r) {
  if (r > n - r) {
    r = n - r;
  }
  int C[n + 1][r + 1];

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= min(i, r); ++j) {
      if (j == 0 or j == i) {
        C[i][j] = 1;
        continue;
      }
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][r];
}

int main() {
  cout << nCr(20, 18) << nCr_iter(20, 18) << "\n";
  return 0;
}
