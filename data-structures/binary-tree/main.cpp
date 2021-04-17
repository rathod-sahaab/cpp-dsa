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

  const auto traversal_pre = bt.traverse(TreeTraversalMode::PRE_ORDER);
  const auto traversal_in = bt.traverse(TreeTraversalMode::IN_ORDER);
  const auto traversal_post = bt.traverse(TreeTraversalMode::POST_ORDER);

  std::vector<int> expected_pre{
      3, 1, 2, 4, 10, 7, 5,
  },
      expected_in{
          1, 2, 3, 4, 5, 7, 10,
      },
      expected_post{
          2, 1, 5, 7, 10, 4, 3,
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

  assert(traversal_pre == expected_pre);
  assert(traversal_in == expected_in);
  assert(traversal_post == expected_post);

  assert(traversal_pre != not_expected);
  assert(traversal_in != not_expected);
  assert(traversal_post != not_expected);

  assert(bt.breadth_first_search(3) == true);
  assert(bt.breadth_first_search(INT16_MIN) == false);

  assert(bt.depth_first_search(3) == true);
  assert(bt.depth_first_search(INT16_MIN) == false);

  return 0;
}
