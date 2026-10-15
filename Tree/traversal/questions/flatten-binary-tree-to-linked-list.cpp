// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Question Link : https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode *next_right = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = next_right;
        next_right = root;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();