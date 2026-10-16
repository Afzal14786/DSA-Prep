// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Question Link : https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree/question

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val > p->val && root->val > q->val) {
            // means in the left side
            return lowestCommonAncestor(root->left, p, q);
       } else if (root->val < p->val && root->val < q->val) {
        // means in the right side
            return lowestCommonAncestor(root->right, p, q);
       } 
       return root;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();