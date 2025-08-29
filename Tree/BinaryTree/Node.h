
#ifndef NODE_H
#define NODE_H

#include "./binarytree.h"

template <typename T>
class btree;

template <typename T>
class Node {
    Node<T> *leftChild;
    Node<T> *rightChild;
    T data;

    friend class btree<T>;        // now the binary class can access the private member's of node class

    public:
        Node(T data) {
            this->data = data;
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        ~Node() {
            leftChild = nullptr;
            rightChild = nullptr;
        }
};



#endif