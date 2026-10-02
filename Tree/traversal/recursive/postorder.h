#ifndef POSTORDER
#define POSTORDER

#include "../node.h"
#include <iostream>

void postorder_traversal(Node *curr_node) {
    if (curr_node != nullptr) {
        // first go left, then right and then visit
        postorder_traversal(curr_node->leftChild);
        postorder_traversal(curr_node->rightChild);
        std::cout << curr_node->data << " ";
    }
}

#endif