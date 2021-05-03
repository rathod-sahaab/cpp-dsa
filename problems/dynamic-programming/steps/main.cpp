#include <bits/stdc++.h>
using namespace std;

int stepper(const int N, int i = 0) {
  if (i > N) {
    return 0;
  }

  if (i == N) {
    return 1;
  }

  return stepper(N, i + 1) + stepper(N, i + 2);
}

int stepper_memoized(vector<int> &dp, const int N, int i = 0) {
  if (i > N) {
    return 0;
  }

  if (i == N) {
    return 1;
  }

  if (dp[i] != -1) {
    return dp[i];
  }

  return dp[i] = stepper(N, i + 1) + stepper(N, i + 2);
}

int main(int argc, char *argv[]) {
  int n = 14;
  vector<int> dp(n, -1);

  cout << stepper(n) << endl;
  cout << stepper_memoized(dp, n) << endl;
  return 0;
}
