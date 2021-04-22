#ifndef GRAPH_UI_HPP
#define GRAPH_UI_HPP

#include <iostream>
#include <iterator>
#include <vector>

namespace GraphUI {

void create_graph_weighted(std::vector<std::vector<int>> &graph) {
  int src, dest, weight;
  do {
    std::cout << "Enter new edge <src> <dest> (-1 -1 to stop adding edges): ";
    std::cin >> src >> dest >> weight;

    if (0 <= src and src < graph.size() and 0 <= dest and dest < graph.size()) {
      graph[src][dest] = weight;
      // graph[dest][src] = true; // undirected
      std::cout << "GRAPH MATRIX:\n";
      for (const auto row : graph) {
        copy(std::begin(row), std::end(row),
             std::ostream_iterator<decltype(row[0])>{std::cout, " "});
        std::cout << "\n";
      }
    }
  } while (src != -1);
}

} // namespace GraphUI

#endif // GRAPH_UI_HPP
