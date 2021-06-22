#include <bits/stdc++.h>
#include <numeric>
#include <string>

#define LOG 0
using namespace std;

// equal to char range allowed for text lower is better
constexpr const int n_chars = 256;
constexpr const int MOD = 101; // prime number

vector<int> find_positions(const string &text, const string &pattern) {
  vector<int> result;
  const int N = text.length();
  const int M = pattern.length();

  const int pattern_hash =
      accumulate(pattern.begin(), pattern.end(), 0,
                 [](int hash, char c) { return (hash * n_chars + c) % MOD; });
#if LOG
  std::cout << "Pattern hash:" << pattern_hash << "\n";
#endif

  int first_char_hash_base = 1;
  {
    // to isolate hash of first character of M characters long string
    for (int i = 0; i < M - 1; ++i) {
      first_char_hash_base = (first_char_hash_base * n_chars) % MOD;
    }
  }

#if LOG
  std::cout << "First char base hash:" << first_char_hash_base << "\n";
#endif

  int running_hash = 0;
  for (int i = 0; i < M; ++i) {
    running_hash = (running_hash * n_chars + text[i]) % MOD;
  }

  for (int i = 0; i <= N - M; ++i) {
#if LOG
    std::cout << "[" << i << "] Running hash:" << running_hash << "\n";
#endif

    if (running_hash == pattern_hash) {
      // preliminary tests passed, checking more intricately
#if LOG
      std::cout << "[" << i << "] Preliminary test passed!" << text[i] << "\n";
#endif
      int j = 0;
      for (; j < M; ++j) {
        if (text[i + j] != pattern[j]) {
          break;
        }
      }

      if (j == M) {
        result.push_back(i);
      }
    }
    if (i + M < N) {

      // there is one more character to accommodate
      const int first_char_removed_hash =
          running_hash - (text[i] * first_char_hash_base);
      running_hash = (first_char_removed_hash * n_chars + text[i + M]) % MOD;

      if (running_hash < 0) {
        running_hash = running_hash + MOD;
      }
    }
  }

  return result;
}

void solve() {
  string text, pattern;
  getline(cin, text);
  getline(cin, pattern);

#if LOG
  std::cout << "TEXT: " << text << "\n";
  std::cout << "PATTERN: " << pattern << "\n";
#endif

  const auto result = find_positions(text, pattern);

  copy(std::begin(result), std::end(result),
       std::ostream_iterator<decltype(result[0])>{std::cout, " "});
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  cin.ignore(); // needed for getline
  while (T--) {
    solve();
  }

  return 0;
}
