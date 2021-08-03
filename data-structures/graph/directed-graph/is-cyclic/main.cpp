#include "../digraph.hpp"
#include "cyclic.hpp"
#include <bits/stdc++.h>
using namespace std;

void solve() {
  Digraph digraph = Digraph::from_input(cin);
  Cyclic cyclic(digraph);

  if (not cyclic.is_cyclic()) {
    cout << "NOT ";
  }
  cout << "CYCLIC\n";
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
