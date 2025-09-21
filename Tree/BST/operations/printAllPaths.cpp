#include <iostream>
#include <string>
#include <vector>

#include "../BST.h"

template <typename T>
void bst<T>::printAllPaths() {
    std::vector<std::string> all_paths;
    std::string current_path = std::to_string(root->key);
    printAllPaths_helper(root, current_path, all_paths);

    for (int i = 0; i < all_paths.size(); ++i) {
        std::cout << all_paths[i] << ", ";
    }

    std::cout << std::endl;
}

template <typename T>
void bst<T>::printAllPaths_helper(Node<T> *node, std::string current_path, std::vector<std::string> &all_paths) {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        all_paths.push_back(current_path);
        return;
    }

    if (node->left) {
        printAllPaths_helper(node->left, current_path + "->" + std::to_string(node->left->key), all_paths);
    }
    if (node->right) {
        printAllPaths_helper(node->right, current_path + "->" + std::to_string(node->right->key), all_paths);
    }
}