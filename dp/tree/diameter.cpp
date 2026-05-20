// Question Link : https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode *root, int &res) {
        if (root == nullptr) return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        res = max(res, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = -1e9;
        solve(root, res);
        return res;  
    }
};