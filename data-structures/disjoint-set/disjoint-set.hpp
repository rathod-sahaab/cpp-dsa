#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP
#include <bits/stdc++.h>

class DisjointSet {
  std::vector<size_t> _parent;

public:
  DisjointSet(size_t n_vertices) : _parent(n_vertices) {
    std::iota(_parent.begin(), _parent.end(), 0);
  }

  size_t find_set(size_t vertex) {
    std::vector<size_t> path_nodes;

    while (vertex != _parent[vertex]) {
      path_nodes.push_back(vertex);
      vertex = _parent[vertex];
    }

    const int final_parent = vertex;
    for (const auto &node : path_nodes) {
      _parent[node] = final_parent; // Path Compression
    }
    /*
     * recursive
    if (vertex == _parent[vertex]) {
      return vertex;
    }
    return _parent[vertex] = find_set(_parent[vertex]); // Path Compression
    */

    return final_parent;
  }
  void union_sets(size_t a, size_t b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      _parent[b] = a;
    }
  }
};

#endif // DISJOINT_SET_HPP
