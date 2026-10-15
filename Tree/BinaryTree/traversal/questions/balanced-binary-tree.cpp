// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/balanced-binary-tree/question?list=neetcode150
// Question Link : https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:

    int check(TreeNode *root) {
        if (!root) return 0;
        int lh = check(root->left);
        if (lh == -1) return -1;

        int rh = check(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return check(root) != -1;
    }
};
