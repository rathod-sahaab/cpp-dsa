#ifndef BIPARTITE_HPP
#define BIPARTITE_HPP

#include "../../undirected-graph.hpp"
#include <bits/stdc++.h>

class Bipartite {
public:
  Bipartite(const UndirectedGraph &graph)
      : visited(graph.get_vertices(), false),
        color(graph.get_vertices(), false) {
    for (int i = 0; i < graph.get_vertices(); ++i) {
      dfs(graph, i);
    }
  }

  bool is_bipartite() const { return bipartite; }

private:
  void dfs(const UndirectedGraph &graph, int current) {
    visited[current] = true;

    for (const int child : graph.adj(current)) {
      if (not visited[child]) {
        color[child] = !color[current];
        dfs(graph, child);
      } else if (color[child] == color[current]) {
        // graph is not bipartite because a node already painted in same color
        // as its adjacent, because other adjacent node painted it in this color
        // conflict of interest and hence graph is not bipartite
        bipartite = false;
      }
    }
  }

  vector<bool> visited;
  vector<bool> color;

  bool bipartite = true;
};

#endif // BIPARTITE_HPP
