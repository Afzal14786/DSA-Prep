// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/practice/problem-list/tree
// Question Link : https://leetcode.com/problems/merge-two-binary-trees/description/

// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
    TreeNode* merge(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;

        t1->val += t2->val;

        t1->left = merge(t1->left, t2->left);
        t1->right = merge(t1->right, t2->right);

        return t1;
    }
public:
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};
