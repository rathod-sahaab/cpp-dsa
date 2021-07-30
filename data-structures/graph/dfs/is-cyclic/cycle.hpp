#ifndef CYCLE_HPP
#define CYCLE_HPP

#include "../../undirected-graph.hpp"
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Cycle {
public:
  Cycle(const UndirectedGraph &graph) : visited(graph.get_vertices(), false) {
    for (int i = 0; i < graph.get_vertices(); ++i) {
      if (not visited[i]) {
        dfs(graph, i, i);
      }
    }
  }

  bool is_cyclic() const { return cyclic; }

private:
  void dfs(const UndirectedGraph &graph, int curr, int parent) {
    visited[curr] = true;
    for (const int child : graph.adj(curr)) {
      if (not visited[child]) {
        dfs(graph, child, curr);
      } else if (child != parent) {
        // child of curr already visited, cycle exists
        cyclic = true;
      }
    }
  }
  vector<bool> visited;
  bool cyclic = false;
};

#endif // CYCLE_HPP
