#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int lcs(const string &a, const string &b, int i = 0, int j = 0) {
  const int n = a.size(), m = b.size();
  if (i == n or j == m) {
    return 0;
  }

  if (a[i] == b[j]) {
    return 1 + lcs(a, b, i + 1, j + 1);
  }

  int left = lcs(a, b, i + 1, j);
  int right = lcs(a, b, i, j + 1);

  return max(left, right);
}

int lcs_memoized(const string &a, const string &b, vector<vector<int>> &dp,
                 int i = 0, int j = 0) {
  const int n = a.size(), m = b.size();
  if (i == n or j == m) {
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (a[i] == b[j]) {
    return dp[i][j] = 1 + lcs_memoized(a, b, dp, i + 1, j + 1);
  }

  int left = lcs_memoized(a, b, dp, i + 1, j);
  int right = lcs_memoized(a, b, dp, i, j + 1);

  return dp[i][j] = max(left, right);
}

int main(int argc, char *argv[]) {
  string a = "ajdkflajvhc", b = "aehbec";

  vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));

  std::cout << lcs(a, b) << "\n";
  std::cout << lcs_memoized(a, b, dp) << "\n";

  return 0;
}
