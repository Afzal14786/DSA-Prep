#ifndef INORDER
#define INORDER

#include "../node.h"
#include <iostream>

void inorder_traversal(Node *curr_node) {
    if (curr_node != nullptr) {
        // first go left, then visit and then right
        inorder_traversal(curr_node->leftChild);
        std::cout << curr_node->data << " ";
        inorder_traversal(curr_node->rightChild);
    }
}

#endif
