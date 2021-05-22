#include <bits/stdc++.h>
using namespace std;

int edit_distance_recur(vector<vector<int>> &dp, const string &s,
                        const string &t, int n, int m) {
  if (n == 0) {
    return m;
  }
  if (m == 0) {
    return n;
  }

  if (dp[n][m] != -1) {
    return dp[n][m];
  }

  if (s[n - 1] == t[m - 1]) {
    return dp[n][m] = edit_distance_recur(dp, s, t, n - 1, m - 1);
  }

  int insert_score = edit_distance_recur(dp, s, t, n, m - 1);
  int remove_score = edit_distance_recur(dp, s, t, n - 1, m);
  int replace_score = edit_distance_recur(dp, s, t, n - 1, m - 1);

  return dp[n][m] = 1 + min({insert_score, remove_score, replace_score});
}

int edit_distance(const string &s, const string &t) {
  int N = s.length();
  int M = t.length();

  vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));

  return edit_distance_recur(dp, s, t, N, M);
}

int edit_distance_iter(const string &s, const string &t) {
  int N = s.length();
  int M = t.length();

  vector<vector<int>> table(N + 1, vector<int>(M + 1, -1));

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if (i == 0) {
        table[i][j] = j;
        continue;
      }
      if (j == 0) {
        table[i][j] = i;
        continue;
      }

      if (s[i - 1] == t[j - 1]) {
        table[i][j] = table[i - 1][j - 1];
        continue;
      }

      int insert_score = table[i][j - 1];
      int remove_score = table[i - 1][j];
      int replace_score = table[i - 1][j - 1];

      table[i][j] = 1 + min({insert_score, remove_score, replace_score});
    }
  }

  return table[N][M];
}

void solve() {
  string s, t;
  cin >> s >> t;
  cout << edit_distance(s, t) << " " << edit_distance_iter(s, t) << "\n";
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
