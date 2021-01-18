#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <bits/stdc++.h>

enum class TreeTraversalMode {
  PRE_ORDER,
  IN_ORDER,
  POST_ORDER,
};

template <typename T> struct BinaryNode {
  T value;
  std::unique_ptr<BinaryNode<T>> left = nullptr, right = nullptr;

  BinaryNode(T val) { value = val; }
};

template <typename T> class BinaryTree {
  std::unique_ptr<BinaryNode<T>> _root = nullptr;

public:
  // constructors, asssignment, destructor
  BinaryTree();
  void insert(T val);

  // search
  bool depth_first_search(T val);
  bool breadth_first_search(T val);

  // traversal
  /* std::vector<T> traverse(TreeTraversalMode mode); */

private:
};

/// Iterative approach
template <typename T> void BinaryTree<T>::insert(T val) {
  if (not _root) {
    _root = std::make_unique<BinaryNode<T>>(val);
    return;
  }

  auto current = _root;
  while (current) {
    if (val < current->value) {
      if (not current->left) {
        current->left = std::make_unique<BinaryNode<T>>(val);
        return;
      }
      current = current->left;
    } else if (val > current->value) {
      if (not current->right) {
        current->right = std::make_unique<BinaryNode<T>>(val);
        return;
      }
      current = current->right;
    }
  }
}

template <typename T> bool BinaryTree<T>::depth_first_search(T val) {
  std::stack<BinaryNode<T>> s;

  s.push(_root);
  while (not s.empty()) {
    auto current = s.top();
    s.pop();

    if (current->left) {
      s.push(current->left);
    }
    if (current->right) {
      s.push(current->right);
    }
  }
}

template <typename T> bool BinaryTree<T>::breadth_first_search(T val) {
  std::queue<BinaryNode<T>> q;

  q.push(_root);
  while (not q.empty()) {
    auto current = q.front();
    q.pop();

    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }
}

/*
template <typename T>
std::vector<T> BinaryTree<T>::traverse(TreeTraversalMode mode) {
  std::vector<T> result;
  std::stack<BinaryNode<T>> s;

  if (_root) {
    s.push(_root);
  }
  while (not s.empty()) {
    auto current = s.top();
    s.pop();

    if (current->left) {
      s.push(current->left);
    }
    if (current->right) {
      s.push(current->right);
    }
  }
}
*/
#endif // BINARY_TREE_HPP
