#ifndef CONNECTED_COMPONENTS_HPP
#define CONNECTED_COMPONENTS_HPP

#include "../../undirected-graph.hpp"
#include <bits/stdc++.h>

using namespace std;

class ConnectedComponents {
public:
  // constructors, asssignment, destructor
  ConnectedComponents(const UndirectedGraph &graph)
      : id(graph.get_vertices()), visited(graph.get_vertices(), false) {
    for (int i = 0; i < graph.get_vertices(); ++i) {
      if (not visited[i]) {
        dfs(graph, i);
        count++;
      }
    }
  }

  int get_count() { return count; }
  int get_id(int vertex) { return id[vertex]; }

  bool connected(int u, int v) { return id[u] == id[v]; }

private:
  void dfs(const UndirectedGraph &graph, int v) {
    for (const int child : graph.adj(v)) {
      if (not visited[child]) {
        visited[child] = true;
        id[child] = count;
        dfs(graph, child);
      }
    }
  }

  vector<int> id;
  vector<bool> visited;
  int count = 0;
};

#endif // CONNECTED_COMPONENTS_HPP
