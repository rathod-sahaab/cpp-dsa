#ifndef DISJOINT_SET_SIZED_HPP
#define DISJOINT_SET_SIZED_HPP

#include <bits/stdc++.h>
class DisjointSetSized {
  std::vector<size_t> _parent, _size;

public:
  DisjointSetSized(size_t n_vertices)
      : _parent(n_vertices), _size(n_vertices, 1) {
    std::iota(_parent.begin(), _parent.end(), 0);
  }

  size_t find_set(size_t vertex) {
    if (vertex == _parent[vertex]) {
      return vertex;
    }
    return _parent[vertex] = find_set(_parent[vertex]);
  }
  void union_sets(size_t a, size_t b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
      if (_size[a] < _size[b]) {
        std::swap(a, b);
      }
      _parent[b] = a;
      _size[a] += _size[b];
    }
  }
};

#endif // DISJOINT_SET_SIZED_HPP
