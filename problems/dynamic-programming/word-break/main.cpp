#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

bool is_possible(const string &s, const vector<string> &words, vector<int> &dp,
                 int start = 0) {
  if (s.length() == start) {
    return true;
  }

  if (dp[start] != -1) {
    return dp[start] == 1;
  }

  for (const auto &word : words) {
    const bool word_smaller = word.length() <= (s.length() - start);
    const bool s_starts_with_word = s.compare(start, word.length(), word);

    if (word_smaller and s_starts_with_word) {
      if (is_possible(s, words, dp, start + word.length())) {
        dp[start] = 1;
        return true;
      }
    }
  }

  dp[start] = 0;
  return false;
}

void solve() {
  string to_form;
  cin >> to_form;

  int N;
  cin >> N;
  vector<string> words(N);

  for (int i = 0; i < N; ++i) {
    cin >> words[i];
  }

  int M = to_form.length();
  vector<int> dp(M, -1);

  if (is_possible(to_form, words, dp)) {
    cout << "Possible\n";
    return;
  }

  cout << "Not possible\n";
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
