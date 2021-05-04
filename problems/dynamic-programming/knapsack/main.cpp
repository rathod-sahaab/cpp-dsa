#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<vector<int>> &dp, int W, int wt[], int val[], int n, int i,
             int w, int v) {
  /* printf("i = %d, w = %d, v = %d\n", i, w, v); */
  if (i == n) {
    return v;
  }
  if (dp[i][w] != -1) {
    return dp[i][w];
  }
  if (w + wt[i] <= W) {
    int exclude = knapSack(dp, W, wt, val, n, i + 1, w, v);
    int include = knapSack(dp, W, wt, val, n, i + 1, w + wt[i], v + val[i]);
    return dp[w][i] = max(exclude, include);
  } else {
    return dp[w][i] = knapSack(dp, W, wt, val, n, i + 1, w, v);
  }
}

int knapSack(int W, int wt[], int val[], int n) {
  vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
  return knapSack(dp, W, wt, val, n, 0, 0, 0);
}

int knapSackIter(int W, int wt[], int val[], int n) {
  int td[W + 1][n + 1];

  for (int w = 0; w <= W; ++w) {
    for (int i = 0; i <= n; ++i) {
      if (i == 0 or w == 0) {
        td[w][i] = 0;
        continue;
      }

      if (wt[i - 1] <= w) {
        td[w][i] = max(val[i - 1] + td[w - wt[i - 1]][i - 1], td[w][i - 1]);
        continue;
      }

      td[w][i] = td[w][i - 1];
    }
  }

  return td[W][n];
}

void TEST(string test_name, bool passed) {
  std::cout << test_name << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}
int main() {
  int wt[] = {4, 5, 1}, val[] = {1, 2, 3};
  int n = sizeof(wt) / sizeof(int);
  int W = 3;
  TEST("Iter test", knapSackIter(W, wt, val, n) == 3);
  TEST("Recursive test", knapSack(W, wt, val, n) == 3);
  return 0;
}
