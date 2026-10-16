// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/recover-binary-search-tree/description/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

/**
 * @details this is my initial thought
 * @time complexity  : O(2n) + O(nlogn)
 * @space complexity : O(n)
 */
class Solution {
public:
    void get_nums(TreeNode *node, vector<int> &a) {
        if (!node) return;
        get_nums(node->left, a);
        a.push_back(node->val);
        get_nums(node->right, a);
    }

    void solve(TreeNode *root, int &i, vector<int> &nums) {
        if (!root) return;
        solve(root->left, i, nums);
        root->val = nums[i];
        i++;
        solve(root->right, i, nums);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        get_nums(root, nums);
        sort(nums.begin(), nums.end());
        int i = 0;
        solve(root, i, nums);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();