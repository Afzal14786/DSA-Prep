
#include "../BST.h"

/**
 * @attention this cpp file help us to calculate the sum of all the keys, if the tree is integer based
 * 
 * @return Integer sum
 */

template <typename T>
int bst<T>::sum() {
    return sum_helper(root);
}

template <typename T>
int bst<T>::sum_helper(Node<T> *current) {
    if (current == nullptr) {
        return -1;      // means there is no node in the tree
    }
    
    int left_sum = sum_helper(current->left);
    int right_sum = sum_helper(current->right);

    return left_sum + right_sum + current->key;
}