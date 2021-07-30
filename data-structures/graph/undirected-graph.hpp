#ifndef UNDIRECTED_GRAPH_HPP
#define UNDIRECTED_GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph {
public:
  /**
   * Create a graph with V vertices
   */
  explicit UndirectedGraph(int V) : adj_lists(V) {}

  /**
   * Get the number of edges in graph
   */
  int get_edges() const { return edges; };

  /**
   * Get the number of edges in graph
   */
  int get_vertices() const { return adj_lists.size(); }

  /**
   * Get vertices, adjacent to the vertex
   */
  vector<int> adj(int v) const { return adj_lists[v]; }

  /**
   * Add an edge between u and v vertices
   */
  void add_edge(int u, int v) {
    adj_lists[u].push_back(v);
    adj_lists[v].push_back(u);
    // increase count of edges
    edges++;
  }

  /**
   * Factory function to create from input
   */
  static UndirectedGraph from_input(istream &in) {
    int V, E;
    in >> V >> E;

    UndirectedGraph graph(V);

    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      graph.add_edge(u, v);
    }

    return graph;
  }

private:
  vector<vector<int>> adj_lists;
  /**
   * Number of edges in graph
   */
  int edges;
};

#endif // UNDIRECTED_GRAPH_HPP
