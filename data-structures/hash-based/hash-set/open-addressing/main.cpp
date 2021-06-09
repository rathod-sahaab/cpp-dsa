#include <bits/stdc++.h>
using namespace std;

#include "open-addressing-hash-set.hpp"

void solve() {
  int N;
  cin >> N;

  vector<short> seen(N);

  HashSet hs(31);

  for (int i = 0; i < N; ++i) {
    int number;
    cin >> number;

    seen[i] = hs.find(number);
    hs.insert(number);
  }

  copy(std::begin(seen), std::end(seen),
       std::ostream_iterator<decltype(seen[0])>{std::cout, " "});
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
