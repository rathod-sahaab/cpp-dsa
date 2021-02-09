#ifndef BIDIRECTIONAL_GRAPH_HPP
#define BIDIRECTIONAL_GRAPH_HPP

#include <bits/stdc++.h>
/*
 * Implementation of bidirectional graph using adjacency list
 */
class BidirectionalGraph {
private:
  std::vector<std::vector<int>> _data;

public:
  // resize _data vector to hold given nodes
  BidirectionalGraph(int n_nodes) : _data(n_nodes) {}
  void connect(int source, int to) {
    if (source >= 0 and source < _data.size() and to >= 0 and
        to < _data.size()) {
      // only if they are valid graph nodes
      // front track
      _data[source].push_back(to);
      // back track
      _data[to].push_back(source);
    }
  }
};

#endif // BIDIRECTIONAL_GRAPH_HPP
