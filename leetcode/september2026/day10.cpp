
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

using namespace std;
#include <bits/stdc++.h>

// Question Link : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/?envType=daily-question&envId=2026-09-10

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
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
