#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "./Node.h"
#include <iostream>

template <typename T>
class btree {
    Node<T> *root;

    //helper function for creating a tree
    Node<T>* insertRecursively(Node<T>* current, T data) {
        if (current == nullptr) {
            return new Node<T>(data);
        }

        if (data < current->data) {
            current->leftChild = insertRecursively(current->leftChild, data);
        } else {
            current->rightChild = insertRecursively(current->rightChild, data);
        }

        return current;
    }


    void preOrderTraversal(Node<T>* current) {
        if (current == nullptr) {
            return;
        }

        std::cout << current->data << " ";
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }

    void inorderTraversal(Node<T>* current) {
        if (current == nullptr) {
            return;
        }

        inorderTraversal(current->leftChild);
        std::cout << current->data << " ";
        inorderTraversal(current->rightChild);
    }

    void postOrderTraversal(Node<T>* current) {
        if (current == nullptr) {
            return;
        }

        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
        std::cout << current->data << " ";
    }
    
    void deleteTree(Node<T>* current) {
        if (current == nullptr) {
            return;
        }

        deleteTree(current->leftChild);
        deleteTree(current->rightChild);
        delete current;
    }

    public:
        btree() {
            root = nullptr;
        }

        ~btree() {
            deleteTree(root);
        }

        // this is the public members
        void insert(T data) {
            root = insertRecursively(root, data);
        }

        void preOrder() {
            std::cout << "Pre Order Traversal : ";
            preOrderTraversal(root);
            std::cout << std::endl;
        }

        void inorder() {
            std::cout << "Inorder Tree Traversal : ";
            inorderTraversal(root);
            std::cout << std::endl;
        }

        void postOrder() {
            std::cout << "Post Order Traversal : ";
            postOrderTraversal(root);
            std::cout << std::endl;
        }
};

#endif