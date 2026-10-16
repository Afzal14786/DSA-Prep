#include <iostream>
#include <vector>

/**
 * @param arr[T] 
 * 
 * @return A balanced Binary Tree
 */

#include "../BST.h"

template <typename T>
Node<T>* bst<T>::sortedArrToBST(std::vector<T>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

template <typename T>
Node<T>* helper(std::vector<T>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start)/2;
    Node<T>* curr_node = new Node<T>(nums[mid]);
    curr_node->left = helper(nums, start, mid-1);
    curr_node->right = helper(nums, mid+1, end);

    return curr_node;
}