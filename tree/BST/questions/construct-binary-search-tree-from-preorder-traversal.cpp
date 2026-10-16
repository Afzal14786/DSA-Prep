// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &nums, int &i, int bound) {
        if (i == nums.size() || nums[i] > bound) return nullptr;
        TreeNode *node = new TreeNode(nums[i++]);
        node->left  = buildTree(nums, i, node->val);  // we are passing the upper value as bound
        node->right = buildTree(nums, i, bound);  // we are always transfarring the bound
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildTree(preorder, i, INT_MAX);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();