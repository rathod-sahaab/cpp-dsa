#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "binary-tree.hpp"

template <typename T> class BinarySearchTree : public BinaryTree<T> {
public:
  void insert(T val);
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

#endif // BINARY_SEARCH_TREE_HPP
