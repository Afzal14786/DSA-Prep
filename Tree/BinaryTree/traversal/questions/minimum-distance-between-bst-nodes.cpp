// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> &ans) {
        if (!node) return;
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    int minDiffInBST(TreeNode* root) {
        // this is the brute force solution using extra space O(n)
        vector<int> ans;
        solve(root, ans);
        int mini = INT_MAX;
        for (int i = 1; i < ans.size(); ++i) {
            mini = min(mini, abs(ans[i] - ans[i-1]));
        }

        return mini;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
