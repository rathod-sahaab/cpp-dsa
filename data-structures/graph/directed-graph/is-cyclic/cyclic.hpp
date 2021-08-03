#ifndef CYCLIC_HPP
#define CYCLIC_HPP

#include "../digraph.hpp"
#include <bits/stdc++.h>
#include <vector>

class Cyclic {
public:
  // constructors, asssignment, destructor
  Cyclic(const Digraph &digraph)
      : visited(digraph.V(), false), stacked(digraph.V(), false) {
    for (int i = 0; i < digraph.V(); i++) {
      if (not visited[i]) {
        dfs(digraph, i);
      }
    }
  }

  bool is_cyclic() { return cyclic; }

private:
  void dfs(const Digraph &digraph, int s) {
    stacked[s] = true;

    visited[s] = true;

    for (const int child : digraph.adj(s)) {
      if (is_cyclic()) {
        return;
      }
      if (not visited[child]) {
        dfs(digraph, child);
        continue;
      }
      if (stacked[child]) {
        cyclic = true;
        return;
      }
    }

    stacked[s] = false;
  }

  vector<bool> visited;
  vector<bool> stacked;
  bool cyclic = false;
};

#endif // CYCLIC_HPP
