#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <bits/stdc++.h>

using namespace std;

class Digraph {
public:
  // constructors, asssignment, destructor
  Digraph(int vertices) : graph(vertices) {}
  int V() { return graph.size(); }
  int E() { return edges; }
  vector<int> adj(int vertex);

  Digraph reverse() {
    Digraph reversed_graph(V());

    for (int i = 0; i < V(); ++i) {
      for (const auto &child : adj(i)) {
        reversed_graph.add_edge(child, i);
      }
    }

    return reversed_graph;
  }

  void add_edge(int src, int dest) {
    graph[src].push_back(dest);
    edges++;
  }

private:
  vector<vector<int>> graph;
  int edges = 0;
};

#endif // DIGRAPH_HPP
