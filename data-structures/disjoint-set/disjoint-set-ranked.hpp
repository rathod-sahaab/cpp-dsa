#ifndef DISJOINT_SET_RANKED_HPP
#define DISJOINT_SET_RANKED_HPP
#include <bits/stdc++.h>

class DisjointSetRanked {
  std::vector<size_t> _parent, _rank;

public:
  DisjointSetRanked(size_t n_vertices)
      : _parent(n_vertices), _rank(n_vertices, 0) {
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
      if (_rank[a] < _rank[b]) {
        std::swap(a, b);
      }
      _parent[b] = a;
      if (_rank[a] == _rank[b]) {
        _rank[a]++;
      }
    }
  }
};

#endif // DISJOINT_SET_RANKED_HPP
