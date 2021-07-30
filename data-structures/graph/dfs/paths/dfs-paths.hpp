#ifndef DFS_HPP
#define DFS_HPP

#include "../../undirected-graph.hpp"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class DepthFirstPaths {
public:
  DepthFirstPaths(const UndirectedGraph &graph, int s)
      : g(graph), visited(graph.get_vertices(), false),
        prev(graph.get_vertices(), -1), s(s) {
    dfs(s);
  }

  int get_count() const { return count; };

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
  void dfs(int v) {
    visited[v] = true;
    count++;

    for (const auto vertex : g.adj(v)) {
      if (not visited[vertex]) {
        prev[vertex] = v;
        dfs(vertex);
      }
    }
  }

  const UndirectedGraph &g;
  int s; // source
  vector<bool> visited;
  /**
   * previous node in path from source
   */
  vector<int> prev;
  /**
   * Number of visisted during operation
   */
  int count;
};

#endif // DFS_HPP
