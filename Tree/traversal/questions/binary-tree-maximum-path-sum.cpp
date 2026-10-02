// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Question Link : https://neetcode.io/problems/binary-tree-maximum-path-sum/question?list=neetcode150

class Solution {
public:

    int maxiPathDown(TreeNode* root, int &maxi) {
        if (!root) return 0;

        int leftSum = max(0, maxiPathDown(root->left, maxi));
        int rightSum = max(0, maxiPathDown(root->right, maxi));
        maxi = max(maxi, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxi = INT_MIN;
        maxiPathDown(root, maxi);
        return maxi;
    }
};
