/**
 * This file contain the implementation of deletion a key from BST
 * 
 *  When we delete a key, we must take care of the property of BST .
 *  The properties of BST not be affected after performming BST .
 */

#include "../BST.h"

template <typename T>
T bst<T>::delete_key(T key) {
    // (2) this function will return the value of the node
    root = delete_helper(root, key);
    if (root == nullptr) {
        throw std::runtime_error("The key is not in the tree");
        exit(1);
    }

    return root->key;
}

template <typename T>
Node<T>* bst<T>::delete_helper(Node<T>* root, T key) {
    // (1) this function will return the node, and then
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr || root->right == nullptr) {
        delete root;
        return nullptr;
    }

    if (key < root->key) {
        // perform deletion on the left sub tree
        root->left = delete_helper(root->left, key);
    } else if (key > root->key){
        root->right = delete_helper(root->right, key);
    } else {
        if (height_helper(root->left) > height_helper(root->right)) {
            Node<T> *temp = inorder_predesor(root->left);
            root->key = temp->key;
            root->left = delete_helper(root->left, temp->key);
        } else {
            Node<T> *temp = inorder_successor(root->right);
            root->key = temp->key;
            root->right = delete_helper(root->right, temp->key);
        }
    }

    return root;
}

template <typename T>
Node<T>* bst<T>::inorder_predesor(Node<T>* root) {
    while (root && root->right) {
        root = root->right;
    }

    return root;
}

template <typename T>
Node<T>* bst<T>::inorder_successor(Node<T>* root) {
    while (root && root->left) {
        root = root->left;
    }

    return root;
}

template <typename T>
int height_helper(Node<T>* node) {
    if (node == nullptr) {
        return -1;
    }

    int left_h = height_helper(node->left);
    int right_h = height_helper(node->right);

    return std::max(left_h, right_h) + 1;
}