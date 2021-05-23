#include <bits/stdc++.h>
using namespace std;

string longest_palindrome(const string &s) {
  const int N = s.length();
  int longest_size = INT_MIN;
  int longest_beg = 0;
  for (int i = 0; i < N; ++i) {
    {
      // even
      int l = i, r = i + 1;
      int size = 0;
      while (l >= 0 and r < N) {
        if (s[l] != s[r])
          break;
        l--;
        r++;
        size += 2;
      }

      if (size > longest_size) {
        longest_beg = l + 1;
        longest_size = size;
      }
    }
    {
      // odd
      int l = i - 1, r = i + 1;
      int size = 1;
      while (l >= 0 and r < N) {
        if (s[l] != s[r])
          break;
        l--;
        r++;
        size += 2;
      }

      if (size > longest_size) {
        longest_beg = l + 1;
        longest_size = size;
      }
    }
  }

  return s.substr(longest_beg, longest_size);
}

void solve() {
  string s;
  cin >> s;
  std::cout << longest_palindrome(s) << "\n";
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
