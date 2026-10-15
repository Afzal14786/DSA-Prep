#ifndef PREORDER_TRAVERSAL
#define PREORDER_TRAVERSAL

#include "../node.h"
#include <iostream>

void preorder_traversal(Node *curr_node) {
    if (curr_node != nullptr) {
        std::cout << curr_node->data << " ";
        preorder_traversal(curr_node->leftChild);
        preorder_traversal(curr_node->rightChild);
    }
}

#endif