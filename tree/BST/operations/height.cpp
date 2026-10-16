
#include <algorithm>
#include "../BST.h"

/**
 * @attention this cpp file is useful for calculating the height of a BST
 * 
 * @return Integer height
 */

template <typename T>
int bst<T>::height() {
    return height_helper(root);
}

template <typename T>
int bst<T>::height_helper(Node<T> *current) {
    if (current == nullptr) {
        return -1;   // means the height of the tree is -1, there is no element inside the tree
    }

    int left_height = height_helper(current->left);
    int right_height = height_helper(current->right);

    return std::max(left_height, right_height) + 1;
}