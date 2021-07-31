#include "../../undirected-graph.hpp"
#include "bfs-paths.hpp"

#include <bits/stdc++.h>
using namespace std;

void solve() {
  UndirectedGraph graph = UndirectedGraph::from_input(cin);

  int s;
  cin >> s;
  DepthFirstPaths bfs_paths(graph, s);

  for (int i = 0; i < graph.get_vertices(); ++i) {
    const auto path = bfs_paths.get_path_to(i);
    if (path.empty()) {
      continue;
    }
    cout << i << ": ";

    for (const auto node : path) {
      cout << node << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
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
