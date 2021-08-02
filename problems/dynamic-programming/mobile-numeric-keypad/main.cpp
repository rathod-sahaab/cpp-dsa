#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reachable = {
    {0, 8},          {1, 2, 4},    {2, 1, 3, 5}, {3, 2, 6},       {4, 1, 5, 7},
    {5, 2, 4, 6, 8}, {6, 3, 5, 9}, {7, 4, 8},    {8, 0, 5, 7, 9}, {9, 6, 8},
};

long long combinations_recur(int N, int parent_num) {
  if (N == 0) {
    return 1;
  }

  long long total = 0;
  for (const int succ : reachable[parent_num]) {
    total += combinations_recur(N - 1, succ);
  }

  return total;
}

long long combinations_recur(int N) {
  long long total = 0;
  for (int i = 0; i < 10; ++i) {
    total += combinations_recur(N - 1, i);
  }

  return total;
}

long long combinations_iter(int N) {
  vector<vector<int>> dp(N + 1, vector<int>(10, 1));

  for (int i = 2; i <= N; ++i) {
    for (int j = 0; j < 10; ++j) {
      int combi = 0;

      for (const int r : reachable[j]) {
        combi += dp[i - 1][r];
      }

      dp[i][j] = combi;
    }
  }

  long long total = 0;
  for (int i = 0; i < 10; ++i) {
    total += dp[N][i];
  }
  return total;
}

void solve() {
  int N;
  cin >> N;
  cout << combinations_iter(N) << "\n";
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
