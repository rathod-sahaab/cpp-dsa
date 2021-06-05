#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string superstring(const string &str1, const string &str2) {
  const int N = str1.length();
  const int M = str2.length();

  int table[N + 1][M + 1];

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if (i == 0 or j == 0) {
        table[i][j] = 0;
        continue;
      }

      if (str1[i - 1] == str2[j - 1]) {
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

  string result;
  {
    // build lcs
    int i = N, j = M;
    while (i > 0 and j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        result += str1[i - 1];
        i--;
        j--;
        continue;
      }
      if (table[i - 1][j] > table[i][j - 1]) {
        i--;
        continue;
      }
      j--;
    }
  }
  reverse(result.begin(), result.end());

  return result;
}

void solve() {
  string str1, str2;
  cin >> str1 >> str2;

  cout << superstring(str1, str2) << "\n";
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
