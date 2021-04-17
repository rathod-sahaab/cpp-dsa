#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "binary-tree.hpp"
#include <functional>

template <typename T> class BinarySearchTree : public BinaryTree<T> {
public:
  void insert(T val);

  bool binary_search(const T &val) const noexcept;
  BinaryNode<T> *binary_search_ptr(const T &val) const noexcept;
};

template <typename T> void BinarySearchTree<T>::insert(T val) {
  BinaryNode<T> *new_node = new BinaryNode<T>(val);
  if (not BinaryTree<T>::_root) {
    BinaryTree<T>::_root = new_node;
    return;
  }

  auto current = BinaryTree<T>::_root;
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

/// TODO: use custom comparator
/// decltype(std::less<T>()) comparator = std::less<T>())
template <typename T>
BinaryNode<T> *
BinarySearchTree<T>::binary_search_ptr(const T &val) const noexcept {
  auto current = BinaryTree<T>::_root;

  while (current) {
    const auto value = current->value;
    if (val < value) {
      current = current->left;
      continue;
    }
    if (val > value) {
      current = current->right;
    }
    return current;
  }

  return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::binary_search(const T &val) const noexcept {
  return binary_search_ptr(val) != nullptr;
}

#endif // BINARY_SEARCH_TREE_HPP
