#include <bits/stdc++.h>
using namespace std;

#include "../../undirected-graph.hpp"
#include "connected-components.hpp"
void solve() {
  ifstream f("test.txt");
  const auto graph = UndirectedGraph::from_input(cin);

  ConnectedComponents cc(graph);

  vector<vector<int>> components(cc.get_count());

  for (int vertex = 0; vertex < graph.get_vertices(); ++vertex) {
    components[cc.get_id(vertex)].push_back(vertex);
  }

  for (int i = 0; i < cc.get_count(); ++i) {
    cout << i << " : ";
    for (const auto node : components[i]) {
      cout << node << " ";
    }
    cout << "\n";
  }
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
