// Question Link : https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08
// Submission Link : https://leetcode.com/problems/balanced-binary-tree/submissions/1912166142/?envType=daily-question&envId=2026-02-08

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        // If the current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Otherwise, return the actual height
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
