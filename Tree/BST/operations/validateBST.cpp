#include "../BST.h"

template <typename T>
bool bst<T>::validate_bst() {
    return validateBST_helper(root, nullptr, nullptr);
}

template <typename T>
bool bst<T>::validateBST_helper(Node<T>* node, Node<T>* min, Node<T>* max) {
    if (node == nullptr) {
        return true;
    }

    if (min != nullptr && node->key <= min->key) {
        return false;
    }

    if (max != nullptr && node->key >= max->key) {
        return false;
    }

    return validateBST_helper(node->left, min, node) && validateBST_helper(node->right, node, max);
}