#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <iostream>
#include <iterator>
#include <queue>

#include "../graph-ui.hpp"

#define NIL -1

using namespace std;
using Graph = vector<vector<int>>;

struct DijkstraData {
  std::vector<int> predecessor, distance;
  std::vector<bool> is_permanent;

  DijkstraData(int N)
      : predecessor(N, NIL), distance(N, INT_MAX), is_permanent(N, false) {}
};

int min_element(const DijkstraData &dd) {
  int k = NIL;
  int min = INT_MAX;

  for (int i = 0; i < dd.distance.size(); ++i) {
    if (not dd.is_permanent[i] and min > dd.distance[i]) {
      min = dd.distance[i];
      k = i;
    }
  }

  return k;
}

DijkstraData dijkstra_solve(const Graph &g, int source) {
  assert(0 <= source and source < g.size());
  DijkstraData dd(g.size());

  dd.distance[source] = 0;

  while (true) {
    auto current = min_element(dd);
    if (current == NIL) {
      return dd;
    }

    dd.is_permanent[current] = true;

    for (int i = 0; i < g.size(); ++i) {
      if (g[current][i] != 0 and
          not dd.is_permanent[i]) { // path exists and vertex is not permanent
        if (g[current][i] + dd.distance[current] < dd.distance[i]) {
          dd.predecessor[i] = current;
          dd.distance[i] = g[current][i] + dd.distance[current];
        }
      }
    }
  }
}

vector<int> shortest_path(const DijkstraData &dd, int dest) {
  vector<int> sp;
  auto current = dest;
  while (dd.predecessor[current] != NIL) {
    sp.push_back(current);
    current = dd.predecessor[current];
  }
  sp.push_back(current); // source

  reverse(sp.begin(), sp.end());

  return sp;
}

void print_shortest_path(const vector<int> &sp);

int main(int argc, char *argv[]) {
  size_t N;
  cin >> N;

  Graph g(N, vector<int>(N, 0));

  GraphUI::create_graph_weighted(g);

  int src, dest;
  cin >> src >> dest;

  const auto dijkstra_data = dijkstra_solve(g, src);

  printf("Minimum distance between %d - %d is %d units.\n", src, dest,
         dijkstra_data.distance[dest]);

  const auto sp = shortest_path(dijkstra_data, dest);
  print_shortest_path(sp);

  cout << "Other shortest paths from given source:\n";
  copy(std::begin(dijkstra_data.distance), std::end(dijkstra_data.distance),
       std::ostream_iterator<decltype(dijkstra_data.distance[0])>{std::cout,
                                                                  " "});
  std::cout << "\n";

  return 0;
}

void print_shortest_path(const vector<int> &sp) {
  cout << "Shortest path: ";
  copy(std::begin(sp), std::end(sp) - 1,
       std::ostream_iterator<decltype(sp[0])>{std::cout, "->"});
  cout << sp.back() << ";\n";
}
