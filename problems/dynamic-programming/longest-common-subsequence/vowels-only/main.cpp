#include <algorithm>
#include <array>
#include <bits/stdc++.h>
using namespace std;
bool is_vowel(char c) {
  return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}
int lcsubstr(const string &str1, const string &str2) {

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
        int count_this = (is_vowel(str1[i - 1]) ? 1 : 0);
        table[i][j] = count_this + table[i - 1][j - 1];
        continue;
      }
      table[i][j] = max(table[i - 1][j], table[i][j - 1]);
    }
  }
  return table[N][M];
}
void solve() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << lcsubstr(str1, str2) << "\n";
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
