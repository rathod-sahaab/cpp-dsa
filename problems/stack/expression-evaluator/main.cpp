#include <bits/stdc++.h>

#include "pmath.cpp"

using namespace std;

void solve() {
  string expression_string;
  cin >> expression_string;

  const auto post_fix = post_fixer(expression_string);

  cout << post_fix << "\n";

  const float result = evaluate_postfix(post_fix);

  cout << result << "\n";
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
