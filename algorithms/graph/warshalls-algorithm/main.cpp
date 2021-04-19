#include <bits/stdc++.h>
#include <vector>
using namespace std;

std::vector<std::vector<bool>>
generate_path_matrix(std::vector<std::vector<bool>> p) {
  // Warshall's algorithm
  const int N = p.size();

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        p[i][j] = p[i][j] or (p[i][k] and p[k][j]);
      }
    }
  }

  return p;
}

void create_graph(std::vector<std::vector<bool>> &graph) {
  int src, dest;
  do {
    cout << "Enter new edge <src> <dest> (-1 -1 to stop adding edges): ";
    cin >> src >> dest;

    if (0 <= src and src < graph.size() and 0 <= dest and dest < graph.size()) {
      graph[src][dest] = true;
      // graph[dest][src] = true; // undirected
      cout << "GRAPH MATRIX:\n";
      for (const auto row : graph) {
        copy(std::begin(row), std::end(row),
             std::ostream_iterator<decltype(row[0])>{std::cout, " "});
        std::cout << "\n";
      }
    }
  } while (src != -1);
}

int main(int argc, char *argv[]) {
  size_t N;
  cin >> N;

  std::vector<std::vector<bool>> g(N, vector<bool>(N, false));

  create_graph(g);
  const auto p = generate_path_matrix(g);

  cout << "PATH MATRIX:\n";
  for (const auto row : p) {
    copy(std::begin(row), std::end(row),
         std::ostream_iterator<decltype(row[0])>{std::cout, " "});
    std::cout << "\n";
  }
  return 0;
}
