#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <bits/stdc++.h>

enum class TreeTraversalMode { PRE_ORDER, IN_ORDER, POST_ORDER, LEVEL_ORDER };

template <typename T> struct BinaryNode {
  T value;
  BinaryNode<T> *left = nullptr, *right = nullptr;

  BinaryNode(T val) { value = val; }
};

template <typename T> class BinaryTree {
protected:
  BinaryNode<T> *_root = nullptr;

private:
  std::vector<T> _pre_order_traversal() const noexcept;
  std::vector<T> _in_order_traversal() const noexcept;
  std::vector<T> _post_order_traversal() const noexcept;
  std::vector<T> _level_order_traversal() const noexcept;

public:
  // constructors, asssignment, destructor
  BinaryTree() = default;
  ~BinaryTree(); // delete newed

  // search
  bool depth_first_search(T val) const noexcept;
  BinaryNode<T> *depth_first_search_ptr(T val) const noexcept;

  bool breadth_first_search(T val) const noexcept;
  BinaryNode<T> *breadth_first_search_ptr(T val) const noexcept;

  // traversal
  std::vector<T> traverse(TreeTraversalMode mode) const noexcept;
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

template <typename T>
BinaryNode<T> *BinaryTree<T>::depth_first_search_ptr(T val) const noexcept {
  if (not _root) {
    return nullptr;
  }

  std::stack<BinaryNode<T> *> s;
  s.push(_root);

  while (not s.empty()) {
    auto current = s.top();
    s.pop();

    if (current->value == val) {
      return current;
    }

    if (current->right) {
      s.push(current->right);
    }
    if (current->left) {
      s.push(current->left);
    }
  }

  return nullptr;
}

template <typename T>
bool BinaryTree<T>::depth_first_search(T val) const noexcept {
  return depth_first_search_ptr(val) != nullptr;
}

template <typename T>
BinaryNode<T> *BinaryTree<T>::breadth_first_search_ptr(T val) const noexcept {
  if (not _root) {
    return nullptr;
  }

  std::queue<BinaryNode<T> *> q;
  q.push(_root);

  while (not q.empty()) {
    auto current = q.front();
    q.pop();

    if (current->value == val) {
      return current;
    }

    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }

  return nullptr;
}

template <typename T>
bool BinaryTree<T>::breadth_first_search(T val) const noexcept {
  return breadth_first_search_ptr(val) != nullptr;
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

template <typename T>
std::vector<T> BinaryTree<T>::_in_order_traversal() const noexcept {
  std::vector<T> result;
  std::stack<BinaryNode<T> *> s;

  auto current = _root;

  while (true) {
    while (current->left) {
      s.push(current);
      current = current->left;
    }

    while (current->right == nullptr) {
      result.push_back(current->value);
      if (s.empty()) {
        return result;
      }
      current = s.top();
      s.pop();
    }
    result.push_back(current->value);
    current = current->right;
  }
}

template <typename T>
std::vector<T> BinaryTree<T>::_post_order_traversal() const noexcept {
  std::vector<T> result;
  if (_root == nullptr) {
    return result;
  }

  std::stack<BinaryNode<T> *> s;

  BinaryNode<T> *current = _root, *prev = _root;

  while (true) {
    while (current->left) {
      s.push(current);
      current = current->left;
    }

    while (current->right == nullptr or current->right == prev) {
      result.push_back(current->value);

      if (s.empty()) {
        return result;
      }

      prev = current;
      current = s.top();
      s.pop();
    }

    s.push(current);
    current = current->right;
  }
}

template <typename T>
std::vector<T> BinaryTree<T>::_level_order_traversal() const noexcept {
  std::vector<T> result;

  if (not _root) {
    return result;
  }

  std::queue<BinaryNode<T> *> q;
  q.push(_root);

  while (not q.empty()) {
    auto current = q.front();
    q.pop();

    result.push_back(current->value);

    if (current->left) {
      q.push(current->left);
    }
    if (current->right) {
      q.push(current->right);
    }
  }

  return result;
}

template <typename T>
std::vector<T> BinaryTree<T>::traverse(TreeTraversalMode mode) const noexcept {
  switch (mode) {
  case TreeTraversalMode::PRE_ORDER:
    return _pre_order_traversal();
  case TreeTraversalMode::POST_ORDER:
    return _post_order_traversal();
  case TreeTraversalMode::IN_ORDER:
    return _in_order_traversal();
  case TreeTraversalMode::LEVEL_ORDER:
    return _level_order_traversal();
  }
}
#endif // BINARY_TREE_HPP
