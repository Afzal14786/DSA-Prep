// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/symmetric-tree/description/

// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
public:
    static bool solve(const TreeNode *t1, const TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;

        return t1->val == t2->val && solve(t1->left, t2->right) && solve(t1->right, t2->left);
    }
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    static bool isSymmetric(const TreeNode* root) {
        if (!root) return true;
        const TreeNode *temp = root;
        return solve(temp->left, temp->right);
    }
};
