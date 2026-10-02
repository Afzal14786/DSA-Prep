// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


// Question Link : https://leetcode.com/problems/diameter-of-binary-tree/description/
// Question Link : https://neetcode.io/problems/binary-tree-diameter/question?list=neetcode150  



class Solution {
public:

    int height(TreeNode *root, int &diameter) {
        if (!root) return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};