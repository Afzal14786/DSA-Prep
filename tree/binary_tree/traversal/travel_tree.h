
#ifndef TRAVEL_TREE
#define TRAVEL_TREE

#include <iostream>
#include "node.h"
#include "recursive/preorder.h"
#include "recursive/postorder.h"
#include "recursive/inorder.h"

class TravelTree {
    Node *root;
    Node *insert_recursive(Node *curr_node, int data) {
        if (curr_node == nullptr) {
            return new Node(data);
        }

        if (data < curr_node->data) {
            curr_node->leftChild = insert_recursive(curr_node->leftChild, data);
        } else {
            curr_node->rightChild = insert_recursive(curr_node->rightChild, data);
        }

        return curr_node;
    }

    void display_tree(Node *curr_node) {
        if (curr_node != nullptr) {
            std::cout << curr_node->data << " ";
            display_tree(curr_node->leftChild);
            display_tree(curr_node->rightChild);
        }
    }

public:
    TravelTree() {
        root = nullptr;
    }

    void insert_data(int data) {
        root = insert_recursive(root, data);
    }

    void preoder() {
        preorder_traversal(root);
    }

    void inorder() {
        inorder_traversal(root);
    }

    void postorder() {
        postorder_traversal(root);
    }

    void display() {
        std::cout << "Here are the elements of tree: ";
        display_tree(root);
        std::cout << "\n";
    }
};

#endif