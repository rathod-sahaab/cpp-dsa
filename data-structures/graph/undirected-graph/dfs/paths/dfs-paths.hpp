#ifndef DFS_HPP
#define DFS_HPP

#include "../../undirected-graph.hpp"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class DepthFirstPaths {
public:
  DepthFirstPaths(const UndirectedGraph &graph, int s)
      : visited(graph.get_vertices(), false), prev(graph.get_vertices(), -1),
        s(s) {
    dfs(graph, s);
  }

  bool has_path_to(int v) { return visited[v]; }

  vector<int> get_path_to(int v) {
    if (not has_path_to(v)) {
      return {};
    }
    vector<int> result;

    for (int curr = v; curr != s; curr = prev[curr]) {
      result.push_back(curr);
    }
    result.push_back(s);

    reverse(result.begin(), result.end());
    return result;
  }

private:
  void dfs(const UndirectedGraph &graph, int v) {
    visited[v] = true;

    for (const auto vertex : graph.adj(v)) {
      if (not visited[vertex]) {
        prev[vertex] = v;
        dfs(graph, vertex);
      }
    }
  }

  int s; // source
  vector<bool> visited;
  /**
   * previous node in path from source
   */
  vector<int> prev;
};

#endif // DFS_HPP
