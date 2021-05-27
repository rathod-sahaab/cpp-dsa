#include <bits/stdc++.h>
using namespace std;

#include "hash-set.hpp"

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  HashSet hs(31);

  for (auto &number : numbers) {
    cin >> number;
    if (hs.find(number)) {
      cout << "Seen " << number << " before\n";
    }
    hs.insert(number);
  }
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
