// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/find-bottom-left-tree-value/

class Solution {
public:
    void solve(TreeNode *root, int level, pair<int, int> &ans) {
        if (!root) return;

        if (level > ans.first) {
            ans.first = level;
            ans.second = root->val;
        }

        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        pair<int, int> ans = {-1, 0};
        solve(root, 0, ans);
        return ans.second;
    }
};

// another way of solving this using queue

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }

        return node->val;
    }
};