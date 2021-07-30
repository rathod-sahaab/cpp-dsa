#include "../../undirected-graph.hpp"
#include "cycle.hpp"

#include <bits/stdc++.h>
using namespace std;

void solve() {
  UndirectedGraph graph = UndirectedGraph::from_input(cin);

  Cycle c(graph);

  if (not c.is_cyclic()) {
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
