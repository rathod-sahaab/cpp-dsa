#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "binary-tree.hpp"
#include <functional>

template <typename T> class BinarySearchTree : public BinaryTree<T> {
public:
  void insert(T val);
  void remove(T val);

  bool binary_search(const T &val) const noexcept;
  BinaryNode<T> *binary_search_ptr(const T &val) const noexcept;

private:
  /**
   * @param node pointer to node to be deleted
   * @param parent pointer to parent of node to be deleted
   * @param is_left_child if [node] is the left child of [parent]
   */
  void remove_helper(BinaryNode<T> *node, BinaryNode<T> *parent,
                     bool is_left_child);
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

template <typename T> void BinarySearchTree<T>::remove(T val) {
  const auto root = BinaryTree<T>::_root;

  BinaryNode<T> *curr = root, *parent = nullptr;
  bool is_left_child;
  while (curr) {
    if (val == curr->value) {
      // is_left_child is undefined for parent == nullptr i.e. element to remove
      // is root element
      return remove_helper(curr, parent, is_left_child);
    }
    parent = curr;
    if (val < curr->value) {
      curr = curr->left;
      is_left_child = true;
      continue;
    }
    curr = curr->right;
    is_left_child = false;
  }
}

template <typename T>
void BinarySearchTree<T>::remove_helper(BinaryNode<T> *node,
                                        BinaryNode<T> *parent,
                                        bool is_left_child) {
  if (not node->left and not node->right) {
    // case A when node is leaf
    if (parent) {
      BinaryNode<T> *&parent_to_node =
          is_left_child ? parent->left : parent->right;
      parent_to_node = nullptr;
    } else {
      BinaryTree<T>::_root = nullptr;
    }
    delete node;
  }
  if (not node->left xor not node->right) {
    if (parent) {
      BinaryNode<T> *&parent_to_node =
          is_left_child ? parent->left : parent->right;
      parent_to_node = node->left ? node->left : node->right;
    } else {
      BinaryTree<T>::_root = node->left ? node->left : node->right;
    }

    delete node;
  }

  // inorder successor : left most child/smallest element of right subtree
  BinaryNode<T> *is = node->right, *parent_is = node;

  while (is->left) {
    parent_is = is;
    is = is->left;
  }

  if (parent_is == node) {
    is->left = node->left;
    is->right = nullptr;
  } else {
    parent_is->left = is->right;
    is->left = node->left;
    is->right = node->right;
  }
  delete node;
  if (parent) {
    BinaryNode<T> *&parent_to_node =
        is_left_child ? parent->left : parent->right;
    parent_to_node = is;
  } else {
    BinaryTree<T>::_root = is;
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
