
#include "../BST.h"

/**
 * @attention
 * 
 *      This following piece of code is used to search total number of nodes or keys present in a BST
 * 
 * @return Integer
 */

template <typename T>
int bst<T>::count() {
    return count_helper(root);
}

template <typename T>
int bst<T>::count_helper(Node<T> *current) {
    if (current == nullptr) {
        return 0;
    }

    return 1 + count_helper(current->left) + count_helper(current->right);
}

/**
 * @attention the following function is the extended version of count
 * 
 * this functions are helpful for counting,
 *  ~ nodes with deg(0) OR the leaf nodes
 *  ~ nodes with deg(1) OR the nodes having one child only
 *  ~ nodes with deg(2)
 *  
 */


template <typename T>
int count_leaf_nodes(Node<T>* current) {
    if (current == nullptr) {
        return 0; // base case: 0 leaf nodes in an empty tree
    }
    // Check if the current node is a leaf
    if (current->left == nullptr && current->right == nullptr) {
        return 1;
    }
    // Recursively count leaf nodes in both subtrees
    return count_leaf_nodes(current->left) + count_leaf_nodes(current->right);
}

/**
 * node with exactly degree 1
 */
template <typename T>
int count_deg_1(Node<T>* current) {
    if (current == nullptr) {
        return 0; // base case: 0 degree-1 nodes in an empty tree
    }
    int count = 0;
    // Check for exactly one child
    if ((current->left != nullptr && current->right == nullptr) || (current->left == nullptr && current->right != nullptr)) {
        count = 1;
    }
    // Recursively count degree-1 nodes in both subtrees and add them
    return count + count_deg_1(current->left) + count_deg_1(current->right);
}


template <typename T>
int count_deg_2(Node<T>* current) {
    if (current == nullptr) {
        return 0; // base case: 0 degree-2 nodes in an empty tree
    }
    int count = 0;
    // Check if the current node has both children
    if (current->left != nullptr && current->right != nullptr) {
        count = 1;
    }
    return count + count_deg_2(current->left) + count_deg_2(current->right);
}

template <typename T>
int count_deg_1_deg_2(Node<T>* current) {
    if (current == nullptr) {
        return 0; // case: 0 nodes with degree 1 or 2
    }
    int count = 0;
    
    if (current->left != nullptr || current->right != nullptr) {
        count = 1;
    }
    
    return count + count_deg_1_deg_2(current->left) + count_deg_1_deg_2(current->right);
}