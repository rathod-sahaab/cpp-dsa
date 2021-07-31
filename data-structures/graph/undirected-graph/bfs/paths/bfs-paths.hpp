#ifndef DFS_HPP
#define DFS_HPP

#include "../../undirected-graph.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class DepthFirstPaths {
public:
  DepthFirstPaths(const UndirectedGraph &graph, int s)
      : visited(graph.get_vertices(), false), prev(graph.get_vertices(), -1),
        s(s) {
    bfs(graph, s);
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
  void bfs(const UndirectedGraph &g, int v) {

    queue<int> q;
    visited[v] = true;

    while (not q.empty()) {
      v = q.front();
      q.pop();
      for (const auto vertex : g.adj(v)) {
        if (not visited[vertex]) {
          visited[vertex] = true;
          prev[vertex] = v;
          q.push(vertex);
        }
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
