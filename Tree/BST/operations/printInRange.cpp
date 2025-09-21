/**
 * This file contain the implementaion for printing all the number of a tree that lies within a range
 */

#include <iostream>
#include "../BST.h"

#include <algorithm>
#include <vector>

template <typename T>
void bst<T>::printInRange(int start, int end) {
    std::vector<T> res = printInRange_helper(root, start, end);
    std::cout << "Total number of values within range = " << res.size() << std::endl;

    for (const T& val : res) {
        std::cout << val << " ";
    }

    std::cout << std::endl;
}

/**
 * Solution 1:
 */
template <typename T>
std::vector<T> bst<T>::printInRange_helper(Node<T>* root, int start, int end) {
    if (root == nullptr) {
        return {};
    }

    std::vector<T> ans;

    if (root->key > start) {
        std::vector<T> left_ans = printInRange_helper(root->left, start, end);
        ans.insert(ans.end(), left_ans.begin(), left_ans.end());
    }

    if (root->key >= start & root->key <= end) {
        ans.push_back(root->key);
    }

    if (root->key < end) {
        std::vector<T> right_ans = printInRange_helper(root->right, start, end);
        ans.insert(ans.end(), right_ans.begin(), right_ans.end());
    }
    return ans;
}

/**
 * Solution 2: Just print the element inside the function only
 */

template <typename T>
void printInRange_sol2(Node<T>* root, int start, int end) {
    if (root == nullptr) {
        return;
    }

    if (root->key >= start && root->key <= end) {
        std::cout << root->key << " ";
        printInRange_sol2(root->left, start, end);
        printInRange_sol2(root->right, start, end);
    } else if (root->key < start) {
        printInRange_sol2(root->right, start, end);
    } else if (root->right > end) {
        printInRange_sol2(root->left, start, end);
    }

    std::cout << std::endl;
}