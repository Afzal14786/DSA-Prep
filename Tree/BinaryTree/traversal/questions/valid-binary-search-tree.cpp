// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/valid-binary-search-tree/question
// Question Link : https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    void solve(TreeNode *node, vector<int> &ans) {
        if (!node) return;
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        // testing
        for (int x : ans) cout << x << " ";
        cout << endl;
        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i-1] >= ans[i]) return false;
        }

        return true;
    }
};

class Solution {
public:
    // recursive solution
    bool solve(TreeNode *node, long long min_val, long long max_val) {
        if (!node) return true;
        if (node->val <= min_val || node->val >= max_val) return false;
        bool left = solve(node->left, min_val, node->val);
        bool right = solve(node->right, node->val, max_val);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();