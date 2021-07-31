#include "../../undirected-graph.hpp"
#include "bipartite.hpp"

#include <bits/stdc++.h>
using namespace std;

void solve() {
  UndirectedGraph graph = UndirectedGraph::from_input(cin);

  Bipartite bipartite(graph);

  if (not bipartite.is_bipartite()) {
    cout << "NOT ";
  }
  cout << "BIPARTITE\n";
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
