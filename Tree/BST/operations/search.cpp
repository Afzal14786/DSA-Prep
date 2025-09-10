
#include "../BST.h"

/**
 * @attention this cpp file help u to search a key within a tree with logn time complexity only
 * 
 * @return boolean
 */

template <typename T>
bool bst<T>::search(T key) {

    return search_helper(root, key);
}

template <typename T>
bool bst<T>::search_helper(Node<T> *current, T key) {
    if (current == nullptr) {
        return false;
    }

    if (current->key == key) {
        return true;
    }

    if (key < current->key) {
        // search on left side
        return search_helper(current->left, key);
    } else {
        return search_helper(current->right, key);
    }
}

/**
 * @attention the following code is options method for searching a key using iterative appraoch
 * 
 * @return bool
 */

template <typename T>
bool search_iterative(Node<T> *current, T key) {
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}
