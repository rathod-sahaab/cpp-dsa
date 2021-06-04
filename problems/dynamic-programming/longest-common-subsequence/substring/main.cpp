#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int lcsubstr(const string &str1, const string &str2, int &maxi, int i, int j) {
  if (i == 0 or j == 0) {
    return 0;
  }
  if (str1[i - 1] == str2[j - 1]) {
    int result = 1 + lcsubstr(str1, str2, maxi, i - 1, j - 1);
    maxi = max(result, maxi);
    return result;
  }

  lcsubstr(str1, str2, maxi, i, j - 1);
  lcsubstr(str1, str2, maxi, i - 1, j);
  return 0;
}

int lcsubstr_iter(const string &str1, const string &str2) {
  const int N = str1.length();
  const int M = str2.length();

  int table[N + 1][M + 1];

  int maxi = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      if (i == 0 or j == 0) {
        table[i][j] = 0;
        continue;
      }

      if (str1[i - 1] == str2[j - 1]) {
        table[i][j] = 1 + table[i - 1][j - 1];
        maxi = max(maxi, table[i][j]);
        continue;
      }
      table[i][j] = 0;
    }
  }

  return maxi;
}

void solve() {
  string str1, str2;
  cin >> str1 >> str2;

  int maxi = 0;
  lcsubstr(str1, str2, maxi, str1.length(), str2.length());
  int maxi_iter = lcsubstr_iter(str1, str2);
  cout << maxi << "\t" << maxi_iter << "\n";
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
