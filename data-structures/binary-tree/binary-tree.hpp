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
  BinaryNode<T> *left = nullptr, *right = nullptr;

  BinaryNode(T val) { value = val; }
};

template <typename T> class BinaryTree {
  BinaryNode<T> *_root = nullptr;

  std::vector<T> _pre_order_traversal() const noexcept;

public:
  // constructors, asssignment, destructor
  BinaryTree() = default;
  ~BinaryTree(); // delete newed

  void insert(T val);

  // search
  bool depth_first_search(T val) const noexcept;
  bool breadth_first_search(T val) const noexcept;

  // traversal
  std::vector<T> traverse(TreeTraversalMode mode) const noexcept;

private:
};

template <typename T> BinaryTree<T>::~BinaryTree() {
  std::stack<BinaryNode<T> *> s;

  s.push(_root);
  while (not s.empty()) {
    auto current = s.top();
    s.pop();

    if (current->right) {
      s.push(current->right);
    }
    if (current->left) {
      s.push(current->left);
    }

    delete current;
  }
}

/// Iterative approach
template <typename T> void BinaryTree<T>::insert(T val) {
  BinaryNode<T> *new_node = new BinaryNode<T>(val);
  if (not _root) {
    _root = new_node;
    return;
  }

  auto current = _root;
  while (current) {
    if (val < current->value) {
      if (not current->left) {
        current->left = new_node;
        return;
      }
      current = current->left;
    } else if (val > current->value) {
      if (not current->right) {
        current->right = new_node;
        return;
      }
      current = current->right;
    }
  }
}

template <typename T>
bool BinaryTree<T>::depth_first_search(T val) const noexcept {
  std::stack<BinaryNode<T> *> s;

  s.push(_root);
  while (not s.empty()) {
    auto current = s.top();
    s.pop();

    if (current->right) {
      s.push(current->right);
    }
    if (current->left) {
      s.push(current->left);
    }
  }
}

template <typename T>
bool BinaryTree<T>::breadth_first_search(T val) const noexcept {
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

template <typename T>
std::vector<T> BinaryTree<T>::traverse(TreeTraversalMode mode) const noexcept {
  switch (mode) {
  case TreeTraversalMode::PRE_ORDER:
    return _pre_order_traversal();
  case TreeTraversalMode::POST_ORDER:
    return {};
  case TreeTraversalMode::IN_ORDER:
    return {};
  }
}

template <typename T>
std::vector<T> BinaryTree<T>::_pre_order_traversal() const noexcept {
  std::vector<T> result;
  std::stack<BinaryNode<T> *> s;

  if (_root) {
    s.push(_root);
  }

  while (not s.empty()) {
    const auto current = s.top();
    s.pop();

    result.push_back(current->value);

    if (current->right) {
      s.push(current->right);
    }
    if (current->left) {
      s.push(current->left);
    }
  }

  return result;
}

#endif // BINARY_TREE_HPP
