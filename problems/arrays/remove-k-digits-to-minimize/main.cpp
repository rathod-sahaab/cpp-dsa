#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string remove_k_digits(string str, int k) {
  vector<int> digits(str.length(), 0);
  transform(str.begin(), str.end(), digits.begin(),
            [](char c) -> int { return c - '0'; });

  stack<int> s;

  for (int i = 0; i < digits.size(); ++i) {
    while (k > 0 and !s.empty() and s.top() > digits[i]) {
      s.pop();
      k--;
    }
    s.push(digits[i]);
  }

  while (k) {
    s.pop();
    k--;
  }

  vector<int> res;

  while (not s.empty()) {
    res.push_back(s.top());
    s.pop();
  }

  while (not res.empty() and res.back() == 0) {
    res.pop_back();
  }

  if (res.empty()) {
    return "0";
  }

  stringstream ss;
  copy(res.rbegin(), res.rend(),
       std::ostream_iterator<decltype(res[0])>{ss, ""});

  return ss.str();
}

string remove_k_digits_fast(string num, int k) {
  string res;

  for (int i = 0; i < num.size() - 1; i++) {
    if (res.empty() && num[i] == '0')
      continue; // don't add leading zeros
    if (k == 0 || num[i] <= num[i + 1])
      res += num[i]; // already removed_k_digits or digit is less than later
    else {
      // digit is more than later
      k--; // we didn't add so decreasing for that one
      while (k > 0 && !res.empty() && res.back() > num[i + 1]) {
        res.pop_back();
        k--; // decreasing for now k
      }
    }
  }
  res += num.back(); // last digit is always added
  while (!res.empty() && k) {
    res.pop_back();
    // if there was increasing sequence remove larger numbers from back
    k--;
  }
  return res.empty() ? "0" : res;
}
void solve() {
  string str;
  int k;
  cin >> str >> k;

  cout << remove_k_digits(str, k) << " " << remove_k_digits_fast(str, k)
       << "\n";
  // string to digits
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
