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

    if (key < root->key) {
        // perform deletion on the left sub tree
        root->left = delete_helper(root->left, key);
    } else if (key > root->key){
        root->right = delete_helper(root->right, key);
    } else {
        // case 1 : node has no children or 1 childre
        if (root->left == nullptr) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        // case 2: means that node has 2 childrens
        // find the inorder successor (smallest in the right subtree)
        Node<T>* temp = inorder_successor(root->right);
        root->key = temp->key;
        // delete the node, now
        root->right = delete_helper(root->right, temp->key);
    }

    return root;
}

template <typename T>
Node<T>* bst<T>::inorder_successor(Node<T>* node) {
    Node<T> *temp = node;
    while (temp && temp->left != nullptr) {
        temp = temp->left;
    }

    return temp;
}
