// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-paths/description/

class Solution {
public:

    void solve(TreeNode *root, vector<string> &ans, string temp) {
        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }
        if (root->left)
            solve(root->left, ans, temp + "->" + to_string(root->left->val));
        if (root->right)
            solve(root->right, ans, temp + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> ans;
        string path = to_string(root->val);
        solve(root, ans, path);
        return ans;
    }
};