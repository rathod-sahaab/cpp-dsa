#ifndef DFS_HPP
#define DFS_HPP

#include "../../undirected-graph.hpp"
#include <bits/stdc++.h>

using namespace std;

class DFS {
public:
  DFS(const UndirectedGraph &graph, int s)
      : visited(graph.get_vertices(), false) {
    dfs(graph, s);
  }

  bool is_visited(int v) const { return visited[v]; }
  int get_count() const { return count; };

private:
  void dfs(const UndirectedGraph &graph, int v) {
    visited[v] = true;
    count++;

    for (const auto vertex : graph.adj(v)) {
      if (not visited[vertex]) {
        dfs(graph, vertex);
      }
    }
  }

  vector<bool> visited;
  /**
   * Number of visisted during operation
   */
  int count;
};

#endif // DFS_HPP
