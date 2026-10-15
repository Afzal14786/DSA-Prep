// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/range-sum-of-bst/description/
// Question Link : https://neetcode.io/problems/range-sum-of-bst/question?list=neetcode150

// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
    static void solve(const TreeNode *root, int low, int high, long long &curr_sum) {
        if (!root) return; // if the node is null return from here
        if (root->val >= low && root->val <= high) curr_sum += root->val;
        solve(root->left, low, high, curr_sum);
        solve(root->right, low, high, curr_sum);
    }
public:

    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    static int rangeSumBST(const TreeNode* root, int low, int high) {
        if (!root) return 0;
        long long curr_sum = 0;
        solve(root, low, high, curr_sum);
        return (int)curr_sum;
    }
};
