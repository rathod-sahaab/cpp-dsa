#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <bits/stdc++.h>

using namespace std;

class Digraph {
public:
  // constructors, asssignment, destructor
  Digraph(int vertices) : graph(vertices) {}
  int V() const { return graph.size(); }
  int E() const { return edges; }
  vector<int> adj(int vertex) const { return graph[vertex]; }

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

  static Digraph from_input(istream &in) {
    int n_vertices;
    in >> n_vertices;

    Digraph graph(n_vertices);

    int n_edges;
    in >> n_edges;

    while (n_edges--) {
      int src, dest;
      in >> src >> dest;
      graph.add_edge(src, dest);
    }

    return graph;
  }

  void print(ostream &out) {
    for (int i = 0; i < V(); ++i) {
      cout << i << ": ";

      for (const int child : adj(i)) {
        cout << child << " ";
      }

      cout << "\n";
    }
  }

private:
  vector<vector<int>> graph;
  int edges = 0;
};

#endif // DIGRAPH_HPP
