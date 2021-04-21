#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <iterator>
#include <queue>

#include "../graph-ui.hpp"

#define NIL -1

using namespace std;
using Graph = vector<vector<int>>;

struct DijkstraData {
  std::vector<int> parent, distance;
  std::vector<bool> is_permanent;

  DijkstraData(int N)
      : parent(N, NIL), distance(N, INT_MAX), is_permanent(N, false) {}
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
          dd.parent[i] = current;
          dd.distance[i] = g[current][i] + dd.distance[current];
        }
      }
    }
  }
}

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

  copy(std::begin(dijkstra_data.distance), std::end(dijkstra_data.distance),
       std::ostream_iterator<decltype(dijkstra_data.distance[0])>{std::cout,
                                                                  " "});
  std::cout << "\n";

  return 0;
}
