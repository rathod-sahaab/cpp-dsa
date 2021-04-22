#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <iterator>
#include <queue>

#include "../graph-ui.hpp"

#define NIL -1

using namespace std;
using Graph = vector<vector<int>>;

struct BellmanFordData {
  std::vector<int> parent, distance, in_queue;

  BellmanFordData(int N)
      : parent(N, NIL), distance(N, INT_MAX), in_queue(N, false) {}
};

BellmanFordData bellman_ford_solve(const Graph &g, int source) {
  assert(0 <= source and source < g.size());
  BellmanFordData bfd(g.size());

  queue<int> q;

  bfd.distance[source] = 0;
  q.push(source);

  while (not q.empty()) {
    auto current = q.front();
    q.pop();
    bfd.in_queue[current] = false;

    if (current == NIL) {
      return bfd;
    }

    for (int i = 0; i < g.size(); ++i) {
      if (g[current][i] != 0) { // path exists and vertex is not permanent
        if (g[current][i] + bfd.distance[current] < bfd.distance[i]) {
          bfd.parent[i] = current;
          bfd.distance[i] = g[current][i] + bfd.distance[current];
          if (not bfd.in_queue[i]) {
            q.push(i);
            bfd.in_queue[i] = true;
          }
        }
      }
    }
  }
  return bfd;
}

int main(int argc, char *argv[]) {
  size_t N;
  cin >> N;

  Graph g(N, vector<int>(N, 0));

  GraphUI::create_graph_weighted(g);

  int src, dest;
  cin >> src >> dest;

  const auto dijkstra_data = bellman_ford_solve(g, src);

  printf("Minimum distance between %d - %d is %d units.\n", src, dest,
         dijkstra_data.distance[dest]);

  copy(std::begin(dijkstra_data.distance), std::end(dijkstra_data.distance),
       std::ostream_iterator<decltype(dijkstra_data.distance[0])>{std::cout,
                                                                  " "});
  std::cout << "\n";

  return 0;
}
