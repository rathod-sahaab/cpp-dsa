#include "binary-tree.hpp"
#include <algorithm>
#include <cassert>
#include <vector>
int main() {
  BinaryTree<int> bt;

  bt.insert(3);
  bt.insert(4);
  bt.insert(10);
  bt.insert(7);
  bt.insert(5);
  bt.insert(1);
  bt.insert(2);

  const auto traversal = bt.traverse(TreeTraversalMode::PRE_ORDER);

  std::vector<int> expected{
      3, 1, 2, 4, 10, 7, 5,
  };
  std::vector<int> not_expected{
      2, 4, 10, 7, 5,
  };

  copy(std::begin(traversal), std::end(traversal),
       std::ostream_iterator<decltype(traversal[0])>{std::cout, ", "});

  std::cout << "\n";

  assert(traversal == expected);
  assert(traversal != not_expected);

  return 0;
}
