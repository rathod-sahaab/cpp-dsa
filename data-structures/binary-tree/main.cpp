#include "binary-search-tree.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

int main() {
  BinarySearchTree<int> bst;

  bst.insert(3);
  bst.insert(4);
  bst.insert(10);
  bst.insert(7);
  bst.insert(5);
  bst.insert(1);
  bst.insert(2);

  const auto traversal_pre = bst.traverse(TreeTraversalMode::PRE_ORDER);
  const auto traversal_in = bst.traverse(TreeTraversalMode::IN_ORDER);
  const auto traversal_post = bst.traverse(TreeTraversalMode::POST_ORDER);
  const auto traversal_level = bst.traverse(TreeTraversalMode::LEVEL_ORDER);

  std::vector<int> expected_pre{
      3, 1, 2, 4, 10, 7, 5,
  },
      expected_in{
          1, 2, 3, 4, 5, 7, 10,
      },
      expected_post{
          2, 1, 5, 7, 10, 4, 3,
      },
      expected_level{
          3, 1, 4, 2, 10, 7, 5,
      };
  std::vector<int> not_expected{
      2, 4, 7, 5, 10,
  };

  std::cout << "PRE_ORDER: ";
  copy(std::begin(traversal_pre), std::end(traversal_pre),
       std::ostream_iterator<decltype(traversal_pre[0])>{std::cout, ", "});
  std::cout << "\n";

  std::cout << "IN_ORDER: ";
  copy(std::begin(traversal_in), std::end(traversal_in),
       std::ostream_iterator<decltype(traversal_in[0])>{std::cout, ", "});
  std::cout << "\n";

  std::cout << "POST_ORDER: ";
  copy(std::begin(traversal_post), std::end(traversal_post),
       std::ostream_iterator<decltype(traversal_post[0])>{std::cout, ", "});
  std::cout << "\n";

  std::cout << "LEVEL_ORDER: ";
  copy(std::begin(traversal_level), std::end(traversal_level),
       std::ostream_iterator<decltype(traversal_level[0])>{std::cout, ", "});
  std::cout << "\n";

  assert(traversal_pre == expected_pre);
  assert(traversal_in == expected_in);
  assert(traversal_post == expected_post);
  assert(traversal_level == expected_level);

  assert(traversal_pre != not_expected);
  assert(traversal_in != not_expected);
  assert(traversal_post != not_expected);
  assert(traversal_level != not_expected);

  assert(bst.breadth_first_search(3) == true);
  assert(bst.breadth_first_search(INT16_MIN) == false);

  assert(bst.depth_first_search(3) == true);
  assert(bst.depth_first_search(INT16_MIN) == false);

  return 0;
}
