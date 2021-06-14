#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int longest_repeating_subsequence(const string &str) {
  const int N = str.length();

  int table[N + 1][N + 1];

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (i == 0 or j == 0) {
        table[i][j] = 0;
        continue;
      }

      if (str[i - 1] == str[j - 1] and i != j) {
        table[i][j] = 1 + table[i - 1][j - 1];
        continue;
      }

      if (table[i - 1][j] > table[i][j - 1]) {
        table[i][j] = table[i - 1][j];
        continue;
      }

      table[i][j] = table[i][j - 1];
    }
  }
  return table[N][N];
}

void solve() {
  string str;
  cin >> str;

  cout << longest_repeating_subsequence(str) << "\n";
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
