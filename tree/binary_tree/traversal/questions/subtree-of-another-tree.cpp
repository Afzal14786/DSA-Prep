// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:

    bool isSame(TreeNode *p, TreeNode *q) {
        if (!p || !q) return p == q;
        return p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return root == subRoot;
        if (root->val == subRoot->val && isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
