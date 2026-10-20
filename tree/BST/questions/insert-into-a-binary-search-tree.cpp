// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// Question Link : https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// Question Link : https://neetcode.io/problems/insert-into-a-binary-search-tree/question

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

/**
 * another recursive approach
 * 
 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else 
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *curr_node = root;
        TreeNode *tail = nullptr;

        while (curr_node) {
            tail = curr_node;
            if (curr_node->val == val) return new TreeNode(val);
            else if (val < curr_node->val) curr_node = curr_node->left;
            else curr_node = curr_node->right;
        }

        TreeNode *temp = new TreeNode(val);
        if (val > tail->val) tail->right = temp;
        else tail->left = temp;

        return root;  // always return the root after inserting this
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();