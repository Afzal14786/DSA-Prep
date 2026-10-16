#ifndef NODE_H
#define NODE_H

struct Node {
    Node *leftChild;
    Node *rightChild;
    int data;
    Node(int data) {
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