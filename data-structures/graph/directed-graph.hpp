#ifndef DIRECTED_GRAPH_HPP
#define DIRECTED_GRAPH_HPP

#include <bits/stdc++.h>
/*
 * Implementation of directed graph using adjacency list
 * This is not to say you can't use it as a undirected graph
 * You just have add back route manually
 * i.e. connect(x, y) and then connect(y, x) but bidirectional
 * graph does that automatically for you
 */
class DirectedGraph {
private:
  std::vector<std::vector<int>> _data;

public:
  // resize _data vector to hold given nodes
  DirectedGraph(int n_nodes) : _data(n_nodes) {}
  void connect(int source, int to) {
    if (source >= 0 and source < _data.size() and to >= 0 and
        to < _data.size()) {
      // only if they are valid graph nodes
      // front track
      _data[source].push_back(to);
    }
  }
};

#endif // DIRECTED_GRAPH_HPP
