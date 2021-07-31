#include "../../undirected-graph.hpp"
#include "dfs.hpp"

#include <bits/stdc++.h>
using namespace std;

void solve() {
  UndirectedGraph graph = UndirectedGraph::from_input(cin);

  int s;
  cin >> s;
  DFS dfs(graph, s);

  if (dfs.get_count() != graph.get_vertices()) {
    cout << "NOT ";
  }
    cout << "CONNECTED\n";
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
